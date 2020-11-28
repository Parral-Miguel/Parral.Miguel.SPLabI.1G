#ifndef ENTIDADES_H_INCLUDED
#define ENTIDADES_H_INCLUDED
#include "LinkedList.h"

typedef struct
{
    int id;
    char pais[128];
    int recuperados;
    int infectados;
    int muertos;
}ePaises;

ePaises* pais_nuevo();

int pais_setId(ePaises* pais,int id);
int pais_getId(ePaises* pais,int* id);

int pais_setPais(ePaises* pais,char* paisNombre);
int pais_getPais(ePaises* pais,char* paisNombre);

int pais_setRecuperados(ePaises* pais,int recuperados);
int pais_getRecuperados(ePaises* pais,int* recuperados);

int pais_setInfectados(ePaises* pais,int infectados);
int pais_getInfectados(ePaises* pais,int* infectados);

int pais_setMuertos(ePaises* pais,int muertos);
int pais_getMuertos(ePaises* pais,int* muertos);

ePaises* asignar_estadisticas(ePaises* pais);

int filtrar_exito(ePaises* pais);
int filtrar_horno(ePaises* pais);

int ordenar_infectados(void* paisA, void* PaisB);

#endif // ENTIDADES_H_INCLUDED
