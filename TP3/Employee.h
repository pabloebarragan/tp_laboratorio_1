#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;


//1. Constructor:
Employee* employee_new();

//3. Constructor con parametros:
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);

//2. Destructor:
void employee_delete(Employee* this); //PABLO - AGREGO EL PARAMETRO.

// 4.Seters:
int employee_setId(Employee* this,int id);
int employee_setNombre(Employee* this,char* nombre);
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_setSueldo(Employee* this,int sueldo);

// 5.Geters:
int employee_getNombre(Employee* this,char* nombre);
int employee_getId(Employee* this,int* id);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);
int employee_getSueldo(Employee* this,int* sueldo);

int employee_validarParametros(Employee* this);



#endif // employee_H_INCLUDED
