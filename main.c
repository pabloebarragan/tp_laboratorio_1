#include <stdio.h>
#include <stdlib.h>
#include "operaciones.h"

void mostrarMenu(void);

int main()
{
    int opcionDeMenu;
    float operando1;
    float operando2;
    float resultadoSuma;
    float resultadoResta;
    float resultadoDivision;
    float resultadoMultiplicacion;
    int resultadoFactorial1;
    int resultadoFactorial2;

    do{
        //system("cls");
        mostrarMenu();
        scanf("%d",&opcionDeMenu);
        switch(opcionDeMenu)
        {
            case 1:
                printf("Ingresar el valor del primer operando\n");
                scanf("%f",&operando1);
                break;
            case 2:
                printf("Ingresar el valor del segundo operando\n");
                scanf("%f",&operando2);
                break;
            case 3:
                resultadoSuma = operaciones_getSuma(operando1,operando2);
                resultadoResta = operaciones_getResta(operando1,operando2);
                resultadoDivision = operaciones_getDivision(operando1,operando2);
                resultadoMultiplicacion = operaciones_getMultiplicacion(operando1,operando2);
                resultadoFactorial1 = operaciones_getFactorial(operando1);
                resultadoFactorial2 = operaciones_getFactorial(operando2);
                break;
            case 4:
                printf("RESULTADOS OBTENIDOS: \n");
                printf("--------------------- \n\n");
                printf("El resultado de %f + %f es: %f \n", operando1,operando2,resultadoSuma);
                printf("El resultado de %f - %f es: %f \n", operando1,operando2,resultadoResta);
                printf("El resultado de %f / %f es: %f \n", operando1,operando2,resultadoDivision);
                printf("El resultado de %f * %f es: %f \n", operando1,operando2,resultadoMultiplicacion);
                printf("El factorial de %f es: %d y el factorial de %f es: %d \n", operando1,resultadoFactorial1,operando1,resultadoFactorial2);
                break;
            case 5:
                break;
            default:
                printf("Ha ingresado un numero no valido\n");
                break;
        }
    }while(opcionDeMenu != 5);
}

//MOSTRARMENU:
void mostrarMenu(void)
{
    printf("CALCULADORA: \n");
    printf("Por favor, ingresar una opcion de menu para continuar: \n\n");
    printf("1. Ingresar 1er operando \n");
    printf("2. Ingresar 2do operando \n");
    printf("3. Calcular todas las operaciones \n");
    printf("4. Informar resultados \n");
    printf("5. Salir \n");
}
