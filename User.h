#ifndef _USER
#define _USER

typedef struct user User;

typedef struct playlist Playlist;

typedef struct midia Midia;

/*Aloca memoria para usuario
Entrada: -
Saida: usuario alocado
*/
User* AlocaUsuario();

/*Verifica se pelo menos uma playlist daquele usuario ja foi criada
Entrada: um usuario
Saida: -
*/
int VerificaPlaylist(User* u);

/*Compara nomes
Entrada: um usuario
		 um nome para comparar
Saida: um inteiro (1 - nomes iguais, 2 - nomes diferentes)
*/
int ComparaNomes(User* u, char nome[]);

/*Imprime uma playlist desejada
Entrada: um usuario
Saida: -
*/
void MostraPlaylists(User* u);

/*Entra na opcao de editar uma playlist
Entrada: Um usuario
		 Todos os albuns
		 Quantidade De Albuns
		 Tipo de edicao que deseja realizar
Saida: -
*/
void EditaPlaylists(User* u, Album* a[], int QtdAlbum, int tipo);

/*Salva dados dos usuarios
Entrada: Um usuario
		 Um arquivo
Saida: -
*/
void salvaUsuario(User* u, FILE* f);

/*Utiliza a leitura a partir de arquivos (conta ja criada)
Entrada: Quantidade de albuns
		 Todos os albuns
         Um arquivo contendo a conta ja criada
Saida: Usuario alocado e preenchido
*/
User* ObtemUsuarioJaCriado(int QtdAlbum, Album* album[], FILE* c);

/*Faz a distribuicao das playlists compartilhadas 
Entrada: Usuario 1
         Usuario 2
         Usuario 3
Saida: -
*/
void DistribuiPlayCompartilhada(User* u1, User* u2, User* u3);



#endif
