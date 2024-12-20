#include <iostream>
#include "GameOfLife.h"
#include <string>

void printHelp() {
    std::cout << "Available commands:" << std::endl;
    std::cout << "  load <filename> - Load universe from a file" << std::endl;
    std::cout << "  display - Display the current universe" << std::endl;
    std::cout << "  tick <n> - Generate `n` iterations (default is 1)" << std::endl;
    std::cout << "  save <filename> - Save current universe to a file" << std::endl;
    std::cout << "  setname <new name>" << std::endl;
    std::cout << "  info - Show info about this universe" << std::endl;
    std::cout << "  help - Show this help message" << std::endl;
    std::cout << "  exit - Exit the game" << std::endl;
}

int main() {
    GameOfLife game(10, 10);
    std::string command;
    bool running = true;

    std::cout << "Welcome to Conway's Game of Life!" << std::endl;
    printHelp(); 

    while (running) {
        std::cout << "> ";
        std::getline(std::cin, command);

        if (command.rfind("load ", 0) == 0) {
            std::string filename = command.substr(5);
            try {
                game.loadUniverse(filename);
                std::cout << "Loaded universe from " << filename << std::endl;
            }
            catch (const std::runtime_error& e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }
        }
        else if (command == "display") {
            game.display();
        }
        else if (command.rfind("tick ", 0) == 0) {
            std::string param = command.substr(5);
            int iterations = 1;
            if (!param.empty()) {
                iterations = std::stoi(param);
            }
            game.tick(iterations);
            std::cout << "Ticked " << iterations << " generations." << std::endl;
        }
        else if (command.rfind("save ", 0) == 0) {
            std::string filename = command.substr(5);
            try {
                game.saveUniverse(filename);
                std::cout << "Saved universe to " << filename << std::endl;
            }
            catch (const std::runtime_error& e) {
                std::cerr << "Error: " << e.what() << std::endl;
            }
        }
        else if (command == "help") {
            printHelp(); 
        }
        else if (command == "exit") {
            running = false;
        }
        else if (command == "info") {
            std::cout << game.getUniverse().getInfo();
        }
        else if (command.rfind("setname ", 0) == 0) {
            std::string newName = command.substr(8);
            game.getUniverse().setName(newName);
            std::cout << "Universe name set to: " << newName << std::endl;
        }
        else {
            std::cout << "Unknown command. Type 'help' for a list of commands." << std::endl;
        }
    }

    std::cout << "Exiting the game. Goodbye!" << std::endl;
    return 0;
}
