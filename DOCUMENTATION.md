# Sandbox game

## Input

This term paper belongs to the category of games. Your goal is to create a specific game,
which will be modifiable through configuration files.
Do not try to define all the values directly in the code (not even using constants).
Place them in the configuration files (one or more) that your program will load.

Your task is to program a simple 2D sandbox game. Sandbox games are characterized primarily by the possibility of modifying the existing environment.

The game must meet the following functionalities:

1) Implement the player (e.g. character, spaceship, …), his state (e.g. energy, lives, armor, …) and allow to interact with the environment (e.g. mine, dig, build, …).

2) Create a (combat) injury model that will have at least 3 different causes (e.g. falling from a height, fighting an enemy, being in lava, ...).

3) Create a simple environment model, implement at least 3 different mechanics (e.g. gravity, water overflow, tree growth, …).

4) The game must be configurable from the file:

       a) map (or even better its generator),

       b) definition of individual enemies, names of objects or their attributes.

5) The game must allow you to save and then load the played game.

Where can polymorphism be used? (recommended)

     + characters: player, animals, friend (merchant), enemy (various species), …

     + action effects: fall (takes life according to the square of height), hit (takes life according to strength and defense), contact with lava (applies fire and takes 1 life each time), …

     + environment: air (does nothing), water (fills or empties when used with a bucket), dirt (picks up by player and stores in inventory),
     coal and other ores (if the player holds a pickaxe, it will be mined), a ladder (moves the player to the end), …

     + user interface: console, ncurses, SDL, OpenGL (various variants), …

## Specifications

I will implement a sandbox game inspired by games like Minecraft, Terraria and Don't starve.
The player is surrounded by impenetrable ground on the map and can move on 4 sides.
There is always a bed, computer and electricity generator block for that computer on the map.
There may also be other blocks on the map, such as soil, coal, tree (can be a sapling), mushroom, water, infection, etc.
Some of these blocks can be interacted with by the player, some can be passed through.
The player can mine blocks and use them as fuel for a generator (not all blocks release energy when burned).
Some blocks can only be mined with a pickaxe (also a block) in hand (active block in inventory).
The player needs electricity to run a progtest on the computer.
Also, using the computer, the player can try to pass (limited number of attempts) the progtest and get some score depending on the readiness of the task, there is also a chance to get a red flag.
If a player receives a red flag, then each pass will cause them some damage. Also, damage is done if the player steps on an infection or for every action without energy.
The player can get energy by eating something (mushrooms) or sleeping. Energy is consumed during movement, etc.
Mined blocks are stored in a limited inventory, the active block can be placed in front of you. After sleeping, the player not only restores energy,
but also mushrooms and trees can grow on the map, of course the progtest deadline is approaching. With each player action, the infection has a chance to spread to the nearest non-fixed blocks.
In addition, a water block can expand several blocks.
The end of the game occurs when the player dies, the progtest deadline arrives or the player wants to quit alone.
The map, toolLevel of the croupier, the player's life, his energy, inventory, programming level, amount of electricity, difficulty of the progtest, maximum number of attempts, etc. can be configured using a configuration file.

'^', 'v', '>', '<' - Player, depends on movement direction.<br/>
'#' - Soil.<br/>
'C' - Computer.<br/>
'G' - Electricity generator.<br/>
'B' - Bed.<br/>
'.' - Small mushroom(cannot be eaten).<br/>
'?' - Large mushroom (can be eaten).<br/>
't' - Tree (no fuel, walkable).<br/>
'T' - Tree(is fuel, cannot be passed).<br/>
'R' - rock.<br/>
'/' - pickaxe.<br/>
'x' - infection.<br/>
'@' - coal.<br/>
'~', '"', '`' - water with resource strength 2, 1 and 0.<br/>

## Control

- `w` - move up
- `s` - move down
- `a` - move left
- `d` - move to the right

- `q` - dig the block in front of you
- `e` - place an active block in front of you
- `f` - communicate with the block in front of you using the active block

- `k` - quit the game
- `l` - save game
- `r` - restart the game

## Polymorphism

Polymorphism is applied within the `CBlock` and `CAction` class hierarchy.

The `CBlock` class has 5 (and more) children: `CAirBlock`, `CDirtBlock`, `CComputerBlock`, `CBedBlock` and `CBedrockBlock`.
This class is needed so that we can have different blocks on the map that behave differently when you interact with them.
The `CBlock` class has polymorphic `update`, `refresh` and `action` methods.
The `update` method tells the block that it is a new day and those blocks that depend on time can change or do something (trees and small mushrooms will grow).
The 'refresh' method is called for neighboring blocks with the block that was supplied or destroyed
They will accept it has a two-dimensional array of blocks and its position to interact with neighboring blocks in some way (for example, water replaces non-fixed neighboring blocks with a copy of itself - it flows out).
The `action` method constructs and returns some implementation of the CAction(pointer) class depending on the implementation of the CBlock class itself. The CAction already takes place in the CGame class.
For example, `CBedBlock` changes the day on interaction and restores the player's energy (`CSkipDay` as a pointer to `CAction`).

The `CAction` class has 3 children: `CNoAction`, `CBurn`, `CEnergyAction`, `CMakeProgtest`, `CSkipDay`, `CSubmitProgtest`, `CTakeDamage`.
This class is needed so that any block doesn't know about player or progtest properties and doesn't take them as parameters in its methods.
The `CAction` class has polymorphic `activate`, `changeStats` and `changeProgtest` methods.
The `activate` method, depending on the class implementation, will make some changes with the player and progtest characteristics.
The `changeStats` method, depending on the implementation of the class, will make some changes to the player's characteristics only.
The `changeProgtest` method, depending on the class implementation, will make some changes to the progtest characteristics.
For example, `CTakeDamage` will take away the amount of HP from the player that was specified when the class was instantiated.