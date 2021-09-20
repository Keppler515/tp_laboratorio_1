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
		total =(float) a/b;
	}
	else
	{
		estado = -1;
	}

	*pDir = total;

	return estado;
}

int factorial(int numero)
{
	int i;
	int aux=numero;

	for(i=1; i<numero; i++)
	{
		aux=aux*i;
	}
	return aux;
}

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{

	int bufferInt;
	int retorno = -1;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo<=maximo && reintentos>=0)
	{

		while(reintentos>=0)
		{
			puts(mensaje);
			fflush(stdin);
			if(scanf("%d",&bufferInt)==1)
			{
				if(bufferInt>=minimo && bufferInt<=maximo)
				{
					retorno = 0;
					break;
				}
				else
				{
					puts(mensajeError);
					reintentos--;
				}
			}
			else
			{
				puts(mensajeError);
			}
		}

		*pResultado = bufferInt;
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

int esNumerica(char cadena[])
{
	int retorno = -1;
	int i = 0;
	if(cadena!=NULL)
	{
		while(cadena[i]!='\0')
			{
				if(cadena[i]<'0' || cadena[i]>'9')
				{
					puts("Error");
				}
				else
				{
					retorno=0;
				}

				i++;
			}
	}

	return retorno;
}


int esTexto(char cadena[])
{
	int retorno = -1;
	int i = 0;
	if(cadena!=NULL)
	{
		while(cadena[i]!='\0')
			{
				if((cadena[i]>= 'A' && cadena[i]<= 'Z') || (cadena[i]>= 'a'  && cadena[i]<= 'z' ))
				{
					retorno=0;
				}
				else
				{
					retorno=2;
				}

				i++;
			}
	}

	return retorno;
}


int esAlfanumerica(char cadena[])
{
	{
		int retorno = -1;
		int i = 0;
		if(cadena!=NULL)
		{
			while(cadena[i]!='\0')
				{
					if(esTexto(cadena)==0 && esNumerica(cadena)==0)
					{
						retorno=0;
					}

					i++;
				}
		}

		return retorno;
	}

}
