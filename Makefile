CXX=g++
CXXFLAGS=-Wall -c

prog.exe : main.o ASCII.o dialogues.o terminal.o TextGame.o
	$(CXX) -o prog.exe main.o ASCII.o dialogues.o terminal.o TextGame.o

	ASCII.o : ASCII.cpp TextGame.cpp TextGame.hpp
	$(CXX) $(CXXFLAGS) ASCII.o TextGame.cpp ASCII.cpp

dialogues.o : TextGame.cpp TextGame.hpp dialogues.cpp dialogues.hpp
	$(CXX) $(CXXFLAGS) dialogues.o TextGame.cpp

terminal.o : terminal.cpp terminal.hpp
	$(CXX) $(CXXFLAGS) terminal.o terminal.cpp

TextGame.o : TextGame.cpp TextGame.hpp dialogues.cpp dialogues.hpp
	$(CXX) $(CXXFLAGS) TextGame.o TextGame.cpp dialogues.cpp

main.o : ASCII.cpp dialogues.cpp dialogues.hpp terminal.cpp terminal.hpp TextGame.cpp TextGame.hpp
	$(CXX) $(CXXFLAGS) main.o ASCII.cpp dialogues.cpp terminal.cpp TextGame.cpp