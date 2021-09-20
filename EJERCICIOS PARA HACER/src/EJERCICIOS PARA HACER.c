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
 * Definir un array de floats de 31 posiciones. Cada posicion corresponder� a un dia
 * del mes. Hacer un programa con un menu de dos opciones, 1.imprimir array y 2.cargar array
 * Al elegir la opcion 1, se imprimira el indice y el valor de cada posicion del array.
 * Al elegir la opcion 2 que le pida al usuario que ingrese un numero de dia (1 a 31)
 * y luego que ingrese un valor de temperatura. Almacenar el valor en el indice correspondiente
 * Ambas opciones deben volver al menu ppal.
 * Utilizar la funcion utn_getNumeroFloat() de la biblioteca utn.h
 *
 */



#include <stdio.h>
#include <stdlib.h>

#include "utn_biblioteca.h"

#define DIAS 31
#define EJ2 5


int main(void) {

	setbuf(stdout,NULL);

	float temperaturaDiaria[DIAS]={0};
	int dia;
	float temperatura;
	int opcion;
	int i;
	int respuesta;





	//1--------------------------------------
	while(1==1)
	{

		//INICIA EL PROGRAMA
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
					printf("\nLa temperatura ingresada es: %.2f�\n\n", temperatura);
				}
				else
				{
					printf("\nError\n");
				}

				for(i=0; i<DIAS; i++) //RECORRE EL ARRAY COMPLETO Y EN CADA POSICION DADA POR dia LE AGREGA EL VALOR DE temperatura
					{
						temperaturaDiaria[dia]=temperatura;

						printf("Dia %d: Temperatura: %.2f�\n",i+1,temperaturaDiaria[i+1]); //IMPRIMIENDO EL ARRAY EN CADA ITERACION SE PUEDE VER COMO DESAPARECEN LOS INDICES 1 Y 31
					}

			}
			else
			{
				if(opcion==1)
				{
					for(i=0; i<DIAS; i++)
					{
						if(temperaturaDiaria[i]!=0)
						{
							printf("Dia %d: Temperatura: %.2f�\n",i+1,temperaturaDiaria[i+1]); //PROBLEMAS CON LA IMPRESION. DEL ORDEN DE CU�NDO INGRESO VALORES PARA EL DIA 1 o 31 DEPENDE QUE SE VEAN O NO
							printf("\n");
						}
					}
				}
			}

		}while(opcion !=1);

	}



	return EXIT_SUCCESS;
}




