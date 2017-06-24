#include "includes/padmaisbeats.h"

main (int argc, char **argv){
	/*Declaração de variáveis*/
	unsigned short 
	   numCaminhos = 0, count = 0, c_loop = 0, estadoLoop = LOOP_DESLIGADO;
	unsigned int
	   indice = 0;
	int
	  i,pagAtual = 0;
	char
	  *caminho = "exemplo.txt";
	FILE 
	  *lista_arquivos = fopen( caminho, "r" );
	Mix_Chunk
	  **botao, *ultimoLido = NULL;/*vetor de audios*/
	CanalAtual
	   *canais;
	/* -------------------
	 * Fim da declaração*/
	
	/*Alocação de botoes*/
	if ( !(botao  = (Mix_Chunk **) malloc( sizeof(Mix_Chunk *) * (++numCaminhos))) )
		mostraErro("Falha ao alocar: ");
	else{
		for ( i = 0; i < numCaminhos; i++ ){
			if( !(botao[i] = (Mix_Chunk *) malloc(sizeof(Mix_Chunk))) )
				mostraErro("Falha ao alocar: ");
		}
	}
	/*Passo os caminhos para o arquivo de audio associado aos botoes*/
	/*Checo se houve erro*/
	if ( insereCaminho(botao, numCaminhos, &listaudio) < 0 )
		mostraErro("Falha ao inserir caminhos nos botoes: ");
	
	alocaCanais( &canais, numCaminhos, Mix_AllocateChannels );	
	
	/*WHILE DO ARDUINO*/
	while (1){
		/*se for loop*/
		if ( retorno == PAD_LOOP ){
			/*incremento loop
			 * se o loop entrou duas vezes, significa que pressionei o botao loop duas vezes! Kkk*/
			if ( (++c_loop) && c_loop == 2 ){
				/* chamo a função desenfileira(),
				 * além disso, é necessário parar o ultimo som loop tocado, ou a primeiro... */
			}
			/*ativo a variável de loop*/
			estadoLoop = LOOP_LIGADO;
		}
		
		/*não é loop, precisamos avaliar as páginas e os comandos de áudio propriamente ditos nesse else*/
		else{
			/*Checo se os retornos correspondem à paginas*/
			/*Já mato os três coelhos se o byte não corresponder aos botoes de audio*/
			if(retorno > 12){
				if ( retorno == PAD_PAG1 )
					pagAtual = 0;
					
				else if ( retorno == PAD_PAG2 )
					pagAtual = 1;
		
				else if ( retorno == PAD_PAG3 )
					pagAtual = 2;
			}	
			else{
				/*Seto o índice*/	
				indice = (12 * pagAtual) + retorno;
				
				if( estadoLoop == LOOP_DESLIGADO)
					Mix_PlayChannel( canais[indice].canal, botoes[indice], 0 );		
				
				else if( estadoLoop == LOOP_LIGADO && /*canal indice ja foi usado*/ ){
					Mix_PlayChannel( canais[indice].canal, botoes[inidice], -1 );
					enfileira(indice);/*A DEFINIR FUNCAO*/
				}
			}
			
			c_loop = 0; /*reinicio as vezes que o botao loop foi pressionado*/
			estadoLoop = LOOP_DESLIGADO;
		}
	}
	
	free(botao);
	fclose(listaudio);
	Mix_CloseAudio();
	Mix_Quit();
	return 0;
}
