//
// Created by Андрей Боровец on 09.04.2020.
//

#ifndef GAME_TECHPROG_MAP_H
#define GAME_TECHPROG_MAP_H

#include <iostream>
#include <vector>
#include <building.h>
#include "../unit/unit.h"
#include "destination.h"
#include "../buildings/building.h"

class Objects {
    std::string name_;
    int money_ = 1500;

    int CasernCnt_ = 0;
    int MinerCnt_ = 0;
    int TowerCnt_ = 0;

    int SwordsmanCnt_ = 0;
    int ArcherCnt_ = 0;
    int RiderCnt_ = 0;

    std::vector<Squad> Squads_;
public:
    Casern casern_;
    Miner miner_;
    Tower tower_;

    Swordsman swordsman_;
    Archer archer_;
    Rider rider_;

    void getObjects() const;
    void setName(std::string name);
    std::string getName();

    int getMoney() const;
    int& getMoney();


    int getCasernCnt() const;
    int& getCasernCnt();

    int getMinerCnt() const;
    int& getMinerCnt();

    int getTowerCnt() const;
    int& getTowerCnt();


    int getSwordsmanCnt() const;
    int& getSwordsmanCnt();

    int getArcherCnt() const;
    int& getArcherCnt();

    int getRiderCnt() const;
    int& getRiderCnt();
};

class Cell {
    Destination destination_ = {-1, -1};
 //   std::vector<AbstractUnit> MineSwordsmen_;
 //   std::vector<AbstractUnit> MineArchers_;
 //   std::vector<AbstractUnit> MineRider_;
    int MySworsmanCnt_ = 0;
    int MyArcherCnt_ = 0;
    int MyRiderCnt_ = 0;


    std::vector<AbstractUnit> Rival_;

    std::vector<Squad> MySquads_;
 //   std::vector<Squad> RivelSquads_;
public:
    Cell() = default;
//    Cell& operator=(const Cell& other);

    void attack(const AbstractUnit& unit);

    Destination getDestination() const;
    Destination& getDestination();
/*
    std::vector<AbstractUnit>& getMineSwordsmen();
    std::vector<AbstractUnit>& getMineArcher();
    std::vector<AbstractUnit>& getMineRider();
*/
    int getMySwordmanCnt() const;
    int& getMySwordmanCnt();
    int getMyArcherCnt() const;
    int& getMyArcherCnt();
    int getMyRiderCnt() const;
    int& getMyRiderCnt();
    int getUnitCnt() const;

    void CreateSwordman(Objects& objects);
    void CreateArcher(Objects& objects);
    void CreateRider(Objects& objects);

    void CreateCasern(Objects& objects);
    void CreateMiner(Objects& objects);
    void CreateTower(Objects& objects);

    std::vector<Squad>& getMySquads();
 //   void FormSquad(const std::string& name, int SwordsmanCnt, int ArcherCnt, int RiderCnt,
   //         Squad* Squad1 = nullptr, int index_of_squad = 0,
     //       Squad* Squad2 = nullptr, int index_of_squad2 = 0);
};

class Map {
    Cell** array;
    const int width_draw = 150;
    const int hight_draw = 32;
    const int width_ = 15;
    const int hight_ = 8;
public:
    Objects my_objects_;
    Objects rivel_objects_;
    Map();
    ~Map();

    Cell* operator[] (int i); //     чтобы можно было писать - map[i][j]
    void draw();

    int getWidth() const;
    int getHight() const;
};

void boost_casern(Objects& my_objects_);

#endif //GAME_TECHPROG_MAP_H
