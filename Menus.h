//
// Created by chu on 11/13/2018.
//

#ifndef DESTA_FINAL_PROJECT_BINARY_TREE_MENUS_H
#define DESTA_FINAL_PROJECT_BINARY_TREE_MENUS_H
#include <iostream>
#include "Database.h"



class Menus {
    Database dataBase;


public:
    void display_main_menu();
    void displayMenu_data_set_menu();
    //*************** ACTOR MENU ***************
    void displayMenu_actor_dataset_menu();
    void displayMenu_actor_search_menu();
    void displayMenu_actor_sort_menu();

    //****************** MOVIE MENU******************
    void displayMenu_picture_dataset_menu();
    void displayMenu_picture_search_menu();
    void displayMenu_picture_sort_menu();
    //****************** Nominations MENU******************
    void displayMenu_Nominations_dataset_menu();
    void displayMenu_Nominations_search_menu();
    void displayMenu_Nominations_sort_menu();

};


#endif //DESTA_FINAL_PROJECT_BINARY_TREE_MENUS_H
