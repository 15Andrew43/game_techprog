//
// Created by Андрей Боровец on 09.04.2020.
//
#include <iostream>
#include "unit.h"


void Swordsman::go() {
    //...   взаимодействие с юзером
}
int Swordsman::getPower() const {
    return power_;
}
 int& Swordsman::getHealthy()  {
    return healthy_;
}
int Swordsman::getHealthy() const {
    return healthy_;
}
bool Swordsman::isMine() const {
    return is_mine_;
}
int Swordsman::getRadius() const {
    return radius_;
}
Destination Swordsman::getDestination() const {
    return destination_;
}
Destination& Swordsman::getDestination() {
    return  destination_;
}
int Swordsman::getPrice() const {
    return price_;
}
int& Swordsman::getPrice() {
    return price_;
}
int Swordsman::getLevel() const {
    return level_;
}
int& Swordsman::getLevel() {
    return level_;
}
int Swordsman::getSpeed() const {
    return speed_;
}
int& Swordsman::getSpeed() {
    return speed_;
}




void Archer::go() {
    //...   взаимодействие с юзером
}
int Archer::getPower() const {
    return power_;
}
int& Archer::getHealthy()  {
    return healthy_;
}
int Archer::getHealthy() const {
    return healthy_;
}
bool Archer::isMine() const {
    return is_mine_;
}
int Archer::getRadius() const {
    return radius_;
}

Destination Archer::getDestination() const {
    return destination_;
}
Destination& Archer::getDestination() {
    return  destination_;
}

int Archer::getPrice() const {
    return price_;
}
int& Archer::getPrice() {
    return price_;
}

int Archer::getLevel() const {
    return level_;
}
int& Archer::getLevel() {
    return level_;
}
int Archer::getSpeed() const {
    return speed_;
}
int& Archer::getSpeed() {
    return speed_;
}




void Rider::go() {
    //...   взаимодействие с юзером
}
int Rider::getPower() const {
    return power_;
}
int& Rider::getHealthy()  {
    return healthy_;
}
int Rider::getHealthy() const {
    return healthy_;
}
bool Rider::isMine() const {
    return is_mine_;
}
int Rider::getRadius() const {
    return radius_;
}

Destination Rider::getDestination() const {
    return destination_;
}
Destination& Rider::getDestination() {
    return  destination_;
}

int Rider::getPrice() const {
    return price_;
}
int& Rider::getPrice() {
    return price_;
}

int Rider::getLevel() const {
    return level_;
}
int& Rider::getLevel() {
    return level_;
}
int Rider::getSpeed() const {
    return speed_;
}
int& Rider::getSpeed() {
    return speed_;
}





void Squad::setName(const std::string& name) {
    name_ = name;
}
std::string Squad::getName() const {
    return name_;
}

int Squad::getSwodsmanCnt() const {
    return SwordsmanCnt_;
}
int& Squad::getSwordsmanCnt() {
    return SwordsmanCnt_;
}
int Squad::getArcherCnt() const {
    return ArcherCnt_;
}
int& Squad::geArcherCnt() {
    return ArcherCnt_;
}
int Squad::getRiderCnt() const {
    return RiderCnt_;
}
int& Squad::getRiderCnt() {
    return RiderCnt_;
}

Squad::Squad(const std::string& name, int SwordsmanCnt, int ArcherCnt, int RiderCnt,
             bool contain_squad1, Squad* Squad1,
             bool contain_squad2, Squad* Squad2) {
    name_ = name;

    SwordsmanCnt_ = SwordsmanCnt;
    ArcherCnt_ = ArcherCnt;
    RiderCnt_ = RiderCnt;
//    contain_squads_ = contain_squads;

    squad1_ = Squad1;
    squad2_ = Squad2;

    contain_squad1_ = contain_squad1;
    contain_squad2_ = contain_squad2;

}
Squad& Squad::operator=(const Squad& other) {
    name_ = other.name_;

    destination_ = other.destination_;

    SwordsmanCnt_ = other.SwordsmanCnt_;
    ArcherCnt_ = other.ArcherCnt_;
    RiderCnt_ = other.RiderCnt_;
//    contain_squads_ = other.contain_squads_;

    Squad* squad1_ = other.squad1_;
    Squad* squad2_ = other.squad2_;

    contain_squad1_ = other.contain_squad1_;
    contain_squad2_ = other.contain_squad2_;

    return (*this);
}


int Squad::getAllSwordsmanCnt() const {
    int s1 = 0, s2 = 0;
//    std::cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
//    std::cout << name_;
//    std::cout << SwordsmanCnt_ << '\n';
//    std::cout << "contain squad1 " << contain_squad1_ << "\ncontain squad2 " <<  contain_squad2_ << '\n';
    if (contain_squad1_) {
//        std::cout << "5555555555555555555\n";
//        std::cout << "________________________squad1 name_ptr = " << squad1_ << '\n';
//        std::cout << "________________090909909090090909________squad1 name = " << squad1_->getName() << '\n';
//        std::cout << "        swdcmen = " << squad1_->SwordsmanCnt_ << '\n';

        s1 = (squad1_->getAllSwordsmanCnt());
//        std::cout << "    swordsmen = " << s1 << '\n';
    }
    if (contain_squad2_) {
//        std::cout << "________________________squad2 name = " << squad2_->getName();
        s2 = (squad2_->getAllSwordsmanCnt());
//        std::cout << "    swordsmen = " << s2 << '\n';
    }
    return SwordsmanCnt_ + s1 + s2;
}
int Squad::getAllArcherCnt() const {
    int s1 = 0, s2 = 0;
    if (squad1_) {
        s1 = squad1_->getAllArcherCnt();
    }
    if (squad2_) {
        s2 = squad2_->getAllArcherCnt();
    }
    return ArcherCnt_ + s1 + s2;
};
int Squad::getAllRiderCnt() const {
    int s1 = 0, s2 = 0;
    if (squad1_) {
        s1 = squad1_->getAllRiderCnt();
    }
    if (squad2_) {
        s2 = squad2_->getAllRiderCnt();
    }
    return RiderCnt_ + s1 + s2;
}

int Squad::getSpeed() const {
    int speed;
    if (getAllSwordsmanCnt() > 0) {
        speed = swordsman_.getSpeed();
    }
    if (getAllArcherCnt() > 0) {
        speed = std::min(speed, archer_.getSpeed());
    }
    if (getAllRiderCnt() > 0) {
        speed = std::min(speed, rider_.getSpeed());
    }
    return speed;
}