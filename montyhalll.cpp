// montyhalll.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <time.h>
#include <iostream>
#include <random>


class Player
{
    int doorChoice;
    bool playerSwitches;
public:
    Player();
    int getDoorChoice();
    void changeChoice(bool b);
    bool doesPlayerSwitch();
    void chooseDoor();
};
Player::Player()
{
    int doorchoice = NULL;
}
int Player::getDoorChoice()
{
    return doorChoice;
}
void Player::changeChoice(bool b)
{
    playerSwitches = b;
}
bool Player::doesPlayerSwitch()
{
    return playerSwitches;
}
void Player::chooseDoor()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(1, 3);
    int random = distrib(gen);
    random = random-1;
    doorChoice = random;
    std::cout << "Player chooses: " << doorChoice << std::endl;
}



class game 
{
    bool doors[3] = { };
    int openedDoor;

public:
    game();
    bool isACar(int i);
    void printDoors();
    void openDoor(Player player);
    int getOpenedDoor();
    void choose(int i);
    void changeDoorChoice(int i);
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
bool game::isACar(int i)
{
    if (doors[i] == true)
    {
        return true;
    }
    return false;
}
void game::printDoors() {
    for (int i = 0; i < 3; i++)
    {
        std::cout << "Car behind door " << i << ": " << doors[i] <<std::endl;
    }
}
void game::openDoor(Player player)
{
    for (int i = 0; i < 3; i++)
    {
        if ((doors[i] != true) || (i != player.getDoorChoice()))
        {
            openedDoor = i;
            std::cout << "Door: " << i << " opened" << std::endl;
        }
    }
}
int game::getOpenedDoor()
{
    return openedDoor;
}



int main()
{
    game monty;
    Player p;
    monty.printDoors();
    p.chooseDoor();

}
