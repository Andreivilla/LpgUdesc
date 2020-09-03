#include<stdio.h>
#include<stdlib.h>
#define num_contas 2
typedef struct{
    int numero_da_conta;
    char nome_do_clinte[10];
    float saldo_corrente;
    int tipo_cartao;//(0 –não possui; 1:cartão TIPO1; 2: cartão TIPO2)
    float limite_emprestimo;
    float saldo_cartao;
    float saldo_ivestimento;
}conta;
void ler_contas(conta *a){
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
void modif_contas(conta *a){
    int i;
    for(i=0; i<num_contas; i++){
        printf("\n-----Conta %d: -----\n", i);
        printf("Numero da conta: ");
        scanf("%d", &a[i].numero_da_conta);
        printf("Nome do cliente: ");
        scanf("%s", a[i].nome_do_clinte);fflush(stdin);
        printf("Saldo da conta corrente: ");
        scanf("%f", &a[i].saldo_corrente);
        printf("Tipo do cartao(0:nao possui, 1:cartao TIPO1, 2:cartao TIPO2): ");
        scanf("%d", &a[i].tipo_cartao);
        printf("Limite de emprestimo: ");
        scanf("%f", &a[i].limite_emprestimo);
        printf("Saldo do cartao: ");
        scanf("%f", &a[i].saldo_cartao);
        printf("Saldo invetimento: ");
        scanf("%f", &a[i].saldo_ivestimento);
    }
}
void descarregar(conta *a){
    FILE *file = fopen("contas.bin", "rb");
    fread(a, sizeof(conta), num_contas, file);
    fclose(file);
}
void carregar(conta *a){
    int i;
    FILE *file = fopen("contas.bin", "wb");
    for(i=0; i<num_contas; i++)
        fwrite(&a[i], sizeof(conta), 1, file);
    fclose(file);
}
int achar_conta(conta *a){
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
/*void registro(conta a, char tipo){
        switch (escolha){
        case '1':
            descarregar(contas);
            modif_contas(contas);
            carregar(contas);
            break;
        case '2':
            descarregar(contas);
            ler_contas(contas);
            break;
        case 's':// para saque

            f = fopen("movimento.txt", "a");
            fprintf(f,"Conta: %d ---- Sacou: %f\n", contas[nconta].numero_da_conta, valor);
            fclose(f);
            carregar(contas);
        break;
        case 'd':

            f = fopen("movimento.txt", "a");
            fprintf(f,"Conta: %d ---- Depositou: %f\n", contas[nconta].numero_da_conta, valor);
            fclose(f);
            carregar(contas);
        break;
        case 'c':

            f = fopen("movimento.txt", "a");
            fprintf(f,"Conta: %d ---- Usou credito: %f\n", contas[nconta].numero_da_conta, valor);
            fclose(f);
            carregar(contas);
        break;
        case 'i':

            f = fopen("movimento.txt", "a");
            fprintf(f,"Conta: %d ---- Investiu: %f\n", contas[nconta].numero_da_conta, valor);
            fclose(f);
            carregar(contas);
        break;
        case 'e':

            f = fopen("movimento.txt", "a");
            fprintf(f,"Conta: %d ---- Emprestou: %f\n", contas[nconta].numero_da_conta, valor);
            fclose(f);
            carregar(contas);
        break;
    }
}*/