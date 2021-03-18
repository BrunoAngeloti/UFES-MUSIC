#include <stdio.h>
#include <stdlib.h>
#include "Midia.h"
#include "Menu.h"
#include "Playlist.h"
#include "Album.h"
#include <string.h>

struct midia{
    int tipo; //1.VIDEO 2.PODCAST 3.MUSICA
    char* nome;
    char* compositor;
    char* genero;
    char* cantor;
    float tempo;
};

void ApagaMidia(Midia* m){
    if(m != NULL)
        free(m);
}

Midia* AtribuiMidia(FILE* adm){
    Midia* midia;
    midia = CriaMidia(adm);
    return midia;
}

/*Le um nome que o usuario digitar*/
void AtribuiNomeMidia(Midia* m, char* nome){
    m->nome = nome;
}
void AtribuiCantor(Midia* m, char* cantor){
    m->cantor = cantor;
}
void AtribuiCompositor(Midia* m, char* compositor){
    m->compositor = compositor;
}
void AtribuiGenero(Midia* m, char* genero){
    m->genero = genero;
}
void AtribuiTempo(Midia* m, float tempo){
    m->tempo = tempo;
}
void AtribuiTipoMidia(Midia* m, int tipo){
    m->tipo = tipo;
}

/*Adiciona musicas ao sistema*/
Midia* CriaMidia(FILE* adm){
    Midia* m = (Midia *) malloc(sizeof(Midia));;
    m->nome = (char *) malloc(sizeof(char)*35);
    m->compositor = (char *) malloc(sizeof(char)*35);
    m->genero = (char *) malloc(sizeof(char)*35);
    m->cantor = (char *) malloc(sizeof(char)*35);

    LeTipoMidia(m, adm);
    LeNomeMidia(m, adm);
    LeCompositor(m, adm);
    LeGenero(m, adm);
    LeCantor(m, adm);
    LeTempo(m, adm);

    return m;
}

void ImprimeMidia(Midia* m){
    int back;
    printf("\n- Nome da midia: %s\n", m->nome);
    if(m->tipo == 1){
        printf("- Tipo da midia: Video\n");
    }
    if(m->tipo == 2){
        printf("- Tipo da midia: Podcast\n");
    }
    if(m->tipo == 3){
        printf("- Tipo da midia: Musica\n");
    }

    printf("- Nome do cantor: %s\n", m->cantor);
    printf("- Nome do compositor: %s\n", m->compositor);
    printf("- Genero da midia: %s\n", m->genero);
    printf("- Duracao da midia: %.2f\n\n", m->tempo);
    while(1){
        printf("Digite 1 para voltar: ");
        scanf("%d", &back);
        if(back == 1) break;
    }
}

char* RecuperaNomeMidia(Midia* m){
    return m->nome;
}
char* RecuperaCantorMidia(Midia* m){
    return m->cantor;
}
char* RecuperaGeneroMidia(Midia* m){
    return m->genero;
}

Midia* AlocaMidia(){
    Midia* m = (Midia *)malloc(sizeof(Midia));
    return m;
}
