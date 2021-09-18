/*
 ============================================================================
 Name        : TP_1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones:
1. Ingresar 1er operando (A=x)
2. Ingresar 2do operando (B=y)
3. Calcular todas las operaciones
a) Calcular la suma (A+B)
b) Calcular la resta (A-B)
c) Calcular la division (A/B)
d) Calcular la multiplicacion (A*B)
e) Calcular el factorial (A!)
4. Informar resultados
a) “El resultado de A+B es: r”
b) “El resultado de A-B es: r”
c) “El resultado de A/B es: r” o “No es posible dividir por cero”
d) “El resultado de A*B es: r”
e) “El factorial de A es: r1 y El factorial de B es: r2”
5. Salir
• Todas las funciones matemáticas del menú se deberán realizar en una biblioteca aparte,
que contenga las funciones para realizar las cinco operaciones.
• En el menú deberán aparecer los valores actuales cargados en los operandos A y B
(donde dice “x” e “y” en el ejemplo, se debe mostrar el número cargado)
• Deberán contemplarse los casos de error (división por cero, etc)
• Documentar todas las funciones

 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utn_biblioteca.h"


int main(void) {

	setbuf(stdout,NULL);


	int operandoA;
	int operandoB;
	int opcion;
	float resultado;

	do
	{
		puts("1- Ingresar 1er operando (A=x): ");
		puts("2- Ingresar 2do operando (B=x): ");
		puts("3- Calcular todas las operaciones: ");
		scanf("%d", &opcion);



			if(opcion==1)
			{
				utn_getNumero(&operandoA, "Numero de 1 a 100: ", "\nNumero fuera de rango\n", 1, 100, 3);
				printf("Operando A = %d\n",operandoA);
				printf("\n");
			}
			else
			{
				if(opcion==2)
				{
					utn_getNumero(&operandoB, "Numero de 1 a 100: ", "Numero fuera de rango", 1, 100, 3);
					printf("Operando B = %d\n",operandoB);
					printf("\n");
				}
			}


	}while(opcion!=3);


	//SUMA

		printf("\nEl resultado de la suma es: %d",suma(operandoA,operandoB));
		printf("\n");

	//RESTA

		printf("\nEl resultado de la resta es: %d",resta(operandoA,operandoB));
		printf("\n");

	//MULTIPLICACION

		printf("\nEl resultado de la multiplicación es: %d",multiplicacion(operandoA,operandoB));
		printf("\n");

	//DIVISION

		if(division(operandoA, operandoB, &resultado)==0)
		{
			printf("\nEl resultado de la división es: %.2f", resultado);
			printf("\n");
		}
		else
		{
			printf("No se puede dividir por cero");
			printf("\n");
		}


	//FACTORIAL

		printf("\nEl factorial de A es: %d",factorial(operandoA));
		printf("\n");
		printf("\nEl factorial de B es: %d",factorial(operandoB));
		printf("\n");


	return EXIT_SUCCESS;
}




