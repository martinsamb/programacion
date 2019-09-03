#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    float  numeroUno = 'a';
    float  numeroDos = 'b';
    float operacionFactorial1;
    float operacionFactorial2;
    float suma;
    float resta;
    float multiplicacion;
    float division;

    while(seguir=='s')
    {
        if ( numeroUno == 'a' )
        {
            printf("\n1- Ingresar 1er operando (A=x)\n");
        }
        else
        {
            printf("\n1- Ingresar 1er operando (A= %.2f)\n", numeroUno);
        }

        if ( numeroDos == 'b' )
        {
            printf("\n2- Ingresar 1er operando (B=y)\n");
        }
        else
        {
            printf("\n2- Ingresar 2do operando (B= %.2f)\n", numeroDos);
        }
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n");

        printf("Ingrese la opcion 1-9\n");
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                printf("Ingrese un primer numero\n");
                scanf("%f",&numeroUno);
                break;
            case 2:
                printf("Ingrese un segundo numero\n");
                scanf("%f",&numeroDos);
                break;
            case 3:
                suma = sumar(numeroUno, numeroDos);
                printf("La suma es: %.2f\n", suma);
                break;
            case 4:
                resta = restar(numeroUno, numeroDos);
                printf("La resta es %.2f\n", resta);
                break;
            case 5:
                division = dividir(numeroUno, numeroDos);
                printf("La division es %.2f\n", division);
                break;
            case 6:
                multiplicacion = multiplicar(numeroUno, numeroDos);
                printf("La multiplicacion es %.2f\n", multiplicacion);
                break;
            case 7:
                if(numeroUno < 0)
                {
                    printf("ERROR: NO EXISTE FACTORIAL DE UN NEGATIVO\n");
                }
                else
                {
                    operacionFactorial1 = factorial(numeroUno);
                    printf("\nEl factorial de %.2f es: %.2f\n",numeroUno, operacionFactorial1);
                }
                if (numeroDos < 0)
                {
                    printf("ERROR: NO EXISTE FACTORIAL DE UN NEGATIVO\n");
                }
                else
                {
                    operacionFactorial2 = factorial(numeroDos);
                    printf("\nEl factorial de %.2f  es: %.2f\n",numeroDos, operacionFactorial2);
                }
                break;
            case 8:
                suma = sumar(numeroUno, numeroDos);
                resta = restar(numeroUno, numeroDos);
                multiplicacion = multiplicar(numeroUno, numeroDos);
                division = dividir(numeroUno, numeroDos);
                operacionFactorial1 = factorial(numeroUno);
                operacionFactorial2 = factorial(numeroDos);
                printf("La suma es %.2f\n", suma);
                printf("La resta es %.2f\n", resta);
                printf("La multiplicacion es %.2f\n", multiplicacion);
                printf("La division es %.2f\n", division);
                if(numeroUno < 0)
                {
                    printf("ERROR: NO EXISTE FACTORIAL DE UN NEGATIVO\n");
                }
                else
                {
                    operacionFactorial1 = factorial(numeroUno);
                    printf("\nEl factorial de %.2f es: %.2f\n",numeroUno, operacionFactorial1);
                }
                if (numeroDos < 0)
                {
                    printf("ERROR: NO EXISTE FACTORIAL DE UN NEGATIVO\n");
                }
                else
                {
                    operacionFactorial2 = factorial(numeroDos);
                    printf("\nEl factorial de %.2f  es: %.2f\n",numeroDos, operacionFactorial2);
                }
                break;
            case 9:
                seguir = 'n';
                break;
            default:
                printf("Debe ingresar un numero del 1-9");
                break;
        }
    }
    return 0;
}
