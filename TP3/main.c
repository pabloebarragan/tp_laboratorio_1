#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int main()
{
    int option = 0;
    int cargaModoBinario = 0;
    int cargaModoTexto = 0;
    int existenDatos = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();

    printf("\nTRABAJO PRACTICO N3:\n\n");
    printf("MENU:\n");
    printf(" 1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf(" 2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n");
    printf(" 3. Alta de empleado.\n");
    printf(" 4. Modificar datos de empleado.\n");
    printf(" 5. Baja de empleado.\n");
    printf(" 6. Listar empleados.\n");
    printf(" 7. Ordenar empleados.\n");
    printf(" 8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf(" 9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n");
    printf("10. Salir.\n\n");

    do{
        utn_getEntero(&option,2,"\nPor favor, ingrese una opcion del menu: \n","Opcion incorrecta, intente nuevamente \n",1,10);

        switch(option)
        {
            case 1:
                if(cargaModoTexto == 0 && cargaModoBinario == 0)
                {
                    listaEmpleados = ll_newLinkedList();
                    controller_loadFromText("data.csv",listaEmpleados);
                    printf("\nLa carga de datos ha finalizado de forma exitosa.\n");
                    cargaModoTexto = 1;

                }
                else
                {
                    printf("Los datos ya han sido cargados anteriormente.\n");
                }

                break;
             case 2:
                if(cargaModoTexto == 0 && cargaModoBinario == 0)
                {
                    listaEmpleados = ll_newLinkedList();
                    controller_loadFromBinary("data.bin",listaEmpleados);
                    printf("\nLa carga de datos ha finalizado de forma exitosa.\n");
                    cargaModoBinario = 1;
                }else
                {
                    printf("Los datos ya han sido cargados anteriormente.\n");
                    getchar();
                }
                break;

            case 3:
                if(controller_addEmployee(listaEmpleados))
                {
                    printf("Hubo un error al realizar el alta de un empleado. Los datos cargados no son validos.\n");
                }else
                    existenDatos = 1;
                break;

            case 4:
                if(cargaModoBinario == 0 && cargaModoTexto == 0 && existenDatos == 0)
                {
                    printf("No hay empleados cargados en el sistema.\n");
                }else
                if(controller_editEmployee(listaEmpleados) == 0)
                    {
                    printf("La modificacion del empleado se realizo con exito.\n");
                    }
                    else
                    {
                    printf("Hubo un error al realizar la modificacion de un empleado.\n");
                    }
                break;
            case 5:
                if(cargaModoBinario == 0 && cargaModoTexto == 0 && existenDatos == 0)
                {
                    printf("No hay empleados cargados en el sistema.\n");
                }else if(!controller_removeEmployee(listaEmpleados))
                {
                    printf("La baja del empleado se realizo con exito.\n");
                }else
                {
                    printf("Hubo un error al realizar la baja de un empleado.\n");
                }
                break;

            case 6:
                if(cargaModoBinario == 1 || cargaModoTexto == 1 || existenDatos == 1)
                {
                    controller_ListEmployee(listaEmpleados);
                }
                else
                {
                    printf("No hay empleados cargados en el sistema.\n");
                }
                break;

            case 7:
                controller_sortEmployee(listaEmpleados);
                printf("El ordenamiento de empleados ha finalizado correctamente.\n");
                break;

            case 8:
                if(cargaModoBinario == 0 && cargaModoTexto == 0 && existenDatos == 0)
                {
                    printf("No hay empleados cargados en el sistema.\n");
                }else if(controller_saveAsText("data.csv",listaEmpleados) == 0)
                {
                    ll_deleteLinkedList(listaEmpleados);
                    existenDatos = 0;
                    cargaModoTexto = 0;
                    cargaModoBinario = 0;
                }
                else
                {
                    printf("Hubo un error al guardar los datos.\n");
                }
                break;

            case 9:
                if(cargaModoBinario == 0 && cargaModoTexto == 0 && existenDatos == 0)
                {
                    printf("No hay empleados cargados en el sistema.\n");
                }else if(!controller_saveAsBinary("data.bin",listaEmpleados))
                {
                    ll_deleteLinkedList(listaEmpleados);
                    existenDatos = 0;
                    cargaModoTexto = 0;
                    cargaModoBinario = 0;
                }else
                {
                    printf("Hubo un error al guardar los datos.\n");
                }
                break;
        }
    }while(option != 10);
    return 0;
}
