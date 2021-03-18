#include <stdio.h>
#include <stdlib.h>
#include "Midia.h"
#include "Menu.h"
#include "Album.h"
#include "Playlist.h"

struct midia{
    int tipo; //1.VIDEO 2.PODCAST 3.MUSICA
    char* nome;
    char* compositor;
    char* genero;
    char* cantor;
    float tempo;
};

struct album{
    Midia* midia[21];
    char* nome;
    char *compositores[4];
    int qtdMidias;
    int qtdCompositores;
};

struct playlist{
    char* nome;
    Midia* midia[51];
    int numMidias;
    int compartilhavel;
    char* segundoNome;
    char* primeiroNome;
};

struct user{
    char* nome;
    Playlist* playlists[6];
    Playlist* compartilhada[6];
    int qtdPlaylists;
    int qtdPlaylistsCompartilhadas;
    int criou;
};

void AtribuiPlaylist(User* u, Album* a[], int QtdAlbum, User* u2, User* u3){
    int condicao, i, k=0;
    for(i=u->qtdPlaylists;i<5;i++){
        u->qtdPlaylists++;
        printf("\n\t\t----------PLAYLIST %d de %s----------\n\n", u->qtdPlaylists, u->nome);
        u->playlists[i]->primeiroNome = u->nome;
        printf("Nome da sua playlist %d: ",u->qtdPlaylists);
        scanf("%s", u->playlists[i]->nome);
        u->criou = 1;
        AdicionaMusica(u->playlists[i], a, QtdAlbum);
        printf("\n\t\t----------ANTES DE IR----------\n\n");
        printf("Sera uma playlist compartilhavel?\n1. Sim\n2. Nao\n");
        scanf("%d", &u->playlists[i]->compartilhavel);
        if(u->playlists[i]->compartilhavel == 1){
            printf("Qual usuario poderá acessar essa playlist?\n");
            printf("1. %s\n2. %s\n", u2->nome, u3->nome);
            scanf("%d", &condicao);
            if(condicao == 1){
                u->playlists[i]->segundoNome = u2->nome;
                u2->compartilhada[u2->qtdPlaylistsCompartilhadas] = u->playlists[i];
                u2->qtdPlaylistsCompartilhadas++;
            }
            if(condicao == 2){
                u->playlists[i]->segundoNome = u3->nome;
                u3->compartilhada[u3->qtdPlaylistsCompartilhadas] = u->playlists[i];
                u3->qtdPlaylistsCompartilhadas++;
            }
        }
        printf("Deseja criar uma nova playlist?\n");
        printf("1. Sim\n2. Nao\n");
        scanf("%d", &condicao);
        if(condicao == 2){
            break;
        }
    }
    if(u->qtdPlaylists == 5){
        printf("\n\t\t----------%s ATINGIU O LIMITE DE PLAYLISTS----------\n\n", u->nome);
    }
}

void AbrePlaylist(Playlist* p){
    int i, condicao;
    while(1){
        printf("\t\t----------PLAYLIST %s----------\n\n", p->nome);
        if(p->compartilhavel == 1){
            printf("Playlist de: %s\n", p->primeiroNome);
            printf("Playlist compartilhada com: %s\n\n", p->segundoNome);
        }else{
            printf("Playlist privada!\n\n");
        }
        for(i=0;i < p->numMidias; i++){
            printf("%d. %s\n", i, p->midia[i]->nome);
        }
        printf("\n1. Detalhes de alguma midia\n");
        printf("2. Voltar ao menu\n");
        scanf("%d", &condicao);
        if(condicao == 1){
            printf("\n\nQual midia deseja ver detalhes? (utilize o numero)\n");
            scanf("%d", &condicao);
            ImprimeMidia(p->midia[condicao]);
        }else{
            break;
        }
    }
}

void ApagaPlaylist(Playlist* p){
    if(p != NULL)
        free(p);
}

void AdicionaMusica(Playlist* p, Album* a[], int QtdAlbum){
    int tipo, i;
    char finaliza;

    printf("\n\t\t----------ADICIONANDO MIDIAS EM %s----------\n\n", p->nome);
    for(i=0; i<50; i++){
        ImprimePesquisa();
        scanf("%d", &tipo);
        p->midia[i] = PesquisaMidiaAlbum(tipo, a, QtdAlbum);
        printf("\n\t\t----------MIDIA ADICIONADA COM EXITO----------\n\n");
        printf("Finalizar? [S] [N]\n");
        scanf("\n%c", &finaliza);
        if(finaliza == 'S' || finaliza == 's') break;
    }
    p->numMidias = i+1;
}

void AdicionaMidiaNoMeio(Playlist* p, Album* a[], int QtdAlbum){
    int tipo, i;
    char finaliza;

    printf("\n\t\t----------ADICIONANDO MIDIAS EM %s----------\n\n", p->nome);
    for(i=p->numMidias; i<50; i++){
        ImprimePesquisa();
        scanf("%d", &tipo);
        p->midia[i] = PesquisaMidiaAlbum(tipo, a, QtdAlbum);
        printf("\n----------MIDIA ADICIONADA COM EXITO----------\n\n");
        printf("Finalizar? [S] [N]\n");
        scanf("\n%c", &finaliza);
        if(finaliza == 'S' || finaliza == 's') break;
    }
    p->numMidias = i+1;
}

Playlist* AlocaPlaylist(){
    Playlist* p;
    p = (Playlist*) malloc (sizeof(Playlist));
    p->nome = (char *) malloc(sizeof(char));
    p->primeiroNome = (char*) malloc (sizeof(char));
    p->segundoNome = (char*) malloc (sizeof(char));
    for(int i=0;i<50;i++){
        p->midia[i] = (Midia*) malloc(sizeof(Midia)*50);
    }
    return p;
}

void ApagaMidiaPlaylist(Playlist* p, int id){
    int i;
    free(p->midia[id]);
    for(i=id;i<50;i++){
        p->midia[id] = p->midia[id+1];
        id++;
    }
    p->numMidias--;
}

void TrocaOrdem(Playlist* p){
    int i, num1, num2;
    Midia* aux = (Midia *) malloc(sizeof(Midia));
    printf("Escolha duas midias para trocar de posicao\n");
    for(i=0;i<p->numMidias;i++){
        printf("%d. %s\n", i, p->midia[i]->nome);
    }
    printf("midia 1: ");
    scanf("%d", &num1);
    printf("midia 2: ");
    scanf("%d", &num2);
    aux = p->midia[num1];
    p->midia[num1] = p->midia[num2];
    p->midia[num2] = aux;
}
