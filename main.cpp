#include <iostream>
#include "Menus.h"
using namespace std;





int main() {
    cout<<"****************************************************************************"<<endl;
    cout<<"****************                                        ********************"<<endl;
    cout<<"****************   WELCOME TO MOVIE DATABASE            ********************"<<endl;
    cout<<"****************                                        ********************"<<endl;
    cout<<"****************************************************************************"<<endl;
    Menus menus;
    menus.display_main_menu();

    return 0;
}