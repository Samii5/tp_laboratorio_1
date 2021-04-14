#include "Funciones.h"

float sumar(float NumeroUno, float NumeroDos)
{
float resultado;
resultado = NumeroUno + NumeroDos;
return resultado;
} // hace la suma

float restar(float NumeroUno, float NumeroDos)
{
float resultado;
resultado = NumeroUno - NumeroDos;
return resultado;
} // hace la resta

float multiplicar(float NumeroUno, float NumeroDos)
{
float resultado;
resultado = NumeroUno * NumeroDos;
return resultado;
} // hace la multiplicacion

float dividir(float NumeroUno, float NumeroDos)
{
float resultado;
resultado = NumeroUno / NumeroDos;
return resultado;
} // hace la division

float factorial(float NumeroUno)
{
    float resultado = 1;

    for (int i = 1; i <= NumeroUno; i++)
    {
        resultado = resultado * i;
    }
    return (float) resultado;
} // te da el factorial
