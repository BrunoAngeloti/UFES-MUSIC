#include <stdio.h>
#include <stdlib.h>
#include "Midia.h"
#include "Menu.h"
#include "Album.h"
#include "Playlist.h"
#include "User.h"
#include <string.h>

void LeNomeMidia(Midia* m, FILE* adm){
    char* nome;
    nome = (char *) malloc(sizeof(char)*35);
    fscanf(adm, "%s\n", nome);
    AtribuiNomeMidia(m, nome);
}
void LeTipoMidia(Midia* m, FILE* adm){
    int tipo;
    fscanf(adm, "%d\n", &tipo);
    AtribuiTipoMidia(m, tipo);
}
void LeCantor(Midia* m, FILE* adm){
    char* cantor;
    cantor = (char *) malloc(sizeof(char)*35);
    fscanf(adm, "%s\n", cantor);
    AtribuiCantor(m, cantor);
}
void LeTempo(Midia* m, FILE* adm){
    float tempo;
    fscanf(adm, "%f\n", &tempo);
    AtribuiTempo(m, tempo);
}
void LeCompositor(Midia* m, FILE* adm){
    char* compositor;
    compositor = (char *) malloc(sizeof(char)*35);
    fscanf(adm, "%s\n", compositor);
    AtribuiCompositor(m, compositor);
}
void LeGenero(Midia* m, FILE* adm){
    char* genero;
    genero = (char *) malloc(sizeof(char)*35);
    fscanf(adm, "%s\n", genero);
    AtribuiGenero(m, genero);
}

int main(){
	int opcao, QtdAlbum, QtdMidia, senha, criou = 0, i, j, escolha;
    char nomeAux[20];
	Album* album[21];
    FILE* adm;
    User* user1;
    User* user2;
    User* user3;
	char* Nome = (char*)malloc(sizeof(char)*100);
	char* Compositor = (char*)malloc(sizeof(char)*100);

//-------------------------LEITURA DE ALBUNS -------------------------
    adm = fopen("albuns.txt", "r");
    if(adm == NULL){
        printf("ERRO AO ABRIR O ARQUIVO");
        return 0;
    }
    fscanf(adm, "%d",&QtdAlbum);

    for(j=0;j<QtdAlbum;j++){
        album[j] = AlocaAlbum(adm);
    }
    fclose(adm);
//-------------------------LEITURA DE ALBUNS FEITA-------------------------

	ImprimeMenu();
	scanf("%d", &opcao);
	if(opcao == 1){
        printf("USUARIO 1:\n");
        user1 = AlocaUsuario();
        printf("\nUSUARIO 2:\n");
        user2 = AlocaUsuario();
        printf("\nUSUARIO 3:\n");
        user3 = AlocaUsuario();
        criou = 1;
        printf("\n\t\t----------USUARIOS CRIADOS COM SUCESSO----------\n\n");
    }
    if(opcao == 2){
        FILE* c;
        c = fopen("UsuarioJaCriado.txt", "r");
        if(c == NULL){
            printf("ERRO AO ABRIR CONTA JA CRIADA");
            exit(1);
        }
        user1 = ObtemUsuarioJaCriado(QtdAlbum, album, c);
        user2 = ObtemUsuarioJaCriado(QtdAlbum, album, c);
        user3 = ObtemUsuarioJaCriado(QtdAlbum, album, c);
        DistribuiPlayCompartilhada(user1, user2, user3);
        criou = 1;
        fclose(c);
        printf("\n\t\t----------CONTA SINCRONIZADA COM EXITO----------\n\n");
    }
    if(opcao == 3){
        return 0;
    }

    while(1){
        ImprimeMenuUsuario();
        scanf("%d", &opcao);
        if(opcao == 1){
            printf("\nUsuario: ");
            scanf("%s", nomeAux);
            if(ComparaNomes(user1, nomeAux) == 1){
                AtribuiPlaylist(user1, album, QtdAlbum, user2, user3);
            }else if(ComparaNomes(user2, nomeAux) == 1){
                AtribuiPlaylist(user2, album, QtdAlbum, user1, user3);
            }else if(ComparaNomes(user3, nomeAux) == 1){
                AtribuiPlaylist(user3, album, QtdAlbum, user1, user2);
            }else{
                printf("\n\t\t----------USUARIO NAO ENCONTRADO----------\n\n");
            }
        }else if(opcao == 2){
            printf("\nUsuario: ");
            scanf("%s", nomeAux);
            if(ComparaNomes(user1, nomeAux) == 1){
                if(VerificaPlaylist(user1)){
                    MostraPlaylists(user1);
                }
            }else if(ComparaNomes(user2, nomeAux) == 1){
                if(VerificaPlaylist(user2)){
                    MostraPlaylists(user2);
                }
            }else if(ComparaNomes(user3, nomeAux) == 1){
                if(VerificaPlaylist(user3)){
                    MostraPlaylists(user3);
                }
            }else{
                printf("\n\t\t----------USUARIO NAO ENCONTRADO----------\n\n");
            }
        }else if(opcao == 3){
            printf("\nUsuario: ");
            scanf("%s", nomeAux);
            if(ComparaNomes(user1, nomeAux) == 1){
                if(VerificaPlaylist(user1)){
                    ImprimeEdicao();
                    scanf("%d", &escolha);
                    if(escolha != 1 && escolha != 2 && escolha != 3 && escolha != 4){
                        printf("ESCOLHA OPCAO VALIDA");
                    }else{
                        EditaPlaylists(user1, album, QtdAlbum, escolha);
                    }
                }
            }else if(ComparaNomes(user2, nomeAux) == 1){
                if(VerificaPlaylist(user2)){
                    ImprimeEdicao();
                    scanf("%d", &escolha);
                    if(escolha != 1 && escolha != 2 && escolha != 3 && escolha != 4){
                        printf("ESCOLHA OPCAO VALIDA");
                    }else{
                        EditaPlaylists(user2, album, QtdAlbum, escolha);
                    }
                }
            }else if(ComparaNomes(user3, nomeAux) == 1){
                if(VerificaPlaylist(user3)){
                    ImprimeEdicao();
                    scanf("%d", &escolha);
                    if(escolha != 1 && escolha != 2 && escolha != 3 && escolha != 4){
                        printf("ESCOLHA OPCAO VALIDA");
                    }else{
                        EditaPlaylists(user3, album, QtdAlbum, escolha);
                    }
                }
            }else{
                printf("\n\t\t----------USUARIO NAO ENCONTRADO----------\n\n");
            }
        }else if(opcao == 4){
            FILE* conta;
            conta = fopen("UsuarioJaCriado.txt", "w");
            salvaUsuario(user1, conta);
            salvaUsuario(user2, conta);
            salvaUsuario(user3, conta);
            printf("\n\t\t----------CONTA SALVA COM SUCESSO----------\n\n");
            fclose(conta);
        }else if(opcao == 5){
            opcao = 0;
            break;
        }else {
            printf("\n\t\t----------OPCAO INVALIDA----------\n\n");
        }
    }
}
