/* Autor.....: Felipe Lobato De Andrade
   Data......: 08/03/2026
   Objetivo..: Menu Sistema de Cadastro de Cliente */

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

#define MAX 5 // capacidade da lista

// ---------------------- Tipos ----------------------

typedef struct
{
    int codigo;
    char nome[50];
    char endereco[50];
    char telefone[16];
    char cpf[15];
    char email[50];
    char dt_nascimento[11];

} reg_clientes;

typedef struct
{
    reg_clientes ficha[MAX];
    int inicio;
    int fim;

} Lista;


// Funcao para posicionar o cursor em um determinado ponto da Tela
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = (short)x;
    coord.Y = (short)y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


// Limpa a Linha da Mensagem nas coordenadas 07,23
void limpa_mensagem()
{
    gotoxy(07,23);
    printf("                                                              ");
}


// Funcao da Tela padrao
void tela()
{
    system("cls");

    int l;
    int c;

    for (l = 1; l < 25; l++)
    {
        gotoxy(01, l);
        printf("|");
        gotoxy(80, l);
        printf("|");
    }

    for (c = 1; c < 81; c++)
    {
        gotoxy(c, 01);
        printf("-");
        gotoxy(c, 04);
        printf("-");
        gotoxy(c, 22);
        printf("-");
        gotoxy(c, 24);
        printf("-");
    }

    gotoxy(01,01); printf("+");
    gotoxy(80,01); printf("+");

    gotoxy(01,04); printf("+");
    gotoxy(80,04); printf("+");

    gotoxy(01,22); printf("+");
    gotoxy(80,22); printf("+");

    gotoxy(01,24); printf("+");
    gotoxy(80,24); printf("+");

    gotoxy(03,02);
    printf("UNICV");

    gotoxy(61,02);
    printf("Estrutura de Dados");

    gotoxy(58,03);
    printf("Felipe Lobato De Andrade");

    gotoxy(02,23);
    printf("MSG.: ");
}


// Funcao Tela de Registro de Cliente
void tela_cliente()
{
    gotoxy(10,7);
    printf("Codigo do Cliente..:");

    gotoxy(10,9);
    printf("1 - Nome............:");

    gotoxy(10,11);
    printf("2 - Endereco........:");

    gotoxy(10,13);
    printf("3 - Telefone........:");

    gotoxy(10,15);
    printf("4 - CPF.............:");

    gotoxy(10,17);
    printf("5 - Email...........:");

    gotoxy(10,19);
    printf("6 - Data Nascimento.:");
}


// Pesquisa um cliente no ARRAY
int pesquisa(Lista *L, int cod)
{
    int i;

    for (i = 0; i < L->fim; i++)
    {
        if (L->ficha[i].codigo == cod)
        {
            return i;
        }
    }

    return -1;
}


// Funcao que Cadastra Cliente
void cadastra_cliente(Lista *L)
{
    reg_clientes clie;
    int result;
    int resp;

    do
    {
        if (L->fim >= MAX)
        {
            tela();
            gotoxy(30,03);
            printf("CADASTRA CLIENTE");
            gotoxy(07,23);
            printf("Lista cheia. Nao pode cadastrar mais clientes...");
            getch();
            return;
        }

        do
        {
            tela();

            gotoxy(30,03);
            printf("CADASTRA CLIENTE");

            tela_cliente();

            gotoxy(33,7);
            scanf("%d",&clie.codigo);

            result = pesquisa(L, clie.codigo);

            if (result != -1)
            {
                gotoxy(07,23);
                printf("Codigo ja existe...");
                getch();
            }

        } while (result != -1);

        gotoxy(33,9);
        fflush(stdin);
        fgets(clie.nome, 50, stdin);

        gotoxy(33,11);
        fflush(stdin);
        fgets(clie.endereco, 50, stdin);

        gotoxy(33,13);
        fflush(stdin);
        fgets(clie.telefone, 16, stdin);

        gotoxy(33,15);
        fflush(stdin);
        fgets(clie.cpf, 15, stdin);

        gotoxy(33,17);
        fflush(stdin);
        fgets(clie.email, 50, stdin);

        gotoxy(33,19);
        fflush(stdin);
        fgets(clie.dt_nascimento, 11, stdin);

        gotoxy(07,23);
        printf("Deseja salvar os dados digitados (1=Sim, 2=Nao): ");
        scanf("%d",&resp);

        if (resp == 1)
        {
            L->ficha[L->fim] = clie;
            L->fim++;

            limpa_mensagem();
            gotoxy(07,23);
            printf("Cliente cadastrado com sucesso...");
            getch();
        }

        limpa_mensagem();
        gotoxy(07,23);
        printf("Deseja cadastrar outro (1=Sim, 2=Nao): ");
        scanf("%d",&resp);

    } while (resp == 1);
}


// Funcao que Altera Cliente
void altera_cliente(Lista *L)
{
    int cod;
    int pos;
    int resp;

    tela();
    gotoxy(30,03);
    printf("ALTERA CLIENTE");

    gotoxy(10,7);
    printf("Codigo do Cliente..:");
    gotoxy(33,7);
    scanf("%d",&cod);

    pos = pesquisa(L, cod);

    if (pos == -1)
    {
        gotoxy(07,23);
        printf("Cliente nao encontrado...");
        getch();
    }
    else
    {
        tela();
        gotoxy(30,03);
        printf("ALTERA CLIENTE");
        tela_cliente();

        gotoxy(33,7);
        printf("%d", L->ficha[pos].codigo);

        gotoxy(33,9);
        fflush(stdin);
        fgets(L->ficha[pos].nome, 50, stdin);

        gotoxy(33,11);
        fflush(stdin);
        fgets(L->ficha[pos].endereco, 50, stdin);

        gotoxy(33,13);
        fflush(stdin);
        fgets(L->ficha[pos].telefone, 16, stdin);

        gotoxy(33,15);
        fflush(stdin);
        fgets(L->ficha[pos].cpf, 15, stdin);

        gotoxy(33,17);
        fflush(stdin);
        fgets(L->ficha[pos].email, 50, stdin);

        gotoxy(33,19);
        fflush(stdin);
        fgets(L->ficha[pos].dt_nascimento, 11, stdin);

        gotoxy(07,23);
        printf("Deseja salvar a alteracao (1=Sim, 2=Nao): ");
        scanf("%d",&resp);

        if (resp == 1)
        {
            gotoxy(07,23);
            printf("Cliente alterado com sucesso...");
            getch();
        }
        else
        {
            gotoxy(07,23);
            printf("Alteracao cancelada...");
            getch();
        }
    }
}


// Funcao que Consulta Cliente
void consulta_cliente(Lista *L)
{
    int cod;
    int pos;

    tela();
    gotoxy(30,03);
    printf("CONSULTA CLIENTE");

    gotoxy(10,7);
    printf("Codigo do Cliente..:");
    gotoxy(33,7);
    scanf("%d",&cod);

    pos = pesquisa(L, cod);

    if (pos == -1)
    {
        gotoxy(07,23);
        printf("Cliente nao encontrado...");
        getch();
    }
    else
    {
        tela();
        gotoxy(30,03);
        printf("CONSULTA CLIENTE");

        gotoxy(10,7);
        printf("Codigo............: %d", L->ficha[pos].codigo);

        gotoxy(10,9);
        printf("Nome..............: %s", L->ficha[pos].nome);

        gotoxy(10,11);
        printf("Endereco..........: %s", L->ficha[pos].endereco);

        gotoxy(10,13);
        printf("Telefone..........: %s", L->ficha[pos].telefone);

        gotoxy(10,15);
        printf("CPF...............: %s", L->ficha[pos].cpf);

        gotoxy(10,17);
        printf("Email.............: %s", L->ficha[pos].email);

        gotoxy(10,19);
        printf("Data Nascimento...: %s", L->ficha[pos].dt_nascimento);

        gotoxy(07,23);
        printf("Consulta realizada com sucesso...");
        getch();
    }
}


// Funcao que Exclui Cliente
void exclui_cliente(Lista *L)
{
    int cod;
    int pos;
    int i;
    int resp;

    tela();
    gotoxy(30,03);
    printf("EXCLUI CLIENTE");

    gotoxy(10,7);
    printf("Codigo do Cliente..:");
    gotoxy(33,7);
    scanf("%d",&cod);

    pos = pesquisa(L, cod);

    if (pos == -1)
    {
        gotoxy(07,23);
        printf("Cliente nao encontrado...");
        getch();
    }
    else
    {
        gotoxy(07,23);
        printf("Deseja excluir o cliente (1=Sim, 2=Nao): ");
        scanf("%d",&resp);

        if (resp == 1)
        {
            for (i = pos; i < L->fim - 1; i++)
            {
                L->ficha[i] = L->ficha[i + 1];
            }

            L->fim--;

            gotoxy(07,23);
            printf("Cliente excluido com sucesso...");
            getch();
        }
        else
        {
            gotoxy(07,23);
            printf("Exclusao cancelada...");
            getch();
        }
    }
}


// Programa Principal
int main()
{
    Lista L;
    int opcao;

    L.inicio = 0;
    L.fim = 0;

    system("cls");
    system("Color 1e");

    do
    {
        tela();

        gotoxy(7,3);
        printf(" -------- SISTEMA DE CLIENTES --------");

        gotoxy(30,10);
        printf("1 - INCLUSAO");

        gotoxy(30,12);
        printf("2 - ALTERACAO");

        gotoxy(30,14);
        printf("3 - CONSULTA");

        gotoxy(30,16);
        printf("4 - EXCLUSAO");

        gotoxy(30,18);
        printf("5 - FINALIZAR O PROGRAMA");

        gotoxy(07,23);
        printf("Digite sua Opcao.: ");
        scanf("%d",&opcao);

        switch (opcao)
        {
            case 1:
                cadastra_cliente(&L);
                break;

            case 2:
                altera_cliente(&L);
                break;

            case 3:
                consulta_cliente(&L);
                break;

            case 4:
                exclui_cliente(&L);
                break;

            case 5:
                gotoxy(07,23);
                printf("Programa finalizado...");
                break;

            default:
                gotoxy(07,23);
                printf("Opcao invalida...");
                getch();
        }

    } while (opcao != 5);

    return 0;
}
