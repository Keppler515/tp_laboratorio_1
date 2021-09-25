/*
 * utn_biblioteca.h
 *
 *  Created on: 7 sep. 2021
 *      Author: maxis
 */

#ifndef UTN_BIBLIOTECA_H_
#define UTN_BIBLIOTECA_H_

void menu(float a, float b); //MUESTRA EL MENU POR PANTALLA Y A MEDIDA QUE RECIBE LOS VALORES LOS COLOCA EN SUS LUGARES

float suma(float a,float b); //RECIBE DOS NUMEROS FLOAT Y RETORNA EL RESULTADO COMO FLOAT
float resta(float a,float b); //RECIBE DOS NUMEROS FLOAT Y RETORNA EL RESULTADO COMO FLOAT
float multiplicacion(float a,float b); //RECIBE DOS NUMEROS FLOAT Y RETORNA EL RESULTADO COMO FLOAT
int division(float a,float b, float* pDir); //RECIBE DOS NUMEROS FLOAT Y RETORNA EL ESTADO DE LA DIVISION. -1 SI NO SE PUDO CALCULAR O 0 SI SE PUDO. EN TAL CASO DEVUELVE POR REFERENCIA EL RESULTADO
int factorial(float a, int* pResultado);//RECIBE DOS NUMEROS FLOAT Y, EN CASO DE SER >0 Y TENER DECIMALES ==0 LO CASTEA A INT Y RETORNA EL RESULTADO COMO ENTERO

void imprimir(float s, float r, float m, int estadoD, float d, int estadoFA, int estadoFB, int fA, int fB, float num1, float num2); //IMPRIME EN DIFERENTES RENGLONES LOS RESULTADOS DE LOS CALCULOS

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError); //SOLICITA UN NUMERO ENTERO Y LO ALOJA EN LA VARIABLE INDICADA EN EL PUNTERO
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError); //SOLICITA UN NUMERO FLOTANTE Y LO ALOJA EN LA VARIABLE INDICADA EN EL PUNTERO

#endif /* UTN_BIBLIOTECA_H_ */
