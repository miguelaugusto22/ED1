#include <stdio.h>

struct contatos{
    char nomes[100][128];
    char telefones[100][32];
};

typedef struct contatos Contatos;

Contatos agenda;
int total = 0;

void novoContato(){
    printf("Nome: ");
    scanf(" %[^\n]", agenda.nomes[total]);

    printf("Telefone: ");
    scanf(" %[^\n]", agenda.telefones[total]);

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
        printf("Arquivo nao encontrado\n");
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