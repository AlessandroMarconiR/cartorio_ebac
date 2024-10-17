#include <stdio.h>\\ biblioteca de comunicação de usuario converte a lingugaem da maquina para o usuario conseguir interagir.
#include <stdlib.h>\\ biblioteca de alocação de espaço em memória, ela aloca uma parte da memória.
#include <locale.h>\\ biblioteca de alocações de texto por região
#include<string.h>\\biblioteca para chamar a variavel string.

int registro()
{
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];

    printf("Digite o cpf a ser cadastrado: ");
    scanf("%s", cpf);

    strcpy(arquivo, cpf);//utilizado para copiar os valores das strings

    FILE *file;//cria o arquivo
    file = fopen(arquivo, "w");//cria o arquivo essas duas primeiras linhas de código uma chama a função FILE para criação do arquivo e a outra para criação.
    fprintf(file, cpf);//salva o valor da variavel e guarda as informções no arquivo.
    fclose(file);//fecha o arquivo

    file = fopen(arquivo, "a");//estou abrindo para adicionar alguma informação no arquivo
    fprintf(file, ",");//adicionando e salvando informação
    fclose(file);//informações salvas fechando o arquivo.

    printf("Digite o nome a ser cadastrado: ");
    
    file = fopen(arquivo, "a");
    fprintf(file, " nome: ");
    fclose(file);

    scanf("%s", nome);

    file = fopen(arquivo, "a");
    fprintf(file, nome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);


    printf("Digite o sobrenome a ser cadastrado: ");
     
    file = fopen(arquivo, "a");
    fprintf(file, " Sobrenome: ");
    fclose(file);
    
    scanf("%s", sobrenome);

    file = fopen(arquivo, "a");
    fprintf(file, sobrenome);
    fclose(file);

    file = fopen(arquivo, "a");
    fprintf(file, ",");
    fclose(file);

    printf("Digite o cargo a ser cadastrado: ");
     
    file = fopen(arquivo, "a");
    fprintf(file, " cargo: ");
    fclose(file);
    
    scanf("%s", cargo);
   
   file = fopen(arquivo, "a");
   fprintf(file, cargo);
   fclose(file);

}

int consulta()
{
    char cpf[40];
    char conteudo[200];

    setlocale(LC_ALL, ("portuguese"));


    printf("Digite o cpf a ser consultado: ");
    scanf("%s", cpf);

    FILE *file;
    file = fopen(cpf, "r");

    if(file == NULL)
    {
        printf("Não foi possivel abrir o arquivo, não localizado!!\n\n");  
         int c;
        while ((c = getchar()) != '\n' && c != EOF) { }
        printf("Pressione enter para retornar.....");
        getchar();
        return 1;
    }
    
    while(fgets(conteudo, 200, file) != NULL)
    {
        printf("\nEssas são as informações do usuario, cpf: ");
        printf("%s", conteudo);
        printf("\n\n\n");
    }
    
     int c;
    while ((c = getchar()) != '\n' && c != EOF) { }

    printf("pressione enter para retornar ao menu.....");
    getchar();
    
}
int deleta()
{
   char cpf[40];

   printf("Digite o cpf do usuario a ser deletado: ");
   scanf("%s", cpf);

     int c;
    while ((c = getchar()) != '\n' && c != EOF) { }

   remove(cpf);

   FILE *file;
   file = fopen(cpf, "r");

    /*if(file == cpf)
    {
        printf("usuario deletado com sucesso!!.\n\n");
        getchar();
    }else */
    if (file == NULL)
    {
    printf("Usuario não se encontra no sistema!!.\n");
    printf("\n\nPressione qualquer tecla para retornar ao menu....");
    getchar();
   }
   
}
int main() 
{
    int opcao=0;//definindo variaveis

    int laco=1;

    for(laco=1;laco=1;)
    {

    

        setlocale(LC_ALL, "portuguese"); // determina a linguagem, basicamente é para converter acentos e etc...
    
        printf("##### Cartório EBAC #########\n\n");//inicio do menu
        printf("Escolha a opção desejada do menu:\n\n");
        printf("\t1 - Registrar nomes\n\n");
        printf("\t2 - Consultar nomes\n\n");
        printf("\t3 - Deletar nomes\n\n");
        printf("\t4 - Sair do sistema\n\n");
        printf("\topção:  ");//fim do menu
        

        scanf("%d", &opcao);//armazenando a opção do usuario

        int c;
        while ((c = getchar()) != '\n' && c != EOF) { }

        system("clear");

        switch(opcao)
        {

            case 1:
            registro();
            break;

            case 2:
            consulta();
            break;

            case 3:
            deleta();
            break;

            case 4:
            printf("Obrigado por utilizar o sistema!!\n\n");
            return 0;
            break;

            default:
            printf("\nVocê escolheu uma opção invalida, tente novamente!\n\n");
            getchar();
            break;

        }
    /*
        if(opcao==1)//inicio da seleção
        {
            printf("\nVoce escolheu registrar nomes!\n\n");
            system("pause");
        }
        if(opcao==2)
        {
            printf("\nVoce escolheu consultar nomes!\n\n");
            system("pause");
        }
        if(opcao==3)
        {
            printf("\nVoce escolheu deletar nomes!\n\n");
            system("pause");
        }
        if(opcao>=4)
        {
            printf("\nEssa opção não existe!\n\n");
            system("pause");
        }
        if(opcao<=0)
        {
            printf("\nEssa opção não existe!\n\n");
            system("pause");
        }//fim da seleção
                
        printf("Esse software é de livre uso dos alunos\n\n");
        */
    }
}  
