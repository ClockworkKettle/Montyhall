// montyhalll.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <time.h>
#include <iostream>
#include <random>


class Player
{
    int choice;
public:
    Player();
    int getChoice();
    void choose();
};
Player::Player()
{
    int choice = NULL;
}
int Player::getChoice()
{
    return choice;
}
void Player::choose()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1, 3);
    int random = distrib(gen);
    random = random-1;
    choice = random;
    std::cout << "Player chooses: " << choice << std::endl;
}

class game {
    bool doors[3] = { };
    int openeddoor;

public:
    game();
    bool isacar(int i);
    void printdoors();
    void opendoor(Player player);
    int getOpenedDoor();
    void choose(int i);
    void changechoice(int i);
};
game::game()
{
    std::random_device rd;  
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 2);
    int random_index = distrib(gen);
    std::cout << "Random num: " << random_index << std::endl;
    for (int i = 0; i < 3; i++)
    {
        doors[i] = false;
    }
    doors[random_index] = true;
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
void game::opendoor(Player player)
{
    for (int i = 0; i < 3; i++)
    {
        if ((doors[i] != true) || (i != player.getChoice()))
        {
            openeddoor = i;
            std::cout << "Door: " << i << " opened" << std::endl;
        }
    }
}
int game::getOpenedDoor()
{
    return openeddoor;
}



int main()
{
    game monty;
    monty.printdoors();
    Player p;
    p.choose();

}
