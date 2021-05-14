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

int mostrarEmpleados(eEmpleado listaDeEmpleados[], int tam);
//int mostrarListadoDeEmpleados(eEmpleado listaDeEmpleados[], int tam);
void PedirDatosEmpleado(void);
int cargarEmpleado(eEmpleado listaDeEmpleados[], int tam, int* id);
//void OrdenarEmpleadosPorApellido(eEmpleado listaDeEmpleados[], int tam);
int OrdenarEmpleadosPorSectorApellido(eEmpleado listaDeEmpleados[], int tam);
int inicializarEmpleados(eEmpleado listaDeEmpleados[], int tam);
int BuscarLibre(eEmpleado listaDeEmpleados[], int tam);
int bajaEmpleado(eEmpleado listaDeEmpleados[], int tam, int cual);

int main(void)
{
setbuf(stdout,NULL);

char seguir = 's';
int retorno;
int opcion;
eEmpleado listaDeEmpleados[T];
int identificador = 1;
int guardarId;



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
			break;

			case 2:
				mostrarEmpleados(listaDeEmpleados, T);
				printf("ingrese el id del empleado que desee dar de baja");
				scanf("%d\n", &guardarId);
				retorno = bajaEmpleado(listaDeEmpleados , T, guardarId);
                printf("%d", retorno);
				if(retorno !=1)
				{
					printf("Empleado dado de baja con exito!!!\n");
				}
				else
				{
					printf("No se pudo dar de baja!!\n");
				}

			break;

			case 3:
				mostrarEmpleados(listaDeEmpleados, T);
				printf("ingrese el id del empleado que desee modificar\n");
				scanf("%d\n", &guardarId);

			break;

			case 4:
				  mostrarEmpleados(listaDeEmpleados, T);
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

	int bajaEmpleado(eEmpleado listaDeEmpleados[],int tam, int cual)
	{
		int i;
        int resultado = 0;
        printf("entra en la funcion baja");
		for(i = 0; i < tam; i++)
		{
			if(listaDeEmpleados[i].id == cual)
			{

				listaDeEmpleados[i].isEmpty = 1;
				resultado = 1;
				break;
			}
		}
		return resultado;
	}


/*arrancan las cosas raras q no son el main */

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
	}


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

    }

   int mostrarEmpleados(eEmpleado listaDeEmpleados[], int tam)
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
   }

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
   }


