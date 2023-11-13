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
    printf("%d ", vet[i]);
  }
}

void crescente(int *vet, int tam) {
  for(int i = 0; i < tam - 1; i++) {
    for(int j = 0; j < tam - i - 1; j++) {
      if(vet[j] > vet[j + 1]) {
        troca(&vet[j], &vet[j + 1]);
      }
    }
  }
}

void preencher(int *vet, int tam, int aleatorio){
  if(aleatorio){
    for(int i = 0; i < tam; i++) {
     vet[i] = rand()%100;
    }
    printf("\nVetor gerado com %d números aleatórios: \n", tam);
  }
  else{
    for(int i = 0; i < tam; i++) {
      vet[tam-i-1] = i;
    }
    printf("\nVetor gerado com %d números em ordem decrescente: \n", tam);
  }
}

int main(){
  int t=0;
  int aleatorio=0;
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
  printf("\nPreencher com valores aleatórios ou decrescente?\nAleatório: Digite 1 \nDecrescente: Digite 0\nValor: ");
  scanf("%d", &aleatorio);
  preencher(vet, t, aleatorio);
  mostrarvet(vet,t);
  crescente(vet, t);
  printf("\n\nVetor em ordem crescente: \n");
  mostrarvet(vet, t);
  return 0;
}
