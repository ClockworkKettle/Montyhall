# Montyhall Simulator
For those of us who have struggled with the monty hall problem, the aim of this project is to create a monty hall simulator and observe the results.

The Monty Hall Problem can be explained as follows:

Given three doors, one which contains a car, the other two goats.
A player is given a choice of which door the car is behind.
The host, reveals a goat behind one of the doors and asks the player if they would like to change their choice of door.

It is expected that the changing of choice will lead to choosing the correct door in more scenarios than not changing.

Simulation results after 1,000,000 iterations:

Switching Player Won: 666938 times or 66.69%
Non Switching Player Won: 333062 times or 33.31%


The naive intuition might be that because it is a choice between two doors the odds of winning are 50/50.
This was my initial thought. By breaking it into truth tables I discovered a simpler way to understand the 2/3 probability of winning that seems roughly accurate from the simulation.


Given [ T F F ] ( the car is behind door number 1)
(^ shows player choice, * shows door that can be opened)
If the player starts at position 0  [ T F F ] and switches, the player will lose.
                                      ^ * *
 However if the player starts at either of the other positions, the other False result will be revealed for example
 [ T F F ] [ T F F ] 
      ^ *       * ^
  This shows that if the player switches in either of these scenario's the player will win. For every scenario where the player loses by switching, there are two possibilities     
  where the player wins. 
           
                                      
                                   
