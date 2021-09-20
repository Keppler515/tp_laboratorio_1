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
	int resultadoS;
	int resultadoR;
	int resultadoM;
	float resultadoD;
	float resultado;
	int resultadoFA;
	int resultadoFB;

	operandoA=0;
	operandoB=0;

	do
	{
		puts("1- Ingresar 1er operando (A=x): ");
		puts("2- Ingresar 2do operando (B=x): ");
		puts("3- Calcular todas las operaciones: ");
		puts("4- Mostrar resultados:");
		scanf("%d", &opcion);
		printf("\n");


			if(opcion==1)
			{
				utn_getNumero(&operandoA, "Ingrese un número de 1 a 100: ", "\nNumero fuera de rango\n", -100, 100, 3);
				printf("Operando A = %d\n",operandoA);
				printf("\n");
			}
			else
			{
				if(opcion==2)
				{
					utn_getNumero(&operandoB, "Ingrese un número de 1 a 100: ", "Número fuera de rango", -100, 100, 3);
					printf("Operando B = %d\n",operandoB);
					printf("\n");
				}
			}

			if(opcion==3)
			{
				resultadoS = suma(operandoA,operandoB);
				resultadoR = resta(operandoA,operandoB);
				resultadoM = multiplicacion(operandoA,operandoB);
				resultadoD = division(operandoA, operandoB, &resultado);
				resultadoFA = factorial(operandoA);
				resultadoFB = factorial(operandoB);

				puts("Operaciones calculadas");
				printf("\n");
			}

			if(opcion==4)
				{
					if(operandoA!=0 || operandoB!=0)
					{
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
					}
					else
					{
						puts("No hay operandos ingresados.");
						printf("\n");
					}
				}


	}while(opcion!=4);

	printf("\n");

	return EXIT_SUCCESS;
}




