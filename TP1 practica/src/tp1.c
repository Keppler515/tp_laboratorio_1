/*
 * tp1.c
 *
 *  Created on: 8 sep. 2021
 *      Author: maxis
 */



int sumar(int a, int b)
{
	int total;
	total = a+b;
	return total;
}

int restar(int a, int b)
{
	int total;
	total = a-b;
	return total;
}

int multiplicar(int a, int b)
{
	int total;
	total = a*b;
	return total;
}

float dividir(int a, int b, float* pDir)
{
	int estado;
	float total;

	if(b!=0)
	{
		estado = 0;
		total = (float)a/b;
	}
	else
	{
		estado = -1;
	}

	*pDir = total;
	return estado;
}
