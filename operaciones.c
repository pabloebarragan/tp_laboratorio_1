#include <stdio.h>
#include <stdlib.h>
#include "operaciones.h"

float operaciones_getSuma(float operando1, float operando2)
{
    float resultado;
    resultado = operando1 + operando2;
    return resultado;
}

float operaciones_getResta(float operando1, float operando2)
{
    float resultado;
    resultado = operando1 - operando2;
    return resultado;
}

float operaciones_getDivision(float operando1, float operando2)
{
    float resultado;
    resultado = operando1 / operando2;
    return resultado;
}

float operaciones_getMultiplicacion(float operando1, float operando2)
{
    float resultado;
    resultado = operando1 * operando2;
    return resultado;
}

int operaciones_getFactorial(int operando)
{
    return 0;
}
