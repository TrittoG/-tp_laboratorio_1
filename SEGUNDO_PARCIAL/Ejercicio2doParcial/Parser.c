#include <stdio.h>
#include <stdlib.h>
#include "Empleado.h"
#include "ArrayList.h"
#include "Parser.h"


int parser_parseEmpleados(char* fileName, ArrayList* listaEmpleados)
{
    int retorno = 0;
    if(listaEmpleados != NULL && fileName != NULL)
    {
        FILE* pFile;
        pFile = fopen(fileName, "r");
        if(pFile != NULL)
        {
            char bufId[4096];
            char bufName[4096];
            char bufHorasTrabajadas[4096];
            int id;
            int horasTrabajadas;

            fscanf(pFile, "%[^,],%[^,],%[^\n]\n", bufId, bufName, bufHorasTrabajadas);

            while(!feof(pFile))
            {
                Empleado *auxStruct = Empleado_new();

                fscanf(pFile, "%[^,],%[^,],%[^\n]\n", bufId, bufName, bufHorasTrabajadas);
                id = atoi(bufId);
                horasTrabajadas = atoi(bufHorasTrabajadas);

                auxStruct = empleado_newParamateros(id, bufName, horasTrabajadas);

                	al_add(listaEmpleados, auxStruct);
                	retorno = 1;

            }
            fclose(pFile);
        }
    }
    return retorno;
}



