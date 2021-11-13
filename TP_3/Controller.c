#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "utn_biblioteca.h"
#include "Employee.h"
#include "parser.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	FILE* pArch;

	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		if((pArch = fopen(path,"r"))!=NULL)
		{
			if(parser_EmployeeFromText(pArch, pArrayListEmployee)==0)
			{
				fclose(pArch);
				retorno = 0;
			}
		}
		else
		{
			puts("El archivo no puede ser cargado o no existe\n");
		}
	}

    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	FILE* pArch;

	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		if((pArch = fopen(path,"rb"))!=NULL)
		{
			if(parser_EmployeeFromBinary(pArch, pArrayListEmployee)==0)
			{
				fclose(pArch);
				retorno = 0;
			}
		}
		else
		{
			puts("El archivo no puede ser cargado o no existe\n");
		}
	}
    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	char nombreAux[128];
	int horasAux;
	int salarioAux;
	int idAux;
	int retorno = -1;

	if(pArrayListEmployee!=NULL)
	{
		Employee* thisAux = employee_new();

		if(	utn_getText(nombreAux, 128, "Nombre: ", "Mal")==0 &&
			utn_getNumero(&horasAux, "Horas trabajadas: ", "Err Horas")==0 &&
			utn_getNumero(&salarioAux, "Salario: ", "Err Salario")==0)
		{
			idAux = employee_generadorID()+1000;

			employee_setNombre(thisAux, nombreAux);
			employee_setHorasTrabajadas(thisAux, horasAux);
			employee_setSueldo(thisAux, salarioAux);
			employee_setId(thisAux, idAux);

			ll_add(pArrayListEmployee, thisAux);

			retorno = 0;
		}
	}

    return retorno;


}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int i;
	int idAux;
	int idAuxBuscado;
	int opcionAux;
	char nombreAux[128];
	int horasAux;
	int sueldoAux;
	int retorno = -1;
	int flagExiste = 0;
	Employee* aux;

	if(pArrayListEmployee!=NULL)
	{
		if(utn_getNumero(&idAuxBuscado, "ID a editar: ", "Err. edit")==0)
		{
			for(i=0;i<ll_len(pArrayListEmployee);i++)
			{
				aux = ll_get(pArrayListEmployee, i);

				employee_getId(aux, &idAux);

				if(idAux == idAuxBuscado)
				{
					flagExiste = 1;

					employee_getId(aux, &idAux);
					employee_getNombre(aux, nombreAux);
					employee_getHorasTrabajadas(aux, &horasAux);
					employee_getSueldo(aux, &sueldoAux);

					printf(	"\nNombre: %s\n"
							"Horas: %d\n"
							"Sueldo: %d\n",nombreAux,horasAux,sueldoAux);
					break;
				}
			}
		}

		if(flagExiste==1)
		{
			if(utn_getNumero(&opcionAux,"\nDato a modificar:\n"
										"1) Nombre\n"
										"2) Horas\n"
										"3) Sueldo\n", "Err. edit2")==0)
			{

				switch(opcionAux)
				{
					case 1:
						if(	utn_getText(nombreAux, 128, "\nNuevo nombre: ", "Mal")==0)
						{
							employee_setNombre(aux, nombreAux);
							retorno = 0;
						}
						break;

					case 2:
						if(utn_getNumero(&horasAux, "Cantidad de horas: ", "Maaal")==0)
						{
							employee_setHorasTrabajadas(aux, horasAux);
							retorno = 0;
						}
						break;

					case 3:
						if(utn_getNumero(&sueldoAux, "Nuevo Sueldo: ", "Moool")==0)
						{
							employee_setSueldo(aux, sueldoAux);
							retorno = 0;
						}
						break;
				}
			}
		}
		else
			puts("\nID inexistente o eliminado\n");

}
    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int i;
	int idAux;
	int idAuxBuscado;
	int indexAux;
	int opcionAux;
	char nombreAux[128];
	int horasAux;
	int sueldoAux;
	int retorno = -1;
	int flagExiste = 0;
	Employee* aux;

	if(pArrayListEmployee!=NULL)
	{
		if(utn_getNumero(&idAuxBuscado, "ID a eliminar: ", "Err")==0)
		{
			for(i=0;i<ll_len(pArrayListEmployee);i++)
			{
				aux = ll_get(pArrayListEmployee, i);

				employee_getId(aux, &idAux);

				if(idAuxBuscado == idAux)
				{
					indexAux = i;
					flagExiste = 1;
					employee_getNombre(aux, nombreAux);
					employee_getHorasTrabajadas(aux, &horasAux);
					employee_getSueldo(aux, &sueldoAux);

					printf(	"\nID: %d\n"
							"Nombre: %s\n"
							"Horas: %d\n"
							"Sueldo: %d\n",idAux,nombreAux,horasAux,sueldoAux);
					break;
				}
			}

			if(flagExiste==1)
			{
				do
				{
					if(utn_getNumero(&opcionAux,"\n¿Eliminar?\n"
												"1) Confirma\n"
												"2) Cancela\n", "Err. remove2")==0)
					{
						switch(opcionAux)
						{
						case 1:
							employee_delete(aux);
							ll_remove(pArrayListEmployee, indexAux);
							retorno = 0;
							break;

						case 2:
							puts("Cancelado\n");
							break;
						}
					}
					break;
				}while(opcionAux!=1||opcionAux!=2);
			}
			else
				puts("\nID inexistente o eliminado\n");
		}
	}

	return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int i;
	int idAux;
	char nombreAux[256];
	int horasAux;
	int sueldoAux;
	Employee* aux;

	if(pArrayListEmployee!=NULL)
	{
		printf("ID Nombre Horas Sueldo\n");
		for(i=0;i<ll_len(pArrayListEmployee);i++)
		{
			aux = ll_get(pArrayListEmployee, i);

			employee_getId(aux, &idAux);
			employee_getNombre(aux, nombreAux);
			employee_getHorasTrabajadas(aux, &horasAux);
			employee_getSueldo(aux, &sueldoAux);

			printf("%d,%s,%d,%d\n",idAux,nombreAux,horasAux,sueldoAux);
		}
		printf("\n");
		retorno = 0;
	}
    return retorno;
}


/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int opcion;

	if(pArrayListEmployee!=NULL)
	{
		do
		{
			if(utn_getNumero(&opcion, "1- Alfabeticamente.\n2- ID.\n", "Err.")==0 && opcion>=1 && opcion<3)
			{
				switch(opcion)
				{
					case 1:
					{
						//NOTA: OPCION DESC TARDA MUUUUCHO. NO SE SI FUNCIONA
						puts("\nOrdenando...\n");
						ll_sort(pArrayListEmployee, employee_comparaEmpleados, 1);
						puts("Lista ordenada\n");
						retorno = 0;
						break;
					}
					break;

					case 2:
					{
						puts("\nOrdenando...\n");
						ll_sort(pArrayListEmployee, employee_comparaEmpleadosID, 1);
						puts("Lista ordenada\n");
						retorno = 0;
						break;
					}
					break;
				}
				break;
			}
			else
			{
				puts("Opcion invalida\n");
			}
		}while(opcion!=0 || opcion!=1);
	}

    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int i;
	int idAux;
	char nombreAux[256];
	int horasAux;
	int sueldoAux;
	Employee* aux;
	FILE* pArch = fopen(path,"w");

	if(path!=NULL && pArch!=NULL)
	{

		fprintf(pArch,"ID Nombre Horas Sueldo\n");

		for(i=0;i<ll_len(pArrayListEmployee);i++)
		{
			aux = ll_get(pArrayListEmployee, i);

			employee_getId(aux, &idAux);
			employee_getNombre(aux, nombreAux);
			employee_getHorasTrabajadas(aux, &horasAux);
			employee_getSueldo(aux, &sueldoAux);

			fprintf(pArch,"%d,%s,%d,%d\n",idAux,nombreAux,horasAux,sueldoAux);
		}

		fclose(pArch);
		retorno = 0;
	}

    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int i;
	Employee* aux;
	FILE* pArch = fopen(path,"wb");

	if(path!=NULL && pArch!=NULL)
	{
		for(i=0;i<ll_len(pArrayListEmployee);i++)
		{
			aux = ll_get(pArrayListEmployee, i);

			fwrite(&aux,sizeof(Employee),1,pArch);
		}

		fclose(pArch);
		retorno = 0;
	}

	return retorno;
}


void controller_menu(int* opcion)
{
	utn_getNumero(opcion, 	"1) Cargar los datos de los empleados desde el archivo data.csv(modo texto)\n"
							"2) Cargar los datos de los empleados desde el archivo data.csv(modo binario)\n"
							"3) Alta de empleado\n"
							"4) Modificar datos de empleado\n"
							"5) Baja de empleado\n"
							"6) Listar empleados\n"
							"7) Ordenar empleados\n"
							"8) Guardar los datos de los empleados desde el archivo data.csv(modo texto)\n"
							"9) Guardar los datos de los empleados desde el archivo data.csv(modo binario)\n"
							"10)Salir\n", "ERROR");

}


