//
// Created by diogo on 17/05/2022.
//
//Diogo Cardoso de Sousa Gomes a2021137427
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#define AUX 9
#define N 10
#define NOME 20

#ifndef ULTIMATE_TIC_TAC_TOE_LIBRARY_H
#define ULTIMATE_TIC_TAC_TOE_LIBRARY_H


typedef struct jogadas jogada, *p_jogada;
struct jogadas{
    int jogador;
    int tabuleiro;
    int posicao;
    p_jogada prox;
};

void libertaMat(char** p, int nLin);

char** criaMat(int nLin, int nCol);

int lista_vazia(p_jogada p);

void RegistarJogada(p_jogada p, int jogador, int tabuleiro, int posicao);

p_jogada Adiciona_Jogada(p_jogada p,int jogador,int tabuleiro,int posicao);

void Print_K_jogadas(p_jogada p,int k_jogadas,int num_jogadas);

void Liberta_jogadas(p_jogada p);


void PrintTabuleiro(char **mat,int tabuleiro,int jogador);

void InsereJogada(char **mat,int tabuleiro,int posicao,int jogador);

void TrocaJogador(int *jogador);

int TabuleiroCheio(char **mat,int tabuleiro);

int RandomNumber(int max);

int VerificaVitoriaTabuleiro(char **mat,int tabuleiro,int * vitorias,int posicao);

int LinhaUltimate(char caracter,char **mat,int posicao);

int ColunaUltimate(char caracter,char **mat,int posicao);

int HorizontalUltimate(char caracter,char **mat,int posicao);

int Ultimate(char **mat,int jogador);

int TaboleirosDisponiveis(char **mat);

FILE CriaFicheiroTexto(char nome_ficheiro[NOME]);

//void AdicionaJogadaTexto(FILE *Text_file,int jogador,int tabuleiro, int posicao);
void AdicionaJogadaTexto(FILE *Text_file,p_jogada p,char nome_ficheiro[NOME]);


int CriarFicheiroBinario(p_jogada p, int game_mode);

p_jogada LerBinario(int *game_mode,int *i_aux);

void InsereJogadasAnteriores(int *jogador,p_jogada p,char **mat,int *tabuleiro);

//void Salvar_binario();

#endif //ULTIMATE_TIC_TAC_TOE_LIBRARY_H
