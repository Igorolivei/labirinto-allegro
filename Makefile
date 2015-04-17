casa: casa.cpp casa.h
	g++ casa.cpp -c

tabuleiro: tabuleiro.cpp tabuleiro.h casa
	g++ tabuleiro.cpp -c

labirinto: labirinto.cpp casa tabuleiro
	g++ labirinto.cpp tabuleiro.o casa.o -o labirinto -lallegro -lallegro_primitives
	./labirinto

limpar:
	rm casa.o
