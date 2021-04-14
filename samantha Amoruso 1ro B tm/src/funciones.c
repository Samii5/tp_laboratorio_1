#include "Funciones.h"

float sumar(float NumeroUno, float NumeroDos)
{
float resultado;
resultado = NumeroUno + NumeroDos;
return resultado;
}

float restar(float NumeroUno, float NumeroDos)
{
float resultado;
resultado = NumeroUno - NumeroDos;
return resultado;
}

float multiplicar(float NumeroUno, float NumeroDos)
{
float resultado;
resultado = NumeroUno * NumeroDos;
return resultado;
}

float dividir(float NumeroUno, float NumeroDos)
{
float resultado;
resultado = NumeroUno / NumeroDos;
return resultado;
}

float factorial(float NumeroUno)
{
    float resultado = 1;

    for (int i = 1; i <= NumeroUno; i++)
    {
        resultado = resultado * i;
    }
    return (float) resultado;
}
