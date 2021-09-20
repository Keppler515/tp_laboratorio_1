/*
 ============================================================================
 Name        : BIBLIOTECA.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "utn_biblioteca.h"

int main(void)
{
	setbuf(stdout,NULL);

	int edad;
	int peso;
	char letra;


	if(utn_getCaracter(&letra, "\nIngrese una letra: ", "\nLetra fuera de rango. A a J.\n", 'A', 'J', 1) == 0)
	{
		printf("\nLa letra es: %c\n", letra);
	}
	else
	{
		printf("\nError\n");
	}

	//-------------------------------


	if(utn_getNumero(&edad, "\nIngrese edad: ", "\nEdad fuera de rango. 1 a 10.\n", 1, 10, 3) == 0)
	{
		printf("\nLa edad es: %d\n", edad);
	}
	else
	{
		printf("\nError\n");
	}


	//-----------


	if(utn_getNumero(&peso, "\nIngrese peso: ", "\nPeso fuera de rango.\n", 30, 90, 3) == 0)
	{
		printf("\nEl peso es: %d\n", peso);
	}
	else
	{
		printf("\nError\n");
	}




	return EXIT_SUCCESS;
}

//------------------------------FUNCIONES-----------------------------------








