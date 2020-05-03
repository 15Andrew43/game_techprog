#include <iostream>
#include "main.h"


int main() {
    std::cout << "Hello, World!" << std::endl;
    Map map;
    SetUp(map); // выбор команды и тд
    while (true) {
        try {
            MyStep(map);
        } catch (Exception& ex) {
            std::cout << "вы ПОБЕДИЛИ!\n";
            break;
        }
        try {
            RivalStep(map);
        } catch(Exception& ex) {
            std::cout << "вы ПРОИГРАЛИ.\n";
            break;
        }
    }
    return 0;
}