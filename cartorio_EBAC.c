#include <stdio.h> //biblioteca de comunicação com o usuário.
#include <stdlib.h> //bibiloteca de alocação de espaço de memória.
#include <locale.h> //biblioteca de alocação de texto por região.
#include <string.h> //biblioteca responsável por cuidar das strings.

int registrar() //Função responsável por registrar usuários no sistema
{

//Início variáveis

                    char arquivo[200];
                    char cpf[40];
                    char primeiro_nome[40];
                    char ultimo_none[40];
                    char cargo[40];

//Fim variáveis

                                                    //Inicio CPF

                        printf("Digite o CPF: ");
                        scanf("%s", cpf); //Refere-se a string

                        strcpy(arquivo, cpf);

                        FILE *file;

                        file = fopen(arquivo, "w");
                        fprintf(file, "\nCPF: ");
                        fclose(file);

                        file = fopen(arquivo, "a");
                        fprintf(file, cpf);
                        fclose(file);

                                                    //Fim CPF
                                                    //Inicio NOME

                        file = fopen(arquivo, "a");
                        fprintf(file, "\nNOME: ");
                        fclose(file);

                        printf("Digite o primeiro nome: ");
                        scanf("%s", primeiro_nome);

                        file = fopen(arquivo, "a");
                        fprintf(file, primeiro_nome);
                        fclose(file);

                        file = fopen(arquivo, "a");
                        fprintf(file, " ");
                        fclose(file);

                                                    //Fim NOME
                                                    //Inicio SOBRENOME

                        file = fopen(arquivo, "a");
                        fprintf(file, "\nSOBRENOME: ");
                        fclose(file);

                        printf("Digite o último nome: ");
                        scanf("%s", ultimo_none);

                        file = fopen(arquivo, "a");
                        fprintf(file, ultimo_none);
                        fclose(file);

                        file = fopen(arquivo, "a");
                        fprintf(file, " ");
                        fclose(file);

                                                    //Fim SOBRENOME
                                                    //Inicio CARGO

                        file = fopen(arquivo, "a");
                        fprintf(file, "\nCARGO: ");
                        fclose(file);

                        printf("Digite o cargo: ");
                        scanf("%s", cargo);

                        file = fopen(arquivo, "a");
                        fprintf(file, cargo);
                        fprintf(file, "\n");
                        fclose(file);

                                                    //Fim CARGO

                        system("pause");


}

int consultar()   //Função responsável por consultar usuários no sistema
{
                    setlocale(LC_ALL, "Portuguese");

//Início variáveis

                    char cpf[40];
                    char conteudo[200];

//Fim variáveis

                        printf("Consulte o número de CPF: ");
                        scanf("%s", cpf);


                        FILE *file;
                        file = fopen(cpf, "r");


                        if(file == NULL)
                        {
                            printf("Não foi possível localizar este CPF!.\n");
                        }

                        while(fgets(conteudo, 200, file) != NULL)
                        {
                            printf("%s", conteudo);
                            printf("\n");
                        }

                            system("pause");
                        fclose(file);
}

int deletar() //Função responsável por deletar usuários no sistema
{

//Início variáveis

                   char cpf[40];

//Fim variáveis

                        printf("Digite o CPF a ser deletado: ");
                        scanf("%s", cpf);

                        remove(cpf);

                        FILE *file;
                        file = fopen(cpf, "r");
                        fclose(file);

                        if(file == NULL)
                        {
                            printf("CPF deletado com sucesso!\n\n");
                            system("pause");
                        }

}


int main()
{

//Variáveis
                    int opcao = 0;
                    int loop = 1;

                    for(loop = 1; loop = 1;)
    {
                    system("cls");


                        setlocale(LC_ALL, "Portuguese"); //Definição do idioma.

//Inicio do menu.
                        printf("###Cartório da EBAC###\n\n");
                        printf("Escolha a opção desejada do menu:\n\n");
                        printf("\t1 - Registrar novo cliente\n");
                        printf("\t2 - Consultar nome de cliente\n");
                        printf("\t3 - Deletar cliente\n\n");
                        printf("Opção:");
//Fim do menu.
//Inicio do submenu.
                        scanf("%d", &opcao);

                        system("cls");

                        switch(opcao)
                        {
                            case 1:
                            registrar();
                            break;

                            case 2:
                            consultar();
                            break;

                            case 3:
                            deletar();
                            break;

                            default:
                            printf("Esta opção não está disponível\n\n");
                            system("pause");
                            break;
                        }

//Fim do submenu.

    }
}

