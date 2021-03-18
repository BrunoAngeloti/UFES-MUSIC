#include <stdio.h>
#include <stdlib.h>
#include "Midia.h"
#include "Menu.h"
#include "Album.h"
#include "Playlist.h"
#include "User.h"
#include <string.h>

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

struct midia{
    int tipo; //1.VIDEO 2.PODCAST 3.MUSICA
    char* nome;
    char* compositor;
    char* genero;
    char* cantor;
    float tempo;
};

int ComparaNomes(User* u, char nome[]){
    int condicao;
    condicao = strcmp(nome, u->nome);
    if(condicao == 0){
        return 1;
    }else{
        return 0;
    }
}
User* AlocaUsuario(){
    int i;
    User* u = (User*) malloc (sizeof(User));
    u->nome = (char*) malloc (sizeof(50));
    u->qtdPlaylistsCompartilhadas = 0;
    u->qtdPlaylists = 0;
    u->criou = 0;
    for(i=0;i<5;i++){
        u->playlists[i] = AlocaPlaylist();
    }
    printf("Nome De Usuario: ");
    scanf("%s", u->nome);
    return u;
}

User* ObtemUsuarioJaCriado(int QtdAlbum, Album* album[], FILE* c){
    User* u;
    u = (User*) malloc (sizeof(User));
    u->nome = (char*) malloc (sizeof(50));
    int i, j;
    char aux[31];
    for(i=0;i<5;i++){
        u->playlists[i] = AlocaPlaylist();
    }
    fscanf(c, "%d\n", &u->qtdPlaylists);
    fscanf(c, "%s\n", u->nome);
    u->qtdPlaylistsCompartilhadas = 0;
    u->criou = 1;
    for(i=0; i<u->qtdPlaylists; i++){
        fscanf(c, "%s\n", u->playlists[i]->nome);
        fscanf(c, "%d\n", &u->playlists[i]->numMidias);
        fscanf(c, "%d\n", &u->playlists[i]->compartilhavel);
        if(u->playlists[i]->compartilhavel == 1){
            fscanf(c, "%s\n", u->playlists[i]->segundoNome);
            u->playlists[i]->primeiroNome = u->nome;
        }
        for(j=0;j<u->playlists[i]->numMidias;j++){
             fscanf(c, "%s\n", aux);
             u->playlists[i]->midia[j] = RetornaMidia(aux, QtdAlbum, album);
        }
    }
    return u;
}

void DistribuiPlayCompartilhada(User* u1, User* u2, User* u3){
    int i;
    for(i=0; i<u1->qtdPlaylists; i++){
        if(u1->playlists[i]->compartilhavel == 1){
            if(strcmp(u1->playlists[i]->segundoNome, u2->nome) == 0){
                u2->compartilhada[u2->qtdPlaylistsCompartilhadas] = u1->playlists[i];
                u2->qtdPlaylistsCompartilhadas++;
            }else{
                u3->compartilhada[u3->qtdPlaylistsCompartilhadas] = u1->playlists[i];
                u3->qtdPlaylistsCompartilhadas++;
            }
        }
    }

    for(i=0; i<u2->qtdPlaylists; i++){
        if(u2->playlists[i]->compartilhavel == 1){
            if(strcmp(u2->playlists[i]->segundoNome, u1->nome) == 0){
                u1->compartilhada[u1->qtdPlaylistsCompartilhadas] = u2->playlists[i];
                u1->qtdPlaylistsCompartilhadas++;
            }else{
                u3->compartilhada[u3->qtdPlaylistsCompartilhadas] = u2->playlists[i];
                u3->qtdPlaylistsCompartilhadas++;
            }
        }
    }

    for(i=0; i<u3->qtdPlaylists; i++){
        if(u3->playlists[i]->compartilhavel == 1){
            if(strcmp(u3->playlists[i]->segundoNome, u2->nome) == 0){
                u2->compartilhada[u2->qtdPlaylistsCompartilhadas] = u3->playlists[i];
                u2->qtdPlaylistsCompartilhadas++;
            }else{
                u1->compartilhada[u1->qtdPlaylistsCompartilhadas] = u3->playlists[i];
                u1->qtdPlaylistsCompartilhadas++;
            }
        }
    }
}

int VerificaPlaylist(User* u){
    if(u->criou){
        return 1;
    }else{
        printf("\n\t\t----------PLAYLIST DE %s NAO CRIADA----------\n", u->nome);
        return 0;
    }
}

void MostraPlaylists(User* u){
    int num, num2, i;
    if(u->qtdPlaylistsCompartilhadas == 0){
        printf("Voce nao tem acesso a playlist de outros usuarios\n");
        printf("Playlists a seguir são suas:\n");
        for(i=0;i<u->qtdPlaylists;i++){
            printf("%d. %s\n", i, u->playlists[i]->nome);
        }
        scanf("%d", &num);
        AbrePlaylist(u->playlists[num]);
    }else{
        printf("Voce possui acesso a %d playlists compartilhadas\n", u->qtdPlaylistsCompartilhadas);
        printf("Deseja abrir playlist:\n1. Compartilhada\n2. Privada/Seguida\n");
        scanf("%d", &num2);
        if(num2 == 1){
            for(i=0;i<u->qtdPlaylistsCompartilhadas;i++){
                printf("%d. %s\n", i, u->compartilhada[i]->nome);
            }
            scanf("%d", &num);
            AbrePlaylist(u->compartilhada[num]);
        }else{
            for(i=0;i<u->qtdPlaylists;i++){
                printf("%d. %s\n", i, u->playlists[i]->nome);
            }
            scanf("%d", &num);
            AbrePlaylist(u->playlists[num]);
        }
    }
}

void EditaPlaylists(User* u, Album* a[], int QtdAlbum, int tipo){
    int num, total, i, id, condicao;
    if(tipo == 1){
        while(1){
            if(u->qtdPlaylists == 0){
                printf("\n----------%s NAO POSSUI PLAYLISTS ATIVAS----------\n\n", u->nome);
                break;
            }
            printf("\nQual playlist de %s quer apagar uma midia?\n", u->nome);
            for(i=0;i<u->qtdPlaylists;i++){
                printf(" %d. %s\n", i, u->playlists[i]->nome);
            }
            scanf("%d", &num);
            printf("Qual midia voce deseja apagar?\n");
            for(i=0;i<u->playlists[num]->numMidias;i++){
                printf(" %d. %s\n", i, u->playlists[num]->midia[i]->nome);
            }
            scanf("%d", &id);
            ApagaMidiaPlaylist(u->playlists[num], id);
            printf("\n----------MIDIA APAGADA COM EXITO----------\n\n");
            printf("Continuar apagando midia?\n1. Sim\n2. Nao\n");
            scanf("%d", &condicao);
            if(condicao == 2){
                break;
            }
        }
    }
    if(tipo == 2){
        if(u->qtdPlaylists == 0){
            printf("\n----------%s NAO POSSUI PLAYLISTS ATIVAS----------\n\n", u->nome);
        }else{
            printf("\nQual playlist de %s quer adicionar nova midia?\n", u->nome);
            for(i=0;i<u->qtdPlaylists;i++){
                printf("%d. %s\n", i, u->playlists[i]->nome);
            }
            scanf("%d", &num);
            total = (50 - u->playlists[num]->numMidias);
            printf("\nATENCAO: Esta playlist tem direito a mais %d midias\n\n", total);
            AdicionaMidiaNoMeio(u->playlists[num], a, QtdAlbum);
        }
    }
    if(tipo == 3){
        while(1){
            if(u->qtdPlaylists == 0){
                printf("\n----------%s NAO POSSUI PLAYLISTS ATIVAS----------\n\n", u->nome);
                break;
            }
            printf("\nQual playlist de %s quer trocar a ordem das midias?\n", u->nome);
            for(i=0;i<u->qtdPlaylists;i++){
                printf("%d. %s\n", i, u->playlists[i]->nome);
            }
            scanf("%d", &num);
            if(u->playlists[num]->numMidias >= 2){
                TrocaOrdem(u->playlists[num]);
                printf("\n----------ORDEM TROCADA COM EXITO----------\n\n");
            }else{
                printf("\n----------PLAYLIST COM APENAS UMA MIDIA----------\n\n");
            }
            printf("Deseja trocar mais midias de lugar?\n1. Sim\n2. Nao\n");
            scanf("%d", &condicao);
            if(condicao == 2){
                break;
            }
        }
    }
    if(tipo == 4){
        while(1){
            if(u->qtdPlaylists == 0){
                printf("\n----------%s NAO POSSUI PLAYLISTS ATIVAS----------\n\n", u->nome);
                break;
            }
            printf("\nQual playlist de %s quer apagar?\n", u->nome);
            for(i=0;i<u->qtdPlaylists;i++){
                printf("%d. %s\n", i, u->playlists[i]->nome);
            }
            scanf("%d", &num);
            ApagaPlaylist(u->playlists[num]);
            u->playlists[num] = AlocaPlaylist();
            for(num;num<u->qtdPlaylists;num++){
                u->playlists[num] = u->playlists[num+1];
            }
            u->qtdPlaylists--;
            printf("\n----------PLAYLIST APAGADA COM EXITO----------\n\n");
            printf("Deseja apagar mais playlists?\n1. Sim\n2. Nao\n");
            scanf("%d", &condicao);
            if(condicao == 2){
                break;
            }
        }
    }
}

void salvaUsuario(User* u, FILE* f){
    int i,j;
    fprintf(f, "%d\n", u->qtdPlaylists);
    fprintf(f, "%s\n", u->nome);
    for(i=0; i<u->qtdPlaylists; i++){
        fprintf(f, "%s\n", u->playlists[i]->nome);
        fprintf(f, "%d\n", u->playlists[i]->numMidias);
        fprintf(f, "%d\n", u->playlists[i]->compartilhavel);
        if(u->playlists[i]->compartilhavel == 1){
            fprintf(f, "%s\n", u->playlists[i]->segundoNome);
        }
        for(j=0;j<u->playlists[i]->numMidias;j++){
             fprintf(f, "%s\n", u->playlists[i]->midia[j]->nome);
        }
    }
}
