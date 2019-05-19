/*
Date: 19/05/2019
Author: jivfur
Description: Ejercicio 620/621 de Deitel & Deitel Como progromar en C, 2ed
*/
#include<stdio.h>
#include<stdlib.h>

void asignarNoFumar();
void asignarFumar();
int menu();


int plane[10] = { 0,0,0,0,0,0,0,0,0,0 };
int fumar = 0;
int noFumar = 0;

int menu() {
	int op = -1;
	do {
		system("cls");
		printf("Sistema de Aerolinea\n");
		printf("1. Seccion de Fumar\n");
		printf("2. Seccion No Fumar\n");
		printf("3. Salir\n");
		printf("Opcion: ");
		scanf_s("%d", &op);
	} while (op!=1 && op!=2 &&op!=3);
	return op;
}

void asignarFumar(){
	if (fumar < 5) {
		plane[fumar] = 1;
		printf("Su asiento es %d, y su seccion es FUMAR\n", fumar + 1);
		fumar++;
	}
	else {
		if (noFumar < 5) {
			printf("La seccion de Fumar esta llena, desea ir a la seccion de No Fumar? ");
			while (getchar() != '\n');
			char res = getchar();
			if (res == 's' || res == 'S') {
				asignarNoFumar();
			}
			else {
				printf("El siguiente vuelo sale en 3 Horas\n");
			}
		}
		else {
			printf("El avion esta lleno, El siguiente vuelo sale en 3 Horas\n");
		}


	}
}

void asignarNoFumar(){
	if (noFumar < 5) {
		plane[noFumar+5] = 1;
		printf("Su asiento es %d, y su seccion es NO FUMAR\n", noFumar + 6);
		noFumar++;

	}
	else {
		if (fumar < 5) {
			printf("La seccion de No Fumar esta llena, desea ir a la seccion de Fumar? ");
			while (getchar() != '\n');
			char res = getchar();
			if (res == 's' || res == 'S') {
				asignarFumar();
			}
			else {
				printf("El siguiente vuelo sale en 3 Horas\n");
			}
		}
		else {
			printf("El avion esta lleno, El siguiente vuelo sale en 3 Horas\n");
		}
	}
	
}


int main() {
	int op = -1;
	do {
		op = menu();
		switch (op) {
		case 1: asignarFumar(); break;
		case 2: asignarNoFumar(); break;
		}
		system("pause");
	} while (op != 3);
	return 0;
}