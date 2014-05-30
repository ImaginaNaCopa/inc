#include "resource.h"

bool ILM_IfEmpty(struct ILM *pList)
{
	if(pList==NULL)
		return true;
	else
		return false;
}

bool ILM_SearchNode(struct ILM *pList, int id)
{
	struct ILM *pAux;
	pAux = pList;
	while((pAux->s_id!=id)&&(pAux->Prox!=NULL))
	{
		pAux = pAux->Prox;
	}
	if(pAux->s_id!=id)
		return false;
	else
		return true;	
}

int ILM_VerifyInstance(struct ILM *pList, int id)
{
	struct ILM *pAux;
	pAux = pList;
	while(pAux->s_id!=id)
		pAux = pAux->Prox;
	return pAux->s_instance;
}

struct ILM *ILM_NewNode(struct ILM *pList, int id, SDL_Texture *texture)
{
	struct ILM *pNewNode;
	pNewNode = (ILM*) malloc(sizeof(ILM));
	pNewNode->s_id = id;
	pNewNode->s_instance = 1;
	pNewNode->s_texture = texture;
	pNewNode->Prox = pList;
	pList = pNewNode;
	return pList;
}

struct ILM *ILM_FreeNode(struct ILM *pList, int id)
{
	if(pList->s_id==id)
	{
		struct ILM *pAux;
		pAux = pList;
		pList = pAux->Prox;
		free(pAux);
		return pList;
	}
	else
	{
		struct ILM *pBefore;
		pBefore = pList;
		while(pBefore->Prox->s_id!=id)
			pBefore = pBefore->Prox;
		if(pBefore->Prox->Prox!=NULL)
		{
			struct ILM *pAfter;
			pAfter = pBefore->Prox->Prox;
			free(pBefore->Prox);
			pBefore->Prox=pAfter;
		}
		else
		{
			free(pBefore->Prox);
			pBefore->Prox = NULL;
		}
		return pList;
	}
}

struct ILM *ILM_PlusInstance(struct ILM *pList, int id)
{
	struct ILM *pAux;
	pAux = pList;
	while(pAux->s_id!=id)
		pAux = pAux->Prox;
	pAux->s_instance++;
	return pList;
}

struct ILM *ILM_MinusInstance(struct ILM *pList, int id)
{
	struct ILM *pAux;
	pAux = pList;
	while(pAux->s_id!=id)
		pAux = pAux->Prox;
	pAux->s_instance--;
	return pList;
}

bool ISM_IfEmpty(struct ISM *pList)
{
	if(pList==NULL)
		return true;
	else
		return false;
}

struct ISM *ISM_Pop(struct ISM *pList)
{
	struct ISM *pAux;
	pAux = pList;
	pList = pAux->Prox;
	free(pAux);
	return pList;
}

SDL_Rect *ISM_TopSrc(struct ISM *pList)
{
	return pList->s_src;
}

SDL_Rect *ISM_TopDest(struct ISM *pList)
{
	return pList->s_dest;
}

SDL_Texture *ISM_TopTexture(struct ISM *pList)
{
	return pList->s_texture;
}

struct ISM *ISM_Insert(struct ISM *pList, SDL_Rect *src, SDL_Rect *dest, SDL_Texture *texture)
{
	struct ISM *pNewNode;
	pNewNode = (ISM*) malloc(sizeof(ISM));
	pNewNode->s_src = src;
	pNewNode->s_dest = dest;
	pNewNode->s_texture = texture;
	pNewNode->Prox = pList;
	pList = pNewNode;
	return pList;
}