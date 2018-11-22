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

typedef struct reg * no;

struct reg
{
    char nome[32];
    int estado;
    struct reg * prox;
};

void gotoxy(int x, int y){
     SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),(COORD){x-1,y-1});
}

void registro(no * pacientes)
{
    // Auxiliar para registros:
    int aux_estado;
    char aux[1];

    // Lista auxiliar:
    no p = (no) malloc(sizeof(struct reg));

    system("cls");
    printf("\t\t\tPRONTO-SOCORRO");
    printf("\n\n");
    printf("\tDigite o nome do paciente: ");
    gets(p->nome);

    printf("\n\tEstado do paciente:\n\t\t1. Regular\n\t\t2. Ruim\n\t\t3. Pessimo");
    do
    {
    	gotoxy(30,5);
        aux[0] = getch();
        aux_estado = atoi(aux);
    } while ((aux_estado < 1) || (aux_estado > 3));
    
    if (aux_estado == 1)
        printf("Regular");
    else if (aux_estado == 2)
        printf("Ruim");
    else
        printf("Pessimo", aux_estado);
    
    p->estado = aux_estado;

    if ((*pacientes) == NULL || p->estado > (*pacientes)->estado) 
    {
        p->prox = (*pacientes);
        (*pacientes) = p;
    }    
    else
    {
        no q = (*pacientes), r;
        while (q != NULL &&  q->estado >= p->estado)
        {
            r = q;
            q = q->prox;
        }
        p->prox = q;
        r->prox = p;
    }
    
    printf("\n\n\n\n\n\tPaciente registrado!\n\t");
    system("pause");

}

void atendimento(no * pacientes)
{
    system("cls");
    printf("\t\t\tPRONTO-SOCORRO\n\n\t");
    
    if (!*pacientes)
        printf("Fila vazia!\n\n\t");
    else
    {    
        no p = *pacientes;
        printf("Proximo paciente: %s\n\n\t", p->nome);

        *pacientes = (*pacientes)->prox;
        free(p);
    }

    system("pause");
}

void mostra_fila(no pacientes)
{
    system("cls");
    printf("\t\t\tPRONTO-SOCORRO\n\n\tFila de pacientes:\n\n\t");
    
    if(pacientes == NULL)
        printf("Fila vazia!\n");
    
    int i = 1;
    no p = pacientes;
    while (p)
    {
        printf("%d. %s\t\tESTADO: ", i++, p->nome);
        
        if (p->estado == 1)
            printf("Regular\n\t");
        else if (p->estado == 2)
            printf("Ruim\n\t");
        else
            printf("Pessimo\n\t");
        
        p = p->prox;
    }
    
    printf("\n\t");
    system("pause");
}

int main()
{    
	/*Cria lista de pacientes para o programa todo*/
    no pacientes = (no)malloc(sizeof(struct reg)); // cria uma lista pacientes
    pacientes = NULL; // faz a lista iniciar como nula
	
    /* -----Variaveis----- */
    char escolha;

    /* -----Menu----- */
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
                registro(&pacientes);
                break;

            case '2':
                atendimento(&pacientes);
                break;

            case '3':
                mostra_fila(pacientes);

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
