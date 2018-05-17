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
        getValidInt("\n1.Alta\n2.Baja\n3.Modificar\n4.Publicar\n5.Pausar Publicacion\n6.reanudar publicacion\n7.mostrar clientes\n8.mostrar publicaciones\n9.Salir\n10.El cliente con mas avisos activos\n11.El cliente con mas avisos pausados\n12.el cliente con mas avisos\n13.cant publicaciones de un rubro\n14.rubro con mas publicaciones activas\n15.rubro con menos publicaciones activas\n","\nNo valida\n",&menu,1,15,1);
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
                break;
            case 8 :
                publicaciones_mostrar(arrayC,QTY, arrayP, QTY_PUB);
                break;
            case 10 :
                informar_clienteConMasAvisosActivos(arrayC,QTY,arrayP,QTY_PUB);
                break;
            case 11 :
                informar_clienteConMasAvisosPausados(arrayC,QTY,arrayP,QTY_PUB);
                break;
            case 12 :
                informar_clienteConMasAvisos(arrayC,QTY,arrayP,QTY_PUB);
                break;
            case 13 :
                cantidadPublicacionRubroIngresado(arrayP, QTY_PUB);
                break;
            case 14 :
                rubroMasPublicacionesActivas(arrayP, QTY_PUB);
                break;
            case 15 :
                rubroMenosPublicacionesActivas(arrayP, QTY_PUB);
                break;




        }

    }while(menu != 9);

    return 0;
}
