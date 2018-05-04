#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define QTY 20
#include "FUNCIONES.h"
#include <string.h>

int main()
{
    EPersona persona[QTY];
    char seguir='s';
    int opcion=0;


    InicializarArry(persona , QTY);

    while(seguir=='s')
    {
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n\n");
        printf("5- Salir\n");

        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                {

                    per_alta(persona, 38000,19,"giuliano",0 );

                    per_alta(persona, 23000346, 23,"aaaaaaa",1);
                    per_alta(persona, 24000323, 11, "rrrrrrrr",2);
                    per_alta(persona, 32400213, 40, "ooooooooo",3);
                    per_alta(persona, 11111111, 4, "tttttttttt",4);
                    per_alta(persona, 34895732, 55, "pppppppp",5);
                    per_alta(persona, 23423411, 35, "bbbbbbbbbb",6);
                    per_alta(persona, 11111654, 8, "ffffffffff",7);
                    per_alta(persona, 11111234, 60, "vvvvvvvvvvv",8);
                    per_alta(persona, 11111457, 18, "xxxxxxxxxxx",9);
                }
                break;
            case 2:
                {
                    if(per_baja(persona, QTY)==0)
                    {
                        printf("se ha borrado el usuario\n");
                    }
                    else
                    {
                        printf("no se encontro el dni que se yo\n");
                    }

                }
                break;
            case 3:
                {
                    //per_mostrar(persona,QTY);
                    per_ordenar(persona, QTY,0);
                    per_mostrar(persona, QTY);
                }
                break;
            case 4:
                {
                    imprimir_grafico(persona, QTY);
                }
                break;
            case 5:
                seguir = 'n';
                printf("adios...");
                break;
        }
    }

    return 0;
}
