#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "utn.h"
#include "ArrayEmployees.h"

#define EMPLOYEES_LEN       1000
#define SALARY_MAX          99999999
#define SECTOR_MAX          1000

int main()
{
    Employee employees[EMPLOYEES_LEN];
    int opcion;
    int index;
    int id;
    int i;
    char nameAux[51];
    char lastNameAux[51];
    float salaryAux;
    int sectorAux;
    float averageSalary;
    float sumSalary;
    int flagExceedsAverage;

    initEmployees(employees, EMPLOYEES_LEN);

    printf("\nTRABAJO PRACTICO N2: \n\n");

    do
    {
        utn_getEntero(&opcion,1,"1) ALTAS:\n2) MODIFICAR:\n3) BAJA:\n4) INFORMAR:\n5) SALIR:\n","Opcion incorrecta. Por favor, intentelo nuevamente.\n\n",1,5);

        switch(opcion)
        {
            case 1: //ALTAS:
            {
                if (utn_getLetras(nameAux,51,1,"Ingrese el nombre del empleado:", "Error al ingresar el nombre.\n") == 0)
                {
                    if (utn_getLetras(lastNameAux,51,1,"Ingrese el apellido del empleado:", "Error al ingresar el apellido.\n") == 0)
                    {
                        if(utn_getFloat(&salaryAux,1,"Ingrese el salario del empleado:","Error al ingresar el salario del empleado.\n",1, SALARY_MAX) == 0 )
                        {
                            if(utn_getEntero(&sectorAux,1,"Ingrese el sector del empleado:", "Error al ingresar sector.\n",1,SECTOR_MAX) == 0)
                            {
                                if(addEmployee(employees,EMPLOYEES_LEN,getId(),nameAux,lastNameAux,salaryAux,sectorAux) == -1)
                                    printf("Error al realizar el alta de empleado.\n");
                                else
                                    printf("\nAlta de empleado Exitosa.\n\n");
                            }
                        }
                    }
                }
                break;
            }
            case 2: //MODIFICAR:
            {
                if (arrayIsEmpty(employees,EMPLOYEES_LEN)== 1)
                {
                    printf("\nNo se registran empleados. Por favor, ingrese datos para acceder a esta opcion.\n\n");
                    continue;
                }

                if(utn_getEntero(&id,0,"Ingrese el ID del empleado a modificar:\n","Error al ingresar el ID. Valor incorrecto o fuera de rango.\n\n",0,EMPLOYEES_LEN) == 0)
                {
                    index = findEmployeeById(employees, EMPLOYEES_LEN, id);
                    if (index >= 0)
                    {
                        if (utn_getLetras(nameAux,51,1,"Ingrese el nombre del empleado:", "Error al ingresar el nombre.\n") == 0)
                        {
                            if (utn_getLetras(lastNameAux,51,1,"Ingrese el apellido del empleado:", "Error al ingresar el apellido.\n") == 0)
                            {
                                if(utn_getFloat(&salaryAux,1,"Ingrese el salario del empleado:","Error al ingresar el salario del empleado.\n",1,SALARY_MAX) == 0 )
                                {
                                    if(utn_getEntero(&sectorAux,1,"Ingrese el sector del empleado:", "Error al ingresar sector.\n",1,SECTOR_MAX) == 0)
                                    {
                                        if (modifyEmployee(employees, EMPLOYEES_LEN,nameAux, lastNameAux, salaryAux, sectorAux, index) != 0)
                                            printf("Error al realizar la modificacion del empleado\n");
                                        else
                                            printf("\nModificacion del empleado exitosa.\n\n");
                                    }
                                }
                            }
                        }
                    }
                    else
                        printf("El ID ingresado no existe.\n\n");
                }
                break;

            }
            case 3: //BAJA:
            {
                if (arrayIsEmpty(employees,EMPLOYEES_LEN)== 1)
                {
                    printf("\nNo se registran empleados. Por favor, ingrese datos para acceder a esta opcion.\n\n");
                    continue;
                }

                if(utn_getEntero(&id,0,"Ingrese el ID del empleado a eliminar:\n","Error al ingresar el ID. Valor incorrecto o fuera de rango.\n\n",0,EMPLOYEES_LEN)== 0)
                {
                    index = findEmployeeById(employees, EMPLOYEES_LEN, id);
                    if(index>=0)
                    {
                        if(removeEmployee(employees,EMPLOYEES_LEN,index) != 0)
                            printf("Error en baja de empleado\n");
                        else
                            printf("\nBaja de empleado exitosa.\n\n");
                    }
                    else
                        printf("El ID ingresado no existe.\n\n");
                }
                break;
            }
            case 4: //INFORMAR:
            {
                if (arrayIsEmpty(employees,EMPLOYEES_LEN)== 1)
                {
                    printf("\nNo se registran empleados. Por favor, ingrese datos para acceder a esta opcion.\n\n");
                    continue;
                }

                printf("\nLISTADO DE EMPLEADOS:\n");
                printf("\nID -   NOMBRE  -   APELLIDO    -   SALARIO -   SECTOR\n");

                if(sortEmployees(employees, EMPLOYEES_LEN, 1) == -1)
                {
                    printf("\nError en el ordenamiento de los datos.\n");
                }

                if(printEmployees(employees, EMPLOYEES_LEN) == -1)
                {
                    printf("\nNo se registran datos para imprimir.\n");
                }
                averageSalary = getAverageSalary(employees, EMPLOYEES_LEN);
                if(averageSalary == -1)
                {
                     printf("\nNo se registran empleados\n");
                     break;
                }
                sumSalary = 0;
                flagExceedsAverage = 0;
                printf("\nSALARIO PROMEDIO: %.2f \n", averageSalary);
                printf("\nLISTADO DE EMPLEADOS QUE SUPERAN EL SALARIO PROMEDIO:\n");
                printf("\nID -   NOMBRE  -   APELLIDO    -   SALARIO -   SECTOR\n");
                for(i=0; i < EMPLOYEES_LEN; i++)
                {
                    if (employees[i].isEmpty == 0)
                    {
                        sumSalary = sumSalary + employees[i].salary;
                        if(employees[i].salary > averageSalary)
                        {
                            printf("%d  -   %s  -   %s  -   %.2f  -   %d\n", employees[i].id, employees[i].name, employees[i].lastName, employees[i].salary, employees[i].sector);
                            flagExceedsAverage = 1;
                        }
                    }
                }
                if(flagExceedsAverage == 0)
                {
                    printf("\nNo se registran empleados que superen el salario promedio.\n\n");
                }

                printf("\n\nTOTAL DE SALARIOS: %.2f \n\n\n", sumSalary);
                break;
            }
        }
    }while(opcion !=5 );
}
