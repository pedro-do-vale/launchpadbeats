#include "interface.h"

int main(int argc, char **argv) {
	short int running = 1;
	SDL_Event eventos;
	SDL_Window *janela = NULL;
	
	if(SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("Um problema ocorreu durante a inicializacao do sistema de video SDL\nERRO: %s\n",SDL_GetError());
		exit(1);
	}
	
	if( !(janela = menu()) ) 
		exit(1);
	
	while(running) {
		while(SDL_PollEvent(&eventos)) {
			if(eventos.type == SDL_QUIT)
				running = 0;
		}	
	}
	
	SDL_DestroyWindow(janela);
	SDL_Quit();
	
return 0;	
}
