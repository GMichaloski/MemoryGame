#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define CRED "\x1b[31m"
#define CCYAN "\x1b[36m"
#define CRESET "\x1b[0m"
#define CYELLOW "\x1b[33m"
#define CGREEN "\x1b[32m"
char List[16] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P' };

int* shuffle(void)
{
    srand(time(NULL));
    int i;
    int* listV = malloc(16 * sizeof(int));
    for (i = 0; i < 8; i++)
    {
        listV[i] = i;
        listV[8 + i] = i;
    }

    for (i = 0; i < 16; i++)
    {
        int r = rand() % 16;
        int temp = listV[i];
        listV[i] = listV[r];
        listV[r] = temp;
    }
    return listV;
}

int countIndex(char c)
{
    c = tolower(c) - 'a';
    int n = c;
    return n;
}

char escolha_carta(char c, char* ListRes)
{
    int n = countIndex(c);
    char temp;
    switch (c)
    {
    case 'A':
        temp = List[n];
        List[n] = ListRes[n];
        break;
    case 'B':
        temp = List[n];
        List[n] = ListRes[n];
        break;
    case 'C':
        temp = List[n];
        List[n] = ListRes[n];
        break;
    case 'D':
        temp = List[n];
        List[n] = ListRes[n];
        break;
    case 'E':
        temp = List[n];
        List[n] = ListRes[n];
        break;
    case 'F':
        temp = List[n];
        List[n] = ListRes[n];
        break;
    case 'G':
        temp = List[n];
        List[n] = ListRes[n];
        break;
    case 'H':
        temp = List[n];
        List[n] = ListRes[n];
        break;
    case 'I':
        temp = List[n];
        List[n] = ListRes[n];
        break;
    case 'J':
        temp = List[n];
        List[n] = ListRes[n];
        break;
    case 'K':
        temp = List[n];
        List[n] = ListRes[n];
        break;
    case 'L':
        temp = List[n];
        List[n] = ListRes[n];
        break;
    case 'M':
        temp = List[n];
        List[n] = ListRes[n];
        break;
    case 'N':
        temp = List[n];
        List[n] = ListRes[n];
        break;
    case 'O':
        temp = List[n];
        List[n] = ListRes[n];
        break;
    case 'P':
        temp = List[n];
        List[n] = ListRes[n];
        break;
    default:
        break;
    }
    return temp;
}

int Game()
{
    int Counter = 0, IX, IY, erros = 0, retorno;
    char X, Y, TempX, TempY, ListRes[16];
    int* p = shuffle();
    for (int m = 0; m < 16; m++)
        ListRes[m] = (char)(*(p + m)) + 48;

    while (Counter != 15)
    {

        retorno = strncmp(List, ListRes, 15);
        if (retorno == 0)
        {
            break;
        }

        for (size_t j = 0; j < 3; j++)
        {
            system("clear || cls");
            for (int i = 0; i <= 16; i++)
            {
                if (i == 4 || i == 8 || i == 12 || i == 16)
                {
                    printf("\n");
                }
                if (i == 0 || i == 4 || i == 8 || i == 12)
                    printf(CYELLOW " _____     _____     _____     _____\n"
                        "|     |   |     |   |     |   |     |\n"
                        "|  %c  |   |  %c  |   |  %c  |   |  %c  |\n"
                        "|_____|   |_____|   |_____|   |_____|\n" CRESET,
                        List[i], List[i + 1], List[i + 2], List[i + 3]);
            }

            if (j == 0)
            {

                printf(CCYAN "\nDigite o caracter da primeira carta que voce deseja virar:\n" CRESET);
                scanf("%s", &X);
                X = toupper(X);
                getchar();
                IX = countIndex(X);
                TempX = escolha_carta(X, ListRes);
            }
            if (j == 1)
            {
                printf(CCYAN "\nDigite o caracter da segunda carta que voce deseja virar:\n" CRESET);
                scanf("%s", &Y);
                Y = toupper(Y);
                getchar();
                IY = countIndex(Y);
                TempY = escolha_carta(Y, ListRes);
            }
        }
        if (IX != IY)
        {
            if (List[IX] != List[IY])
            {
                List[IX] = TempX;
                List[IY] = TempY;

                printf(CCYAN "Pressione enter para continuar.\n" CRESET);
                erros++;
                getchar();
            }
            else
            {
                printf(CGREEN "\nVOCE ACERTOU!!!\n" CRESET);
                printf(CCYAN "Pressione enter para continuar.\n" CRESET);
                getchar();
            }
        }
        else
        {
            printf(CRED "\nVoce errou!\n" CRESET);
            erros++;
            printf(CRED "Por favor digite letras diferentes\n" CRESET);
            printf(CCYAN "Pressione enter para continuar.\n" CRESET);
            getchar();
            List[IX] = TempX;
        }
    }

    return erros;
}

int main(void)
{
    int Continuar;
    char list_temp[16] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P' };
    while (1)
    {
        system("clear || cls");
        printf(CYELLOW "-------------------------------------------------------\n"
            "                   JOGO DA MEMORIA\n"
            "-------------------------------------------------------\n\n");
        printf("Por:\nBruna Falheiro, Gustavo Michaloski e Yuri Laranja\n" CRESET);
        printf(CGREEN "Pressione enter para jogar: \n" CRESET);
        getchar();
        int erros = Game();
        printf(CYELLOW "PARABENS! VOCE GANHOU!\n" CRESET);
        printf(CRED "Total de erros: %d\n" CRESET, erros);

        while (1)
        {
            printf(CYELLOW "Digite (0) caso queira sair ou (1) para jogar novamente.\n" CRESET);
            scanf("%d", &Continuar);
            if (Continuar == 0)
            {
                break;
            }
            else if (Continuar == 1)
            {
                break;
            }
            else
                printf(CRED "Por favor Digite (0) ou (1)\n" CRESET);
        }

        if (Continuar == 0)
        {
            printf(CGREEN "Jogo finalizado..." CRESET);
            break;
        }
        else
        {
            for (int i = 0; i < 16; i++)
                List[i] = list_temp[i];
        }
    }
    return 0;
}