#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Guarda los datos del linkedList en modo texto
 * \param pFile FILE* puntero al archivo destino
 * \param pArrayListEmployee LinkedList* puntero a linkedlist
 * \return 0 todo bien -1 error
 */
int save_EmployeesAsText(FILE* pFile,LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int i = 0;
    int len;
    int bufferId;
    int bufferSueldo;
    int bufferHoras;
    char bufferNombre[50];
    Employee* empleado;
    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        fprintf(pFile,"id,nombre,horasTrabajadas,sueldo\n");
        len = ll_len(pArrayListEmployee);
        do{
            empleado = (Employee*)ll_get(pArrayListEmployee,i);
            employee_getNombre(empleado,bufferNombre);
            employee_getId(empleado,&bufferId);
            employee_getSueldo(empleado,&bufferSueldo);
            employee_getHorasTrabajadas(empleado,&bufferHoras);
            fprintf(pFile,"%d,%s,%d,%d\n",bufferId,bufferNombre,bufferHoras,bufferSueldo);
            i++;
        }while(i < len);
        if(i == len)
        {
            retorno = 0;
        }
    }
return retorno;
}


/** \brief Guarda los datos del linkedList en modo binario
 * \param pFile FILE* puntero al archivo destino
 * \param pArrayListEmployee LinkedList* puntero a linkedlist
 * \return 0 todo bien -1 error
 */
int save_EmployeesAsBin(FILE* pArchivo, LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int i;
    int len = ll_len(pArrayListEmployee);
    Employee* empleado;
    if(pArchivo != NULL && pArrayListEmployee != NULL)
    {
        retorno=0;
        for(i=0; i < len; i++)
        {
            empleado = ll_get(pArrayListEmployee,i);
            if(empleado != NULL)
                fwrite(empleado,sizeof(Employee),1,pArchivo);
        }
        if(i == len)
        {
            retorno = 0;
        }
    }
    return retorno;
}
