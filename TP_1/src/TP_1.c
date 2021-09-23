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


	int operandoA = 0;
	int operandoB = 0;
	int opcion=0;
	int resultadoS;
	int resultadoR;
	int resultadoM;
	float resultadoD; //GUARDA EL ESTADO DE LA DIVISION
	float resultado; //GUARDA EL RESULTADO DE LA DIVISION
	int resultadoFA;
	int resultadoFB;
	int flag1=0;
	int flag2=0;
	int flag3=0;


	while(opcion!=5)
	{

		menu(operandoA,operandoB);//IMPRIME LAS OPCIONES EN PANTALLA
		if(scanf("%d",&opcion)==1)
		{
			switch (opcion)
			{
			case 1:
				utn_getNumero(&operandoA, "Ingrese un número: ", "\nError\n");
				printf("Operando A = %d\n",operandoA);
				printf("\n");
				flag1=1;
			break;

			case 2:
				utn_getNumero(&operandoB, "Ingrese un número: ", "\nError\n");
				printf("Operando B = %d\n",operandoB);
				printf("\n");
				flag2=1;
			break;

			case 3:
				if(flag1==1 && flag2==1)
				{

					resultadoS = suma(operandoA,operandoB);
					resultadoR = resta(operandoA,operandoB);
					resultadoM = multiplicacion(operandoA,operandoB);
					resultadoD = division(operandoA, operandoB, &resultado);
					resultadoFA = factorial(operandoA);
					resultadoFB = factorial(operandoB);

					flag3=1;

					puts("TODAS LAS OPERACIONES CALCULADAS");
				}
				else
				{
					puts("Falta ingresar algun operando");
				}
			break;

			case 4:
				if(flag3==1)
				{

					imprimir(resultadoS,resultadoR,resultadoM,resultadoD,resultado,resultadoFA,resultadoFB,operandoA,operandoB);

					flag1 = 0;
					flag2 = 0;
					flag3 = 0;

					operandoA=0;
					operandoB=0;
				}
				else
				{
					puts("Falta calcular las operaciones");
				}
			break;

			case 5:
				puts("Finalizado.");
				printf("\n");
			break;

			}//FIN SWITCH
		}
		else //SI NO SE INGRESAN NÚMEROS EN LAS
		{
			puts("Error. Solo se permiten números."); //NO SÉ CÓMO REINICIARLO DESDE ACÁ
			break;
		}//FIN IF

	}//FIN WHILE

	return EXIT_SUCCESS;
}//FIN MAIN




