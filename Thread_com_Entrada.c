#include <stdio.h>
//#include <sys/wait.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

//const int N = 10; 

#define TRUE 1
#define FALSE 0
#define FLAG 1000

int flag[FLAG], turn;

void peterson_th0( int N)
{
  int i, j, k;
  
  for( i=0; i<N; i++ ) {
    
    flag[i] = TRUE;
    turn = 1;
    while( flag[i+1] & turn == 1 ) ;
    printf("Thread [%d]...Dentro da Regiao Critica...\n",i);

    /* Simula um Processamento */
    for( j=0; j<16384; j++ )
      for( k=0; k<8192; k++) ;
    printf("Thread [%d]...Fora da  Regiao Critica...\n",i);

    flag[i] = FALSE;
    turn = 0;

  }
}

int main( int argc, char* argv[] )
{
	char op;
	int N;
	
	printf("Digite a Quantidade de Processos:");
	scanf("%d",&N);	
  
  pthread_t th0;
  int r_th0;
  long thread0[N];

  turn = 1;
  int i;

  for(i=0; i <N; i++){
  	peterson_th0(N);
  
	  thread0[i] = pthread_create(&th0, NULL, (void *) peterson_th0, NULL);
      if (thread0[i]) {
            perror ("pthread_create");
            exit(1);
        }


      printf("Thread \"Main\": Sincroniza termino com Threads 0 e 1.\n");
      pthread_join(th0, (void *) &r_th0);
      exit(0);

  }
}


