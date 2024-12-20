#include "Universe.h"
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <sstream>
#include <set>
#include <ctime>

namespace {
    const char LIVE = 'O';
    const char DEAD = '.';
}

void Universe::setName(const std::string& newName) {
    universeName = newName;
}

Universe::Universe(int w, int h) : width(w), height(h) {
    grid.resize(height, std::vector<char>(width, DEAD));
}

std::string Universe::getInfo() const {
    std::ostringstream info;
    info << "Universe Name: " << universeName << std::endl;
    info << "Transition Rule: " << transitionRule << std::endl;
    info << "Size: " << width << " x " << height << std::endl;
    return info.str();
}

void Universe::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open the file!");
    }

    std::string line;
    grid.clear();
    universeName.clear();
    transitionRule.clear();

    std::getline(file, line);
    if (line != "#Life 1.06") {
        throw std::runtime_error("Invalid file format, expected #Life 1.06");
    }

    std::getline(file, line);
    if (line.rfind("#N ", 0) == 0) {
        universeName = line.substr(3);
        std::cout << "Universe Name: " << universeName << std::endl;
    }

    std::getline(file, line);
    if (line.rfind("#R ", 0) == 0) {
        transitionRule = line.substr(3);
        std::cout << "Transition Rule: " << transitionRule << std::endl;
    }

    std::getline(file, line);
    if (line.rfind("#Size ", 0) == 0) {
        std::istringstream iss(line.substr(6));
        int w, h;
        iss >> w >> h;
        width = w;
        height = h;
        grid.resize(height, std::vector<char>(width, DEAD));
        std::cout << "Loaded Size: " << width << " x " << height << std::endl;
    }
    else {
        throw std::runtime_error("Size not found in the file.");
    }

    int x, y;
    while (file >> x >> y) {
        if (x >= 0 && x < width && y >= 0 && y < height) {
            grid[y][x] = LIVE;
        }
        else {
            std::cerr << "Warning: Coordinate out of bounds (" << x << ", " << y << ")" << std::endl;
        }
    }

    file.close();
}



void Universe::display() const {
    for (const auto& row : grid) {
        for (char cell : row)
            std::cout << cell;
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void Universe::applyRules() {
    std::vector<std::vector<char>> newGrid = grid;

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int neighbors = countNeighbors(x, y);
            if (grid[y][x] == LIVE) {
                
                if (!shouldSurvive(neighbors)) {
                    newGrid[y][x] = DEAD;
                }
            }
            else {
                if (shouldBirth(neighbors)) {
                    newGrid[y][x] = LIVE;
                }
            }
        }
    }
    grid = newGrid;
}

int Universe::countNeighbors(int x, int y) const {
    int count = 0;
    for (int dy = -1; dy <= 1; ++dy) {
        for (int dx = -1; dx <= 1; ++dx) {
            if (dx == 0 && dy == 0) continue;
            int nx = (x + dx + width) % width;
            int ny = (y + dy + height) % height;
            if (grid[ny][nx] == LIVE) {
                count++;
            }
        }
    }
    return count;
}

bool Universe::shouldSurvive(int liveNeighbors) const {
    std::set<int> survivalConditions;

    size_t sIndex = transitionRule.find('/');
    if (sIndex == std::string::npos) {
        std::cerr << "Invalid transition rule, no survival rules found!" << std::endl;
        return false;
    }

    for (size_t i = sIndex + 1; i < transitionRule.size(); ++i) {
        if (isdigit(transitionRule[i])) { 
            survivalConditions.insert(transitionRule[i] - '0');
        }
    }

    return survivalConditions.count(liveNeighbors) > 0;
}


bool Universe::shouldBirth(int liveNeighbors) const {
    std::set<int> birthConditions;

    for (size_t i = 1; i < transitionRule.size(); ++i) {
        if (transitionRule[i] == '/') break;
        if (isdigit(transitionRule[i])) {
            birthConditions.insert(transitionRule[i] - '0');
        }
    }

    return birthConditions.count(liveNeighbors) > 0;
}

void Universe::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Could not open the file for saving!" << std::endl;
        return;
    }

    file << "#Life 1.06\n";
    file << "#N " << universeName << "\n";
    file << "#R " << transitionRule << "\n";
    file << "#Size " << width << " " << height << "\n";

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            if (grid[y][x] == 'O') {
                file << x << " " << y << "\n";
            }
        }
    }

    file.close();
}



