all:
pch:
	g++ -x c++-header -c src/include/mainpch.h -o src/include/mainpch.h.gch
debug:
	g++ -O0 -c src/*.cpp -c src/Renderer/*.cpp -std=c++17 -g -Wall -m64 -Isrc/include && g++ -Lsrc/lib *.o -o bin/debug/main -lmingw32 -lopengl32 -lSDL2main -lSDL2 -lSDL2_image
release:
	g++ -c src/*.cpp -c src/ImGui/*.cpp -c src/*.c -c src/Renderer/*.cpp -std=c++17 -O3 -Wall -m64 -Isrc/include && g++ -Lsrc/lib *.o -o bin/release/main -s -lmingw32 -lopengl32 -lSDL2main -lSDL2 -lSDL2_image
clean:
	rm -rf *.o