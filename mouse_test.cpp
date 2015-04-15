#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <cmath>
#include "tabuleiro.h"

#define LARGURA 1000
#define ALTURA 600

using namespace std;
bool cores_iguais(ALLEGRO_COLOR c1, ALLEGRO_COLOR c2) {
	if (c1.r == c2.r && c1.g == c2.g && c1.b == c2.b && c1.a == c2.a) {
		return true;
	} else {
		return false;
	}
}

int main(int argc, char **argv) {

	ALLEGRO_DISPLAY *display;

	const float FPS = 60.0;
	bool draw = false;
	bool finalizar = false;

	Tabuleiro *tab = new Tabuleiro(LARGURA, ALTURA);
	tab->desenharTabuleiro();

	if (!al_init()) {
		cout << "Erro inicializando allegro" << endl;
		return -1;		
	}

	al_set_new_display_flags(ALLEGRO_WINDOWED);

	display = al_create_display(LARGURA, ALTURA);

	if (!display) {
		std::cout << "Erro criando display" << std::endl;
		return -1;
	}

	al_set_window_title(display, "NotA");




	al_init_primitives_addon();
	al_install_mouse();
	al_install_keyboard();	


	ALLEGRO_TIMER *timer = al_create_timer(1 / FPS);
	ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();

	al_register_event_source(event_queue, al_get_mouse_event_source());
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	ALLEGRO_COLOR azul = al_map_rgb(0, 0, 255);
	ALLEGRO_COLOR azul_claro = al_map_rgb(200, 200, 255);
	ALLEGRO_COLOR azul_escuro = al_map_rgb(0, 0, 100);
	ALLEGRO_COLOR vermelho = al_map_rgb(255, 0, 0);
	ALLEGRO_COLOR vermelho_escuro = al_map_rgb(100, 0, 0);
	ALLEGRO_COLOR vermelho_claro = al_map_rgb(255, 200, 200);
	ALLEGRO_COLOR verde = al_map_rgb(0, 255, 0);
	ALLEGRO_COLOR verde_claro = al_map_rgb(200, 255, 200);
	ALLEGRO_COLOR verde_escuro = al_map_rgb(0, 100, 0);
	ALLEGRO_COLOR cinza_25 = al_map_rgb(64, 64, 64);
	ALLEGRO_COLOR cinza_50 = al_map_rgb(127, 127, 127);
	ALLEGRO_COLOR cinza_75 = al_map_rgb(191, 191, 191);
	ALLEGRO_COLOR cinza_90 = al_map_rgb(230, 230, 230);
	ALLEGRO_COLOR cor_atual = azul;


	double x = 10, y = 10;
	double destino_x = 10, destino_y = 10;
	float velocidade = 2;

	al_start_timer(timer);

	while (!finalizar) {

		ALLEGRO_EVENT event;
		al_wait_for_event(event_queue, &event);

		if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
			ALLEGRO_MOUSE_STATE mouse_state;
			switch (event.keyboard.keycode) {
				case ALLEGRO_KEY_Q:
					al_get_mouse_state(&mouse_state);
					campeao1->atirar(mouse_state.x, mouse_state.y);
					cout << "ATIRANDO EM " << mouse_state.x << "," << mouse_state.y << endl;
					break;
				case ALLEGRO_KEY_ESCAPE:
					finalizar = true;
					break;
			}
		} else if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
			finalizar = true;
		} else if (event.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN) {
			if (event.mouse.button & 1) {
				if (cores_iguais(cor_atual, vermelho)) {
					cor_atual = azul;
				} else {
					cor_atual = vermelho;
				}
			}
			if (event.mouse.button & 2) {
				cout << "MOUSE 2: " << event.mouse.x << "," << event.mouse.y << endl;
				destino_x = event.mouse.x;
				destino_y = event.mouse.y;
			}
		} else if (event.type == ALLEGRO_EVENT_TIMER) {
			draw = true;
			//atualiza_posicao(x, y, destino_x, destino_y, velocidade);
		}

		if (draw) {
			// calcular nova posicao
			draw = false;
			double novo_x, novo_y;
			ponto_entre_pontos(campeao1->posicao_x, campeao1->posicao_y, destino_x, destino_y, velocidade, novo_x, novo_y);
			campeao1->posicao_x = novo_x;
			campeao1->posicao_y = novo_y;
			cout << "(" << campeao1->posicao_x << "," << campeao1->posicao_y << ")" << endl;

			// desenhar campeao1
			al_draw_filled_circle(campeao1->posicao_x, campeao1->posicao_y, 10, cor_atual);
			al_flip_display();
			al_clear_to_color(al_map_rgb(255,255, 255));

			// desenhar projeteis
			for (int ptr = 0; ptr < mapa->projeteis_ptr; ptr++) {
				Projetil *projetil = mapa->projeteis_no_mapa[ptr];

				al_draw_line(projetil->origem_x, projetil->origem_y, projetil->destino_x, projetil->destino_y, cinza_90, 1);
				al_draw_filled_circle(projetil->posicao_x, projetil->posicao_y, 4, vermelho);

			}

			mapa->avancar_tempo();// colocar movimento dos campeoes aqui
		}
	}

	al_destroy_timer(timer);
	al_destroy_display(display);

	return 0;
}
