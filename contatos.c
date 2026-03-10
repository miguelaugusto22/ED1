#include <stdio.h>
#include <string.h>

struct contatos{
    char nomes[100][128];
    char telefones[100][32];
};

typedef struct contatos Contatos;

Contatos agenda;
int total = 0;

void formatarTelefone(char *num){

    char temp[32];

    int tam = strlen(num);

    if(tam == 11){
        sprintf(temp,"(%c%c)%c%c%c%c%c-%c%c%c%c",
        num[0],num[1],num[2],
        num[3],num[4],num[5],num[6],num[7],
        num[8],num[9],num[10]);

        strcpy(num,temp);
    }

    if(tam == 12){
        sprintf(temp,"(%c%c%c)%c%c%c%c%c-%c%c%c%c",
        num[0],num[1],num[2],
        num[3],num[4],num[5],num[6],num[7],
        num[8],num[9],num[10],num[11]);

        strcpy(num,temp);
    }

}

void novoContato(){

    if(total >= 100){
        printf("Agenda cheia\n");
        return;
    }

    printf("Nome: ");
    scanf(" %[^\n]", agenda.nomes[total]);

    printf("Telefone (somente numeros): ");
    scanf("%31s", agenda.telefones[total]);

    formatarTelefone(agenda.telefones[total]);

    total++;
}

void exibirContatos(){

    for(int i = 0; i < total; i++){

        printf("\nContato %d\n", i+1);
        printf("Nome: %s\n", agenda.nomes[i]);
        printf("Telefone: %s\n", agenda.telefones[i]);

    }

}

void salvarArquivo(){

    FILE *f = fopen("contatos.csv","w");

    for(int i = 0; i < total; i++){
        fprintf(f,"%s,%s\n", agenda.nomes[i], agenda.telefones[i]);
    }

    fclose(f);

    printf("Arquivo salvo!\n");
}

void abrirArquivo(){

    FILE *f = fopen("contatos.csv","r");

    if(f == NULL){
        return;
    }

    total = 0;

    while(fscanf(f," %[^,],%[^\n]", agenda.nomes[total], agenda.telefones[total]) != EOF){
        total++;
    }

    fclose(f);

    printf("Contatos carregados!\n");
}

int main(){

    int opc;

    abrirArquivo();

    do{

        printf("\n1 - Novo contato\n");
        printf("2 - Exibir contatos\n");
        printf("3 - Salvar arquivo\n");
        printf("4 - Abrir arquivo\n");
        printf("5 - Sair\n");

        scanf("%d",&opc);

        switch(opc){

            case 1:
                novoContato();
            break;

            case 2:
                exibirContatos();
            break;

            case 3:
                salvarArquivo();
            break;

            case 4:
                abrirArquivo();
            break;

        }

    }while(opc != 5);

}
