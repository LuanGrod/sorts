#include <stdio.h>
#include <stdlib.h>
#include <math.h>  
#define MAX 7

int vetor[MAX];
int a, once=1, i, j, k, aux, menor, posMenor, flag;

void printaVetor(int vetor[])
{
for (a=0;a<MAX;a++)
{
	printf("%d ", vetor[a]);
}
printf("\n");	
}


void bubbleSort (int vetor[])
{
int flag;
// 5 4 3 2 1
printf("ordenacao por BubbleSort\n");
printaVetor(vetor);

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
		printaVetor(vetor);
	else
		break;		
}
}


void selectionSort (int vetor [])
{
// 5 4 3 2 1
int pos;
printf("ordenacao por SelectionSort\n");	
printaVetor(vetor);

for (i=0;i<MAX-1;i++)
{
	menor = i;
	int flag = 0;
	for (j=i+1;j<MAX;j++)
	{
    	if (vetor[j]<vetor[menor]) 
    	{
			menor = j;
			flag = 1;
		}	
    }    	
        	
	aux = vetor[i];
	vetor[i] = vetor[menor];
	vetor[menor] = aux;	

	if (flag == 1)//imprimi na tela o estado atual da ordenação
		printaVetor(vetor);
	else
		break;
}
}


void insertionSort (int vetor[])
{
printf("ordenacao por InsertionSort\n");	
printaVetor(vetor);

int key;
for(i=1;i<MAX;i++)
{
	int flag=0;	
	key = vetor[i];
	j = i - 1;
	
	while(j>=0 && vetor[j]>key)
	{
		vetor[j+1] = vetor[j];
		j = j -1;
		flag = 1;	
	}
	
	vetor[j+1] = key;
	
	if (flag == 1)//imprimi na tela o estado atual da ordenação
		printaVetor(vetor);
	else
		break;
}
}

//conquista
void merge(int vetor[], int inicio, int m, int fim)
{
/*
tamanho dos vetores [1,2,3,4,5]
n1(inicio ate a metade)[1,2,3] -> n1 = 3
n2(metade ate o final)[4,5] -> n2 = 2
*/
int n1 = m-inicio+1;
int n2 = fim-m;

//vetor de apoio que manterá os valores organizados
int L[n1], R[n2];

//copiar o que tem no vetor base para os vetores de apoio
for (i=0; i<n1; i++)
    L[i] = vetor[inicio+i];
    
for (j=0; j<n2; j++)
    R[j] = vetor[m+1+j];

//copiar o que tem nos vetores de apoio no vetor base
i = 0; //primeiro indice do vetor n1
j = 0; //primeiro indice do vetor n2
k = inicio; //primeiro indice do vetor ordenado

/*
posiciona os valores em ordem crescente no valor ordenado
seleciona o primeiro valor das 2 listas, [i..m] e [m+1..f]
compara e o menor é posicionado na lista ordenada
repete até que chegue no ultimo numero de uma das listas
*/
while (i<n1 && j<n2) 
{
    if (L[i] <= R[j]) 
	{
        vetor[k] = L[i];
        i++;
    }
    else 
	{
        vetor[k] = R[j];
        j++;
    }
    k++;
}

/*
se sobrou algum numero da lista L[], já que já está
ordenado, so vai copiar pra lista final
*/
while (i < n1) 
{
    vetor[k] = L[i];
    i++;
    k++;
}

/*
se sobrou algum numero da lista R[], já que já está
ordenado, so vai copiar pra lista final
*/
while (j < n2) 
{
    vetor[k] = R[j];
    j++;
    k++;
}
}
  
//divisão
void mergeSort(int vetor[], int inicio, int fim)
{
if (once==1)
{
printf("ordenacao por MergeSort\n");	
printaVetor(vetor);
once++;
}

int flag = 0;
if (inicio<fim) 
{
    int m = floor ((fim+inicio) / 2);
    mergeSort(vetor, inicio, m);
    mergeSort(vetor, m+1, fim);
    merge(vetor, inicio, m, fim);
    flag = 1;
}

if(flag==1)
	printaVetor(vetor);
}


void countSort(int vetor[], int exp)
{
	// [251 512 682 976]
	int aux[MAX];
	int i, count[10] = {0}; //count ta [10] porque ta na base 10

	/*
	pega o valor da casa que está sendo usada no exp e guarda na lista 
	quando exp = 1
	251/1 = 251
	251%10 = 1 
	512/1 = 521
	512%10 = 2
	682/1 = 682
	682%10 = 2
	976/1 = 976
	976%10 = 6
								 [0,1,2,3,4,5,6,7,8,9]
	entao na lista count vai ter [0,1,2,0,0,0,1,0,0,0]
	*/
	for (i=0;i<MAX;i++)
		count[(vetor[i]/exp) % 10]++;

	//somar os valores pra realizar o countSort
	//[0,1,2,0,0,0,1,0,0,0] -> [0,1,3,3,3,3,4,4,4,4]
	for (i=1;i<10;i++)
		count[i] += count[i-1];

	//preencher o vetor auxiliar
	for (i=MAX-1;i>=0;i--) 
	{
		aux[count[(vetor[i]/exp)%10]-1] = vetor[i];
		count[(vetor[i]/exp)%10]--;
	}

	//passar do vetor auxiliar pro vetor originanl
	for (i=0;i<MAX;i++)
		vetor[i] = aux[i];
}


void radixsort(int vetor[])
{

	printf("ordenacao por RadixSort\n");	
	printaVetor(vetor);
	
	//acha o maior numero da lista
	int maior = vetor[0];
	for (int i=1;i<MAX;i++)
	{
		if (vetor[i] > maior)
			maior = vetor[i];
	}

	/*
	ex. [251 512 682 976]
	Esse countSort vai varrer a lista e ordenar a quantidade que cada
	numero aparece e vai botar ele em ordem de aparecimento
	10^0	[251 512 682 976]
	10^1	[512 251 976 682]
	10^2	[251 512 682 976]
	Vai iterar de acordo com a base (10)
	1 -> 10 -> 100 -> 1000
	*/
	for (int exp=1;(maior/exp)>0;exp*=10)
	{
		countSort(vetor, exp);
		printaVetor(vetor);
	}
}


int partition(int vetor[], int left, int right)
{

int pivot = vetor[left];
int l = left+1;
int r = right;

/*
[50, 80, 30, 90, 40, 10, 70]
[80, 10, 30, 90, 40, 80, 70]
pivot = 50
left = 0
right = 6
l = 1
r = 6 -> 5
aux = 80
*/

while (l<r)
{
	//acha o primeiro numero maior que o pivot a partir da esquerda, armazena a posicao
	while(l<right && vetor[l]<pivot)
		l++;
	//acha o primeiro numero menor que o pivot a partir da direita, armazena a posicao
	while(r>left && vetor[r]>=pivot)
		r--;
	
	//troca os 2 numeros
	if (l<r)
	{
		aux = vetor[l];
		vetor[l] = vetor[r];
		vetor[r] = aux; 
	}
}

//???
vetor[left] = vetor[r];
vetor[r] = pivot;

return r;
}


void quickSort(int vetor[], int inicio, int fim)
{
if(once==1)
{
printf("ordenacao por QuickSort\n");	
printaVetor(vetor);
once++;
}

if(inicio<fim) 
{
	int p = partition(vetor, inicio, fim);
    quickSort(vetor, inicio, p-1);
    quickSort(vetor, p+1, fim);
}	

}


main()
{
//coleta os valores do vetor
for (i=0;i<MAX;i++)
{
printf("vetor[%d]: ", i+1);
scanf("%d", &vetor[i]);	
}

//imprimi na tela o vetor inicial
printf("vetor: ");
printaVetor(vetor);
printf("\n");


//bubbleSort(vetor);

//selectionSort(vetor);

//insertionSort(vetor);

//mergeSort(vetor, 0, MAX-1);

//radixsort(vetor);

//quickSort(vetor, 0, MAX-1);


printf("\n\nLista ordenada\n");
printaVetor(vetor);

}
