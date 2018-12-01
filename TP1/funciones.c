#include <stdio_ext.h>
#include <stdlib.h>

int sumaNumeros(float numeros[], int cantidad, float *resultado)
{
    float sumas;
    cantidad--;
    for(sumas=0; cantidad >= 0; cantidad--)
    {
        sumas += numeros[cantidad];
    }
    *resultado = sumas;
    return 0;
}

int restaDosNumeros(float numeros[], int primerNumero, int segundoNumero, float*resultado)
{
    float resta;
    resta = numeros[primerNumero] - numeros[segundoNumero];
    *resultado = resta;
    return 0;
}

int multiplicaNumeros(float numeros[], int cantidad, float *resultado)
{
    float multiplicacion;
    cantidad--;
    for(multiplicacion = 1; cantidad >= 0; cantidad--)
    {
        multiplicacion*=numeros[cantidad];
    }
    *resultado = multiplicacion;
    return 0;
}

int divideDosNumeros(float numeros[], int dividendo, int divisor, float *resultado)
{
    float division;
    int retorno=0;

    if (numeros[divisor] == 0)
        retorno=-1;
    else
        division = numeros[dividendo]/numeros[divisor];
    *resultado = division;
    return retorno;
}

int verificaNumeroFloat(float *resultado)
{
    float numeroFloat;
    printf("Ingrese un operando;\n");
    while(scanf("%f",&numeroFloat) != 1)
    {
        __fpurge(stdin);
        printf("ERROR, POR FAVOR INGRESE SOLO NUMEROS\n\n");
        printf("Ingrese el operando;\n");
    }
    *resultado = numeroFloat;
    return 0;
}

float factorial(float number)
{
    float i;
    float result = 1;
    if(number >= 0)
    {
        for(i=1;i <= number;i++)
        {
            result = result * i;
        }
    }
    else
    {
        printf ("ERROR. No existe el factorial de un numero negativo.\n");
        result = -1;
    }
    return(result);
}
