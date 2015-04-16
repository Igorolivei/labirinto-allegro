#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>

#define LARGURA 800
#define ALTURA 600

int main() {

	ALLEGRO_DISPLAY *display;

	const float FPS = 60.0;
	bool draw = false;
	bool finalizar = false;

	if (!al_init()) {
		std::cout << "Erro inicializando allegro" << std::endl;
		return -1;		
	}

	al_set_new_display_flags(ALLEGRO_WINDOWED);

	display = al_create_display(LARGURA, ALTURA);

	if (!display) {
		std::cout << "Erro criando display" << std::endl;
		return -1;
	}


	al_init_primitives_addon();
	al_install_keyboard();


	ALLEGRO_TIMER *timer = al_create_timer(1 / FPS);
	ALLEGRO_EVENT_QUEUE *event_queue = al_create_event_queue();

	al_register_event_source(event_queue, al_get_keyboard_event_source());
	al_register_event_source(event_queue, al_get_timer_event_source(timer));

	ALLEGRO_COLOR azul = al_map_rgb(0, 0, 255);

	int x = 10, y = 10;
	float velocidade = 5;

	ALLEGRO_KEYBOARD_STATE keyboard_state;

	al_start_timer(timer);

	while (!finalizar) {

		ALLEGRO_EVENT event;
		al_wait_for_event(event_queue, &event);

		if (event.type == ALLEGRO_EVENT_KEY_DOWN) {
			switch (event.keyboard.keycode) {
				case ALLEGRO_KEY_ESCAPE:
					finalizar = true;
					break;
			}
		}

		if (event.type == ALLEGRO_EVENT_TIMER) {
			draw = true;
			al_get_keyboard_state(&keyboard_state);
			if (al_key_down(&keyboard_state, ALLEGRO_KEY_DOWN)) {
				y += velocidade;
				if (y >= ALTURA - 10) {
					y = ALTURA - 10;
				}
			}

			if (al_key_down(&keyboard_state, ALLEGRO_KEY_UP)) {
				y -= velocidade;
				if (y < 10) {
					y = 10;
				}
			}

			if (al_key_down(&keyboard_state, ALLEGRO_KEY_RIGHT)) {
				x += velocidade;
				if (x > LARGURA - 10) {
					x = LARGURA - 10;
				}				
			}

			if (al_key_down(&keyboard_state, ALLEGRO_KEY_LEFT)) {
				x -= velocidade;
				if (x <= 10) {
					x = 10;
				}
			}
		}

		if (draw) {
			al_draw_filled_circle(x, y, 10, azul);
			al_flip_display();
			al_clear_to_color(al_map_rgb(0,0,0));
		}
	}

	al_destroy_timer(timer);
	al_destroy_display(display);

	return 0;
}