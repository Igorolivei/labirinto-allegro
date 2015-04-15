labirinto: labirinto.cpp
	g++ labirinto.cpp -o labirinto -lallegro -lallegro_dialog -lallegro_font -lallegro_ttf -lallegro_primitives

keyboard_test: keyboard_test.cpp
	g++ keyboard_test.cpp -o keyboard_test -lallegro -lallegro_dialog -lallegro_font -lallegro_ttf -lallegro_primitives


keyboard_test2: keyboard_test2.cpp
	g++ keyboard_test2.cpp -o keyboard_test2 -lallegro -lallegro_dialog -lallegro_font -lallegro_ttf -lallegro_primitives


mouse_test: mouse_test.cpp
	g++ mouse_test.cpp -o mouse_test -lallegro -lallegro_dialog -lallegro_font -lallegro_ttf -lallegro_primitives -lm -lallegro_main

tabuleiro.o: tabuleiro.h tabuleiro.cpp
	g++ tabuleiro.cpp -c

casa.o: casa.h casa.cpp
	g++ casa.cpp -c

gameutils.o: gameutils.h gameutils.cpp
	g++ gameutils.cpp -c

mouse_test: mouse_test.cpp mapa.o campeao.o projetil.o gameutils.o
	g++ mouse_test.cpp mapa.o campeao.o projetil.o gameutils.o -o mouse_test -lallegro -lallegro_dialog -lallegro_font -lallegro_ttf -lallegro_primitives -lm -lallegro_main

clean:
	rm *.o allegro_test1 keyboard_test keyboard_test mouse_test
