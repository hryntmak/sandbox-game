//
// Created by User on 08.05.2023.
//

#include "CPlayer.h"
#include "CConfig.h"
#include "CBlockAggregator.h"
#include "actions/CNoAction.h"

CPlayer::CPlayer(std::istream &in,
                 CBlockAggregator aggregator) : m_Icon('^'),
                                                m_Aggregator(aggregator) {
    for (auto & item : m_Inventory)
        item = nullptr;
    std::string str;
    in >> str;
    if (str != "Inventory") throw std::logic_error("Bad Inventory configuration.");
    in >> str;
    if (str != "=") throw std::logic_error("Isn't '=' in player configuration.");
    char c;
    in >> c;
    if (c != '{') throw std::logic_error("Isn't '{' in player inventory configuration.");
    SPos tmp = {0, 0};

    // 5 is capacity of the player inventory + 1 to detect '}' on the end
    for (size_t i = 0; i < 6; ++i) {
        in >> c;
        if (c == '}') break; // In config file can be less than 5 blocks in the inventory
        if (i == 5) throw std::logic_error("Excepted '}' in the configuration of the inventory.");
        m_Inventory[i] = m_Aggregator.creatBlock(c, tmp, tmp, tmp);
    }
    m_ActiveItem = CConfig::getInteger(in, "ActiveItem", 5);
    std::cout << "Player has been configured." << std::endl;
}

bool CPlayer::mine(std::unique_ptr<CBlock> & block) {
    if (block->getHardness() > (m_Inventory[m_ActiveItem] == nullptr ? 0 : m_Inventory[m_ActiveItem]->getToolLevel())
     || block->getHardness() < 0)
        return false;
    for (auto & itemSlot : m_Inventory) {
        if (itemSlot == nullptr) {
            itemSlot = std::move(block);
            block = std::make_unique<CAirBlock>();
            return true;
        }
    }
    return false;
}

std::unique_ptr<CAction> CPlayer::action(const std::unique_ptr<CBlock> &block, bool steppedOn) {
    if(!block->isSolid() && !steppedOn) { // If block ahead isn't solid - use active item
        std::unique_ptr<CAction> tmpAction = std::make_unique<CNoAction>();
        if ( m_Inventory[m_ActiveItem] == nullptr || m_Inventory[m_ActiveItem]->use(tmpAction) ) // If out of usage possibilities - delete item
            m_Inventory[m_ActiveItem] = nullptr;
        return tmpAction;
    }
    std::unique_ptr<CBlock> tmpBlock = std::make_unique<CAirBlock>();
    if (m_Inventory[m_ActiveItem] == nullptr)
        return block->action(tmpBlock);
    return block->action(m_Inventory[m_ActiveItem]);
}

void CPlayer::setDirection(const SPos &direction) {
    if (direction == SPos({1,0})) // right
        m_Icon = '>';
    if (direction == SPos({-1,0})) // left
        m_Icon = '<';
    if (direction == SPos({0,-1})) // top
        m_Icon = '^';
    if (direction == SPos({0,1})) // bottom
        m_Icon = 'v';
}

bool CPlayer::placeBlock(std::unique_ptr<CBlock> &block) {
    if (block->isSolid() || m_Inventory[m_ActiveItem] == nullptr)
        return false;
    block = std::move(m_Inventory[m_ActiveItem]);
    m_Inventory[m_ActiveItem] = nullptr;
    return true;
}

CPlayer::CPlayer() : m_Icon('^'), m_ActiveItem(0) {
    for (auto & item : m_Inventory) {
        item = nullptr;
    }
}

void CPlayer::print(std::ostream &out) const {
    out << m_Icon;
}

void CPlayer::setActiveItem(int n) {
    m_ActiveItem = n;
}

std::ostream &operator<<(std::ostream &out, const CPlayer &player) {
    out << "player:" << std::endl << "Inventory = { ";
    for (int i = 0; i < 5; ++i) {
        if (player.m_Inventory[i] == nullptr) {
            out << i + 1 << ":  ";
            if (i!=4)
                out << ", ";
            continue;
        }
        out << i + 1 << ": " << *player.m_Inventory[i];
        if (i!=4)
            out << ", ";
    }
    out << '}' << std::endl;
    out << "ActiveItem = " << player.m_ActiveItem + 1 << std::endl;
    return out;
}

void CPlayer::printConfig(std::ostream &out) const {
    out << "player:" << std::endl << "Inventory = { ";
    for (auto & item : m_Inventory) {
        if (item != nullptr)
            item->printConfig(out);
    }
    out << '}' << std::endl;
    out << "ActiveItem = " << m_ActiveItem << std::endl;
}

