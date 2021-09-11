/*
 * utn_biblioteca.h
 *
 *  Created on: 7 sep. 2021
 *      Author: maxis
 */

#ifndef UTN_BIBLIOTECA_H_
#define UTN_BIBLIOTECA_H_

int suma(int a,int b);
int resta(int a, int b);
int multiplicacion(int a, int b);
float division(int a, int b, float* pDir);

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
int utn_getNumeroFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos);
int utn_getCaracter(char* pResultado, char* mensaje, char* mensajeError, char minimo, char maximo, int reintentos);

#endif /* UTN_BIBLIOTECA_H_ */
