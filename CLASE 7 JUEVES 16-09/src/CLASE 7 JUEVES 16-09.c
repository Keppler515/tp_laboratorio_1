/*
 ============================================================================
 Name        : CLASE.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================


 PARA EL MARTES


-----------------------1-------------------------------------

 int esNumerica(char cadena[])	OK
{

}

int esTexto(char cadena[])	OK
{

}

int esAlfanumerica(char cadena[])	OK
{

}
int esEmail(char cadena[])
{

}


-----------------------2-------------------------------------


formatNombre(cadenaNombre,cadenaApellido);

que imprima: "*-Perez,Juan-*"


 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_biblioteca.h"

int mySrtLen(char cadena[], int* contadorMayusculas);
int esEmail(char cadena[]);

int main(void) {

	setbuf(stdout,NULL);


	char cadenaDeCaracteres[33]="Buenas Tardes. Esto FUNCIONA";
	char cadenaCopia[18]="s4@";

	int mayusculas = 0;
	int caracteres;

	//strncpy(cadenaCopia, cadenaDeCaracteres, sizeof(cadenaCopia));
	//cadenaCopia[sizeof(cadenaCopia)-1]="\0";

	//printf(strlen(cadenaCopia));


	caracteres=mySrtLen(cadenaDeCaracteres,&mayusculas);
	printf("Cantidad de caracteres: %d\nCantidad de mayúsculas: %d\n",caracteres,mayusculas);

	//printf("%d\n%d",mySrtLen(cadenaDeCaracteres,&mayusculas));

	if(esNumerica(cadenaCopia)==0)
	{
		puts("Es numerica");
	}
	else
	{
		if(esNumerica(cadenaCopia)==2)
		{
			puts("Algun caracter no es numerico");
		}
		else
		{
			puts("No es numerica");
		}
	}
//----------------------------------------------

	if(esTexto(cadenaCopia)==0)
	{
		puts("Es de texto");
	}
	else
	{
		if(esTexto(cadenaCopia)==2)
		{
			puts("Algun caracter no es de texto");
		}
		else
		{
			puts("No es de texto");
		}
	}
//-----------------------------------------------

	if(esAlfanumerica(cadenaCopia)==0) //CÓMO VALIDAR QUE HAYA TEXTO Y NUMEROS?
	{
		puts("Es alfanumérica");
	}
	else
	{
		if(esAlfanumerica(cadenaCopia)==2)
		{
			puts("Algun caracter no es alfanumérico");
		}
		else
		{
			puts("No es alfanumérica");
		}
}

//------------------------------------------------



	return EXIT_SUCCESS;
}





int mySrtLen(char cadena[], int* contadorMayusculas)

{

	int i = 0;
	int contador = 0;

	while(cadena[i]!='\0')
	{
		if(cadena[i]>='A' && cadena[i]<='Z')
		{
			contador++;
		}

		i++;
	}

	*contadorMayusculas = contador;

	return i;
}


/*
void myPuts(cadena)
{
	printf("%c",variableChar);
}


void myStrCpy(cadena2, cadena1)
{

}
*/



int esEmail(char cadena[])
{

}







