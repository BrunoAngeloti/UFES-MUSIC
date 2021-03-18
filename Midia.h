#ifndef _MIDIA
#define _MIDIA
#include "Playlist.h"

typedef struct midia Midia;

/*Atribui e aloca uma midia
Entrada: -
Saida: Uma midia pronta
*/
Midia* AtribuiMidia(FILE* adm);

/*Apaga uma midia
Entrada: Uma midia
Saida: -
*/
void ApagaMidia(Midia* m);

/*Cria a midia, alocando todos os seus componentes
Entrada: -
Saida: Uma midia alocada e preenchida
*/
Midia* CriaMidia(FILE* adm);

/*Atribui o cantor da midia na midia
Entrada: Uma midia
		 O cantor da midia
Saida: -
*/
void AtribuiCantor(Midia* m, char* cantor);

/*Atribui o compositor da midia na midia
Entrada: Uma midia
		 O compositor da midia
Saida: -
*/
void AtribuiCompositor(Midia* m, char* compositor);

/*Atribui o genero da midia na midia
Entrada: Uma midia
		 O genero da midia
Saida: -
*/
void AtribuiGenero(Midia* m, char* genero);

/*Atribui o tempo da midia na midia
Entrada: Uma midia
		 O tempo da midia
Saida: -
*/
void AtribuiTempo(Midia* m, float tempo);

/*Atribui o tipo da midia na midia
Entrada: Uma midia
		 O tipo da midia
Saida: -
*/
void AtribuiTipoMidia(Midia* m, int tipo);

/*Atribui o nome da midia na midia
Entrada: Uma midia
		 O nome da midia
Saida: -
*/
void AtribuiNomeMidia(Midia* m, char* nome);

/*Imprime a midia, contendo todas suas caracteristicas
Entrada: Uma midia
Saida: -
*/
void ImprimeMidia(Midia* m);

/*Le o nome da midia
Entrada: Uma midia
Saida: -
*/
void LeNomeMidia(Midia* m, FILE* adm);

/*Le o compositor da midia
Entrada: Uma midia
Saida: -
*/
void LeCompositor(Midia* m, FILE* adm);

/*Le o tipo da midia
Entrada: Uma midia
Saida: -
*/
void LeTipoMidia(Midia* m, FILE* adm);

/*Le o genero da midia
Entrada: Uma midia
Saida: -
*/
void LeGenero(Midia* m, FILE* adm);

/*Le o cantor da midia
Entrada: Uma midia
Saida: -
*/
void LeCantor(Midia* m, FILE* adm);

/*Le o tempo da midia
Entrada: Uma midia
Saida: -
*/
void LeTempo(Midia* m, FILE* adm);

/*Retorna o nome da midia
Entrada: Uma midia
Saida: o nome da midia
*/
char* RecuperaNomeMidia(Midia* m);

/*Retorna o nome do cantor da midia
Entrada: Uma midia
Saida: o nome do cantor da midia
*/
char* RecuperaCantorMidia(Midia* m);

/*Retorna o genero da midia
Entrada: Uma midia
Saida: o genero da midia
*/
char* RecuperaGeneroMidia(Midia* m);

/*Aloca espaco para uma midia
Entrada: -
Saida: midia alocada
*/
Midia* AlocaMidia();

#endif
