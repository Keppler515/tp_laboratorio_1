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


int main(void)
{

	setbuf(stdout,NULL);


	int operandoA; //¿CÓMO HACER QUE NO SE PUEDAN REALIZAR LOS CALCULOS CON LA BASURA QUE ESTÁ EN LAS VARIABLES SIN TENER QUE INICIALIZAR EN CERO?
	int operandoB;
	int opcion;
	int resultadoS;
	int resultadoR;
	int resultadoM;
	float resultadoD; //GUARDA EL ESTADO DE LA DIVISION
	float resultado; //GUARDA EL RESULTADO DE LA DIVISION
	int resultadoFA;
	int resultadoFB;

	while(1==1) //BUCLE INFINITO
	{
		printf("\n");
		puts("MENU DE OPCIONES");	//SI PONGO ALGO QUE NO SEA UN NÚMERO SE ROMPE TODO.
		printf("\n");
		puts("\t1- Ingresar 1er operando (A=x): ");
		puts("\t2- Ingresar 2do operando (B=x): ");
		puts("\t3- Calcular todas las operaciones: "); //NO DEBERÍA CALCULAR NI MOSTRAR LOS RESULTADOS CON LA BASURA QUE HAY EN LAS VARIABLES
		puts("\t4- Mostrar resultados:");
		scanf("%d",&opcion);


		switch (opcion)
		{
		case 1:
			utn_getNumero(&operandoA, "Ingrese un número de 1 a 100: ", "\nNumero fuera de rango\n", -100, 100, 3);
			printf("Operando A = %d\n",operandoA);
			printf("\n");
		break;

		case 2:
			utn_getNumero(&operandoB, "Ingrese un número de 1 a 100: ", "\nNúmero fuera de rango\n", -100, 100, 3);
			printf("Operando B = %d\n",operandoB);
			printf("\n");
		break;

		case 3:
			resultadoS = suma(operandoA,operandoB);
			resultadoR = resta(operandoA,operandoB);
			resultadoM = multiplicacion(operandoA,operandoB);
			resultadoD = division(operandoA, operandoB, &resultado);
			resultadoFA = factorial(operandoA);
			resultadoFB = factorial(operandoB);

			puts("TODAS LAS OPERACIONES CALCULADAS");
			printf("\n");
		break;

		case 4:

			printf("El resultado de la suma es: %d",resultadoS);
			printf("\n");
			printf("El resultado de la resta es: %d",resultadoR);
			printf("\n");
			printf("El resultado de la multiplicación es: %d",resultadoM);
			printf("\n");
			if(resultadoD==0)
			{
				printf("El resultado de la división es: %.2f",resultado);
				printf("\n");
			}
			else
			{
				printf("No se puede dividir por cero");
				printf("\n");
			}
			printf("El factorial de %d es: %d",operandoA,resultadoFA);
			printf("\n");
			printf("El factorial de %d es: %d",operandoB,resultadoFB);
			printf("\n");

		break;

		default:
			puts("Indique una opción");
			printf("\n");
		break;

		}//FIN SWITCH

	}//FIN WHILE

	return EXIT_SUCCESS;
}//FIN MAIN




