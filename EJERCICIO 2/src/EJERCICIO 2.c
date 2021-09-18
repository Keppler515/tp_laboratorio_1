/*
 ============================================================================
 Name        : EJERCICIOS.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
*
 *
 * * Ejercicio 2:
 a) Realizar un programa que le pida 5 numeros int al usuario y los almacene en un array.
 Luego ejecutar la funcion borrarImpares() pasandole el array y que deberá reemplazar
 los numeros que son impares por un cero.
 b) Luego imprimir el array para chequear el funcionamiento.
 c) Ordenar el array y volver a imprimirlo ordenado.
 *
 *
 */



#include <stdio.h>
#include <stdlib.h>

#include "utn_biblioteca.h"

#define DIAS 31
#define EJ2 5


int main(void) {

	setbuf(stdout,NULL);


	int respuesta;
	int arrayEjercicio2[EJ2];
	int j;
	int numero;



//2------------------------

for(j=0; j<EJ2; j++)
{
	respuesta = utn_getNumero(&numero, "\nIngrese numero (1 a 100): ", "\nNumero fuera de rango.\n", 1, 100, 3);

	if(respuesta == 0)
	{
		printf("\nEl numero ingresado es: %d\n", numero);
		arrayEjercicio2[j]=numero;
	}
	else
	{
		printf("\nError\n");
	}
}

printf("El array original es:\n");

for(j=0; j<EJ2; j++)
{
	printf("%d\n",arrayEjercicio2[j]);
}


if(borrarImparesArray(arrayEjercicio2, EJ2)==0)
{
	printf("\nEl array modificado es:\n");

	for(j=0; j<EJ2; j++)
	{
		printf("%d\n",arrayEjercicio2[j]);
	}
}




	return EXIT_SUCCESS;
}




