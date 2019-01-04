//
// Created by chu on 11/13/2018.
//

#include "Menus.h"

void Menus::display_main_menu(){
    int choose;
    cout<<"******************** WELCOME TO MAIN MENU **************************"<<endl;
    cout<<"Please choose the options"<<endl;
    cout<<"1:-List type of data set available to work on."<<endl;
    cout<<"2:-Exit the program."<<endl;
    bool is_valide_input=true;
    while(is_valide_input) {

        cin >> choose;

        if(cin.fail()){
            cin.clear();
            cin.ignore();
            cout<<"\n&&&&&&&&&&&&&  Invalid data.. Please Enter the exact number choice &&&&&&&&&&&&&&&&&&\n\n"<<endl;
        } else if((choose == 1) || (choose == 2))
        {
            is_valide_input=false;
        } else{
            cout<<"\n&&&&&&&&&&&&&  Invalid data.. Please Enter the exact number choice &&&&&&&&&&&&&&&&&&\n\n"<<endl;

        }


    }
    switch (choose)
    {
        case 1:
            displayMenu_data_set_menu();
            break;
        case 2:
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
    cout<<"2:- Picture database"<<endl;
    cout<<"3:- Nominations database"<<endl;
    cout<<"4:- Back to list of data set menu"<<endl;
    cout<<"5:->Exit the program"<<endl;
    bool is_valide_input=true;
    while(is_valide_input) {

        cin >> choose;

        if(cin.fail()){
            cin.clear();
            cin.ignore();
            cout<<"\n&&&&&&&&&&&&&  Invalid data.. Please Enter the exact number choice &&&&&&&&&&&&&&&&&&\n\n"<<endl;
        } else if((choose == 1) || (choose == 2) || (choose == 3) || (choose == 4) || (choose == 5))
        {
            is_valide_input=false;
        } else{
            cout<<"\n&&&&&&&&&&&&&  Invalid data.. Please Enter the exact number choice &&&&&&&&&&&&&&&&&&\n\n"<<endl;

        }


    }
    switch (choose)
    {
        case 1:
            dataBase.create_bst_for_actor();             //this will add the file to binary search tree
            dataBase.writ_actor_bst_tofile();            //this will load binary search tree to vector
            displayMenu_actor_dataset_menu();
            break;
        case 2:
            dataBase.create_bst_for_picture_class();
            dataBase.write_picture_bst_to_vector();
            displayMenu_picture_dataset_menu();
            break;
        case 3:
            dataBase.create_bst_for_Nominations();
            dataBase.writ_Nominations_bst_tofile();
            displayMenu_Nominations_dataset_menu();
            break;
        case 4:
            display_main_menu();
            break;
        case 5:
            exit(1);
        default:
            exit(1);

    }

}
//******************************************************  START OF ACTOR DATA SET MENU ***********************************************
void Menus::displayMenu_actor_dataset_menu(){
    int choose;
    cout<<"************  WELCOME TO ACTOR DATA SET*************"<<endl;
    cout<<"Please choose a task from the  options"<<endl;
    cout<<"1:- Add a record to the data set"<<endl;
    cout<<"2:- Update a record from the data set"<<endl;
    cout<<"3:- Delete a record from the data set"<<endl;
    cout<<"4:- Search a record from data set"<<endl;
    cout<<"5:- Sort the data set"<<endl;
    cout<<"6:- Get the latest actor data set."<<endl;
    cout<<"7:- Back to the list of data sets"<<endl;
    cout<<"8:- Back to main menu"<<endl;
    cout<<"9:- Exit the program"<<endl;
    bool is_valide_input=true;
    while(is_valide_input) {

        cin >> choose;

        if(cin.fail()){
            cin.clear();
            cin.ignore();
            cout<<"\n&&&&&&&&&&&&&  Invalid data.. Please Enter the exact number choice &&&&&&&&&&&&&&&&&&\n\n"<<endl;
        } else if((choose == 1) || (choose == 2) || (choose == 3) || (choose == 4) || (choose == 5)||(choose == 6) || (choose == 7) || (choose == 8) || (choose == 9))
        {
            is_valide_input=false;
        } else{
            cout<<"\n&&&&&&&&&&&&&  Invalid data.. Please Enter the exact number choice &&&&&&&&&&&&&&&&&&\n\n"<<endl;

        }


    }
    switch (choose)
    {
        case 1:
            dataBase.addDataToActorDataSet();
            cout<<"\n\n"<<endl;
            displayMenu_actor_dataset_menu();
            break;
        case 2:
            dataBase.update_a_record();
            cout<<"\n\n"<<endl;
            displayMenu_actor_dataset_menu();
            break;
        case 3:
            dataBase.delete_record();
            cout<<"\n\n"<<endl;
            displayMenu_actor_dataset_menu();
            break;
        case 4:
            displayMenu_actor_search_menu();

            break;
        case 5:
            displayMenu_actor_sort_menu();
            break;

        case 6:
            dataBase.writfile();
            cout<<"\n\n"<<endl;
            displayMenu_actor_dataset_menu();
            break;
        case 7:
            displayMenu_actor_dataset_menu();
            break;
        case 8:
            display_main_menu();
            break;
        case 9:
            exit(1);
        default:
            exit(1);

    }

}

void Menus::displayMenu_actor_search_menu() {
    int choose;
    cout<<"********** WELCOME TO ACTOR DATA SET SEARCH MENU***********"<<endl;
    cout<<"Please choose a task"<<endl;
    cout<<"1:- Search a record"<<endl;
    cout<<"2:- Back to actor data set menu."<<endl;
    cout<<"3:- Back to data sets menu."<<endl;
    cout<<"4:- Back to main menu."<<endl;
    cout<<"5:- Exit the program."<<endl;

    bool is_valide_input=true;
    while(is_valide_input) {

        cin >> choose;

        if(cin.fail()){
            cin.clear();
            cin.ignore();
            cout<<"\n&&&&&&&&&&&&&  Invalid data.. Please Enter the exact number choice &&&&&&&&&&&&&&&&&&\n\n"<<endl;
        } else if((choose == 1) || (choose == 2) || (choose == 3) || (choose == 4) || (choose == 5))
        {
            is_valide_input=false;
        } else{
            cout<<"\n&&&&&&&&&&&&&  Invalid data.. Please Enter the exact number choice &&&&&&&&&&&&&&&&&&\n\n"<<endl;

        }


    }
    switch (choose){
        case 1:
            dataBase.search_a_record();
            displayMenu_actor_search_menu();
            break;
        case 2:
            displayMenu_actor_dataset_menu();
            break;
        case 3:
            displayMenu_data_set_menu();
            break;
        case 4:
            display_main_menu();
            break;
        case 5:
            exit(1);
        default:
            exit(1);

    }

}

void Menus::displayMenu_actor_sort_menu() {
    int choose;
    cout<<"************** WELCOME TO ACTOR DATA SET SORT MENU ************************"<<endl;
    cout<<"Please choose a task.."<<endl;

    cout<<"1:- Sort by year"<<endl;
    cout<<"2:- Sort by award."<<endl;
    cout<<"3:- Sort by winner"<<endl;
    cout<<"4:- Sort by name"<<endl;
    cout<<"5:- Sort by file"<<endl;
    cout<<"6:- Back to actor search menu."<<endl;
    cout<<"7:- Back to actor data set menu."<<endl;
    cout<<"8:- Back to data sets menu."<<endl;
    cout<<"9:- Back to main menu."<<endl;
    cout<<"10:- Exit the program."<<endl;

    bool is_valide_input=true;
    while(is_valide_input) {

        cin >> choose;

        if(cin.fail()){
            cin.clear();
            cin.ignore();
            cout<<"\n&&&&&&&&&&&&&  Invalid data.. Please Enter the exact number choice &&&&&&&&&&&&&&&&&&\n\n"<<endl;
        } else if((choose == 1) || (choose == 2) || (choose == 3) || (choose == 4) || (choose == 5)||(choose == 6) || (choose == 7) || (choose == 8) || (choose == 9)|| (choose == 10))
        {
            is_valide_input=false;
        } else{
            cout<<"\n&&&&&&&&&&&&&  Invalid data.. Please Enter the exact number choice &&&&&&&&&&&&&&&&&&\n\n"<<endl;

        }


    }

    switch (choose){
        case 1:
            dataBase.sortActorDataByType(1);
            displayMenu_actor_sort_menu();
            break;
        case 2:
            dataBase.sortActorDataByType(2);
            displayMenu_actor_sort_menu();
            break;
        case 3:
            dataBase.sortActorDataByType(3);
            displayMenu_actor_sort_menu();
            break;
        case 4:
            dataBase.sortActorDataByType(4);
            displayMenu_actor_sort_menu();
            break;
        case 5:
            dataBase.sortActorDataByType(5);
            displayMenu_actor_sort_menu();
            break;

        case 6:
            displayMenu_actor_search_menu();
            break;
        case 7:
            displayMenu_actor_dataset_menu();
            break;
        case 8:
            displayMenu_data_set_menu();
            break;
        case 9:
            display_main_menu();
            break;
        case 10:
            exit(1);
        default:
            exit(1);
    }

}
//****************************************************** END OF ACTOR DATA SET MENU ***********************************************
//**********************************************************  MOVIE MENU *************************************************
void Menus::displayMenu_picture_dataset_menu(){
    int choose;
    cout<<"************  WELCOME TO PICTURE DATA SET*************"<<endl;
    cout<<"Please choose a task from the  options"<<endl;
    cout<<"1:- Add a record to picture  data set"<<endl;
    cout<<"2:- Update a picture record from the data set"<<endl;
    cout<<"3:- Delete a picture record from the data set"<<endl;
    cout<<"4:- Search a picture record from data set"<<endl;
    cout<<"5:- Sort the picture data set"<<endl;
    cout<<"6:- Get the latest picture data set."<<endl;
    cout<<"7:- Back to the list of data sets"<<endl;
    cout<<"8:- Back to main menu"<<endl;
    cout<<"9:- Exit the program"<<endl;

    bool is_valide_input=true;
    while(is_valide_input) {

        cin >> choose;

        if(cin.fail()){
            cin.clear();
            cin.ignore();
            cout<<"\n&&&&&&&&&&&&&  Invalid data.. Please Enter the exact number choice &&&&&&&&&&&&&&&&&&\n\n"<<endl;
        } else if((choose == 1) || (choose == 2) || (choose == 3) || (choose == 4) || (choose == 5)||(choose == 6) || (choose == 7) || (choose == 8) || (choose == 9))
        {
            is_valide_input=false;
        } else{
            cout<<"\n&&&&&&&&&&&&&  Invalid data.. Please Enter the exact number choice &&&&&&&&&&&&&&&&&&\n\n"<<endl;

        }


    }

    switch (choose)
    {
        case 1:
            dataBase.addDataToPictureDataSet();
            cout<<"\n\n"<<endl;
            displayMenu_picture_dataset_menu();
            break;
        case 2:
            dataBase.update_a_picture_record();
            cout<<"\n\n"<<endl;
            displayMenu_picture_dataset_menu();
            break;
        case 3:
            dataBase.delete_record_prcture();
            cout<<"\n\n"<<endl;
            displayMenu_picture_dataset_menu();
            break;
        case 4:
            displayMenu_picture_search_menu();

            break;
        case 5:
            displayMenu_picture_sort_menu();
            break;

        case 6:
            dataBase.writfile_picture_data_to_new_file();
            cout<<"\n\n"<<endl;
            displayMenu_picture_dataset_menu();
            break;
        case 7:
            displayMenu_data_set_menu();
            break;
        case 8:
            display_main_menu();
            break;
        case 9:
            exit(1);
        default:
            exit(1);

    }

}

void Menus::displayMenu_picture_search_menu(){
    int choose;
    cout<<"********** WELCOME TO PICTURE DATA SET SEARCH MENU***********"<<endl;
    cout<<"Please choose a task"<<endl;
    cout<<"1:- Search a picture record"<<endl;
    cout<<"2:- Back to picture data set menu."<<endl;
    cout<<"3:- Back to data sets menu."<<endl;
    cout<<"4:- Back to main menu."<<endl;
    cout<<"5:- Exit the program."<<endl;

    bool is_valide_input=true;
    while(is_valide_input) {

        cin >> choose;

        if(cin.fail()){
            cin.clear();
            cin.ignore();
            cout<<"\n&&&&&&&&&&&&&  Invalid data.. Please Enter the exact number choice &&&&&&&&&&&&&&&&&&\n\n"<<endl;
        } else if((choose == 1) || (choose == 2) || (choose == 3) || (choose == 4) || (choose == 5))
        {
            is_valide_input=false;
        } else{
            cout<<"\n&&&&&&&&&&&&&  Invalid data.. Please Enter the exact number choice &&&&&&&&&&&&&&&&&&\n\n"<<endl;

        }


    }

    switch (choose){
        case 1:
            dataBase.search_a_picture_record();
            displayMenu_picture_search_menu();
            break;
        case 2:
            displayMenu_picture_dataset_menu();
            break;
        case 3:
            displayMenu_data_set_menu();
            break;
        case 4:
            display_main_menu();
            break;
        case 5:
            exit(1);
        default:
            exit(1);

    }

}

void Menus::displayMenu_picture_sort_menu(){
    int choose;
    cout<<"************** WELCOME TO PICTURE DATA SET SORT MENU ************************"<<endl;
    cout<<"Please choose a task.."<<endl;

    cout<<"1:- Sort by Name"<<endl;
    cout<<"2:- Sort by Year."<<endl;
    cout<<"3:- Sort by Nominations"<<endl;
    cout<<"4:- Sort by Rating"<<endl;
    cout<<"5:- Sort by Duration"<<endl;
    cout<<"6:- Sort by Genre1"<<endl;
    cout<<"7:- Sort by Genre2"<<endl;
    cout<<"8:- Sort by Release"<<endl;
    cout<<"9:- Sort by Metacritic"<<endl;
    cout<<"10:- Sort by Synopsis"<<endl;
    cout<<"11:- Back to picture data set menu."<<endl;
    cout<<"12:- Back to data sets menu."<<endl;
    cout<<"13:- Back to main menu."<<endl;
    cout<<"14:- Exit the program."<<endl;


    bool is_valide_input=true;
    while(is_valide_input) {

        cin >> choose;

        if(cin.fail()){
            cin.clear();
            cin.ignore();
            cout<<"\n&&&&&&&&&&&&&  Invalid data.. Please Enter the exact number choice &&&&&&&&&&&&&&&&&&\n\n"<<endl;
        } else if((choose == 1) || (choose == 2) || (choose == 3) || (choose == 4) || (choose == 5)||(choose == 6) || (choose == 7) || (choose == 8) || (choose == 9)|| (choose == 10)||(choose == 11) || (choose == 12) || (choose == 13) || (choose == 14))
        {
            is_valide_input=false;
        } else{
            cout<<"\n&&&&&&&&&&&&&  Invalid data.. Please Enter the exact number choice &&&&&&&&&&&&&&&&&&\n\n"<<endl;

        }


    }


    switch (choose){

        case 1:
            dataBase.sortPictutreDataByType(1);
            displayMenu_picture_sort_menu();
            break;
        case 2:
            dataBase.sortPictutreDataByType(2);
            displayMenu_picture_sort_menu();
            break;
        case 3:
            dataBase.sortPictutreDataByType(3);
            displayMenu_picture_sort_menu();
            break;
        case 4:
            dataBase.sortPictutreDataByType(4);
            displayMenu_picture_sort_menu();
            break;
        case 5:
            dataBase.sortPictutreDataByType(5);
            displayMenu_picture_sort_menu();
            break;
        case 6:
            dataBase.sortPictutreDataByType(6);
            displayMenu_picture_sort_menu();
            break;
        case 7:
            dataBase.sortPictutreDataByType(7);
            displayMenu_picture_sort_menu();
            break;
        case 8:
            dataBase.sortPictutreDataByType(8);
            displayMenu_picture_sort_menu();
            break;
        case 9:
            dataBase.sortPictutreDataByType(9);
            displayMenu_picture_sort_menu();
            break;
        case 10:
            dataBase.sortPictutreDataByType(10);
            displayMenu_picture_sort_menu();
            break;
        case 11:
            displayMenu_picture_dataset_menu();
            break;
        case 12:
            displayMenu_data_set_menu();
            break;
        case 13:
            display_main_menu();
            break;
        case 14:
            exit(1);
        default:
            exit(1);
    }

}
//********************************************************END OF  PICTURE Data set ****************************************************
//******************************************************** Nominations Data set ****************************************************
void Menus::displayMenu_Nominations_dataset_menu() {
    int choose;
    cout<<"************  WELCOME TO Nominations DATA SET*************"<<endl;
    cout<<"Please choose a task from the  options"<<endl;
    cout<<"1:- Add a record to the Nominations data set"<<endl;
    cout<<"2:- Update a record from the Nominations data set"<<endl;
    cout<<"3:- Delete a record from the Nominations data set"<<endl;
    cout<<"4:- Search a record from Nominations data set"<<endl;
    cout<<"5:- Sort the Nominations data set"<<endl;
    cout<<"6:- Get the latest Nominations data set."<<endl;
    cout<<"7:- Back to the list of data sets"<<endl;
    cout<<"8:- Back to main menu"<<endl;
    cout<<"9:- Exit the program"<<endl;

    bool is_valide_input=true;
    while(is_valide_input) {

        cin >> choose;

        if(cin.fail()){
            cin.clear();
            cin.ignore();
            cout<<"\n&&&&&&&&&&&&&  Invalid data.. Please Enter the exact number choice &&&&&&&&&&&&&&&&&&\n\n"<<endl;
        } else if((choose == 1) || (choose == 2) || (choose == 3) || (choose == 4) || (choose == 5)||(choose == 6) || (choose == 7) || (choose == 8) || (choose == 9))
        {
            is_valide_input=false;
        } else{
            cout<<"\n&&&&&&&&&&&&&  Invalid data.. Please Enter the exact number choice &&&&&&&&&&&&&&&&&&\n\n"<<endl;

        }


    }

    switch (choose)
    {
        case 1:
            dataBase.addDataToNominationsDataSet();
            cout<<"\n\n"<<endl;
            displayMenu_Nominations_dataset_menu();
            break;
        case 2:
            dataBase.update_a_Nominations_record();
            cout<<"\n\n"<<endl;
            displayMenu_Nominations_dataset_menu();
            break;
        case 3:
            dataBase.delete_record_Nominations();
            cout<<"\n\n"<<endl;
            displayMenu_Nominations_dataset_menu();
            break;
        case 4:
            displayMenu_Nominations_search_menu();

            break;
        case 5:
            displayMenu_Nominations_sort_menu();
            break;

        case 6:
            dataBase.writfile_Nominations_data_to_new_file();
            cout<<"\n\n"<<endl;
            displayMenu_Nominations_dataset_menu();
            break;
        case 7:
            displayMenu_data_set_menu();
            break;
        case 8:
            display_main_menu();
            break;
        case 9:
            exit(1);
        default:
            exit(1);

    }


}

void Menus::displayMenu_Nominations_search_menu() {
    cout<<"********** WELCOME TO Nominations  DATA SET SEARCH MENU***********"<<endl;


        int choose;


        cout<<"Please choose a task"<<endl;
        cout<<"1:- Search a record"<<endl;
        cout<<"2:- Back to actor data set menu."<<endl;
        cout<<"3:- Back to data sets menu."<<endl;
        cout<<"4:- Back to main menu."<<endl;
        cout<<"5:- Exit the program."<<endl;

        bool is_valide_input=true;
    while(is_valide_input) {

        cin >> choose;

        if(cin.fail()){
            cin.clear();
            cin.ignore();
            cout<<"\n&&&&&&&&&&&&&  Invalid data.. Please Enter the exact number choice &&&&&&&&&&&&&&&&&&\n\n"<<endl;
        } else if((choose == 1) || (choose == 2) || (choose == 3) || (choose == 4) || (choose == 5))
        {
            is_valide_input=false;
        } else{
            cout<<"\n&&&&&&&&&&&&&  Invalid data.. Please Enter the exact number choice &&&&&&&&&&&&&&&&&&\n\n"<<endl;

        }


    }








        switch (choose) {
                case 1:
                    dataBase.search_a_Nominations_record();
                    displayMenu_Nominations_search_menu();
                    break;
                case 2:
                    displayMenu_Nominations_dataset_menu();
                    break;
                case 3:
                    displayMenu_data_set_menu();
                    break;
                case 4:
                    display_main_menu();
                    break;
                case 5:
                    exit(1);
                default:break;
            }








}

void Menus::displayMenu_Nominations_sort_menu() {
    int choose;
    cout<<"************** WELCOME TO Nominations DATA SET SORT MENU ************************"<<endl;
    cout<<"Please choose a task.."<<endl;

    cout<<"1:- Sort by year"<<endl;
    cout<<"2:- Sort by award."<<endl;
    cout<<"3:- Sort by winner"<<endl;
    cout<<"4:- Sort by name"<<endl;
    cout<<"5:- Sort by file"<<endl;
    cout<<"6:- Back to Nominations search menu."<<endl;
    cout<<"7:- Back to Nominations data set menu."<<endl;
    cout<<"8:- Back to data sets menu."<<endl;
    cout<<"9:- Back to main menu."<<endl;
    cout<<"10:- Exit the program."<<endl;


    bool is_valide_input=true;
    while(is_valide_input) {

        cin >> choose;

        if(cin.fail()){
            cin.clear();
            cin.ignore();
            cout<<"\n&&&&&&&&&&&&&  Invalid data.. Please Enter the exact number choice &&&&&&&&&&&&&&&&&&\n\n"<<endl;
        } else if((choose == 1) || (choose == 2) || (choose == 3) || (choose == 4) || (choose == 5)||(choose == 6) || (choose == 7) || (choose == 8) || (choose == 9) || (choose == 10))
        {
            is_valide_input=false;
        } else{
            cout<<"\n&&&&&&&&&&&&&  Invalid data.. Please Enter the exact number choice &&&&&&&&&&&&&&&&&&\n\n"<<endl;

        }


    }
    switch (choose){
        case 1:
            dataBase.sortNominationsDataByType(1);
            displayMenu_Nominations_sort_menu();
            break;
        case 2:
            dataBase.sortNominationsDataByType(2);
            displayMenu_Nominations_sort_menu();
            break;
        case 3:
            dataBase.sortNominationsDataByType(3);
            displayMenu_Nominations_sort_menu();
            break;
        case 4:
            dataBase.sortNominationsDataByType(4);
            displayMenu_Nominations_sort_menu();
            break;
        case 5:
            dataBase.sortNominationsDataByType(5);
            displayMenu_Nominations_sort_menu();
            break;

        case 6:
            displayMenu_Nominations_search_menu();
            break;
        case 7:
            displayMenu_Nominations_dataset_menu();
            break;
        case 8:
            displayMenu_data_set_menu();
            break;
        case 9:
            display_main_menu();
            break;
        case 10:
            exit(1);
        default:
            exit(1);
    }

}
