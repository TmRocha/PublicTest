

#include<stdio.h>
#include<time.h>
#include<ctype.h>

#define NUM_TOTAL 50
#define NUM_ESTRELAS 9
#define NUM_APOSTAR 5
#define NUM_EST_APOSTAR 2
#define LinhaNum 6
#define LinhaEstrela 3
#define ESPACO ' '


void InicAleat();					// faz com que a cada chamada de rand() seja obtido um valor diferente
void InicVect(char *s, int n);				// inicializa todos os vectores com o caracter "ESPACO"
int NumAleat(int valmax);				// devolve um numero aleatorio >=1 e <=(numero passado para a função)
void Preencher(char *s, int valmax, int valjogar);	// preenche com 'X' a posição obtida com o numero aleatorio, se este ja nao estiver ocupado
void Mostrar(char *s,int Linha,int size);		// mostra o resultado obtido numa forma "formatada"



void InicAleat()
{
	long ultime;
	time(&ultime);
	srand((unsigned) ultime);
}


void InicVect(char *s, int n)
{
	int i;
	for(i=0;i<n;i++)
		s[i]=ESPACO;
}

int NumAleat(int valmax)
{
	return 1+(rand()%valmax);
}


void Preencher(char *s, int valmax, int valjogar)
{
	int i, val;
	for(i=0;i<valjogar;i++)
	{
		val=NumAleat(valmax);
		if(s[val]==ESPACO)
			s[val]='X';
		else
			i--;
	}
}


void Mostrar(char *s,int Linha, int size)
{
	int i;
	for(i=0; i<size; i++)
	{
		if(s[i]==ESPACO)
			printf("| %2d",i+1);
		else
			printf("| %2c",s[i]);
		
		if((i+1)%Linha==0)
			putchar('\n');
	}
}



int main()
{
	char Num[NUM_TOTAL], nEstrela[NUM_ESTRELAS], rspt;

	// INICIAR OS NUMEROS ALEATORIOS
	InicAleat();
	do
	{
		// INICIAR OS VECTORES COM ESPACO
		InicVect(Num,NUM_TOTAL);	
		InicVect(nEstrela,NUM_ESTRELAS);
		// PREENCHO OS VECTORES COM OS 'X' 
		Preencher(Num,NUM_TOTAL,NUM_APOSTAR);	
		Preencher(nEstrela,NUM_ESTRELAS,NUM_EST_APOSTAR);
		// MOSTRO O RESULTADO
		Mostrar(Num,LinhaNum,NUM_TOTAL);
		printf("\nEstrelas\n");
		Mostrar(nEstrela,LinhaEstrela,NUM_ESTRELAS);
		// REPETIR???
		printf("\n(Prima \"S\" se deseja obter outra combinacao)\n");
		fflush(stdin); rspt=getchar();
	}while(toupper(rspt)=='S');
	
	return 0;
}
