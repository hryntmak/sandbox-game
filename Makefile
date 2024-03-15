CXX=g++
CXXFLAGS=-Wall -pedantic
LD=g++
LDFLAGS=-Wall -pedantic
HEADERS = $(wildcard src/*.h src/actions/*.h src/blocks/*.h)
SOURCES = $(wildcard src/*.cpp src/blocks/*.cpp src/actions/*cpp)
OBJS=$(subst .cpp,.o,$(SOURCES))

all: compile doc

run: compile
	./hryntmak

compile: hryntmak

hryntmak: $(OBJS)
	$(LD) $(LDFLAGS) $(OBJS) -o hryntmak

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

doc: Doxyfile $(HEADERS)
	doxygen Doxyfile

clean:
	rm -rf hryntmak src/*.o src/blocks/*.o src/actions/*.o doc/ *~ core


CAction.o: src/CAction.cpp src/CAction.h src/SState.h src/SProgtest.h
CApplication.o: src/CApplication.cpp src/CApplication.h src/CGame.h \
 src/CMap.h src/CBlock.h src/SState.h src/SProgtest.h src/SPos.h \
 src/CAction.h src/blocks/CBedBlock.h src/blocks/../CBlock.h \
 src/blocks/../SState.h src/blocks/../SProgtest.h src/blocks/../SPos.h \
 src/blocks/../CAction.h src/blocks/CAirBlock.h \
 src/blocks/CComputerBlock.h src/blocks/CSolidBlock.h \
 src/blocks/CGeneratorBlock.h src/blocks/CMushroomBlock.h \
 src/blocks/CTreeBlock.h src/blocks/CWaterBlock.h src/CBlockAggregator.h \
 src/blocks/CCorruptionBlock.h src/CPlayer.h
CBlockAggregator.o: src/CBlockAggregator.cpp src/CBlockAggregator.h \
 src/CBlock.h src/SState.h src/SProgtest.h src/SPos.h src/CAction.h \
 src/blocks/CBedBlock.h src/blocks/../CBlock.h src/blocks/../SState.h \
 src/blocks/../SProgtest.h src/blocks/../SPos.h src/blocks/../CAction.h \
 src/blocks/CAirBlock.h src/blocks/CComputerBlock.h \
 src/blocks/CSolidBlock.h src/blocks/CGeneratorBlock.h \
 src/blocks/CMushroomBlock.h src/blocks/CTreeBlock.h \
 src/blocks/CWaterBlock.h src/blocks/CCorruptionBlock.h src/CConfig.h
CBlock.o: src/CBlock.cpp src/CBlock.h src/SState.h src/SProgtest.h \
 src/SPos.h src/CAction.h
CConfig.o: src/CConfig.cpp src/CConfig.h
CGame.o: src/CGame.cpp src/CGame.h src/CMap.h src/CBlock.h src/SState.h \
 src/SProgtest.h src/SPos.h src/CAction.h src/blocks/CBedBlock.h \
 src/blocks/../CBlock.h src/blocks/../SState.h src/blocks/../SProgtest.h \
 src/blocks/../SPos.h src/blocks/../CAction.h src/blocks/CAirBlock.h \
 src/blocks/CComputerBlock.h src/blocks/CSolidBlock.h \
 src/blocks/CGeneratorBlock.h src/blocks/CMushroomBlock.h \
 src/blocks/CTreeBlock.h src/blocks/CWaterBlock.h src/CBlockAggregator.h \
 src/blocks/CCorruptionBlock.h src/CPlayer.h src/actions/CNoAction.h \
 src/actions/../CAction.h src/actions/../SState.h \
 src/actions/../SProgtest.h
CMap.o: src/CMap.cpp src/CMap.h src/CBlock.h src/SState.h src/SProgtest.h \
 src/SPos.h src/CAction.h src/blocks/CBedBlock.h src/blocks/../CBlock.h \
 src/blocks/../SState.h src/blocks/../SProgtest.h src/blocks/../SPos.h \
 src/blocks/../CAction.h src/blocks/CAirBlock.h \
 src/blocks/CComputerBlock.h src/blocks/CSolidBlock.h \
 src/blocks/CGeneratorBlock.h src/blocks/CMushroomBlock.h \
 src/blocks/CTreeBlock.h src/blocks/CWaterBlock.h src/CBlockAggregator.h \
 src/blocks/CCorruptionBlock.h src/CPlayer.h src/actions/CEnergyAction.h \
 src/actions/../CAction.h src/actions/../SState.h \
 src/actions/../SProgtest.h
CPlayer.o: src/CPlayer.cpp src/CPlayer.h src/SState.h src/CBlock.h \
 src/SProgtest.h src/SPos.h src/CAction.h src/CBlockAggregator.h \
 src/blocks/CBedBlock.h src/blocks/../CBlock.h src/blocks/../SState.h \
 src/blocks/../SProgtest.h src/blocks/../SPos.h src/blocks/../CAction.h \
 src/blocks/CAirBlock.h src/blocks/CComputerBlock.h \
 src/blocks/CSolidBlock.h src/blocks/CGeneratorBlock.h \
 src/blocks/CMushroomBlock.h src/blocks/CTreeBlock.h \
 src/blocks/CWaterBlock.h src/blocks/CCorruptionBlock.h src/CConfig.h \
 src/actions/CNoAction.h src/actions/../CAction.h src/actions/../SState.h \
 src/actions/../SProgtest.h
main.o: src/main.cpp src/CApplication.h src/CGame.h src/CMap.h \
 src/CBlock.h src/SState.h src/SProgtest.h src/SPos.h src/CAction.h \
 src/blocks/CBedBlock.h src/blocks/../CBlock.h src/blocks/../SState.h \
 src/blocks/../SProgtest.h src/blocks/../SPos.h src/blocks/../CAction.h \
 src/blocks/CAirBlock.h src/blocks/CComputerBlock.h \
 src/blocks/CSolidBlock.h src/blocks/CGeneratorBlock.h \
 src/blocks/CMushroomBlock.h src/blocks/CTreeBlock.h \
 src/blocks/CWaterBlock.h src/CBlockAggregator.h \
 src/blocks/CCorruptionBlock.h src/CPlayer.h
SPos.o: src/SPos.cpp src/SPos.h
SProgtest.o: src/SProgtest.cpp src/SProgtest.h src/CConfig.h
SState.o: src/SState.cpp src/SState.h src/CConfig.h
CBurn.o: src/actions/CBurn.cpp src/actions/CBurn.h \
 src/actions/../CAction.h src/actions/../SState.h \
 src/actions/../SProgtest.h
CEnergyAction.o: src/actions/CEnergyAction.cpp \
 src/actions/CEnergyAction.h src/actions/../CAction.h \
 src/actions/../SState.h src/actions/../SProgtest.h
CMakeProgtest.o: src/actions/CMakeProgtest.cpp \
 src/actions/CMakeProgtest.h src/actions/../CAction.h \
 src/actions/../SState.h src/actions/../SProgtest.h
CNoAction.o: src/actions/CNoAction.cpp src/actions/CNoAction.h \
 src/actions/../CAction.h src/actions/../SState.h \
 src/actions/../SProgtest.h
CSkipDay.o: src/actions/CSkipDay.cpp src/actions/CSkipDay.h \
 src/actions/../CAction.h src/actions/../SState.h \
 src/actions/../SProgtest.h
CSubmitProgtest.o: src/actions/CSubmitProgtest.cpp \
 src/actions/CSubmitProgtest.h src/actions/../CAction.h \
 src/actions/../SState.h src/actions/../SProgtest.h
CTakeDamage.o: src/actions/CTakeDamage.cpp src/actions/CTakeDamage.h \
 src/actions/../CAction.h src/actions/../SState.h \
 src/actions/../SProgtest.h
CAirBlock.o: src/blocks/CAirBlock.cpp src/blocks/CAirBlock.h \
 src/blocks/../CBlock.h src/blocks/../SState.h src/blocks/../SProgtest.h \
 src/blocks/../SPos.h src/blocks/../CAction.h \
 src/blocks/../actions/CNoAction.h src/blocks/../actions/../CAction.h \
 src/blocks/../actions/../SState.h src/blocks/../actions/../SProgtest.h
CBedBlock.o: src/blocks/CBedBlock.cpp src/blocks/CBedBlock.h \
 src/blocks/../CBlock.h src/blocks/../SState.h src/blocks/../SProgtest.h \
 src/blocks/../SPos.h src/blocks/../CAction.h \
 src/blocks/../actions/CSkipDay.h src/blocks/../actions/../CAction.h \
 src/blocks/../actions/../SState.h src/blocks/../actions/../SProgtest.h
CComputerBlock.o: src/blocks/CComputerBlock.cpp \
 src/blocks/CComputerBlock.h src/blocks/../CBlock.h \
 src/blocks/../SState.h src/blocks/../SProgtest.h src/blocks/../SPos.h \
 src/blocks/../CAction.h src/blocks/../CConfig.h \
 src/blocks/../actions/CMakeProgtest.h src/blocks/../actions/../CAction.h \
 src/blocks/../actions/../SState.h src/blocks/../actions/../SProgtest.h \
 src/blocks/../actions/CSubmitProgtest.h \
 src/blocks/../actions/CNoAction.h
CCorruptionBlock.o: src/blocks/CCorruptionBlock.cpp \
 src/blocks/CCorruptionBlock.h src/blocks/../CBlock.h \
 src/blocks/../SState.h src/blocks/../SProgtest.h src/blocks/../SPos.h \
 src/blocks/../CAction.h src/blocks/../actions/CTakeDamage.h \
 src/blocks/../actions/../CAction.h src/blocks/../actions/../SState.h \
 src/blocks/../actions/../SProgtest.h
CGeneratorBlock.o: src/blocks/CGeneratorBlock.cpp \
 src/blocks/CGeneratorBlock.h src/blocks/../CBlock.h \
 src/blocks/../SState.h src/blocks/../SProgtest.h src/blocks/../SPos.h \
 src/blocks/../CAction.h src/blocks/../actions/CBurn.h \
 src/blocks/../actions/../CAction.h src/blocks/../actions/../SState.h \
 src/blocks/../actions/../SProgtest.h src/blocks/../blocks/CAirBlock.h \
 src/blocks/../blocks/../CBlock.h src/blocks/../blocks/../SState.h \
 src/blocks/../blocks/../SProgtest.h src/blocks/../blocks/../SPos.h \
 src/blocks/../blocks/../CAction.h
CMushroomBlock.o: src/blocks/CMushroomBlock.cpp \
 src/blocks/CMushroomBlock.h src/blocks/../CBlock.h \
 src/blocks/../SState.h src/blocks/../SProgtest.h src/blocks/../SPos.h \
 src/blocks/../CAction.h src/blocks/../actions/CNoAction.h \
 src/blocks/../actions/../CAction.h src/blocks/../actions/../SState.h \
 src/blocks/../actions/../SProgtest.h \
 src/blocks/../actions/CEnergyAction.h
CSolidBlock.o: src/blocks/CSolidBlock.cpp src/blocks/CSolidBlock.h \
 src/blocks/../CBlock.h src/blocks/../SState.h src/blocks/../SProgtest.h \
 src/blocks/../SPos.h src/blocks/../CAction.h \
 src/blocks/../actions/CNoAction.h src/blocks/../actions/../CAction.h \
 src/blocks/../actions/../SState.h src/blocks/../actions/../SProgtest.h
CTreeBlock.o: src/blocks/CTreeBlock.cpp src/blocks/CTreeBlock.h \
 src/blocks/../CBlock.h src/blocks/../SState.h src/blocks/../SProgtest.h \
 src/blocks/../SPos.h src/blocks/../CAction.h \
 src/blocks/../actions/CNoAction.h src/blocks/../actions/../CAction.h \
 src/blocks/../actions/../SState.h src/blocks/../actions/../SProgtest.h
CWaterBlock.o: src/blocks/CWaterBlock.cpp src/blocks/CWaterBlock.h \
 src/blocks/../CBlock.h src/blocks/../SState.h src/blocks/../SProgtest.h \
 src/blocks/../SPos.h src/blocks/../CAction.h \
 src/blocks/../actions/CNoAction.h src/blocks/../actions/../CAction.h \
 src/blocks/../actions/../SState.h src/blocks/../actions/../SProgtest.h \
 src/blocks/../actions/CEnergyAction.h
