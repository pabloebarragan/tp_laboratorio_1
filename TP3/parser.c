#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int flagPrimeraLinea = 0;
    char bufferId[256];
    char bufferNombre[256];
    char bufferHorasTrabajadas[256];
    char bufferSueldo[256];
    Employee* employee;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        retorno = 0;
        do
        {
            if(flagPrimeraLinea == 0)
            {
                fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",bufferId,bufferNombre,bufferHorasTrabajadas,bufferSueldo);
                flagPrimeraLinea = 1;
            }
            fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n", bufferId,bufferNombre,bufferHorasTrabajadas,bufferSueldo);
            employee = employee_newParametros(bufferId, bufferNombre, bufferHorasTrabajadas, bufferSueldo);
            if(employee != NULL)
            {
                ll_add(pArrayListEmployee,employee);
            }
            else
            {
                employee_delete(employee);
                printf("Error en la carga: %s,%s,%s,%s\n", bufferId,bufferNombre,bufferHorasTrabajadas,bufferSueldo);
                getchar();
            }
        } while (!feof(pFile));
    }
    return retorno ;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    Employee* employee;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        retorno = 0;
        do
        {
            employee = employee_new();
            fread(employee, sizeof(Employee),1,pFile);

            if(employee_validarParametros(employee) == 0)
                ll_add(pArrayListEmployee,employee);
            else
                employee_delete(employee);
        } while (!feof(pFile));
    }
    return retorno;
}









