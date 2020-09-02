#include<stdio.h>
#include<stdlib.h>
#define num_contas 2
typedef struct{
    int numero_da_conta;
    char nome_do_clinte[10];
    float saldo_corrente;
    int tipo_cartao;//(0 –não possui; 1:cartão TIPO1; 2: cartão TIPO2)
    float limite_cartao;
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
        printf("Limite do cartao: %f\n", a[i].limite_cartao);
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
        printf("Limite do cartao: ");
        scanf("%f", &a[i].limite_cartao);
        printf("Saldo do cartao: ");
        scanf("%f", &a[i].saldo_cartao);
        printf("Saldo invetimento: ");
        scanf("%f", &a[i].saldo_ivestimento);
    }
}