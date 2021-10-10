/*
 ============================================================================
 Name        : TP_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "utn_biblioteca.h"


#define CANTIDAD_EMP	1000
#define CHAR_LEN		64

int main(void)
{

	setbuf(stdin,NULL);

	Employee arrayEmpleados[CANTIDAD_EMP];

	initEmployees(arrayEmpleados, CANTIDAD_EMP);

	int opcion;
	int idAux;
	int idNuevo;
	int i;
	int flagAltas = -1;
	int orden;
	float promedioS;

	char nameAux[CHAR_LEN];
	char lastNameAux[CHAR_LEN];
	int sectorAux;
	float salaryAux;



	while(1)
	{

		fflush(stdout);
		if(utn_getNumero(&opcion, "INGRESE OPCION\n\n1. ALTAS\n2. MODIFICAR\n3. BAJA\n4. INFORMAR\n", "\nOPCION INCORRECTA\n")==0)
		{

		for(i=0; i<CANTIDAD_EMP; i++) // Si la cantidad de altas al iniciar es 0 no entra en las opciones 2, 3 y 4. Al final se vuelve a setear en 0.
		{
			if(arrayEmpleados[i].isEmpty==1)
			{
				flagAltas=0;
			}
		}

		switch(opcion)
		{
			case 1:
				if(utn_getText(nameAux, CHAR_LEN, "INGRESE NOMBRE: ", "NOMBRE INCORRECTO.\n")==0)
				{
					if(utn_getText(lastNameAux, CHAR_LEN, "INGRESE APELLIDO: ", "APELLIDO INCORRECTO.\n")==0)
					{
						if(utn_getNumero(&sectorAux, "INGRESE SECTOR: ", "SECTOR INCORRECTO.\n")==0)
						{
							if(utn_getNumeroFlotante(&salaryAux, "INGRESE SALARIO: ", "SALARIO INCORRECTO.\n")==0)
							{
								if(arrayEmpleados!=NULL && CANTIDAD_EMP>0 && sectorAux>0 && salaryAux>0)
								{
									idNuevo = generadorID();

									if(addEmployee(arrayEmpleados, CANTIDAD_EMP, idNuevo, nameAux, lastNameAux, salaryAux, sectorAux)==0)
									{
										puts("\nEMPLEADO INGRESADO CORRECTAMENTE\n");
									}
									else
									{
										puts("ERROR.\n");
									}
								}
								else
								{
									printf("ERROR EN ALGUN DATO INGRESADO\n");
								}
							}
						}
					}
				}
			break;

			case 2:
				if(flagAltas==0 && utn_getNumero(&idAux, "INGRESE ID: ", "ID INCORRECTO\n")==0)
				{
					if(modifyEmployee(arrayEmpleados, CANTIDAD_EMP, idAux)==0)
					{
						puts("\nDATOS MODIFICADOS CORRECTAMENTE\n");
					}
				}
				else
				{
					puts("\nNO HAY DATOS PARA MODIFICAR.\n");
				}
			break;

			case 3:
				if(flagAltas==0 && utn_getNumero(&idAux, "INGRESE ID: ", "ID INCORRECTO\n")==0)
				{
					if(removeEmployee(arrayEmpleados,CANTIDAD_EMP,idAux)==0)
					{
						puts("\nDATOS BORRADOS\n");
					}
				}
				else
				{
					puts("\nNO HAY DATOS PARA ELIMINAR\n");
				}

			break;

			case 4:
				if(flagAltas==0 && utn_getNumero(&orden, "IMPRIMIR LISTA DE EMPLEADOS\n\n0. ASC.\n1. DESC.\n", "OPCION INCORRECTA")==0)
				{
					if(sortEmployees(arrayEmpleados,CANTIDAD_EMP,orden)==0)
					{
						printEmployees(arrayEmpleados,CANTIDAD_EMP);
						printf("\nTOTAL DE SUELDOS: %.2f\n",total(arrayEmpleados, CANTIDAD_EMP));
						printf("\nPROMEDIO DE SUELDOS: %.2f\n",promedioS = promedio(arrayEmpleados, CANTIDAD_EMP));
						superanPromedio(arrayEmpleados, CANTIDAD_EMP, promedioS);
					}
				}
				else
				{
					puts("\nNO HAY DATOS PARA MOSTRAR\n");
					break;
				}
			break;

			default:
				puts("\nOPCION INCORRECTA\n");
			break;
		}//FIN switch
		}//FIN getNumero
		flagAltas=-1;
	}//FIN while

	return EXIT_SUCCESS;
}


