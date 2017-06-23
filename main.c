#include "includes/padmaisbeats.h"

main (int argc, char **argv){
	
	int i, pagAtual = 0;
	/*Dados para controle do caminho dos audios/*/
	char *caminho = "exemplo.txt";
	FILE *lista_arquivos = fopen(caminho, "r");
	/*vetor de audios*/
	Mix_Chunk **botao;
	/* ----- */
	unsigned short noAlocado,
				   count;

	/*Alocação de botoes*/
	if (!(botao  = (Mix_Chunk **) malloc(sizeof(Mix_Chunk*) * (noAlocado+1)))){
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
	if (insereCaminho(botao, noAllocate, listaudio,recebeCaminho) < 0)
		mostraErro("Falha ao inserir caminhos nos botoes: ");	
		
	free(botao);
	fclose(listaudio);
	Mix_CloseAudio();
	Mix_Quit();
	return 0;
}
