#include "includes/padmaisbeats.h"

main (int argc, char **argv){
	
	unsigned short numCaminhos, count;
	unsigned int indice = 0;
	int i, pagAtual = 0;
	char *caminho = "exemplo.txt";
	FILE *lista_arquivos = fopen(caminho, "r");
	Mix_Chunk **botao;/*vetor de audios*/
	CanalAtual *canais;
	
	/*Alocação de botoes*/
	if (!(botao  = (Mix_Chunk **) malloc(sizeof(Mix_Chunk*) * (numCaminhos+1)))){
		mostraErro("Falha ao alocar: ");
	}
	else{
		for (i = 0; i <= noAlocado; i++){
			if(!(botao[i] = (Mix_Chunk *) malloc(sizeof(Mix_Chunk))))
				mostraErro("Falha ao alocar: ");
		}
	}

	/*Passo os caminhos para o arquivo de audio associado aos botoes*/
	/*Checo se houve erro*/
	if (insereCaminho(botao, numCaminhos, listaudio) < 0)
		mostraErro("Falha ao inserir caminhos nos botoes: ");
		
	indice = 12 * PAG + retorno;
		
	alocaCanais(&canais, numCaminhos, Mix_AllocateChannels);
	
	Mix.PlayChannel(canais[indice].canal, botao[indice], 0);
		
		
	free(botao);
	fclose(listaudio);
	Mix_CloseAudio();
	Mix_Quit();
	return 0;
}
