// montyhalll.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <time.h>
#include <iostream>
#include <random>


class Player
{
    int doorChoice;
public:
    Player();
    int getDoorChoice();
    void chooseDoor();
    void chooseNewDoor(int i);   
};
Player::Player()
{
    doorChoice = -1;
}
int Player::getDoorChoice()
{
    return doorChoice;
}
void Player::chooseDoor()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> distrib(1, 3);
    int random = distrib(gen);
    random = random-1;
    doorChoice = random;
    std::cout << "Player chooses: " << doorChoice << " | " ;
}
void Player::chooseNewDoor(int i)
{
    doorChoice = i;
    std::cout << "New door: " << doorChoice << " | ";
}

class game 
{
    bool doors[3] = { };
    int openedDoor;

public:
    game();
    Player player;
    bool isACar(int i);
    void printDoors();
    void openDoor();
    int getOpenedDoor();
    void changeDoorChoice();
    bool doesPlayerWin();
};
game::game()
{
    std::random_device rd;  
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(0, 2);
    int random_index = distrib(gen);
    openedDoor = -1;
    for (int i = 0; i < 3; i++)
    {
        doors[i] = false;
    }
    doors[random_index] = true;
    std::cout << "Winning door: " << random_index << " | ";
}
bool game::isACar(int i)
{
    if (doors[i] == true)
    {
        return true;
    }
    return false;
}
void game::printDoors() 
{
    for (int i = 0; i < 3; i++)
    {
        std::cout << "Car behind door " << i << ": " << doors[i] <<std::endl;
    }
}
void game::openDoor()
{
    for (int i = 0; i < 3; i++)
    {
        if ((doors[i] == false) && (i != player.getDoorChoice()))
        {
            openedDoor = i;
            std::cout << "Door: " << i << " opened" << " | ";
            break;
        }
    }
}
int game::getOpenedDoor()
{
    return openedDoor;
}
bool game::doesPlayerWin()
{
    return isACar(player.getDoorChoice());
}
void game::changeDoorChoice()
{
    for (int i = 0; i < 3; i++)
    {
        if ((i != player.getDoorChoice()) && (i != getOpenedDoor()))
        {
            player.chooseNewDoor(i);
            break;
        }
    }
    std::cout << "Player switches to: " << player.getDoorChoice() << " | ";
}
int main()
{
    std::cout.setf(std::ios::boolalpha);
    int switchWins=0;
    int noSwitchWins=0;
    
    int numberOfIterations;
    std::cout << "Please enter the number of times you wish to run the simulation: " << std::endl << ">";
    std::cin >> numberOfIterations;

    for (int i = 0; i < numberOfIterations; i++) 
    {
        
        game* monty = new game();
        //monty.printDoors();
        monty->player.chooseDoor();
        monty->openDoor();
        monty->changeDoorChoice();
        monty->player.getDoorChoice();
        std::cout << "Player wins: " << monty->doesPlayerWin();
        if (monty->doesPlayerWin())
        {
            switchWins += 1;
        }
        else
        {
            noSwitchWins += 1;
        }
        delete(monty);
        std::cout << std::endl;
    }
    std::cout << "Switching Player Won: " << switchWins << " times" << std::endl;
    std::cout << "Non Switching Player Won: " << noSwitchWins << " times" << std::endl;
}

/*   win condition  win condition   lose condition
pc  [T              F               F] 
         
    [F              F              T] 
    
*/