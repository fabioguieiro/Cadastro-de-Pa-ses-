#ifndef LISTAPAIS_H_INCLUDED
#define LISTAPAIS_H_INCLUDED

struct pais{
    char nome[14];
    char grupo;
    char idioma[12];
    float populacao;
};typedef struct pais Pais;

struct no {
    Pais info;
    struct no* prox;
};typedef struct no No;

struct lingua{
    char idioma[12];
    int contador;
    struct lingua* prox;
};typedef struct lingua Lingua;


typedef struct lingua Lingua;
typedef struct no No;
typedef struct pais Pais;

Lingua* inserirIdioma(Lingua* l, char* linguagem);
No* inserir_inicio(No* l, Pais* pais);
No* remover(No* l,char* nome);
int igual(Pais a, Pais b);
void imprimir(No* l);
Pais maiorPop(No* l);
void buscar(No* l, char idioma[]);
void grava(No* l);
No* inserirPais(No* l);
void imprimirPais(No* p);
No* remover(No* l,char* nome);
No* obterLista();
void liberarLingua(Lingua* l);
void liberarPais(No* l);
Lingua* maisFalado(No* l);
int numPaises(No* l);
float populacaoTotal(No* l);



//-----------Arvore AVL----------------------------------------------------------------------------------------------------------------------------

typedef struct No_avl* ArvAVL;

void lista2AVL(No* l, ArvAVL* a);
ArvAVL* cria_ArvAVL();
void libera_ArvAVL(ArvAVL *raiz);
int insere_ArvAVL(ArvAVL *raiz, Pais valor);
int remove_ArvAVL(ArvAVL *raiz, char valor[]);
int estaVazia_ArvAVL(ArvAVL *raiz);
int altura_ArvAVL(ArvAVL *raiz);
int totalNO_ArvAVL(ArvAVL *raiz);
int consulta_ArvAVL(ArvAVL *raiz, char valor[]);
void preOrdem_ArvAVL(ArvAVL *raiz);
void emOrdem_ArvAVL(ArvAVL *raiz);
void posOrdem_ArvAVL(ArvAVL *raiz);

void RotacaoLL(ArvAVL *A);
void RotacaoRR(ArvAVL *A);
void RotacaoLR(ArvAVL *A);
void RotacaoRL(ArvAVL *A);


//-----------HEAP----------------------------------------------------------------------------------------------------------------------------

typedef struct {
  struct pais* A;
  int tamanhoAtual;
  int tamanhoMaximo;
} HEAP;

typedef int bool;

void inicializarHeap(HEAP * h, int tamanhoMax);
void destruirHeap(HEAP * h);
int pai(int i);
int filhoEsquerda(int i);
int filhoDireita(int i);
void maxHeapify(HEAP * h, int i);
void construirHeapMaximo(HEAP * h);
bool inserirForaDeOrdem(HEAP * h, struct pais valor);
void imprimirIdioma (HEAP* h, char idioma[]);
void imprimirArranjo(HEAP *h);
void heapSort(HEAP * h,char idioma[]);
bool inserirHeap(HEAP * h, struct pais chave);
int percursoPreOrdem(HEAP* h, int atual,char idioma[]);
int alturaHeap(HEAP* h);
void deleta(HEAP * h, int posicao);
void heapify_down(HEAP * h, int v);
#endif //LISTAPAIS_H_INCLUDED
