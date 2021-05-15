#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef TP2_H_
#define TP2_H_
#define VACIO 1
#define OCUPADO 0
#define T 5

typedef struct
{
	int id;
	char nombre[51];
	char apellido[51];
	float salario;
	int sector;
	int isEmpty;

}eEmpleado;

/**
 * @fn estructura de empleados
 * @brief muestra una estructura de los datos del empleado
 *
 * @param int id
 * @param char nombre
 * @param char apellido
 * @param float salario
 * @param int sector
 * @param int isempty
 * @return eEmpleado
 */

int mostrarEmpleados(eEmpleado listaDeEmpleados[], int tam, int identificador);
/**
 * @fn mostrar empleados
 * @brief muestra una lista con los empleados
 *
 * @param el array de lista de empleados
 * @param  el tamaño del array de empelados
 * @param el identificador de los empleados
 * @return 1 si mostro la lista y 0 si hubo error
 */

int cargarEmpleado(eEmpleado listaDeEmpleados[], int tam, int* id);
/**
 * @fn cargar empleados
 * @brief muestra una lista con los empleados que se cargaron
 *
 * @param el array de lista de empleados
 * @param  el tamaño del array de empelados
 * @param el identificador de los empleados
 * @return 0 si mostro la carga de empleados y -1 si hubo error
 */

int OrdenarEmpleadosPorSectorApellido(eEmpleado listaDeEmpleados[], int tam);
/**
 * @fn mostrar empleados
 * @brief muestra una lista con los empleados
 *
 * @param el array de lista de empleados
 * @param  el tamaño del array de empelados
 * @param el identificador de los empleados
 * @return 1 si mostro la lista y 0 si hubo error
 */


int inicializarEmpleados(eEmpleado listaDeEmpleados[], int tam);
/**
 * @fn mostrar empleados
 * @brief muestra una lista con los empleados
 *
 * @param el array de lista de empleados
 * @param  el tamaño del array de empelados
 * @param el identificador de los empleados
 * @return 1 si mostro la lista y 0 si hubo error
 */

int BuscarLibre(eEmpleado listaDeEmpleados[], int tam);
/**
 * @fn buscar libre
 * @brief busca si hay espacios libres para ingresar mas empleados
 *
 * @param el array de lista de empleados
 * @param  el tamaño del array de empelados
 * @param el identificador de los empleados
 * @return 1 si encuentra libres y 0 si hubo error
 */

int bajaEmpleado(eEmpleado listaDeEmpleados[], int tam, int guardarId);
/**
 * @fn baja empleado
 * @brief da de baja al id seleccionado del empleado
 *
 * @param el array de lista de empleados
 * @param  el tamaño del array de empelados
 * @param el que guarda el ID de los empleados
 * @return 1 si hace la baja al empleado y 0 si hubo error
 */

int modificarEmpleado(eEmpleado listaDeEmpleados[], int tam, int identificador);
/**
 * @fn modificar empleado
 * @brief hace una modificacion al id del empleado seleccionado
 *
 * @param el array de lista de empleados
 * @param  el tamaño del array de empelados
 * @param el identificador de los empleados
 * @return -1 si pudo modificar al empleado y 0 si hubo error
 */

int buscarEmpleado(eEmpleado listaDeEmpleados[], int tam, int identificador);
/**
 * @fn buscar empleado
 * @brief busca al empleado
 *
 * @param el array de lista de empleados
 * @param  el tamaño del array de empelados
 * @param el identificador de los empleados
 * @return -1 si pudo buscar el empleado y 0 si hubo error
 */

#endif /* TP2_H_ */
