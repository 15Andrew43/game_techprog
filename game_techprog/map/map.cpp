//
// Created by Андрей Боровец on 09.04.2020.
//

#include "map.h"
#include <iomanip>

/*
void Cell::attack(const AbstractUnit& unit) {
    for (int i = 0; i < ((unit.isMine()) ? Rival_ : Mine_).size(); ++i) {
        ((unit.isMine()) ? Rival_ : Mine_)[i].getHealthy() -= unit.getPower();
    }
}
*/
//Cell& Cell::operator=(const Cell& other) {
//    destination_ = other.destination_;
//
//    MySworsmanCnt_ = other.MySworsmanCnt_;
//    MyArcherCnt_ = other.MyArcherCnt_;
//    MyRiderCnt_ = other.MyRiderCnt_;
//
//    Rival_ = other.Rival_;
//    MySquads_ = other.MySquads_;
//}
Destination Cell::getDestination() const {
    return destination_;
}
Destination& Cell::getDestination() {
    return destination_;
}
/*
std::vector<AbstractUnit>& Cell::getMineSwordsmen() {
    return MineSwordsmen_;
}
std::vector<AbstractUnit>&  Cell::getMineArcher() {
    return MineArchers_;
}
std::vector<AbstractUnit>& Cell::getMineRider() {
    return MineRider_;
}
*/
void Cell::CreateSwordman(Objects& objects) {
    Swordsman swordsman;
    swordsman.getDestination() = objects.casern_.getDestination();
    objects.getMoney() -= swordsman.getPrice();
//    MineSwordsmen_.push_back(swordsman);
    ++MySworsmanCnt_;
}

void Cell::CreateArcher(Objects& objects) {
    Archer archer;
    archer.getDestination() = objects.casern_.getDestination();
    objects.getMoney() -= archer.getPrice();
    ++MyArcherCnt_;
}

void Cell::CreateRider(Objects& objects) {
    Rider rider;
    rider.getDestination() = objects.casern_.getDestination();
    objects.getMoney() -= rider.getPrice();
    ++MyRiderCnt_;
}

void Cell::CreateCasern(Objects& objects) {
    Casern casern;
    ++objects.getCasernCnt();
    casern.getDestination() = getDestination();
    objects.casern_.getDestination() = getDestination();
    std::cout << casern.getDestination().x_ << ' ' << casern.getDestination().y_ << '\n';
    objects.getMoney() -= casern.getPrice();
}
void Cell::CreateMiner(Objects& objects) {
    Miner miner;
    ++objects.getMinerCnt();
    miner.getDestination() = getDestination();
    objects.getMoney() -= miner.getPrice();
}
void Cell::CreateTower(Objects& objects) {
    Tower tower;
    ++objects.getTowerCnt();
    tower.getDestination() = getDestination();
    objects.getMoney() -= tower.getPrice();
}
int Cell::getMySwordmanCnt() const {
    return MySworsmanCnt_;
}
int& Cell::getMySwordmanCnt() {
    return MySworsmanCnt_;
}
int Cell::getMyArcherCnt() const {
    return MyArcherCnt_;
}
int& Cell::getMyArcherCnt() {
    return MyArcherCnt_;
}
int Cell::getMyRiderCnt() const {
    return MyRiderCnt_;
}
int& Cell::getMyRiderCnt() {
    return MyRiderCnt_;
}
std::vector<Squad>& Cell::getMySquads() {
    return MySquads_;
}

int Cell::getUnitCnt() const {
    return MySworsmanCnt_ + MyArcherCnt_ + MyRiderCnt_;
}

/*
void Cell::FormSquad(const std::string& name, int SwordsmanCnt, int ArcherCnt, int RiderCnt,
        Squad* Squad1, int index_of_squad1,
        Squad* Squad2, int index_of_squad2) {
    Squad newSquad(name, SwordsmanCnt, ArcherCnt, RiderCnt, Squad1, Squad2);
    if (index_of_squad1 < index_of_squad2) {
        MySquads_.erase(MySquads_.begin() + index_of_squad1);
        MySquads_.erase(MySquads_.begin() + index_of_squad2 - 1);
    } else {
        MySquads_.erase(MySquads_.begin() + index_of_squad2);
        MySquads_.erase(MySquads_.begin() + index_of_squad1 - 1);
    }
    MySquads_.push_back(newSquad);
}
*/

Map::Map() {
    array = new Cell* [hight_];
    for (int i = 0; i < hight_; ++i) {
        array[i] = new Cell [width_];
        for (int j = 0; j < width_; ++j) {
            array[i][j].getDestination() = {i, j};
        }
    }
}

Map::~Map() {
    for (int i = 0; i < hight_; ++i) {
        delete[] array[i];
    }
    delete[] array;
}

Cell* Map::operator[] (int i) {
    return array[i];
}

int Map::getWidth() const {
    return width_;
}

int Map::getHight() const {
    return hight_;
}


bool formula(int x, int y) {
    if (x%4 == 0 || y%10 == 0) {
        return true;
    } else {
        return false;
    }
}
void Map::draw() {
    // в данный момент обычное прямоуголное поле, а хотелось бы шестиугольные клетки...
    // мб потом сделать графический итнтерфейс?

    // 8 * 15
    std::cout << "        ";
    for (int i = 0; i < 15; ++i) {
        std::cout << std::setfill(' ') << std::setw(6) << i << "    ";
    }
    std::cout << "\n";
    for (int i = 0; i < hight_draw+1; ++i) {
        //std::cout << "  " << std::setfill(' ') << std::setw(3) << i << "   ";
        if ((i + 2) % 4 == 0) {
            std::cout << "  " << std::setfill(' ') << std::setw(3) << i/4 << "   ";
        } else {
            std::cout << "        ";
        }
        for (int j = 0; j < width_draw+1; ++j) {
            if (formula(i, j))
                std::cout << "*";
            else
                std::cout << " ";
        }
        std::cout << '\n';
    }
}







void Objects::setName(std::string name) {
    name_ = name;
}
std::string Objects::getName() {
    return name_;
}

int Objects::getMoney() const {
    return money_;
}
int& Objects::getMoney() {
    return money_;
}
/*
int Objects::getCasernLevel() const {
    return casern_level_;
}
int& Objects::getCasernLevel() {
    return  casern_level_;
}

int Objects::getMinerLevel() const {
    return miner_level_;
}
int& Objects::getMinerLevel() {
    return miner_level_;
}

int Objects::getTowerLevel() const {
    return tower_level_;
}
int& Objects::getTowerLevel() {
    return tower_level_;
}
*/

int Objects::getCasernCnt() const {
    return  CasernCnt_;
}
int& Objects::getCasernCnt() {
    return  CasernCnt_;
}

int Objects::getMinerCnt() const {
    return MinerCnt_;
}
int& Objects::getMinerCnt() {
    return MinerCnt_;
}

int Objects::getTowerCnt() const {
    return TowerCnt_;
}
int& Objects::getTowerCnt() {
    return  TowerCnt_;
}



int Objects::getSwordsmanCnt() const {
    return SwordsmanCnt_;
}
int& Objects::getSwordsmanCnt() {
    return SwordsmanCnt_;
}

int Objects::getArcherCnt() const {
    return ArcherCnt_;
}
int& Objects::getArcherCnt() {
    return ArcherCnt_;
}

int Objects::getRiderCnt() const {
    return RiderCnt_;
}
int& Objects::getRiderCnt() {
    return RiderCnt_;
}


void Objects::getObjects() const {
    std::cout << "\n\n ---------------------------------------------------\n";
    std::cout << "|   ***   You have " << getMoney() << " dollars\n"
              << "|   ***      Level of the casern = " << casern_.getLevel() << "\n"
              << "|   ***      Level of the miner = " << miner_.getLevel() << "\n"
              << "|   ***      Level of the tower = " << tower_.getLevel() << "\n";
    if (casern_.getLevel() >= 1) {
        std::cout << "|   ***         Level of the Swordsman = " << swordsman_.getLevel() << "\n"
                  << "|   ***         Number of Swordsmen = " << getSwordsmanCnt() << "\n";
    }
    if (casern_.getLevel() >= 2) {
        std::cout << "|   ***         Level of the Archer = " << archer_.getLevel() << "\n"
                  << "|   ***         Number of Archers = " << getArcherCnt() << "\n";
    }
    if (casern_.getLevel() >= 3) {
        std::cout << "|   ***         Level of the Rider = " << rider_.getLevel() << "\n"
                  << "|   ***         Number of Rider = " << getRiderCnt() << "\n";
    }
    std::cout << " ----------------------------------------------------\n";
}