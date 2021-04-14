/******************************************************************************
Samantha Amoruso 1ro B TM
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"

int main()
{
	setbuf(stdout,NULL);

    float NumeroUno;
    float NumeroDos;
    float xsuma;
    float xresta;
    float xmultiplicacion;
    float xdivision;
    float xfactorial;
    float xfactorial2;
    int menu;
    char seguir;
    seguir='s';
    int bandera1 = 0;
    int bandera2 = 0;
    int realizaroperaciones;

    bandera1=0;
    bandera2=0;
    realizaroperaciones=0;

    while(seguir=='s')
    {
    printf("\n Ingrese la funcion que desee hacer: \n 1-pedir el primer numero \n 2-pedir el segundo numero \n 3-realizar operaciones \n 4-mostrar operaciones \n 5-salir");
    printf("\n elegir opcion: ");
    scanf("%d", &menu);


        switch(menu)
        {

            case 1:
            printf("Ingresar un numero: ");
            scanf("%f", &NumeroUno);
            printf("El numero que usted ingreso es: %.2f", NumeroUno);
            bandera1=1;
            break;

            case 2:
            if (bandera1==0)
            {
            	printf("\n error,no ingresaste el primer numero");
            }
            else
            {
            	printf("\n Ingrese otro numero: ");
            	scanf("%f", &NumeroDos);
            	printf("Los numeros que usted ingreso son: %.2f y el %.2f", NumeroUno, NumeroDos);
            	bandera2=1;
            }
            break;

            case 3:
            if(bandera1==1 && bandera2==1)
            {
            	xsuma = sumar( NumeroUno ,NumeroDos);
				xresta = restar(NumeroUno, NumeroDos);
				xmultiplicacion = multiplicar(NumeroUno, NumeroDos);
				xdivision = dividir( NumeroUno, NumeroDos);
				xfactorial = factorial (NumeroUno);
				xfactorial2 = factorial (NumeroDos);
				printf("Ya se realizaron las operaciones");
				realizaroperaciones=1;
            }
            else if(bandera2==0)
				{
					printf("\n error,no ingresaste el segundo numero");
				}
					if (bandera1==0)
					{
					printf("\n error,no ingresaste el primer numero");
					}
					break;

			case 4:
			if (bandera1==1 && bandera2==1 && realizaroperaciones==1)
			{
				printf("\n El resultado de la suma de %.2f y %.2f es: %.2f",NumeroUno,NumeroDos,xsuma);
				printf("\n El resultado de la resta de %.2f y %.2f es: %.2f",NumeroUno,NumeroDos,xresta);
				printf("\n El resultado de la multiplicacion de %.2f y %.2f es: %.2f",NumeroUno,NumeroDos,xmultiplicacion);
				printf("\n El resultado del factorial del primer numero es : %.2f y del segundo factorial es : %.2f", xfactorial, xfactorial2);

				if(NumeroDos != 0)
				{
				printf("\n El resultado de la division de %.2f y %.2f es: %.2f",NumeroUno,NumeroDos,xdivision);
				}
				else
				{
					printf("\n No es posible dividir por 0");
				}
			}
			else if (realizaroperaciones==0)
			{
				printf("\n error,no realizaste las operaciones");
			}
				if (bandera2==0)
				{
					printf("\n error,no ingresaste el segundo numero");
				}
					if (bandera1==0)
					{
						printf("\n error,no ingresaste el primer numero");
					}
					break;

				case 5:
				printf("si desea seguir escribe s sino n");
				fflush(stdin);
				scanf("%c", &seguir);
				break;
        }

    }

    return 0;
}
