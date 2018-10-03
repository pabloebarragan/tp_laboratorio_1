#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "utn.h"
#include "ArrayEmployees.h"

int getId(void)
{
    static int id = -1;
    id++;
    return id;
}

int initEmployees(Employee* list, int len)
{
    int retorno = -1;
    int i;
    if(list != NULL && len > 0)
    {
        for(i=0; i<len; i++)
        {
            list[i].isEmpty = 1;
            retorno = 0;
        }
    }
    return retorno;
}


int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
    int emptyPosition;
    int retorno = -1;
    if(list != NULL && len > 0)
    {
        emptyPosition = findEmptyPosition(list,len);
        if(emptyPosition >= 0)
        {
            //ENCONTRE UN LUGAR:
            strncpy(list[emptyPosition].name, name, 51);
            strncpy(list[emptyPosition].lastName, lastName, 51);
            list[emptyPosition].id = id;
            list[emptyPosition].salary = salary;
            list[emptyPosition].sector = sector;
            list[emptyPosition].isEmpty = 0;
            retorno = 0;
        }
    }
    return retorno;
}


int modifyEmployee(Employee* list, int len, char name[],char lastName[],float salary,int sector, int index)
{
    int retorno = -1;
    if(list != NULL && len > 0)
    {
        //MODIFICO LOS DATOS DEL EMPLEADO:
        strncpy(list[index].name, name, 51);
        strncpy(list[index].lastName, lastName, 51);
        list[index].salary = salary;
        list[index].sector = sector;
        retorno = 0;
    }
    return retorno;
}



int findEmployeeById(Employee* list, int len,int id)
{
    int i;
    int retorno = -1;
    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty == 0)
        {
            //evaluo el ID
            if(list[i].id == id)
            {
                //lo encontre:
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}



int removeEmployee(Employee* list, int len, int id)
{
    int retorno = -1;
    if(list != NULL && len > 0)
    {
        list[id].isEmpty = 1;
        retorno = 0;
    }
    return retorno;
}



int sortEmployees(Employee* list, int len, int order)
{

    Employee employeeAux;
    int i,j;
    int retorno = -1;
    if(list != NULL && len > 0)
    {
        for(i=0; i < len - 1; i++)
        {
            if(list[i].isEmpty == 1)
            {
                continue;
            }
            for(j=i+1; j < len; j++)
            {
                if(list[i].isEmpty == 1)
                {
                    continue;
                }
                if (order == 0)
                {
                    if(strcmp(list[j].lastName,list[i].lastName) > 0)
                    {
                        employeeAux = list[j];
                        list[j] = list[i];
                        list[i] = employeeAux;
                    }
                    else if(strcmp(list[j].lastName,list[i].lastName) == 0)
                    {
                        if(list[i].sector < list[j].sector)
                        {
                            employeeAux = list[j];
                            list[j] = list[i];
                            list[i] = employeeAux;
                        }
                    }
                }
                else
                {
                    if(strcmp(list[j].lastName,list[i].lastName) < 0)
                    {
                        employeeAux = list[j];
                        list[j] = list[i];
                        list[i] = employeeAux;
                    }
                    else if(strcmp(list[j].lastName,list[i].lastName) == 0)
                    {
                        if(list[i].sector > list[j].sector)
                        {
                            employeeAux = list[j];
                            list[j] = list[i];
                            list[i] = employeeAux;
                        }
                    }
                }
            }
        }
        retorno = 0;
    }
    return retorno;
}


int printEmployees(Employee* list, int len)
{
    int i;
    int retorno = -1;
    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty == 0)
        {
            printf("%d  -   %s  -   %s  -   %.2f  -   %d\n", list[i].id, list[i].name, list[i].lastName, list[i].salary, list[i].sector);
            retorno = 0;
        }
    }
    return retorno;
}


int findEmptyPosition(Employee* list, int len)
{
    int retorno = -1;
    int i;
    if(list != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            if(list[i].isEmpty == 1)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}


float getAverageSalary(Employee* list, int len)
{
    int i;
    float totalSalary = 0;
    int SumEmployees = 0;
    for(i=0;i < len; i++)
    {
        if(list[i].isEmpty == 0)
        {
            totalSalary = totalSalary + list[i].salary;
            SumEmployees++;
        }
    }
    if(SumEmployees == 0)
        return -1;

    return (totalSalary / (float)SumEmployees);
}



int arrayIsEmpty(Employee* list, int len)
{
    int i;
    int retorno = 1;
    if(list != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            if(list[i].isEmpty == 0)
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

/*
void addEmployee_forzada(Employee* list, int len, char name[],char lastName[],float salary,int sector)
{
    int index = findEmptyPosition(list, len);
    if(index >=0)
    {
        strncpy(list[index].name, name, 51);
        strncpy(list[index].lastName, lastName, 51);
        list[index].id = getId();
        list[index].salary = salary;
        list[index].sector = sector;
        list[index].isEmpty = 0;
    }
} */








