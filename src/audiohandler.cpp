#include "audiohandler.h"

namespace audioHandler
{
	Music sCurrentMusic = NOMUSIC;
	Effect sCurrentEffect = NOEFFECT;

	Mix_Music* currentMusic = NULL;

	Mix_Music* bachizuera = NULL;
	Mix_Music* bossaNovaSafada = NULL;
	Mix_Music* cromusica = NULL;
	Mix_Music* hueragem = NULL; 
	Mix_Music* jornada = NULL;
	Mix_Music* sapucai = NULL;

	Mix_Chunk* currentEffect = NULL;

	Mix_Chunk* civilFlwVlw1 = NULL;
	Mix_Chunk* civilFlwVlw2 = NULL;
	Mix_Chunk* civilFlwVlw3 = NULL;
	Mix_Chunk* civilFlwVlw4 = NULL;
	Mix_Chunk* civilFlwVlw5 = NULL;
	Mix_Chunk* civilFlwVlw6 = NULL;
	Mix_Chunk* civilFlwVlw7 = NULL;

	Mix_Chunk* corruptoDie = NULL;

	Mix_Chunk* enemyHerpDerp1 = NULL;
	Mix_Chunk* enemyHerpDerp2 = NULL;
	Mix_Chunk* enemyHerpDerp3 = NULL;
	Mix_Chunk* enemyHerpDerp4 = NULL;
	Mix_Chunk* enemyHerpDerp5 = NULL;
	Mix_Chunk* enemyHerpDerp6 = NULL;
	Mix_Chunk* enemyHerpDerp7 = NULL;

	Mix_Chunk* fanfare = NULL;
	Mix_Chunk* gameOver = NULL;

	Mix_Chunk* giganteAttack = NULL;
	Mix_Chunk* giganteDie = NULL;

	Mix_Chunk* itemCollect = NULL;
	Mix_Chunk* itemUse = NULL;

	Mix_Chunk* liderAttack = NULL;
	Mix_Chunk* liderDie = NULL;

	Mix_Chunk* ouch = NULL;

	Mix_Chunk* puzzleSolved = NULL;

	Mix_Chunk* shot = NULL;
	Mix_Chunk* shotLong = NULL;

	Mix_Chunk* terroristaDie = NULL;
	Mix_Chunk* urubuDie = NULL;

	int aleatorio = 0;

	void tickRand()
	{
		aleatorio++;
	}

	int getRand()
	{
		return aleatorio;
	}

	void resetRand()
	{
		aleatorio = 0;
	}

	void requestMusic()
	{
		switch(sCurrentMusic)
		{
			case BCH:
				currentMusic = bachizuera;
			break;

			case BNS:
				currentMusic = bossaNovaSafada;
			break;

			case CRO:
				currentMusic = cromusica;
			break;

			case HUE:
				currentMusic = hueragem;
			break;

			case JOR:
				currentMusic = jornada;
			break;

			case SAP:
				currentMusic = sapucai;
			break;

			case NOMUSIC:
				currentMusic = NULL;
			break;
		}
	}

	void requestEffect()
	{
		switch(sCurrentEffect)
		{
			case C1:
				currentEffect = civilFlwVlw1;
			break;
			case C2:
				currentEffect = civilFlwVlw2;
			break;
			case C3:
				currentEffect = civilFlwVlw3;
			break;
			case C4:
				currentEffect = civilFlwVlw4;
			break;
			case C5:
				currentEffect = civilFlwVlw5;
			break;
			case C6:
				currentEffect = civilFlwVlw6;
			break;
			case C7:
				currentEffect = civilFlwVlw7;
			break;

			case pDie:
				currentEffect = corruptoDie;
			break;

			case eDerp1:
				currentEffect = enemyHerpDerp2;
			break;
			case eDerp2:
				currentEffect = enemyHerpDerp2;
			break;
			case eDerp3:
				currentEffect = enemyHerpDerp3;
			break;
			case eDerp4:
				currentEffect = enemyHerpDerp3;
			break;
			case eDerp5:
				currentEffect = enemyHerpDerp5;
			break;
			case eDerp6:
				currentEffect = enemyHerpDerp6;
			break;
			case eDerp7:
				currentEffect = enemyHerpDerp7;
			break;

			case FF:
				currentEffect = fanfare;
			break;
			case GO:
				currentEffect = gameOver;
			break;

			case gAtt:
				currentEffect = giganteAttack;
			break;
			case gDie:
				currentEffect = giganteDie;
			break;

			case iC:
				currentEffect = itemCollect;
			break;
			case iU:
				currentEffect = itemUse;
			break;

			case lAtt:
				currentEffect = liderAttack;
			break;
			case lDie:
				currentEffect = liderDie;
			break;

			case Ouch:
				currentEffect = ouch;
			break;

			case PS:
				currentEffect = puzzleSolved;
			break;

			case S1:
				currentEffect = shot;
			break;

			case S2:
				currentEffect = shotLong;
			break;

			case tDie:
				currentEffect = terroristaDie;
			break;
			case uDie:
				currentEffect = urubuDie;
			break;

			case NOEFFECT:
				currentEffect = NULL;
			break;
		}
	}

	void setCurrentMusic(Music index)
	{
		Mix_HaltMusic();
		if(index != NOMUSIC)
		{
			sCurrentMusic = index;
			requestMusic();
		}
	}

	void playMusic(const int times)
	{
		if(currentMusic)
		{
			Mix_VolumeMusic(MIX_MAX_VOLUME);
			Mix_PlayMusic(currentMusic, times);
		}
	}

	void initMusicsAndSoundEffects()
	{
		bachizuera = Mix_LoadMUS("res/audios/bgm/bachizuera.wav");
		bossaNovaSafada = Mix_LoadMUS("res/audios/bgm/bossa_nova_safada.wav");
		cromusica = Mix_LoadMUS("res/audios/bgm/cromusica.wav");
		hueragem = Mix_LoadMUS("res/audios/bgm/hueragem.wav");
		jornada = Mix_LoadMUS("res/audios/bgm/jornada.wav");
		sapucai = Mix_LoadMUS("res/audios/bgm/sapucai.wav");

		civilFlwVlw1 = Mix_LoadWAV("res/audios/se/civil_flwvlw_1.ogg");
		civilFlwVlw2 = Mix_LoadWAV("res/audios/se/civil_flwvlw_2.ogg");
		civilFlwVlw3 = Mix_LoadWAV("res/audios/se/civil_flwvlw_3.ogg");
		civilFlwVlw4 = Mix_LoadWAV("res/audios/se/civil_flwvlw_4.ogg");
		civilFlwVlw5 = Mix_LoadWAV("res/audios/se/civil_flwvlw_5.ogg");
		civilFlwVlw6 = Mix_LoadWAV("res/audios/se/civil_flwvlw_6.ogg");
		civilFlwVlw7 = Mix_LoadWAV("res/audios/se/civil_flwvlw_7.ogg");

		corruptoDie = Mix_LoadWAV("res/audios/se/corrupto_die.ogg");

		enemyHerpDerp1 = Mix_LoadWAV("res/audios/se/enemy_herpderp_1.ogg");
		enemyHerpDerp2 = Mix_LoadWAV("res/audios/se/enemy_herpderp_2.ogg");
		enemyHerpDerp3 = Mix_LoadWAV("res/audios/se/enemy_herpderp_3.ogg");
		enemyHerpDerp4 = Mix_LoadWAV("res/audios/se/enemy_herpderp_4.ogg");
		enemyHerpDerp5 = Mix_LoadWAV("res/audios/se/enemy_herpderp_5.ogg");
		enemyHerpDerp6 = Mix_LoadWAV("res/audios/se/enemy_herpderp_6.ogg");
		enemyHerpDerp7 = Mix_LoadWAV("res/audios/se/enemy_herpderp_7.ogg");

		fanfare = Mix_LoadWAV("res/audios/se/fanfare.ogg");
		gameOver = Mix_LoadWAV("res/audios/se/game_over.ogg");

		giganteAttack = Mix_LoadWAV("res/audios/se/gigante_attack.ogg");
		giganteDie = Mix_LoadWAV("res/audios/se/gigante_die.ogg");

		itemCollect = Mix_LoadWAV("res/audios/se/item_collect.ogg");
		itemUse = Mix_LoadWAV("res/audios/se/item_use.ogg");

		liderAttack = Mix_LoadWAV("res/audios/se/lider_attack.ogg");
		liderDie = Mix_LoadWAV("res/audios/se/lider_die.ogg");

		ouch = Mix_LoadWAV("res/audios/se/ouch.ogg");

		puzzleSolved = Mix_LoadWAV("res/audios/se/puzzle_solved.ogg");

		shot = Mix_LoadWAV("res/audios/se/shot.ogg");
		shotLong = Mix_LoadWAV("res/audios/se/shot_long.ogg");

		terroristaDie = Mix_LoadWAV("res/audios/se/terrorista_die.ogg");
		urubuDie = Mix_LoadWAV("res/audios/se/urubu_die.ogg");
	}

	void freeMusicsAndSoundEffects()
	{
		Mix_FreeMusic(bachizuera);
		Mix_FreeMusic(bossaNovaSafada);
		Mix_FreeMusic(cromusica);
		Mix_FreeMusic(hueragem);
		Mix_FreeMusic(jornada);
		Mix_FreeMusic(sapucai);

		Mix_FreeChunk(civilFlwVlw1);
		Mix_FreeChunk(civilFlwVlw2);
		Mix_FreeChunk(civilFlwVlw3);
		Mix_FreeChunk(civilFlwVlw4);
		Mix_FreeChunk(civilFlwVlw5);
		Mix_FreeChunk(civilFlwVlw6);
		Mix_FreeChunk(civilFlwVlw7);
		Mix_FreeChunk(corruptoDie);
		Mix_FreeChunk(enemyHerpDerp1);
		Mix_FreeChunk(enemyHerpDerp2);
		Mix_FreeChunk(enemyHerpDerp3);
		Mix_FreeChunk(enemyHerpDerp4);
		Mix_FreeChunk(enemyHerpDerp5);
		Mix_FreeChunk(enemyHerpDerp6);
		Mix_FreeChunk(enemyHerpDerp7);
		Mix_FreeChunk(fanfare);
		Mix_FreeChunk(gameOver);
		Mix_FreeChunk(giganteAttack);
		Mix_FreeChunk(giganteDie);
		Mix_FreeChunk(itemCollect);
		Mix_FreeChunk(itemUse);
		Mix_FreeChunk(liderAttack);
		Mix_FreeChunk(liderDie);
		Mix_FreeChunk(ouch);
		Mix_FreeChunk(puzzleSolved);
		Mix_FreeChunk(shot);
		Mix_FreeChunk(shotLong);
		Mix_FreeChunk(terroristaDie);
		Mix_FreeChunk(urubuDie);

		currentMusic = NULL;
		bachizuera = NULL;
		bossaNovaSafada = NULL;
		cromusica = NULL;
		hueragem = NULL;
		jornada = NULL;
		sapucai = NULL;
		currentEffect = NULL;
		civilFlwVlw1 = NULL;
		civilFlwVlw2 = NULL;
		civilFlwVlw3 = NULL;
		civilFlwVlw4 = NULL;
		civilFlwVlw5 = NULL;
		civilFlwVlw6 = NULL;
		civilFlwVlw7 = NULL;
		corruptoDie = NULL;
		enemyHerpDerp1 = NULL;
		enemyHerpDerp2 = NULL;
		enemyHerpDerp3 = NULL;
		enemyHerpDerp4 = NULL;
		enemyHerpDerp5 = NULL;
		enemyHerpDerp6 = NULL;
		enemyHerpDerp7 = NULL;
		fanfare = NULL;
		gameOver = NULL;
		giganteAttack = NULL;
		giganteDie = NULL;
		itemCollect = NULL;
		itemUse = NULL;
		liderAttack = NULL;
		liderDie = NULL;
		ouch = NULL;
		puzzleSolved = NULL;
		shot = NULL;
		shotLong = NULL;
		terroristaDie = NULL;
		urubuDie = NULL;
	}

	void setCurrentEffect(Effect index){
		if(index != NOEFFECT)
		{
			sCurrentEffect = index;
			requestEffect();
		}
	}

	void playEffect(){
		if(currentEffect)
		{
			Mix_Volume(-1, MIX_MAX_VOLUME);
			Mix_PlayChannel(-1, currentEffect, 0);
		}
	}
}