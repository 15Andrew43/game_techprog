//
// Created by Андрей Боровец on 11.04.2020.
//

#ifndef GAME_TECHPROG_ABSTRACTBUILDING_H
#define GAME_TECHPROG_ABSTRACTBUILDING_H

#include "../map/destination.h"

class AbstractBuilding {
public:
    virtual int getLevel() const = 0;
    virtual int& getLevel() = 0;
    virtual int getPrice() const = 0;
    virtual int& getPrice() = 0;
    virtual int getMaxLevel() = 0;
    virtual void Boost(int& money);
    virtual Destination getDestination() const = 0;
    virtual Destination& getDestination() = 0;
};

class Casern : public AbstractBuilding{
    Destination destination_ = {0, 0};
    int level_ = 0;
    const int max_level = 3;
    int price_ = 100;
public:
    virtual int getLevel() const override;
    virtual int& getLevel() override;
    virtual int getPrice() const override;
    virtual int& getPrice() override;
    virtual int getMaxLevel() override;
    virtual Destination getDestination() const override;
    virtual Destination& getDestination() override;

};


class Miner : public AbstractBuilding{
    Destination destination_ = {0, 0};
    int level_ = 0;
    const int max_level = 3;
    int price_ = 200;
public:
    virtual int getLevel() const override;
    virtual int& getLevel() override;
    virtual int getPrice() const override;
    virtual int& getPrice() override;
    virtual int getMaxLevel() override;
    virtual Destination getDestination() const override;
    virtual Destination& getDestination() override;
};


class Tower : public AbstractBuilding{
    Destination destination_ = {0, 0};
    int level_ = 0;
    const int max_level = 3;
    int price_ = 500;
public:
    virtual int getLevel() const override;
    virtual int& getLevel() override;
    virtual int getPrice() const override;
    virtual int& getPrice() override;
    virtual int getMaxLevel() override;
    virtual Destination getDestination() const override;
    virtual Destination& getDestination() override;
};
#endif //GAME_TECHPROG_ABSTRACTBUILDING_H
