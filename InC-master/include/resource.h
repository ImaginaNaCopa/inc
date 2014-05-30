#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#ifndef RESOURCE_H
#define RESOURCE_H

// Image List Manager
struct ILM{
	int s_id;
	int s_instance;
	SDL_Texture *s_texture;
	struct ILM *Prox;
	ILM(){s_id=0, s_instance=0, s_texture=NULL, Prox=NULL;}
};

// Image Stack Manager
struct ISM{
	SDL_Rect *s_src;
	SDL_Rect *s_dest;
	SDL_Texture *s_texture;
	struct ISM *Prox;
	ISM(){s_src=NULL,s_dest=NULL,s_texture=NULL,Prox=NULL;}
};

extern bool ILM_IfEmpty(struct ILM *pList);
extern bool ILM_SearchNode(struct ILM *pList, int id);
extern int ILM_VerifyInstance(struct ILM *pList, int id);
extern struct ILM *ILM_NewNode(struct ILM *pList, int id, SDL_Texture *texture);
extern struct ILM *ILM_FreeNode(struct ILM *pList, int id);
extern struct ILM *ILM_PlusInstance(struct ILM *pList, int id);
extern struct ILM *ILM_MinusInstance(struct ILM *pList, int id);

extern bool ISM_IfEmpty(struct ISM *pList);
extern struct ISM *ISM_Pop(struct ISM *pList);
extern SDL_Rect *ISM_TopSrc(struct ISM *pList);
extern SDL_Rect *ISM_TopDest(struct ISM *pList);
extern SDL_Texture *ISM_TopTexture(struct ISM *pList);
extern struct ISM *ISM_Insert(struct ISM *pList, SDL_Rect *src, SDL_Rect *dest, SDL_Texture *texture);

#endif