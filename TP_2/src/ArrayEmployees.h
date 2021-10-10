/*
 * ArrayEmployees.h
 *
 *  Created on: 30 sep. 2021
 *      Author: maxis
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn_biblioteca.h"

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

#define CANTIDAD_EMP	1000

typedef struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;
}Employee;


int initEmployees(Employee list[], int len);
int addEmployee(Employee list[], int len, int id, char name[],char lastName[],float salary,int sector);
int removeEmployee(Employee list[], int len, int id);
int modifyEmployee(Employee list[], int len, int id);
int printEmployees(Employee list[], int len);
int findEmployeeById(Employee list[], int len, int id);
int sortEmployees(Employee pList[], int len, int order);
int buscarLibre(Employee list[], int len);
int generadorID(void);
float promedio(Employee pList[], int len);
float total(Employee pList[], int len);
int superanPromedio(Employee pList[], int len, float promedio);


#endif /* ARRAYEMPLOYEES_H_ */
