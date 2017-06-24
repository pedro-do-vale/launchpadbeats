#include "includes/padmaisbeats.h"
#define MAX 80

void mostraErro(char *msg){
	perror();
	exit(EXIT_FAILURE);
}

int insereCaminho(Mix_Chunk **botoes, unsigned short n, FILE **caminho){
	char
	  str[MAX];/*buffer dos caminhos*/
	/* Para cada linha do arquivo, recebo o caminho listado na linha x e
	 * adiciono ele aos botoes, já carregando o áudio respectivo*/
	for ( i = 1; i <= n; i++ ){
		__fpurge(*caminho);
		fgets(str, MAX, *caminho);
		if( feof(*caminho) )
			break;
		else if(!(botoes[i] = Mix_LoadWAV(str))){
			fprintf(stdout ,"Falha ao associar botoes %s ",Mix_GetError();
			return -1;
		}
	}
	return 0;
}

int alocaCanais(CanalAtual **_botao, unsigned short numCaminhos, int (*fptr_AllocateChannels)(int)){
	int
	  i;
	
	/*Aloco os canais necessários para reprodução dos áudios*/
	(*fptr_AllocateChannels)((int) numCaminhos); /*Aloco o numero de canais necessários*/
		
	/*Aloco a estrutura de canais para numCaminhos+1 pois o ultimo canal será canal de loop*/
	if ( !(*_botao = (CanalAtual *) malloc(sizeof(CanalAtual) * (numCaminhos))) ){
		perror("Falha ao alocar: ");
		return -1;	
	}
	else{
		/*Associo cada botao ao respectivo canal*/
		for ( i = 1; i <= numCaminhos; i++ ){
			(*_botao + i)->canal = i;
			/* botao[PAD_Q] recebe 1, q é seu canal.
			 * botao[PAD_W] recebe 2, q é seu canal... e por aí vai...
			 */
		}
	}
	return 0;
}

