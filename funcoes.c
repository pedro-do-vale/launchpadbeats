#include "includes/padmaisbeats.h"
#define MAX 80

void mostraErro(char *msg){
	perror();
	exit(EXIT_FAILURE);
}
int insereCaminho(Mix_Chunk **botoes, unsigned short n, FILE *caminho){
	char str[MAX];
	for (i = 1; i <= n; i++){
		fgets(str, MAX, caminho);
		if(!(botoes[i] = Mix_LoadWAV(str)))
			Mix_GetError();
			return -1;
	}	

	return 0;
}
