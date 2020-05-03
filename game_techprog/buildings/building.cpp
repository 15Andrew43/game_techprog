//
// Created by Андрей Боровец on 11.04.2020.
//

#include "building.h"
#include "../main.h"


void AbstractBuilding::Boost(int& money) {
    if (money < getPrice()) {
        throw NotEnoughMoney();
    }
    if (getLevel() == getMaxLevel()) {
        throw MaxLevel();
    }
    ++getLevel();
    money -= getPrice();
}




int Casern::getLevel() const {
    return level_;
}
int& Casern::getLevel() {
    return level_;
}
int Casern::getPrice() const {
    return price_;
}
int& Casern::getPrice() {
    return price_;
}
int Casern::getMaxLevel() {
    return max_level;
}
Destination Casern::getDestination() const {
    return destination_;
}
Destination& Casern::getDestination() {
    return destination_;
}



int Miner::getLevel() const {
    return level_;
}
int& Miner::getLevel() {
    return level_;
}
int Miner::getPrice() const {
    return price_;
}
int& Miner::getPrice() {
    return price_;
}
int Miner::getMaxLevel() {
    return max_level;
}
Destination Miner::getDestination() const {
    return destination_;
}
Destination& Miner::getDestination() {
    return destination_;
}



int Tower::getLevel() const {
    return level_;
}
int& Tower::getLevel() {
    return level_;
}
int Tower::getPrice() const {
    return price_;
}
int& Tower::getPrice() {
    return price_;
}
int Tower::getMaxLevel() {
    return max_level;
}
Destination Tower::getDestination() const {
    return destination_;
}
Destination& Tower::getDestination() {
    return destination_;
}