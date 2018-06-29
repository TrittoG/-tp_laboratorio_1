#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "parse.h"



/** \brief lee un archivo
 *
 * \param pList ArrayList* donde se va a guardar lo que lee
 * \param path char* path ubicacion del archivo
 * \param pathError char* ubicacion del archivo secundario donde se guardaran los elementos con errores
 * \return int -1 si hay algun parametro nulo
                0 si esta todo ok
 *
 */
int parse_leerArchivo(ArrayList* pList, char* path, char* pathError)
{
    int retorno = -1;
    if(pList != NULL && path != NULL && pathError != NULL)
    {
        FILE* pFile;
        FILE* pFileError;
        pFile = fopen(path, "r");
        pFileError = fopen(pathError, "w");
        if(pFile != NULL && pFileError != NULL)
        {
            char bufId[4096];
            char bufName[4096];
            char bufLastName[4096];
            int id;
            void* auxStruct;
            while(!feof(pFile))
            {
            	retorno = 0;
                fscanf(pFile, "%[^,],%[^,],%[^\n]\n", bufId, bufName, bufLastName);
                id = atoi(bufId);
                auxStruct = struct_newParamateros(bufName, bufLastName, id);
                if(auxStruct != NULL)
                {
                	al_add(pList, auxStruct);
				}
				else
				{
					fprintf(pFileError,"%s,%s,%s\n", bufId,bufName,bufLastName);
				}

            }
            fclose(pFile);
            fclose(pFileError);
        }
    }
    return retorno;
}




/** \brief escribe un archivo
 *
 * \param pList ArrayList* lugar de donde se sacan los elementos a guardar en el archivo
 * \param path char* ubicacion del archivo
 * \return int -1 si hay error o es nulo
 *              0 si esta todo ok
 */
int parse_writeArchivo(ArrayList* pList, char* path)
{
    int retorno = -1;
    if(pList != NULL && path != NULL)
    {
    	FILE* pFile;
    	pFile = fopen(path, "w");
    	if(pFile != NULL)
    	{
    		void* auxStruc;
    		char* nombre;
    		char* apellido;
    		int id;
    		int i;
    		for(i = 0; i < al_len(pList); i++)
    		{
    			auxStruc = al_get(pList, i);
    			struct_getName(auxStruc, nombre);
    			struct_getApellido(auxStruc, apellido);
    			struct_getId(auxStruc, &id);
    			fprintf(pFile, "%d,%s,%s\n", id, nombre, apellido);
    			retorno = 0;
			}
		}
		fclose(pFile);
	}
    return retorno;
}

