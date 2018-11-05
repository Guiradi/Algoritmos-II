/*
 * Um pronto-socorro deseja informatizar o seu sistema de atendimento aos pacientes.
 * As recepcionistas utilizarão um terminal para fazer a ficha de cada paciente que chega. 
 * Juntamente com os dados do paciente, a recepcionista preenche um campo informando o estado do paciente (regular, ruim, péssimo). 
 * Ao terminar de atender a um paciente, o médico consultará o sistema para chamar o próximo paciente e, naturalmente, 
 * o sistema deverá priorizar os pacientes que estiverem em pior estado de saúde.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>

#define MAX 100

typedef struct
{
    char nome[32];
    int estado;
} reg;

reg pacientes[MAX];

void gotoxy(int x, int y){
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x-1,y-1});
}

void mostra_fila(int n)
{
    // mostra os pacientes
    int i;

    system("cls");
    printf("\t\t\tPRONTO-SOCORRO\n\n\tFila de pacientes:\n\n\t");

    if(!n)
        printf("Fila vazia\n");

    for (i = 0; i < n; i++)
    {
        printf("%d. %s\t\tESTADO: ", i+1, (pacientes[i]).nome);

        if ((pacientes[i]).estado == 1)
            printf("Regular\n\t");
        else if ((pacientes[i]).estado == 2)
            printf("Ruim\n\t");
        else
            printf("Pessimo\n\t");
    }

    printf("\n\t");
    system("pause");
}

void atendimento(int *n)
{
    // atender um paciente
    int i;
    reg proximo;

    system("cls");
    printf("\t\t\tPRONTO-SOCORRO\n\n\t");
    
    if (!n)
        printf("Fila vazia!\n\n\t");
    else
    {    
        printf("Proximo paciente: %s\n\n\t", pacientes[0]);
        
        for (i = 1; i < (*n); i++)
            pacientes[i-1] = pacientes[i];
        
        (*n)--;
    }

    system("pause");
}

void registro(int *n)
{
    //registra pacientes
    reg paciente, anterior, proximo;

    // Variaveis:
    char aux[1];
    int i, j, inseriu = 0;
    

    system("cls");
    printf("\t\t\tPRONTO-SOCORRO");
    printf("\n\n");
    
    // Registra nome
    printf("\tDigite o nome do paciente: ");
    gets(paciente.nome);
    
    // Registra estado
    printf("\n\tEstado do paciente:\n\t\t1. Regular\n\t\t2. Ruim\n\t\t3. Pessimo");
    do
    {
    	gotoxy(30,5);
        aux[0] = getch();
        paciente.estado = atoi(aux);
    } while ((paciente.estado < 1) || (paciente.estado > 3));

    if (paciente.estado == 1)
        printf("Regular");
    else if (paciente.estado == 2)
        printf("Ruim");
    else
        printf("Pessimo", paciente.estado);

    for (i = 0; i < (*n); i++)
    {
        if (paciente.estado > (pacientes[i]).estado)
        {
            anterior = pacientes[i];
            pacientes[i] = paciente;
            (*n)++;
            inseriu = 1;
            for (j = i+1; j < (*n); j++)
            {
                proximo = pacientes[j];
                pacientes[j] = anterior;
                anterior = proximo;
            }
        }
    }

    if (!inseriu)
    {
        (*n)++;
        pacientes[(*n)-1] = paciente;
    }

    printf("\n\n\n\n\n\tPaciente registrado!\n\t");
    system("pause");
}

int main()
{
    // Quantidade atual de pacientes:
    int n = 0;
    // Char para decisoes
    char escolha;

    /* ----- MENU ----- */
    do
    {
        system("cls");
        printf("\t\t\tPRONTO-SOCORRO");
        printf("\n\n\tBem vindo ao sistema de atendimentos aos pacientes.");
        printf("\n\n\t1. Registrar novo paciente.");
        printf("\n\t2. Atender proximo paciente.");
        printf("\n\t3. Mostrar fila.");
        printf("\n\t0. Sair.\n\t");

        do
        {
            escolha = getch();
        } while ((escolha != '0') && (escolha != '1') && (escolha != '2') && (escolha != '3'));

        switch (escolha)
        {
            case '1':
                registro(&n);
                break;

            case '2':
                atendimento(&n);
                break;

            case '3':
                mostra_fila(n);

            case '0':
                break;

            default:
                system("cls");
                printf("Erro encontrado. Favor consultar o desenvolvedor do programa.\n");
                system("pause");
                return;
        }

    } while (escolha != '0');

    /* -----FIM----- */
    return 0;
}
