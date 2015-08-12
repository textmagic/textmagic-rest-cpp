CXX=g++
JSONCPP_INCLUDE = include/jsoncpp
INCLUDE = -Iinclude -I$(JSONCPP_INCLUDE)

EXAPMPLE_SRC   = $(wildcard ./example/*.cpp)
ENTITY_SRC     = $(wildcard ./src/entity/*.cpp)
CONTROLLER_SRC = $(wildcard ./src/controller/*.cpp)
ENTITY_H       = $(wildcard ./include/entity/*.h)
CONTROLLER_H   = $(wildcard ./include/controller/*.h)

EXAPMPLE_AIMS   = $(subst ./example/,, $(EXAPMPLE_SRC:.cpp=_example))
ENTITY_AIMS     = $(subst ./src/entity/,, $(ENTITY_SRC:.cpp=_model.o))
CONTROLLER_AIMS = $(subst ./src/controller/,, $(CONTROLLER_SRC:.cpp=_controller.o))
LIBRARY_AIMS   = jsoncpp.o utils.o restclient.o textmagic.o

ENTITY_OBJ     = $(addprefix obj/, $(ENTITY_AIMS))
CONTROLLER_OBJ = $(addprefix obj/, $(CONTROLLER_AIMS))
LIBRARY_OBJ    = $(addprefix  obj/, $(LIBRARY_AIMS))

all: lib $(EXAPMPLE_AIMS)

%_example: %_example.o
		@echo $@
		$(CXX)  -o bin/$@  obj/$@.o -lcurl -L./lib -ltextmagic

lib: $(LIBRARY_AIMS) $(ENTITY_AIMS) $(CONTROLLER_AIMS)
		ar rcs lib/libtextmagic.a $(ENTITY_OBJ) $(CONTROLLER_OBJ) $(LIBRARY_OBJ)

clean:
		rm -rf bin/*
		rm -rf obj/*
		rm -rf lib/*

%_model.o: $(ENTITY_SRC)
		$(CXX)  -Wall -c -o obj/$(@F) $< $(INCLUDE)

%_controller.o: $(CONTROLLER_SRC)
		$(CXX)  -Wall -c -o obj/$(@F) $< $(INCLUDE)

%_example.o: ./example/%.cpp
		$(CXX)  -Wall -c -o obj/$(@F) $< $(INCLUDE)

restclient.o: src/restclient.cpp
		$(CXX)  -Wall -c -o obj/restclient.o src/restclient.cpp $(INCLUDE)

utils.o: src/utils.cpp
		$(CXX)  -Wall -c -o obj/utils.o src/utils.cpp $(INCLUDE)

textmagic.o: src/textmagic.cpp
		$(CXX)  -Wall -c -o obj/textmagic.o src/textmagic.cpp $(INCLUDE)

jsoncpp.o: $(JSONCPP_INCLUDE)/jsoncpp.cpp
		$(CXX)  -Wall -c -o obj/jsoncpp.o $(JSONCPP_INCLUDE)/jsoncpp.cpp -I$(JSONCPP_INCLUDE)



