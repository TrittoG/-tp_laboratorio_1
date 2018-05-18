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
    int resultado;

    Cliente_init(arrayC,QTY);
    Publicacion_init(arrayP,QTY_PUB);


    do
    {
        getValidInt("\n1.Alta\n2.Baja\n3.Modificar\n4.Publicar\n5.Pausar Publicacion\n6.reanudar publicacion\n7.mostrar clientes\n8.mostrar publicaciones\n9.Salir\n10.El cliente con mas avisos activos\n11.El cliente con mas avisos pausados\n12.el cliente con mas avisos\n13.cant publicaciones de un rubro\n14.rubro con mas publicaciones activas\n15.rubro con menos publicaciones activas\n","\nNo valida\n",&menu,1,15,1);
        switch(menu)
        {
            case 1:
                resultado = Cliente_alta(arrayC,QTY);
                if(resultado == -1)
                {
                    printf("Error en el array o su cantidad");
                }
                else
                {
                   if(resultado == -2)
                   {
                       printf("indice invalido");
                   }
                   else
                    {
                        if(resultado == -3)
                        {
                            printf("mal pasados los datos");
                        }
                        else
                        {
                            if(resultado == 0)
                            {
                                printf("Creado ");
                            }
                        }
                    }
                }
                break;
            case 2:
                getValidInt("ID?","\nNumero valida\n",&auxiliarId,0,200,2);
                resultado = Cliente_baja(arrayC,QTY,auxiliarId);
                if(resultado == -1)
                {
                    printf("mal parametros");
                }
                else
                {
                    if(resultado == -2)
                    {
                        printf("Indice invalido");
                    }
                    else
                    {
                        if(resultado == 0)
                            printf("baja correctamente");
                    }
                }

                break;
            case 3:
                getValidInt("ID?","\nNumero valida\n",&auxiliarId,0,200,2);
                resultado = Cliente_modificacion(arrayC,QTY,auxiliarId);
                if(resultado == -1)
                {
                    printf("Error en el array o su cantidad");
                }
                else
                {
                   if(resultado == -2)
                   {
                       printf("indice  invalido");
                   }
                   else
                    {
                        if(resultado == -3)
                        {
                            printf("No se completaron bien los datos");
                        }
                        else
                        {
                            if(resultado == 0)
                            {
                                printf("Modificado");
                            }
                        }
                    }
                }
                break;
            case 4:
                resultado = Publicacion_alta(arrayP,QTY_PUB,arrayC, QTY );
                if(resultado == -1)
                {
                    printf("Se pasaron mal los parametros");
                }
                else
                {
                    if(resultado == -2)
                    {
                        printf("Error en el indice donde guardar");
                    }
                    else
                    {
                        if(resultado == -3)
                        {
                            printf("Los datos no son validos");
                        }
                        else
                        {
                            if(resultado == 0)
                            {
                                printf("Publicacion creada correctamente");
                            }
                        }
                    }
                }

                break;
            case 5:
                resultado = publicacion_pausar(arrayP, QTY_PUB , arrayC, QTY);
                if(resultado == -1)
                {
                    printf("Se pasaron mal los parametros");
                }
                else
                {
                    if(resultado == -2)
                    {
                        printf("Error en el indice donde guardar");
                    }
                    else
                    {
                        if(resultado == -3)
                        {
                            printf("Los datos no son validos");
                        }
                        else
                        {
                            if(resultado == 0)
                            {
                                printf("Publicacion pausada");
                            }
                        }
                    }
                }

                break;
            case 6:
                resultado = publicacion_reanudar(arrayP, QTY_PUB,arrayC, QTY);
                if(resultado == -1)
                {
                    printf("Se le pasaron mal los parametros");
                }

                break;
            case 7 :
                resultado = Cliente_mostrar(arrayC,QTY,arrayP, QTY_PUB);
                if(resultado == -1)
                {
                    printf("Se le pasaron mal los parametros");
                }
                break;
            case 8 :
                resultado = publicaciones_mostrar(arrayC,QTY, arrayP, QTY_PUB);
                if(resultado == -1)
                {
                    printf("Se le pasaron mal los parametros");
                }
                break;
            case 10 :
                resultado = informar_clienteConMasAvisosActivos(arrayC,QTY,arrayP,QTY_PUB);
                if(resultado == -1)
                {
                    printf("pasaron mal los parametros");
                }
                break;
            case 11 :
                resultado = informar_clienteConMasAvisosPausados(arrayC,QTY,arrayP,QTY_PUB);
                if(resultado == -1)
                {
                    printf("pasaron mal los parametros");
                }
                break;
            case 12 :
                resultado = informar_clienteConMasAvisos(arrayC,QTY,arrayP,QTY_PUB);
                if(resultado == -1)
                {
                    printf("pasaron mal los parametros");
                }
                break;
            case 13 :
                resultado = cantidadPublicacionRubroIngresado(arrayP, QTY_PUB);
                if(resultado == -1)
                {
                    printf("pasaron mal los parametros");
                }
                break;
            case 14 :
                rubroMasPublicacionesActivas(arrayP, QTY_PUB);
                if(resultado == -1)
                {
                    printf("pasaron mal los parametros");
                }
                break;
            case 15 :
                resultado = rubroMenosPublicacionesActivas(arrayP, QTY_PUB);
                if(resultado == -1)
                {
                    printf("pasaron mal los parametros");
                }
                break;




        }

    }while(menu != 9);

    return 0;
}
