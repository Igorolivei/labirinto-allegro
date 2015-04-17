#include "casa.h"
#include "tabuleiro.h"
#include <allegro5/allegro.h>
#include <iostream>

using namespace std;

int main(void){

	ALLEGRO_DISPLAY *display;

	al_init();
	al_init_primitives_addon();
	al_set_new_display_flags(ALLEGRO_WINDOWED);
	display = al_create_display(600, 600);

	int x = 0;
	int y = 0;

	Tabuleiro *tabuleiro = new Tabuleiro();

	tabuleiro->Iniciar(10,10);

	int TabuleiroAux[10][10] = {
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

	for (int i = 0; i < 10; i ++){
		for (int j = 0; j < 10; j ++){
			if (TabuleiroAux[i][j] == 0)
		            tabuleiro->AlterarCasaTipo(i,j,Casa::CHAO);
		        if (TabuleiroAux[i][j] == 1)
		            tabuleiro->AlterarCasaTipo(i,j,Casa::PAREDE);
			if (TabuleiroAux[i][j] == 2)
		            tabuleiro->AlterarCasaTipo(i,j,Casa::VISITADA);
		        if (TabuleiroAux[i][j] == 3)
		            tabuleiro->AlterarCasaTipo(i,j,Casa::ATUAL);
		        if (TabuleiroAux[i][j] == 4)
		            tabuleiro->AlterarCasaTipo(i,j,Casa::SAIDA);
		}
	}

	tabuleiro->DesenharTabuleiro();

	bool finalizado = false;
	bool draw = false;
	enum Direction { UP, DOWN, RIGHT, LEFT };

	if(!al_install_keyboard()){
		cout << "Falha ao iniciar teclado!";
		return -1;
	}

    	al_flip_display();

	ALLEGRO_EVENT events;

	ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();
	float fps = 30;
	ALLEGRO_TIMER *timer = al_create_timer(1.0 / fps);

	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	al_start_timer(timer);

	while(!finalizado){
		
		al_wait_for_event(event_queue, &events);

		if(events.type == ALLEGRO_EVENT_TIMER) {

			if(draw) {
				draw = false;
				tabuleiro->DesenharTabuleiro();
				al_flip_display();
			}

		}
		else if (events.type == ALLEGRO_EVENT_KEY_DOWN) {
			draw = true;
			switch (events.keyboard.keycode) {
				case ALLEGRO_KEY_UP:// or ALLEGRO_KEY_W:
					if(tabuleiro->tabuleiro[x-1][y] == Casa::SAIDA){
						tabuleiro->Fim();
						finalizado = true;
					}
					if(tabuleiro->tabuleiro[x-1][y] == Casa::CHAO){
						tabuleiro->AlterarCasaTipo(x,y,Casa::VISITADA);
						tabuleiro->AlterarCasaTipo(x--,y,Casa::ATUAL);
					}
					break;
				case ALLEGRO_KEY_DOWN:// or ALLEGRO_KEY_S:
					if(tabuleiro->tabuleiro[x+1][y] == Casa::SAIDA){
						tabuleiro->Fim();
						finalizado = true;
					}
					if(tabuleiro->tabuleiro[x+1][y] == Casa::CHAO){
						tabuleiro->AlterarCasaTipo(x,y,Casa::VISITADA);
						tabuleiro->AlterarCasaTipo(x++,y,Casa::ATUAL);
					}
					break;
				case ALLEGRO_KEY_LEFT:// or ALLEGRO_KEY_A:
					if(tabuleiro->tabuleiro[x][y-1] == Casa::SAIDA){
						tabuleiro->Fim();
						finalizado = true;
					}
					if(tabuleiro->tabuleiro[x][y-1] == Casa::CHAO){
						tabuleiro->AlterarCasaTipo(x,y,Casa::VISITADA);
						tabuleiro->AlterarCasaTipo(x,y--,Casa::ATUAL);
					}
					break;
				case ALLEGRO_KEY_RIGHT:// or ALLEGRO_KEY_D:
					if(tabuleiro->tabuleiro[x][y+1] == Casa::SAIDA){
						tabuleiro->Fim();
						finalizado = true;
					}
					if(tabuleiro->tabuleiro[x][y+1] == Casa::CHAO){
						tabuleiro->AlterarCasaTipo(x,y,Casa::VISITADA);
						tabuleiro->AlterarCasaTipo(x,y++,Casa::ATUAL);
					}
					break;
				case ALLEGRO_KEY_ESCAPE:
					finalizado = true;
					al_destroy_display(display);
					return 0;
					break;
			}
			
		}
	}

	tabuleiro->DesenharTabuleiro();
	al_flip_display();
	al_rest(1.0);
	al_destroy_display(display);
	return 0;
}
