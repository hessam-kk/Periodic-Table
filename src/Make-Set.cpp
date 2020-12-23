#include "../header/Elements.hpp"
#include <iostream>
#include <string.h>
#include <unistd.h>
#include "../header/Search.hpp"

void make_init(unsigned short int n, char* name,
 char* symbol, float weight, unsigned short int state, char* attribute, Element * p){
    p[n].elementNumber = n;
    strcpy( p[n].name, name );
    strcpy( p[n].symbol, symbol );
    p[n].weight = weight;
    p[n].state = state;
    strcpy( p[n].attribute, attribute);
    p[n].defined = true;
}



void define_new_element(unsigned short int o, Element * p ){
    if( o <= 118 && o >= 0 ){
        p[o].elementNumber = o;
        std::cout << "A New Element With Number "<< o << 
        " Has Been Made or overwritten." << std::endl;
    }
    else std::cout << "Invalid Input!" << std::endl;
}

void set_elementNumber(short int o, short int newN, Element * p){
    if( newN <= 118 && newN >= 0 ){
        p[o].elementNumber = newN;
        std::cout << "A New Element With Number "<< newN << 
        " Has Been Made or overwritten." << std::endl;
    }
    else std::cout << "Invalid Input!" << std::endl;
}

void set_element_name(unsigned short int o, char * ch, Element * p){
    char xx[15];
    strcpy( xx , ch );
    to_lowercase(xx);
    strcpy( p[o].name , xx );
    std::cout << "The name " << ch << 
    " Has Been set or updated for the element with number: " << o << std::endl;
}

void set_element_weight(unsigned short int o, float x, Element * p){
        p[o].weight = x;
        std::cout << "The weight " << x << 
        " Has Been set or updated for the element with number: " << o << std::endl;
}

void set_element_symbol(unsigned short int o, char* ch, Element * p){
        char xx[3];
        strcpy( xx ,ch);
        to_lowercase(xx);
        strcpy( p[o].symbol , xx);
        std::cout << "The Symbol " << p[o].symbol << 
        " Has Been set or updated for the element with number: " << o << std::endl;
}

void set_element_state(short int o , short int x, Element * p){
    // 1:Gas | 2:Liquid | 3:Solid 
    switch (x){
    case 1:
        p[o].state = x;
        std::cout << "The State " << "Gas" << 
        " Has Been set or updated for the element with number: " << o << std::endl;
        break;
    case 2:
        p[o].state = x;
        std::cout << "The State " << "Liquid" << 
        " Has Been set or updated for the element with number: " << o << std::endl;
        break;
    case 3:
        p[o].state = x;
        std::cout << "The State " << "Solid" << 
        " Has Been set or updated for the element with number: " << o << std::endl;
        break;
    default:
        std::cout << "You Have Entered a Wrong Number For States!";
        break;
    }
}

void set_element_attribute(short int o, char * ch, Element * p){
    strcpy( p[o].attribute, ch );
    std::cout << "||  The attribute \"" << p[o].attribute << 
    "\" Has Been set or updated for the element with number: " << o << std::endl;
}

void element_defined_yet(int o, Element * p, short int * agree){
    
    std::cout << "||  This Element is defined yet, Do you want to" <<
    " Redefine It? ( yes = 1 | no = 0 ) : ";
    int x;
        std::cin >> x;
    if(x == 1) {
        *agree = 0;
    }
    if( x == 0){
        *agree = 1;
    }
}

int wrong_state(int x){
    if(x != 1 && x != 2 && x != 3) {
        std::cout << "||  State Should be 1(Gas) or 2(Liquid) or 3(Solid). \n";
        sleep(3);
        return true;
    } else return false;
}

int wrong_weight(float x){
    if( x == 0.0 ){
        std::cout << "||  Weight cannot be 0, Try Again.\n";
        sleep(2);
        return true;
    } else if ( x < 0) {
        std::cout << "||  Weight cannot be Negative, Try Again.\n";
        sleep(2);
        return true;
    } else return false;
}
