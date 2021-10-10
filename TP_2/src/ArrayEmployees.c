/*
 * ArrayEmployees.c
 *
 *  Created on: 30 sep. 2021
 *      Author: maxis
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "utn_biblioteca.h"

//----------INICIALIZAR LISTA---------

/** \brief 	Inicializa todas las posiciones del array con un flag isEmpty=0 para indicar que las posiciones están libres.
 *
 * \param 	Employee list[] es un puntero al array de empleados.
 * \param	int len recibe la longitud del array.
 * return	retorno = -1 ERROR. retorno = 0 OK.
 */

int initEmployees(Employee list[], int len)
{
		int retorno = -1;
		int i;

		if(list!=NULL && len>0)
		{
			for(i=0; i<len; i++)
			{
				list[i].isEmpty = 0;
			}
		retorno = 0;
		}
	return retorno;
}

//----------AGREGAR EMPLEADO---------

/** \brief 	Llama a diferentes funciones dentro que reciben los datos y los agregan al array de empleados.
 * \param 	Employee list[] es un puntero al array de empleados.
 * \param	int len recibe la longitud del array.
 * \param	char name[] recibe el nombre del empleado.
 * \param	char lastName[] recibe el apellido del empleado.
 * \param	float salary recibe el salario del empleado.
 * \param	int sector recibe el sector del empleado.
 * return	retorno = -1 ERROR. retorno = 0 OK.
 */

int addEmployee(Employee list[], int len, int id, char name[],char lastName[],float salary,int sector)
{
	int retorno = -1;
	int indice;

	indice = buscarLibre(list, len);

	if(indice>=0)
	{
		list[indice].id=id;
		strcpy(list[indice].name,name);
		strcpy(list[indice].lastName,lastName);
		list[indice].salary=salary;
		list[indice].sector=sector;
		list[indice].isEmpty=1;
		retorno = 0;
	}
	else
	{
		puts("NO HAY LUGARES DISPONIBLES");
	}
 return retorno;
}

//----------IMPRIMIR LISTA---------

/** \brief 	Imprime el array de empleados.
 * \param 	Employee list[] es un puntero al array de empleados.
 * \param	int len recibe la longitud del array.
 * return	retorno = -1 ERROR. retorno = 0 OK.
 */

int printEmployees(Employee list[], int len)
{
	int retorno = -1;
	int i;
	if(list!=NULL && len>0)
	{
		for(i=0; i<len; i++)
		{
			if(list[i].isEmpty == 1)
			{
				printf("\nNOMBRE: %s\nAPELLIDO: %s\nID: %d\nSALARIO: %.2f\nSECTOR: %d\n",list[i].name, list[i].lastName, list[i].id, list[i].salary, list[i].sector);
				retorno = 0;
			}
		}

	}

	return retorno;
}


//----------BUSCADOR DE EMPLEADO---------

/** \brief 	Busca en la lista el ID que coincida con el ingresado en la funcion utn_getNumero.
 * \param 	Employee list[] es un puntero al array de empleados.
 * \param	int len recibe la longitud del array.
 * \param	int id recibe el ID del empleado que se desea buscar.
 * return	La función devuelve por retorno el valor de la posición encontrada.
 */

int findEmployeeById(Employee list[], int len, int id)
{
	int i;
	int indice = -1;

	if(list!=NULL && len>0)
	{
	for(i=0; i<len; i++)
		{
			if(list[i].id == id && list[i].isEmpty==1)
			{
				indice = i;
				break;
			}

		}
	}
	return indice;
}

//--------------------BORRAR EMPLEADO-------------

/** \brief 	Busca en la lista el ID que coincida con el ingresado.
 * \param 	Employee list[] es un puntero al array de empleados.
 * \param	int len recibe la longitud del array.
 * \param	int id recibe el ID del empleado que se desea buscar.
 * return	retorna 0 si pudo cumplir o -1 si no.
 */

int removeEmployee(Employee list[], int len, int id)
{
	int retorno = -1;
	int i;
	int opcionAux;

	int index = findEmployeeById(list, len, id);

	for(i=0; i<len; i++)
	{
		if(index>=0 && list[index].isEmpty==1)
		{
			printf("\nEMPLEADO ENCONTRADO\n\nNOMBRE: %s\nAPELLIDO: %s\nSALARIO: %.2f\nSECTOR: %d\nPOSICION: %d\n",list[index].name,list[index].lastName,list[index].salary,list[index].sector,index);

			if(utn_getNumero(&opcionAux,"\nDESEA ELIMINAR LOS DATOS? 1-SI / 2-NO\n", "ERROR")==0)
			{
				switch(opcionAux)
				{
					case 1:
						list[index].isEmpty=-1;
						retorno = 0;
					break;

					case 2:
						puts("\nCANCELADO\n");
					break;
				}
			}
			break;
		}
		else
		{
			break;
		}
	}

	return retorno;
}

//---------------MODIFICAR DATOS-------------

/** \brief 	Permite modificar algun dato del seleccionado por ID.
 * \param 	Employee list[] es un puntero al array de empleados.
 * \param	int len recibe la longitud del array.
 * \param	int id recibe el ID del empleado a modificar.
 * return	retorno = -1 ERROR. retorno = 0 OK.
 */

int modifyEmployee(Employee list[], int len, int id)
{
	int retorno = -1;
	int opcionAux;
	char nameAux[64];
	char lastNameAux[64];
	int sectorAux;
	float salaryAux;

	int index = findEmployeeById(list, len, id);

	if(index>=0)
	{
		printf("\nEMPLEADO ENCONTRADO\n\nNOMBRE: %s\nAPELLIDO: %s\nSALARIO: %f\nSECTOR: %d\n",list[index].name,list[index].lastName,list[index].salary,list[index].sector);

		if(utn_getNumero(&opcionAux,"\n¿QUE DATO DESEA MODIFICAR?\n\n1- NOMBRE\n2- APELLIDO\n3- SALARIO\n4- SECTOR\n", "ERROR.\n")==0)
		{
			switch(opcionAux)
			{
			case 1:
				if(utn_getText(nameAux, 64, "INGRESE NOMBRE: ", "ERROR.\n")==0)
				{
					strcpy(list[index].name,nameAux);
				}
			break;

			case 2:
				if(utn_getText(lastNameAux, 64, "INGRESE APELLIDO: ", "ERROR.\n")==0)
				{
					strcpy(list[index].lastName,lastNameAux);
				}
			break;

			case 3:
				if(utn_getNumeroFlotante(&salaryAux, "INGRESE SALARIO: ", "ERROR.\n")==0)
				{
					list[index].salary=salaryAux;
				}
			break;

			case 4:
				if(utn_getNumero(&sectorAux, "INGRESE SECTOR: ", "ERROR.\n")==0)
				{
					list[index].sector=sectorAux;
				}
			break;

			default:
				puts("OPCION INCORRECTA\n");
			break;
			}//FIN SWITCH
		}
	}

	retorno = 0;
	return retorno;
}


//---------------ORDENAR LISTA-------------

/** \brief 	Ordena la lista segun la opcion elegida.
 * \param 	Employee list[] es un puntero al array de empleados.
 * \param	int len recibe la longitud del array.
 * \param	int order recibe la opcion de ordenamiento.
 * return	retorno = -1 ERROR. retorno = 0 OK.
 */

int sortEmployees(Employee pList[], int len, int order)
{
	int retorno = -1;
	int i;
	Employee buffer;
	int flagSwap;
	if(pList!=NULL && len>0)
	{
		do
		{
			flagSwap = 0;

			for(i=0; i<len-1; i++)
			{
				switch(order)
				{
				case 0:
					if(strcmp(pList[i].lastName,pList[i+1].lastName)>0)
					{
						flagSwap = 1;
						buffer=pList[i];
						pList[i]=pList[i+1];
						pList[i+1]=buffer;
					}
					else
					{
						if(strcmp(pList[i].lastName,pList[i+1].lastName)==0)
						{
							if(pList[i].sector>pList[i+1].sector)
							{
								flagSwap = 1;
								buffer=pList[i];
								pList[i]=pList[i+1];
								pList[i+1]=buffer;
							}
						}
					}
				break;
				case 1:
					if(strcmp(pList[i+1].lastName,pList[i].lastName)>0)
					{
						flagSwap = 1;
						buffer=pList[i];
						pList[i]=pList[i+1];
						pList[i+1]=buffer;
					}
					else
					{
						if(strcmp(pList[i].lastName,pList[i+1].lastName)==0)
						{
							if(pList[i].sector>pList[i+1].sector)
							{
								flagSwap = 1;
								buffer=pList[i];
								pList[i]=pList[i+1];
								pList[i+1]=buffer;
							}
						}
					}
				break;
				}//FIN switch
			}//FIN for
		}while(flagSwap);
		retorno = 0;
	}
	return retorno;
}

//--------------BUSCA UNA POSICION LIBRE-------------

/** \brief 	Recorre el array y guarda la primer posicion libre encontrada.
 * \param 	Employee list[] es un puntero al array de empleados.
 * \param	int len recibe la longitud del array.
  * return	Retorna el valor de la posicion libre.
 */

int buscarLibre(Employee list[], int len)
{
	int i;
	int indice = -1;
	for(i=0;i<len;i++)
	{
		if(list[i].isEmpty==0)
		{
			indice=i;
			break;
		}
	}
	return indice;
}

//--------------GENERA UN ID-------------

/** \brief 	Genera numeros correlativos.
 * return	Retorna el valor del contador que se usa como ID.
 */

int generadorID(void)
{
	static int contador = 0;
	contador++;
	return contador;
}

//--------------CALCULAR PROMEDIO-------------

/** \brief 	Suma el valor de todos los salarios y los divide entre la cantidad de empleados.
 * \param 	Employee list[] es un puntero al array de empleados.
 * \param	int len recibe la longitud del array.
  * return	Retorna el valor float del promedio.
 */

float promedio(Employee pList[], int len)
{
	float promedio;
	int i;
	float acumulador = 0;
	int contador = 0;

	for(i=0;i<len;i++)
	{
		if(pList[i].isEmpty==1)
		{
			acumulador += pList[i].salary;
			contador++;
		}
	}
	promedio = acumulador/contador;
	return promedio;
}

//--------------CALCULAR TOTAL-------------

/** \brief 	Suma todos los salarios.
 * \param 	Employee list[] es un puntero al array de empleados.
 * \param	int len recibe la longitud del array.
  * return	Retorna el valor de la suma.
 */

float total(Employee pList[], int len)
{
	int i;
	float acumulador = 0;

	for(i=0;i<len;i++)
	{
		if(pList[i].isEmpty==1)
		{
			acumulador += pList[i].salary;
		}
	}

	return acumulador;
}

//--------------CALCULA CUANTOS SUPERAN EL PROMEDIO-------------

/** \brief 	Recorre el array y compara los salarios con el promedio.
 * \param 	Employee list[] es un puntero al array de empleados.
 * \param	int len recibe la longitud del array.
 * \param 	float promedio recibe el valor de la funcion que calcula el promedio.
 * return	Retorna por valor el numero de empleados que superan el promedio.
 */

int superanPromedio(Employee pList[], int len, float promedio)
{
	int i;
	Employee buffer[len];
	int contador = 0;
	int retorno = -1;

	initEmployees(buffer, len);

	for(i=0;i<len;i++)
	{

		if(pList[i].salary>promedio && pList[i].isEmpty==1)
		{
			contador++;
			strcpy(buffer[i].name,pList[i].name);
			strcpy(buffer[i].lastName,pList[i].lastName);
			buffer[i].isEmpty=1;
		}

	}
		printf("\nSUPERAN EL PROMEDIO: %d\n", contador);

	for(i=0;i<len;i++)
	{
		if(buffer[i].isEmpty==1)
		{
			printf("\n\t%s %s\n",buffer[i].name,buffer[i].lastName);
		}
	}
	printf("\n");
	return retorno;
}
