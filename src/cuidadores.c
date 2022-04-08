#include "../include/cuidadores.h"
#include "../include/listaC.h"
#include "../include/pacientes.h"
#include "../include/listaP.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct cuidadores
{
    char *nome;     
    double lati;
    double longi;
    //double distancia;

};

Cuidadores* iniciaCuidador(char* nome)
{   
    Cuidadores* cuidador = (Cuidadores*)malloc(sizeof(Cuidadores));
    cuidador->nome = strdup(nome);
    
        return cuidador;
}



char* retornaNomeCuidador(Cuidadores* c)
{
        return c->nome;

}

void destroiCuidador(Cuidadores* c){
  free(c->nome);
  free(c);
}

double retornaLatiCuidador(Cuidadores* cuid){

        return cuid->lati;


}

double retornaLongiCuidador(Cuidadores* cuid){

        return cuid->longi;
}