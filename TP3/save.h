#ifndef SAVE_H_INCLUDED
#define SAVE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

int save_EmployeesAsText(FILE* pFile,LinkedList* pArrayListEmployee);
int save_EmployeesAsBin(FILE* pArchivo,LinkedList* pArrayListEmployee);

#endif // SAFE_H_INCLUDED
