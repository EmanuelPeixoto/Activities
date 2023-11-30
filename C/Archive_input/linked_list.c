#include <stdio.h>
#include <stdlib.h>

typedef struct gominho{
  char ch;
  int cont;
  struct gominho *prox;
} gom;

typedef struct{
  int n;
  gom *first;
  gom *last;
} head;

void mostraLista(gom *no) {
  while (no) {
    printf(" %c: %d \n", no->ch, no->cont);
    no = no->prox;
  }
}

void trocaint(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void trocachar(char *a, char *b) {
    char temp = *a;
    *a = *b;
    *b = temp;
}
gom *geraNo(char c) {
  gom *no = (gom*)malloc(sizeof(no));
  no->ch = c;
  no->cont = 1;
  no->prox = NULL;
  return no;
}


void registraDado(char c, head *lst) {
  gom *no, *noAnt, *noNew;
  noAnt = NULL;
  no = lst->first;
  if(!no) {
    lst->first = geraNo(c);
    lst->n +=1;
    return;
  }
  do{
    if(no->ch == c) {
      no->cont +=1;
      break;
    }
    if(c < no->ch) {
      noNew = geraNo(c);
      noNew->prox = no;
      lst->n += 1;
      if(noAnt) noAnt->prox = noNew;
      else lst->first = noNew;
      break;
    }
    noAnt = no;
    no = no->prox;
    }while (no);

    if(!no) {
      noNew = geraNo(c);
      noNew->prox = no;
      lst->n += 1;
      if(noAnt)
        noAnt->prox = noNew;
    }
}

void bubbleSort(head *root){
  gom *temp1 = root->first, *temp2;
  while (temp1 != NULL){
    temp2 = root->first;
      while (temp2->prox != NULL){
        if (temp2->cont > temp2->prox->cont){
          trocaint(&temp2->cont, &temp2->prox->cont);
          trocachar(&temp2->ch, &temp2->prox->ch);
          /*int tempcont = temp2->cont;
          int tempchar = temp2->ch;
          temp2->cont = temp2->prox->cont;
          temp2->ch = temp2->prox->ch;
          temp2->prox->cont = tempcont;
          temp2->prox->ch = tempchar;*/
        }
        temp2 = temp2->prox;
      }
    temp1 = temp1->prox;
  }
}

int main(){
  FILE *arq;
  head root;
  arq = fopen("oi.txt", "r");
  if(!arq){
    printf("o arquivo não abriu!");
    exit(1);
  }
  root.first = root.last = NULL;
  root.n = 0;

  int caractere;
  while ((caractere = fgetc(arq)) != EOF) {
    putchar(caractere);
    registraDado(caractere, &root);
  }
  fclose(arq);
  mostraLista(root.first);
  printf("\n\nOrdenando...\n\n\n");
  bubbleSort(&root);
  mostraLista(root.first);
}
