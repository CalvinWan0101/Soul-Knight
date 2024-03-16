﻿#include "stdafx.h"
#include "monster.h"
#include "../../weapon/weapon.h"

#include <iostream>

#include "../../weapon/BadPistol.h"

Monster::Monster()
{
}


void Monster::Start()
{
    this->AddAnimation({
                           "resources/monster/floor_1/goblin_giant/idle/1.bmp",
                           "resources/monster/floor_1/goblin_giant/idle/2.bmp",
                           "resources/monster/floor_1/goblin_giant/idle/3.bmp",
                           "resources/monster/floor_1/goblin_giant/idle/4.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_1/goblin_giant/run/1.bmp",
                           "resources/monster/floor_1/goblin_giant/run/2.bmp",
                           "resources/monster/floor_1/goblin_giant/run/3.bmp",
                           "resources/monster/floor_1/goblin_giant/run/4.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->index = 0;
    this->speed.SetVec(0.0, 0.0);
    this->AddFrontChild(static_cast<Weapon*>(new BadPistol()));
}

void Monster::Update()
{
    // Vec v = frontGameObjects[0]->GetPoint() - Point(0, 0);
    // v.Rotate(0.1);
    // if (v.GetRadian() > 6)
    // {
    //     v.SetLength(v.GetLength() + 10);
    // }
    // frontGameObjects[0]->GetPoint() = Point(0, 0) + v;
    // run.Notify(this);
}