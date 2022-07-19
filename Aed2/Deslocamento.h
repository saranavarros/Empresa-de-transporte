int statusDeslocamentoMotorista[QTD_MOTORISTAS][1];
int statusDeslocamentoCarreta[QTD_CARRETAS][1];

int motoristaEmDeslocamento(Motorista* motorista) {
    for (int i = 0; i < QTD_MOTORISTAS; i++) {
        if (statusDeslocamentoMotorista[i][0] == motorista->id) {
            return 1;
        }
    }
    return 0;
}

int carretaEmDeslocamento(Carreta* carreta) {
    for (int i = 0; i < QTD_CARRETAS; i++) {
        if (statusDeslocamentoCarreta[i][0] == carreta->numeracao) {
            return 1;
        }
    }
    return 0;
}

void alteraStatusDeslocamento(Motorista* motorista, Carreta* carreta, int status) {
    for (int i = 0; i < QTD_CARRETAS; i++) {
        if (statusDeslocamentoCarreta[i][0] == carreta->numeracao) {
            statusDeslocamentoCarreta[i][0] = 0;
        }
    }
    
    for (int i = 0; i < QTD_MOTORISTAS; i++) {
        if (statusDeslocamentoMotorista[i][0] == motorista->id) {
            statusDeslocamentoMotorista[i][0] = 0;
        }
    }
}
