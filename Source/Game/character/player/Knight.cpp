#include "stdafx.h"
#include "Knight.h"

#include "../../weapon/melee_weapon/Hammer.h"
#include "../../weapon/melee_weapon/Hoe.h"
#include "../../weapon/melee_weapon/Spear.h"
#include "../../weapon/ranged_weapon/BadPistol.h"
#include "../../weapon/ranged_weapon/Bow.h"
#include "../../weapon/ranged_weapon/GoblinStaff.h"
#include "../../weapon/ranged_weapon/Pistol.h"
#include "../../weapon/ranged_weapon/Shotgun.h"

Knight::Knight() {
}

void Knight::Start() {
    Player::Start();
    weaponOffsetX = 7;
    weaponOffsetY = 7;
    ChangeWeapon(new Shotgun());
    maxHp = 7;
    hp = maxHp;
    maxMp = 200;
    mp = maxMp;
    maxShild = 6;
    shield = maxShild;
}

void Knight::Update() {
    Player::Update();
}

void Knight::Skill() {
    
}

void Knight::LoadResources() {
    this->AddAnimation({
                           "resources/player/knight/idle/1.bmp",
                           "resources/player/knight/idle/2.bmp",
                           "resources/player/knight/idle/3.bmp",
                           "resources/player/knight/idle/4.bmp"
                       }, RGB(255, 255, 255), 100, false);

    this->AddAnimation({
                           "resources/player/knight/idle/flip_1.bmp",
                           "resources/player/knight/idle/flip_2.bmp",
                           "resources/player/knight/idle/flip_3.bmp",
                           "resources/player/knight/idle/flip_4.bmp"
                       }, RGB(255, 255, 255), 100, false);

    this->AddAnimation({
                           "resources/player/knight/run/1.bmp",
                           "resources/player/knight/run/2.bmp",
                           "resources/player/knight/run/3.bmp",
                           "resources/player/knight/run/4.bmp"
                       }, RGB(255, 255, 255), 100, false);

    this->AddAnimation({
                           "resources/player/knight/run/flip_1.bmp",
                           "resources/player/knight/run/flip_2.bmp",
                           "resources/player/knight/run/flip_3.bmp",
                           "resources/player/knight/run/flip_4.bmp"
                       }, RGB(255, 255, 255), 100, false);

    this->AddAnimation({
                           "resources/player/knight/dead.bmp",
                       }, RGB(255, 255, 255), 100, true);

    this->AddAnimation({
                           "resources/player/knight/flip_dead.bmp",
                       }, RGB(255, 255, 255), 100, true);
}
