
#include "Universe.h"

class GameOfLife {
public:
    GameOfLife(int width, int height);
    void loadUniverse(const std::string& filename);
    void display() const;
    void tick(int iterations);
    void saveUniverse(const std::string& filename) const;
    Universe& getUniverse();

private:
    Universe universe;
};


