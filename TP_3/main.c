#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "FuncionesVarias.h"
#include "parser.h"
#include "utn_biblioteca.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout,NULL);

    int option;
    int flagBin = 0;
    int flagText = 0;
    int flagManual = 0;


    LinkedList* listaEmpleados = ll_newLinkedList();
    do{

    	employee_menu(&option);
    	printf("\n");

        switch(option)
        {
            case 1:
				if(flagBin==0)
                {
					if(controller_loadFromText("data.csv",listaEmpleados)==0)
                	{
						flagText = 1;
						puts("Archivo cargado en modo texto\n");
                	}
                }
				else
					puts("Ya se encuentra cargado el archivo en modo binario\n");
                break;
            case 2:
				if(flagText==0)
            	{
					if(controller_loadFromBinary("data.csv",listaEmpleados)==0)
            		{
						flagBin = 1;
						puts("Archivo cargado en modo binario\n");
            		}
            	}
				else
					puts("Ya se encuentra cargado el archivo en modo texto\n");
            	break;
            case 3:
            	if(controller_addEmployee(listaEmpleados)==0)
            	{
            		flagManual = 1;
            		puts("Empleado agregado correctamente\n");
            	}
				break;
			case 4:
				if(flagText||flagBin||flagManual)
				{
					if(controller_editEmployee(listaEmpleados)==0)
					{
						puts("Datos modificados correctamente\n");
					}
				}
				else
					puts("No hay datos para modificar\n");
				break;
			case 5:
				if(flagText||flagBin||flagManual)
				{
					if(controller_removeEmployee(listaEmpleados)==0)
					{
						puts("Datos eliminados correctamente\n");
					}
				}
				else
					puts("No hay datos para eliminar\n");
				break;
			case 6:
				if(flagText||flagBin||flagManual)
				{
					controller_ListEmployee(listaEmpleados);
				}
				else
					puts("No hay datos para mostrar\n");
				break;
			case 7:
				if(flagText||flagBin||flagManual)
				{
					controller_sortEmployee(listaEmpleados);
				}
				else
					puts("No hay datos para ordenar\n");
				break;
			case 8:
				if(flagText||flagBin||flagManual)
				{
					if(controller_saveAsText("dataText.txt",listaEmpleados)==0)
					{
						puts("Datos guardados correctamente en modo texto\n");
					}
				}
				else
					puts("No hay datos para guardar\n");
				break;
			case 9:
				if(flagText||flagBin||flagManual)
				{
					if(controller_saveAsBinary("dataBin.bin",listaEmpleados)==0)
					{
						puts("Datos guardados correctamente en modo binario\n");
					}
				}
				else
					puts("No hay datos para guardar\n");
				break;
			default:
				puts("Terminado");
				ll_deleteLinkedList(listaEmpleados);
				break;
        }
    }while(option != 10);




    return 0;

}



