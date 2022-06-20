#include "mounty_hall.h"

#include <time.h>
#include <stdlib.h>
#include <iostream>

#define GOAT (0)
#define CAR (1)
#define SELECTED (2)
#define CLOSE (3)

simulation::simulation(){
    srand(time(NULL));   // Initialization, should only be called once.
}

int simulation::randomGenerator (){
     return ( rand()%MAX_NUM_DOOR + 1 ); // 1-3
}

/**
 * @brief doors randomly
*/
void simulation::generatorDoors (void){
    doorGuest = doorHost = -1;
    int car = randomGenerator();
    doors[car - 1] = CAR;
}

int simulation::getDoorFromGuest (void){
    std::cout << "Select the door winner please"<< std::endl;
    std::cin >> doorGuest ;
    
    if ( doorGuest -1 < 0 || doorGuest -1 >= MAX_NUM_DOOR ){
        std::cout << "ERROR: Bad entry door" << std::endl;
        return -1;
    }
    doorsGuestAux[doorGuest -1] = 0;// seleccionado por concursante
    doorsSelected[doorGuest -1] = doorGuest;
    return doorGuest;    

}

/**
 * @brief escoge una puerta que no es la ganadora
*/
int simulation::openDoorFromHost (void){
    do {
        doorHost = randomGenerator();
    }while( iSselectDoorWinner(doorHost) || (doorHost == doorGuest ));  
    doorsGuestAux[doorHost -1] = 1;//seleccionado por el presentador
    doorsSelected[doorHost -1] = doorHost;
    return doorHost;
}

bool simulation::iSselectDoorWinner(int value){
    return (doors[ value -1] == CAR);
}

bool simulation::iSselectDoorFromHostAGoat(int value){
    return (doors[ value -1 ] == GOAT);
}

void simulation::print(void){
    std::cout << doors[0] << doors[1] << doors[2] << std::endl;
    std::cout << "doorGuest: " << doorGuest << std::endl;
    std::cout << "doorHost: " << doorHost << std::endl ;
}


void simulation::printDoorsClose(void){
    patternClose();
    patternClose();
    patternClose();
    std::cout << "==========================================" << std::endl;

}

void simulation::printDoorsAll(void){
   for( int i=0 ; i< MAX_NUM_DOOR ;i ++){
        patternSelector(doors[i]);
   }
    std::cout << "==========================================" << std::endl;

}

void simulation::printDoorsFromPosition(void){
   for( int i=0 ; i< MAX_NUM_DOOR ;i ++){
    switch(doorsGuestAux[i]){
        case 0: // guest
            patternSelector(2);//sin mostarr aun
        break;
        case 1:  //host
            patternSelector(0);
        break;
        case -1: // no mostrar
            patternSelector(3);
        break;
    }
   }
    std::cout << "==========================================" << std::endl;

}
void simulation::printDoorsFromPosition(int pos, int shape){
    if( pos == 1){
        patternSelector(shape);
        patternClose();
        patternClose();
        }
    else if(pos == 2){
            patternClose();
            patternSelector(shape);
            patternClose();
        }else if(pos == 3) {
            patternClose();
            patternClose();
            patternSelector(shape);
        }
    std::cout << "==========================================" << std::endl;

}
void simulation::patternClose(void){
        std::cout << "--------------" << std::endl;
        std::cout << "     ___     " << std::endl;
        std::cout << "    |__ \\   " << std::endl;
        std::cout << "       ) |   " << std::endl;
        std::cout << "      / /    " << std::endl;
        std::cout << "     |_|     " << std::endl;
        std::cout << "     (_)     " << std::endl;
        std::cout << "--------------" << std::endl;
}

void simulation::patternCloseAndSelected(void){
        std::cout << ANSI_YELLOW <<"--------------" << ANSI_RESET <<  std::endl;
        std::cout << ANSI_YELLOW <<"     ___     " <<  ANSI_RESET << std::endl;
        std::cout << ANSI_YELLOW <<"    |__ |   " <<   ANSI_RESET << std::endl;
        std::cout << ANSI_YELLOW <<"     | |    " <<   ANSI_RESET << std::endl;
        std::cout << ANSI_YELLOW <<"     | |    " <<   ANSI_RESET << std::endl;
        std::cout << ANSI_YELLOW <<"     |_|     " <<  ANSI_RESET << std::endl;
        std::cout << ANSI_YELLOW <<"     (_)     " <<  ANSI_RESET << std::endl;
        std::cout << ANSI_YELLOW <<"--------------" << ANSI_RESET << std::endl;
}

void simulation::patternSelector(int value){

    switch (value){
        case CAR:
            std::cout<< ANSI_CYAN << "--------------" << ANSI_RESET <<  std::endl;
            std::cout<< ANSI_CYAN << "              " << ANSI_RESET <<  std::endl;
            std::cout<< ANSI_CYAN << "  ______      " << ANSI_RESET <<  std::endl;
            std::cout<< ANSI_CYAN << " /|_||_\\`.__ "<<  ANSI_RESET << std::endl;
            std::cout<< ANSI_CYAN << "(   _    _ _\\"<<  ANSI_RESET << std::endl;
            std::cout<< ANSI_CYAN << "=`-(_)--(_)-'" <<  ANSI_RESET << std::endl;
            std::cout<< ANSI_CYAN << "              " << ANSI_RESET <<  std::endl;
            std::cout<< ANSI_CYAN << "--------------" << ANSI_RESET <<  std::endl;
        break;
        case GOAT:
            std::cout<< ANSI_MAGENTA << "--------------" <<         ANSI_RESET <<std::endl;
            std::cout<< ANSI_MAGENTA << "              " <<         ANSI_RESET <<std::endl;
            std::cout<< ANSI_MAGENTA << " (_(         " <<          ANSI_RESET <<std::endl;
            std::cout<< ANSI_MAGENTA << " /_/'_____/) " <<          ANSI_RESET <<std::endl;
            std::cout<< ANSI_MAGENTA << " \"  |      | " <<         ANSI_RESET <<std::endl;
            std::cout<< ANSI_MAGENTA << "    |\"\"\"\"\"\"| "  <<   ANSI_RESET <<std::endl;
            std::cout<< ANSI_MAGENTA << "              " <<         ANSI_RESET <<std::endl;
            std::cout<< ANSI_MAGENTA << "--------------" <<         ANSI_RESET <<std::endl;
        break;
        case SELECTED:
            patternCloseAndSelected();
        break;
        case CLOSE:
            patternClose();
        break;
    }

}




