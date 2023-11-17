#include <stdio.h>   // ler, mostrar
#include <stdlib.h>  // random
#include <time.h>

void defMatEntrada(int mat[10][10]) { // gera matriz aleatória , revisado
	int i, j;
	srand(time(0));
	for(i=0; i<10; i++)
		for(j=0; j<10; j++) 
			mat[i][j] = rand()%100;
}

void mostrartwo(int mat[10][10], int mat2[10][10]) { // mostra duas matrizes, revisado
	int i, j,k;
	printf("\n Matriz \n");
	for(i=0; i<10; i++)
	{
		for(j=0; j<10; j++){
			printf(" %d", mat[i][j]);
		}

		for(k=0; k< 10; k++){
			printf(" %d", mat2[i][k]);
		}
		printf("\n");
	}
}

void mostrar(int mat[10][10]) { // mostra uma matriz, revisado
	int i, j;
	printf("\n Matriz \n");
	for(i=0; i<10; i++)
	{
		printf("\n");
		for(j=0; j<10; j++) 
			printf(" %d", mat[i][j]);
	}
}

void defVk(int k, int vK[10], int mat[10][10]) { // define vK com valores aleatórios, revisado
	int  r, i, j;
	srand(time(0));
	for(r=0; r<k; r++) {
		i = rand()%10;
		j = rand()%10;
		vK[r] = mat[i][j];
	}
	printf("\n Vetor vK: \n");
	for(i=0; i<k; i++) {
		printf(" %d", vK[i]);
	}
		
}

void iniciarVet(int Vetor[10]){
	int i, j;
	for(i = 0; i <10; i ++){
		Vetor[i]=0;
	}
}

void procGeraMatS(int k, int vK[10], int matE[10][10], int matS[10][10],int MatI[10][10],int vkmelhorado[10]) {
	int i, j, r, rMin, d, dMin;
	for(i=0; i<10; i++)
		for(j=0; j<10; j++){
			dMin = 300;
			
			for(r=0; r<k; r++){
				d = abs(matE[i][j]-vK[r]);
				if(dMin > d) {
					dMin = d;
					rMin = r;
					MatI[i][j] = r; // r é o indice do vK
				}
			}
			matS[i][j] = vK[rMin];		
		}
		 
}

void ContarInd(int VetAc[10], int VetCont[10], int MatInd[10][10], int MatEnt[10][10], int k){
	int i,j;
	for(i = 0; i <10; i ++){
		for (j=0; j<10; j++){
		//temp = MatInd[i][j];
		//printf(" %d ", temp);
		//VetCont[temp];
		VetCont[MatInd[i][j]]++;
		}
	}

	printf("\n Vetor contador de indice: \n");
	for(i=0; i<k; i++) {
		printf(" %d", VetCont[i]);
	}

}


void melhoravk(int a,int vk[10], int matE[10][10],int contavk[10]){
	int i,j,k,c;
	for(i = 0; i <10; i ++){
		for (j=0; j<10; j++){
			for(k=0; k<10; k++){
				if (matE[i][j] == vk[k]){
					contavk[k]++;
				}
			}
		}
	}
	
}

/*void melhoravk(int k, int vk[10], int matE[10][10], int matI[10][10], int vkmelhorado10]){
	
//fazer a média dos números que cada indice pegou em MatE 
}*/

int main() {
	int matE[10][10], matS[10][10], vK[10], k, MatI[10][10],contavk[10],vkmelhorado[10], VetCont[10], VetAc[10];
	
	defMatEntrada(matE);
	mostrar(matE);
	printf("\n Digite valor de k (inteiro): ");
	scanf("%d", &k);
	defVk(k, vK, matE);
	iniciarVet(VetCont);
	iniciarVet(VetAc);
	//melhoravk(k,vK,matE,contavk);
	procGeraMatS(k, vK, matE, matS,MatI,vkmelhorado);
	ContarInd(VetAc, VetCont, MatI, matE, k);
	mostrartwo(MatI, matS);
	
	return 0;
}
