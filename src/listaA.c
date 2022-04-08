#include "../include/listaA.h"
#include "../include/listaP.h"
#include "../include/amizades.h"
#include "../include/pacientes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct celAmiz CelulaAmiz;

struct celAmiz{
  Amizade* amizade;
  CelulaAmiz* prox;

};

struct listaA{
  CelulaAmiz* prim;
  CelulaAmiz* ult;
};

ListaA* iniciaListaAmizades(){
  ListaA* amizade = (ListaA*)malloc(sizeof(ListaA));
  amizade->prim = NULL;
  amizade->ult = NULL;

  return amizade;
}

ListaA* insereListaAmizade(ListaA* l, Amizade* amizade)
{
  CelulaAmiz* nova = (CelulaAmiz*)malloc(sizeof(CelulaAmiz));
  nova->amizade = amizade;
  nova->prox = NULL;

  if(l->prim == NULL)
  {
    l->prim = nova;
  }

  if(l->ult != NULL)
  {
    l->ult->prox = nova;
  }
  
  l->ult = nova;
}


char* acionaAmigoMaisProximo(ListaA* l, Paciente* pac, int linha){

        CelulaAmiz* a;
        int amigoMaisPerto = 1000000;
        char* nomeAmigoMaisPerto;
        FILE* fileAmigos;
        char* aux;
      for(a= l->prim; a != NULL; a = a->prox){
        
        aux = malloc(sizeof(char)*(strlen(retornaNomeAmizade(a->amizade))));
        strcpy(aux, "data/");
        strcat(aux, retornaNomeAmizade(a->amizade));
        strcat(aux, ".txt");
        fileAmigos = fopen(aux, "r");
             if(fileAmigos == NULL){
                printf("Problemas na abertura do arquivo\n");
                exit(1);
            }
        char linhaArquivo[200];

        for(int i = 0; i <= linha; i++){

            fgets(linhaArquivo, 200, fileAmigos);

        }
        double latiAmigo, longiAmigo;
        int queda;
        float temp;
        double distancia;

        temp = atof(strtok(linhaArquivo, ";"));
        latiAmigo = atof(strtok(NULL, ";"));
        longiAmigo = atof(strtok(NULL, ";"));
        queda = atoi(strtok(NULL, ";\n "));

        distancia = sqrt(pow((latiAmigo - retornaLatitude(pac)), 2) + pow((longiAmigo - retornaLongitude(pac)), 2));
            if(distancia < amigoMaisPerto){
                amigoMaisPerto = distancia;
                nomeAmigoMaisPerto = retornaNomeAmizade(a->amizade);  

            }
      }
   
            return nomeAmigoMaisPerto;
            fclose(fileAmigos);
            free(aux);
}


void destroiListaAmizade(ListaA* l)
{
  CelulaAmiz* p = l->prim;
  CelulaAmiz* t;

  while(p != NULL){
    t = p->prox;
    destroiAmizade(p->amizade);
    free(p);
    p = t;
  }
  free(l);
}