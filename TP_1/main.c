#include <stdio.h>
#include <stdlib.h>
#include "func.h"
#define maximo 32000
#define minimo -32000

int main()
{
    char seguir='s';
    int opcion=0;
    int numeroUno;
    int numeroDos;
    int suma; //ya se que no hace falta poner todas las variables para cada operacion, pero asi no me pierdo con los valores de las mismas
    int resta;
    float division;
    int multiplica;
    int factor;

    while(seguir=='s')
    {
        printf("\n1- Ingresar 1er operando \n");
        printf("2- Ingresar 2do operando \n");
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                if(getInt("\ningrese el primer numero \n", "error", 5, maximo,minimo, &numeroUno)==0)
                {
                    printf("\nel numero que elijio fue %d \n",numeroUno);
                }
                else
                {
                    printf("error\n");
                }

            break;
            case 2:
                if(getInt("\n ingrese el segundo numero \n","error",5,23000,-23000,&numeroDos)==0)
                {
                    printf("\nel numero que elijio fue: %d\n", numeroDos);
                }
                else
                {
                    printf("error\n");
                }

            break;
            case 3:
                if(sumar(numeroUno, numeroDos,&suma)==0)
                {
                    printf("\nla suma es: %d\n", suma);
                }
                else
                {
                    printf("error\n");
                }

            break;
            case 4:
                if(restar(numeroUno, numeroDos, &resta)==0)
                {
                    printf("\nla resta es: %d\n", resta);
                }
                else
                {
                    printf("error\n");
                }

            break;
            case 5:
                if(dividir(numeroUno,numeroDos, &division)==0)
                {
                    printf("\nla division es: %.2f\n", division);
                }
                else
                {
                    printf("error\n");
                }

            break;
            case 6:
                if(multiplicacion(numeroUno, numeroDos, &multiplica)==0)
                {
                    printf("\nLa division es: %d\n", multiplica);
                }
                else
                {
                    printf("error\n");
                }

            break;
            case 7:
                if(factorial(numeroUno,&factor)==0)
                {
                    printf("\nEl factorial es: %d\n", factor);
                }
                else
                {
                    printf("error\n");
                }

            break;
            case 8:
                 if(sumar(numeroUno, numeroDos,&suma)==0)
                {
                    printf("\nla suma es: %d", suma);
                }
                 if(restar(numeroUno, numeroDos, &resta)==0)
                {
                    printf("\nla resta es: %d", resta);
                }
                if(dividir(numeroUno,numeroDos, &division)==0)
                {
                    printf("\nla division es: %.2f", division);
                }
                if(multiplicacion(numeroUno, numeroDos, &multiplica)==0)
                {
                    printf("\nLa division es: %d", multiplica);
                }
                  if(factorial(numeroUno,&factor)==0)
                {
                    printf("\nEl factorial es: %d", factor);
                }
                else
                {
                    printf("error\n");
                }

            break;
            case 9:
                seguir = 'n';
            break;
            default :
                printf("ingrese un numero enntre 1 y 9\n");
            break;
        }//fin del switcj

    }//fin del while
    return 0;
}//fin del main
