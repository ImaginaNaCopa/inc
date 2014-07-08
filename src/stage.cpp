#include "stage.h"
#include <iostream>

using namespace std;

Stage::Stage() : Scenario(), Hud(), Entity()
{}

Stage::~Stage()
{
	delete m_text;
}

void 
Stage::init()
{
	m_text = new Text(getFontTulpenOne(),getFontSize(8));
	m_text->addPosition(getWindowW()/2-120, getWindowH()/2-60);
	m_text->addText("Caio morreu! :(");
	m_text->setColor(0, 0, 0, 255);
	m_text->setTextNumber(0);
	m_text->setPositionNumber(0);
	
	step("[Stage] Initiating Each Stage Object.");
	initScenario();
	initHud();
	initEntity();
}

void
Stage::draw()
{
	loop("[Stage] Drawing Each Stage Object.");
	
	if (caio->getHealth() == 0)
	{
		m_text->drawText();
	}
	else
	{
		drawScenarioStaticImages();
		drawScenarioRelativeImages();
		drawHud();
		drawEntity();
	}
}

void 
Stage::update()
{
	setOver(false);
	loop("[Stage] Updating Each Stage Object.");
	if (caio->getHealth() != 0)
	{
		updateEntity();
		controlEntityEvents();
	}
	else
	{
		setOver(true);
		setFinished(false);
		setGameOver(true);
	}
	if(caio->getPosition().x >= 1500)
	{
		setOver(true);
		setFinished(true);
	}
}

void
Stage::setGameOver(bool over)
{
	m_gameOver = over;
}

bool
Stage::gameOver()
{
	loop("[Stage] Returning Game Over.");
	return m_gameOver;
}

void 
Stage::setFinished(bool finished)
{
	m_finished = finished;
}

bool
Stage::isFinished()
{
	loop("[Stage] Returning True if Finished.");
	return m_finished;
}


void 
Stage::damagingCaio()
{
	loop("[Stage] Verifying if Caio is imune.");
	if (!caio->isImune())
	{
		for (auto it = enemies.begin(); it != enemies.end(); it++)
		{
			loop("[Stage] Verifying Collision Between Caio and Enemies.");
			if (caio->overEnemy((*it)->getPosition()))
			{
				caio->setImune(true);
				caio->resetFirstAid();
				caio->setHealth(-1);
				hp->setHp(caio->getHealth());
				cout << "hp: " << hp->getHp() << endl;
				caio->newReverseFade();
			}
		}
	}
	else
	{
  		caio->defineCurrentIdleTime(2);
    	if (caio->getCurrentIdleTime() == 5)
    	{
    		caio->setCurrentIdleTime(0);
    		caio->setImune(false);
    	}
    	else
    	{
    		if(caio->isFadeEnded())
    		{
	    		caio->newReverseFade();
	    		caio->setCurrentIdleTime(1+caio->getCurrentIdleTime());
    		}
  			caio->reverseFade(85,0);
    	}
	}

	if (caio->getHealth() == 0)
		caio->release();
}

void
Stage::lootItem()
{
	auto loot = itens.end();

	for (auto it = itens.begin(); it != itens.end(); it++)
	{
		loop("[Stage] Verifying Collision Between Caio and Itens.");
		if (caio->overItem((*it)->getPosition()))
		{
			loot = it;
			switch ((*loot)->getId())
			{
				case 1:
					inventory->setQtdPotion(1);
				break;
				case 2:
					inventory->setQtdAlteredPotion(1);
				break;
				case 3:
					// Nothing yet
				break;
				default:
					// Nothing to do
				break;
			}
		}
	}

	if (loot != itens.end())
	{
    	loop("[Stage] Delete all Dead Enemies.");
  		delete *loot;
		itens.erase(loot);
	}
}

void
Stage::killingEnemy()
{
	auto dead = enemies.end();
	for (auto it = enemies.begin(); it != enemies.end(); it++)
	{
		if (aim->overEnemy((*it)->getPosition()) && isCShooted())
		{
  		loop("[Stage] if Shooted an Enemy, define Dead to it.");
			falseCShoot();
			sebastiao->setShoot(true);
			dead = it;
   		SDL_Rect position = (*dead)->getPosition();

			switch ((*dead)->getItem())
			{
				case 0:
					// Nothing to drop
				break;
				case 1: // Normal Potion Drop
					item = new Potion(round(position.x + (position.w/2)), position.y);
					item->init();
					itens.push_back(item);
				break;
				case 2: // Altered Potion Drop
					item = new AlteredPotion(round(position.x + (position.w/2)), position.y);
					item->init();
					itens.push_back(item);
				break;
				case 3:
				break;
				case 4:
				break;
				case 5:
				break;
				case 6:
				break;
				default:
				break;
			}
			break;
		}
	}
	falseCShoot();

	if (dead != enemies.end())
	{
    loop("[Stage] Delete all Dead Enemies.");
  	delete *dead;
		enemies.erase(dead);
	}
}

void
Stage::usingItens()
{
	switch (caio->getItemUsed())
	{
		case 1:
			cout << "health atual: " << caio->getHealth() << endl;
			if (caio->getHealth() < caio->getMaxHealth() && inventory->getQtdPotion() > 0)
			{
				caio->setHealth(+1);
				hp->setHp(caio->getHealth());
				inventory->setQtdPotion(-1);
			}
		break;
		case 2:
			cout << "health máximo: " << caio->getMaxHealth() << endl;
			if (caio->getMaxHealth() < 7 && inventory->getQtdAlteredPotion() > 0)
			{
				caio->setMaxHealth(1);
				hp->setMaxHp(caio->getMaxHealth());
				inventory->setQtdAlteredPotion(-1);
			}
		break;
		case 3:
			cout << caio->getItemUsed() << endl;
		break;
		case 5:
			cout << caio->getItemUsed() << endl;
		break;
		case 6:
			cout << caio->getItemUsed() << endl;
		break;
		default:
		break;
	}
}

void
Stage::rescuingCivilian()
{
	auto secured = civis.end();
	loop("[LevelTwo] Handling Civil Rescue.");
	for (auto it = civis.begin(); it != civis.end(); it++)
	{
		if((*it)->isRunned())
			secured = it;
		loop("[Stage] Verifying Collision Between Caio and Civil.");
		if(caio->nearCivilian((*it)->getPosition()))
		{
			if(caio->successfulFirstAid())
				(*it)->saved();
			break;
		}
	}
	if (secured != civis.end())
	{
  	delete *secured;
		civis.erase(secured);
	}
}

void
Stage::controlEntityEvents()
{
	loop("[LevelTwo] Handling Specific Entity Conditions.");

	damagingCaio();
	lootItem();
	killingEnemy();
	rescuingCivilian();
	usingItens();
}