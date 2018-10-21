//
// Created by chu on 10/21/2018.
//

#include "Menus.h"
#include <conio.h>


void Menus::display_main_menu(){
    int choose;
    cout<<"******************** WELCOME TO MAIN MENU **************************"<<endl;
    cout<<"Please choose the options"<<endl;
    cout<<"1:-List type of data set available to work on."<<endl;
    cout<<"2:-List to display the updated type of data set."<<endl;
    cout<<"3:-Exit the program."<<endl;
    cin>>choose;
    switch (choose)
    {
        case 1:
            displayMenu_data_set_menu();
            system("clear");
            break;
        case 2:
            cout<<"display updated data set menu is in progress..."<<endl;
            break;
        case 3:
            exit(1);
        default:
            exit(1);

    }

}

void Menus::displayMenu_data_set_menu() {
    int choose;
    cout<<"****************** WELCOME TO THE LIST OF DATA SETS *********"<<endl;
    cout<<"Please choose the type of data set to work on."<<endl;
    cout<<"1:- Actor database"<<endl;
    cout<<"2:- Movie database"<<endl;
    cout<<"3:- Back to list of data set menu"<<endl;
    cout<<"4:->Exit the program"<<endl;
    cin>>choose;
    switch (choose)
    {
        case 1:
            displayMenu_actor_dataset_menu();
            system("cls");
            break;
        case 2:
                cout<<"Movie data set menu is in progress..."<<endl;
            break;
        case 3:
            display_main_menu();
            break;
        case 4:
            exit(1);
        default:
            exit(1);

    }
    system("CLS");
}
void Menus::displayMenu_actor_dataset_menu(){
    int choose;
    cout<<"************  WELCOME TO ACTOR DATA SET*************"<<endl;
    cout<<"Please choose a task from the  options"<<endl;
    cout<<"1:- Add a record to the data set"<<endl;
    cout<<"2:- Update a record from the data set"<<endl;
    cout<<"3:- Delete a record from the data set"<<endl;
    cout<<"4:- Search a record from data set"<<endl;
    cout<<"5:- Sort the data set"<<endl;
    cout<<"6:- Back to the list of data sets"<<endl;
    cout<<"7:- Back to main menu"<<endl;
    cout<<"8:- Exit the program"<<endl;
    cin>>choose;
    switch (choose)
    {
        case 1:
            cout<<"Adding record to data set..."<<endl;
            break;
        case 2:
            cout<<"updating a record data set...."<<endl;
            break;
        case 3:
            cout<<"deleting  data set record"<<endl;
            break;
        case 4:
                displayMenu_actor_search_menu();

            break;
        case 5:
                cout<<"Sorting data set.."<<endl;
            break;
        case 6:
            displayMenu_actor_dataset_menu();
            break;
        case 7:
            display_main_menu();
            break;
        case 8:
            exit(1);
        default:
            exit(1);

    }
    system("CLS");
}

void Menus::displayMenu_actor_search_menu() {
    int choose;
    cout<<"********** WELCOME TO ACTOR DATA SET SEARCH MENU***********"<<endl;
    cout<<"Please choose a task"<<endl;
    cout<<"1:- Partial search by.."<<endl;//menu
    cout<<"2:- Complete search by.."<<endl;//menu
    cout<<"3:- Back to actor data set menu."<<endl;
    cout<<"4:- Back to data sets menu."<<endl;
    cout<<"5:- Back to main menu."<<endl;
    cout<<"6:- Exit the program."<<endl;
    cin>>choose;
    switch (choose){
        case 1:
            cout<<"Partial search by menu..."<<endl;
            break;
        case 2:
            cout<<"Complete search by ..menu"<<endl;//menu
            break;
        case 3:
            displayMenu_actor_dataset_menu();
            break;
        case 4:
            displayMenu_data_set_menu();
            break;
        case 5:
            display_main_menu();
            break;
        case 6:
            exit(1);
        default:
            exit(1);

    }
    system("CLS");
}

void Menus::displayMenu_actor_sort_menu() {
    int choose;
    cout<<"************** WELCOME TO ACTOR DATA SET SORT MENU ************************"<<endl;
    cout<<"Please choose a task.."<<endl;
    cout<<"1:- Sort by award."<<endl;
    cout<<"2:- Sort by year"<<endl;
    cout<<"3:- Sort by winner"<<endl;
    cout<<"4:- Sort by name"<<endl;
    cout<<"5:- Sort by file"<<endl;
    cout<<"6:- Back to actor search menu."<<endl;
    cout<<"7:- Back to actor data set menu."<<endl;
    cout<<"8:- Back to data sets menu."<<endl;
    cout<<"9:- Back to main menu."<<endl;
    cout<<"10:- Exit the program."<<endl;
    cin>>choose;

}



