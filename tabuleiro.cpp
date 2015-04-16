#include "tabuleiro.h"

Tabuleiro::Tabuleiro(int largura, int altura) {
  this->largura = largura;
  this->altura = altura;
}

void Tabuleiro::DesenharTabuleiro() {
	int tabuleiro[10][10] = {
		3, 0, 0, 0, 0, 0, 1, 0, 0, 0,
		0, 1, 1, 1, 0, 1, 1, 0, 1, 1,
		0, 0, 0, 1, 0, 0, 1, 0, 0, 0,
		1, 1, 0, 1, 1, 0, 1, 1, 1, 0,
		0, 1, 0, 0, 1, 1, 1, 0, 0, 0,
		0, 1, 1, 0, 0, 0, 0, 0, 1, 1,
		0, 0, 1, 1, 1, 0, 1, 0, 0, 0,
		0, 0, 0, 0, 1, 0, 0, 0, 1, 0,
		1, 1, 1, 0, 0, 0, 0, 1, 1, 0,
		0, 0, 0, 0, 0, 1, 0, 0, 1, 4};

	for (i = 0; i < 10; i ++){
		for (j = 0; j < 10; j ++){
			if (tabuleiro[i][j] == 0)
		            printf("   ");
		        if (tabuleiro[i][j] == 1)
		            printf(" # ");
		        if (tabuleiro[i][j] == 3)
		            printf(" * ");
		        if (tabuleiro[i][j] == 4)
		            printf(" $ ");
		}
		printf("\n");
	}
	return 0;
}
