
#include <vector>
#include <string>

class Universe {
public:
    Universe(int width, int height);
    void loadFromFile(const std::string& filename);
    void display() const;
    void applyRules();
    void saveToFile(const std::string& filename) const;
    void setName(const std::string& newName);
    std::string getInfo() const;

    void setCell(int x, int y, char state) {
        if (y >= 0 && y < height && x >= 0 && x < width) {
            grid[y][x] = state;
        }
    }

    char getCell(int x, int y) const {
        if (y >= 0 && y < height && x >= 0 && x < width) {
            return grid[y][x];
        }
        return '.';
    }

    void setTransitionRule(const std::string& rule) {
        transitionRule = rule;
    }

    int countNeighbors(int x, int y) const;
    bool shouldSurvive(int liveNeighbors) const;
    bool shouldBirth(int liveNeighbors) const;

private:
    int width, height;
    std::vector<std::vector<char>> grid;
    std::string universeName;
    std::string transitionRule;
};

