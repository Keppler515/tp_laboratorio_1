/*
 * FuncionesVarias.c
 *
 *  Created on: 6 nov. 2021
 *      Author: maxis
 */

#include "utn_biblioteca.h"


void employee_menu(int* opcion)
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


int employee_generadorID(void)
{
	static int contador = 0;
	contador++;
	return contador;
}
