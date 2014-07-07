#ifndef CAIO_H
#define CAIO_H

#include "behaviour.h"
#include "controls.h"
#include "fontconfiguration.h"
#include "imageeffect.h"
#include "text.h"

using namespace behaviour;
using namespace controls;
using namespace fontConfiguration;

class Caio : public ImageEffect
{

public:
	Caio();
	~Caio();

	void update();
	void drawTexts();

	bool nearCivilian(SDL_Rect rect);
	bool overEnemy(SDL_Rect rect);
	bool overItem(SDL_Rect rect);

	bool isCrouching();
	bool isJumping();
	bool isMoving();
	bool isDead();
	bool isImune();

	float getJumpspeed();
	int getDirection();
	int getSpeed();
	int getHealth();
	int getMaxHealth();
	int getItemUsed();

	void setDead(bool dead);
	void setSpeed(int speed);
	void setHealth(int health);
	void setMaxHealth(int quantity);
	void setImune(int imune);

	void resetFirstAid();
	bool successfulFirstAid();

private:
	typedef enum {FIRSTAID, STANDING, JUMPING, CROUCHING, MOVING} State;
	typedef enum {FORWARD, BACKWARD} Looking;
	typedef enum {ENERGYTONIC, ALTEREDTONIC, ANTIALL, FREEBOIMEAT, IMAGINANACOPA, NOUSE} UseItem;

	bool m_dead;
	bool m_imune;

	int m_itemUsed;
	bool m_use;

	float m_jumpspeed;

	int m_dx;
	int m_speed;
	int m_health;
	int m_maxHealth;

	Looking m_looking;
	State m_state;
	UseItem m_useItem;

	Text* m_firstAidCountdown;
	bool m_nearCivilian;
	bool m_nearOnLeftSide;
	bool m_firstAid;
	bool m_successfulFirstAid;

	void generateClips();
	void generateDefaultStats();

	void handleItens();
	
	void stand();
	void standForward();
	void standBackward();

	void crouch();
	void moveCrouch();

	void jump();
	void moveJump();
	
	void move();
	void moveForward();
	void moveBackward();

	void firstAid();
	void moveFirstAid();
	void tickFACountdown();

};

#endif // CAIO_H
