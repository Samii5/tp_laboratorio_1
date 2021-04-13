/******************************************************************************
Samantha Amoruso 5to 4ta TM
Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
	setbuf(stdout,NULL);

    float numero1;
    float numero2;
    float xsumar;
    float xrestar;
    float xmultiplicar;
    float xdividir;
    float xfactorial;
    float xfactorial2;
    int menu;
    char seguir;
    seguir='s';
    int bandera1 = 0;
    int bandera2 = 0;
    int realizaroperaciones;

    //bandera1=0;
    //bandera2=0;
    realizaroperaciones=0;

    while(seguir=='s')
    {
    printf("\nIngrese la funcion que desee hacer: \n1-pedir el primer numero \n2-pedir el segundo numero \n3-realizar operaciones \n4-mostrar operaciones \n5-salir");
    printf("\nelegir opcion: ");
    scanf("%d", &menu);


        switch(menu)
        {

            case 1:
            printf("Ingresar un numero: ");
            scanf("%f", &numero1);
            printf("El numero que usted ingreso es: %.2f", numero1);
            bandera1=1;
            break;

            case 2:
            printf("\nIngresar otro numero: ");
            scanf("%f", &numero2);
            printf("El numero que usted ingreso es: %.2f y el %.2f", numero1, numero2);
            bandera2=1;
            break;

            case 3:
            if(bandera1==0)
            {
                printf("\nerror,no ingresaste el primer numero");
            }
            else
            {
                if(bandera2==0)
                {
                    printf("\nerror,no ingresaste el segundo numero");
                }
                	else
                	{
						xsumar = sumar( numero1 ,numero2);
						xrestar = restar(numero1, numero2);
						xmultiplicar = multiplicar(numero1, numero2);
						xdividir = dividir( numero1, numero2);
						xfactorial = factorial (numero1);
						xfactorial2 = factorial (numero2);
						printf("Ya se realizaron las operaciones");
						realizaroperaciones=1;
					}

             }
             break;

			case 4:
			if(bandera1==0)
			{
				printf("\nerror,no ingresaste el primer numero");
			}
				else
				{
					if(bandera2==0)
					{
						printf("\nerror,no ingresaste el segundo numero");
					}
						else
						{
							if(realizaroperaciones==0)
							{
								printf("\nerror, no se realizaron las operaciones");
							}
								else
								{
									printf("\n El resultado de la suma de %.2f y %.2f es: %.2f",numero1,numero2,xsumar);
									printf("\n El resultado de la resta de %.2f y %.2f es: %.2f",numero1,numero2,xrestar);
									printf("\n El resultado de la multiplicacion de %.2f y %.2f es: %.2f",numero1,numero2,xmultiplicar);
									printf("\n El resultado del factorial del primer numero es : %.2f y del segundo factorial es : %.2f", xfactorial, xfactorial2);

									if(numero2 != 0)
									{
									printf("\n El resultado de la division de %.2f y %.2f es: %.2f",numero1,numero2,xdividir);
									}
									else
									{
										printf("\n No es posible dividir por 0");
									}
								}
						}
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
