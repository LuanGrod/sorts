#include <stdio.h>
#define MAX 5

int a, i, j, aux, menor;

achaMenor(int a, int b)
{
if (a<b)
menor = a;	
else
menor = b;

printf("%d", menor);
}


void bubbleSort (int vetor[])
{
int flag;
// 5 4 3 2 1
printf("ordenacao por BubbleSort\n");

for (i=0;i<MAX-1;i++) 
{
	flag = 0;
	for (j=0;j<MAX-1-i;j++) 
	{
		if (vetor[j]>vetor[j+1]) 
		{
		   aux = vetor [j];
		   vetor[j] = vetor[j+1];
		   vetor[j+1] = aux;
		   flag = 1;
		}
	}
	
	if (flag == 1)//imprimi na tela o estado atual da ordenação
	{
		for (a=0;a<MAX;a++)
		{
			printf("%d ", vetor[a]);
		}
		printf("\n");
	}
	else//caso a ordenação esteja correta antes de O(n^2)
	{
		break;
	}		
}








}


void selectionSort (int vetor [])
{
	
	
}


main()
{
int vetor[MAX];

//coleta os valores do vetor
for (i=0;i<MAX;i++)
{
printf("vetor[%d]: ", i+1);
scanf("%d", &vetor[i]);	
}

//imprimi na tela o vetor inicial
printf("vetor: ");
for (a=0;a<MAX;a++)
{
	printf("%d ", vetor[a]);
}
printf("\n\n");







//bubbleSort(vetor);





}
