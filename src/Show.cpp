#include "../header/Show.hpp"
#include <iostream>
#include <cstring>
#include <unistd.h>
#include <iomanip>
#define UPBORDER std::cout<<"=====================================================\n";

void show_all(Element * p){
    for(int i = 0; i < 118 ; i++){
        if( p[i].defined == false )
            continue;
        UPBORDER;
        std::cout << "||  The Element Number is: " << p[i].elementNumber  << std::endl;
        std::cout << "||  Name and Symbol: " << p[i].name << 
        " And "  << p[i].symbol << std::endl;
        std::cout << "||  Weight: " << p[i].weight << std::endl;
        switch (p[i].state){
            case 1 :
                std::cout << "||  State: Gas " << std::endl; 
                break;
            case 2 :
                std::cout << "||  State: Liquid " << std::endl; 
                break;
            case 3 :
                std::cout << "||  State: Solid " << std::endl; 
                break;
            default:
            std::cout << "||  State has been set wrong or not set yet." << std::endl;
                break;
        }
        std::cout << "||  Attribute: " << p[i].attribute << std::endl;
    }
    UPBORDER;
}

void show_selected(unsigned short int o, Element * p){
     UPBORDER;
        std::cout << "||  The Element Number is: " << p[o].elementNumber + 1 << std::endl;
        std::cout << "||  Name and Symbol: " << p[o].name << 
        " And "  << p[o].symbol << std::endl;
        std::cout << "||  Weight: " << p[o].weight << std::endl;
        switch (p[o].state){
            case 1 :
                std::cout << "||  State: Gas " << std::endl; 
                break;
            case 2 :
                std::cout << "||  State: Liquid " << std::endl; 
                break;
            case 3 :
                std::cout << "||  State: Solid " << std::endl; 
                break;
        }
        std::cout << "||  Attribute: " << p[o].attribute << std::endl;
    UPBORDER;
    }

void show_guide(){
    system("clear");
    UPBORDER;
    std::cout << "||  To define a new element please enter 1,        ||" << std::endl;
    std::cout << "||  To show all elements already defined,enter 2,  ||" << std::endl;
    std::cout << "||  To search an element and edit it enter 3,      ||" << std::endl;
    std::cout << "||  To sort all of them enter 4.                   ||" << std::endl;
    UPBORDER;
    std::cout << "  >> ";
}

void show_in_define(int x){
    system("clear");
    UPBORDER;
    std::cout << "||  Element Number: " << x << std::endl;;
}

void show_in_define(int x, char * chname){
    system("clear");
    UPBORDER;
    std::cout << "||  Element Number: " << x << "  -  Name: "<< chname << std::endl;
}

void show_in_define(int x, char * chname, char * chsymbol){
    show_in_define(x, chname);
    std::cout << "||  Symbol: " << chsymbol;
}

void show_in_define(int x, char * chname, char * chsymbol, float weight){
   show_in_define(x, chname, chsymbol); 
  std::cout << "  -  Weight: " << weight;
}

void show_in_define(short int x, char * chname, char * chsymbol, float weight, short int state){
    show_in_define(x, chname, chsymbol, weight);
    switch (state){
        case 1 :
            std::cout << "     -  State: Gas " << std::endl; 
            break;
        case 2 :
            std::cout << "     -  State: Liquid " << std::endl; 
            break;
        case 3 :
            std::cout << "     -  State: Solid " << std::endl; 
            break;;
    }
}

void show_in_define(short int x, char * chname, char * chsymbol, float weight, short int state, char * chatt ){
    show_in_define(x, chname, chsymbol, weight, state);
    std::cout << "||  Attribute: " << chatt << std::endl;
    UPBORDER;
}

void show_search(void){
        system("clear");
        UPBORDER;
        std::cout << "=============+How Do You Want To Search+=============" << std::endl;
        UPBORDER;
        std::cout << "1:Name |2:Element Number |3:Symbol |4:Weight |5:State" << std::endl;
        UPBORDER;
        std::cout << "  >> ";

}

void show_search_name(void){
        system("clear");
        UPBORDER;;
        std::cout << "============Search Method Selected : Name============" << std::endl;
        UPBORDER;
        std::cout << "Please Enter The Name.(0 To Main Menu)\n" <<
        "(Not Sensetive To UPPERCASE or lowercase)" << std::endl;
        std::cout << "  >> ";
}

void show_search_name_selected(char * g){
    system("clear");
    UPBORDER;
    printf("=============Selected Element : %s=============\n", g);
    UPBORDER;
    std::cout << "What Do You Want To Edit From This Element?" << std::endl;
    std::cout << "1:Name |2:Element Number |3:Symbol |4:Weight |5:State" << std::endl;
    std::cout << "  >> ";
}

void show_edit_name(char * g){
    system("clear");
    UPBORDER;
    std::cout << "You Are Editing Element With Name:  " << g << std::endl;;
    UPBORDER;
    std::cout << "Enter The New Name." << std::endl;
    std::cout << "  >> ";
}

void show_search_elementNumber(void){
        system("clear");
        UPBORDER;;
        std::cout << "=======Search Method Selected : Element Number=======" << std::endl;
        UPBORDER;
        std::cout << "Please Enter The Element Number.(0 To Main Menu)\n";
        std::cout << "  >> ";
}

void show_search_elementNumber_selected(const short int g){
    system("clear");
    UPBORDER;
    printf("=============Selected Element : Number %d============\n", g);
    UPBORDER;
    std::cout << "What Do You Want To Edit From This Element?" << std::endl;
    std::cout << "1:Name |2:Element Number |3:Symbol |4:Weight |5:State" << std::endl;
    std::cout << "  >> ";
}
void show_edit_element_number(const short int g){
    UPBORDER;
    std::cout << "You Are Editing Element With Number:  " << g+1 << std::endl;;
    UPBORDER;
    std::cout << "Enter The New Number." << std::endl;
    std::cout << "  >> ";
}

void show_search_symbol(void){
        system("clear");
        UPBORDER;
        std::cout << "=======Search Method Selected : Element Symbol=======" << std::endl;
        UPBORDER;
        std::cout << "Please Enter The Element Symbol.(0 To Main Menu)\n";
        std::cout << "  >> ";
}

void show_search_symbol_selected(const char * g){
    system("clear");
    UPBORDER;
    printf("============Selected Element : Symbol %s============\n", g);
    UPBORDER;
    std::cout << "What Do You Want To Edit From This Element?\n";
    std::cout << "1:Name |2:Element Number |3:Symbol |4:Weight |5:State" << std::endl;
    std::cout << "  >> ";
}



void show_search_weight(void){
        system("clear");
        UPBORDER;
        std::cout << "=======Search Method Selected : Element Weight=======" << std::endl;
        UPBORDER;
        std::cout << "Please Enter The Element Weight.\n";
        std::cout << "  >> ";
}

void show_search_weight_selected(const float x){
    system("clear");
    UPBORDER;
    printf("=========Selected Element : Weight %f==========\n", x);
    UPBORDER;
    std::cout << "What Do You Want To Do With This Element?\n  >> ";
}