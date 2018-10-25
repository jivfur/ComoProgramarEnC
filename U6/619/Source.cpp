/*
date: Octubre 2018
Author: jivfur
Descripcion: Ejercicio 6.19 de Deitel&Deitel
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int TIMES = 36000;
int vector[11]; //2,3,4,5,6,7,8,9,10,11,12

void inicializaVector() {
	for (int i = 0; i < 11; i++) {
		vector[i] = 0;
	}
}

//Devolver un valor entre 1 y 6 de manera aleatoria.
int tirarDados() {
	return (rand() % 6) + 1;
}

void juego() {
	int temp1;
	for (int i = 0; i < TIMES; i++) {
		temp1 = tirarDados() + tirarDados();
		vector[temp1 - 2]++;
	}
}

void imprimeVector() {
	for (int i = 0; i < 11; i++) {
		printf("%d %d\n",i+2,vector[i]);
	}
}


int main() {
	srand(time(0));
	inicializaVector();
	juego();
	imprimeVector();
	system("pause");
	return 0;
}
