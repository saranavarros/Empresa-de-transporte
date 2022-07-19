#define QTD_CARRETAS 40

typedef struct carreta {
  int numeracao;
  struct carreta* prox;
} Carreta;

typedef struct listaCarretas {
   int qtd;
   Carreta* primeiro;
} ListaCarretas;

Carreta* criaCarreta(ListaCarretas* lc, int numeracao) {
    Carreta* c = malloc(sizeof(Carreta));
    c->numeracao = numeracao;
    c->prox = NULL;
    
    if (lc->primeiro == NULL) {
        lc->primeiro = c;
    }
    else {
        Carreta* aux = lc->primeiro;
        while(aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = c;
    }
    
    return c;
}

Carreta* buscaCarreta(ListaCarretas* lc, int numeracao) {
    Carreta* aux = lc->primeiro;
    while(aux->numeracao != numeracao && aux->prox != NULL) {
        aux = aux->prox;
    }
    return aux;
}