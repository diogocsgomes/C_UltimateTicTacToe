//Diogo Cardoso de Sousa Gomes a2021137427

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "library.h"

#include<time.h>
#define N 10
#define AUX 9
#define NOME 20

void testes(char **mat,int tabuleiro,int jogador){
    // funcao para testar as outras funcoes
    //CODIGOS ANTERIORES NO FICHEIRO TESTES_BAUP.TXT
    /*
    mat[0][0] = 'X';
    mat[1][0] = 'X';
    mat[2][0] = 'X';
    mat[3][0] = ' ';
    mat[4][0] = ' ';
    mat[5][0] = ' ';
    for(int i = 6; i < 9; i++)
    {
        for(int j = 0;j < N;j++)
        {
            mat[i][j] = 'X';
        }
    }
    //puts(mat);
int taboleiros_disp = TaboleirosDisponiveis(mat);
    //printf("taboleiros disponiveis: %d",taboleiros_disp);

    printf("Taboleiro: %d\n",tabuleiro +1 );
    printf("E a vez do Jogador: %d\n",jogador);
    //printf("   1   2   3\n");
    //printf(" +____+____+____+\n");
    printf("    %c  |  %c  |  %c \n",mat[tabuleiro][1],mat[tabuleiro][2],mat[tabuleiro][3]);
    printf("  _____|_____|_____\n");

    printf("    %c  |  %c  |  %c \n",mat[tabuleiro][4],mat[tabuleiro][5],mat[tabuleiro][6]);
    printf("  _____|_____|_____\n");

    printf("    %c  |  %c  |  %c \n",mat[tabuleiro][7],mat[tabuleiro][8],mat[tabuleiro][9]);
    ///*printf("  ____|____|____\n");
    printf("       |     |     \n");
*/
    mat[0][0] = 'O';
    mat[1][0] = 'O';
    mat[2][0] = 'O';
}

int main(void)
{
    //char mat[9][N];
    char **mat = criaMat(9,10);
    //testes(mat,0,1);
    int tabuleiro;
    int taboleiros_disponiveis;
    int game_mode;
    int jogador = 1; //jogador = 1 e X Jogador = 2 e O
    int posicao;
    int vitorias = 0;
    int jogo_cheio;
    int vitoria_ultimate = 0;
    //struct jogada k_jogadas;
    p_jogada lista = NULL;
    //int num_jogadas;
    int opcao;
    int k_jogadas;
    FILE Text_file;
    char nome_ficheiro[NOME];
    int auxiliar = 0;
    int i_aux = 0;
    //CriaMatUni(&k_jogadas);

    printf(" BEM VINDO AO JOGO DO GALO \n SELECIONE O SEU MODO DE JOGO\n 1- 1 VS 1\n 2- 1 VS COMPUTADOR\n 3- Carregar Jogo anterior");
    //Text_file = CriaFicheiroTexto();

    do{
        printf("\n Modo de jogo:");
        scanf("%d",&game_mode);
    } while (game_mode < 1 || game_mode > 3);




    do{

        tabuleiro = RandomNumber(8);

    }
    while (tabuleiro < 0 || tabuleiro > 8);

    if(game_mode == 3)
    {
        lista = LerBinario(&game_mode,&i_aux);
        InsereJogadasAnteriores(&jogador,lista, mat,&tabuleiro);

    }


        for (int i = i_aux, num_jogadas = i; i < N * N, vitoria_ultimate != 1; i++) {



            jogo_cheio = TabuleiroCheio(mat, tabuleiro);

            taboleiros_disponiveis = TaboleirosDisponiveis(mat);

            if (taboleiros_disponiveis == 0) {
                vitoria_ultimate = Ultimate(mat, jogador);
                break;
            }

            if (jogo_cheio == 1 || mat[tabuleiro][0] != ' ') {

                do {
                    tabuleiro = RandomNumber(8);
                } while (TabuleiroCheio(mat, tabuleiro) == 1 || mat[tabuleiro][0] != ' '); // EVITA QUE O PROGRAMA ENVIE OS JOGADORES PARA JOGOS QUE JA ACABARAM OU QUE JA FORAM GANHOS
            }


            PrintTabuleiro(mat, tabuleiro, jogador);

        //PEDIR JOGADA AO UTILIZADOR
            if(game_mode == 2 && jogador == 2){
                //random
                do{
                    posicao = RandomNumber(8);
                    posicao += 1;
                } while (mat[tabuleiro][posicao] != ' ');
            }
            else {
                do {
                    printf("\nPosicao: ");
                    scanf("%d", &posicao);

                } while (mat[tabuleiro][posicao] != ' ' || posicao < 1 || posicao > 9);
            }

            //funcao para inserir jogada

            InsereJogada(mat, tabuleiro, posicao, jogador);
            num_jogadas +=1;

            lista = Adiciona_Jogada( lista, jogador, tabuleiro,posicao);



            //MENU
            if(num_jogadas > 0 && game_mode!=2 ||jogador != 2 ) {
                do {

                    printf("\nContinuar o jogo ------------- 1 \n Mostrar K jogadas anteriores - 2 \n "
                           "Sair ------------------------- 3 \n opcao: ");

                    scanf("%d", &opcao);
                } while (opcao < 1 || opcao > 3);


                switch (opcao) {
                    case 1:;
                        break;
                    case 2:
                        do{
                            printf("Quantas jogadas quer verificar? ");
                            scanf("%d",&k_jogadas);
                        }
                        while (k_jogadas <= 0 || k_jogadas > num_jogadas || k_jogadas > 10);

                        Print_K_jogadas(lista,k_jogadas,num_jogadas);

                        break;
                    case 3:

                        do{

                            auxiliar = 0;

                            printf("\n   Introduza um nome para o ficheiro de texto: ");
                            scanf(" %20[^\n]", nome_ficheiro);

                            for(int i = 0; nome_ficheiro[i] != '\0'; i++)
                            {
                                if(nome_ficheiro[i] == 92 ||  nome_ficheiro[i] == '/' || nome_ficheiro[i] == ':' || nome_ficheiro[i] == '*' || nome_ficheiro[i] == '?' || nome_ficheiro[i]== '"' || nome_ficheiro[i] == '<' || nome_ficheiro[i] =='>' || nome_ficheiro[i] == '|')
                                {
                                    auxiliar = 1;
                                    break;
                                }
                            }

                        }while(auxiliar);

                        strcat(nome_ficheiro,".txt");

                        Text_file = CriaFicheiroTexto(nome_ficheiro);
                        AdicionaJogadaTexto(&Text_file,lista,nome_ficheiro);
                        CriarFicheiroBinario(lista,game_mode);


                        printf("Adeus :)");
                        Liberta_jogadas(lista);
                        libertaMat(mat,9);
                        //ENTER TO LEAVE
                        char y;
                        scanf("%c", &y);
                        scanf("%c", &y);
                        exit(0);
                        break;
                }
            }


            VerificaVitoriaTabuleiro(mat, tabuleiro, &vitorias, posicao);

            if (taboleiros_disponiveis == 1) {
                tabuleiro = tabuleiro;
            } else {
                tabuleiro = posicao - 1;
            }


            vitoria_ultimate = Ultimate(mat, jogador);
            //trocar jogador
            if (vitoria_ultimate == 0) {
                TrocaJogador(&jogador);
            }

            // FIM DO CICLO FOR
        }



        if (vitoria_ultimate == 1 && game_mode == 1) {

            printf("Vitoria para o jogador: %d", jogador);

            //print taboleiro
        }
        else if(vitoria_ultimate == 1 && game_mode == 2)
        {
            if(jogador == 1) {
                printf("Vitoria para o jogador: 1");

            }
            if(jogador == 2)
            {
                printf("Vitoria para o computador");
            }
        }
        else {
            printf("Ninguem ganhou");
        }



    Liberta_jogadas(lista);
    libertaMat(mat,9);
//ENTER TO LEAVE
    char x;
    scanf("%c", &x);
    scanf("%c", &x);
}
//TO DO LIST
//Funcao para verificar se o taboleiro esta cheio DONE :)
//funcao para verificar vitoria de um taboleiro DONE :)
//Funcao para verificar vitoria ultimate PRATICAMENTE FEIRO SO FALTA INCORPORAR NO MAIN() DONE :)
//single game finalizor DONE :)


//User Interface atualizada
//Jogador automatico(computador) done :)
// Estrutura que gurada as jogadas do jogadores {int jogador, int tabooleiro,int posicao}DONE :)

//guarrdar as jogadoas num ficheiro binario DONE :)
//Guardar o jogo num ficheiro de texto DONE :)

//dispor lateralmente o tabuleiro ultimate (opcional)


