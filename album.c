#include <stdio.h>
#include <stdlib.h>
#include "Midia.h"
#include "Menu.h"
#include "Playlist.h"
#include <string.h>

struct album{
    Midia* midia[21];
    char* nome;
    char *compositores[4];
    int qtdMidias;
    int qtdCompositores;
};

Midia* PesquisaMidiaAlbum(int tipo, Album* a[], int QtdAlbum){
    char nome[30], cantores[50][30], generos[50][30];
    int i, j, k, l, achou = 0, numeroAlbum, numeroMidia, japrintou = 0, indice = 0;
    if(tipo == 1){
        indice = 0;
        for(i=0;i<50;i++){
            for(j=0;j<30;j++){
                cantores[i][j] = '\0';
            }
        }
        while(1){
			for(i=0;i<QtdAlbum;i++){
                for(j=0;j<a[i]->qtdMidias;j++){
                    for(k=0;k<50;k++){
                        if(strcmp(RecuperaCantorMidia(a[i]->midia[j]), cantores[k]) == 0){
                            japrintou = 1;
                        }
                    }
                    if(japrintou){
                        japrintou = 0;
                    }else{
                        printf("- %s\n", RecuperaCantorMidia(a[i]->midia[j]));
                        strcpy(cantores[indice], RecuperaCantorMidia(a[i]->midia[j]));
                        indice++;
                    }
				}
            }
            printf("\nNome do cantor: ");
            scanf("%s", nome);
            for(i=0;i<QtdAlbum;i++){
                for(j=0;j<a[i]->qtdMidias;j++){
                    if(strcmp(RecuperaCantorMidia(a[i]->midia[j]), nome) == 0){
                        achou = 1;
                        printf("- %s\n", RecuperaNomeMidia(a[i]->midia[j]));
                    }
                }
            }
            if(!achou){
                printf("\n\t\t----------CANTOR NAO ENCONTRADO----------\n");
            }else{
                while(1){
                    achou = 0;
                    printf("\nNome da musica: ");
                    scanf("%s", nome);
                    for(i=0;i<QtdAlbum;i++){
                        for(j=0;j<a[i]->qtdMidias;j++){
                            if(strcmp(RecuperaNomeMidia(a[i]->midia[j]), nome) == 0){
                                achou = 1;
                            }
                            if(achou){
                                break;
                            }
                        }
                        if(achou){
                            break;
                        }
                    }
                    if(!achou){
                        printf("\n\t\t----------MIDIA NAO ENCONTRADA----------\n");
                    }else{
                        return a[i]->midia[j];
                    }
                }
            }
        }
    }
    if(tipo == 2){
        while(1){
			for(i=0;i<QtdAlbum;i++){
                for(j=0;j<a[i]->qtdMidias;j++){
					printf("- %s\n", RecuperaNomeMidia(a[i]->midia[j]));
				}
            }
            printf("\nNome da musica: ");
            scanf("%s", nome);
            for(i=0;i<QtdAlbum;i++){
                for(j=0;j<a[i]->qtdMidias;j++){
                    if(strcmp(RecuperaNomeMidia(a[i]->midia[j]), nome) == 0){
                        achou = 1;
                    }
                    if(achou){
                        break;
                    }
                }
                if(achou){
                    break;
                }
            }
            if(!achou){
                printf("\n\t\t----------MIDIA NAO ENCONTRADA----------\n");
            }else{
                break;
            }
        }
        return a[i]->midia[j];
    }
    if(tipo == 3){
        printf("\n");
        for(i=0;i<QtdAlbum;i++){
            printf("%d. %s\n", i, a[i]->nome);
        }
        scanf("%d", &numeroAlbum);
        printf("\n");
            for(j=0;j<a[numeroAlbum]->qtdMidias;j++){
                printf("%d. %s\n", j, RecuperaNomeMidia(a[numeroAlbum]->midia[j]));
            }
        scanf("%d", &numeroMidia);
        return a[numeroAlbum]->midia[numeroMidia];
    }



    if(tipo == 4){
        indice = 0;
        for(i=0;i<50;i++){
            for(j=0;j<30;j++){
                generos[i][j] = '\0';
            }
        }
        while(1){
			for(i=0;i<QtdAlbum;i++){
                for(j=0;j<a[i]->qtdMidias;j++){
                    for(k=0;k<50;k++){
                        if(strcmp(RecuperaGeneroMidia(a[i]->midia[j]), generos[k]) == 0){
                            japrintou = 1;
                        }
                    }
                    if(japrintou){
                        japrintou = 0;
                    }else{
                        printf("- %s\n", RecuperaGeneroMidia(a[i]->midia[j]));
                        strcpy(generos[indice], RecuperaGeneroMidia(a[i]->midia[j]));
                        indice++;
                    }
				}
            }
            printf("\nGenero da midia: ");
            scanf("%s", nome);
            for(i=0;i<QtdAlbum;i++){
                for(j=0;j<a[i]->qtdMidias;j++){
                    if(strcmp(RecuperaGeneroMidia(a[i]->midia[j]), nome) == 0){
                        achou = 1;
                        printf("- %s\n", RecuperaNomeMidia(a[i]->midia[j]));
                    }
                }
            }
            if(!achou){
                printf("\n\t\t----------GENERO NAO ENCONTRADO----------\n");
            }else{
                while(1){
                    achou = 0;
                    printf("\nNome da musica: ");
                    scanf("%s", nome);
                    for(i=0;i<QtdAlbum;i++){
                        for(j=0;j<a[i]->qtdMidias;j++){
                            if(strcmp(RecuperaNomeMidia(a[i]->midia[j]), nome) == 0){
                                achou = 1;
                            }
                            if(achou){
                                break;
                            }
                        }
                        if(achou){
                            break;
                        }
                    }
                    if(!achou){
                        printf("\n\t\t----------MIDIA NAO ENCONTRADA----------\n");
                    }else{
                        return a[i]->midia[j];
                    }
                }
            }
        }
    }
}

Album* AlocaAlbum(FILE* adm){
	int indice = 0, i, j;
    Album *a = (Album *)malloc(sizeof(Album));
    a->nome = (char *)malloc(sizeof(char)*50);

    fscanf(adm, "%d\n", &a->qtdMidias);
    for(i=0;i<a->qtdMidias;i++){
    	a->midia[i] = AlocaMidia();
    }

    fscanf(adm, "%d\n", &a->qtdCompositores);

    for(j=0;j<a->qtdCompositores;j++){
    	a->compositores[j] = (char *)malloc(sizeof(char)*50);
    }
    for(j=0;j<a->qtdCompositores;j++){
        fscanf(adm, "%s\n",a->compositores[j]);
    }
    fscanf(adm, "%s\n", a->nome);
    for(i=0;i<a->qtdMidias;i++){
        a->midia[i] = AtribuiMidia(adm);
    }
    return a;
}

Midia* RetornaMidia(char aux[], int QtdAlbum, Album* album[]){
    int i, j, achou = 0;
    for(i=0;i<QtdAlbum;i++){
        for(j=0;j<album[i]->qtdMidias;j++){
            if(strcmp(RecuperaNomeMidia(album[i]->midia[j]), aux) == 0){
                achou = 1;
            }
            if(achou){
                break;
            }
        }
        if(achou){
            break;
        }
    }
    return album[i]->midia[j];
}
