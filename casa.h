#ifndef _CASA_H_
#define _CASA_H_

#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

class Casa {

	public:
		enum CasaTipo {
			CHAO,
			PAREDE,
			VISITADA,
			ATUAL,
			SAIDA
		};
		
		CasaTipo casa;
		ALLEGRO_COLOR cor;

	void AlterarTipo(CasaTipo tipo);

	void ExibirCasa();
};

#endif
