#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "entidades.h"
#include "LinkedList.h"


ePaises* pais_nuevo()
{
    ePaises* paisNuevo;

    paisNuevo = (ePaises*) malloc(sizeof(ePaises));

    return paisNuevo;
}

int pais_setId(ePaises* pais,int id)
{
    if (pais != NULL)
    {
        pais->id = id;
    }

    return 0;
}
int pais_getId(ePaises* pais,int* id)
{

    int error = 0;
    if (pais != NULL)
    {
        *id = pais->id;
        error = 1;
    }

    return error;
}

int pais_setPais(ePaises* pais,char* paisNombre)
{
    if(pais != NULL)
    {
        strcpy(pais->pais, paisNombre);
    }
    return 0;
}
int pais_getPais(ePaises* pais,char* paisNombre)
{
    int error = 0;
    if (pais != NULL)
    {
        strcpy(paisNombre, pais->pais);
        error = 1;
    }

    return error;
}

int pais_setRecuperados(ePaises* pais,int recuperados)
{
    if (pais != NULL)
    {
        pais->recuperados = recuperados;
    }
    return 0;
}
int pais_getRecuperados(ePaises* pais,int* recuperados)
{
    int error = 0;
    if (pais != NULL)
    {
        *recuperados = pais->recuperados;
        error = 1;
    }

    return error;
}

int pais_setInfectados(ePaises* pais,int infectados)
{
    if (pais != NULL)
    {
        pais->infectados = infectados;
    }

    return 0;
}
int pais_getInfectados(ePaises* pais,int* infectados)
{
    int error = 0;
    if (pais != NULL)
    {
        *infectados = pais->infectados;
        error = 1;
    }

    return error;
}

int pais_setMuertos(ePaises* pais,int muertos)
{
    if (pais != NULL)
    {
        pais->muertos = muertos;
    }

    return 0;
}
int pais_getMuertos(ePaises* pais,int* muertos)
{
    int error = 0;
    if (pais != NULL)
    {
        *muertos = pais->muertos;
        error = 1;
    }

    return error;
}

ePaises* asignar_estadisticas(ePaises* pais)
{
    int recuperados;
    int muertos;
    int infectados;

    recuperados = rand()%(1000000 + 1)+50000;
    muertos = rand()%(50000 + 1)+1000;
    infectados = rand()%(2000000 + 1)+400000;


    pais_setMuertos(pais, muertos);
    pais_setInfectados(pais, infectados);
    pais_setRecuperados(pais, recuperados);

    return pais;

}

int filtrar_exito(ePaises* pais)
{
    int resultado = 0;
    int comparo;

    comparo = pais->muertos;

    if (comparo < 5000)
    {
        resultado = 1;
    }
    return resultado;
}

int filtrar_horno(ePaises* pais)
{
    int resultado = 0;
    int comparo;
    int recuperados;

    comparo = pais->muertos;
    recuperados = pais->recuperados;

    if (comparo ==  recuperados*3)
    {
        resultado = 1;
    }
    return resultado;
}

int ordenar_infectados(void* paisA, void* paisB)
{
    int comparacion = 0;
    int infectadosA;
    int infectadosB;

    if ((pais_getInfectados((ePaises*) paisA, &infectadosA)) &&
            (pais_getInfectados((ePaises*) paisB, &infectadosB)))
    {
        comparacion = infectadosA - infectadosB;
    }
    return comparacion;
}
