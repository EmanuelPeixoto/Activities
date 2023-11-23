#include <stdio.h>
#include <stdlib.h>

typedef struct {
  char ch;
  int f;
} CC;

CC* IniciarVet(){
  CC *vet = (CC*)malloc(256 * sizeof(CC));
  for(int i = 0; i < 255; i++){
      vet[i].ch = i;
      vet[i].f = 0;

  }
  return vet;
}

void troca(CC *a, CC *b){
  CC temp = *a;
  *a = *b;
  *b = temp;
}


void Org(CC *v){
    for(int j = 0; j< 255; j++){
    for(int i = 0; i < 255 - 1; i++){
      if (v[i].f > v[i+1].f){
        troca(&v[i], &v[i+1]);
      }
    }
  }
}

void Mostrar(CC *v){
  for(int i = 0; i < 255; i++){
    if(v[i].f != 0)printf("%c  %d\n",v[i].ch, v[i].f);
  }
}


int main(){
  FILE *arq;
  CC *vet = IniciarVet();
  arq = fopen("oi.txt", "r");
  if(!arq){
    printf("o arquivo não abriu!");
    exit(1);
  }
  int caractere;
  while ((caractere = fgetc(arq)) != EOF) {
    putchar(caractere);
    vet[caractere].f += 1;
  }
  Org(vet);
  Mostrar(vet);
  fclose(arq);
}
