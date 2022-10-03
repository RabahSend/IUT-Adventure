CXX=g++
CXXFLAGS=-Wall -c

prog.exe : src/main.o includes/ASCII.o includes/dialogues.o includes/terminal.o includes/TextGame.o
	$(CXX) -o prog.exe src/main.o includes/ASCII.o includes/dialogues.o includes/terminal.o includes/TextGame.o

main.o : src/main.cpp includes/ASCII.cpp includes/dialogues.cpp includes/dialogues.hpp includes/terminal.cpp includes/terminal.hpp includes/TextGame.cpp includes/TextGame.hpp
	$(CXX) $(CXXFLAGS) main.o src/main.cpp includes/ASCII.cpp includes/dialogues.cpp includes/terminal.cpp includes/TextGame.cpp

ASCII.o : includes/ASCII.cpp includes/TextGame.cpp includes/TextGame.hpp
	$(CXX) $(CXXFLAGS) ASCII.o includes/ASCII.cpp includes/TextGame.cpp

dialogues.o : includes/TextGame.cpp includes/TextGame.hpp includes/dialogues.cpp includes/dialogues.hpp
	$(CXX) $(CXXFLAGS) dialogues.o includes/TextGame.cpp

terminal.o : includes/terminal.cpp includes/terminal.hpp
	$(CXX) $(CXXFLAGS) terminal.o includes/terminal.cpp

TextGame.o : includes/TextGame.cpp includes/TextGame.hpp includes/dialogues.cpp includes/dialogues.hpp
	$(CXX) $(CXXFLAGS) TextGame.o includes/TextGame.cpp includes/dialogues.cpp