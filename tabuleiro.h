#ifndef _TABULEIRO_H_
#define _TABULEIRO_H_

#include "casa.h"

class Tabuleiro{

	public:
		int largura;
		int altura;
		Casa::CasaTipo **tabuleiro;

	void Iniciar(int largura, int altura);

	void AlterarCasaTipo(int x, int y, Casa::CasaTipo tipo);

	void DesenharTabuleiro();

	void Fim();
};

#endif
