#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "fantasma.h"
#include "fantasmaDos.h"
#include "utn.h"
#define QTY 100
#define QTY_PUB 1000
#include "informar.h"

int main()
{
    Cliente arrayC[QTY];
    Publicacion arrayP[QTY_PUB];

    int menu;
    int auxiliarId;

    Cliente_init(arrayC,QTY);
    Publicacion_init(arrayP,QTY_PUB);
    do
    {
        getValidInt("\n1.Alta\n2.Baja\n3.Modificar\n4.Publicar\n5.Pausar Publicacion\n6.reanudar publicacion\n7.mostrar clientes\n8.mostrar publicaciones\n Debug\n9.Salir\n","\nNo valida\n",&menu,1,9,1);
        switch(menu)
        {
            case 1:
                Cliente_alta(arrayC,QTY);
                break;
            case 2:
                getValidInt("ID?","\nNumero valida\n",&auxiliarId,0,200,2);
                Cliente_baja(arrayC,QTY,auxiliarId);
                break;
            case 3:
                getValidInt("ID?","\nNumero valida\n",&auxiliarId,0,200,2);
                Cliente_modificacion(arrayC,QTY,auxiliarId);
                break;
            case 4:
                Publicacion_alta(arrayP,QTY_PUB,arrayC, QTY );

                break;
            case 5:
                publicacion_pausar(arrayP, QTY_PUB , arrayC, QTY);

                break;
            case 6:
                publicacion_reanudar(arrayP, QTY_PUB,arrayC, QTY);
                break;
            case 7 :
                Cliente_mostrar(arrayC,QTY,arrayP, QTY_PUB);
            case 8 :
                publicaciones_mostrar(arrayC,QTY, arrayP, QTY_PUB);



        }

    }while(menu != 9);

    return 0;
}
