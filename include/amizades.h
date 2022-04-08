#ifndef Amizades_h
#define Amizades_h

#include "../include/pacientes.h"
#include "../include/listaP.h"

#include <stdio.h>


typedef struct amizade Amizade;

/**
 * @brief Retorna o nome de um amigo
 * @param a - struct de amigo
 * @return nome do amigo 
 */
char* retornaNomeAmizade(Amizade* a);

/**
 * @brief retorna a latitude de um amigo 
 * @param pac - struct do paciente 
 * @param amigo - struct do amigo desse paciente
 * @return o valor da latitude do amigo
 */
double recuperaLatiAmigo(Amizade* amigo, Paciente* pac);

/**
 * @brief retorna a longitude de um amigo 
 * @param pac - struct do paciente 
 * @param amigo - struct do amigo desse paciente
 * @return o valor da longitude do amigo
 */
double recuperaLongiAmigo(Amizade* amigo, Paciente* pac);

/**
 * @brief Função que é responsável por ler e armazenar as amizades presentes no apoio.txt 
 * @param p - Lista de pacientes 
 * @param arquivoApoio - arquivo apoio.txt para leitura dentro da funçao
 */
void criaAmizade(ListaP* p, FILE* arquivoApoio);

/**
 * @brief inicia uma struct amizade em TAD's onde, alocando da forma convencional, ocasionaria em ciclo de inclusao 
 * @param p - struct de um paciente
 * @return uma struct amizade 
 */
Amizade* iniciaAmizade(Paciente* p);

/**
 * @brief Libera a memoria das amizades
 * @param a - struct de amizade
 **/
 void destroiAmizade(Amizade* a);

#endif