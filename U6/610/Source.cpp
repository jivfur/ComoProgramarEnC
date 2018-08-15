/*
author: jivfur
date: 2018/08/15
Description: Ejercicio 6.10 Deitel & Deitel
*/

#include<stdio.h>
#include<stdlib.h>

int ventas[10];

void inicializaVentas() {
	for (int i = 0; i < 10; i++) {
		ventas[i] = 0;
	}
}

void imprimeVentas() {
	/*
	100*(i+1) - 100*(i+2)-1
	i=0
	100-199
	i=1
	200-299
	*/
	int lim1 = 0;
	int lim2 = 0;
	for (int i = 0; i < 10; i++) {
		lim1 = 100 * (i + 1);
		lim2 = 100 * (i + 2) - 1;
		printf("%d - %d = %d\n", lim1,lim2,ventas[i]);
	}
}

int menu() {
	int op = -1;
	do {
		printf("Sistema de Ventas\n");
		printf("1. Agregar Ventas\n");
		printf("2. Imprime Resumen\n");
		printf("3. Salir\n");
		printf("Opcion: ");
		scanf_s("%d", &op);
	} while (op < 1 || op>3);
	return op;
}

void agregaVentas() {
	int v = 0;
	printf("Ventas: ");
	scanf_s("%d", &v);
	int s = int(200 + 0.09*v);
	printf("Salario %d\n", s);
	if (s >= 1000) {
		ventas[9]++;
	}
	else {
		//  100/100 = 1 -1 
		int pos = (s / 100)-1;
		ventas[pos]++;
	}
}

int main() {
	inicializaVentas();
	int op = 0;
	do {
		system("cls");
		op = menu();
		switch (op) {
			case 1: agregaVentas(); break;
			case 2: imprimeVentas(); break;
			case 3: printf("Saliendo del sistema\n"); break;
			default: printf("Opcion no valida\n");
		}
		system("pause");
	} while (op != 3);	
	return 0;
}
