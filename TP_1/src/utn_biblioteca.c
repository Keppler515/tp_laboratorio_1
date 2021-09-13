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

int division(int a, int b, float* pDir)
{
	float total;
	int estado;

	if(b!=0)
	{
		estado = 0;
		total = (float) a/b;
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

