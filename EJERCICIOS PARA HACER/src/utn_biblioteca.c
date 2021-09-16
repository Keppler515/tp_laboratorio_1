/*
 * utn_biblioteca.c
 *
 *  Created on: 7 sep. 2021
 *      Author: maxis
 */

#include <stdio.h>
#include <stdlib.h>

int suma(int a,int b)
{
	int resultado;
	resultado=a+b;
	return resultado;
}

int resta(int a, int b)
{
	int total;
	total = a-b;
	return total;
}

int multiplicacion(int a, int b)
{
	int total;
	total = a*b;
	return total;
}

float division(float a, float b, float* pDir)
{
	float total;
	int estado;

	if(b!=0)
	{
		estado = 0;
		total = a/b;
	}
	else
	{
		estado = -1;
	}

	*pDir = total;

	return estado;
}

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{

	int bufferInt;
	int retorno = -1;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo<=maximo && reintentos>=0)
	{
		do
		{
			printf("%s",mensaje);
			scanf("%d",&bufferInt);

			if(bufferInt>=minimo && bufferInt<=maximo)
			{
				*pResultado = bufferInt;
				retorno = 0;
				break;

			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		} while(reintentos>=0);
	}

	return retorno;

}

int utn_getCaracter(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos)
{

	char bufferChar;
	int retorno = -1;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo<=maximo && reintentos>=0)
	{
		do
		{
			printf("%s",mensaje);
			fflush(stdin);
			scanf("%c",&bufferChar);

			if(bufferChar>=minimo && bufferChar<=maximo)
			{
				*pResultado = bufferChar;
				retorno = 0;
				break;

			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		} while(reintentos>=0);
	}

	return retorno;

}

int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{

	float bufferInt;
	int retorno = -1;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo<=maximo && reintentos>=0)
	{
		do
		{
			printf("%s",mensaje);
			scanf("%f",&bufferInt);

			if(bufferInt>=minimo && bufferInt<=maximo)
			{
				*pResultado = bufferInt;
				retorno = 0;
				break;

			}
			else
			{
				printf("%s",mensajeError);
				reintentos--;
			}
		} while(reintentos>=0);
	}

	return retorno;

}

int factorizar(int a)
{
	int total;

	int i;

	for(i=0; i<a; i++)
	{
		total = a*(a-1);
	}

	return total;
}

void imprimirArray(int contenidoArray[],int longitudArray)
{
	int i;

	for(i=0; i<longitudArray; i++)
	{
		printf("%d ",contenidoArray[i]);
	}

}


int borrarImparesArray(int arrayDeEnteros[], int tamanoArray)
{
	int retorno = -1;
	int i;
	if(arrayDeEnteros != NULL && tamanoArray >=0)
	{
		for(i=0; i<tamanoArray; i++)
		{
			if(arrayDeEnteros[i]%2 != 0)
			{
				arrayDeEnteros[i] = 0;
			}
		}

		retorno = 0;
	}

	return retorno;
}

