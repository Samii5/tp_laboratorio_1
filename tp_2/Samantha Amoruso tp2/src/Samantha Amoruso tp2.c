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

int mostrarEmpleados(eEmpleado listaDeEmpleados[], int tam, int identificador);
//int mostrarListadoDeEmpleados(eEmpleado listaDeEmpleados[], int tam);
void PedirDatosEmpleado(void);
int cargarEmpleado(eEmpleado listaDeEmpleados[], int tam, int* id);
//void OrdenarEmpleadosPorApellido(eEmpleado listaDeEmpleados[], int tam);
int OrdenarEmpleadosPorSectorApellido(eEmpleado listaDeEmpleados[], int tam);
int inicializarEmpleados(eEmpleado listaDeEmpleados[], int tam);
int BuscarLibre(eEmpleado listaDeEmpleados[], int tam);
int bajaEmpleado(eEmpleado listaDeEmpleados[], int tam, int guardarId);
int modificarEmpleado(eEmpleado listaDeEmpleados[], int tam, int identificador);
int buscarEmpleado(eEmpleado listaDeEmpleados[], int tam, int identificador);

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
        indice = int buscarEmpleado(int respuesta, int listaDeEmpleados[indice], int tam, int identificador);
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
	}

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


