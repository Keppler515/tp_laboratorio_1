/*
 * utn_biblioteca.h
 *
 *  Created on: 7 sep. 2021
 *      Author: maxis
 */

#ifndef UTN_BIBLIOTECA_H_
#define UTN_BIBLIOTECA_H_

void menu();
int suma(int a,int b);
int resta(int a,int b);
int multiplicacion(int a,int b);
int division(int a,int b, float* pDir);
int factorial(int numero);

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError);
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError);
int utn_getCaracter(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos);

int esNumerica(char cadena[]);
int esTexto(char cadena[]);
int esAlfanumerica(char cadena[]);

#endif /* UTN_BIBLIOTECA_H_ */
