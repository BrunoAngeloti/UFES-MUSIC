#ifndef _PLAYLIST
#define _PLAYLIST

typedef struct playlist Playlist;

typedef struct midia Midia;

typedef struct user User;

typedef struct album Album;

/*Atribui playlist a um usuario
Entrada: Primeiro usuario
		 Os albuns com as midias
		 Quantidade de albuns
         Segundo usuario
         Terceiro usuario
Saida: -
*/
void AtribuiPlaylist(User* u, Album* a[], int QtdAlbum, User* u2, User* u3);

/*Aloca os componentes de uma playlist
Entrada: -
Saida: Uma playlist alocada
*/
Playlist* AlocaPlaylist();

/*Abre as opcoes de abrir uma playlist ja criada
Entrada: -
Saida: -
*/
void AbrePlaylist();

/*Abre as opcoes apagar uma playlist
Entrada: -
Saida: -
*/
void ApagaPlaylist();

/*Adiciona a musica na playlist
Entrada: Uma playlist
		 Todos os albuns
		 QuantidadeDeAlbuns
Saida: -
*/
void AdicionaMusica(Playlist* p, Album* a[], int QtdAlbum);

/*Momento para o usuario adicionar a midia quando quiser
Entrada: Uma playlist
		 Todos os albuns
		 Quantidade De Albuns
Saida: -
*/
void AdicionaMidiaNoMeio(Playlist* p, Album* a[], int QtdAlbum);

/*Apaga uma midia de uma playlist
Entrada: Uma playlist
		 A identificacao da midia que sera apagada
Saida: -
*/
void ApagaMidiaPlaylist(Playlist* p, int id);

/*Troca a ordem de midias na playlist
Entrada: Uma playlist
Saida: -
*/
void TrocaOrdem(Playlist* p);

#endif
