CXX=g++
CXXFLAGS=-Wall -c

prog.exe : src/main.o includes/dialogues.o includes/terminal.o includes/TextGame.o Mobs_and_Persos/Entity.o
	$(CXX) -o prog.exe src/main.o includes/dialogues.o includes/terminal.o includes/TextGame.o Mobs_and_Persos/Entity.o

main.o : src/main.cpp includes/dialogues.cpp includes/dialogues.hpp includes/terminal.cpp includes/terminal.hpp includes/TextGame.cpp includes/TextGame.hpp
	$(CXX) $(CXXFLAGS) main.o src/main.cpp includes/dialogues.cpp includes/terminal.cpp includes/TextGame.cpp

Entity.o : Mobs_and_Persos/Entity.cpp Mobs_and_Persos/Entity.hpp includes/terminal.cpp includes/terminal.hpp
	$(CXX) $(CXXFLAGS) Entity.o Mobs_and_Persos/Entity.cpp includes/terminal.cpp

dialogues.o : includes/TextGame.cpp includes/TextGame.hpp includes/dialogues.cpp includes/dialogues.hpp
	$(CXX) $(CXXFLAGS) dialogues.o includes/TextGame.cpp

terminal.o : includes/terminal.cpp includes/terminal.hpp
	$(CXX) $(CXXFLAGS) terminal.o includes/terminal.cpp

TextGame.o : includes/TextGame.cpp includes/TextGame.hpp includes/dialogues.cpp includes/dialogues.hpp Mobs_and_Persos/Entity.cpp Mobs_and_Persos/Entity.hpp
	$(CXX) $(CXXFLAGS) TextGame.o includes/TextGame.cpp includes/dialogues.cpp Mobs_and_Persos/Entity.cpp