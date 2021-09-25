/*
 * utn_biblioteca.c
 *
 *  Created on: 7 sep. 2021
 *      Author: maxis
 */

#include <stdio.h>
#include <stdlib.h>

float suma(float a,float b)
{
	float total;
	total=a+b;
	return total;
}


float resta(float a,float b)
{
	float total;
	total = a-b;
	return total;
}


float multiplicacion(float a,float b)
{
	float total;
	total = a*b;
	return total;
}


int division(float a,float b, float* pDir)
{
	float total;
	int estado;

	if(b!=0)
	{
		estado = 0;
		total =a/b;
	}
	else
	{
		estado = -1;
	}

	*pDir = total;

	return estado;
}


int factorial(float a, int* pResultado)
{
	int retorno;

	if(a<=0 || a>(int)a)
	{
		retorno = -1;
	}
	else
	{
		int i;
		int aux = (int)a;

		for(i=1; i<a; i++)
		{
			aux=aux*i;
		}

		*pResultado = aux;
		retorno = 0;
	}

	return retorno;
}


int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError)
{

	int bufferInt;
	int retorno = -1;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL)
	{

			printf(mensaje);
			fflush(stdin);
			if(scanf("%d",&bufferInt)==1)
			{
				retorno = 0;
			}
			else
			{
				puts(mensajeError);
			}

		*pResultado = bufferInt;
	}

	return retorno;

}


int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError)
{
	float bufferInt;
	int retorno = -1;

	while(pResultado != NULL && mensaje != NULL && mensajeError != NULL)
	{
			printf(mensaje);
			fflush(stdin);
			if(scanf("%f",&bufferInt)==1)
			{
				retorno = 0;
				break;
			}
			else
			{
				puts(mensajeError);
			}
	}
	*pResultado = bufferInt;

	return retorno;
}


void menu(float a, float b)
{
	printf("\n");
	puts("MENU DE OPCIONES");
	printf("\n");
	printf("1- Ingresar 1er operando (A=%.2f)",a);
	printf("\n");
	printf("2- Ingresar 2do operando (B=%.2f)",b);
	printf("\n");
	puts("3- Calcular todas las operaciones. ");
	puts("4- Mostrar resultados.");
	puts("5- Salir.");
}


void imprimir(float s, float r, float m, int estadoD, float d, int estadoFA, int estadoFB, int fA, int fB, float num1, float num2)
{
	printf("\nRESULTADOS: \n\n");
	printf("El resultado de la suma es: %.2f",s);
	printf("\n");
	printf("El resultado de la resta es: %.2f",r);
	printf("\n");
	printf("El resultado de la multiplicación es: %.2f",m);
	printf("\n");
	if(estadoD==0)
	{
		printf("El resultado de la división es: %.2f",d);
		printf("\n");
	}
	else
	{
		printf("No se puede dividir por cero");
		printf("\n");
	}

	if(estadoFA==0)
	{
		printf("El factorial de %.2f es: %d",num1,fA);
		printf("\n");
	}
	else
	{
		printf("El número %.2f no se puede factorizar",num1);
		printf("\n");
	}
	if(estadoFB==0)
	{
		printf("El factorial de %.2f es: %d",num2,fB);
		printf("\n");
	}
	else
	{
		printf("El número %.2f no se puede factorizar",num2);
		printf("\n");
	}
}

