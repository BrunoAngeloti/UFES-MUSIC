#include <stdio.h>
#include <stdlib.h>
#include "Midia.h"
#include "Menu.h"
#include "Playlist.h"

void ImprimeMenu(){
    printf("    --------------------------------\n");
    printf("    |          BEM VINDO AO        |\n");
    printf("    |           UFES MUSIC         |\n");
    printf("    |                              |\n");
    printf("    |   Escolha uma opcao:         |\n");
    printf("    |   1. Criar conta             |\n");
    printf("    |   2. Ja possuo conta criada  |\n");
    printf("    |   3. Sair                    |\n");
    printf("    --------------------------------\n");
}

void ImprimePesquisa(){
    printf("    -----------------------------------\n");
    printf("    |         ADICIONANDO MIDIAS      |\n");
    printf("    |             NA PLAYLIST         |\n");
    printf("    |                                 |\n");
    printf("    |   Escolha um meio de pesquisa:  |\n");
    printf("    |   1. Nome do cantor             |\n");
    printf("    |   2. Nome da midia              |\n");
    printf("    |   3. Nome do album              |\n");
    printf("    |   4. Genero da midia            |\n");
    printf("    -----------------------------------\n");
}

void ImprimeMenuUsuario(){
    printf("ATENCAO: Seu plano cobre apenas 3 usuarios\n");
    printf("    --------------------------------\n");
    printf("    |          BEM VINDO A         |\n");
    printf("    |       PAGINA DO USUARIO      |\n");
    printf("    |                              |\n");
    printf("    |   Escolha uma opcao:         |\n");
    printf("    |   1. Criar playlists         |\n");
    printf("    |   2. Entrar nas playlists    |\n");
    printf("    |   3. Editar playlist         |\n");
    printf("    |   4. Salvar conta            |\n");
    printf("    |   5. Sair                    |\n");
    printf("    --------------------------------\n");
}

void ImprimeEdicao(){
    printf("    --------------------------------\n");
    printf("    |           EDITE A SUA        |\n");
    printf("    |            PLAYLIST          |\n");
    printf("    |                              |\n");
    printf("    |   Escolha uma opcao:         |\n");
    printf("    |   1. Apagar midia            |\n");
    printf("    |   2. Adicionar midia         |\n");
    printf("    |   3. Trocar ordem de midias  |\n");
    printf("    |   4. Apagar playlist         |\n");
    printf("    --------------------------------\n");
}
