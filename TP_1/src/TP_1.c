/*
 ============================================================================
 Name        : TP_1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "utn_biblioteca.h"

int main(void) {

	setbuf(stdout,NULL);


	int numero1;
	int numero2;
	float resultado;


	printf("Ingrese un número: ");
	scanf("%d", &numero1);

	printf("Ingrese otro número: ");
	scanf("%d", &numero2);

/*1- El factorial no me funciona.
 * 		Para mí la lógica está bien construida. Incluso lo probé de varias maneras.
 *
 * 2- Problemas con las funciones.
 * 		Si pido los numeros una sola vez y llamo a las funciones para que hagan las operaciones,
 * 		va a depender de dónde invoque a cada función para que me de o no el resultado.
 *
 * 		Si pido los numeros antes de llamar a cada función, los resultados dan bien.
 *
 * 		El problema puede estar en la función "division" porque si no la invoco no me da error.
*/



//SUMA

	resultado = suma(numero1, numero2);
	printf("\nEl resultado de la suma es: %.0f",resultado);

//RESTA

	resultado = resta(numero1, numero2);
	printf("\nEl resultado de la resta es: %.0f",resultado);

//MULTIPLICACION DA MAL EL RESULTADO SI NO SE INVOCA MAS ARRIBA O SI SE INVOCA A DIVISION

	resultado = multiplicacion(numero1, numero2);
	printf("\nEl resultado de la multiplicación es: %.0f",resultado);

//DIVISION NO FUNCIONA BIEN Y CAUSA ERRORES EN EL RESTO DE LAS FUNCIONES.


	if(division(numero1, numero2, &resultado)==0)
	{
		printf("%.2f", resultado);
	}
	else
	{
		printf("No se puede dividir por cero");
	}


	return EXIT_SUCCESS;
}
