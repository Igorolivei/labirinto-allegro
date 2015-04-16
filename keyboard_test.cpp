#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_primitives.h>

#define LARGURA 800
#define ALTURA 600

int main() {

	ALLEGRO_DISPLAY *display;

	const float FPS = 60.0;

	bool draw = false;

	enum Direction { UP, DOWN, RIGHT, LEFT };

	if (!al_init()) {
		al_show_native_message_box(NULL, NULL, NULL, "Não pode iniciar o Allegro", NULL, 0);

		return -1;
	}

	al_set_new_display_flags(ALLEGRO_WINDOWED);

	display = al_create_display(LARGURA, ALTURA);
	al_set_window_title(display, "Labirinto legal :D");
	al_init_primitives_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_install_keyboard();

	if (!display) {
		al_show_native_message_box(display, "Olá", "Opções do display", "Mensage,", NULL, 0);
	}

	// Criando fontes e textos
	ALLEGRO_FONT *font = al_load_font("primetime.ttf", 24, 0);
	al_draw_text(font, al_map_rgb(255, 0, 0), 10, 10, ALLEGRO_ALIGN_LEFT, "NotA");
	
	// Mostra na tela o que está no buffer do display
	al_flip_display();


	// ****** PRIMITIVAS ******
	ALLEGRO_COLOR azul = al_map_rgb(0, 0, 255);
	ALLEGRO_COLOR verde = al_map_rgb(0, 255, 0);
	ALLEGRO_COLOR vermelho = al_map_rgb(255, 0, 0);

	// ***** RECEBENDO EVENTOS *****

	// Fila de eventos criada
	ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();

	// registrando o teclado na fila de eventos
	al_register_event_source(event_queue, al_get_keyboard_event_source());

	// timer event
	ALLEGRO_TIMER *timer = al_create_timer( 1.0 / FPS );
	al_register_event_source(event_queue, al_get_timer_event_source(timer));


	// Game loop
	bool finalizado = false;
	int x = 10, y = 10;
	float velocidade = 5;
	Direction direcao = DOWN;

	al_start_timer(timer);

	while (!finalizado) {

		// Espera por um evento (tecla pressionado por exemplo)
		ALLEGRO_EVENT events;
		al_wait_for_event(event_queue, &events);
		const char *texto = "";


		// Verifica o tipo de evento é "tecla pressionada"
		if (events.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch (events.keyboard.keycode) {
				case ALLEGRO_KEY_DOWN:
					direcao = DOWN;
					break;
				case ALLEGRO_KEY_UP:
					direcao = UP;
					break;
				case ALLEGRO_KEY_RIGHT:
					direcao = RIGHT;
					break;
				case ALLEGRO_KEY_LEFT:
					direcao = LEFT;
					break;
				case ALLEGRO_KEY_ESCAPE:
					finalizado = true;
					break;
				default:
					texto = "";

			}
		}

		if (events.type == ALLEGRO_EVENT_TIMER) {
			switch (direcao) {
				case DOWN:
					y += velocidade;
					break;
				case UP:
					y -= velocidade;
					break;
				case RIGHT:
					x += velocidade;
					break;
				case LEFT:
					x -= velocidade;
					break;
			}

			draw = true;
		}


		if (draw) {
			draw = false;
			// desenha retanguo 20x20 na posicao x,y nova
			//al_draw_rectangle(x, y, x+20, y+20, azul, 1);
			al_draw_filled_circle(x, y, 20, azul);
			// Mostra na tela o que está no buffer do display
			al_flip_display();
			// preenche o buffer com preto
			al_clear_to_color(al_map_rgb(0,0,0));
		}

	}


	al_destroy_display(display);
	return  0;
}	

