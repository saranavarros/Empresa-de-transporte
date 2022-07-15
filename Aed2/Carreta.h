#define QTD_CARRETAS 4

typedef struct carreta {
  int numeracao;
  int emTransito;
  struct carreta* prox;
} Carreta;

typedef struct listaCarretas {
   int qtd;
   Carreta* primeiro;
} ListaCarretas;

Carreta* criaCarreta(ListaCarretas* lc, int numeracao) {
    Carreta* c = malloc(sizeof(Carreta));
    c->numeracao = numeracao;
    c->emTransito = 0;
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

ListaCarretas* criaListaCarretas() {
    ListaCarretas* lc = malloc(QTD_CARRETAS * sizeof(Carreta));
    lc->primeiro = NULL;
    for (int i = 0; i < QTD_CARRETAS; i++) {
        int numeracao = i + 1;
        criaCarreta(lc, numeracao);
    }
    return lc;
}