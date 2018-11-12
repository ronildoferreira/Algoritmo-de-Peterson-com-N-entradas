#include <stdio.h>
//#include <sys/wait.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX 50

const int N = 50;

#define TRUE 1
#define FALSE 0

int flag[MAX], turn;
 

void peterson_th1( void )
{
  int i, j, k;
  
for(i=0;i<N;i++){
    flag[i] = TRUE;
    turn = 0; //peterson_th0 o tunr recebia 1
    while( flag[i+1] & turn == 1 ) ; //igual a 1
    

    printf("Thread %d... Dentro da Regiao Critica ... \n",i);

    /* Simula um Processamento */
    for( j=0; j<8192; j++ )
      for( k=0; k<4096; k++) ;

    printf("Thread %d: ... Fora da Regiao Critica ... \n",i);
}
    flag[i] = FALSE;
  
}

int main( int argc, char* argv[] )
{
	
  pthread_t th1;
  int r_th1;
  long thread1[N];//criar como vetor
	 int qtd;
	 
	turn = 1;
	int i;
	 for(i=0;i<N;i++){
  	 flag[i] = FALSE; 
}


for(i=0;i<N;i++){
	
  thread1[i] = pthread_create(&th1, NULL, (void *)peterson_th1, NULL);

  if (thread1[i]) {
    perror ("pthread_create") ;
    exit(1);
  }

  printf("Thread \"Main\": Sincroniza termino com Threads 0 e 1.\n");
  pthread_join( th1, (void *) &r_th1 );
  exit(0);
}
}
