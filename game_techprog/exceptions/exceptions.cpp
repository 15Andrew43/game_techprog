//
// Created by Андрей Боровец on 11.04.2020.
//

#include <iostream>
#include <cstring>
#include "exceptions.h"


std::string Exception::what() {
    return "EXCEPTION!!!1!1!1!1!1!1!1!1!1!\n";
}

std::string GameOverException::what() {
    return "game__over__blabla!!!1!1!1!1!1!1!1!1!1!\n";
}

std::string NotEnoughMoney::what() {
    return "You do NOT have enough money.\n";
}

std::string LowLevel::what() {
    return "You should boost the level of the building.\n";
}

std::string HasAlreadyGone::what() {
    return "You have already gone. You can't go 2 times in one round\n";
}

std::string MaxLevel::what() {
    return "You can't upgrade, because level of it is MAX\n";
}

std::string InvalidArgument::what() {
    return "YOU INPUT SMTH WRONG\n";
}

std::string NotEnougSquads::what() {
    return "No squads in this Cell\n";
}

std::string NotEnoughUnits::what() {
    return "Not enough units in this Cell\n";
}

std::string NoName::what() {
    return "There is NO name, ehich you input.\n";
}

std::string LongDistance::what() {
    return "you can't go so far\n";
}