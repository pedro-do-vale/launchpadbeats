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

int alocaCanais(CanalAtual **_botao, unsigned short numCaminhos, int (*fptr_AllocateChannels)(int)){
	int i, retorno = 0;
	
	(*fptr_AllocateChannels)(numCaminhos) /*Aloco o numero de canais necessários*/
		
	if(!(*botao = (CanalAtual *) malloc(sizeof(CanalAtual) * (numCaminhos+1)))){
		perror("Falha ao alocar: ");
		return -1;	
	}
	else{
		for (i = 1; i <= numCaminhos; i++){
			(*botao + i)->canal = i;
		}
	}

}

