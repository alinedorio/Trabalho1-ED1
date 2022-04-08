#include "../include/pacientes.h"
#include "../include/listaP.h"
#include "../include/cuidadores.h"
#include "../include/listaC.h"
#include "../include/amizades.h"
#include "../include/listaA.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct paciente{
    char* nome;
    float temp;
    double lati;
    double longi;
    int queda;
    ListaC* cuidadores;
    ListaA* amigos;

};

void inicializaEDCare(){
    
  
    FILE *arquivoApoio = fopen("data/apoio.txt", "r");

    if (arquivoApoio == NULL)
    {
        printf("Problemas na abertura do arquivo\n");
        exit(1);
    }
    
    char* linha = malloc(sizeof(char)*1000);

    ListaP* p = iniciaListaPacientes();

    fgets(linha,1000,arquivoApoio);
    char* aux;
    //strtok(linha, ";\n");

    char* rest = linha;

    while ((aux = strtok_r(rest, ";\n ", &rest)))
    {
        Paciente* paciente = (Paciente*)malloc(sizeof(Paciente));
        paciente->nome = strdup(aux); 
        paciente->amigos = iniciaListaAmizades();  
        p = insereListaPaciente(p, paciente);
        //aux = strtok(NULL, ";\n");
        //criaSaidaPaciente(paciente);        
    }

    //////////////////////// amizades ////////////////////////////
    criaAmizade(p, arquivoApoio);
    //imprimeListaPaciente(p);

    /////////////////////////// cuidadores ///////////////////////
    
    FILE* arquivoCuidadores = fopen("data/cuidadores.txt", "r");
    if(arquivoCuidadores == NULL)
    {
        printf("Problemas na abertura do arquivo\n");
        exit(1);
    }

    ListaC* c = iniciaListaCuidadores();

    fgets(linha,1000,arquivoCuidadores);
    aux = strtok(linha, ";\n ");
    
    while(aux != NULL){
        
        Cuidadores* cuidador =  iniciaCuidador(aux);
        aux = strtok(NULL, ";\n ");
        c = insereListaCuidador(c, cuidador);
    
    }
    
    linha = fgets(linha,1000,arquivoCuidadores);
    while(linha != NULL){
        aux = strtok(linha, "; ");
        Paciente* paciente = iniciaPaciente(aux);
        paciente = procuraPacienteLista(p, aux);
        paciente->cuidadores = iniciaListaCuidadores();
        aux = strtok(NULL, ";\n ");
            while(aux != NULL && paciente != NULL)
            {
                Cuidadores* cuidador = procuraCuidadorLista(c, aux);
                paciente->cuidadores = insereListaCuidador(paciente->cuidadores, cuidador);
                aux = strtok(NULL, ";\n ");
                
            }
        leDadosPaciente(paciente);
        
    
        linha = fgets(linha, 1000, arquivoCuidadores);
        
        
    }
    fclose(arquivoApoio);
    fclose(arquivoCuidadores);
    destroiListaCuid(c);
    destroiListaPaciente(p);
    free(linha);
}


Paciente* iniciaPaciente(char* nome)
{   
    Paciente* paciente = (Paciente*)malloc(sizeof(Paciente));
    paciente->nome = strdup(nome);
    
        return paciente;
}

char* recuperaNome(Paciente* pac)
{
  return pac->nome;
  
}

void* recuperaListaAmizade(Paciente* pac){

    return pac->amigos;

}

void* retornaCuidadoresPaciente(Paciente* pac){


        return pac->cuidadores;
}


void leDadosPaciente(Paciente* pac){
    
    int qtd_FebreBaixa = 0;

    FILE* filePaciente;
    char* stringAux;
    stringAux = malloc(sizeof(char)*(strlen(recuperaNome(pac))+strlen("data/ ")));
    strcpy(stringAux, "data/");
    strcat(stringAux, recuperaNome(pac));
    strcat(stringAux, ".txt");
        printf("%s\n", stringAux);
        filePaciente = fopen(stringAux, "r");
        if (filePaciente == NULL) 
          {
              printf("erro");
          printf("Problemas na abertura do arquivo\n");
          exit(1);
          }
    char linha[1000];
    int i = 0;

    FILE* arquivoSaida;
    char* stringAux2;
    stringAux2 = malloc(sizeof(char)*(strlen(recuperaNome(pac))+strlen("data/ ")));
            strcpy(stringAux2, "data/");
            strcat(stringAux2, recuperaNome(pac));
            strcat(stringAux2, "-saida.txt");
            arquivoSaida = fopen(stringAux2, "w");
    
    while(fgets(linha, 1000, filePaciente))
    {   
        int aux;
        pac->temp = atof(strdup(strtok(linha, ";")));
        pac->lati = atoi(strdup(strtok(NULL, ";")));
        pac->longi = atoi(strdup(strtok(NULL, ";")));
        pac->queda = atoi(strdup(strtok(NULL, ";\n")));
        
            

        aux = verificaSensores(pac);
          switch (aux)
          {
          case 1:
            fprintf(arquivoSaida, "queda, acionou %s\n", acionaMaisProximo(pac->cuidadores, pac, i));
            
                
              break;
          case 2:
            fprintf(arquivoSaida, "febre alta, acionou %s\n",acionaMaisProximo(pac->cuidadores, pac, i));
                qtd_FebreBaixa = 0;
                break;

          case 3:
                
                if(qtd_FebreBaixa < 3){
                fprintf(arquivoSaida, "febre baixa, acionou amigo %s\n", acionaAmigoMaisProximo(pac->amigos, pac, i));
                qtd_FebreBaixa++;
                }
                 else if(qtd_FebreBaixa == 3){
                fprintf(arquivoSaida, "febre baixa pela quarta vez, acionou %s\n", acionaMaisProximo(pac->cuidadores, pac, i));
                    qtd_FebreBaixa = 0;
                    
                }

                break;

          case 0:
                fprintf(arquivoSaida, "tudo ok\n");

                
                break;

          default:
              break;
          }
           
         i++; 
    }   //destroiListaAmizade(pac->amigos);
        destroiListaCuid(pac->cuidadores);        
        free(stringAux);
        free(stringAux2);
        fclose(filePaciente);
        fclose(arquivoSaida);
}

int verificaSensores(Paciente* pac)
{   
        if(pac->queda == 1){

                return 1;
        }

        else if(pac->temp > 38.0)
        {        
                return 2;
        }
        else if(pac->temp >=37.0 && pac->temp <= 38.0)
        {             
                return 3;
        }
        else if(pac->temp < 37){
           
                return 0;
        }
 
}




void criaSaidaPaciente(Paciente* pac){
    FILE* arquivoSaida;
    char* stringAux;
    stringAux = malloc(sizeof(char)*(strlen(recuperaNome(pac))+strlen("data/ ")));
    strcpy(stringAux, "data/");
    strcat(stringAux, recuperaNome(pac));
    strcat(stringAux, "-saida.txt");
    arquivoSaida = fopen(stringAux, "w");

    free(stringAux);
    fclose(arquivoSaida);

}


/*void imprimeDadosPaciente(Paciente* pac)
{   
    printf("Paciente %s - Dados: \n", pac->nome);
    printf("%f\n%f\n%f\n%d\n", pac->temp, pac->lati, pac->longi, pac->queda);

}*/



float retornaTemp(Paciente* pac){
return pac->temp;
}

double retornaLatitude (Paciente* pac){
return pac->lati;
}

double retornaLongitude (Paciente* pac){
    return pac->longi;
}

int retornaQueda (Paciente* pac){
    return pac->queda;
}


void destroiPaciente(Paciente* p){
    free(p->nome);
    free(p);
}

