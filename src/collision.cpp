#include "../include/collision.h"

namespace collision
{
	bool
	ifCollided(int type, SDL_Rect positionSource, SDL_Rect positionTarget)
	{
		//loop("[Collision] Verifying if Two Rects Collided.");
		if(	positionSource.x+positionSource.w >= positionTarget.x &&
			positionSource.x <= positionTarget.x + positionTarget.w &&
			positionSource.y+positionSource.h >= positionTarget.y &&
			positionSource.y <= positionTarget.y + positionTarget.h	)
		{
			switch(type)
			{
				case 0:
					//condition("[Collision] Two Rects Collided, General Case.");
					return true;
				break;
				case 1:
					if(positionSource.x+positionSource.w/2 < positionTarget.x+positionTarget.w/2)
					{
						//condition("[Collision] Source Rect Collided in Left Side of Target.");
						return true;
					}
				break;
				case 2:
					if(positionSource.x+positionSource.w/2 >= positionTarget.x+positionTarget.w/2)
					{
						//condition("[Collision] Source Rect Collided in Right Side of Target.");
						return true;
					}
				break;
				case 3:
					if(positionSource.y+positionSource.h/2 < positionTarget.y+positionTarget.h/2)
					{
						//condition("[Collision] Source Rect Collided Above of Target.");
						return true;
					}
				break;
				case 4:
					if(positionSource.y+positionSource.h/2 >= positionTarget.y+positionTarget.h/2)
					{
						//condition("[Collision] Source Rect Collided Below of Target.");
						return true;
					}
				break;
				default:
				break;
			}
		}
		return false;
	}
}