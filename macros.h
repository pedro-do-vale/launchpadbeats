
const int PAG = 12;

enum Botoes{
	PAD_Q = 1, PAD_W, PAD_R, PAD_T,
	PAD_A, PAD_S, PAD_D, PAD_F, PAD_Z,
	PAD_X, PAD_K, PAD_L, PAD_PAG1 = 49,
	PAD_PAG2, PAD_PAG3, PAD_LOOP;
};
	
/*Estrutura que abrangerá os canais de cada botão*/
typedef struct canalAtual{
	int canal;
}CanalAtual;
