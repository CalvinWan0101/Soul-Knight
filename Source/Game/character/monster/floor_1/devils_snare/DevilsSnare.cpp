﻿#include "stdafx.h"
#include "DevilsSnare.h"

#include "../../../../manager/ObjectManager.h"
#include "../../../../pool/ProjectilePool.h"
#include "../../../../projectile/bullet/RedRectangleBullet.h"
#include "../../../../weapon/melee_weapon/Hammer.h"
#include "../../../../weapon/ranged_weapon/UfoWeapon.h"
#include "DevilsSnareSkill.h"

DevilsSnare::DevilsSnare(double level = 1) : Monster(level), timer(0) {
    skill0 = new DevilsSnareSkill0(&position);
    skill1 = new DevilsSnareSkill1(&position);
    skill2 = new DevilsSnareSkill2(&position);
    skill3 = new DevilsSnareSkill3(&position);
    skill4 = new DevilsSnareSkill4(&position);
    skill5 = new DevilsSnareSkill5(&position);
}

DevilsSnare::~DevilsSnare() {
    delete skill0;
    delete skill1;
    delete skill2;
    delete skill3;
    delete skill4;
    delete skill5;
}

void DevilsSnare::Start() {
    Monster::Start();
    this->maxHp = 552 * level;
    hp = maxHp;
    this->speed.SetVec(0.0, 0.0);
    this->maxSpeed = 0.0001;
    SetMonsterType(MonsterType::DEVELS_SNARE);
}

void DevilsSnare::Update() {
    Monster::Update();
    skill0->Update();
    skill1->Update();
    skill2->Update();
    skill3->Update();
    skill4->Update();
    skill5->Update();
    if (timer == 0) {
        // skill0->Activate();
        // skill1->Activate();
        // skill2->Activate();
        // skill3->Activate();
        skill4->Activate();
        // skill5->Activate();
        timer = 100;
    }
    timer--;
}

void DevilsSnare::LoadResources() {
    this->AddAnimation({
                           "resources/monster/floor_1/devils_snare/section_1/1.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_1/devils_snare/section_1/flip_1.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_1/devils_snare/section_1/1.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_1/devils_snare/section_1/flip_1.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_1/devils_snare/dead.bmp"
                       }, RGB(255, 255, 255), 100, false);
    this->AddAnimation({
                           "resources/monster/floor_1/devils_snare/flip_dead.bmp"
                       }, RGB(255, 255, 255), 100, false);
}

void DevilsSnare::AutoMation() {
}

void DevilsSnare::InitializeWeapon() {
    this->SetWeapon(new UfoWeapon(5));
}
