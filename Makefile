bin/main.exe : src/MainPOO.cpp src/Food.cpp src/Snake.cpp
	g++ -o bin/main src/MainPOO.cpp src/Food.cpp src/Snake.cpp -Iinclude

run : bin/main.exe
	./bin/main.exe