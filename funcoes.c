#include "stdlib.h"
#include "stdio.h"
#include "funcoes.h"
#include <string.h>

int comparacoes=0;


Lingua* inserirIdioma(Lingua* l, char* linguagem){
    Lingua* p;
    for(p=l;p!=NULL;p=p->prox){
        if(strcmp(linguagem ,p->idioma) == 0){
            p->contador++;
            return l;
        }
    }
    Lingua* novo = (Lingua*) malloc(sizeof(Lingua));
    strcpy(novo->idioma,linguagem);
    novo->contador = 1;
    novo->prox = l;
    return novo;
}

No* inserir_inicio(No* l, Pais* pais) {
    No* novo = (No*) malloc(sizeof(No));
    novo->info = *pais;
    novo->prox = l;
    return novo;
}

int igual(Pais a, Pais b){
    if (strcmp(a.idioma, b.idioma) == 0){
        return 1;
    }
    return 0;
}
void imprimir(No* l) {
    No* p;
    for(p = l; p != NULL; p = p->prox) {
        printf("Pais: %s|Grupo: %c|Idioma: %s|Populacao: %.3f milhoes", p->info.nome, p->info.grupo, p->info.idioma, p->info.populacao);
        printf("\n");
    }
}
Pais maiorPop(No* l){
    No* p;
    float maior = 0;
    Pais maiorPais;
    for(p = l; p != NULL; p = p->prox) {
        if(p->info.populacao > maior){
            maior = p->info.populacao;
            maiorPais = p->info;
        }
    }
    return maiorPais;
}

void buscar(No* l, char idioma[]) {
    No *p = l;
    int i=0;
    while (p!=NULL){
            if (strcmp(p->info.idioma,idioma)==0){
                printf("\n---------------------------------------------\nPaís: %s\nGrupo: %c\nIdioma: %s\nPopulacao: %.3f milhoes\n---------------------------------------------\n",p->info.nome,p->info.grupo,p->info.idioma,p->info.populacao);
                i++;
            }
            p=p->prox;
        }
        if(i!=0) printf("\nIdioma nao encontrado na base de dados\n");
    }


void grava(No* l){
    FILE *arq = fopen("paises.txt", "w");
    No* p;
    for(p = l; p != NULL; p = p->prox) {
        fprintf(arq,"%s %s %c %.3f\r\n", p->info.nome, p->info.idioma, p->info.grupo, p->info.populacao);
    }
    fclose(arq);
}
No* inserirPais(No* l){
    char c;
    Pais* novo = (Pais*)malloc(sizeof(Pais));
    printf("Entre com o nome do pais: ");
    scanf("%s",novo->nome);
    fflush(stdin);
    printf("Entre com o idioma do pais: ");
    scanf("%s",novo->idioma);
    fflush(stdin);
    printf("Entre com o grupo do pais: ");
    scanf("%c",&novo->grupo);
    fflush(stdin);

    printf("Entre com a populacao do pais: ");
    scanf("%f",&novo->populacao);
    l = inserir_inicio(l,novo);
    printf("Pais inserido com sucesso!\n");
    grava(l);
    return l;

}
void imprimirPais(No* p){
    printf("Pais: %s| Idioma: %s | Grupo: %c| Populacao: %.3f\n",p->info.nome,p->info.idioma,p->info.grupo,p->info.populacao);

}
No* remover(No* l,char* nome) {
    No* ant = NULL;
    No* p = l;
    while (p != NULL && strcmp(p->info.nome,nome)!=0) {
        ant = p;
        p = p->prox;
    }
    if (p == NULL) {
        printf("Pais nao encontrado!\n");
        return l;
    }
    if (ant == NULL) {
        printf("Pais removido com sucesso!\n");
        l = p->prox;
    }
    else {
        printf("Pais removido com sucesso!\n");
        ant->prox = p->prox;
    }
    printf("NOVA LISTA:\n");
    imprimir(l);
    free(p);
    grava(l);
    return l;
}

No* obterLista(){
    No* l = NULL;
    FILE * arq;
    float populacao;
    char nomepais[13], idioma[12];
    char grupo;
    arq=fopen("paises.txt","r");
    if ( arq == NULL ) {
        printf("Erro ao abrir o arquivo <<paises.txt>>");
        return NULL;
        exit(-1);
    };

    while ( fscanf(arq,"%s %s %c %f\n",nomepais,idioma,&grupo,&populacao) != EOF ){
       Pais* pais = (Pais*)malloc(sizeof(Pais));
       strcpy(pais->nome,nomepais);
       strcpy(pais->idioma,idioma);
       pais->grupo = grupo;
       pais->populacao = populacao;
       l = inserir_inicio(l,pais);
       free(pais);
   };
    fclose(arq);
    return l;
}
void liberarLingua(Lingua* l) {
    Lingua* p = l;
    while (p != NULL) {
        Lingua* t = p->prox;
        free(p);
        p = t;
    }
}
void liberarPais(No* l) {
    No* p = l;
    while (p != NULL) {
        No* t = p->prox;
        free(p);
        p = t;
    }
}
Lingua* maisFalado(No* l){
    No* p;
    Lingua* listaLinguas = NULL;
    Lingua* aux;
    Lingua* falado = NULL;
    for(p = l; p != NULL; p = p->prox){
        listaLinguas = inserirIdioma(listaLinguas,p->info.idioma);
    }
    for(p=l;p!=NULL;p=p->prox){
        for(aux = listaLinguas;aux!=NULL;aux=aux->prox){
            if(p->info.idioma == aux->idioma){
                aux->contador++;
            }
        }
    }
    int maior = 0;
    for(aux=listaLinguas;aux!=NULL;aux=aux->prox){
        if(aux->contador > maior){
            falado = aux;
            maior = aux->contador;
        }
    }
    free(aux);

    return falado;
}
int numPaises(No* l){
    No* p;
    int cont = 0;
    for(p = l; p != NULL; p = p->prox) {
        cont++;
    }
    return cont;
}

float populacaoTotal(No* l) {
    No *p;
    float soma = 0;
    for (p = l; p != NULL; p = p->prox) {
        soma+= p->info.populacao;
    }
    return soma;
}


void lista2AVL(No* l,ArvAVL* a){
    No *p = l;
    while (p!=NULL){
        insere_ArvAVL(a, p->info);
        p=p->prox;
    }
}

//-----------Arvore AVL----------------------------------------------------------------------------------------------------------------------------

struct No_avl
{
    Pais info;
    int altura;
    struct No_avl *esq;
    struct No_avl *dir;
};

ArvAVL* cria_ArvAVL()
{
    ArvAVL* raiz = (ArvAVL*) malloc(sizeof(ArvAVL));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;
}
void libera_NO(struct No_avl* no)
{
    if(no == NULL)
        return;
    libera_NO(no->esq);
    libera_NO(no->dir);
    free(no);
    no = NULL;
}
void libera_ArvAVL(ArvAVL* raiz)
{
    if(raiz == NULL)
        return;
    libera_NO(*raiz);//libera cada nó
    free(raiz);//libera a raiz
}

int altura_NO(struct No_avl* no)
{
    if(no == NULL)
        return -1;
    else
        return no->altura;
}

int consulta_ArvAVL(ArvAVL *raiz, char valor[])
{
    if(raiz == NULL)
        return 0;
    struct No_avl* atual = *raiz;
    while(atual != NULL)
    {
        if(strcmp(valor, atual->info.idioma)==0)
        {
            imprime(atual->info);
            return 1;
        }
        if(strcmp(valor, atual->info.idioma) > 0)
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    return 0;
}
void imprime(Pais d) //imprime um drone
{
    printf("\Pais: %s",d.nome);
    printf("\nGrupo: %c",d.grupo);
    printf("\nIdioma: %s",d.idioma);
    printf("\nPopulacao: %.3f",d.populacao);
    printf("\n");
}



int fatorBalanceamento_NO(struct No_avl* no)
{
    return labs(altura_NO(no->esq) - altura_NO(no->dir));
}

int maior(int x, int y)
{
    if(x > y)
        return x;
    else
        return y;
}

int estaVazia_ArvAVL(ArvAVL *raiz)
{
    if(raiz == NULL)
        return 1;
    if(*raiz == NULL)
        return 1;
    return 0;
}

int totalNO_ArvAVL(ArvAVL *raiz)
{
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;
    int alt_esq = totalNO_ArvAVL(&((*raiz)->esq));
    int alt_dir = totalNO_ArvAVL(&((*raiz)->dir));
    return(alt_esq + alt_dir + 1);
}

int altura_ArvAVL(ArvAVL *raiz)
{
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;
    int alt_esq = altura_ArvAVL(&((*raiz)->esq));
    int alt_dir = altura_ArvAVL(&((*raiz)->dir));
    if (alt_esq > alt_dir)
        return (alt_esq + 1);
    else
        return(alt_dir + 1);
}

void preOrdem_ArvAVL(ArvAVL *raiz)
{
    if(raiz == NULL)
        return;
    if(*raiz != NULL)
    {
        printf("No %d: %d\n",(*raiz)->info,altura_NO(*raiz));
        preOrdem_ArvAVL(&((*raiz)->esq));
        preOrdem_ArvAVL(&((*raiz)->dir));
    }
}

void emOrdem_ArvAVL(ArvAVL *raiz)
{
    if(raiz == NULL){
        printf("\narvore vazia\n");
    return;
    }
    if(*raiz != NULL)
    {
        emOrdem_ArvAVL(&((*raiz)->esq));
        printf("No %s: H(%d) fb(%d)\n",(*raiz)->info.idioma,altura_NO(*raiz),fatorBalanceamento_NO(*raiz));
        emOrdem_ArvAVL(&((*raiz)->dir));
    }
}

void posOrdem_ArvAVL(ArvAVL *raiz)
{
    if(raiz == NULL)
        return;
    if(*raiz != NULL)
    {
        posOrdem_ArvAVL(&((*raiz)->esq));
        posOrdem_ArvAVL(&((*raiz)->dir));
        printf("%d\n",(*raiz)->info);
    }
}



//=================================
void RotacaoLL(ArvAVL *A) //LL
{
    printf("RotacaoLL\n");
    struct No_avl *B;
    B = (*A)->esq;
    (*A)->esq = B->dir;
    B->dir = *A;
    (*A)->altura = maior(altura_NO((*A)->esq),altura_NO((*A)->dir)) + 1;
    B->altura = maior(altura_NO(B->esq),(*A)->altura) + 1;
    *A = B;
}

void RotacaoRR(ArvAVL *A) //RR
{
    printf("RotacaoRR\n");
    struct No_avl *B;
    B = (*A)->dir;
    (*A)->dir = B->esq;
    B->esq = (*A);
    (*A)->altura = maior(altura_NO((*A)->esq),altura_NO((*A)->dir)) + 1;
    B->altura = maior(altura_NO(B->dir),(*A)->altura) + 1;
    (*A) = B;
}

void RotacaoLR(ArvAVL *A) //LR
{
    RotacaoRR(&(*A)->esq);
    RotacaoLL(A);
}

void RotacaoRL(ArvAVL *A) //RL
{
    RotacaoLL(&(*A)->dir);
    RotacaoRR(A);
}

int insere_ArvAVL(ArvAVL *raiz, Pais valor)
{
    int res;
    if(*raiz == NULL) //árvore vazia ou nó folha
    {
        comparacoes++;
        struct No_avl *novo;
        novo = (struct No_avl*)malloc(sizeof(struct No_avl));
        if(novo == NULL)
            return 0;

        novo->info = valor;
        novo->altura = 0;
        novo->esq = NULL;
        novo->dir = NULL;
        *raiz = novo;
        return 1;
    }
    struct No_avl *atual = *raiz;
    if(strcmp(valor.idioma, atual->info.idioma) <0)
    {
        comparacoes++;
        if((res = insere_ArvAVL(&(atual->esq), valor)) == 1)
        {
            comparacoes++;
            if(fatorBalanceamento_NO(atual) >= 2)
            {
                comparacoes++;
                if(strcmp(valor.idioma, (*raiz)->esq->info.idioma)<0)
                {
                    comparacoes++;
                    RotacaoLL(raiz);
                }
                else
                {
                    comparacoes++;
                    RotacaoLR(raiz);
                }
            }
        }
    }
    else
    {
        comparacoes++;
        if(strcmp(valor.idioma, atual->info.idioma)>0)
        {
            comparacoes++;
            if((res = insere_ArvAVL(&(atual->dir), valor)) == 1)
            {
                comparacoes++;
                if(fatorBalanceamento_NO(atual) >= 2)
                {
                    comparacoes++;
                    if(strcmp((*raiz)->dir->info.idioma, valor.idioma)<0)
                    {
                        comparacoes++;
                        RotacaoRR(raiz);
                    }
                    else
                    {
                        comparacoes++;
                        RotacaoRL(raiz);
                    }
                }
            }
        }
        else
        {
            comparacoes++;
            printf("Valor duplicado!!\n");
            return 0;
        }
    }

    atual->altura = maior(altura_NO(atual->esq),altura_NO(atual->dir)) + 1;
    return res;
}
void getcomp(){
       printf("\n foram feitas %d comparacoes\n", comparacoes);
       comparacoes=0;
}

struct NO* procuraMenor(struct No_avl* atual)
{
    struct No_avl *no1 = atual;
    struct No_avl *no2 = atual->esq;
    while(no2 != NULL)
    {
        no1 = no2;
        no2 = no2->esq;
    }
    return no1;
}

int remove_ArvAVL(ArvAVL *raiz, char valor[])
{
    if(*raiz == NULL) // valor não existe
    {
        printf("valor nao existe!!\n");
        return 0;
    }

    int res;
    if(strcmp(valor, (*raiz)->info.idioma)< 0)
    {
        if((res = remove_ArvAVL(&(*raiz)->esq,valor)) == 1)
        {
            if(fatorBalanceamento_NO(*raiz) >= 2)
            {
                if(altura_NO((*raiz)->dir->esq) <= altura_NO((*raiz)->dir->dir))
                    RotacaoRR(raiz);
                else
                    RotacaoRL(raiz);
            }
        }
    }

    if(strcmp((*raiz)->info.idioma, valor)< 0)
    {
        if((res = remove_ArvAVL(&(*raiz)->dir, valor)) == 1)
        {
            if(fatorBalanceamento_NO(*raiz) >= 2)
            {
                if(altura_NO((*raiz)->esq->dir) <= altura_NO((*raiz)->esq->esq) )
                    RotacaoLL(raiz);
                else
                    RotacaoLR(raiz);
            }
        }
    }

    if(strcmp((*raiz)->info.idioma, valor) == 0)
    {
        if(((*raiz)->esq == NULL || (*raiz)->dir == NULL)) // nó tem 1 filho ou nenhum
        {
            struct No_avl *oldNode = (*raiz);
            if((*raiz)->esq != NULL)
                *raiz = (*raiz)->esq;
            else
                *raiz = (*raiz)->dir;
            free(oldNode);
        }
        else    // nó tem 2 filhos
        {
            struct No_avl* temp = procuraMenor((*raiz)->dir);
            (*raiz)->info = temp->info;
            remove_ArvAVL(&(*raiz)->dir, (*raiz)->info.idioma);
            if(fatorBalanceamento_NO(*raiz) >= 2)
            {
                if(altura_NO((*raiz)->esq->dir) <= altura_NO((*raiz)->esq->esq))
                    RotacaoLL(raiz);
                else
                    RotacaoLR(raiz);
            }
        }
        if (*raiz != NULL)
            (*raiz)->altura = maior(altura_NO((*raiz)->esq),altura_NO((*raiz)->dir)) + 1;
        return 1;
    }

    (*raiz)->altura = maior(altura_NO((*raiz)->esq),altura_NO((*raiz)->dir)) + 1;

    return res;
}





//-----------Heap Máxima---------------------------------------------------------------------------------------------------------------------------

void lista2HEAP(No* l,HEAP* h){
    No *p = l;
    while (p!=NULL){
        inserirHeap(h,p->info);
        p=p->prox;
    }
}


void inicializarHeap(HEAP * h, int tamanhoMax)
{
    h->A = (Pais*) malloc(sizeof(Pais)*(tamanhoMax+1));
    h->tamanhoAtual = 0;
    h->tamanhoMaximo = tamanhoMax;
}

void destruirHeap(HEAP * h)
{
    int tamanho = h->tamanhoMaximo;
    free(h->A);
    h->tamanhoMaximo=0;
    h->tamanhoAtual=0;
}

void deleta(HEAP * h, int posicao){
    struct pais aux;
    printf("\n_________________________________________\n");
    printf("Pais: %s\n",h->A[posicao].nome);
    printf("Idioma: %s\n",h->A[posicao].idioma);
    printf("Grupo: %c\n",h->A[posicao].grupo);
    printf("População: %.3f\n",h->A[posicao].populacao);
    printf("\n_________________________________________\n");
    aux= h->A[posicao];
    h->A[posicao] = h->A[h->tamanhoAtual];
    h->A[h->tamanhoAtual] = aux;
    h->tamanhoAtual--;
    heapify_down(h,posicao);
}


void heapify_down(HEAP * h, int v){

    int d = filhoDireita(v);
    int e = filhoEsquerda(v);

    int maior = v;

    if(d <= h->tamanhoAtual && strcmp(h->A[d].idioma, h->A[maior].idioma)> 0) maior = d;
    if(e <= h->tamanhoAtual && strcmp(h->A[e].idioma, h->A[maior].idioma)> 0) maior = e;

    if(maior != v){


        struct pais aux;
        aux= h->A[v];
        h->A[v] = h->A[maior];
        h->A[maior] = aux;

        heapify_down(h,maior);
    }
}


int pai(int i)
{
    return i/2;
}

int filhoEsquerda(int i)
{
    return 2*i;
}

int filhoDireita(int i)
{
    return 2*i + 1;
}


/* metodo auxiliar que pressupoe que o heap para qualquer j>i estah ordenado
   porem o elemento i nao eh necessariamente maior que seus filhos           */
void maxHeapify(HEAP * h, int i)
{
    int esq = filhoEsquerda(i);
    int dir = filhoDireita(i);
    char temp[12];
    int maior = i;
    if ((esq <= h->tamanhoAtual) && strcmp(h->A[esq].idioma, h->A[i].idioma)>0)
        maior = esq;
    if ((dir <= h->tamanhoAtual) && strcmp(h->A[dir].idioma, h->A[maior].idioma)>0)
        maior = dir;
    if (maior != i)
    {
        strcpy (temp ,h->A[i].idioma);
        h->A[i] = h->A[maior];
        strcpy (h->A[maior].idioma, temp);
        maxHeapify(h,maior);
    }
}

// Constroi heap a partir do arranjo usando o metodo maxHeapify
void construirHeapMaximo(HEAP * h)
{
    int i;
    int metadeTamanho = h->tamanhoAtual/2;
    for (i=metadeTamanho; i>0; i--)
        maxHeapify(h,i);
}

// no final do arranjo do heap
bool inserirForaDeOrdem(HEAP * h, struct pais valor)
{
    if (h->tamanhoAtual < h->tamanhoMaximo)
    {
        (h->tamanhoAtual)++;
        h->A[h->tamanhoAtual] = valor;
        return 1;
    }
    return 0;
}


// Imprime o arranjo (na ordem que estiver)
void imprimirArranjo(HEAP *h)
{
    int tamanho = h->tamanhoAtual;
    int i;
    for (i=0; i<tamanho; i++)
        printf("%s \n",h->A[i].idioma);
    printf("\n");
}

void imprimirIdioma (HEAP* h, char idioma[])
{
    int tamanho = h->tamanhoAtual;
    int i;
    for (i=0; i<=tamanho; i++){
        if (strcmp(h->A[i].idioma, idioma)==0){
                printf("\nPais: %s",h->A[i].nome);
                printf("\nIdioma: %s",h->A[i].idioma);
                printf("\nGrupo: %c",h->A[i].grupo);
                printf("\nPopulacao: ",h->A[i].populacao);
                printf("\n");
        }

    }

    printf("\n");
}




// Imprime elementos em ordem decrescente e esvazia o heap
void heapSort(HEAP * h,char idioma[])
{
    int tamanho = h->tamanhoAtual;
    int i;
    struct pais temp;
    construirHeapMaximo(h);  // se o arranjo ja for um heap, nao precisa desta linha
    for (i=tamanho; i>1; i--)
    {
        temp = h->A[1];
        h->A[1] = h->A[i];
        h->A[i]= temp;

        if(strcmp(h->A[i].idioma,idioma)==0){
        printf("\nPais: %s",h->A[i].nome);
        printf("\nIdioma: %s",h->A[i].idioma);
        printf("\nGrupo: %c",h->A[i].grupo);
        printf("\nPopulacao: ",h->A[i].populacao);
    }
        (h->tamanhoAtual)--;
        maxHeapify(h,1);
    }
    printf("\n");
    h->tamanhoAtual = tamanho;
}

bool inserirHeap(HEAP * h, struct pais chave)
{
    int i;
    struct pais temp;
    comparacoes++;
    if (h->tamanhoAtual == h->tamanhoMaximo)
        return 0;


    (h->tamanhoAtual)++;
    i = h->tamanhoAtual;

    h->A[i] = chave;
    while ((i>0) && (strcmp(h->A[pai(i)].idioma, h->A[i].idioma)))
    {
        comparacoes++;
        comparacoes++;
        temp = h->A[i];
        h->A[i] = h->A[pai(i)];
        h->A[pai(i)] = temp;
        i = pai(i);
    }
    comparacoes++;
    comparacoes++;
    return 1;
}

int percursoPreOrdem(HEAP* h, int atual,char idioma[])
{
    printf("\n*Imprimindo em pre ordem*\n");
    if (atual <= h->tamanhoAtual)
    {
        if(strcmp(idioma,h->A[atual].idioma)==0)
            printf("%i - %s ", h->A[atual],h->A[atual].idioma);
        percursoPreOrdem(h, filhoEsquerda(atual),idioma);
        percursoPreOrdem(h, filhoDireita(atual),idioma);
    }
}

int alturaHeap(HEAP* h)
{
    int altura = -1;
    int i = 1;
    while (i <= h->tamanhoAtual)
    {
        i = filhoEsquerda(i);
        altura++;
    }
    return altura;
}

