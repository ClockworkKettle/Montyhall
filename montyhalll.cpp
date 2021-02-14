// montyhalll.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <time.h>
#include <iostream>
#include <random>
class game {
    bool doors[3] = { };

public:
    game();
    bool isacar(int i);
    void printdoors();
    void choose(int i);
    void changechoice(int i);
};
game::game()
{
    std::random_device rd;  
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 2);
    int random = distrib(gen);
    std::cout << "Random num: " << random << std::endl;
    for (int i = 0; i < 3; i++)
    {
        doors[i] = false;
    }
    doors[random] = true;
}
bool game::isacar(int i)
{
    if (doors[i] == true)
    {
        return true;
    }
    return false;
}
void game::printdoors() {
    for (int i = 0; i < 3; i++)
    {
        std::cout << "Car behind door " << i << ": " << doors[i] <<std::endl;
    }
}
int main()
{
    game monty;
    monty.printdoors();
}
