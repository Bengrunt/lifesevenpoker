#ifndef AfficheSdl_H
#define AfficheSdl_H

#include "AfficheDynamique.h"


/** @brief
	@note
*/
void pause();


/** @brief Fonction qui initialise SDL et ses sous-systemes.
	@param [in,out] screen La surface principale de SDL.
	@param [in] screen_width La largeur de la surface principale.
	@param [in] screen_height La hauteur de la surface principale.
	@param [in] screen_bpp Le nombre de bits par pixels de la surface principale.
	@param [in] caption Une chaine de caracteres representant le nom de la fenetre du programme.
	@return Renvoie un booleen
	@note
*/
bool initSDL(SDL_Surface* & screen, const int & screen_width, const int & screen_height, const int & screen_bpp, const char* caption);


/** @brief Fonction permettant le chargement d'une image dans certains formats.
    @param [in] filename Une chaine de caracteres representant le nom de fichier.
    @return Renvoie un pointeur sur l'image chargée en mémoire.
    @note Formats supportés : BMP, GIF, JPEG, LBM, PCX, PNM, TGA, TIFF, XCF, XPM, XV et PNG.
*/
SDL_Surface *load_image( const char* filename );


/** @brief Procedure qui applique une surface SDL sur une autre selon la méthode du "blitting", qui est en quelque sort un collage simple.
    @param [in] x Coordonnee en x pour le blitting de l'image.
    @param [in] y Coordonnee en y pour le blitting de l'image.
    @param [in] source Le pointeur sur image de ce qu'on veut blitter.
    @param [in] destination Le pointeur sur image de sur quoi on veut blitter.
    @note Attention : le système de coordonnees utilise ici est un systeme X,Y dont l'origine est le coin superieur gauche de l'image et dont l'axe Y est inverse et pointe vers le bas.
*/
void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination );


/** @brief
	@param affichage
	@param x
	@param y
	@param zoom
	@note
*/
void affichageOmbreCarte(SDL_Surface* affichage,int x,int y,double zoom);


/** @brief
	@param affichage
	@param c
	@param x
	@param y
	@param zoom
	@note
*/
void AffAfficheCarte(SDL_Surface* affichage, Carte* c, int x, int y, double zoom);


/** @brief
	@param affichage
	@param c
	@param x
	@param y
	@param zoom
	@param evidence
	@note
*/
void AffAfficheCarte(SDL_Surface* affichage, Carte* c, int x, int y, double zoom,bool evidence);


/** @brief
	@param destination
	@param message
	@param x
	@param y
	@param r
	@param g
    @param b
	@param style
	@param size
	@note
*/
void AffAfficheTexte(SDL_Surface* destination,const char* message,int x,int y,int r,int g,int b,int style,int size);


/** @brief
	@param destination
	@param message
	@param x
	@param y
	@param r
	@param g
    @param b
	@return
	@note fait appel a AffAfficheTexte(destination,message,x,y,r,g,b,TTF_STYLE_NORMAL,28)
*/
void AffAfficheTexte(SDL_Surface* destination,const char* message,int x,int y,int r,int g,int b);


/** @brief
	@param affichage
	@note
*/
void AffActualiser(SDL_Surface* affichage);


/** @brief
	@param aff
	@param tapis
	@note
*/
void AffAfficheTapis(SDL_Surface* aff,SDL_Surface* tapis);


#endif

