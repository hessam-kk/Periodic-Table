#pragma once

struct Element{
    unsigned short int elementNumber;
    char name[15];
    char symbol[3];
    float weight;
    unsigned short int state; // 1:Gas | 2:Liquid | 3:Solid 
    char attribute[50];
    bool defined = false;
};

void make_init(unsigned short int, char*,
        char*, float, unsigned short int, char*, Element *);

void define_new_element(unsigned short int, Element *);

void set_elementNumber(short int, short int, Element *);

void set_element_name(unsigned short int, char *, Element *);

void set_element_weight(unsigned short int, float, Element *);

void set_element_symbol(unsigned short int, char *,  Element *);

void set_element_state(short int , short int, Element *);

void set_element_attribute(short int , char *, Element *);

void element_defined_yet(int, Element *, short int *);

int wrong_state(int);

int wrong_weight(float);
