#include "funciones.h"

/*Esta funcion te hace la suma*/
float sumar(float numero1, float numero2)
{

float resultado;
resultado = numero1 + numero2;
return resultado;

}

/*Esta funcion te hace la resta*/
float restar(float numero1, float numero2)
{

float resultado;
resultado = numero1 - numero2;
return resultado;

}

/*Esta funcion te hace la multiplicacion*/
float multiplicar(float numero1, float numero2)
{

float resultado;
resultado = numero1 * numero2;
return resultado;

}

/*Esta funcion te hace la division*/
float dividir(float numero1, float numero2)
{

float resultado;
resultado = numero1 / numero2;
return resultado;

}

/*Esta funcion te hace el factorial*/
float factorial(float numero1)
{
    float resultado = 1;

    for (int i = 1; i <= numero1; i++)
    {
        resultado = resultado * i;
    }

    return (float) resultado;
}
