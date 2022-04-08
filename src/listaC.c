#include "../include/listaC.h"
#include "../include/cuidadores.h"
#include "../include/pacientes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct listaC{
  Cuidadores* cuid;
  ListaC* ant;
  ListaC* prox;
};

ListaC* iniciaListaCuidadores()
{
    return NULL;
}

ListaC* insereListaCuidador(ListaC* c, Cuidadores* cuidador){

    ListaC* nova = (ListaC*)malloc(sizeof(ListaC));
    nova->cuid = cuidador;
    nova->ant = NULL;
    nova->prox = c;

    if(c != NULL)
    {
        c->ant = nova;
    }
        
    return nova;
}

void imprimeListaCuid(ListaC* c){
  
   for(c = c; c != NULL; c = c->prox){
    printf("\t%s\n", retornaNomeCuidador(c->cuid));
    }
}

Cuidadores* procuraCuidadorLista(ListaC* c, char* nome){

    for(c= c; c != NULL; c = c->prox){
    if(strcmp(nome,retornaNomeCuidador(c->cuid)) == 0)
    {
        return c->cuid;

    }       
  }
        return NULL;
}

char* acionaMaisProximo(ListaC* c, void* p, int linha){


        Paciente* pac = (Paciente*) p;
        double cuidMaisPerto = 1000000;
        char* nomeCuidMaisPerto;
        FILE* fileCuidadores;
        char* aux;
      for(c= c; c != NULL; c = c->prox){
        
        aux = malloc(sizeof(char)*(strlen(retornaNomeCuidador(c->cuid))+10));
        strcpy(aux, "data/");
        strcat(aux, retornaNomeCuidador(c->cuid));
        strcat(aux, ".txt");
        fileCuidadores = fopen(aux, "r");
             if(fileCuidadores == NULL){
                printf("Problemas na abertura do arquivo\n");
                exit(1);
            }
        char linhaArquivo[200];

        for(int i = 0; i <= linha; i++){

            fgets(linhaArquivo, 200, fileCuidadores);

        }
        double latiCuid, longiCuid, distancia;

        latiCuid = atof(strtok(linhaArquivo, ";"));
        longiCuid = atof(strtok(NULL, "\n"));

        distancia = sqrt(pow((latiCuid - retornaLatitude(pac)), 2) + pow((longiCuid - retornaLongitude(pac)), 2));
            if(distancia < cuidMaisPerto){
                cuidMaisPerto = distancia;
                nomeCuidMaisPerto = retornaNomeCuidador(c->cuid);  

            }
      }

    
            return nomeCuidMaisPerto;
            fclose(fileCuidadores);
            destroiPaciente(pac);
            free(aux);
}


void destroiListaCuid(ListaC* lista){

    ListaC* p = lista;
    ListaC* t;

    while (p!= NULL){
        t = p->prox;
        //destroiCuidador(p->cuid);
        free(p);
        p = t;
    }

}

