/**
 * @brief gamem mounty hall
 * @author Julian Bustamante N
 * @date 220620
 * 
*/
//4-5h
/*use:
$ g++ main.cpp mounty_hall.cpp -Wall -Wextra -o main
$ ./main
Note: ampliar pantalla para ver graficos.
 */

#include <iostream>
#include "mounty_hall.h"
#include<unistd.h>

int main (){

    int door;
    simulation sim;
    int secodSelection;
    sim.printDoorsClose();
    sim.generatorDoors();
   
    do{
        std::cout << "Guest Select..." << std::endl;
        door = sim.getDoorFromGuest();
        std::cin.clear();
        std::cin.ignore();
    }while( door  == -1);

    sim.printDoorsFromPosition();
    std::cout << "Host Select..." << std::endl;
    usleep(2*1E6);
    int doorHost = sim.openDoorFromHost() ;

    sim.printDoorsFromPosition();

     std::cout << "Guest again Select..." << std::endl;
        while ( secodSelection = sim.getDoorFromGuest(), secodSelection == doorHost){
        }
        if( sim.iSselectDoorWinner(secodSelection)){
            std::cout << ANSI_GREEN << WINNER() << ANSI_RESET;
            std::cout << "==========================================" << std::endl;

        }else{
            std::cout << ANSI_RED << LOSER() << ANSI_RESET;
            std::cout << "==========================================" << std::endl;

        }
        sim.printDoorsAll();
    
     return EXIT_SUCCESS;
    




}