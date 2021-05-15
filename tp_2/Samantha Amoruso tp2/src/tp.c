#include "tp2.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
 * tp.c
 *
 *  Created on: 15 may. 2021
 *      Author: User
 */
#define VACIO 1
#define OCUPADO 0
#define T 5

int identificador = 1;
int guardarId;

int bajaEmpleado(eEmpleado listaDeEmpleados[],int tam, int guardarId)
	{
		int i;
        int resultado = 0;
        int respuesta;
        char opcion;
        int indice;

        int mostrarEmpleados(eEmpleado listaDeEmpleados[], int tam, int identificador);
        printf("\n\n");
        printf("cual es el id que queres dar de baja?");
        scanf("%d", &respuesta);
        indice = buscarEmpleado(respuesta, listaDeEmpleados[indice], tam, identificador);
        printf("estas seguro que quiere dar de baja a este empleado %d s/n ?\n", respuesta);
        fflush(stdin);
        scanf("%c", &opcion);
        if (opcion == 's')
        {
        	listaDeEmpleados[indice].isEmpty = 1;
        	return resultado;

        }

		for(i = 0; i < tam; i++)
		{
			if(listaDeEmpleados[i].id == guardarId)
			{

				listaDeEmpleados[i].isEmpty = VACIO;
				resultado = 1;
				break;
			}
		}
		return resultado;
	} // fin de baja empleado

    int cargarEmpleado(eEmpleado listaDeEmpleados[], int tam, int *id)
	{
		int libre;
		libre = BuscarLibre(listaDeEmpleados, tam);
		eEmpleado miEmpleado;


		if(listaDeEmpleados != NULL && tam > 0 && libre > -1)
		{
			printf("Ingrese nombre: ");
			fflush(stdin);
			scanf("%[^\n]", miEmpleado.nombre);

			printf("Ingrese apellido: ");
			fflush(stdin);
			scanf("%[^\n]", miEmpleado.apellido);

			printf(" Ingrese salario: ");
			scanf("%f", &miEmpleado.salario);

			printf(" Ingrese sector: ");
			scanf("%d", &miEmpleado.sector);

            listaDeEmpleados[libre].salario = miEmpleado.salario;
            listaDeEmpleados[libre].sector = miEmpleado.sector;
            strcpy(listaDeEmpleados[libre].apellido, miEmpleado.apellido);
            strcpy(listaDeEmpleados[libre].nombre, miEmpleado.nombre);
            listaDeEmpleados[libre].id = *id;
            (*id) ++;
            listaDeEmpleados[libre].isEmpty = 0;
		}
		return 0;
	}// fin de cargar empleado


    int BuscarLibre(eEmpleado listaDeEmpleados[], int tam)
    {
    	int lugarLibre =-1;

        if(listaDeEmpleados != NULL && tam > 0)
        {
            for(int i=0; i < tam; i++)
            {
            	if(listaDeEmpleados[i].isEmpty == VACIO)
            	{
            	    lugarLibre = i;
            	    break;
            	}

            }

        }
    	return lugarLibre;

    }// fin de buscar libre

   int mostrarEmpleados(eEmpleado listaDeEmpleados[], int tam, int identificador)
   {
	    int i;
    	int retorno =0;

		if(listaDeEmpleados != NULL && tam > 0)
		{
			for(i=0; i<tam; i++)
			 {
				if(listaDeEmpleados[i].isEmpty == OCUPADO)
				{
					printf("%d %s %s %.2f %d \n ", listaDeEmpleados[i].id,
							                       listaDeEmpleados[i].nombre,
												   listaDeEmpleados[i].apellido,
												   listaDeEmpleados[i].salario,
												   listaDeEmpleados[i].sector );
					retorno = 1;
				}

			 }

		}

    return retorno;
   } // fin de mostrar empleados

   int inicializarEmpleados(eEmpleado listaDeEmpleados[], int tam)
   {
	   int retorno = 0;
	   if(listaDeEmpleados != NULL && tam > 0)
	   {
		   for(int i= 0; i < tam; i++)
		   {
			   listaDeEmpleados[i].isEmpty = VACIO;
			   retorno = 1;
		   }
	   }

	   return retorno;
   }// fin de inicializar empleados

int modificarEmpleado(eEmpleado listaDeEmpleados[], int tam, int identificador)
{
	   int modificacion;
	   int indice = -1;
	   float nuevoSalario;
	   int nuevoSector;
 	   char nuevoApellido[51];
 	   char nuevoNombre[51];
 	   int tomarId;

	  mostrarEmpleados(listaDeEmpleados, T, identificador);
	  printf("ingrese el id del empleado que desea modificar");
	  scanf("%d", &tomarId);

	  printf("ingrese lo que quiere modificar de ese empleado 1.nombre\n 2.apellido\n 3.salario'n 4.sector\n");
	  scanf("%d%*c", &modificacion);

	  switch(modificacion)
	  {
		  case 1:
			printf("Ingrese el nuevo nombre: ");
			fflush(stdin);
			gets(nuevoNombre);

			strcpy(listaDeEmpleados[indice].nombre, nuevoNombre);
		  break;

		  case 2:
			printf("Ingrese el nuevo apellido: ");
			fflush(stdin);
			gets(nuevoApellido);

			strcpy(listaDeEmpleados[indice].apellido, nuevoApellido);
		  break;

		  case 3:
			  printf("ingrese el nuevo salario");
			  scanf("%f", &nuevoSalario);
			  listaDeEmpleados[indice].salario = nuevoSalario;
		  break;

		  case 4:
			  printf("ingrese el nuevo sector");
			  scanf("%d", &nuevoSector);
			  listaDeEmpleados[indice].sector = nuevoSector;
		  break;
	  }
return indice;
} /*fin de modificar empleado */

int buscarEmpleado(eEmpleado listaDeEmpleados[], int tam, int identificador)
{
		  int indice = -1;
		  if (listaDeEmpleados != NULL && tam > 0)
		  {
			   for (int i=0; i< tam; i++)
			   {
				   if (listaDeEmpleados[i].id && listaDeEmpleados[i].isEmpty)
				   {
					   indice = i;
					   break;
				   }
			   }
		  }
 return indice;
} // fin de buscarEmpleado

