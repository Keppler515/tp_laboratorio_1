/*
 ============================================================================
 Name        : EJERCICIOS.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

 * Ejercicio 1:
 * crear un programa que permita registrar el valor de temperatura maxima de cada dia de un mes.
 * Definir un array de floats de 31 posiciones. Cada posicion corresponderá a un dia
 * del mes. Hacer un programa con un menu de dos opciones, 1.imprimir array y 2.cargar array
 * Al elegir la opcion 1, se imprimira el indice y el valor de cada posicion del array.
 * Al elegir la opcion 2 que le pida al usuario que ingrese un numero de dia (1 a 31)
 * y luego que ingrese un valor de temperatura. Almacenar el valor en el indice correspondiente
 * Ambas opciones deben volver al menu ppal.
 * Utilizar la funcion utn_getNumeroFloat() de la biblioteca utn.h
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

int borrarImparesArray(int arrayDeEnteros[], int tamanoArray);

int main(void) {

	setbuf(stdout,NULL);

	float temperaturaDiaria[DIAS];
	int dia;
	float temperatura;
	int opcion;
	int i;
	int respuesta;
	int arrayEjercicio2[EJ2];
	int j;
	int numero;

	//2

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




	//1--------------------------------------

	for(i=0; i<=DIAS; i++){temperaturaDiaria[i]=0;} //INICIALIZO ARRAY EN 0 PARA QUE NO HAYA BASURA


	do
	{
		printf("\n1-Imprimir array\n");
		printf("2-Cargar array\n");
		scanf("%d", &opcion);


		if(opcion == 2)
		{
			//PIDE EL DIA
			respuesta = utn_getNumero(&dia, "\nIngrese dia (1 a 31): ", "\nFechafuera de rango.\n", 1, 31, 3);
			if(respuesta == 0)
			{
				printf("\nLa fecha es: %d\n", dia);
			}
			else
			{
				printf("\nError\n");
			}

			//PIDE LA TEMPERATURA
			respuesta = utn_getNumeroFlotante(&temperatura, "\nIngrese temperatura (0 a 100): ", "\nTemperatura fuera de rango.\n", 0.00, 100.00, 3);
			if(respuesta == 0)
			{
				printf("\nLa temperatura ingresada es: %.2f°\n\n", temperatura);
			}
			else
			{
				printf("\nError\n");
			}

			for(i=0; i<DIAS; i++) //RECORRE EL ARRAY COMPLETO Y EN CADA POSICION DADA POR dia LE AGREGA EL VALOR DE temperatura
				{
					temperaturaDiaria[dia]=temperatura;

				}

			//contador++;

		}
		else
		{
			for(i=0; i<=DIAS; i++)
			{
				if(temperaturaDiaria[i]!=0.00)
				{
					printf("Dia %d: Temperatura: %.2f°\n",i+1,temperaturaDiaria[i]);
				}
			}
		}

	}while(opcion !=1);






	return EXIT_SUCCESS;
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


