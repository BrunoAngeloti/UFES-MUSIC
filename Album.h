#ifndef _ALBUM
#define _ALBUM
#include "Midia.h"

typedef struct album Album;

/*Funcao que aloca espaco para um tipo album
Entrada: Um arquivo contendo os albuns
Saida: Um album, alocado e alguns detalhes preenchidos
*/
Album* AlocaAlbum(FILE* adm);

/*Funcao que pesquisa uma midia de dentro de um album
Entrada: Tipo de maneira que o usuario deseja pesquisar (nome, cantor, etc.)
		 Todos os álbuns ja criados inicialmente pela administracao
		 A quantidade de albuns que existe
Saida: Uma midia escolhida pelo usuario para adicionar em sua playlist
*/
Midia* PesquisaMidiaAlbum(int tipo, Album* a[], int QtdAlbum);

/*Funcao que retorna uma midia atraves de um nome inserido
Entrada: O nome que sera comparado a todas as midias dos albuns
         A quantidade de albuns que existe
		 Todos os álbuns ja criados inicialmente pela administracao
Saida: Uma midia que foi comparada com o nome que veio pela auxiliar
*/
Midia* RetornaMidia(char aux[], int QtdAlbum, Album* album[]);

#endif
