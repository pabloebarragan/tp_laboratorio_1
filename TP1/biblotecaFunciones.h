/**suma x cantidad de numeros float.
parametros (array,cantidad de numeros en el array,direccion de variable donde guardar resultado)
*/
int sumaNumeros(float numeros[],int cantidad,float *resultado);


/** Resta dos numeros:
parametros (array,subindice del primer numero,subindice del segundo numero,puntero a guardar el resultado)
*/
int restaDosNumeros(float numeros[],int primerNumero,int segundoNumero,float *resultado);


/** multiplica numeros:
parametros (array,cantidad de subindices a multiplicar "desde el numero indicado hacia adelante",puntero a guardar el resultado)
*/
int multiplicaNumeros(float numeros[],int cantidad,float *resultado);


/** divide dos numeros:
parametros (array,subindices del dividendo,subindice del divisor,puntero a guardar el resultado)
return :retorna -1 si el divisor es 0 "no se puede dividir x 0"
*/
int divideDosNumeros(float numeros[],int dividendo,int divisor,float *resultado);


/** calcula factorial:
Retorna el factorial del numero pasado como parametro.
*/
float factorial(float number);

/** Verificador de numero float:
pide al usuario el ingreso de un numero, de no ser asi muestra un error y se vuelve a pedir el ingreso.
la funcion termina solo cuando ingrese un numero y lo devuelve
parametros (puntero a guardar el numero obtenido)
*/
int verificaNumeroFloat(float *resultado);
