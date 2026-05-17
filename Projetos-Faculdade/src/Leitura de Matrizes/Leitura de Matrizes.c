#include <stdio.h>

void leMatriz3(int m[3][3]) {
for (int i = 0; i < 3; i++) {
for (int j = 0; j < 3; j++) {
printf("Valor [%d][%d]: ", i, j);
scanf("%d", &m[i][j]);
  }
 }
}

void imprimeMatriz3(int m[3][3]) {
for (int i = 0; i < 3; i++) {
for (int j = 0; j < 3; j++) {
printf("%d ", m[i][j]);
  }
printf("\n");
 }
}

void subtraiMatriz(int a[3][3], int b[3][3], int d[3][3]) {
for (int i = 0; i < 3; i++) {
for (int j = 0; j < 3; j++) {
d[i][j] = a[i][j] - b[i][j];
  }
 }
}

void transposta(int m[3][3], int t[3][3]) {
for (int i = 0; i < 3; i++) {
for (int j = 0; j < 3; j++) {
t[j][i] = m[i][j]; 
  }
 }
}

int main() {
int A[3][3], B[3][3], D[3][3], T[3][3];

printf("Digite a Matriz A:\n");
leMatriz3(A);
printf("Digite a Matriz B:\n");
leMatriz3(B);

subtraiMatriz(A, B, D);
transposta(D, T);

printf("\nMatriz Diferença (D):\n");
imprimeMatriz3(D);

printf("\nMatriz Transposta de D (T):\n");
imprimeMatriz3(T);

return 0;
}