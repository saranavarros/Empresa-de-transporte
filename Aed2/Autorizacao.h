typedef struct autorizacao {
    Motorista* motorista;
    Carreta* carreta;
    Trajeto* trajeto;
} Autorizacao;

Autorizacao* criaAutorizacao(Motorista* motorista, Carreta* carreta, Trajeto* trajeto);
void imprimeAutorizacao(Autorizacao* autorizacao);

Patio* patioRandom(ListaPatios* lp) {
    int id = ((rand() % QTD_PATIOS) + 1) * 1000;
    return buscaPatio(lp, id);
}

void autorizaMotorista(ListaPatios* lp, ListaTrajetos* lt, Patio* patioSaida) {
    Carreta* carreta;
    Motorista* motorista = patioSaida->motoristas->primeiro;
    Trajeto* trajeto;
    Patio* patioChegada = patioRandom(lp);
    
    if (motorista != NULL) {
        patioSaida->motoristas->primeiro = motorista->prox;
        carreta = patioSaida->carretas->primeiro;
        // printf("carr prox NULL: %d\n", carreta->prox == NULL);
        patioSaida->carretas->primeiro = carreta->prox;;
        trajeto = buscaTrajeto(lt, patioSaida, patioChegada);
        Autorizacao* autorizacao = criaAutorizacao(motorista, carreta, trajeto);
        alteraStatusDeslocamento(motorista, carreta, 1);
        imprimeAutorizacao(autorizacao);
    }
}

Autorizacao* criaAutorizacao(Motorista* motorista, Carreta* carreta, Trajeto* trajeto) {
    Autorizacao* a = malloc(sizeof(Autorizacao));
    a->motorista = motorista;
    a->carreta = carreta;
    a->trajeto = trajeto;
}

void imprimeAutorizacao(Autorizacao* autorizacao) {
    printf(
        "auth -> Mot: %d, Carr: %d, Traj > saida: %d, chegada > %d\n",
        autorizacao->motorista->id,
        autorizacao->carreta->numeracao,
        autorizacao->trajeto->saida->id,
        autorizacao->trajeto->chegada->id
    );
}