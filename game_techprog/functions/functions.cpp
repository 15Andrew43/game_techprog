//
// Created by Андрей Боровец on 11.04.2020.
//

#include <iostream>
#include <cstring>
#include "functions.h"
#include "../map/map.h"
#include "../exceptions/exceptions.h"
#include "../buildings/building.h"
#include <iomanip>

bool GameOver(Map& map) {
    return false;
}

void SetUp(Map& map) {
    std::cout << "Change your name of the city:";
    std::string MyName;
    std::cin >> MyName;
    map.my_objects_.setName(MyName);
    map.draw();
}

void MyActions(Map& map);
void BuildingsActions(Map& map);
void MyStep(Map& map) {
    BuildingsActions(map);
    MyActions(map); // go / boost / make units

    map.draw();
    try {
        GameOver(map);
    } catch (Exception& ex) {
        throw;
    }
}
void RivalStep(Map& map) {
    std::cout << "тут будет искусственный интеллект 100500\n";


    map.draw();
    try {
        GameOver(map);
    } catch (Exception& ex) {
        throw;
    }
}

void Go(Map& map, bool& has_gone);
void WorkWithBuildings(Map& map);
void WorkWithUnits(Map& map);
void FormSquads(Map& map);
// go / boost / make units
void MyActions(Map& map) {
    std::string answer = "-1";
    bool has_gone = false;
    while (answer != "0") {
        map.my_objects_.getObjects();
        std::cout << "You want to\n"
                  << "0. end step\n"
                  << "1. go\n"
                  << "2. boost(create) smth\n"
                  << "3. make units\n"
                  << "4. form squads!\n";
        std::cin >> answer;
        try {
            if (answer == "1") {
                std::cout << "bruh\n";
                Go(map, has_gone);
            } else if (answer == "2") {
                WorkWithBuildings(map);
            } else if (answer == "3") {
                WorkWithUnits(map);
            } else if (answer == "4") {
                FormSquads(map);
                int t;
            }
        } catch (Exception& ex) {
            std::cout << ex.what();
        }
    }
}

void Go(Map& map, bool& has_gone) {
    if (has_gone) {
        throw HasAlreadyGone();
    }
    std::cout << "which squad do you want to go?\n";
    for (int i = 0; i < map.getHight(); ++i) {
        for (int j = 0; j < map.getWidth(); ++j) {
            if (map[i][j].getMySquads().size() > 0) { //      обязательно чекнуть, когда будет функция go
                std::cout << "( " << i << ", " << j << " )  |  ";
            }
        }
    }
    int x, y;
    std::cin >> x >> y;
    for (int i = 0; i < map[x][y].getMySquads().size(); ++i) {
        std::cout << std::setw(20) << map[x][y].getMySquads()[i].getName() << " :    ";
        std::cout << "sworsmaen - " << map[x][y].getMySquads()[i].getAllSwordsmanCnt() << '\n'
                  << "                          archers - " << map[x][y].getMySquads()[i].getAllSwordsmanCnt() << '\n' //   CHANGE HERE
                  << "                          riders - " << map[x][y].getMySquads()[i].getAllSwordsmanCnt() << '\n';//            CHANGE HERE
    }
    std::string name = map[x][y].getMySquads()[0].getName();
    if (map[x][y].getMySquads().size() > 1) {
        std::cout << "which squad do you want to go? Input name\n";
        std::cin >> name;
    }
    int ind_squad;
    for (int i = 0; i < map[x][y].getMySquads().size(); ++i) {
        if (name == map[x][y].getMySquads()[i].getName()) {
            ind_squad = i;
            break;
        }
    }
    Squad squad = map[x][y].getMySquads()[ind_squad];
    map[x][y].getMySquads().erase(map[x][y].getMySquads().begin() + ind_squad);

    while (true) {
        std::cout << "where do you want to go? Input x, y\n";
        int x_new, y_new;
        std::cin >> x_new >> y_new;
        int step = squad.getSpeed();
        try {
            if (abs(x_new - x) + abs(y_new - y) > step) {
                throw LongDistance();
            }
            map[x_new][y_new].getMySquads().push_back(squad);
            break;
        } catch (Exception& ex) {
            std::cout << ex.what();
            std::cout << "try again!\n";
        }
    }
    has_gone = true;
}
void WorkWithBuildings(Map& map) {
    std::string answer1 = "-1";
    while (answer1 != "0") {
        map.my_objects_.getObjects();
        std::cout << "you want\n"
                  << "0. exit\n"
                  << "1. create(boost) Casern\n"
                  << "2. create(boost) Miner\n"
                  << "3. create(boost) Tower\n";
        std::cin >> answer1;
        try {
            if (answer1 == "0") {
                break;
            }
            if (answer1 == "1") {
                if (map.my_objects_.getCasernCnt() > 0) {
                    map.my_objects_.casern_.Boost(map.my_objects_.getMoney());
                } else {
                    std::cout << "Where do you want to build the Casern? Input (x, y)\n";
                    int x, y;
                    std::cin >> x >> y;
                    map[x][y].CreateCasern(map.my_objects_);
                }
            } else if (answer1 == "2") {
                if (map.my_objects_.getMinerCnt() > 0) {
                    map.my_objects_.miner_.Boost(map.my_objects_.getMoney());
                } else {
                    std::cout << "Where do you want to build the Miner? Input (x, y)\n";
                    int x, y;
                    std::cin >> x >> y;
                    map[x][y].CreateMiner(map.my_objects_);
                }
            } else if (answer1 == "3") {
                if (map.my_objects_.getTowerCnt() > 0) {
                    map.my_objects_.tower_.Boost(map.my_objects_.getMoney());
                } else {
                    std::cout << "Where do you want to build the Tower? Input (x, y)\n";
                    int x, y;
                    std::cin >> x >> y;
                    map[x][y].CreateTower(map.my_objects_);
                }
            } else {
                throw InvalidArgument();
            }
        } catch (Exception &ex) {
            std::cout << ex.what();
        }
    }
}
void WorkWithUnits(Map& map) {
    std::string answer1 = "-1";
    while (answer1 != "0") {
        map.my_objects_.getObjects();
        std::cout << "you want to get\n";
        if (map.my_objects_.casern_.getLevel() == 1) {
            std::cout << "0. exit\n"
                      << "1. Swordsman\n";
        } else if (map.my_objects_.casern_.getLevel() == 2) {
            std::cout << "0. exit\n"
                      << "1. Swordsman\n"
                      << "2. Archer\n";
        } else if (map.my_objects_.casern_.getLevel() == 3) {
            std::cout << "0. exit\n"
                      << "1. Swordsman\n"
                      << "2. Archer\n"
                      << "3. Rider\n";
        } else if (map.my_objects_.casern_.getLevel() == 0) {
            throw LowLevel();
        } else {
            throw InvalidArgument();
        }
        std::cin >> answer1;
        try {
            if (answer1 == "0") {
                break;
            } else if (answer1 == "1") {
                if (map.my_objects_.casern_.getLevel() < 1) {
                    throw LowLevel();
                }
                if (map.my_objects_.getMoney() < map.my_objects_.swordsman_.getPrice()) {
                    throw NotEnoughMoney();
                }
                map[map.my_objects_.casern_.getDestination().x_]
                   [map.my_objects_.casern_.getDestination().y_].CreateSwordman(map.my_objects_);
                ++map.my_objects_.getSwordsmanCnt();
            } else if (answer1 == "2") {
                if (map.my_objects_.casern_.getLevel() < 2) {
                    throw LowLevel();
                }
                if (map.my_objects_.getMoney() < map.my_objects_.archer_.getPrice()) {
                    throw NotEnoughMoney();
                }
                map[map.my_objects_.casern_.getDestination().x_]
                   [map.my_objects_.casern_.getDestination().y_].CreateArcher(map.my_objects_);
                ++map.my_objects_.getArcherCnt();
            } else if (answer1 == "3") {
                if (map.my_objects_.casern_.getLevel() < 3) {
                    throw LowLevel();
                }
                if (map.my_objects_.getMoney() < map.my_objects_.rider_.getPrice()) {
                    throw NotEnoughMoney();
                }
                map[map.my_objects_.casern_.getDestination().x_]
                   [map.my_objects_.casern_.getDestination().y_].CreateRider(map.my_objects_);
                ++map.my_objects_.getRiderCnt();
            } else {
                throw InvalidArgument();
            }
        } catch (Exception& ex) {
            std::cout << ex.what();
        }
    }
}

void BuildingsActions(Map& map) {
    int t;
}

void SquadCreating(Cell& cell);
void FormSquads(Map& map) {
    std::string answer = "-1";
    while (answer != "0") {
        std::cout  << "0. exit\n"
                   << "1. form squads\n";
        std::cin >> answer;
        if (answer == "1") {
            try {
                std::cout << "you can form new squad here:\n";
                for (int i = 0; i < map.getHight(); ++i) {
                    for (int j = 0; j < map.getWidth(); ++j) {
                        if (map[i][j].getMySquads().size() >= 2) { //      обязательно чекнуть, когда будет функция go
                            std::cout << "( " << i << ", " << j << " )  |  ";
                        }
                    }
                }

                if ( map[map.my_objects_.casern_.getDestination().x_]
                        [map.my_objects_.casern_.getDestination().y_].getUnitCnt() > 0) {
                    std::cout << "( " << map.my_objects_.casern_.getDestination().x_ << ", "
                              << map.my_objects_.casern_.getDestination().y_ << " )  |  \n";
                }


                std::cout << "input where do you want to form squad:\n";
                int x, y;
                std::cin >> x >> y;
                if (map[x][y].getMySquads().size() <= 1
                && (x != map.my_objects_.casern_.getDestination().x_
                    || y != map.my_objects_.casern_.getDestination().y_)) {
                    throw NotEnougSquads();
                } else {
                    SquadCreating(map[x][y]);
                }
            } catch (Exception& ex) {
                std::cout << ex.what();
            }




        }
    }
}

void SquadCreating(Cell& cell) {
    if ((cell.getMySquads().size() < 2 && cell.getUnitCnt() == 0)) {
        throw NotEnoughUnits();
    }
    if (cell.getMySquads().size() > 0) {
        std::cout << "you have squads:\n";
        for (int i = 0; i < cell.getMySquads().size(); ++i) {
            std::cout << cell.getMySquads()[i].getName() << "  |  ";
        }
    }

    std::cout << "\nyou have  " << cell.getMySwordmanCnt() << "  Swordsmen\n"
              << "you have  " << cell.getMyArcherCnt() << "  Archers\n"
              << "you have  " << cell.getMyRiderCnt() << "  Riders\n";

    int SworsmanCnt = 0;
    if (cell.getMySwordmanCnt() > 0) {
        std::cout << "how many Swordsmen do you want to include in Squad";
        std::cin >> SworsmanCnt;
        if (SworsmanCnt > cell.getMySwordmanCnt()) {
            throw NotEnoughUnits();
        }
        cell.getMySwordmanCnt() -= SworsmanCnt;
    }

    int ArcherCnt = 0;
    if (cell.getMyArcherCnt() > 0) {
        std::cout << "how many Archers do you want to include in Squad";
        std::cin >> ArcherCnt;
        if (ArcherCnt > cell.getMyArcherCnt()) {
            throw NotEnoughUnits();
        }
        cell.getMyArcherCnt() -= ArcherCnt;
    }

    int RiderCnt = 0;
    if (cell.getMyRiderCnt() > 0) {
        std::cout << "how many Riders do you want to include in Squad";
        std::cin >> RiderCnt;
        if (RiderCnt > cell.getMyRiderCnt()) {
            throw NotEnoughUnits();
        }
        cell.getMyRiderCnt() -= RiderCnt;
    }

    bool contain_squad1 = false;
    bool contain_squad2 = false;

    Squad* squad1_ptr = nullptr;
    Squad* squad2_ptr = nullptr;
    int ind_squad1 = -1, ind_squad2 = -1;
    if (cell.getMySquads().size() > 0) {
        std::string name;
        while (true) {
            std::cout << "which squads do you want to to include to the squad?\n"
                      <<"Input the name or 0 if don't want to include other squads: \n";
            for (int i = 0; i < cell.getMySquads().size(); ++i) {
                std::cout << cell.getMySquads()[i].getName() << "  |  ";
            }
            std::cin >> name;
            if (name == "0") {
                break;
            }
            for (int i = 0; i < cell.getMySquads().size(); ++i) {
                if (cell.getMySquads()[i].getName() == name) {
                    ind_squad1 = i;
                    break;
                }
            }

            try {
                if (ind_squad1 == -1) {
                    throw NoName();
                } else {
                    //squad1_ptr = &squad1;
                    break;
                }
            } catch (Exception &ex) {
                std::cout << ex.what();
                std::cout << "try again\n";
            }
        }

        if (name != "0") {
            squad1_ptr = new Squad;
            (*squad1_ptr) = cell.getMySquads()[ind_squad1];
//            contain_squads = true;
            cell.getMySquads().erase(cell.getMySquads().begin() + ind_squad1);
            contain_squad1 = true;
        } else {
//            delete squad1_ptr;
            squad1_ptr = nullptr;
        }
    }
    if (cell.getMySquads().size() > 0) {
        std::string name;
        while (true) {
            std::cout << "which squads do you want to to include to the squad?\nInput the name: \n";
            for (int i = 0; i < cell.getMySquads().size(); ++i) {
                std::cout << cell.getMySquads()[i].getName() << "  |  ";
            }

            std::cin >> name;
            if (name == "0") {
                break;
            }
            for (int i = 0; i < cell.getMySquads().size(); ++i) {
                if (cell.getMySquads()[i].getName() == name) {
                    ind_squad2 = i;
                    break;
                }
            }

            try {
                if (ind_squad2 == -1) {
                    throw NoName();
                } else {
//                    squad2_ptr = &squad2;
                    break;
                }
            } catch (Exception &ex) {
                std::cout << ex.what();
                std::cout << "try again\n";
            }
        }
        if (name != "0") {
            squad2_ptr = new Squad;
//            squad2 = cell.getMySquads()[ind_squad1];
            (*squad2_ptr) = cell.getMySquads()[ind_squad2];
            cell.getMySquads().erase(cell.getMySquads().begin() + ind_squad2);
            contain_squad2 = true;
        } else {
//            delete squad2_ptr;
            squad2_ptr = nullptr;
        }
    }
    std::string name;
    std::cout << "input name of squad:";
    std::cin >> name;


    Squad squad(name, SworsmanCnt, ArcherCnt, RiderCnt, contain_squad1, squad1_ptr, contain_squad2, squad2_ptr);
    cell.getMySquads().push_back(squad);

    std::cout << "name = " << squad.getName() << "\n";

    std::cout << "swordsmen = "
              << squad.getAllSwordsmanCnt() << "   " << squad.getName() << "================" << '\n';
}