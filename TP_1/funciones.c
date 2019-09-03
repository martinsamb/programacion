#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

/** \brief Funcion que permite hacer la operacion de suma
 *
 * \param numeroUno float Primer operando
 * \param numeroDos float Segundo operando
 * \return float resultado
 *
 */
float sumar(float numeroUno, float numeroDos)
{
    float resultado;
    resultado = numeroUno + numeroDos;
    return resultado;
}

/** \brief Funcion que permite hacer la operacion de la resta
 *
 * \param numeroUno float Minuendo
 * \param numeroDos float Sustraendo
 * \return float resultado
 *
 */
float restar(float numeroUno, float numeroDos)
{
    float resultado;
    resultado = numeroUno - numeroDos;
    return resultado;
}

/** \brief Funcion que permite hacer la operacion de la multiplicacion,
 *  incluye la correccion al multiplicar un numero negativo por cero
 * \param numeroUno float Primer factor
 * \param numeroDos float Segundo factor
 * \return float resultado
 *
 */
float multiplicar(float numeroUno, float numeroDos)
{
    float resultado;
    resultado = numeroUno * numeroDos;
    return resultado;
}

/** \brief Funcion que permite hacer la operacion de la division,
 *  incluye la condicion de error al dividir por cero
 * \param numeroUno float Dividendo
 * \param numeroDos float Divisor
 * \return return division
 *
 */
float dividir(float numeroUno, float numeroDos)
{

    if( numeroDos == 0)
    {
        printf("ERROR: NO SE PUEDE DIVIDIR POR CERO\n");
        return 0;
    }
    else
    {
        return (numeroUno / numeroDos);
    }
}
/** \brief Funcion que permite obtener el factorial del primer operando, segundo operando, incluye error por numero negativo
 *   y resultado 1 del factorial del 0. Si el operando tiene decimales, opera unicamente la parte entera.
 * \param numeroUno int Numero a ser factorizado
 * \param numeroDos int Numero a ser factorizado
 * \return int Factorial
 *
 */
int factorial(int a)
{
    int i, aux;
    aux = 1;
    for( i = 1; i <= a; i++)
    {
        aux *= i;
    }
    return aux;


}






