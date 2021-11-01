all:
debug:
	g++ -c src/*.cpp -std=c++17 -g -Wall -m64 -Isrc/include && g++ -Lsrc/lib *.o -o bin/debug/main -lmingw32 -lSDL2main -lSDL2 -lSDL2_image
release:
	g++ -c src/*.cpp -std=c++17 -O3 -Wall -m64 -Isrc/include && g++ -Lsrc/lib *.o -o bin/release/main -s -lmingw32 -lSDL2main -lSDL2 -lSDL2_image