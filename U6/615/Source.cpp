/*
author: jivfur
date: 2018/09/09
description: Ejercicio 6.15 Deitel & Deitel
*/
#include<stdio.h>
#include<stdlib.h>

int arreglo[] = { 0,0,0,0,0,0,0,0,0,0 };
/*
20 numeros diferentes
5 numeros diferentes
20 numeros iguales
*/

void addVector(int x) {	
	if (x > 9 && x < 101) {
		int pos = x / 10;
		int val = x % 10; 
		int aux = 1 << val;  
		if ((aux & arreglo[pos]) == 0) {
			arreglo[pos] += aux;
		}
	}
}

void printVector() {
	for (int i = 0; i < 10; i++) {
		if (arreglo[i] != 0) {
			for (int j= 0; j < 10; j++) {
				if (arreglo[i] & 1) {
					printf("%d\n",j+i*10);
				}
				arreglo[i] >>= 1;
			}
		}
	}
}


int main() {
	int x;
	for (int i = 0; i < 20; i++) {
		system("cls");
		printf("Valor: ");
		scanf_s("%d", &x);
		addVector(x);
	}
	printVector();
	system("pause");
	return 0;
}