#include "stdafx.h"
#include "Hoe.h"

#include "stdafx.h"
#include "Hammer.h"

#include "../../projectile/ShockWave.h"
#include "../../projectile/InvisibleShockWave.h"
#include "../../manager/ObjectManager.h"
#include "../../pool/ProjectilePool.h"

Hoe::Hoe(Point point) : MeleeWeapon(point) {
    damage = 5;
}

Hoe::Hoe(double damage) : MeleeWeapon(damage) {
}

Weapon* Hoe::Copy() {
    return new Hammer(this->position);
}

void Hoe::Start() {
    MeleeWeapon::Start();
    SetAttackAnimation({-0.7, -1.4, 1.4, 0.7, 0}, {}, 0.6, 0.65);
}

void Hoe::Update() {
    MeleeWeapon::Update();
}

void Hoe::LoadResources() {
    SetImages("Resources/weapon/hoe/", 3, RGB(255, 255, 255));
}

void Hoe::Attack() {
    InvisibleShockWave* shockWave = ProjectilePool::Instance()->AcquireInvisibleShockWave();
    shockWave->SetPosition(&(this->position + Vec(&rotation, 10)));
    shockWave->SetSpeed(rotation, 0);
    shockWave->SetSize(30);
    shockWave->SetDamage(damage);
    shockWave->SetAliveTime(0.1);
    UpdateTag(shockWave);
    ObjectManager::Instance()->AddObject(shockWave);
}
