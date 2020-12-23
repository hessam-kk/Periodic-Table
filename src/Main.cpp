#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <limits>
#include <limits.h>
#include <unistd.h>
#include <fstream>
#include "Elements.hpp"
#include "Show.hpp"
#include "Search.hpp"

using namespace std;
#define UPBORDER std::cout<<"====================================================="<<std::endl;

int main(){
    // std::cout << endl;
    struct Element ele[118];
    // defining new elements
    make_init(0,  (char*)"hedrogen",(char*)"H",  4.5,   2, (char*)"Beautiful", ele);
    make_init(1,  (char*)"argon",  (char*)"ar",  15.6,  1, (char*)"poisoness", ele);
    make_init(7,  (char*)"lorem",  (char*)"lr",  15.17, 3, (char*)"lorem ipsum", ele);
    make_init(15, (char*)"alu",    (char*)"al",  99.03, 3, (char*)"Hellish", ele);
    make_init(19, (char*)"ipsum",  (char*)"ip",  0.263, 1, (char*) "Lorem Ipsummmm", ele);
    make_init(25, (char*)"xenon",  (char*)"xe",  25.09, 2, (char*)"Gasic", ele);
    make_init(30, (char*)"text",   (char*)"tx",  14.97, 1, (char*)"Textte", ele);
    make_init(33, (char*)"dolor",  (char*)"dl",  5.0,   3, (char*)"dollor elexa", ele);
    make_init(40, (char*)"elem",   (char*)"el",  2.3,   1, (char*)"elem se gfe a", ele);
    make_init(47, (char*)"hexa",   (char*)"he", 66.03, 3, (char*)"hexa ere juta", ele);
    make_init(50, (char*)"erea",   (char*)"er",  556.98,2, (char*)"era dora pura", ele);
    make_init(80, (char*)"chrome", (char*)"ch",  77.3,  2, (char*)"Fast", ele);
    make_init(86, (char*)"firefox",(char*)"fx",  86.99, 1, (char*)"slow", ele);
    make_init(90, (char*)"tor",    (char*)"tr",  47.7,  3, (char*)"secure more", ele);
    make_init(117,(char*)"lst",    (char*)"ls",  17.87, 2, (char*)"last one", ele);
    std::system("clear");

    int input = -30; //Garbage Value;
while( 1 ){
 
    show_guide();
        cin >> input;

    if(input == 1){
        short int inp_ele_num, inp_ele_state, redefine = 1; 
        float inp_ele_weight;
        string st;
        char inp_ele_name[15], inp_ele_symb[3], inp_ele_att[50];
        
        while( redefine == 1 ){
                system("clear");
                UPBORDER;
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "||  Please Enter Element Number: ";
                cin >> inp_ele_num;
                while( (inp_ele_num) > 118 || (inp_ele_num) < 0 ){
                    cerr << "--- Input Should be in Range 1 - 118 ---\n";
                    sleep(2);
                    system("clear");
                    UPBORDER;
                    cout << "||  Please Enter Element Number: ";
                    cin >> inp_ele_num;
                }
                
                for (size_t i = 0; i < 118; i++){
                    redefine = 0;
                    if( inp_ele_num == ele[i].elementNumber ){
                        element_defined_yet(inp_ele_num, ele, &redefine);
                        break;
                    }
                }
                if(redefine == 0) break;
        }         
        
        ele[inp_ele_num].elementNumber = inp_ele_num;
        if( redefine == 0 ){ // redefine == 0 Means User want to overwrite
            show_in_define(inp_ele_num);
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "||  Element Name(Without Spaces, Maximum 15 Characters): "; 
            cin >> inp_ele_name;
            //Converting to string to use SUBSTR and converting back to char[] to save it
            string inp_ele_name_str;
            inp_ele_name_str = (string) inp_ele_name;
            string inp_ele_name_limited = inp_ele_name_str.substr(0, 14);
            strcpy( ele[inp_ele_num].name, inp_ele_name_limited.c_str() );

            show_in_define(inp_ele_num, ele[inp_ele_num].name );
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "||  Element Symbol(Without Spaces, Maximum 3 Characters): "; 
                cin >> inp_ele_symb;
            string inp_ele_symb_str;
            inp_ele_symb_str = (string) inp_ele_symb;
            string inp_ele_symb_limited = inp_ele_symb_str.substr(0, 2);
            strcpy( ele[inp_ele_num].symbol, inp_ele_symb_limited.c_str() );

    
            do{
            show_in_define(inp_ele_num, ele[inp_ele_num].name, ele[inp_ele_num].symbol);
            std::cout << "\n";
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cout << "||  Element Weight: "; 
                    cin >> inp_ele_weight;
            } while( wrong_weight(inp_ele_weight) );
            ele[inp_ele_num].weight = inp_ele_weight;

            do{
                show_in_define(inp_ele_num, ele[inp_ele_num].name,
                            ele[inp_ele_num].symbol, inp_ele_weight);
                std::cout << "\n";
                cout << "||  Element State(1:Gas | 2:Liquid | 3:Solid): "; 
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cin >> inp_ele_state;
            } while ( wrong_state(inp_ele_state) );
            ele[inp_ele_num].state = inp_ele_state;

            show_in_define(inp_ele_num, ele[inp_ele_num].name,
                             ele[inp_ele_num].symbol, inp_ele_weight, inp_ele_state);
            cout << "||  Element Attribute(Maximum 50 Characters): "; 
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                cin.getline(inp_ele_att, 50);
            //Converting to string to use SUBSTR and converting back to char[] to save it
            string inp_ele_att_str;
            inp_ele_att_str = (string) inp_ele_att;
            string inp_ele_att_limited = inp_ele_att_str.substr(0, 49);
            strcpy( ele[inp_ele_num].attribute, inp_ele_att_limited.c_str() );

            show_in_define(inp_ele_num, ele[inp_ele_num].name,
                            ele[inp_ele_num].symbol, inp_ele_weight,
                            inp_ele_state, ele[inp_ele_num].attribute );
            
            

            ele[inp_ele_num].defined = true;
            // cout << number_of_elements << "--------";
            cout << "--   Well done! Element declaired successfully;   --\n";
            sleep(1);
            cout  << "To Show it Please Enter 5 or any key To Show Main Menu :  ";
            int z;
                cin >> z;
            if( z == 5 ){
                system("clear");
                show_in_define(inp_ele_num, inp_ele_name,
                inp_ele_symb, inp_ele_weight, inp_ele_state, inp_ele_att);
                sleep(3);      
            }
        }
    }

//SHOW ALL
    if(input == 2){
        system("clear");
        show_all(ele);
        sleep(2);
        cout << "Press 0 To Show Main Menu And 1 To Export in a File: ";
        int x;
        cin >> x;
        if(x == 1){
            ofstream myfile;
            myfile.open( "Elements.txt" );
            for(int i = 0; i < 118 ; i++){
                if( ele[i].defined == false )
                    continue;
                myfile<<"====================================================="<<endl;
                myfile << "||  The Element Number is: " << ele[i].elementNumber << endl;
                myfile << "||  Name and Symbol: " << ele[i].name << 
                " And "  << ele[i].symbol << endl;
                myfile << "||  Weight: " << ele[i].weight << endl;
                switch (ele[i].state){
                    case 1 :
                        myfile << "||  State: Gas " << endl; 
                        break;
                    case 2 :
                        myfile << "||  State: Liquid " << endl; 
                        break;
                    case 3 :
                        myfile << "||  State: Solid " << endl; 
                        break;
                    default:
                    myfile << "||  State has been set wrong or not set yet." << endl;
                        break;
                }
                myfile << "||  Attribute: " << ele[i].attribute << endl;
            }
            myfile<<"====================================================="<<endl;
;
            myfile.close();
        }
        system("clear");
    }

//SEARCH ---------------------------------------------------------
    if( input == 3 ){
        show_search();
        short int z;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin >> z;
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        // 1:Name |2:Element Number |3:Symbol |4:Weight |5:State
        
        // Search : 1:Name
        int gh;
        while( z == 1 ){
            show_search_name();
            char zinput[15];
            cin >> zinput;
            if( strcmp(zinput, "0") == 0 )
                break;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            to_lowercase( zinput );
            int selected_by_search = search_by_name(zinput, ele);
            
            if( selected_by_search == -404 ){
                cout << "Enter 1 To Search Another or 0 To Main Menu.\n";
                cout << "  >> ";
                do {
                    cin >> gh;
                    cerr << "-- Invalid Input! ONLY 1(Search Another) OR 0(Main Menu). -- " << endl;
                    cout << " >> ";
                } while (gh != 0   &&   gh != 1 );
                    if( gh == 0 ){
                        break;
                    } else if( gh == 1 ){
                        continue;
                    }
            }
            sleep(2);
            system("clear");
            show_selected(selected_by_search, ele);
            cout << "What Do You Want To Edit From This Element?(0 To main Menu)" << endl;
            cout << "1:Name |2:Element Number |3:Symbol |4:Weight |5:State" << endl;
            cout << "  >> ";
            int intedit;
            cin >> intedit;
            if( intedit == 0)
                break;
            if( intedit == 1 ){
                char zz[15];
                cout << "Enter New Name: >> "; 
                cin >> zz;
                set_element_name(selected_by_search, zz, ele);
                sleep(2);
                }
            else if( intedit == 2 ){
                int x;
                cout << "Enter New Element Number: >>";
                cin >> x;
                set_elementNumber(selected_by_search, x, ele);
                sleep(2);
                }
            else if ( intedit == 3 ){
                char xx[3];
                cout << "Enter New Element Symbol: >>";
                cin >> xx;
                set_element_symbol(selected_by_search, xx, ele);
                sleep(2);
                }
            else if( intedit == 4 ){
                float xx;
                cout << "Enter New Element Weight: >>";
                cin >> xx;
                set_element_weight(selected_by_search, xx, ele);
                sleep(2);
                }
            else if ( intedit == 5 ){
                int x;
                cout << "Enter New Element State: >>";
                cin >> x;
                set_element_state(selected_by_search, x, ele);
                sleep(2);
                }

        }

        //Search : 2:Element Number
        short int error_elementNumber = 0, selected_by_search, hh;
        while ( z == 2 && error_elementNumber == 0){
            show_search_elementNumber();
            cin >> hh;
            if( hh == 0 )
                break;
            selected_by_search = search_by_elementNumber(hh, ele);
            if ( selected_by_search == 503 ){
                continue;
            } 
            else if ( selected_by_search == -404){
                cout << "Enter 1 To Search Another or 0 To Main Menu.\n";
                cout << "  >> ";
                do {
                    cin >> hh;
                    cerr << "-- Invalid Input! ONLY 1(Search Another) OR 0(Main Menu). -- " << endl;
                    cout << " >> ";
                } while (hh != 0   &&   hh != 1 );
                if( hh == 0 ){
                    error_elementNumber = 1;
                    break;
                } else if( hh == 1 )
                    continue;
            }
            //Edit Elementumber Selected by Element-Number-Search
            system("clear");
            show_selected(selected_by_search, ele);
            cout << "What Do You Want To Edit From This Element?(0 To main Menu)" << endl;
            cout << "1:Name |2:Element Number |3:Symbol |4:Weight |5:State" << endl;
            cout << "  >> ";
            int intedit;
            cin >> intedit;
            if ( intedit == 0 )
                break;
            if( intedit == 1 ){
                char zz[15];
                cout << "Enter New Name: >> "; 
                cin >> zz;
                set_element_name(selected_by_search, zz, ele);
                sleep(2);    
            }
            else if( intedit == 2 ){
                int x;
                cout << "Enter New Element Number: >>";
                cin >> x;
                set_elementNumber(selected_by_search, x, ele);
                sleep(2);    
            }
            else if ( intedit == 3 ){
                char xx[3];
                cout << "Enter New Element Symbol: >>";
                cin >> xx;
                set_element_symbol(selected_by_search, xx, ele);
                sleep(2);    
            }
            else if( intedit == 4 ){
                float xx;
                cout << "Enter New Element Weight: >>";
                cin >> xx;
                set_element_weight(selected_by_search, xx, ele);
                sleep(2);    
            }
            else if ( intedit == 5 ){
                int x;
                cout << "Enter New Element State: >>";
                cin >> x;
                set_element_state(selected_by_search, x, ele);
                sleep(2);    
            }
        }

        while( z == 3 ){
            system("clear");
            show_search_symbol();
            char sinput[15];
                cin >> sinput;
            if( strcmp(sinput, "0") == 0 )
                break;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            to_lowercase( sinput );
            selected_by_search = search_by_symbol(sinput, ele);
            int rh;
            if ( selected_by_search == -404 ){
                cout << "Enter 1 To Search Another or 0 To Main Menu.\n";
                cout << "  >> ";
                do {
                    cin >> rh;
                    cerr << "-- Invalid Input! ONLY 1(Search Another) OR 0(Main Menu). -- " << endl;
                    cout << " >> ";
                } while (rh != 0   &&   rh != 1 );
                if( rh == 0 ){
                    break;
                } else if( rh == 1 ){
                    continue;
                }
            }
            system("clear");
            show_selected(selected_by_search, ele);
            cout << "What Do You Want To Edit From This Element?(0 To main Menu)" << endl;
            cout << "1:Name |2:Element Number |3:Symbol |4:Weight |5:State" << endl;
            cout << "  >> ";
            int intedit;
            cin >> intedit;
            if( intedit == 0 )
                break;
            else if( intedit == 1 ){
                char zz[15];
                cout << "Enter New Name: >> "; 
                cin >> zz;
                set_element_name(selected_by_search, zz, ele);
                sleep(2);    
            }
            else if( intedit == 2 ){
                int x;
                cout << "Enter New Element Number: >>";
                cin >> x;
                set_elementNumber(selected_by_search, x, ele);
                sleep(2);    
            }
            else if ( intedit == 3 ){
                char xx[3];
                cout << "Enter New Element Symbol: >>";
                cin >> xx;
                set_element_symbol(selected_by_search, xx, ele);
                sleep(2);    
            }
            else if( intedit == 4 ){
                float xx;
                cout << "Enter New Element Weight: >>";
                cin >> xx;
                set_element_weight(selected_by_search, xx, ele);
                sleep(2);    
            }
            else if ( intedit == 5 ){
                int x;
                cout << "Enter New Element State: >>";
                cin >> x;
                set_element_state(selected_by_search, x, ele);
                sleep(2);    
            }


           
        }

        if( z == 4 || z == 5 ){
            cout << "--- Coming soon..! ---" << endl;
            sleep(3);
        }
        /*
        int error_weight = 0;
        while( z == 4 && error_weight == 0 ){
            show_search_weight();
            float winput;
                cin >> winput;
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            selected_by_search = search_by_weight(winput, ele, number_of_elements);
            if ( selected_by_search == 503 ){
                continue;
            }
            if ( selected_by_search == -404 ){
                cout << "Enter 1 To Search Another or 0 To Main Menu.\n";
                cout << "  >> ";
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cin >> hh;
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                if( hh == 0 ){
                    error_symbol = 1;
                    break;
                } else if( hh == 1 ){
                    continue;
                }
                else {
                    show_search_weight_selected(winput);        

                }
            }
        }*/
    }

        if( input == 4 ){
            system("clear");
            cout << "Elements Have Been Sorted Automatically, Nothing to do...\n";
            sleep(3);
            system("clear");
        }
}

return 0;
}