#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>

#define BAUD_DEFAULT 9600

main (int argc, char *argv[]){
	const char *arduino = "/dev/ttyUSB0"; /*endereço do dispositivo*/
	int fd_ino;
	char retorno;
	struct termios config;/*estrutura para configuracoes termios*/
	
	speed_t baudrate = BAUD_DEFAULT;
	
	/*
	 * Abro o dispositivo serial com as flags e sem blocking*/
	if((fd_ino = open(arduino, O_RDONLY | O_NOCTTY | O_NDELAY)) == -1){
		perror("Falha ao abrir arduino: ");
		exit(EXIT_FAILURE);
	}
	
	/*checo se o dispositivo é de fato serial, se nao for, retorno 0, */
	if(!isatty(fd_ino)){
		perror("Dispositivo foi aberto, mas não é serial");
		exit(EXIT_FAILURE);
	}
	/*Coloco as informações sobre o arduino na estrutura config*/
	if((tcgetattr(fd_ino, &config)) == -1){
		perror("Falha ao obter informações sobre o dispositivo");
		exit(EXIT_FAILURE);
	}
	
	/*
	 * Passo os parametros que preciso, no caso, quase nenhum*/
	config.c_iflag = 0;/*seto os parametros de input para 0*/
	config.c_oflag = 0;/*seto os parametros de output para 0*/
	config.c_lflag = 0;/* *seto os parametros de NL para 0*/
	config.c_cflag &= ~(CSIZE | PARENB); /*cancelo paridade de bits e sizemasking*/
	config.c_cflag |= CS8;/*forço o input de 8 bits*/
	config.c_cc[VMIN] = 1; /*só oportuno o read quando tiver um bit*/
	config.c_cc[VTIME] = 0; /*sem timer, assim q a fila estiver disponível, dados serão enviados*/
	
	/*Seto os baudrates*/
	if(cfsetispeed(&config, B9600) < 0 || cfsetospeed(&config, B9600) < 0){
		perror("Falha ao setar baudrates: ");
		exit(EXIT_SUCCESS);
	}
	
	/*Hora de aplicar as configuraçoes
	 */
	if(tcsetattr(fd_ino, TCSANOW, &config) < 0){
		perror("Falha ao aplicar as configurações feitas ");
		exit(EXIT_FAILURE);
	}
	
	while(1){
		if (!read(fd_ino, &retorno, 1)){
			perror("Falha ao ler do arduino: ");
			break;
		}
		else
			printf("\n%d ", retorno);
        sleep(1);
	}
	
	
	close(fd_ino); /*terminando a bagunça*/
	return 0;
}
