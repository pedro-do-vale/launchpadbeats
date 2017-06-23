
void mostraErro(char *msg);

int insereCaminho(Mix_Chunk **, unsigned short n, FILE *caminho); 
int alocaCanais(CanalAtual **, unsigned short n, int (*fptr_AllocateChannels)(int));
