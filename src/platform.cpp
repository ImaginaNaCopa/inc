#include "platform.h"

using namespace std;

Platform::Platform(const string& path) : ImageSprite()
{
	step("[Platform] Constructing.");
	imagePath.assign(path);
	generatePosition(0,getPlatformH(),getWindowW(),getWindowH()-getPlatformH());
}

Platform::~Platform()
{
	step("[Platform] Destroying.");
}