#include"util.h"
void ler_contas(conta *a){//lista todas as contas armazenadas no sistema
    int i;
    for(i=0; i<num_contas; i++){
        printf("\n-----Conta %d: -----\n", i);
        printf("Numero da conta: %d\n", a[i].numero_da_conta);
        printf("Nome do cliente: %s\n", a[i].nome_do_clinte);
        printf("Saldo da conta corrente: %f\n", a[i].saldo_corrente); 
        printf("Tipo do cartao: %d\n", a[i].tipo_cartao);
        printf("Limite de emprestimo: %f\n", a[i].limite_emprestimo);
        printf("Saldo do cartao: %f\n", a[i].saldo_cartao);
        printf("Saldo invetimento: %f\n", a[i].saldo_ivestimento);
    } 

}
void modif_contas(conta *a){//abre um painel para modidficar todas as contas
    int i;
    for(i=0; i<num_contas; i++){
        printf("\n-----Conta %d: -----\n", i);
        printf("Numero da conta: ");
        scanf("%d", &a[i].numero_da_conta);
        printf("Nome do cliente: ");
        scanf("%s", a[i].nome_do_clinte);fflush(stdin);
        printf("Saldo da conta corrente: ");
        scanf("%f", &a[i].saldo_corrente);
        while(1){
            printf("Tipo do cartao(0:nao possui, 1:cartao TIPO1, 2:cartao TIPO2): ");
            scanf("%d", &a[i].tipo_cartao);
            if(a[i].tipo_cartao==0 || a[i].tipo_cartao==1 || a[i].tipo_cartao==2)
                break;
            else
                printf("---opcao invalida---\n");
        }
        printf("Limite de emprestimo: ");
        scanf("%f", &a[i].limite_emprestimo);
        if(!(a[i].tipo_cartao==0)){
            printf("Saldo do cartao: ");
        scanf("%f", &a[i].saldo_cartao);
        }
        printf("Saldo invetimento: ");
        scanf("%f", &a[i].saldo_ivestimento);
    }
}
void descarregar(conta *a){//descarrega as strucs do .bin
    FILE *file = fopen("contas.bin", "rb");
    fread(a, sizeof(conta), num_contas, file);
    fclose(file);
}
void carregar(conta *a){//carrega as structs no .bin
    int i;
    FILE *file = fopen("contas.bin", "wb");
    for(i=0; i<num_contas; i++)
        fwrite(&a[i], sizeof(conta), 1, file);
    fclose(file);
}
int achar_conta(conta *a){//verifica se valor digitado é o numero de uma conta e retorna para main o endereço do vetor da conta
    int i;
    int nconta;
    while(1){
        printf("Numero da conta: ");
        scanf("%d", &nconta);
        for(i=0; i<num_contas; i++){
            if(a[i].numero_da_conta == nconta)
                return i;                
        }
        printf("-Numero de conta invalido-\n");       
    }
}
void registro(conta a, char tipo, float valor){//regitra no arquivo registro.txt (conta a ser registrada, tipo do registro, valor do registro)
    FILE *f = fopen("movimento.txt", "a");
    switch (tipo){
        case 's':        
            fprintf(f,"Conta: %d----Sacou: %f\n", a.numero_da_conta, valor);
        break;
        case 'd':
            fprintf(f,"Conta: %d----Depositou: %f\n", a.numero_da_conta, valor);
        break;
        case 'c':
            fprintf(f,"Conta: %d----Usou credito: %f\n", a.numero_da_conta, valor);
        break;
        case 'i':
            fprintf(f,"Conta: %d----Investiu: %f\n", a.numero_da_conta, valor);
        break;
        case 'e':
            fprintf(f,"Conta: %d----Emprestou: %f\n", a.numero_da_conta, valor);
        break;
    }
    fclose(f);
}
void limite_estourado_emprestimo(conta a, float v){//faz o registro do limite de emprestimo estourado
    FILE *f = fopen("limite_estourado.txt", "a");
    printf("Limite de emprestimo estourado em %f\n", (v - a.limite_emprestimo));
    fprintf(f,"Conta: %d ---- limite emprestimo estourado em: %f\n", a.numero_da_conta, (v - a.limite_emprestimo));
}
void limite_estourado_cartao(conta a, float v){//faz o registro do limite do cartao estourado
    FILE *f = fopen("limite_estourado.txt", "a");
    printf("Limite do cartao estourado em %f\n", (v - a.saldo_cartao));
    fprintf(f,"Conta: %d ---- limite cartao estourado em: %f\n", a.numero_da_conta, (v - a.saldo_cartao));
}
char menu(){//gera o menu e retorna a opcao do jogador
    char c;
    char *opcoes = "012sSdDcCiIeE";
    int i;
    printf("\n-------- Menu --------\n");
    printf("0- Fechar programa\n");
    printf("1- Modificar todas as contas\n");
    printf("2- listar todas as contas\n");
    printf("s- Realizar saque\n");
    printf("d- Fazer um deposito\n");
    printf("c- credito via cartao\n");
    printf("i- Realizar um investimento\n");
    printf("e- pedir emprestimo\n");
    printf("Oque voce deseja fzr:\n");
    while(1){
        fflush(stdin);
        scanf("%c", &c);
        for (i=0; i<13; i++){
            if(opcoes[i] == c)
                return tolower(c);
        }
        printf("Opcao invalida\n"); fflush(stdin);
    }
}
void ordena_vet(float *a){//ordena um vetor
    int i,j;
    float h;
    for(i=0; i<num_contas; i++){
        for (j=i+1 ; j<num_contas; j++){
            if(a[i] < a[j]){
                h = a[j];
                a[j] = a[i];
                a[i] = h;
            }
        }
    }
}
