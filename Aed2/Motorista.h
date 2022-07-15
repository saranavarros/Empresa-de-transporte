#define QTD_MOTORISTAS 20

typedef struct motorista {
  int id;
  struct motorista* prox;
} Motorista;

typedef struct filaMotoristas {
   int qtd;
   Motorista* primeiro;
} FilaMotoristas;

Motorista* insereMotorista(FilaMotoristas* lm, int id) {
    Motorista* m = malloc(sizeof(Motorista));
    m->id = id;
    m->prox = NULL;
    
    if (lm->primeiro == NULL) {
        lm->primeiro = m;
    }
    else {
        Motorista* aux = lm->primeiro;
        while(aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = m;
    }
    
    return m;
}

Motorista* buscaMotorista(FilaMotoristas* lm, int id) {
    Motorista* aux = lm->primeiro;
    while(aux->id != id && aux->prox != NULL) {
        aux = aux->prox;
    }
    return aux;
}

FilaMotoristas* criaFilaMotoristas() {
    FilaMotoristas* lm = malloc(QTD_MOTORISTAS * sizeof(Motorista));
    lm->primeiro = NULL;
    return lm;
}