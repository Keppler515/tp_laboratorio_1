#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{

	Employee* eAux;
	char idAux[32];
	char nombreAux[128];
	char horasAux[32];
	char sueldoAux[32];

	if(pFile!=NULL)
	{
  		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idAux,nombreAux,horasAux,sueldoAux); //SALTEO LA PRIMER LINEA
		do
		{
			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idAux,nombreAux,horasAux,sueldoAux)==4)
			{
				eAux = employee_newParametros(idAux, nombreAux, horasAux, sueldoAux);
				if(eAux!=NULL)

				ll_add(pArrayListEmployee, eAux);
			}
			else
			{
				//employee_delete(eAux);
				break;
			}
		}while(feof(pFile)==0);
	}


    return 1;
}

/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

	Employee* eAux;

	if(pFile!=NULL)
	{
		do
		{
			eAux = employee_new();
			if(fread(eAux,sizeof(Employee),1,pFile)==1)
			{
				ll_add(pArrayListEmployee, eAux);
			}
			else
			{
				employee_delete(eAux);
				break;
			}
		}while(feof(pFile)==0);
	}


    return 1;
}


