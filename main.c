#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "funcoes.h"

int main()
{
    int n,m, menu2,i;
    char c, idio[12];
    No* lista = NULL;
    Pais pais;
    Pais pais2;
    Lingua* lingua = NULL;
    ArvAVL* a = NULL;
    a=cria_ArvAVL();
    HEAP *h;
    do
    {
        system("cls");
        menu2=-1;
        printf("1 - Parte 1 do Trabalho Pratico\n"
               "2 - Parte 2 do Trabalho Pratico\n"
               "3 - Parte 3 do Trabalho Pratico\n"
               "4 - Terminar: \n");
        printf("Entre com a opcao: ");
        scanf("%d",&n);
        switch(n)
        {
        case 1:
            do
            {
                system("cls");
                printf("1 - Ler os paises do arquivo texto e inserir na estrutura Lista\n"
                       "2 - Exibir os paises\n"
                       "3 - Buscar um pais pelos seus campos\n"
                       "4 - Remover pais pelo campo 'Nome'\n"
                       "5 - Inserir um pais\n"
                       "6 - Buscar pais com o maior populaçao\n"
                       "7 - Exibir o numero de paises na copa, a populacao media dos paises na copa,\n    a soma da populacao de todos os paises na copa e o idioma mais falado\n"
                       "8 - Liberar as estruturas alocadas e voltar para a tela anterior\n");


                printf("Entre com a opcao: ");
                scanf("%d",&m);
                switch(m)
                {
                case 1:
                    system("cls");
                    lista = obterLista();
                    if(lista==NULL)
                        printf("Arquivo vazio!\n");
                    else
                        printf("Leitura realizada com sucesso!\n");
                    system("pause");
                    break;
                case 2:
                    system("cls");
                    if(lista!=NULL)
                    {
                        imprimir(lista);
                    }
                    else
                    {
                        printf("Lista de paises esta vazia!\n");
                    }
                    system("pause");
                    break;
                case 3:
                    system("cls");
                    scanf("%c",&c);
                    printf("Entre com o idioma falado no pais: ");
                    gets(pais.idioma);
                    buscar(lista,pais.idioma);
                    system("pause");
                    break;
                case 4:
                    system("cls");
                    printf("Entre com o nome do pais a ser removido: ");
                    scanf("%s",&pais.nome);
                    lista = remover(lista,pais.nome);
                    system("pause");
                    break;
                case 5:
                    system("cls");
                    lista = inserirPais(lista);
                    system("pause");
                    break;
                case 6:
                    system("cls");
                    pais2 = maiorPop(lista);
                    printf("Nome: %s\nGrupo: %c\nIdioma: %s\nPopulacao: %.3f\n",pais2.nome,pais2.grupo,pais2.idioma,pais2.populacao);
                    system("pause");
                    break;
                case 7:
                    system("cls");
                    lingua = maisFalado(lista);
                    printf("Numero de paises na copa: %d\n",numPaises(lista));
                    printf("Lingua mais falada: %s\nPaises que falam %s: %d\n",lingua->idioma,lingua->idioma,lingua->contador);
                    float a = populacaoTotal(lista);
                    int totalPaises = numPaises(lista);
                    float media = a/(float)totalPaises;
                    printf("Populacao total em milhoes: %.3f\n",a);
                    printf("Populacao media em milhoes: %.3f\n",media);
                    system("pause");
                case 8:
                    system("cls");
                    if(lingua != NULL)
                        liberarLingua(lingua);
                    if(lista != NULL)
                        liberarPais(lista);
                    system("pause");
                    break;
                default:
                    system("cls");
                    printf("Digito invalido!\n");
                    system("pause");
                    break;
                }
                printf("\n");
            }
            while(m!=8);
            break;
        case 2:
            while(menu2!=0)
            {
                system("cls");
                printf("\n\t*Bem vindo a parte 2 do trabalho*\n");
                printf("escolha uma opcao:\n");
                printf("1- Ler os paises do arquivo texto e inserir na lista\n");
                printf("2- Exibir os paises\n");
                printf("3- Montar arvore AVL pela chave 'idioma'\n");
                printf("4- Exibir a arvore AVL pela chave 'idioma'\n");
                printf("5- Buscar e exibir um país segundo a chave digitada pelo usuario\n");
                printf("6- Remover da arvore AVL um pais segundo a chave que foi digitada\n");
                printf("7- Inserir na arvore AVL um pais que sera digitado pelo usuario e exibir o numero de comparacoes executadas\n");
                printf("8- Liberar a arvore AVL da memoria\n");
                printf("9- Montar o heap maximo com a chave 'idioma'\n");
                printf("10- Exibir o heap maximo na tela\n");
                printf("11- Buscar e exibir um pais segundo a chave digitada pelo usuario\n");
                printf("12- Remover o pais raiz do heap e exibir a chave removida\n");
                printf("13- Inserir no heap um pais que sera digitado pelo usuario e exibir quantas comparacoes foram feitas\n");
                printf("14- Remover e exibir sucessivamente na tela o conteudo da chave de cada elemento raiz do heap, ate que o heap nao mais exista\n");
                printf("15-  Liberar a Lista e fechar o programa\n");
                printf("0- Voltar ao menu anterior");
                scanf("%d",&menu2);
                switch(menu2){
                case 1:
                    system("cls");
                    lista = obterLista();
                    if(lista==NULL)
                        printf("Arquivo vazio!\n");
                    else
                        printf("Leitura realizada com sucesso!\n");
                    system("pause");
                    break;
                case 2:
                    system("cls");
                    if(lista!=NULL)
                        imprimir(lista);
                    else
                        printf("Lista de paises esta vazia!\n");
                    system("pause");
                    break;
                case 3:
                    system("cls");
                    lista2AVL(lista,a);
                    system("pause");
                    break;
                case 4:
                    system("cls");
                    printf("Imprimindo em Ordem...\n");
                    emOrdem_ArvAVL(a);
                    system("pause");
                    break;
                case 5:
                    system("cls");
                    printf("Digite o idioma falado o pais que deseja procurar [EM CAPS LOCK]");
                    scanf("%s",idio);
                    consulta_ArvAVL(a,idio);
                    system("pause");
                    break;
                case 6:
                    system("cls");
                    printf("Digite o idioma no pais que deseja remover [EM CAPS LOCK]");
                    scanf("%s",&idio);
                    i= remove_ArvAVL(a,idio);
                    if(i>0){
                        printf("\n*Removido*\n");
                    }
                    system("pause");
                    break;
                case 7:
                    system("cls");
                    printf("Entre com o nome do pais: ");
                    scanf("%s",pais.nome);
                    fflush(stdin);
                    printf("Entre com o idioma do pais: [EM CAPS LOCK]");
                    scanf("%s",pais.idioma);
                    fflush(stdin);
                    printf("Entre com o grupo do pais: ");
                    scanf("%c",&pais.grupo);
                    fflush(stdin);
                    printf("Entre com a populacao do pais: ");
                    scanf("%f",&pais.populacao);
                    insere_ArvAVL(a,pais);
                    getcomp();
                    system("pause");
                    break;
                case 8:
                    system("cls");
                    printf("Liberando...\n");
                    libera_ArvAVL(a);
                    system("pause");
                    break;
                case 9:
                    system("cls");
                    printf("Inicializando heap ...\n");//Montar Heap Maximo
                    inicializarHeap(&h, 100);
                    lista2HEAP(lista,&h);
                    construirHeapMaximo(&h);
                    printf("Criado com sucesso \n\n");
                    system("pause");
                    break;
                case 10:
                    system("cls");
                    imprimirArranjo(&h);
                    system("pause");
                    break;
                case 11:
                    system("cls");
                    printf("Digite o idioma falado no pais que deseja buscar[EM CAPS LOCK]");
                    scanf("%s",&idio);
                    heapSort(&h,idio);
                    system("pause");
                    break;
                case 12:
                    system("cls");
                    deleta(&h,0);
                    system("pause");
                    break;
                case 13:
                    system("cls");
                    printf("Digite os dados do pais que deseja inserir:\n");
                    printf("\nNome: ");
                    fflush(stdin);
                    scanf("%s",&pais.nome);
                    printf("\nIdioma: ");
                    fflush(stdin);
                    scanf("%s",&pais.idioma);
                    printf("\nGrupo: ");
                    fflush(stdin);
                    scanf("%c",&pais.grupo);
                    printf("\nPopulacao: ");
                    fflush(stdin);
                    scanf("%f",&pais.populacao);
                    inserirHeap(&h, pais);
                    getcomp();
                    system("pause");
                    break;
                case 14:
                    system("cls");
                    for(i=0;i < h->tamanhoAtual-4;i++){
                        deleta(&h,0);
                        system("pause");
                    }
                    destruirHeap(&h);
                    system("pause");
                    break;
                case 15:
                    system("cls");
                    destruirHeap(&h);
                    if(lingua != NULL)
                        liberarLingua(lingua);
                    if(lista != NULL)
                        liberarPais(lista);
                    system("pause");
                case 0:
                    break;
                default:
                    system("cls");
                    printf("insira uma opcao valida\n");
                    system("pause");
                    break;
                }
            }
            break;
        case 4:
            break;
        default:
            printf("Opcao Invalida ou nao implementada\n");
            system("pause");

        }
        printf("\n");
    }
    while(n!=4);
    return 0;
}
