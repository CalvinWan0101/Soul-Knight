﻿#include "stdafx.h"
#include "transfer_gate.h"

#include "object_manager.h"
#include "stage_manager.h"

TransferGate::TransferGate() {
    AddTag(Tag::TRANSFER_GATE);
}

void TransferGate::Start() {
    AddAnimation({ "resources/object/transfergate.bmp" }, RGB(255, 255, 255), 0, false);
    SetHitBoxByRatio(0.7, 0.7);
    GameObject::Start();
}

void TransferGate::Update() {
    GameObject::Update();
}

void TransferGate::Collision(GameObject* gameObject) {
    if (gameObject->HasTag(Tag::PLAYER)) {
        StageManager::Instance()->NextStage();
    }
}