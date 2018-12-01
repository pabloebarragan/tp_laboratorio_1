#include <stdio_ext.h>
#include <stdlib.h>
#include "biblotecaFunciones.h"


int main()
{
    float numeros[2];
    float suma;
    float resta;
    float multiplicacion;
    float division;
    float factorialNumA;
    float factorialNumB;
    int opcion;
    int realizarCalculos = 0;
    numeros[0] = 0;
    numeros[1] = 0;

    //Menu:
    printf("TRABAJO PRACTICO N3: - CALCULADORA\n\n");
    printf("MENU:\n");
    printf("1. Ingresar 1er operando (A=%.2f)\n",numeros[0]);
    printf("2. Ingresar 2do operando (B=%.2f)\n",numeros[1]);
    printf("3. Calcular todas las operaciones siguentes:\n");
    printf("    a) Calcular la suma\n");
    printf("    b) Calcular la resta (A-B)\n");
    printf("    c) Calcular la division (A/B)\n");
    printf("    d) Calcular la multiplicacion (A*B)\n");
    printf("    e) Calcular el factorial (A!)\n");
    printf("4. Informar los resultados\n");
    printf("5. Salir\n");

    do{
        printf("Ingrese una opcion del menu:\n");

        if (scanf("%d",&opcion) !=1 || (opcion < 1 || opcion > 5))
        {
            __fpurge(stdin);
            printf("El valor ingresado es invalido, por favor ingrese un numero entre 1 y 5.\n\n");
        }

        switch (opcion)
        {
            case 1:
                verificaNumeroFloat(&numeros[0]);
                break;

            case 2:
                verificaNumeroFloat(&numeros[1]);
                break;

            case 3:
                realizarCalculos = 1;
                sumaNumeros(numeros,2,&suma);
                restaDosNumeros(numeros,0,1,&resta);
                multiplicaNumeros(numeros,2,&multiplicacion);
                divideDosNumeros(numeros,0,1,&division);
                factorialNumA = factorial(numeros[0]);
                factorialNumB = factorial(numeros[1]);
                printf("Todas las operaciones ya fueron realizadas. Para ver su resultado, seleccionar la opcion 4.\n\n");
                break;

            case 4:
                if(realizarCalculos == 0)
                {
                    printf("Faltan realizar calculos. Una vez cargados los numeros A y B, seleccionar la opcion 3.\n");
                    break;
                }

                printf("A= %.2f    B= %.2f\n\n",numeros[0],numeros[1]);
                printf("La suma de los operandos es A+B: %.2f \n",suma);
                printf("La resta de los operandos es A-B: %.2f \n",resta);
                printf("La multiplicacion de los operandos es A*B: %.2f \n",multiplicacion);
                if (divideDosNumeros(numeros,0,1,&division) == -1)
                    printf("No se puede dividir por cero \n");
                else
                    printf("La division de los operandos es A/B: %.2f\n",division);
                printf("El factorial del primer operando es: %.0f \n",factorialNumA);
                printf("El factorial del segundo operando es: %.0f \n",factorialNumB);
                break;
        }
    } while(opcion != 5);
    return 0;
}
