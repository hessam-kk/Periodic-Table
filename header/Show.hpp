#pragma once
#include "Elements.hpp"

void show_all(Element *);

void show_selected(unsigned short int, Element *);

void show_guide();

void show_in_define(int);
void show_in_define(int, char *);
void show_in_define(int, char *, char *);
void show_in_define(int, char *, char *,float);
void show_in_define(short int, char *, char *, float , short int);
void show_in_define(short int, char *, char *, float, short int, char *);

void show_search(void);
void show_search_name(void);
void show_search_name_selected(char *);
void show_search_elementNumber(void);
void show_search_elementNumber_selected(const short int);
void show_search_symbol(void);
void show_search_symbol_selected(const char *);
void show_search_weight(void);
void show_search_weight_selected(const float);

void show_edit_name(char *);
void show_edit_element_number(const short int);