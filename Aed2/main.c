#include <stdio.h>
#include <stdlib.h>
#include "Motorista.h"
#include "Carreta.h"
#include "Patio.h"
#include "Trajeto.h"

typedef struct autorizacao {
    Motorista* motorista;
    Carreta* carreta;
    Trajeto* trajeto;
} Autorizacao;

typedef struct registro {
    int atraso;
    int atencipacao;
    int distancia;
    Autorizacao* autorizacao;
} Registro;

ListaPatios* lp;
ListaCarretas* lc;
ListaTrajetos* lt;

void inspecaoChegada(Registro* registro) {
    printf("patio saida: %d\n", registro->autorizacao->trajeto->saida->id);
    printf("patio chegada: %d\n", registro->autorizacao->trajeto->chegada->id);
    printf("motorista: %d\n", registro->autorizacao->motorista->id);
    printf("distancia: %d\n", registro->distancia);
}

void geraFilaDeMotoristas() {
    
    Patio* p;
    int step = QTD_MOTORISTAS / QTD_PATIOS;
    int pid = 1;
    
    for (int j = 0; j < QTD_MOTORISTAS; j++) {
        int mid = j + 1;
        p = buscaPatio(lp, pid);
        insereMotorista(p->motoristas, mid);
        
        if ((mid % step) == 0) {
            pid++;
        }
    }
}

void relatorioPatios() {
    Patio* p;
    for (int j = 0; j < QTD_PATIOS; j++) {
        int pid = j + 1;
        p = buscaPatio(lp, pid);
        imprimeMotoristasDoPatio(p);
    }
}

void loop() {
    relatorioPatios();
    // gerar autorização com dados random
}

int main() {
    
    lc = criaListaCarretas();
    lp = criaListaPatios();
    lt = criaListaTrajetos(lp);
    
    geraFilaDeMotoristas();
    loop();
    
    free(lc);
    free(lp);
    free(lt);
    
    // Motorista* m = buscaMotorista(lm, 5);
    // Trajeto* t = buscaTrajeto(lt, 4, 1);
    
    // Autorizacao* a = malloc(sizeof(Autorizacao));
    // a->trajeto = t;
    // a->motorista = m;
    // a->carreta = buscaCarreta(lc, 1);
    
    // Registro* r = malloc(sizeof(Registro));
    // r->autorizacao = a;
    // r->distancia = calculaDistancia(t);
    // r->atraso = 1;
    // r->atencipacao = 0;
    
    // inspecaoChegada(r);
    return 0;
}