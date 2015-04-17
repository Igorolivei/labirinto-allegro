#include "casa.h"
#include "tabuleiro.h"
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

using namespace std;

void Tabuleiro::Iniciar(int largula, int altura) {

	this->largura = largula;
	this->altura = altura;

	//Cria um tabuleiro com a largura e altura definidas
	this->tabuleiro = new Casa::CasaTipo*[this->largura];
	for(int i = 0; i < this->largura; i++) {
		tabuleiro[i] = new Casa::CasaTipo[this->altura];
	}

}

void Tabuleiro::AlterarCasaTipo(int x, int y, Casa::CasaTipo tipo) {
	this->tabuleiro[x][y] = tipo;
}

void Tabuleiro::DesenharTabuleiro(){
	

	for(int i = 0; i < this->largura; i++) {
		for (int j = 0; j < this->altura; j++) {
			Casa *casa = new Casa();
			casa->AlterarTipo(this->tabuleiro[i][j]);
			//if (this->tabuleiro[i][j] == Casa::VISITADA) {
			//	al_draw_filled_rectangle(j*30,i*30,(j*30)+30,(i*30)+30,casa->cor);
			//}
			//else {
				al_draw_filled_rectangle(j*60,i*60,(j*60)+60,(i*60)+60,casa->cor);
			}
		}
		cout << endl;
	}

}

void Tabuleiro::Fim() {
	
	for(int i = 0; i < this->largura; i++) {
		for (int j = 0; j < this->altura; j++) {
			this->tabuleiro[i][j] = Casa::SAIDA;
		}
	}
}
