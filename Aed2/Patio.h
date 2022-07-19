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

ListaCarretas* criaListaCarretas(Patio* patio);
FilaMotoristas* criaFilaMotoristas(Patio* patio);

Patio* criaPatio(ListaPatios* lp, int id) {
    Patio* p = malloc(sizeof(Patio));
    p->id = id;
    p->qtd = 0;
    p->carretas = criaListaCarretas(p);
    p->motoristas = criaFilaMotoristas(p);
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

Patio* buscaPatio(ListaPatios* lp, int id) {
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
        int id = (i + 1) * 1000;
        criaPatio(lp, id);
    }
    return lp;
}

ListaCarretas* criaListaCarretas(Patio* patio) {
    int qtdCarretasPorPatio = QTD_CARRETAS / QTD_PATIOS;
    ListaCarretas* lc = malloc(qtdCarretasPorPatio * sizeof(Carreta));
    lc->primeiro = NULL;
    for (int i = 0; i < qtdCarretasPorPatio; i++) {
        int numeracao = i + 1 + patio->id;
        criaCarreta(lc, numeracao);
    }
    return lc;
}

FilaMotoristas* criaFilaMotoristas(Patio* patio) {
    int qtd_motorista_por_patio = QTD_MOTORISTAS/QTD_PATIOS;
    FilaMotoristas* fm = malloc(qtd_motorista_por_patio * sizeof(Motorista));
    fm->primeiro = NULL;
    for (int i = 0; i < qtd_motorista_por_patio; i++) {
        int id = i + 1 + patio->id;
        insereMotorista(fm, id);
    }
    return fm;
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

void imprimeCarretasDoPatio(Patio* patio) {
    printf("Carretas do Patio %d: \n", patio->id);
    Carreta* aux = patio->carretas->primeiro;
    while(aux != NULL) {
        printf("%d ", aux->numeracao);
        aux = aux->prox;
    }
    printf("\n");
}