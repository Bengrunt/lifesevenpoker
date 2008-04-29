/**
	@brief Fichier H pour l'affichage dynamique


	Gere l'affichage dynamique en utilisant le moteur de rendu SDL (Simple Directmedia Layer).

	@author  James Benjamin
	@file AfficheDynamique.h
	@version 1.2
	@date 2008/04/21
 */

//Librairies Standard.
#include <stdlib.h>
#include <stdio.h>

//Librairies SDL.
#include <SDL/SDL.h>
#include "SDL/SDL_image.h" //Gestion des images.
#include "SDL/SDL_ttf.h" //Gestion des polices True Type Fonts.
#include "SDL/SDL_mixer.h" //Gestion du multi channeling audio.



/** 	@brief
	@param
	@param
	@param
	@param 
	@param [in] filename Une chaine de caracteres representant le nom de fichier.
	@return Renvoie un booleen
	@note 
*/
bool init(SDL_Surface* & screen, const int & screen_width, const int & screen_height, const int & screen_bpp, char* caption)


/** @brief Fonction permettant le chargement d'une image dans certains formats.
    @param [in] filename Une chaine de caracteres representant le nom de fichier.
    @return Renvoie un pointeur sur l'image chargée en mémoire.
    @note Formats supportés : BMP, GIF, JPEG, LBM, PCX, PNM, TGA, TIFF, XCF, XPM, XV et PNG.
*/
SDL_Surface *load_image( std::string filename );

/** @brief Procedure qui applique une surface SDL sur une autre selon la méthode du "blitting", qui est en quelque sort un collage simple.
    @param [in] x Coordonnee en x pour le blitting de l'image.
    @param [in] y Coordonnee en y pour le blitting de l'image.
    @param [in] source Le pointeur sur image de ce qu'on veut blitter.
    @param [in] destination Le pointeur sur image de sur quoi on veut blitter.
    @note Attention : le système de coordonnees utilise ici est un systeme X,Y dont l'origine est le coin superieur gauche de l'image et dont l'axe Y est inverse et pointe vers le bas.
*/
void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination );