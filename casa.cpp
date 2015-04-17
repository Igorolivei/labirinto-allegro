#include "casa.h"
#include <iostream>

using namespace std;

void Casa::AlterarTipo(CasaTipo tipo){
	this->casa = tipo;

	al_init();
	
	//cor da casa
	switch(this->casa){
		case CHAO:
			this->cor = al_map_rgb(255,255,255);
			break;
		case PAREDE:
			this->cor = al_map_rgb(0,0,0);
			break;
		case VISITADA:
			this->cor = al_map_rgb(97,97,97);
			break;
		case ATUAL:
			this->cor = al_map_rgb(0,139,139);
			break;
		case SAIDA:
			this->cor = al_map_rgb(255,0,0);
			break;
	}
}

void Casa::ExibirCasa(){
	switch(this->casa){
		case CHAO:
			cout << "0";
			break;		
		case PAREDE:
			cout << "1";
			break;
		case VISITADA:
			cout << "2";
			break;
		case ATUAL:
			cout << "3";
			break;
		case SAIDA:
			cout << "4";
			break;		

	}
}
