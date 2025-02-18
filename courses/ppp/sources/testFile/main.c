//----------PROJETO-----------//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//-----------------------------------------------
//Estruturas

typedef struct despesas{
    int valor;
    char descricao[50];
    char data[20];
}despesas;

typedef struct Pessoa{
    char nome[50];
    char DN[20];
    char turma[10];
    int numero;
    float saldo;
    struct Pessoa *next;
    struct despesas;
}PESSOA;

//-------------------------------------------------
//escrever no ficheiro

PESSOA *Escreve(){
    PESSOA *L=NULL,*aux;
    FILE *f;
    char Lnome[50];
    char LDN[50];
    char LTurma[50];
    int numero;
    float saldo;
    if(f==NULL)
        f=fopen("dados.txt", "w"); //abre o ficheiro para escrita caso este não exista
    else
        f=fopen("dados.txt","a"); //abre o ficheiro para escrita caso este já exista
    printf("Nome:");
    scanf("%s",Lnome);
    printf("Data de Nascimento:");
    scanf("%s", LDN);
    printf("Ano/Turma:");
    scanf("%s", LTurma);
    printf("numero:");
    scanf("%d", &numero);
    printf("saldo:");
    scanf("%2f", &saldo);
    fprintf(f, "%s %s %s %d %2f\n", Lnome, LDN, LTurma, numero, saldo);
    fclose(f);
    printf("::::::::::O Aluno foi adicionado com sucesso::::::::::\n");
}

//----------------------------------------------------
//ler o ficheiro os valores e armazena-los em memoria

PESSOA *Ler(){
    PESSOA *L=NULL,*aux;
    FILE *f;
    char Lnome[50];
    char LDN[50];
    char LTurma[50];
    int numero;
    float saldo;
    //abrir o ficheiro de dados
    f=fopen("dados.txt","r");
    //verificar se o ficheiro existe
    if(f==NULL)
        return(NULL);
    while(fscanf (f, "%s %s %s  %d %2f", Lnome, LDN, LTurma, &numero, &saldo)!=EOF){
        //se a lista estiver vazia, inserimos na 1 posicao
        if(L==NULL){
            //reservar memoria do tipo de struct PESSOA
            L=(PESSOA*)malloc (1*sizeof(PESSOA));
            strcpy(L->nome,Lnome);
            strcpy(L->DN, LDN);
            strcpy(L->turma, LTurma);
            L->numero=numero;
            L->saldo=saldo;
            //declarar “a seta” da proxima pessoa  a NULL (vazio)
            L->next=NULL;
            //a partir de agora o aux é a nossa lista (L -> cabeca da lista)
            aux=L;
        }
        else {
            aux->next=(PESSOA*)malloc (1*sizeof(PESSOA));
            aux=aux->next;
            strcpy(aux->nome,Lnome);
            strcpy(aux->DN, LDN);
            strcpy(aux->turma, LTurma);
            aux->numero=numero;
            aux->saldo=saldo;
            aux->next=NULL;
        }
    }
    fclose(f);
    return(L);
}

//-----------------------------------------
//funcao para mostrar o que existe na lista

void Showlist(PESSOA *L){
    if(L==NULL){
        printf("A Lista esta vazia\n");
        return;
    }
    else {
        //enquanto houver nodos..
        while(L!=NULL){
            printf(":::::::::::::::::::::::\n");
            printf("-> Nome: %s\n-> Data de Nascimento: %s\n-> Ano/turma: %s\n-> Numero: %d\n-> Saldo: %2f euros\n",L->nome,L->DN,L->turma,L->numero,L->saldo);
            printf(":::::::::::::::::::::::\n");
            L = L->next;
        }
    }

}

//----------------------------------------
//Apagar um aluno existente

PESSOA *apaga(PESSOA *L)
{
    FILE *f;
    FILE *faux;
    int apaga;
    char texto[1000]; //string para extrair o texto do ficheiro original
    f = fopen("dados.txt", "r");
    faux = fopen("dados2.txt", "a");
    L = Ler();
    printf("Numero do aluno que deseja apagar:");
    scanf("%d", &apaga);
    if(L==NULL){
        printf("A Lista esta vazia\n");
    }
    else {
        while(L!=NULL){
            if(L->numero != apaga)
            {
                printf("%d\n", L->numero);
                fgets(texto, 1000, f);
                printf("%s\n",texto);
                fputs(texto, faux);
            }
            L = L->next;
        }
    }
    fclose(f);
    fclose(faux);
    printf("%d\n", remove("dados.txt"));
    printf("%d\n", rename("dados2.txt", "dados.txt"));
}


//------------------------------------------
//MAIN

int main(){
    PESSOA *L=NULL;
    //Escreve();
    L=Ler();
    apaga(L);
    Showlist(L);
    return (0);
}

//----------------------------------------