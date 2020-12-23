#include "../header/Search.hpp"
#include <iostream>
#include <string.h>
#include <cstring>
#include <unistd.h>


int search_by_name(char * ch, Element * p){
    for(int i = 0; i < 118; i++){
        if ( strcmp( ch , p[i].name) == 0 ){
            std::cout << "---- Element Found!! ----" << std::endl;
            return i;            
        }
    }
    std::cerr << "---- Not Found!! ----" << std::endl;
    return -404;
}

void to_lowercase (char * ch){
    for(int i = 0; i < std::strlen(ch) ;i++){
        if( ch[i] >= 'A' && ch[i] <= 'Z')
            ch[i] += 32;
    }
}

int search_by_elementNumber(const int j, Element * p){
    if( j <= 0 && j > 118){
        std::cerr << "Invalid Input!" << std::endl;
        sleep(2);
        return 503;
    }

    for(int i = 0; i < 118; i++){
        if(j == p[i].elementNumber){
            std::cout << "---- Element Found!! ----" << std::endl;
            sleep(2);
            return j;            
        }
    }
    std::cerr << "---- Not Found!! ----" << std::endl;
    return -404;
}

int search_by_symbol(char * ch, Element * p){
    for(int i = 0; i < 118; i++){
        if ( strcmp( ch , p[i].symbol) == 0 ){
            std::cout << "---- Element Found!! ----" << std::endl;
            sleep(2);
            return i;            
        }
    }
    std::cerr << "---- Not Found!! ----" << std::endl;
    sleep(2);
    return -404;
}


float search_by_weight(const float j, Element * p){
    if( j <= 0 ){
        std::cerr << "Invalid Input!" << std::endl;
        sleep(2);
        return 503;
    }

    for(int i = 0; i < 118; i++){
        if(j == p[i].weight){
            std::cout << "---- Element Found!! ----" << std::endl;
            sleep(3);
            return j;            
        }
    }
    std::cerr << "---- Not Found!! ----" << std::endl;
    return -404;
}
