#include<stdio.h>
#include<stdlib.h>
#include <time.h>


// Função para trocar dois elementos
void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função para mostrar o vetor
void mostrarvet(int *vet, int t){
  for(int i = 0; i < t ; i++){
    printf("%2d ", vet[i]);
    //printf("%d ", vet[i]);
  }
  printf("\n");
}

// Função para encontrar a posição correta do pivô no array
int partition(int *arr, int low, int high) {
    int pivo = arr[high]; // Escolhendo o ultimo elemento como pivô, trocar dps
    //int pivo = arr[low]; // Escolhendo o primeiro elemento do pivo
    int i = (low - 1);     // Índice do menor elemento

    for (int j = low; j <= high - 1; j++) {
        // Se o elemento atual for menor ou igual ao pivô
        if (arr[j] <= pivo) {
            i++; // Incrementa o índice do menor elemento
            troca(&arr[i], &arr[j]);
        }
    }
    //troca(&arr[i + 1], &arr[low]);
    troca(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// Função principal do Quick Sort
void quickSort(int low, int high, int *arr, int vetsize) {
    mostrarvet(arr, vetsize);
  if (low <= high) {
        // Encontra a posição do pivô
        int pi = partition(arr, low, high);

        // Ordena os elementos antes e depois da posição do pivô
        quickSort(low, pi - 1, arr, vetsize);
        quickSort(pi + 1, high, arr, vetsize);
    }
}


// Função para preencher o vetor com valores
void preencher(int *vet, int tam, int aleatorio){
  if(aleatorio){
    for(int i = 0; i < tam; i++) {
     vet[i] = rand()%100;
    }
    printf("\nVetor não ordenado com %d números aleatórios: \n", tam);
  }
  else{
    for(int i = 0; i <= tam; i++) {
      vet[tam-i-1] = i;
      printf("Tam: %d I: %d Tam-I-1: %d\n", tam, i, (tam-i-1));
    }
    printf("\nVetor não ordenado com %d números em ordem decrescente: \n", tam);
  }
}


int main(){
  int t = 0, aleatorio = 9;
  srand(time(0));

  while(t<=0){
  printf("Escolha o tamanho do vetor, (valor inteiro maior que zero): ");
  scanf("%d", &t);
  }

  int *vet = (int*)malloc(t*sizeof(int));
  if(!vet){
    printf("erro na alocacao de memoria");
    exit(1);
  }

  while(aleatorio != 0 && aleatorio != 1){
    printf("\nPreencher com valores aleatórios ou decrescente?\nAleatório: Digite 1 \nDecrescente: Digite 0\nValor: ");
    scanf("%d", &aleatorio);
  }

  preencher(vet, t, aleatorio);
  mostrarvet(vet, t);
  quickSort(0, t - 1, vet, t);
  printf("\n\nVetor em ordem crescente: \n");
  mostrarvet(vet, t);
  return 0;
}
