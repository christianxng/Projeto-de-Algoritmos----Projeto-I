#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* Projeto 1 - Projeto de Algoritmos
			
		Professor: 
				Joelson Antônio dos Santos
		Alunos: 
				Christian Rodrigues Moura - 3629
				Jordi Henrique Marques da Silva - 3927
				Douglas Patrick Barbosa Boaventura - 5144
				
*/

 void criarinstancia(FILE * instancias,int tamanho,char opcaoins) // FUNÇÃO para gerar instancias
 {
	int i=0, x; // variável contador e variável para receber numero rand()
	
	switch(tamanho)  // switch para receber o tamanho da instancia e criar instancia com respectivo nome pelo tamanho
    {
    	
    	case 10: 
    		instancias=fopen("instancia10.txt","w+");//criar o arquivo de 10 elementos
    		break;
    	case 100: 
    		instancias=fopen("instancia100.txt","w+");//criar o arquivo de 100 elementos
    		break;
    	case 1000: 
    		instancias=fopen("instancia1000.txt","w+");//criar o arquivo de 1000 elementos
    		break;
    	case 10000: 
    		instancias=fopen("instancia10000.txt","w+");//criar o arquivo de 10000 elementos
    		break;
    	case 100000: 
    		instancias=fopen("instancia100000.txt","w+");//criar o arquivo de 100000 elementos
    		break;
    	case 1000000: 
    		instancias=fopen("instancia1000000.txt","w+");//criar o arquivo de 1000000 elementos
    		break;
	}	
	//instancias=fopen("instancias10.txt","w+");//criar o arquivo 

	
	switch(opcaoins){  // switch para receber caractere que determina qual forma de instancia criar
    	fflush(stdin);
    	case 'a':
    		printf("Numeros Gerados Aleatoriamente:\n");
			for (i = 0; i < tamanho; i++)
			{
				x=rand()%tamanho+1;
				//x = rand();			
				fprintf(instancias,"%d\t",x);
				printf("%d\t",x);
			}			
			break;
		case 'c':			
			printf("Numeros Gerados de forma Crescente:\n");
			for (i = 0; i < tamanho; i++)
			{				
				fprintf(instancias,"%d\t",i+1);
				printf("%d\t",i+1);
			}
			break;			
			
		case 'd':
			printf("Numeros Gerados de forma Decrescente:\n");
			for (i = 0; i < tamanho; i++)
			{
				fprintf(instancias,"%d\t",tamanho-i);
				printf("%d\t",tamanho-i);				
			}		
			break;
			
		default: 
			printf("Opcao Invalida\n");
			exit(1);
	}
	
	fclose(instancias);
}

void leituradeInstacia(FILE * instancias, int * vetor, int tamanho){  //FUNÇÃO para leitura de instancias

	int i=0; // contador
	
	switch(tamanho) // switch para receber o tamanho da instancia e abrir somente para leitura o respectivo arquivo  da instancia
    {
    
    	case 10: 
    		instancias=fopen("instancia10.txt","r");// Leitura do arquivo de 10 elementos
    		break;
    	case 100: 
    		instancias=fopen("instancia100.txt","r");// Leitura do arquivo de 100 elementos
    		break;
    	case 1000: 
    		instancias=fopen("instancia1000.txt","r");// Leitura do arquivo de 1000 elementos
    		break;
    	case 10000: 
    		instancias=fopen("instancia10000.txt","r");// Leitura do arquivo de 10000 elementos
    		break;
    	case 100000: 
    		instancias=fopen("instancia100000.txt","r");//Leitura do arquivo de 100000 elementos
    		break;
    	case 1000000: 
    		instancias=fopen("instancia1000000.txt","r");//Leitura do arquivo de 1000000 elementos
    		break;
    	default:
    		printf("ARQUIVO NAO ENCONTRADO");
	}		
	
	fflush(stdin);
	for(i=0;i<tamanho;i++)
	{
		fscanf(instancias,"%d\t",&vetor[i]); // passando  numeros da instancia para um vetor
	}
	fclose(instancias);
}
 

void Selection(int vet[],int tam){ // FUNÇÃO SELECTION SORT
	int i,j,min,aux;
		for(i=0;i<tam-1;i++){
			min = i;;
				for(j=i+1;j<=tam-1;j++){
					if(vet[min]>vet[j]){
						min=j;
					}
				}
			aux=vet[i];
			vet[i]=vet[min];
			vet[min]=aux;
		}
}
 
void Insertion(int vet[],int tam){ // FUNÇÃO INSERTION SORT
	int i,j,x;
		for(i=0;i<tam;i++){
			j=i-1;
			x=vet[i];
				while(x<vet[j] && j>=0){
					vet[j+1]=vet[j];
					vet[j]=x;
					j--;
				}
		}
}

void shellSort(int vet[],int n){ //FUNÇÃO SHELL SORT
	fflush(stdin);
	int i,j,h=1;
	do{
		h=3*h+1;
	}while(h<n);
	
	do{
		h /= 3;
		for(i=h+1; i<= n; i++){
			int x=vet[i];
			j=i;
			
				while(vet[j-h]>x){
					vet[j]=vet[j-h];
					j -= h;
					
					if(j<=h){
						vet[j]=x;
						break;
					}
				}
			}
		}while(h != 1);
}

void merge_sort ( int vetorDesorndeado[], int posicaoInicio, int posicaoFim ) {  // FUNÇÃO MERGE SORT
   fflush(stdin);
   int i, j, k, metadeTamanho, *vetorTemp;
   if ( posicaoInicio == posicaoFim ) return;
   
   metadeTamanho = ( posicaoInicio+posicaoFim )/2;
   merge_sort( vetorDesorndeado, posicaoInicio, metadeTamanho);
   merge_sort( vetorDesorndeado, metadeTamanho+1,posicaoFim );

   i = posicaoInicio;
   j = metadeTamanho+1;
   k = 0;
   
   vetorTemp = (int *) malloc(sizeof(int) * (posicaoFim-posicaoInicio+1));
   
   while( i < metadeTamanho+1 || j  < posicaoFim+1 ){ 
      if ( i == metadeTamanho+1 ){
         vetorTemp[k] = vetorDesorndeado[j];
         j++;
         k++;
      } 
      else{
         if (j==posicaoFim+1) { 
            vetorTemp[k] = vetorDesorndeado[i];
            i++;
            k++;
         } 
         else {
            if (vetorDesorndeado[i] < vetorDesorndeado[j]) { 
               vetorTemp[k] = vetorDesorndeado[i];
               i++;
               k++;
            } 
            else{ 
              vetorTemp[k] = vetorDesorndeado[j];
              j++;
              k++;
            }
         }
      }
      
   }
   for( i = posicaoInicio; i <= posicaoFim; i++ ){
      vetorDesorndeado[i] = vetorTemp[i-posicaoInicio];
   }
   free(vetorTemp);
}

void quick_sort(int *a, int esq, int dir) {
    int i, j, x, y;
     
    i = esq;
    j = dir;
    x = a[(esq + dir) / 2];
     
    while(i <= j) {
        while(a[i] < x && i < dir) {
            i++;
        }
        while(a[j] > x && j > esq) {
            j--;
        }
        if(i <= j) {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
        }
    }
     
    if(j > esq) {
        quick_sort(a, esq, j);
    }
    if(i < dir) {
        quick_sort(a, i, dir);
    }
}

void heapsort(int a[], int n) {
   int i = n / 2, pai, filho, t;
   while(1) {
      if (i > 0) {
          i--;
          t = a[i];
      } else {
          n--;
          if (n == 0) return;
          t = a[n];
          a[n] = a[0];
      }
      pai = i;
      filho = i * 2 + 1;
      while (filho < n) {
          if ((filho + 1 < n)  &&  (a[filho + 1] > a[filho]))
              filho++;
          if (a[filho] > t) {
             a[pai] = a[filho];
             pai = filho;
             filho = pai * 2 + 1;
          } else {
             break;
          }
      }
      a[pai] = t;
   }
}




 
int main(void)
{
	
	int opcao1,tamanho=0, i; // valores inteiros para menu de tamanho de intancia, tamanho do vetor e um contador
	char opcao2; // variável para o menu de forma de instância
	float tempoGasto, start, end; // valores flutuantes para o temporizador
	FILE *instancias; // variável para manipulação do arquivo/instancia
	
	
	printf("Bem Vindo ao Projeto 1 de P.A\n");
	printf("Selecione Tamanho da Instancia \n\n 1 = 10 numeros\n 2 = 100 numeros \n 3 = 1000 numeros \n 4 = 10000 numeros \n 5 = 100000 numeros \n 6 = 1000000 numeros\n 0 = Sair do Programa\n\n Opcao:  ");
	scanf("%d",&opcao1);
    
    switch(opcao1) // switch para setar numeros da instância
    {
    	case 1: 
    		tamanho = 10;
    		break;
    	case 2: 
    		tamanho = 100;
    		break;
    	case 3: 
    		tamanho = 1000;
    		break;
    	case 4: 
    		tamanho = 10000;
    		break;
    	case 5: 
    		tamanho = 100000;
    		break;
		case 6: 
    		tamanho = 1000000;
    		break;     	
    	case 0: 
    		printf("Tchau");
    		exit(1);
     	default: 
    		printf("opcao invalida");
    		exit(1);
	}                
	printf("Escolha uma forma de instancia:\n");
	printf(" a = Forma Aleatoria\n c = Forma Crescente\n d = Forma Decrescente\n");
    fflush(stdin);
    scanf("%c",&opcao2); // variável parareceber tipo de instancia do menu
    
    
	
	int *vetor=(int*)malloc(tamanho*sizeof(int)); // alocação dinâmica de um vetor para receber os numeros da instancia TXT
		
	criarinstancia(instancias,tamanho,opcao2); // função para criar as instancias possuindo como parametro FILE, tamanho e forma de instancia
	leituradeInstacia(instancias,vetor,tamanho); // função para leitura da instancia e passagem para o vetor dinâmico
	
	
	
	// EXECUTANDO FUNÇÃO SELECTION MAIS TEMPORIZADOR
	start=clock(); //recebendo tempo de início da função
	Selection(vetor,tamanho); // função de Ordenação Selection	
	end = clock(); // revebendo o tempo de termino da execução da função
	tempoGasto = ((end-start)/(double)CLOCKS_PER_SEC); // recebendo a diferença do tempo inicial e final que resulta o tempo de execução
	printf("\n *********************************SELECTION-SORT*********************************\n");	
	for(i=0;i<tamanho;i++)
	{
		printf("%d \n",vetor[i]); // imprimindo cada posição do vetor
	}
	printf("\nTempo gasto SELECTION-SORT = %f  ",tempoGasto);
	
	
	
	
	// EXECUTANDO FUNÇÃO INSERTION MAIS TEMPORIZADOR
	start=clock(); //recebendo tempo de início da função
	Insertion(vetor,tamanho);
	end = clock(); // revebendo o tempo de termino da execução da função
	tempoGasto = ((end-start)/(double)CLOCKS_PER_SEC); // recebendo a diferença do tempo inicial e final que resulta o tempo de execução
	printf("\n*********************************INSERTION-SORT*********************************\n");
	for(i=0;i<tamanho;i++)
	{
		printf("%d \n",vetor[i]);
	}	
	printf("\nTempo gasto INSERTION-SORT = %f  ",tempoGasto);
	
	
	
	// EXECUTANDO FUNÇÃO SHELL MAIS TEMPORIZADOR
	start=clock();//recebendo tempo de início da função
	shellSort(vetor,tamanho);	
	end = clock(); // revebendo o tempo de termino da execução da função
	tempoGasto = ((end-start)/(double)CLOCKS_PER_SEC); // recebendo a diferença do tempo inicial e final que resulta o tempo de execução
	printf("\n*********************************SHELL-SORT*********************************\n");		
	for(i=0;i<tamanho;i++)
	{
		printf("%d \n",vetor[i]);
	}
	printf("\nTempo gasto SHELL-SORT = %f  ",tempoGasto);	
	
	
	
	
	// EXECUTANDO FUNÇÃO MERGE SORT COM TEMPORIZADOR
	start=clock();//recebendo tempo de início da função
	merge_sort(vetor,0,tamanho-1);	
	end = clock(); // revebendo o tempo de termino da execução da função
	tempoGasto = ((end-start)/(double)CLOCKS_PER_SEC); // recebendo a diferença do tempo inicial e final que resulta o tempo de execução
	printf("\n*********************************MERGE-SORT*********************************\n");	
	for(i=0;i<tamanho;i++)
	{
		printf("%d \n",vetor[i]);
	}
	printf("\nTempo gasto MERGE-SORT = %f\n\n",tempoGasto);
	
	
	
	
	
	// EXECUTANDO FUNÇÃO QUICK SORT COM TEMPORIZADOR
	start=clock();//recebendo tempo de início da função
	quick_sort(vetor,0,tamanho);	
	end = clock(); // revebendo o tempo de termino da execução da função
	tempoGasto = ((end-start)/(double)CLOCKS_PER_SEC); // recebendo a diferença do tempo inicial e final que resulta o tempo de execução
	printf("\n*********************************QUICK-SORT*********************************\n");	
	for(i=0;i<tamanho;i++)
	{
		printf("%d \n",vetor[i]);
	}
	printf("\nTempo gasto QUICK-SORT = %f\n\n",tempoGasto);
	
	
	
	
	// EXECUTANDO FUNÇÃO HEAP SORT COM TEMPORIZADOR
	start=clock();//recebendo tempo de início da função
	heapsort(vetor,tamanho);	
	end = clock(); // revebendo o tempo de termino da execução da função
	tempoGasto = ((end-start)/(double)CLOCKS_PER_SEC); // recebendo a diferença do tempo inicial e final que resulta o tempo de execução
	printf("\n*********************************HEAP-SORT*********************************\n");	
	for(i=0;i<tamanho;i++)
	{
		printf("%d \n",vetor[i]);
	}	
	printf("\nTempo gasto HEAP-SORT = %f\n\n",tempoGasto);
	
	
	
	
	free(vetor); // liberando o espaço alocado do vetor
	system("pause");
	return 0;
}

