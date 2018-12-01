#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

static int isValidId(int id);
static int isValidNombre(char* nombre);
static int isValidHorasTrabajadas(int horasTrabajadas);
static int isValidSueldo(int sueldo);

//1. Constructor:
Employee* employee_new()
{
    return (Employee*) malloc(sizeof(Employee));
}

//2. Destructor:
void employee_delete(Employee* this)
{
    free(this);
}

//3. Constructor con parametros:
Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* auxiliarEmpleado;
    auxiliarEmpleado = employee_new();
    if (auxiliarEmpleado != NULL && idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL)
    {
        if( employee_setId(auxiliarEmpleado, atoi(idStr))   == -1 ||
            employee_setNombre(auxiliarEmpleado, nombreStr) == -1 ||
            employee_setHorasTrabajadas(auxiliarEmpleado, atoi(horasTrabajadasStr)) == -1 ||
            employee_setSueldo(auxiliarEmpleado, atoi(sueldoStr))  == -1)
        {
            //algo esta mal
            employee_delete(auxiliarEmpleado);
            auxiliarEmpleado = NULL;
        }
    }
    return auxiliarEmpleado;
}


// 4.Seters:
int employee_setId(Employee* this,int id)
{
    int retorno = -1;
    static int proximoId =-1;
    if(this != NULL && isValidId(id) && id ==-1)
    {
        proximoId++;
        this->id = proximoId;
        retorno = 0;
    }
    else
    {
        this->id = id;
        retorno = 0;
    }

    if(id>proximoId)
    {
        proximoId = id;
        retorno = 0;
    }
    return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int retorno = -1;
    if (this != NULL && isValidNombre(nombre))
    {
        strcpy(this->nombre, nombre);
        retorno = 0;
    }
    return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno = -1;
    if (this != NULL && isValidHorasTrabajadas(horasTrabajadas))
    {
        this->horasTrabajadas = horasTrabajadas;
        retorno = 0;
    }
    return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno = -1;
    if (this != NULL && isValidSueldo(sueldo))
    {
        this->sueldo = sueldo;
        retorno = 0;
    }
    return retorno;
}

// 5.Geters:
int employee_getId(Employee* this, int* id)
{
    int retorno = -1;
    if (this != NULL && id != NULL)
    {
        *id = this->id;
        retorno = 0;
    }
    return retorno;
}

int employee_getNombre(Employee* this, char* nombre)
{
    int retorno = -1;
    if (this != NULL && nombre != NULL)
    {
        strcpy(nombre,this->nombre);
        retorno = 0;
    }
    return retorno;
}

int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas)
{
    int retorno = -1;
    if (this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        retorno = 0;
    }
    return retorno;
}


int employee_getSueldo(Employee* this, int* sueldo)
{
    int retorno = -1;
    if (this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        retorno = 0;
    }
    return retorno;
}


// 6.IsValid:
static int isValidId(int id)
{
    return 1;
}

static int isValidNombre(char* nombre)
{
    return 1;
}

static int isValidHorasTrabajadas(int horasTrabajadas)
{
    return 1;
}

static int isValidSueldo(int sueldo)
{
    return 1;
}

int employee_validarParametros(Employee* this)
{
    int retorno = -1;
    if( isValidId(this->id) == 0 &&
        isValidNombre(this->nombre) == 0 &&
        isValidHorasTrabajadas(this->horasTrabajadas) == 0 &&
        isValidSueldo(this->sueldo) == 0)
        {
            retorno = 0;
        }
    return retorno;
}

