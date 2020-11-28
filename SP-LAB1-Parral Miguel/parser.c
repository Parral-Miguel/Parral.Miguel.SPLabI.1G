#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "entidades.h"

int parsear_paises(FILE* pFile , LinkedList* listaPaises)
{
    ePaises* paisAux;


    int error = 1;
    int r = 0;
    char var1[50],var3[50],var2[50],var4[50],var5[50];

    if(pFile == NULL)
    {
        printf("El archivo no existe");

    }

    r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,]%[^\n]\n",var1,var2,var3,var4,var5);

    do
    {
        r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4,var5);

        if (r == 5)
        {
            paisAux = pais_nuevo();

            paisAux = pais_nuevo();
            paisAux->id = atoi(var1);
            strcpy(paisAux->pais, var2);
            paisAux->recuperados = atoi(var3);
            paisAux->infectados = atoi(var4);
            paisAux->muertos = atoi(var5);

            ll_add(listaPaises, paisAux);

            error = 0;
        }
    }
    while(!feof(pFile));
    fclose(pFile);
    return error;
}

