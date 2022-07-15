#define QTD_TRAJETOS 12

 typedef struct trajeto {
    Patio * saida;
    Patio * chegada;
    int distancia;
    char ocorrencia[50];
    struct trajeto* prox;
} Trajeto;

typedef struct ListaTrajetos {
   int qtd;
   Trajeto* primeiro;
} ListaTrajetos;
 
int matrizTrajeto[QTD_TRAJETOS][3] = { 
    {1, 2, 90}, 
    {2, 1, 120}, 
    {1, 3, 50}, 
    {3, 3, 40}, 
    {1, 4, 110}, 
    {4, 1, 180}, 
    {2, 3, 170}, 
    {3, 2, 30}, 
    {2, 4, 25}, 
    {4, 2, 155}, 
    {3, 4, 280}, 
    {4, 3, 190}, 
};

Trajeto* criaTrajeto(ListaTrajetos* lt, Patio* saida, Patio* chegada, int distancia) {
    Trajeto* t = malloc(QTD_TRAJETOS * sizeof(Trajeto));
    t->saida = saida;
    t->chegada = chegada;
    t->distancia = distancia;
    t->prox = NULL;
    
    if (lt->primeiro == NULL) {
        lt->primeiro = t;
    }
    else {
        Trajeto* aux = lt->primeiro;
        while(aux->prox != NULL) {
            aux = aux->prox;
        }
        aux->prox = t;
    }
    
    return t;
}

Trajeto* buscaTrajeto(ListaTrajetos* lt, Patio* saida, Patio* chegada) {
    Trajeto* aux = lt->primeiro;
    while((aux->saida != saida && aux->chegada != chegada) && aux->prox != NULL) {
        aux = aux->prox;
    }
    return aux;
}

ListaTrajetos* criaListaTrajetos(ListaPatios* lp) {
    ListaTrajetos* lt = malloc(QTD_TRAJETOS * sizeof(Trajeto));
    lt->primeiro = NULL;
    for (int i = 0; i < QTD_TRAJETOS; i++) {
        Patio* saida = buscaPatio(lp, matrizTrajeto[i][0]);
        Patio* chegada = buscaPatio(lp, matrizTrajeto[i][1]);
        int distancia = matrizTrajeto[i][2];
        criaTrajeto(lt, saida, chegada, distancia);
    }
    return lt;
}

int calculaDistancia (Trajeto * trajeto) {
    int d;
    Patio * s = trajeto->saida;
    Patio * c = trajeto->chegada;
    for (int i = 0; i < QTD_TRAJETOS; i++) {
        if (matrizTrajeto[i][0] == s->id && matrizTrajeto[i][1] == c->id) {
            d = matrizTrajeto[i][2];
    	}
    }
    return d;
}
