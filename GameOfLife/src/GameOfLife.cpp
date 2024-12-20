#include "GameOfLife.h"
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <cstdlib>
#include <ctime>

GameOfLife::GameOfLife(int width, int height)
    : universe(width, height) {}

void GameOfLife::loadUniverse(const std::string& filename) {
    universe.loadFromFile(filename);
}


void GameOfLife::display() const {
    universe.display();
}

void GameOfLife::tick(int iterations) {
    for (int i = 0; i < iterations; ++i) {
        universe.applyRules();
    }
}

void GameOfLife::saveUniverse(const std::string& filename) const {
    universe.saveToFile(filename);
}

Universe& GameOfLife::getUniverse() {
    return universe; // Возвращаем ссылку на объект вселенной
}
