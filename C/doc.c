#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void mostrar_vet(int *v,int k){
	int i;
	for (i=0;i<k;i++){
		printf(" %d",v[i]);
	}
printf("\n");
}

void preenche_ale_vet(int *v, int k,int max){
	int i=0, j, temp;
	srand(time(0));
	while(i < k){
        v[i] = rand() %max;
        temp = 0;
        for(j = 0; j < i; j++){
            if(v[j] == v[i]){
                temp = 1;
   			}
	    }

        if(temp == 0){
            i++;
   		}
    }
}

void preenche_manu_vet(int *v, int k){
	int i;
	for (i=0;i<k;i++){
		printf("\nDigite o valor para a posição %d:  ",i+1);
		scanf("%d", &v[i]);

	}
}

void swap(int *num1, int *num2) {
int temp = *num1;
*num1 = *num2;
*num2 = temp;
}

void quick_sort_first(int *v, int inicio, int fim,int tam){
	//mostrar_vet(v,tam);
	if (inicio <= fim){
		int i,j;
		int pivo = v[fim];
		i = (inicio - 1);
		for (j=inicio;j<=fim-1;j++){
			if(v[j] <= pivo){
				i++;
				swap(&v[i],&v[j]);
			}
		}
		swap(&v[i+1], &v[fim]);
		pivo = (i + 1);
		quick_sort_first(v,inicio,pivo-1,tam);
		quick_sort_first(v,pivo+1,fim,tam);
	}
}


int main(void){
	int i,j=0;
		system("clear");
		printf("Qual tamanho do vetor que vc quer ordenar? ");
		scanf("%d", &i);
		int *vet = (int*)malloc(i*sizeof(int));
		if (!vet){
			printf("erro ao alocar memória");
		}
		printf("Escolha:\nDigite (1) para preencher o vetor aleatoriamente. \nDigite (2) para preencher o vetor manualmente. \n");
		scanf("%d", &j);
		if (!((j==1) ||(j==2))){
			while (!((j==1) ||(j==2))){
				printf("Você digitou algo diferente de (1) ou (2). Escolha novamente por favor.");
				scanf("%d",&j);
			}
		}
		if (j==1){
			int m;
			printf("\nQual o maior número que vc quer que apareça no vetor: ");
			scanf("%d", &m);
			if(m<i){
				while(m<i){
					printf("\nQual o maior número que vc quer que apareça no vetor tem que ser maior ou igual o tamnho do vetor: ");
					scanf("%d", &m);
				}
			}
			preenche_ale_vet(vet,i,m);
		}
		else{
			preenche_manu_vet(vet,i);
		}
		printf("Vetor antes de ordenar: \n");
		mostrar_vet(vet,i);
		quick_sort_first(vet, 0,i-1,i);
		printf("\n");
		printf("Vetor depois de ordenar: \n");
		mostrar_vet(vet,i);
	return 0;
}
