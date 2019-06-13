CXX = clang++

CLI-Arcade: main.o C4Game.o TTTGame.o HMGame.o
	$(CXX) main.o C4Game.o TTTGame.o HMGame.o -o CLI-Arcade

main.o: main.cpp C4Game.hpp TTTGame.hpp HMGame.hpp GameClass.hpp
	$(CXX) main.cpp -c

C4Game.o: C4Game.cpp C4Game.hpp
	$(CXX) C4Game.cpp -c

TTTGame.o: TTTGame.cpp TTTGame.hpp
	$(CXX) TTTGame.cpp -c

HMGame.o: HMGame.cpp HMGame.hpp
	$(CXX) HMGame.cpp -c
