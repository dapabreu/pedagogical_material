#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "myLista.h"

#ifdef _WIN32
#include <conio.h>
#else
#define clrscr() printf("\e[1;1H\e[2J")
#endif

int menu();
void eleAdd();
void eleDel();
void orden();

pLista lista;

int main(){
    lista = cria();

    setbuf(stdout, 0);

    while (1) {
        clrscr();
        switch (menu()) {
            case 1:
                eleAdd();
                break;
            case 2:
                eleDel();
                break;
            case 3:
                orden();
                break;
            case 4:
                destroi(lista);
                exit(0);
            default:
                printf("Wrong option. Please select a valid option from the menu");
                break;
        }
    }
}

int menu(){
    int opt;
    printf("--- Welcome to ficha1333, please select an option ---");
    printf("\n");
    printf("\n");
    printf("[1] Add an element to the list");
    printf("\n");
    printf("[2] Delete an element to the list");
    printf("\n");
    printf("[3] Print the list");
    printf("\n");
    printf("[4] Exit");
    printf("\n");
    printf("\n");
    printf("$> ");
    scanf("%d", &opt);
    return opt;
}

void eleAdd(){
    clrscr();
    int lnum, lpontuacao;
    char lnome[50];
    char ldataNacimento[11];
    struct item myItem;
    printf("--- Data of the element to be added to the list ---");
    printf("\n");
    printf("\n");
    printf("# atleta: ");
    scanf("%d", &lnum);
    printf("Nome atleta: ");
    scanf("%s", lnome);
    printf("Data nacimento atleta: ");
    scanf("%s", ldataNacimento);
    printf("Pontuacao atleta: ");
    scanf("%d", &lpontuacao);
    myItem.numero = lnum;
    strcpy(myItem.nome, lnome);
    strcpy(myItem.dataNacimento, ldataNacimento);
    myItem.pontuacao = lpontuacao;
    insere(lista, myItem);
}

void eleDel(){
    clrscr();
    printf("--- ToBe implemented ---");
    printf("\n");
    printf("\n");
    printf("Press Enter to continue\n");
    while ((getchar()) != '\n');
    getchar();
}

void orden(){
    int opt, flag;
    pListaAux listaAux;
    listaAux = criaAux();
    while (1) {
        flag = 0;
        clrscr();
        printf("--- Select a choice for printing the list ---");
        printf("\n");
        printf("\n");
        printf("[1] Print ascending by numero");
        printf("\n");
        printf("[2] Print ascending by nome");
        printf("\n");
        printf("[3] Print ascending by dataNacimento");
        printf("\n");
        printf("[4] Print ascending by pontuacao");
        printf("\n");
        printf("\n");
        printf("$> ");
        scanf("%d", &opt);
        printf("\n");
        printf("\n");
        printf("=== The list order by your choice ===\n");
        printf("\n");

        switch (opt) {
            case 1:
                flag = 1;
                imprime(lista);
                break;
            case 2:
                flag = 1;
                listaAux = org2aux(lista,listaAux);
                bubbleSortList(listaAux, 2);
                imprimeAux(listaAux);
                break;
            case 3:
                flag = 1;
                listaAux = org2aux(lista,listaAux);
                bubbleSortList(listaAux, 3);
                imprimeAux(listaAux);
                break;
            case 4:
                flag = 1;
                listaAux = org2aux(lista,listaAux);
                bubbleSortList(listaAux, 4);
                imprimeAux(listaAux);
                break;
            default:
                printf("Wrong option. Please select a valid option from the menu\n");
                break;
        }

        if (flag) {
            destroiAux(listaAux);
            printf("\n");
            printf("Press Enter to continue\n");
            while ((getchar()) != '\n');
            getchar();
            break;
        }
    }
}