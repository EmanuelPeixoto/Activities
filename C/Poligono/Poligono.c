#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <errno.h>
#include <inttypes.h>

#define RAND 200

typedef struct {
    float x;
    float y;
    float a;
    float t;
}Point;

Point* IniciarVet(int size){
  Point *ponto = (Point*)malloc(size * sizeof(Point));
  for(int i = 0; i < size; i++){
      ponto[i].x = 0;
      ponto[i].y = 0;
      ponto[i].a = 0;
      ponto[i].t = 0;
  }
  return ponto;
}

void Preencher(Point *ponto, int size){
  for(int i = 0; i < size; i++){
      int sinal_x = rand()%2;
      int sinal_y = rand()%2;
      if(sinal_x == 0) sinal_x = -1;
      if(sinal_y == 0) sinal_y = -1;
        ponto[i].x = sinal_x * (float)(((double)rand()/(double)(RAND_MAX) * RAND));
        ponto[i].y = sinal_y * (float)(((double)rand()/(double)(RAND_MAX) * RAND));
          while(ponto[i].x == 0 && ponto[i].y == 0){
          ponto[i].x = sinal_x*(rand()%RAND);
          ponto[i].y = sinal_y*(rand()%RAND);
    }
  }
}

void Mostrar(Point *ponto, int size){
  printf("%c%8c%c%7c%c%7c%c\n", 'X', ' ', 'Y', ' ', 'A', ' ', 'T');
  for(int i = 0; i < size; i++){
    printf("(%07.2f, %07.2f) %07.2f %07.2f\n", ponto[i].x, ponto[i].y, ponto[i].a, ponto[i].t);
  }
}


float Area(Point *ponto, int size){
  float acc = 0, ang = 0, sen = 0, area = 0;
  for(int i = 0; i < size; i++){
    if(i != (size - 1))
      ang = (ponto[(i + 1)%size].a - ponto[i].a);
    else
      ang = 360 - ponto[i].a + ponto[(i + 1)%size].a;
    float rad = ang * (M_PI / 180.0);
    sen = sin(rad);
    area = (ponto[i].t * ponto[(i + 1) % size].t * sen)/2;
    acc += area;
    //printf("\nAng: %f\nSen: %f\nArea : %f\nXa: %f\nXb: %f\n", ang, sen, area, ponto[i].x, ponto[(i + 1) % size].x);
  }
  return acc;
}


void AngConv(Point *ponto, int size, float *VetRef){
  float TamVetRef = sqrt(pow(VetRef[0],2) + pow(VetRef[1],2));
  for(int i = 0; i < size; i++){
    float dir = ponto[i].x * VetRef[1] - VetRef[0] * ponto[i].y;
    float ProdEsc = ponto[i].x * VetRef[0] + VetRef[1] * ponto[i].y;

    float algo = ProdEsc / (TamVetRef * ponto[i].t);
    if(algo >= 1)algo = 1;
    if(algo <= -1)algo = -1;
    float AngRad = acos(algo);
    float AngGraus = AngRad * 180.0 / M_PI;
    if(dir > 0){ponto[i].a = 360 - AngGraus;}
    else{ponto[i].a = AngGraus;}
    //printf("dir: %f prodesc: %f dist1: %f dist2: %f algo: %f AngRad: %f AngGraus: %f\n", dir, ProdEsc, Dist1, Dist2, algo, AngRad, AngGraus);
  }
}

void Tamanho(Point *ponto, int size){
  for(int i = 0; i < size; i++){
    ponto[i].t = sqrt( pow(ponto[i].x,2) + pow(ponto[i].y,2) );
  }
}

Point PontoMedio(int size, Point *point){
  Point novo_ponto;
  novo_ponto.x = 0;
  novo_ponto.y = 0;
  for(int i = 0; i < size; i++){
    novo_ponto.x = novo_ponto.x + point[i].x;
    novo_ponto.y = novo_ponto.y + point[i].y;
  }
  novo_ponto.x = novo_ponto.x/size;
  novo_ponto.y = novo_ponto.y/size;
  return novo_ponto;
}

void Transladar(Point pm, Point *Pontos, int size){
  for(int i = 0; i < size; i++){
    Pontos[i].x = Pontos[i].x - pm.x;
    Pontos[i].y = Pontos[i].y - pm.y;
  }
}

void troca(Point *a, Point *b){
  Point temp = *a;
  *a = *b;
  *b = temp;
}

// Função para encontrar a posição correta do pivô no array
int partition(Point *arr, int low, int high) {
  float pivo = arr[high].a; // Escolhendo o ultimo elemento como pivô
  int i = (low - 1);     // Índice do menor elemento

  for (int j = low; j <= high - 1; j++) {
    // Se o elemento atual for menor ou igual ao pivô
    if (arr[j].a <= pivo) {
      i++; // Incrementa o índice do menor elemento
      troca(&arr[i], &arr[j]);
    }
  }
  troca(&arr[i + 1], &arr[high]);
  return (i + 1);
}

// Função principal do Quick Sort
void quickSort(int low, int high, Point *arr) {
  if (low <= high) {
  // Encontra a posição do pivô
  int pi = partition(arr, low, high);

  // Ordena os elementos antes e depois da posição do pivô
  quickSort(low, pi - 1, arr);
  quickSort(pi + 1, high, arr);
  }
}


void Uniao(Point *ponto, int size){
 printf("\n");
 for(int i = 0; i < size; i++){
   float v1 = ponto[(i)%size].x;
   float v2 = ponto[(i+1)%size].x;
   float v3 = ponto[(i)%size].y;
   float v4 = ponto[(i+1)%size].y;
   printf("(%f, %f)\n",v2-v1, v4-v3);
 }
}

int main(int argc, char** argv){
  clock_t begin = clock();
  intmax_t T = 0;

  if(argc == 1){
    printf("nenhum argumento fornecido");
  }else if (argc > 2){
    printf("muitos argumentos fornecidos");
  } else {
    intmax_t num = strtoimax(argv[1], NULL, 10);
    if(num == INTMAX_MAX && errno == ERANGE){
      printf("Não foi possivel converter");
      exit(-1);
    }else{ T = num;}
  }

  float VetRef[3] = {0, 1, 0};
  srand(clock());

  Point *ponto = IniciarVet(T);
  Preencher(ponto, T);
  Point pm = PontoMedio(T, ponto);
  //printf("Ponto X medio: %f\nPonto Y medio: %f\n", pm.x, pm.y);
  //Mostrar(ponto, T);

  Transladar(pm, ponto, T);
  Tamanho(ponto, T);
  //printf("\nDepois de transladar os pontos: \n");
  //Mostrar(ponto, T);

  //printf("\nCalculando Angulo\n");
  AngConv(ponto, T, VetRef);

  //Mostrar(ponto, T);

  quickSort(0, T - 1, ponto);
  //printf("\nDepois de organizar angulo: \n");
  //Mostrar(ponto, T);
  //printf("\n\n\nVetores para formar o poligono:\n");
  //Uniao(ponto, T);
  float area = Area(ponto, T);
  clock_t end = clock();
  double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
  printf("Area do poligono: %f\n\n", area);
  printf("Time Spent: %f", time_spent);
  return 0;
}
