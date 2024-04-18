#include "stdafx.h"
#include "../Core/Resource.h"
#include <mmsystem.h>
#include <ddraw.h>
#include <ostream>
#include <iostream>

#include "config.h"
#include "../Library/audio.h"
#include "../Library/gameutil.h"
#include "../Library/gamecore.h"
#include "mygame.h"
#include "utils/draw.h"
#include "utils/transfer_gate.h"
#include "wall\wall.h"

using namespace game_framework;

/////////////////////////////////////////////////////////////////////////////
// �o��class���C�����C�����檫��A�D�n���C���{�����b�o��
/////////////////////////////////////////////////////////////////////////////

CGameStateRun::CGameStateRun(CGame* g) : CGameState(g) {
}

CGameStateRun::~CGameStateRun() {
    delete objectManager;
    delete stageManager;
    delete Draw::Instance();
}

void CGameStateRun::OnBeginState() {
}

void CGameStateRun::OnMove() // ���ʹC������
{
    stageManager->Update();
    objectManager->Update();
}

void CGameStateRun::OnInit() // �C������Ȥιϧγ]�w
{
    objectManager->SetPlayer(new Knight());
    objectManager->Start();
    stageManager->Initiliaze();
    CAudio::Instance()->Load(1, "Resources/sound/bullet.mp3");
}

void CGameStateRun::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) {
    // TODO: Fixed the bug of pressing more than one key
    objectManager->KeyDown(nChar);
}

void CGameStateRun::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags) {
    objectManager->KeyUp(nChar);
}

void CGameStateRun::OnLButtonDown(UINT nFlags, CPoint point) // �B�z�ƹ����ʧ@
{
    objectManager->SetLButtonPress(true);
}

void CGameStateRun::OnLButtonUp(UINT nFlags, CPoint point) // �B�z�ƹ����ʧ@
{
    objectManager->SetLButtonPress(false);
}

void CGameStateRun::OnMouseMove(UINT nFlags, CPoint point) // �B�z�ƹ����ʧ@
{
    objectManager->SetPlayerVision(Point(point.x, point.y) - Point(SIZE_X / 2, SIZE_Y / 2));
}

void CGameStateRun::OnRButtonDown(UINT nFlags, CPoint point) // �B�z�ƹ����ʧ@
{
}

void CGameStateRun::OnRButtonUp(UINT nFlags, CPoint point) // �B�z�ƹ����ʧ@
{
}

void CGameStateRun::OnShow() {
    objectManager->Show();
}
