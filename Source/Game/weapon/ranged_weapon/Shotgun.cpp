﻿#include "stdafx.h"
#include "Shotgun.h"

#include "../../manager/ObjectManager.h"
#include "../../projectile/bullet/BadPistolBullet.h"

Shotgun::Shotgun(Point point) : RangedWeapon(point) {
}

Shotgun::Shotgun(double damage) : RangedWeapon(damage) {
}

Weapon* Shotgun::Copy() {
    return new Shotgun(this->position);
}

void Shotgun::Start() {
    SetImages("Resources/weapon/shotgun/", 3, RGB(255, 255, 255));
    SetAttackAnimation({-0.8, -0.4, 0}, {-2, 0}, 0.5);
    RangedWeapon::Start();
}

void Shotgun::Update() {
    RangedWeapon::Update();
}

void Shotgun::Attack() {
    Vec currentRotation = this->rotation;
    currentRotation.Rotate(0.4);

    Bullet* bullet1 = new BadPistolBullet();
    bullet1->SetSpeed(currentRotation, 7);
    bullet1->SetPosition(&(this->position + Vec(&rotation, 7)));
    bullet1->SetDamage(this->GetDamage());
    bullet1->AddTag(HasTag(Tag::PLAYER_WEAPON) ? Tag::PLAYER_ATTACK : Tag::MONSTER_ATTACK);
    ObjectManager::Instance()->AddObject(bullet1);

    currentRotation.Rotate(-0.2);

    Bullet* bullet2 = new BadPistolBullet();
    bullet2->SetSpeed(currentRotation, 7);
    bullet2->SetPosition(&(this->position + Vec(&rotation, 7)));
    bullet2->SetDamage(this->GetDamage());
    bullet2->AddTag(HasTag(Tag::PLAYER_WEAPON) ? Tag::PLAYER_ATTACK : Tag::MONSTER_ATTACK);
    ObjectManager::Instance()->AddObject(bullet2);

    currentRotation.Rotate(-0.2);

    Bullet* bullet3 = new BadPistolBullet();
    bullet3->SetSpeed(currentRotation, 7);
    bullet3->SetPosition(&(this->position + Vec(&rotation, 7)));
    bullet3->SetDamage(this->GetDamage());
    bullet3->AddTag(HasTag(Tag::PLAYER_WEAPON) ? Tag::PLAYER_ATTACK : Tag::MONSTER_ATTACK);
    ObjectManager::Instance()->AddObject(bullet3);

    currentRotation.Rotate(-0.2);

    Bullet* bullet4 = new BadPistolBullet();
    bullet4->SetSpeed(currentRotation, 7);
    bullet4->SetPosition(&(this->position + Vec(&rotation, 7)));
    bullet4->SetDamage(this->GetDamage());
    bullet4->AddTag(HasTag(Tag::PLAYER_WEAPON) ? Tag::PLAYER_ATTACK : Tag::MONSTER_ATTACK);
    ObjectManager::Instance()->AddObject(bullet4);

    currentRotation.Rotate(-0.2);

    Bullet* bullet5 = new BadPistolBullet();
    bullet5->SetSpeed(currentRotation, 7);
    bullet5->SetPosition(&(this->position + Vec(&rotation, 7)));
    bullet5->SetDamage(this->GetDamage());
    bullet5->AddTag(HasTag(Tag::PLAYER_WEAPON) ? Tag::PLAYER_ATTACK : Tag::MONSTER_ATTACK);
    ObjectManager::Instance()->AddObject(bullet5);
}