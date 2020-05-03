//
// Created by Андрей Боровец on 09.04.2020.
//

#ifndef GAME_TECHPROG_UNIT_H
#define GAME_TECHPROG_UNIT_H

#include <vector>
#include "../map/destination.h"

#include "string"

class AbstractUnit {
public:
    virtual void go() = 0;
    virtual int getPower() const = 0;
    virtual int& getHealthy() = 0;
    virtual int getHealthy() const = 0;
    virtual bool isMine() const = 0;
    virtual int getRadius() const  = 0;
    virtual Destination getDestination() const = 0;
    virtual Destination& getDestination() = 0;
    virtual int getPrice() const = 0;
    virtual int& getPrice() = 0;
    virtual int getLevel() const = 0;
    virtual int& getLevel() = 0;
    virtual int getSpeed() const = 0;
    virtual int& getSpeed() = 0;
};

class Swordsman : public AbstractUnit {
    bool is_mine_;
    int radius_ = 0;
    int healthy_ = 100;
    Destination destination_ = {-1, -1};
    int power_ = 20;
    int price_ = 100;
    int level_ = 1;
    int speed_ = 2;
public:
    virtual void go() override;
    virtual int getPower() const override;
    virtual int& getHealthy() override;
    virtual int getHealthy() const override;
    virtual bool isMine() const override;
    virtual int getRadius() const override;
    virtual Destination getDestination() const override;
    virtual Destination& getDestination() override;
    virtual int getPrice() const override;
    virtual int& getPrice() override;
    virtual int getLevel() const override ;
    virtual int& getLevel() override;
    virtual int getSpeed() const;
    virtual int& getSpeed();
};



class Archer : public AbstractUnit {
    bool is_mine_;
    int radius_ = 3;
    int healthy_ = 100;
    Destination destination_ = {-1, -1};
    int power_ = 20;
    int price_ = 150;
    int level_ = 1;
    int speed_ = 3;
public:
    virtual void go() override;
    virtual int getPower() const override;
    virtual int& getHealthy() override;
    virtual int getHealthy() const override;
    virtual bool isMine() const override;
    virtual int getRadius() const override;
    virtual Destination getDestination() const override;
    virtual Destination& getDestination() override;
    virtual int getPrice() const override;
    virtual int& getPrice() override;
    virtual int getLevel() const override;
    virtual int& getLevel() override;
    virtual int getSpeed() const;
    virtual int& getSpeed();
};



class Rider : public AbstractUnit {
    bool is_mine_;
    int radius_ = 0;
    int healthy_ = 100;
    Destination destination_ = {-1, -1};
    int power_ = 20;
    int price_ = 150;
    int level_ = 1;
    int speed_ = 4;
public:
    virtual void go() override;
    virtual int getPower() const override;
    virtual int& getHealthy() override;
    virtual int getHealthy() const override;
    virtual bool isMine() const override;
    virtual int getRadius() const override;
    virtual Destination getDestination() const override;
    virtual Destination& getDestination() override;
    virtual int getPrice() const override;
    virtual int& getPrice() override;
    virtual int getLevel() const override;
    virtual int& getLevel() override;
    virtual int getSpeed() const;
    virtual int& getSpeed();
};

class Squad {
    std::string name_ = "karaoke";

    Destination destination_;

    Swordsman swordsman_;
    int SwordsmanCnt_ = 0; // не считая юнитов которые в под-отрядах
    Archer archer_;
    int ArcherCnt_ = 0;
    Rider rider_;
    int RiderCnt_ = 0;

    bool contain_squad1_ = false;
    Squad* squad1_ = nullptr;
    bool contain_squad2_ = false;
    Squad* squad2_ = nullptr;

public:

    void setName(const std::string& name);
    std::string getName() const;

    int getSwodsmanCnt() const;
    int& getSwordsmanCnt();
    int getArcherCnt() const;
    int& geArcherCnt();
    int getRiderCnt() const;
    int& getRiderCnt();

    Squad() = default;

    Squad(const std::string& name, int SwordsmanCnt, int ArcherCnt, int RiderCnt,
          bool contain_squad1 = false ,Squad* Squad1 = nullptr,
          bool contain_squad2 = false ,Squad* Squad2 = nullptr);
    Squad& operator=(const Squad& other);
//    operator bool() const;

    int getAllSwordsmanCnt() const;
    int getAllArcherCnt() const;
    int getAllRiderCnt() const;

    int getSpeed() const;
};

#endif //GAME_TECHPROG_UNIT_H