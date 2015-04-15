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

	if (!al_init()) {
		al_show_native_message_box(NULL, NULL, NULL, "Não pode iniciar o Allegro", NULL, 0);

		return -1;
	}

	// Setando tipo de janela a ser criada
	//al_set_new_display_flags(ALLEGRO_FULLSCREEN_WINDOW);
	//al_set_new_display_flags(ALLEGRO_OPENGL);
	//al_set_new_display_flags(ALLEGRO_OPENGL);
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


	// ****** PRIMITIVAS ******
	ALLEGRO_COLOR azul = al_map_rgb(0, 0, 255);
	ALLEGRO_COLOR verde = al_map_rgb(0, 255, 0);
	ALLEGRO_COLOR vermelho = al_map_rgb(255, 0, 0);


	al_draw_rectangle(50, 50, 80, 90, vermelho, 2);

	al_draw_triangle(100, 100, 150, 150, 180, 100, verde, 2);

	al_draw_circle(200, 200, 20, azul, 2);
	
	al_draw_filled_circle(250, 250, 30, azul);

	al_draw_ellipse(300, 300, 40, 20, verde, 2);

	al_draw_line(10, 300, 30, 250, verde, 5);

	al_draw_pixel(10, 400, vermelho);
	al_draw_pixel(15, 400, vermelho);
	al_draw_pixel(20, 400, vermelho);

	// desenha pontos (pares x, y) até 4 pares;
	float pontos[] = {300, 10, 325, 50, 350, 10, 450, 20};
	al_draw_spline(pontos, verde, 2);


	// Mostra na tela o que está no buffer do display
	al_flip_display();


	al_rest(2);
	al_destroy_display(display);
	return  0;
}	
