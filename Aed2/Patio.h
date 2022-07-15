#define QTD_PATIOS 4 

typedef struct patio {
    int id;
    int qtd;
    ListaCarretas* carretas;
    FilaMotoristas* motoristas;
    struct patio* prox;
} Patio;

typedef struct listaPatios {
   int qtd;
   Patio* primeiro;
} ListaPatios;

Patio* criaPatio(ListaPatios* lp, int id) {
    Patio* p = malloc(sizeof(Patio));
    p->id = id;
    p->qtd = 0;
    p->carretas = criaListaCarretas();
    p->motoristas = criaFilaMotoristas();
    p->prox = NULL;
    
    if (lp->primeiro == NULL) {
        lp->primeiro = p;
    }
    else {
        Patio* aux = lp->primeiro;
        while(aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = p;
    }
    
    return p;
}

Patio* buscaPatio(ListaPatios* lp,int id) {
    Patio* aux = lp->primeiro;
    while(aux->id != id && aux->prox != NULL) {
        aux = aux->prox;
    }
    return aux;
}

ListaPatios* criaListaPatios() {
    ListaPatios* lp = malloc(QTD_PATIOS * sizeof(Patio));
    lp->primeiro = NULL;
    for (int i = 0; i < QTD_PATIOS; i++) {
        int id = i + 1;
        criaPatio(lp, id);
    }
    return lp;
}

void imprimeMotoristasDoPatio(Patio* patio) {
    printf("Motoristas do Patio %d: \n", patio->id);
    Motorista* aux = patio->motoristas->primeiro;
    while(aux != NULL) {
        printf("%d ", aux->id);
        aux = aux->prox;
    }
    printf("\n");
}