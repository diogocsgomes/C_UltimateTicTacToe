//
// Created by diogo on 17/05/2022.
//Diogo Cardoso de Sousa Gomes a2021137427
//
#include "library.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define AUX 9
#define N 10
#define test 20
#define NOME 20

void libertaMat(char** p, int nLin){

    int i;

    for(i=0; i<nLin; i++)
        free(p[i]);
    free(p);
}

char** criaMat(int nLin, int nCol){
    char **p = NULL;
    int i, j;

    p = malloc(sizeof(char*) * nLin);
    if(p == NULL) {
        printf("Erro na alocacao de memoria");
        return NULL;
    }

    for(i=0; i<nLin; i++){
        p[i] = malloc(sizeof(char) * nCol);
        if(p[i] == NULL){
            libertaMat(p, i-1);
            return NULL;
        }
        for(j=0; j<nCol; j++)
            p[i][j] = ' ';
    }

    return p;
}

int lista_vazia(p_jogada p){

    if(p == NULL){
        return 1;
    } else{
        return 0;
    }
}

void RegistarJogada(p_jogada p, int jogador, int tabuleiro, int posicao){
    p->jogador = jogador;
    p->tabuleiro = tabuleiro;
    p->posicao = posicao;
    p->prox = NULL;
}

p_jogada Adiciona_Jogada(p_jogada p,int jogador,int tabuleiro,int posicao){


    p_jogada novo,aux;

    novo = malloc(sizeof(jogada));

    if(novo == NULL){
        printf("Erro na alocacao de memoria");
        return p;
    }
    // preencher lista

    RegistarJogada(novo,jogador,tabuleiro,posicao);

    if(p == NULL)
    {
        aux = novo;
        p = aux; // p----> novo

       // p = novo;
    } else{
        aux = p;  //aux---> p

        while (aux->prox != NULL)
        {

            aux = aux->prox;
        }
        aux->prox = novo;

    }

    return p;
}

void Print_K_jogadas(p_jogada p,int k_jogadas,int num_jogadas){
    int aux = 0;
    while (p != NULL )
    {
        if(aux >= num_jogadas-k_jogadas){
        printf("\n Jogador:  %d Tabuleiro: %d Posicao: %d"
               ,p->jogador,p->tabuleiro + 1,p->posicao);
        }
        p = p->prox;
        aux++;
        //printf("AUX: %d  K_J: %d",aux,k_jogadas);
    }
}

void Liberta_jogadas(p_jogada p){
    p_jogada aux;
    while(p != NULL)
    {
        aux = p;
        p = p->prox;
        free(aux);
    }
}

void PrintTabuleiro(char **mat,int taboleiro,int jogador)
{
    system("cls");
    printf("\nTabuleiro: %d\n",taboleiro +1 );
    printf("E a vez do Jogador: %d\n",jogador);
    //printf("   1   2   3\n");
    //printf(" +____+____+____+\n");
 /*   printf("    %c  |  %c  |  %c \n",mat[tabuleiro][1],mat[tabuleiro][2],mat[tabuleiro][3]);
    printf("  _____|_____|_____\n");

    printf("    %c  |  %c  |  %c \n",mat[tabuleiro][4],mat[tabuleiro][5],mat[tabuleiro[6]);
    printf("  _____|_____|_____\n");

    printf("    %c  |  %c  |  %c \n",mat[tabuleiro][7],mat[tabuleiro][8],mat[tabuleiro][9]);
    printf("  ____|____|____\n");
    printf("       |     |     \n");
    */
    printf("\n %c %c %c | %c %c %c | %c %c %c ",mat[0][1],mat[0][2],mat[0][3],  mat[1][1],mat[1][2],mat[1][3],  mat[2][1],mat[2][2],mat[2][3]);
    printf("\n %c %c %c | %c %c %c | %c %c %c ",mat[0][4],mat[0][5],mat[0][6],  mat[1][4],mat[1][5],mat[1][6],  mat[2][4],mat[2][5],mat[2][6]);
    printf("\n %c %c %c | %c %c %c | %c %c %c ",mat[0][7],mat[0][8],mat[0][9],  mat[1][7],mat[1][8],mat[1][9],  mat[2][7],mat[2][8],mat[2][9]);
    printf("\n-------|-------|-------");
    printf("\n %c %c %c | %c %c %c | %c %c %c ",mat[3][1],mat[3][2],mat[3][3],  mat[4][1],mat[4][2],mat[4][3],  mat[5][1],mat[5][2],mat[5][3]);
    printf("\n %c %c %c | %c %c %c | %c %c %c ",mat[3][4],mat[3][5],mat[3][6],  mat[4][4],mat[4][5],mat[4][6],  mat[5][4],mat[5][5],mat[5][6]);
    printf("\n %c %c %c | %c %c %c | %c %c %c ",mat[3][7],mat[3][8],mat[3][9],  mat[4][7],mat[4][8],mat[4][9],  mat[5][7],mat[5][8],mat[5][9]);
    printf("\n-------|-------|-------");
    printf("\n %c %c %c | %c %c %c | %c %c %c ",mat[6][1],mat[6][2],mat[6][3],  mat[7][1],mat[7][2],mat[7][3],  mat[8][1],mat[8][2],mat[8][3]);
    printf("\n %c %c %c | %c %c %c | %c %c %c ",mat[6][4],mat[6][5],mat[6][6],  mat[7][4],mat[7][5],mat[7][6],  mat[8][4],mat[8][5],mat[8][6]);
    printf("\n %c %c %c | %c %c %c | %c %c %c ",mat[6][7],mat[6][8],mat[6][9],  mat[7][7],mat[7][8],mat[7][9],  mat[8][7],mat[8][8],mat[8][9]);
    //printf("\n-------|-------|-------");
}

void InsereJogada(char **mat,int tabuleiro,int posicao,int jogador){
    if(jogador == 1)
    {
        mat[tabuleiro][posicao] = 'X';
    }
    if(jogador == 2)
    {
        mat[tabuleiro][posicao] = 'O';
    }
}

void TrocaJogador(int *jogador){
    switch (*jogador) {
        case 1:
            *jogador = 2;
            break;
        case 2:
            *jogador = 1;
            break;

    }
}

int TabuleiroCheio(char **mat,int tabuleiro){
    int empty_count = 0;
    for(int i = 1;i < N; i++){
        if(mat[tabuleiro][i] == ' ')
        {
            empty_count++;
        }
    }
    if(empty_count == 0)
    {

        return 1;// retorna 1 se estiver cheio
    }
    else{

        return 0; // retorna 0 se estiver vazio
    }

}

int RandomNumber(int max){
    int random;
    srand(time(NULL));// determina o tempo como a seed da funcao rand()
    do {
        random = rand();
    }while(random > max);
    // printf("random: %d",random);
    return random;
}

int VerificaVitoriaTabuleiro(char **mat,int tabuleiro,int * vitorias,int posicao){

    char caracter = mat[tabuleiro][posicao];

    int linha = 0;

    // puts(caracter);
    //COLUNA
    if(posicao <= 3)//1 linha
    {
        if(mat[tabuleiro][posicao + 3] == caracter && mat[tabuleiro][posicao + 6] == caracter )
        {
            mat[tabuleiro][0] = caracter;

        }
    }
    if(posicao > 3 && posicao <= 6)//2 linha
    {
        if(mat[tabuleiro][posicao - 3] == caracter && mat[tabuleiro][posicao + 3] == caracter)
        {
            mat[tabuleiro][0] = caracter;
        }
    }
    if(posicao > 6 && posicao <= 9)//3 linha
    {
        if(mat[tabuleiro][posicao - 3] == caracter && mat[tabuleiro][posicao - 6] == caracter)
        {
            mat[tabuleiro][0] = caracter;
        }
    }
    //LINHA
    if(posicao <= 3)//1 linha
    {
        for(int i = 1; i <= 3; i++)
        {
            if(mat[tabuleiro][i] != caracter)
            {
                break;
            }
            else{
                linha += 1;
            }
        }
        if(linha == 3)
        {
            mat[tabuleiro][0] = caracter;
            // printf("%c",mat[taboleiro][0]);
        }
    }
    if(posicao > 3 && posicao <= 6)//2 linha
    {
        for(int i = 4; i <= 6; i++)
        {
            if(mat[tabuleiro][i] != caracter)
            {
                break;
            }
            else{
                linha += 1;
            }
        }
        if(linha == 3)
        {
            mat[tabuleiro][0] = caracter;
        }
    }
    if(posicao > 6 && posicao <= 9)//3 linha
    {
        for(int i = 7; i <= 9; i++)
        {
            if(mat[tabuleiro][i] != caracter)
            {
                break;
            }
            else{
                linha += 1;
            }
        }
        if(linha == 3)
        {
            mat[tabuleiro][0] = caracter;
        }
    }

    //DIAGONAIS
    //esquerda a para a direita

    if(posicao == 1)
    {
        if(mat[tabuleiro][posicao + 4] == caracter && mat[tabuleiro][posicao + 8] == caracter )
        {
            mat[tabuleiro][0] = caracter;
        }
    }
    if(posicao == 5)
    {
        if(mat[tabuleiro][posicao - 4] == caracter && mat[tabuleiro][posicao + 4] == caracter )
        {
            mat[tabuleiro][0] = caracter;
        }
    }
    if(posicao == 9)
    {
        if(mat[tabuleiro][posicao - 4] == caracter && mat[tabuleiro][posicao - 8] == caracter )
        {
            mat[tabuleiro][0] = caracter;
        }
    }
    //direita para a esquerda
    if(posicao == 3)
    {
        if(mat[tabuleiro][posicao + 2] == caracter && mat[tabuleiro][posicao + 4] == caracter )
        {
            mat[tabuleiro][0] = caracter;
        }
    }
    if(posicao == 5)
    {
        if(mat[tabuleiro][posicao + 2] == caracter && mat[tabuleiro][posicao - 2] == caracter )
        {
            mat[tabuleiro][0] = caracter;
        }
    }
    if(posicao == 7)
    {
        if(mat[tabuleiro][posicao - 2] == caracter && mat[tabuleiro][posicao - 4] == caracter )
        {
            mat[tabuleiro][0] = caracter;
        }
    }

    if(mat[tabuleiro][0] == caracter)
    {
        return 1;
    } else{
        return 0;
    }
}

int LinhaUltimate(char caracter,char **mat,int posicao){
    int linha = 0;
    int vitoria = 0;
    if(posicao <= 2)//1 linha
    {
        for(int i = 0; i <= 2; i++)
        {
            if(mat[i][0] != caracter)
            {
                break;
            }
            else{
                linha += 1;
            }
        }
        if(linha == 3)
        {
            //mat[0][0] = caracter;2
            vitoria = 1;

        }
    }
    if(posicao > 2 && posicao <= 5)//2 linha
    {
        for(int i = 3; i <= 5; i++)
        {
            if(mat[i][0] != caracter)
            {
                break;
            }
            else{
                linha += 1;
            }
        }
        if(linha == 3)
        {
            //mat[0][0] = caracter;
            vitoria = 1;

        }
    }
    if(posicao > 5 && posicao <= 8)//3 linha
    {
        for(int i = 6; i <= 8; i++)
        {
            if(mat[i][0] != caracter)
            {
                break;
            }
            else{
                linha += 1;
            }
        }
        if(linha == 3)
        {
            //mat[0][0] = caracter;
            vitoria = 1;

        }
    }
    if(vitoria == 1)
    {
        return 1;
    }
    else{
        return 0;
    }
}

int ColunaUltimate(char caracter,char **mat,int posicao){
    int vitoria = 0;
    if(posicao <= 3)//1 linha
    {
        if(mat[posicao + 3][0] == caracter && mat[posicao + 6][0] == caracter )
        {
            vitoria = 1;

        }
    }
    if(posicao > 3 && posicao <= 6)//2 linha
    {
        if(mat[posicao - 3][0] == caracter && mat[posicao + 3][0] == caracter)
        {
            vitoria = 1;

        }
    }
    if(posicao > 6 && posicao <= 9)//3 linha
    {
        if(mat[posicao - 3][0] == caracter && mat[posicao - 6][0] == caracter)
        {
            vitoria = 1;

        }
    }
    if(vitoria == 1)
    {
        return 1;
    }
    else{
        return 0;
    }

}

int HorizontalUltimate(char caracter,char **mat,int posicao){
    int vitoria = 0;
    //esquerda a para a direita

    if(posicao == 0)
    {
        if(mat[posicao + 4][0] == caracter && mat[posicao + 8][0] == caracter )
        {
            vitoria = 1;

        }
    }
    if(posicao == 4)
    {
        if(mat[posicao - 4][0] == caracter && mat[posicao + 4][0] == caracter )
        {
            vitoria = 1;

        }
    }
    if(posicao == 8)
    {
        if(mat[posicao - 4][0] == caracter && mat[posicao - 8][0] == caracter )
        {
            vitoria = 1;

        }
    }
    //direita para a esquerda
    if(posicao == 2)
    {
        if(mat[posicao + 2][0] == caracter && mat[posicao + 4][0] == caracter )
        {
            vitoria = 1;

        }
    }
    if(posicao == 4)
    {
        if(mat[posicao + 2][0] == caracter && mat[posicao - 2][posicao - 2] == caracter )
        {
            vitoria = 1;

        }
    }
    if(posicao == 6)
    {
        if(mat[posicao - 2][0] == caracter && mat[posicao - 4][0] == caracter )
        {
            vitoria = 1;

        }
    }
    if(vitoria == 1)
    {
        return 1;
    }
    else{
        return 0;
    }


}

int Ultimate(char **mat,int jogador){
    int vitoria = 0;

    char caracter1 = 'X';
    char caracter2 = 'O';
    int posicao_x;
    int posicao_o;

    for(int i = 0; i < 9; i++)
    {
        if(mat[i][0] == 'X')
        {
            posicao_x = i;
            if(LinhaUltimate(caracter1,mat,posicao_x) == 1 ||ColunaUltimate(caracter1,mat,posicao_x) == 1 || HorizontalUltimate(caracter1,mat,posicao_x) == 1)
            {
                vitoria = 1;

                break;
            }

        }
        if(mat[i][0] == 'O')
        {
            posicao_o = i;
            if(LinhaUltimate(caracter2,mat,posicao_o) == 1 ||ColunaUltimate(caracter2,mat,posicao_o) == 1 || HorizontalUltimate(caracter2,mat,posicao_o) == 1)
            {
                vitoria = 1;
                break;
            }

        }


    }


    if(vitoria == 1)
    {

        return 1;
    }
    else{

        return 0;

    }
}

int TaboleirosDisponiveis(char **mat){
    int taboleiros_disp = 8;
    int aux;
    int aux_mat[AUX];
    int a = 0;
    int taboleiro;

    for(int i = 0; i < 8;i++)
    {
        if(mat[i][0] != ' ')
        {
            taboleiros_disp --;

        }
        if(mat[i][0] == ' ')
        {
            aux_mat[a] = i;
            a++;

        }

    }


    for(int j = 0,aux = 0; j < a;j++)
    {


        aux = TabuleiroCheio(mat,aux_mat[j]);

        if(aux == 1)
        {
            taboleiros_disp --;

        }

    }

    return taboleiros_disp;

}

FILE CriaFicheiroTexto(char nome_ficheiro[NOME]){
    FILE *TextPointer;

    TextPointer = fopen(nome_ficheiro,"w");


    if(TextPointer == NULL)
    {
        printf("Erro na criação do ficheiro");
        exit(1);
    }
    fclose(TextPointer);
    return *TextPointer;
}

void AdicionaJogadaTexto(FILE *Text_file,p_jogada p,char nome_ficheiro[NOME]){

    Text_file = fopen(nome_ficheiro,"a");
    //fprintf(Text_file,"\nJogador: %d; Tabuleiro: %d;Posicao: %d ",jogador,tabuleiro,posicao);
    while (p != NULL )
    {
        fprintf(Text_file,"\nJogador: %d - Tabuleiro: %d - Posicao: %d ",p->jogador,p->tabuleiro + 1,p->posicao);


        p = p->prox;

        //printf("AUX: %d  K_J: %d",aux,k_jogadas);
    }
    fclose(Text_file);
}

int CriarFicheiroBinario(p_jogada p, int game_mode)
{
    FILE *ficheiro_binario;
    ficheiro_binario = fopen("LastGame.bin", "wb+");

    if(ficheiro_binario == NULL){
        printf("Erro na criacao do ficheiro");
        fclose(ficheiro_binario);
        return 0;
    }
    else{
        fwrite(&game_mode , sizeof(int) , 1 , ficheiro_binario);
        p_jogada aux = p;
        int teste = 0;
        do{
            fwrite(aux, sizeof(jogada), 1, ficheiro_binario);

            aux = aux->prox;


        } while (aux != NULL);


        fclose(ficheiro_binario);
    }

    return 1;
}

p_jogada LerBinario(int *game_mode,int *i_aux){
    p_jogada lista = NULL;

    p_jogada novo;

    p_jogada aux;

    jogada NovoAux;

    FILE* ficheiro_binario = fopen("LastGame.bin", "rb");

    if(ficheiro_binario == NULL) {
        fclose(ficheiro_binario);
        printf("O ficheiro nao existe\n");
        return NULL;
    }

    fread(game_mode, sizeof(int), 1, ficheiro_binario);

    while(fread(&NovoAux, sizeof(jogada), 1, ficheiro_binario))
    {
        novo = malloc(sizeof(jogada));
        novo->prox = NULL;

        if(novo == NULL) {
            printf("Erro na alocacao de memoria");
            return NULL;
        }

        *novo = NovoAux;

        if(lista == NULL) {
            aux = novo; //aux--> novo
            lista = aux; //lista --> aux

            // lista ----> aux ---> novo

        }else {

            aux->prox = novo;
            aux = aux->prox;

        }

        (*i_aux)++; // contador para o loop principal
    }
    fclose(ficheiro_binario);


    return lista;
}

void InsereJogadasAnteriores(int *jogador,p_jogada p, char **mat,int *tabuleiro){

    int last_player;
    int last_tabuleiro;
    int  last_posicao;
    p_jogada last_p;

    do
    {
        if(p->jogador == 1)
        {
            mat[p->tabuleiro][p->posicao] = 'X';
        }
        if(p->jogador == 2)
        {
            mat[p->tabuleiro][p->posicao] = 'O';
        }


        p = p->prox;
        last_p = p;
        last_player = p->jogador;
        last_tabuleiro = p->tabuleiro;
        last_posicao = p->posicao;

    }while (p->prox != NULL);


    *tabuleiro = last_posicao - 1;


    if(last_player == 1)
    {
        mat[last_tabuleiro][last_posicao] = 'X';
       // printf("TAB: %d  Pos: %d",last_tabuleiro,last_posicao);
        *jogador = 2;
    }
    else if(last_player == 2)
    {
        mat[last_tabuleiro][last_posicao] = 'O';
        //printf("TAB: %d  Pos: %d",last_tabuleiro,last_posicao);
        *jogador = 1;
    }

}

