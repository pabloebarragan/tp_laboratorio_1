#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "save.h"
#include "utn.h"
#include "parser.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    FILE* pArchivo;
    if(path != NULL && pArrayListEmployee != NULL)
    {
        pArchivo = fopen(path,"r");
        if(pArchivo != NULL)
        {
            parser_EmployeeFromText(pArchivo,pArrayListEmployee);
            fclose(pArchivo);
            retorno = 0;
        }else
        {
            printf("Error al intentar abrir el archivo.\n");
        }
    }
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    FILE* pFile;
    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen(path,"rb");
        if(pFile != NULL)
        {
            parser_EmployeeFromBinary(pFile,pArrayListEmployee);
            retorno = 0;
        }else
        {
            printf("Error al intentar abrir el archivo.\n");
        }
    }
    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int bufferHoras;
    int bufferSueldo;
    char bufferNombre[50];
    Employee* empleado;
    if(pArrayListEmployee != NULL &&
       utn_getLetras(bufferNombre,50,3,"\nIngrese el nombre: ","\nError..Intente nuevamente") == 0 &&
       utn_getEntero(&bufferHoras,3,"\nIngrese cantidad de horas: ","\nError..Intente nuevamente",1,9999) == 0 &&
       utn_getEntero(&bufferSueldo,3,"\nIngrese el sueldo: ","\nError..Intente nuevamente",1,9999) == 0)
    {
        empleado = employee_new();
        if(empleado != NULL &&
           employee_setNombre(empleado,bufferNombre) == 0 &&
           employee_setId(empleado,-1) == 0 &&
           employee_setSueldo(empleado,bufferSueldo) == 0 &&
           employee_setHorasTrabajadas(empleado,bufferHoras) == 0)
        {
            ll_add(pArrayListEmployee,empleado);
            retorno = 0;
            }else
            {
                employee_delete(empleado);
                empleado = NULL;
            }
    }
    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int i;
    int len;
    int bufferHoras;
    int bufferSueldo;
    int bufferId;
    int auxId;
    char bufferNombre[50];

    Employee* empleado;
    if(pArrayListEmployee != NULL && utn_getEntero(&auxId,3,"\nIngrese el id del empleado a modificar: ","\nError..Intente nuevamente",0,99999) == 0)
    {
        len=ll_len(pArrayListEmployee);
        for(i=0; i < len; i++)
        {
            empleado = (Employee*)ll_get(pArrayListEmployee,i);
            employee_getId(empleado,&bufferId);
            if(bufferId == auxId && utn_getLetras(bufferNombre,50,3,"\nIngrese el nombre: ","\nError..Intente nuevamente") == 0 &&
               utn_getEntero(&bufferHoras,3,"\nIngrese cantidad de horas: ","\nError..Intente nuevamente",1,9999) == 0 &&
               utn_getEntero(&bufferSueldo,3,"\nIngrese el sueldo: ","\nError..Intente nuevamente",1,9999) == 0 &&
               employee_setNombre(empleado,bufferNombre)  == 0 &&
               employee_setSueldo(empleado,bufferSueldo) == 0 &&
               employee_setHorasTrabajadas(empleado,bufferHoras) == 0)
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int i;
    int len;
    int bufferId;
    int auxId;

    Employee* empleado;

    if(pArrayListEmployee != NULL && utn_getEntero(&auxId,3,"\nIngrese el id del empleado a borrar: ","\nError..Intente nuevamente",0,99999) == 0)
    {
        len = ll_len(pArrayListEmployee);
        for(i=0; i<len; i++)
        {
            empleado = (Employee*)ll_get(pArrayListEmployee,i);
            employee_getId(empleado,&bufferId);
            if(bufferId == auxId)
            {
                ll_remove(pArrayListEmployee,i);
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int i;
    int len;
    int bufferId;
    int bufferSueldo;
    int bufferHoras;
    char bufferNombre[50];

    Employee* bufferEmployee;
    if(pArrayListEmployee != NULL)
    {
        retorno = 0;
        len = ll_len(pArrayListEmployee);
        for(i=0; i < len; i++)
        {
            bufferEmployee = (Employee*)ll_get(pArrayListEmployee,i);
            employee_getNombre(bufferEmployee,bufferNombre);
            employee_getId(bufferEmployee,&bufferId);
            employee_getSueldo(bufferEmployee,&bufferSueldo);
            employee_getHorasTrabajadas(bufferEmployee,&bufferHoras);
            printf("Id: %d, Nombre: %s, Horas: %d, Sueldo: %d\n",bufferId,bufferNombre,bufferHoras,bufferSueldo);
        }
    }
    return retorno;
}

/** \brief Compara dos nombres
 *
 * \param thisA void* puntero a la estructura del primer nombre
 * \param thisB void* puntero a la estructura del segundo nombre
 * \return -1 thisA mayor / 1 thisB mayor / 0 son iguales
 *
 */
int controller_compararByName(void* thisA, void* thisB)
{
    int retorno;
    char bufferNameA[100];
    char bufferNameB[100];
    employee_getNombre(thisA,bufferNameA);
    employee_getNombre(thisB,bufferNameB);
    if(strcmp(bufferNameA,bufferNameB) < 0)
    {
        retorno=-1;
    }else if(strcmp(bufferNameA,bufferNameB)>0)
    {
        retorno = 1;
    }else{
        retorno = 0;
    }
    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    if(pArrayListEmployee != NULL)
    {
        ll_sort(pArrayListEmployee,controller_compararByName,0);
        retorno = 0;
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    FILE*pArchivo;
    if(path != NULL && pArrayListEmployee != NULL)
    {
        pArchivo = fopen(path,"w");
        if(pArchivo != NULL && save_EmployeesAsText(pArchivo,pArrayListEmployee) == 0)
        {
            fclose(pArchivo);
            printf("Los datos se guardaron de forma exitosa.\n");
            getchar();
            retorno = 0;
        }else
        {
            printf("Hubo un error al abrir el archivo.\n");
        }
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    FILE* pArchivo;
    if(path != NULL && pArrayListEmployee != NULL)
    {
        pArchivo = fopen(path,"wb");
        if(pArchivo != NULL && save_EmployeesAsBin(pArchivo,pArrayListEmployee) == 0)
        {
            fclose(pArchivo);
            printf("Los datos se guardaron de forma exitosa.\n");
            getchar();
            retorno = 0;
        }else
        {
            printf("Hubo un error al abrir el archivo.\n");
        }
    }
    return retorno;
}






