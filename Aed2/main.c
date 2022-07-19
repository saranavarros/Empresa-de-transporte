#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Motorista.h"
#include "Carreta.h"
#include "Patio.h"
#include "Trajeto.h"
#include "Deslocamento.h"
#include "Autorizacao.h"

typedef struct registro {
    int atraso;
    int atencipacao;
    int distancia;
    Autorizacao* autorizacao;
} Registro;

ListaPatios* lp;
ListaTrajetos* lt;

void relatorioPatios() {
    Patio* p;
    for (int j = 0; j < QTD_PATIOS; j++) {
        int pid = (j + 1) * 1000;
        p = buscaPatio(lp, pid);
        imprimeMotoristasDoPatio(p);
        imprimeCarretasDoPatio(p);
    }
}

void despachaMotoristas() {
    Patio* p;
    for (int j = 0; j < QTD_PATIOS; j++) {
        int pid = (j + 1) * 1000;
        p = buscaPatio(lp, pid);
        autorizaMotorista(lp, lt, p);
    }
}

void loop() {
    relatorioPatios();
    despachaMotoristas();
}

int main() {
    
    time_t now;
    time(&now);
    srand((unsigned int) now);
    
    int inLoop = 1;
	char buf;
    lp = criaListaPatios();
    lt = criaListaTrajetos(lp);
    
    while(inLoop) {
		printf("Enter para a proxima rodada.\n");
		buf = fgetc(stdin);
		
		if(buf == 0x0A) {
			loop();
		}
		else {
		    printf("cc: %c\n", buf);
		    inLoop = 0;
		}
	}
    
    free(lp);
    free(lt);
    
    return 0;
}