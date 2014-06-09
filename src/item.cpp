#include "item.h"
#include "systemlogger.h"
#include <iostream>

using namespace std;
using namespace systemLogger;

Item::Item()
{
    step("[Item] Contructing.");
}

Item::~Item()
{
    step("[Item] Destroying.");
}

void
Item::initItem()
{
    step("[Item] Initing.");
}

void
Item::drawItem()
{
    loop("[Item] Initing.");
}

void
Item::updateItem()
{
    loop("[Item] Initing.");
}