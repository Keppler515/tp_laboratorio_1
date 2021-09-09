/*
 ============================================================================
 Name        : TP1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "tp1.h"

int factorial(int a, int b);


int main(void) {

	setbuf(stdout,NULL);


	int numero1;
	int numero2;
	float resultado;
	int estado;

/*
	printf("\nIngrese un número: ");
	scanf("%d", &numero1);

	printf("\nIngrese otro número: ");
	scanf("%d", &numero2);

*/

	numero1=3;
	numero2=5;

	resultado = sumar(numero1, numero2);

	printf("\nEl resultado de la suma es: %.2f", resultado);


	resultado = restar(numero1, numero2);

	printf("\nEl resultado de la resta es: %.2f", resultado);


	resultado = multiplicar(numero1, numero2);

	printf("\nEl resultado de la multiplicación es: %.2f", resultado);


	estado = dividir(numero1, numero2, &resultado);

	if(estado==0)
	{
		printf("\nEl resultado de la división es: %.2f", resultado);
	}
	else
	{
		printf("\nNo se puede dividir por cero");
	}


	resultado = factorial(numero1, numero2);

	//printf("\nEl resultado de la factorización es: %.2f", resultado);


	return EXIT_SUCCESS;
}

int factorial(int a, int b)
{
	int suma=0;
	int i;
	float fact;

	suma = a+b;

	for(i=suma;i>1;i--)
	{
		fact = suma*(suma-1);

	}

	return fact;
}

