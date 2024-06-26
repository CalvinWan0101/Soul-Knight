﻿#include "stdafx.h"
#include "DevilsSnareSkill.h"

#include <iostream>

#include "../../../Player.h"
#include "../../../../projectile/bullet/RedCircleBullet.h"
#include "../../../../projectile/bullet/RedConicalBullet.h"
#include "../../../../projectile/bullet/RedHollowCircleBullet.h"
#include "../../../../projectile/bullet/RedRectangleBullet.h"
#include "../../../../projectile/effect/PoisonEffect.h"

DevilsSnareSkill::DevilsSnareSkill(Point* position, int bulletCoolDown, int bulletNumber) : position(position),
    bulletCoolDown(bulletCoolDown), bulletNumber(bulletNumber), bulletCoolDownCounter(bulletCoolDown),
    bulletNumberCounter(0) {
}

void DevilsSnareSkill::Update() {
    if (bulletNumberCounter == 0) {
        return;
    }
    bulletCoolDownCounter--;
    if (bulletCoolDownCounter == 0) {
        GenerageBullet();
        bulletCoolDownCounter = bulletCoolDown;
        bulletNumberCounter--;
    }
}

void DevilsSnareSkill::Activate() {
    bulletNumberCounter = bulletNumber;
}

// ---------- skill 0 ----------

DevilsSnareSkill0::DevilsSnareSkill0(Point* position) : DevilsSnareSkill(position, 50, 1) {
}

void DevilsSnareSkill0::GenerageBullet() {
    PoisonEffect* poisonEffect = new PoisonEffect(PoisonEffect::MONSTER_GREEN);
    poisonEffect->SetPosition(this->position);
    ObjectManager::Instance()->AddObject(poisonEffect);
}


// ---------- skill 1 ----------

DevilsSnareSkill1::DevilsSnareSkill1(Point* position) : DevilsSnareSkill(position, 5, 1) {
}

void DevilsSnareSkill1::GenerageBullet() {
    Vec rotation{1.0, 1.0};
    for (int i = 0; i < 18; ++i) {
        Bullet* bullet = static_cast<RedRectangleBullet*>(projectilePool->
            Acquire(ProjectileType::RED_RECTANGLE_BULLET));
        bullet->SetSpeed(rotation, 5);
        bullet->SetPosition(&(*(this->position) + Vec(&rotation, 7)));
        bullet->SetDamage(3);
        bullet->AddTag(Tag::MONSTER_ATTACK);
        bullet->RemoveTag(Tag::PLAYER_ATTACK);
        bullet->SetPoison(true);
        objectManager->AddObject(bullet);
        rotation.Rotate(-0.35);
    }
}

// ---------- skill 2 ----------

DevilsSnareSkill2::DevilsSnareSkill2(Point* position) : DevilsSnareSkill(position, 5, 20) {
}

void DevilsSnareSkill2::Update() {
    if (bulletNumberCounter == 0) {
        return;
    }
    bulletCoolDownCounter--;
    if (bulletCoolDownCounter == 0) {
        rotation.Rotate(0.1);
        GenerageBullet();
        bulletCoolDownCounter = bulletCoolDown;
        bulletNumberCounter--;
    }
}

void DevilsSnareSkill2::GenerageBullet() {
    Vec rotationTemp = this->rotation;
    for (int i = 0; i < 4; ++i) {
        Bullet* bullet = static_cast<RedCircleBullet*>(projectilePool->
            Acquire(ProjectileType::RED_CIRCLE_BULLET));
        bullet->SetSpeed(rotationTemp, 5);
        bullet->SetPosition(&(*(this->position) + Vec(&rotationTemp, 7)));
        bullet->SetDamage(3);
        bullet->AddTag(Tag::MONSTER_ATTACK);
        bullet->RemoveTag(Tag::PLAYER_ATTACK);
        objectManager->AddObject(bullet);
        rotationTemp.Rotate(-1.57);
    }
}

// ---------- skill 3 ----------

DevilsSnareSkill3::DevilsSnareSkill3(Point* position) : DevilsSnareSkill(position, 10, 1) {
}

void DevilsSnareSkill3::GenerageBullet() {
    Vec rotation{1.0, 1.0};
    for (int i = 0; i < 18; ++i) {
        Bullet* bullet = static_cast<RedHollowCircleBullet*>(projectilePool->
            Acquire(ProjectileType::RED_HOLLOW_CIRCLE_BULLET));
        bullet->SetSpeed(rotation, 5);
        bullet->SetPosition(&(*(this->position) + Vec(&rotation, 7)));
        bullet->SetDamage(3);
        bullet->AddTag(Tag::MONSTER_ATTACK);
        bullet->RemoveTag(Tag::PLAYER_ATTACK);
        bullet->SetPoison(true);
        objectManager->AddObject(bullet);
        rotation.Rotate(-0.35);
    }
}

// ---------- skill 4 ----------

DevilsSnareSkill4::DevilsSnareSkill4(Point* position) : DevilsSnareSkill(position, 5, 1) {
}

void DevilsSnareSkill4::GenerageBullet() {
    Vec rotationTemp{1.0, 1.0};
    for (int i = 0; i < 4; ++i) {
        Bullet* bullet = static_cast<RedConicalBullet*>(projectilePool->
            Acquire(ProjectileType::RED_CONICAL_BULLET));
        bullet->SetSpeed(rotationTemp, 2);
        bullet->SetPosition(&(*(this->position) + Vec(&rotationTemp, 7)));
        bullet->SetDamage(4);
        bullet->AddTag(Tag::MONSTER_ATTACK);
        bullet->RemoveTag(Tag::PLAYER_ATTACK);
        objectManager->AddObject(bullet);
        rotationTemp.Rotate(-1.57);
    }
}
