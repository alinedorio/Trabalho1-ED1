#ifndef PACIENTES_H
#define PACIENTES_H
#include <stdio.h>
#include "../include/listaC.h"
#include "../include/cuidadores.h"

typedef struct paciente Paciente;


/**
 * @brief Inicializa o programa EDCare
 **/
void inicializaEDCare();

/**
 * @brief Inicia uma struct paciente
 * @param nome - nome do paciente a ter sua struct inicializada
 * @return uma nova struct de paciente
 **/
Paciente* iniciaPaciente(char* nome);

/**
 * @brief Recupera o nome de um paciente
 * @param pac - struct do paciente
 * @return O nome do paciente em questão
 **/
char* recuperaNome(Paciente* pac);

/**
 * @brief Retorna valor de queda do paciente(0 ou 1)
 * @param pac - struct do paciente
 * @return um valor inteiro (0 ou 1)
 **/

/**
 * @brief Lê os dados do arquivo de um paciente, a fim de tratar o mesmo linha a linha 
 * @param pac - struct do paciente
 * @param arquivoCuidadores - arquivo para 
 * @return um valor inteiro (0 ou 1)
 **/
void leDadosPaciente(Paciente* pac);

//void imprimeDadosPaciente(Paciente* pac);

/**
 * @brief Verifica as informações de sensores linha a linha de um paciente, providenciando as medidas necessárias
 * @param pac - struct do paciente
 * @return um valor int para verificação em switch, na leDadosPaciente
 **/
int verificaSensores(Paciente* pac);

/**
 * @brief Cria os arquivos de saída dos pacientes
 * @param pac - struct do paciente
 **/
void criaSaidaPaciente(Paciente* pac);

/**
 * @brief Retorna a temperatura do paciente
 * @param pac - struct do paciente
 * @return o valor da temperatura em float
 **/
float retornaTemp(Paciente* pac);

/**
 * @brief Retorna a lista de amizades de um paciente
 * @param pac - struct do paciente
 **/
void* recuperaListaAmizade(Paciente* pac);

/**
 * @brief Retorna a latitude do paciente
 * @param pac - struct do paciente
 * @return valor da latitude do paciente
 **/
double retornaLatitude (Paciente* pac);

/**
 * @brief Retorna a longitude do paciente
 * @param pac - struct do paciente
 * @return valor da longitude do paciente
 **/
double retornaLongitude (Paciente* pac);

/**
 * @brief Retorna valor de queda do paciente(0 ou 1)
 * @param pac - struct do paciente
 * @return um valor inteiro (0 ou 1)
 **/
int retornaQueda (Paciente* pac);

/**
 * @brief Retorna a lista de cuidadores do paciente
 * @param pac - struct do paciente
 **/
void* retornaCuidadoresPaciente(Paciente* pac);

/**
 * @brief Libera a memoria dos pacientes
 * @param p - struct de paciente
 **/
void destroiPaciente(Paciente* p);

#endif



