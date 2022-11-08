#include <stdlib.h>
#include <stdio.h>
#define AC_BLACK "\x1b[30m"
#define AC_RED "\x1b[31m"
#define AC_GREEN "\x1b[32m"
#define AC_YELLOW "\x1b[33m"
#define AC_BLUE "\x1b[34m"
#define AC_MAGENTA "\x1b[35m"
#define AC_CYAN "\x1b[36m"
#define AC_WHITE "\x1b[37m"
#define AC_NORMAL "\x1b[m"

//tira a cor

typedef struct jogada{
    int jogada1;
}jogada;

void reset () 
{
  printf("\033[0m");
}


void print_tabela_vazia(char * tabela)
{
     
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", tabela[1], tabela[2], tabela[3]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", tabela[4], tabela[5], tabela[6]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", tabela[7], tabela[8], tabela[9]);

    printf("     |     |     \n\n");
}

void print_tabela(char * tabela)
{
    
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", tabela[1], tabela[2], tabela[3]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", tabela[4], tabela[5], tabela[6]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", tabela[7], tabela[8], tabela[9]);

    printf("     |     |     \n\n");
}


int acabou(char * tabela)
{
    if (tabela[1] == tabela[2] && tabela[2] == tabela[3])
        return 1;
        
    else if (tabela[4] == tabela[4] && tabela[5] == tabela[6])
        return 1;
        
    else if (tabela[7] == tabela[8] && tabela[8] == tabela[9])
        return 1;
        
    else if (tabela[1] == tabela[4] && tabela[4] == tabela[7])
        return 1;
        
    else if (tabela[2] == tabela[5] && tabela[5] == tabela[8])
        return 1;
        
    else if (tabela[3] == tabela[6] && tabela[6] == tabela[9])
        return 1;
        
    else if (tabela[1] == tabela[5] && tabela[5] == tabela[9])
        return 1;
        
    else if (tabela[3] == tabela[5] && tabela[5] == tabela[7])
        return 1;
        
    else if (tabela[1] != '1' && tabela[2] != '2' && tabela[3] != '3' &&
        tabela[4] != '4' && tabela[5] != '5' && tabela[6] != '6' && tabela[7] 
        != '7' && tabela[8] != '8' && tabela[9] != '9')

        return 0;
    else
        return  - 1;

}

void verifica_jogada(int jogada)
{
    if(jogada > 9 || jogada < 0)
    {
        fprintf(stderr, "%sJogada inválida!\n", AC_RED);
        exit(1);
    }
}

void jogar(char * tabela)
{
    int jogada1, jogada2;

    for(;;)
    {
        printf("Jogador1:");
        scanf("%d", &jogada1);
        verifica_jogada(jogada1);
        tabela[jogada1] = 'x';
        if(acabou(tabela)!=-1 && acabou(tabela)!=0)
        {
            printf("%sO jogador 1 ganhou!\n", AC_CYAN);
            print_tabela(tabela);
            exit(0);
        }
        print_tabela(tabela);
        if(acabou(tabela)==0)
        {
            printf("Empate!\n");
            exit(0);
        }

        printf("Jogador2:");
        scanf("%d", &jogada2);
        tabela[jogada2] = 'o';
        if(acabou(tabela)!=-1)
        {
            printf("%sO jogador 2 ganhou!\n", AC_GREEN);
            print_tabela(tabela);
            exit(0);
        }

        print_tabela(tabela);

    }
}

void human_move(char * tabela, jogada * jogada)
{
    reset();
    printf("Jogador1:");
    scanf("%d", &jogada->jogada1);
    int aux = jogada->jogada1;
    verifica_jogada(aux);
    tabela[jogada->jogada1] = 'o';
    
}

void computer_move(char * tabela, int n)
{
    tabela[n] = 'x';
    printf("%sComputador:\n", AC_RED);
    print_tabela(tabela);
}

void print_computer_win()
{
    printf("%sO computador venceu!\n", AC_RED);
    exit(0);
}

void print_empate()
{
    printf("%sPosição leva a empate. Parabéns, não perdeste!\n", AC_MAGENTA);
    exit(0);
}







void jogar_computador(char * tabela)
{
    jogada jogada;
    jogada.jogada1 = 0;
    //jogada incial
    tabela[9] = 'x';
    print_tabela(tabela);
    human_move(tabela, &jogada);

/////////////////////////////////////////////////////////    
    if(jogada.jogada1 == 1)
    {
        computer_move(tabela, 7);
        human_move(tabela, &jogada);
        if(jogada.jogada1 == 8)
        {
            computer_move(tabela, 3);
            human_move(tabela, &jogada);
            if(jogada.jogada1 == 5)
            {
                computer_move(tabela, 6);
                print_computer_win;
            }
            else
            {
                computer_move(tabela, 5);
                print_computer_win;
            }
        }
        else
        {
            computer_move(tabela, 8);
            print_computer_win();
        }
    }
//////////////////////////////////////////////////////////
    if(jogada.jogada1 == 2)
    {
        computer_move(tabela, 5);
        human_move(tabela, &jogada);
        if(jogada.jogada1 == 1)
        {
            computer_move(tabela, 3);
            human_move(tabela, &jogada);
            if(jogada.jogada1 == 7)
            {
                computer_move(tabela, 6);
                print_computer_win();
            }
            else
            {
                computer_move(tabela, 7);
                print_computer_win();
            }
        }
        else
        {
            computer_move(tabela, 1);
            print_computer_win();
        }

    }
/////////////////////////////////////////////////////////
    if(jogada.jogada1 == 3)
    {
        computer_move(tabela, 7);
        human_move(tabela, &jogada);
        if(jogada.jogada1 == 8)
        {
            computer_move(tabela, 1);
            human_move(tabela, &jogada);
            if(jogada.jogada1 == 4)
            {
                computer_move(tabela, 5);
                print_computer_win();
            }
            else
            {
                computer_move(tabela, 4);
                print_computer_win();
            }
        }
        else
        {
            computer_move(tabela, 8);
            print_computer_win();
        }
    }
/////////////////////////////////////////////////////////
    if(jogada.jogada1 == 4)
    {
        computer_move(tabela, 5);
        human_move(tabela, &jogada);
        if(jogada.jogada1 == 1)
        {
            computer_move(tabela, 7);
            human_move(tabela, &jogada);
            if(jogada.jogada1 == 3)
            {
                computer_move(tabela, 8);
                print_computer_win();
            }
            else
            {
                computer_move(tabela, 3);
                print_computer_win();
            }
        }
        else
        {
            computer_move(tabela, 1);
            print_computer_win();
        }        
    }


/////////////////////////////////////////////////////////    
    if(jogada.jogada1 == 5)
    {
        computer_move(tabela, 1);
        human_move(tabela, &jogada);
        if(jogada.jogada1 == 3)
        {
            computer_move(tabela, 7);
            human_move(tabela, &jogada);
            if(jogada.jogada1 == 4)
            {
                computer_move(tabela, 8);
                print_computer_win();
            }
            else
            {
                computer_move(tabela, 4);
                print_computer_win();
            }
        }
        if(jogada.jogada1 == 7)
        {
            computer_move(tabela, 3);
            human_move(tabela, &jogada);
            if(jogada.jogada1 == 2)
            {
                computer_move(tabela, 6);
                print_computer_win();
            }
            else
            {
                computer_move(tabela, 2);
                print_computer_win();
            }
        }
        else
        {
            print_empate();
        }
    }
/////////////////////////////////////////////////////////
    if(jogada.jogada1 == 6)
    {
        computer_move(tabela,7);
        human_move(tabela, &jogada);
            if(jogada.jogada1 == 8)
            {  
                computer_move(tabela, 5);
                human_move(tabela, &jogada);
                if(jogada.jogada1 == 1)
                {
                    computer_move(tabela, 3);
                    print_computer_win();
                }
                else
                {
                    computer_move(tabela, 1);
                    print_computer_win();
                    
                }
            }
            else
            {
                computer_move(tabela, 8);
                print_computer_win();

            }
    }
/////////////////////////////////////////////////////////
    if(jogada.jogada1 == 7)
    {
        computer_move(tabela, 3);
        human_move(tabela, &jogada);
        if(jogada.jogada1 == 6)
        {
            computer_move(tabela, 1);
            human_move(tabela, &jogada);
            if(jogada.jogada1 == 2)
            {
                computer_move(tabela, 5);
                print_computer_win();
            }
            else
            {
                computer_move(tabela, 2);
                print_computer_win();
            }
        }
        else
        {
            computer_move(tabela, 6);
            print_computer_win();
        }
    }
/////////////////////////////////////////////////////////    
    if(jogada.jogada1 == 8)
    {
        computer_move(tabela, 5);
        human_move(tabela, &jogada);
        if(jogada.jogada1 == 1)
        {
            computer_move(tabela, 3);
            human_move(tabela, &jogada);
            if(jogada.jogada1 == 7)
            {
                computer_move(tabela, 6);
                print_computer_win();
            }
            else
            {
                computer_move(tabela, 7);
                print_computer_win();
            }
        }
        else
        {
            computer_move(tabela, 1);
            print_computer_win();
        }
    }
} 


int main()
{
    char tabela[10]= {'a', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int gamemode = 0;
    int player1 = 0;
    printf("%sEscolhe o modo de jogo:\n", AC_YELLOW);
    reset();
    printf("1.Jogar contra um amigo\n2.Jogar contra o computador\n");
    scanf("%d", &gamemode);
    if(gamemode == 1)
    {
        print_tabela_vazia(tabela);
        jogar(tabela);
    }
    else if(gamemode == 2)
    {
        printf("%sQuem joga primeiro?\n", AC_BLUE);
        printf("%s1.Computador\n", AC_RED);
        printf("%s2.Tu\n", AC_CYAN);
        reset();
        scanf("%d", &player1);
        if(player1 == 1)
        {
            jogar_computador(tabela);
        }
        /*else if(player1 == 2)
        {

        }*/
        else
        {
            fprintf(stderr, "%sModo de jogo inválido!\n", AC_RED);
            exit(1);
        }
    }
    else
    {
        fprintf(stderr, "%sModo de jogo inválido!\n", AC_RED);
        exit(1);
    }


    return 0;     
}
