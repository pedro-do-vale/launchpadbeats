#include<stdio.h>
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>

/*Declarando variáveis globais*/
SDL_Window* janela = NULL;
SDL_Renderer* renderizador = NULL;
SDL_Texture* fundo = NULL;

/*Função usada para carregar as imagens para variáveis tipo textura*/
SDL_Texture* carrega_textura(char *caminho_img) {
	SDL_Texture* textura = NULL;
	
	SDL_Surface* imagem = IMG_Load(caminho_img);
	textura = SDL_CreateTextureFromSurface(renderizador, imagem);
	
	if(!imagem || !textura){
		
		printf("Nao foi possivel carregar a seguinte imagem: \n%s\nErro: %s\n", caminho_img, IMG_GetError());
		SDL_DestroyTexture(textura);
		SDL_FreeSurface(imagem);
		return 0;
	}

	return textura;
}


/*----- Função que gera a janela inicial de menu ----- */
SDL_Window* menu() {
		
	/*Criando janela principal*/	
	janela = SDL_CreateWindow("LaunchPad+ Beats 1.0", SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
	
	if(!janela)	{
		printf("Ocorreu um erro ao abrir a janela!\nErro: %s\n",SDL_GetError());
		return 0;
	}	
	
	/*Inicializando o renderizador na janela criada*/
	renderizador = SDL_CreateRenderer(janela,-1,SDL_RENDERER_ACCELERATED);
	if(!renderizador) {
		printf("Ocorreu um erro ao iniciar o renderizador!\nErro: %s\n",SDL_GetError());
		return 0;
	}			
		
	SDL_SetRendererDrawColor(renderizador, 255,0,0,255);
	
	/*Inicializando suporte para os formatos de imagens a serem usados. (PNG e JPEG)*/
	int img_flags = IMG_INIT_JPG | IMG_INIT_PNG;
	if(IMG_Init(img_flags) != img_flags){
		printf("O programa não conseguiu suporte para os formatos de imagem JPG e/ou PNG\nErro: %s\n", IMG_GetError() );
		return 0;
	}
	
	
	
}
