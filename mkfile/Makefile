CXX=g++
CXXFLAGS=-Wall -pedantic
LD=g++
LDFLAGS=-Wall -pedantic


all: game

game: ../src/actions/CSubmitProgtest.o ../src/actions/CTakeDamage.o ../src/actions/CNoAction.o ../src/blocks/CComputerBlock.o ../src/blocks/CSolidBlock.o ../src/actions/CEnergyAction.o ../src/actions/CMakeProgtest.o ../src/actions/CSkipDay.o ../src/CBlockAggregator.o ../src/actions/CBurn.o ../src/CAction.o ../src/blocks/CAirBlock.o ../src/blocks/CBedBlock.o ../src/main.o ../src/CApplication.o ../src/CBlock.o ../src/CGame.o ../src/CMap.o ../src/CPlayer.o ../src/CProgtest.o ../src/CStats.o
	$(LD) $(LDFLAGS) ../src/actions/CSubmitProgtest.o ../src/actions/CTakeDamage.o ../src/actions/CNoAction.o ../src/blocks/CComputerBlock.o ../src/blocks/CSolidBlock.o ../src/actions/CEnergyAction.o ../src/actions/CMakeProgtest.o ../src/actions/CSkipDay.o ../src/CBlockAggregator.o ../src/actions/CBurn.o ../src/CAction.o ../src/blocks/CAirBlock.o ../src/blocks/CBedBlock.o ../src/main.o ../src/CApplication.o ../src/CBlock.o ../src/CGame.o ../src/CMap.o ../src/CPlayer.o ../src/CProgtest.o ../src/CStats.o -o game

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f ../game game ../src/*.o ../src/blocks/*.o ../src/actions/*.o *~ core


CAction.o: ../src/CAction.cpp ../src/CAction.h ../src/CState.h \
 ../src/CProgtest.h
CApplication.o: ../src/CApplication.cpp ../src/CApplication.h \
 ../src/CGame.h ../src/CMap.h ../src/CBlock.h ../src/CState.h \
 ../src/CProgtest.h ../src/SPos.h ../src/CAction.h ../src/CPlayer.h
CBlockAggregator.o: ../src/CBlockAggregator.cpp ../src/CBlockAggregator.h \
 ../src/blocks/CBedBlock.h ../src/blocks/../CBlock.h \
 ../src/CState.h ../src/blocks/../CProgtest.h \
 ../src/blocks/../SPos.h ../src/blocks/../CAction.h \
 ../src/blocks/CBedrockBlock.h ../src/blocks/CAirBlock.h \
 ../src/blocks/CComputerBlock.h ../src/SPos.h
CBlock.o: ../src/CBlock.cpp ../src/CBlock.h ../src/CState.h \
 ../src/CProgtest.h ../src/SPos.h ../src/CAction.h
CGame.o: ../src/CGame.cpp ../src/CGame.h ../src/CMap.h ../src/CBlock.h \
 ../src/CState.h ../src/CProgtest.h ../src/SPos.h ../src/CAction.h \
 ../src/CPlayer.h
CMap.o: ../src/CMap.cpp ../src/CMap.h ../src/CBlock.h ../src/CState.h \
 ../src/CProgtest.h ../src/SPos.h ../src/CAction.h
CPlayer.o: ../src/CPlayer.cpp ../src/CPlayer.h ../src/CMap.h \
 ../src/CBlock.h ../src/CState.h ../src/CProgtest.h ../src/SPos.h \
 ../src/CAction.h
CProgtest.o: ../src/CProgtest.cpp ../src/CProgtest.h
CStats.o: ../src/CState.cpp ../src/CState.h
main.o: ../src/main.cpp ../src/CApplication.h ../src/CGame.h \
 ../src/CMap.h ../src/CBlock.h ../src/CState.h ../src/CProgtest.h \
 ../src/SPos.h ../src/CAction.h ../src/CPlayer.h
CBurn.o: ../src/actions/CBurn.cpp ../src/actions/CBurn.h \
 ../src/actions/../CAction.h ../src/CState.h \
 ../src/actions/../CProgtest.h
CEnergyAction.o: ../src/actions/CEnergyAction.cpp \
 ../src/actions/CEnergyAction.h ../src/actions/../CAction.h \
 ../src/CState.h ../src/actions/../CProgtest.h
CMakeProgtest.o: ../src/actions/CMakeProgtest.cpp \
 ../src/actions/CMakeProgtest.h ../src/actions/../CAction.h \
 ../src/CState.h ../src/actions/../CProgtest.h
CNoAction.o: ../src/actions/CNoAction.cpp ../src/actions/CNoAction.h \
 ../src/actions/../CAction.h ../src/CState.h \
 ../src/actions/../CProgtest.h
CSkipDay.o: ../src/actions/CSkipDay.cpp ../src/actions/CSkipDay.h \
 ../src/actions/../CAction.h ../src/CState.h \
 ../src/actions/../CProgtest.h
CSubmitProgtest.o: ../src/actions/CSubmitProgtest.cpp \
 ../src/actions/CSubmitProgtest.h ../src/actions/../CAction.h \
 ../src/CState.h ../src/actions/../CProgtest.h
CTakeDamage.o: ../src/actions/CTakeDamage.cpp \
 ../src/actions/CTakeDamage.h ../src/actions/../CAction.h \
 ../src/CState.h ../src/actions/../CProgtest.h
CAirBlock.o: ../src/blocks/CAirBlock.cpp ../src/blocks/CAirBlock.h \
 ../src/blocks/../CBlock.h ../src/CState.h \
 ../src/blocks/../CProgtest.h ../src/blocks/../SPos.h \
 ../src/blocks/../CAction.h ../src/blocks/../actions/CNoAction.h \
 ../src/blocks/../actions/../CAction.h \
 ../src/CState.h \
 ../src/blocks/../actions/../CProgtest.h
CBedBlock.o: ../src/blocks/CBedBlock.cpp ../src/blocks/CBedBlock.h \
 ../src/blocks/../CBlock.h ../src/CState.h \
 ../src/blocks/../CProgtest.h ../src/blocks/../SPos.h \
 ../src/blocks/../CAction.h ../src/blocks/../actions/CSkipDay.h \
 ../src/blocks/../actions/../CAction.h \
 ../src/CState.h \
 ../src/blocks/../actions/../CProgtest.h
CSolidBlock.o: ../src/blocks/CSolidBlock.cpp \
 ../src/blocks/CSolidBlock.h ../src/blocks/../CBlock.h \
 ../src/CState.h ../src/blocks/../CProgtest.h \
 ../src/blocks/../SPos.h ../src/blocks/../CAction.h \
 ../src/blocks/../actions/CNoAction.h \
 ../src/blocks/../actions/../CAction.h \
 ../src/CState.h \
 ../src/blocks/../actions/../CProgtest.h
CComputerBlock.o: ../src/blocks/CComputerBlock.cpp \
 ../src/blocks/CComputerBlock.h ../src/blocks/../CBlock.h \
 ../src/CState.h ../src/blocks/../CProgtest.h \
 ../src/blocks/../SPos.h ../src/blocks/../CAction.h \
 ../src/blocks/../actions/CMakeProgtest.h \
 ../src/blocks/../actions/../CAction.h \
 ../src/CState.h \
 ../src/blocks/../actions/../CProgtest.h \
 ../src/blocks/../actions/CSubmitProgtest.h
