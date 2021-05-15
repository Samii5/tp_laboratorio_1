/*
 ============================================================================
 Name        : Samantha.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tp2.h"

int main(void)
{
setbuf(stdout,NULL);
fflush(stdin);

char seguir = 's';
int retorno;
int opcion;
eEmpleado listaDeEmpleados[T];
int identificador = 1;
int guardarId;

int bandera1 = 0;
//int bandera2 = 0;



inicializarEmpleados(listaDeEmpleados, T);

	while(seguir=='s')
	{
		printf(
	    "\n 1.ALTA empleado"
	    "\n 2.BAJA empleado"
	    "\n 3.MODIFICAR empleado"
	    "\n 4.MOSTRAR empleados ordenados por apellido y sector"
	    "\n 5.SALIR");
		printf("\n Elija una opcion: ");
		scanf("%d", &opcion);

		switch(opcion)
		{
			case 1:
				retorno = cargarEmpleado(listaDeEmpleados, T, &identificador);
				if(retorno !=1)
				{
					printf("Empleado ingresado con exito!!!\n");
				}
				else
				{
					printf("No hay mas lugar en la lista!!\n");
				}
				bandera1=1;
			break;

			case 2:
				if (bandera1==0)
				{
					printf("\n error,no ingresaste empleados");
				}
				else
				{
					mostrarEmpleados(listaDeEmpleados, T, identificador);
					printf("ingrese el id del empleado que desee dar de baja");
					fflush(stdin);
					scanf("%d\n", &guardarId);
					printf("%d", guardarId);
					retorno = bajaEmpleado(listaDeEmpleados , T, guardarId);
					if(retorno !=1)
					{
						printf("Empleado dado de baja con exito!!\n");
					}
					else
					{
						printf("No se pudo dar de baja!!\n");
					}
				bandera1=1;
				}
				break;

			case 3:
				if (bandera1==0)
				{
					printf("\n error,no ingresaste empleados");
				}
				else
				{
					mostrarEmpleados(listaDeEmpleados, T, identificador);
					printf("ingrese el id del empleado que desee modificar\n");
					scanf("%d\n", &guardarId);

					retorno = modificarEmpleado(listaDeEmpleados, T, identificador);
					if(retorno!=1)
					{
						printf("Empleado modificado con exito!!\n");
					}
					else
					{
						printf("No se pudo modificar el empleado!!\n");
					}
				bandera1=1;
				}
			break;

			case 4:
				mostrarEmpleados(listaDeEmpleados, T, identificador);
				//  OrdenarEmpleadosPorApellido(listaDeEmpleados, T);
			  //  OrdenarEmpleadosPorSector(listaDeEmpleados, T);
			 //   mostrarListadoDeEmpleados(listaDeEmpleados, T);
			break;
			case 5:
				printf("si desea seguir escribe s sino n");
				fflush(stdin);
				scanf("%c", &seguir);
			break;
		}
	}
return 0;
} // fin del main
