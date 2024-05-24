﻿#include "stdafx.h"
#include "Stage_3_1.h"
#include "../../../manager/ObjectManager.h"
#include "../../../manager/StageManager.h"
#include "../../RoomSize.h"

Stage_3_1::Stage_3_1() {
    background.LoadBitmapByString({"resources/map/3-1.bmp"}, RGB(255, 255, 255));
    centerOffset = Vec(static_cast<double>(background.GetWidth()) / 2, static_cast<double>(background.GetHeight()) / 2);

    Room* room1 = new Room(Point(576, 0), centerOffset, RoomSize::MEDIUM_SIZE, 4,
                           std::map<MonsterType, int>{{MonsterType::GOBLIN_GIANT, 1}});
    Room* room2 = new Room(Point(0, 672), centerOffset, RoomSize::SMALL_SIZE, 4,
                           std::map<MonsterType, int>{{MonsterType::GOBLIN_GIANT, 1}});
    Room* room3 = new Room(Point(528, 592), centerOffset, RoomSize::LARGE_SIZE, 4,
                           std::map<MonsterType, int>{{MonsterType::GOBLIN_GIANT, 1}});
    Room* room4 = new Room(Point(1216, 640), centerOffset, RoomSize::MEDIUM_SIZE, 4,
                           std::map<MonsterType, int>{{MonsterType::GOBLIN_GIANT, 1}});
    Room* room5 = new Room(Point(1808, 592), centerOffset, RoomSize::LARGE_SIZE, 4,
                           std::map<MonsterType, int>{{MonsterType::GOBLIN_GIANT, 1}});

    rooms.push_back(room1);
    rooms.push_back(room2);
    rooms.push_back(room3);
    rooms.push_back(room4);
    rooms.push_back(room5);
}

void Stage_3_1::GenerateWall() {
    AddWall(Point(575, 1), Point(847, 15));
    AddWall(Point(575, 1), Point(591, 272));
    AddWall(Point(831, 1), Point(847, 272));
    AddWall(Point(527, 256), Point(672, 606));
    AddWall(Point(751, 257), Point(896, 607));
    AddWall(Point(192, 592), Point(545, 735));
    AddWall(Point(192, 815), Point(544, 960));
    AddWall(Point(1, 672), Point(208, 686));
    AddWall(Point(1, 671), Point(15, 880));
    AddWall(Point(1, 864), Point(208, 880));
    AddWall(Point(880, 592), Point(1231, 736));
    AddWall(Point(880, 816), Point(1232, 960));
    AddWall(Point(1215, 639), Point(1487, 654));
    AddWall(Point(1472, 591), Point(1824, 735));
    AddWall(Point(1472, 816), Point(1824, 961));
    AddWall(Point(1808, 592), Point(2176, 608));
    AddWall(Point(1808, 944), Point(2176, 960));
    AddWall(Point(2161, 592), Point(2176, 960));
    AddWall(Point(528, 944), Point(672, 1295));
    AddWall(Point(752, 944), Point(896, 1296));
    AddWall(Point(576, 1280), Point(592, 1551));
    AddWall(Point(832, 1281), Point(848, 1552));
    AddWall(Point(577, 1536), Point(848, 1552));
    AddWall(Point(1216, 896), Point(1311, 1248));
    AddWall(Point(1392, 898), Point(1488, 1248));
    AddWall(Point(1248, 1233), Point(1263, 1440));
    AddWall(Point(1248, 1424), Point(1456, 1441));
    AddWall(Point(1439, 1233), Point(1456, 1440));
}

void Stage_3_1::SetPlayerPosition() {
    ObjectManager::Instance()->SetPlayerPosition(Point(711, 1415) - centerOffset);
}

void Stage_3_1::SetTransferGate() {
    StageManager::Instance()->SetTransferGatePosition(Point(1351, 1335) - centerOffset);
}

void Stage_3_1::GenerateObstacle() {
}