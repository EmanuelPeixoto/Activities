#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define RAND 200

typedef struct {
    float x;
    float y;
    float a;
}Point;

Point* IniciarVet(int size){
  Point *ponto = (Point*)malloc(size * sizeof(Point));
  for(int i = 0; i < size; i++){
      ponto[i].x = 0;
      ponto[i].y = 0;
      ponto[i].a = 0;
  }
  return ponto;
}

void Preencher(Point *ponto, int size){
  for(int i = 0; i < size; i++){
      int sinal_x = rand()%2;
      int sinal_y = rand()%2;
      if(sinal_x == 0) sinal_x = -1;
      if(sinal_y == 0) sinal_y = -1;
        ponto[i].x = sinal_x*(rand()%RAND);
        ponto[i].y = sinal_y*(rand()%RAND);
        ponto[i].a = 0;
          while(ponto[i].x == 0 && ponto[i].y == 0){
          ponto[i].x = sinal_x*(rand()%RAND);
          ponto[i].y = sinal_y*(rand()%RAND);
          ponto[i].a = 0;
    }
  }
}

void Mostrar(Point *ponto, int size){
  printf("%c%8c%c%7c%c\n", 'X', ' ', 'Y', ' ', 'A');
  for(int i = 0; i < size; i++){
    printf("%07.2f  %07.2f %07.2f\n", ponto[i].x, ponto[i].y, ponto[i].a);
  }
}

void Angulo(Point *ponto, int size, float *VetRef){
  for(int i = 0; i < size; i++){
    float dir = ponto[i].x * VetRef[1] - VetRef[0] * ponto[i].y;
    float ProdEsc = ponto[i].x * VetRef[0] + VetRef[1] * ponto[i].y;
    float Dist1 = sqrt(pow(VetRef[0],2) + pow(VetRef[1],2));
    float Dist2 = sqrt(pow(ponto[i].x,2) + pow(ponto[i].y,2));
    float algo = ProdEsc / (Dist1 * Dist2);
    float AngRad = acos(algo);
    float AngGraus = AngRad * 180.0 / M_PI;
    if(dir > 0){ponto[i].a = 360 - AngGraus;}
    else{ponto[i].a = AngGraus;}
    //printf("dir: %f prodesc: %f dist1: %f dist2: %f algo: %f AngRad: %f AngGraus: %f\n", dir, ProdEsc, Dist1, Dist2, algo, AngRad, AngGraus);
  }
}

void troca(Point *a, Point *b){
  Point *temp = a;
  a = b;
  b = temp;
}


void OrgAng(Point *ponto, int size){
    for(int j = 0; j< size; j++){
    for(int i = 0; i < size - 1; i++){
      if (ponto[i].a > ponto[i+1].a){
        troca(&ponto[i], &ponto[i+1]);
      }
    }
  }
}


void Uniao(Point *ponto, int size){
 for(int i = 0; i < size; i++){
   float v1 = ponto[(i)%size].x;
   float v2 = ponto[(i+1)%size].x;
   float v3 = ponto[(i)%size].y;
   float v4 = ponto[(i+1)%size].y;
   printf("(%f, %f)\n",v2-v1, v4-v3);
 }
}

int main(){
  float VetRef[3] = {0, 1, 0};
  int T = 0;
  srand(time(0));

  printf("Informe a quantidade de vetores: ");
  scanf("%d", &T);

  Point *ponto = IniciarVet(T);
  Preencher(ponto, T);
  Mostrar(ponto, T);

  printf("\nCalculando Angulo\n");
  Angulo(ponto, T, VetRef);

  Mostrar(ponto, T);

  OrgAng(ponto, T);
  printf("\nDepois de organizar angulo: \n");
  Mostrar(ponto, T);

  Uniao(ponto, T);
  return 0;
}
