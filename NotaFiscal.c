#include <stdio.h>
#include <stdlib.h>

char nome[20];
char endereco[50];
char data[10];
int telefone;
int a = 1;
int b = 1;
int op;
int n;
int n2;
int c;
int *cod;
int cod2;
float *qtd;
float qtd2;
float total;
float *preco;
float preco2;

void menu(){
    printf("********MENU******\n");
    printf("\n");
    printf("1 Para Cadastrar\n");
    printf("2 Ver Orçamento\n");
    printf("3 Comprar\n");
    printf("4 Excluir Produto \n");
    printf("5 Sair\n");
    printf("******************\n");
}

void cadastrar(){
    printf("\n");
    printf("Digite o seu Nome:\n");
    scanf("%s",nome);
    printf("Digite o seu Endereço:\n");
    scanf("%s",endereco);
    printf("Digite o seu Telefone:\n");
    scanf("%d",&telefone);
    printf("Digite a Data:\n");
    scanf("%s",data);
}

void deletar(){
    do{
        printf("Digite o código do produto\n");
        scanf("%d",&n);
        printf("Digite a quantidade nova\n");
        scanf("%d",&n2);
        
        if(n2 != 0){    
            for(c = 0; c <= b; c++){
                if(cod[c] == n){
                    qtd[c] = n2;
                }
            }
            
        }else{
            for (c = 0; c < b; c++) {
                if(c == 0){
                    cod[c] = cod[c - 1];
                    qtd[c] = qtd[c - 1];
                    preco[c] = preco[c - 1];
                }
            }
            int ult = b - 1;
            qtd[ult] = 0;
            cod[ult] = 0;
            preco[ult] = 0;
            
        }
        total = 0;
        for(c = 0; c <= b; c++){
            if(preco[c] > 0){
                total = total + (preco[c] * qtd[c]);
            }
        }
        printf("Digite 1 para continuar ou 0 para sair\n");
        scanf("%d",&op);
    }while(op != 0);
}
    


void comprar(){
    cod = malloc(a * sizeof(int));
    preco = malloc(a * sizeof(float));
    qtd = malloc(a * sizeof(int));
    
    do{
        printf("Digite 1 para Adicionar Produto \n");
        printf("Digite 0 para Sair\n");
        scanf("%d",&op);
        
        if(op == 1){
            while(op != 0){
                printf("Digite o código do produto \n");
                scanf("%d",&cod2);
                cod = realloc(cod,b * sizeof(int));
                *(cod + b-1) = cod2;
                
                printf("Digite a quantidade comprada \n");
                scanf("%f",&qtd2);
                qtd = realloc(qtd , b * sizeof(int));
                *(qtd + b-1) = qtd2;
                
                printf("Digite o preço do produto \n");
                scanf("%f",&preco2);
                preco = realloc (preco , b * sizeof (float));
                *(preco + b-1) = preco2;
                
                printf("Digite 1 para continuar ou 0 para sair\n");
                scanf("%d",&op);
                
                b++;
                for(c = 0; c <= b; c++){
                    total = total + (preco[c] * qtd[c]);
                }
            }
            
        }else if(op == 0){
            return;
        }else{
            printf("Opção Inválida\n");
        }
    }while(op == 0);
    
}

void orcamento(){
    printf("=========================\n");
    printf("        Orçamento\n");
    printf("\n");
    printf("Nome: %s\n",nome);
    printf("Endereço: %s\n", endereco);
    printf("Telefone: %d\n", telefone);
    printf("Data: %s\n", data);
    printf("\n");
    printf("Cod/Prod | QTD | Preço/Un\n");
    for(c = 0; c <= b; c++){
        printf("%d | %.0f | %.2f \n", cod[c], qtd[c], preco[c]);
    }
    
    printf("TOTAL : %2.f\n",total);
    printf("=========================\n");
}

int main()
{
    while(op != 5){
        menu();
        scanf("%d",&op);
        system("clear||cls");
        if(op==1){
            cadastrar();
            system("clear||cls");
        }else if(op==2){
            orcamento();
        }else if(op==3){
            comprar();
            system("clear||cls");
        }else if(op==4){
            deletar();  
            system("clear||cls");
        }else if(op==5){
            break;
            system("clear||cls");
        }else{
            printf("Opção Inválida\n");
        }
    }
    free(cod); 
    free(qtd); 
    free(preco);
    return 0;
}