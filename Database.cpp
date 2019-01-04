//
// Created by chu on 11/12/2018.
//

#include "Database.h"
//setting global ID
unsigned int id;     //set id to 99, which will start from 100

//****************************************** LOADING A CSV FILE TO BINARY SEARCH TREE *****************************

void Database::create_bst_for_actor() {
    string yearstring,award,winner,name,film;
    id=99;
    ifstream csvFile("C:\\Users\\chu\\CLionProjects\\Desta_final_project_binary_tree\\actor-actress.csv");
    if(!csvFile.is_open()) cout<<"Error on reading file"<<'\n';

    while(!csvFile.eof()) {

        getline(csvFile, yearstring, ',');
        getline(csvFile, award, ',');
        getline(csvFile, winner, ',');
        getline(csvFile, name, ',');
        getline(csvFile, film, '\n');

        actor.setID(id);
        actor.setAward(award);
        actor.setYear(yearstring);
        actor.setWinner(winner);
        actor.setName(name);
        actor.setFilm(film);

        bsTree.addNode(actor.getName(),actor);

        id++;

    }

    id=99;
}
//******************************************END OF LOADING A CSV FILE TO BINARY SEARCH TREE *****************************
//************************************** VISITING EVERY NODE AND ADDING TO VECTOR ***********************

void Database::writ_actor_bst_tofile() {
    writ_actor_bst_tofile(bsTree.Root());

}
void Database::writ_actor_bst_tofile(Node<Actor, string> *node) {
    if(node== nullptr)
        return;
    writ_actor_bst_tofile(node->Left());
    store(node->Data());
    writ_actor_bst_tofile(node->Right());

}

void Database::store(const Actor&actor1) {
    vector1.push_back(actor1);

}
//**************************************END OF VISITING EVERY NODE AND ADDING TO VECTOR *****************
//**************************************** WRITING VECTOR IN TO FILE ************************************
void Database::writfile() {

    string new_file_name,new_file;
    cout<<"Please enter any file name you want"<<endl;
    cin>>new_file_name;


        //create name
        new_file=new_file_name + ".csv"; // C++11 for std::to_string
        //create file
        std::ofstream file(new_file);
        //then do with file

    string file_path="C:\\Users\\chu\\CLionProjects\\Desta_final_project_binary_tree\\"+new_file;  //create new path
    ofstream tofile(file_path);//pass path
    if(!tofile.is_open()) cout<<"Error on reading file"<<'\n';
    tofile<<"ID ,"<<",  Year  ,"<<"       Award      ,"<<"Winner,"<<"      Name      "<<"     Film        "<<endl;
    for (auto &i : vector1) {
        tofile<<i.getID()<<" , "<<i.getYear()<<" , "<<i.getAward()<<" , "<<i.getWinner()<<" , "<< i.getName()<<" , "<<i.getFilm()<<endl;
    }
    tofile.close();
}
//**************************************** END OF  WRITING VECTOR IN TO FILE ************************************
//******************************************* SEARCH A RECORD ***************************************************
void Database::search_a_record() {
    bool back_to_menu=true;

    while (back_to_menu)
    {

        string user_sreach_string;
        cout<<"Please search any record in the actor database......\n"<<endl;
        cout<<"Enter any string"<<endl;
        cin.ignore();
        getline(cin, user_sreach_string);

        cout<<"\n\nThe data associated with :->  "<<user_sreach_string<<"  is the following below...........\n\n"<<endl;
        //display column names
        cout<<"ID"<<" , "<< "Year" <<" ,      "<< "Award" <<"      ,  "<<  " Winner  "<<",     "<< "   Name "<<"      , "<< "     Film   "<<"\n"<<endl;

        for (iterator=vector1.begin();iterator!=vector1.end();++iterator) {
            if((iterator->getName().substr(0,user_sreach_string.size())== user_sreach_string)||(iterator->getFilm().substr(0,user_sreach_string.size())== user_sreach_string)||(iterator->getWinner().substr(0,user_sreach_string.size())== user_sreach_string)||(iterator->getAward().substr(0,user_sreach_string.size())== user_sreach_string)||(iterator->getYear().substr(0,user_sreach_string.size())== user_sreach_string)){
                cout<<iterator->getID()<<" , " <<iterator->getYear()<<" , "<< iterator->getAward()<<" , "<<iterator->getWinner()<<" , "<< iterator->getName()<<" , "<<iterator->getFilm()<<endl;
            }
        }
        cout<<"\n\n"<<endl;
        cout<<"Press any key to go back to menu........."<<endl;
        getchar();
        back_to_menu=false;
    }


}
//*******************************************END SEARCH A RECORD ****************************************************

//************************************************* SORTING **********************************************
//sort by year
bool sortByYear(const Actor &lhs,const Actor &rhs){
    return lhs.getYear()<rhs.getYear();
}
//sort by award
bool sortByAward(const Actor &lhs,const Actor &rhs){
    return lhs.getAward()<rhs.getAward();
}
//sort by winner
bool sortByWinner(const Actor &lhs,const Actor &rhs){
    return lhs.getWinner()<rhs.getWinner();
}
//sort by name
bool sortByName(const Actor &lhs,const Actor &rhs){
    return lhs.getName()<rhs.getName();
}
//sort by film
bool sortByFilm(const Actor &lhs,const Actor &rhs){
    return lhs.getFilm()<rhs.getFilm();
}


void Database::sortActorDataByType(int type) {
    switch (type)
    {
        case 1:
            //sort by year
            sort(vector1.begin(),vector1.end(),sortByYear);
            break;
        case 2:
            //sort by award
            sort(vector1.begin(),vector1.end(),sortByAward);
            break;
        case 3:
            //sort by winner
            sort(vector1.begin(),vector1.end(),sortByWinner);
            break;
        case 4:
            //sort by name
            sort(vector1.begin(),vector1.end(),sortByName);
            break;
        case 5:
            //sort by film
            sort(vector1.begin(),vector1.end(),sortByFilm);
            break;

        default:break;
    }

}
//********************************************** END OF SORT ***************************************
//************************************************* ADDING DATA **********************************************
void Database::addDataToActorDataSet(){
    string award,yearstring,winner,name,film;
    bool keepAsking=true;

    while (keepAsking){

        cout<<"    "<<endl;

        cout<<"Please enter name actor Year: "<<endl;
        getline(cin,yearstring);
        actor.setName(yearstring);

        cout<<"Please enter name actor award: "<<endl;
        getline(cin,award);
        actor.setName(award);


        cout<<"Please enter name actor name: "<<endl;
        getline(cin,name);
        actor.setName(name);

        cout<<"Please enter name actor winner: "<<endl;
        getline(cin,winner);
        actor.setName(winner);

        cout<<"Please enter name actor film: "<<endl;
        getline(cin,film);
        actor.setName(film);

        actor.setID(actor.getID()+1);  //this will get the last row id and add one to the new record

        vector1.push_back(actor);//add new data in to vector

        char comformation;
        cout<<"The new recored is added"<<endl;
        cout<<"whould you like to add agin:  Y(y)  or  N(n) ";
        cin>>comformation;
        cout<<"\n\n"<<endl;
        keepAsking= comformation == 'N' || comformation == 'n' ? false : true;
    }

    id=99;      //reset id
}


//********************************************** END OF ADDING DATA ***************************************
//************************************************ UPDATING RECORD *****************************************
void Database::update_a_record() {

    bool back_to_menu=true;

    while (back_to_menu) {

        string user_sreach_string;

        cout << "Please search any record in the actor database......\n" << endl;
        cout << "Enter any string" << endl;
        cin.ignore();
        getline(cin, user_sreach_string);

        cout << "\n\nThe data associated with :->  " << user_sreach_string << "  is the following below...........\n\n"<< endl;


        cout<<"ID"<<" , "<< "Year" <<" ,      "<< "Award" <<"      ,  "<<  " Winner  "<<",     "<< "   Name "<<"      , "<< "     Film   "<<"\n"<<endl;

        for (iterator=vector1.begin();iterator!=vector1.end();++iterator) {
            if((iterator->getName().substr(0,user_sreach_string.size())== user_sreach_string)||(iterator->getFilm().substr(0,user_sreach_string.size())== user_sreach_string)||(iterator->getWinner().substr(0,user_sreach_string.size())== user_sreach_string)||(iterator->getAward().substr(0,user_sreach_string.size())== user_sreach_string)||(iterator->getYear().substr(0,user_sreach_string.size())== user_sreach_string)){
                cout<<iterator->getID()<<" , " <<iterator->getYear()<<" , "<< iterator->getAward()<<" , "<<iterator->getWinner()<<" , "<< iterator->getName()<<" , "<<iterator->getFilm()<<endl;
            }
        }
        //take ID and update the record
        int row_id;
        cout<<"Please enter the ID of the row you want to update:-  "<<endl;
        cin>>row_id;

        for (iterator=vector1.begin();iterator!=vector1.end();++iterator)
        {
                if(iterator->getID()==row_id){


                    string type_string;
                    char chiose;
                    cout<<"Would you like to update a Year: Y/y or N/n"<<endl;
                    cin>>chiose;
                    if(chiose=='y'|| chiose=='Y'){
                        cout<<"Enter a year"<<endl;
                        cin.ignore();
                        getline(cin,type_string);
                        actor.setYear(type_string);

                    }
                    cout<<"Would you like to update a Award: Y/y or N/n"<<endl;
                    cin>>chiose;
                    if(chiose=='y'|| chiose=='Y'){
                        cout<<"Enter a Award"<<endl;
                        cin.ignore();
                        getline(cin,type_string);
                        actor.setAward(type_string);

                    }
                    cout<<"Would you like to update a Winner: Y/y or N/n"<<endl;
                    cin>>chiose;
                    if(chiose=='y'|| chiose=='Y'){
                        cout<<"Enter a Winner"<<endl;
                        cin.ignore();
                        getline(cin,type_string);
                        actor.setWinner(type_string);

                    }
                    cout<<"Would you like to update a Name: Y/y or N/n"<<endl;
                    cin>>chiose;
                    if(chiose=='y'|| chiose=='Y'){
                        cout<<"Enter a Name"<<endl;
                        cin.ignore();
                        getline(cin,type_string);
                        actor.setName(type_string);

                    }
                    cout<<"Would you like to update a Film: Y/y or N/n"<<endl;
                    cin>>chiose;
                    if(chiose=='y'|| chiose=='Y'){

                            cout<<"Enter a Film"<<endl;
                            cin.ignore();
                            getline(cin,type_string);
                            actor.setFilm(type_string);

                    }

                }

        }





        cout<<"\n\n"<<endl;
        cout<<"Press any key to go back to menu........."<<endl;
        getchar();
        back_to_menu=false;

    }





}


//************************************************END OF UPDATING RECORD *****************************************
void Database::delete_record() {
    bool back_to_menu=true;

    while (back_to_menu) {

        string user_sreach_string;

        cout << "Please search any record in the actor database......\n" << endl;
        cout << "Enter any string" << endl;
        cin.ignore();
        getline(cin, user_sreach_string);

        cout << "\n\nThe data associated with :->  " << user_sreach_string << "  is the following below...........\n\n"
             << endl;


        cout << "ID" << " , " << "Year" << " ,      " << "Award" << "      ,  " << " Winner  " << ",     " << "   Name "
             << "      , " << "     Film   " << "\n" << endl;

        for (iterator = vector1.begin(); iterator != vector1.end(); ++iterator) {
            if ((iterator->getName().substr(0, user_sreach_string.size()) == user_sreach_string) ||
                (iterator->getFilm().substr(0, user_sreach_string.size()) == user_sreach_string) ||
                (iterator->getWinner().substr(0, user_sreach_string.size()) == user_sreach_string) ||
                (iterator->getAward().substr(0, user_sreach_string.size()) == user_sreach_string) ||
                (iterator->getYear().substr(0, user_sreach_string.size()) == user_sreach_string)) {
                cout << iterator->getID() << " , " << iterator->getYear() << " , " << iterator->getAward() << " , "
                     << iterator->getWinner() << " , " << iterator->getName() << " , " << iterator->getFilm() << endl;
            }
        }
        //take ID and update the record
        int row_id;
        cout << "Please enter the ID of the row you want to update:-  " << endl;
        cin >> row_id;
        for (iterator=vector1.begin();iterator!=vector1.end();++iterator) {
            if (iterator->getID() == row_id) {
                vector1.erase(iterator);
                cout<<"The row is successfully deleted"<<endl;
            }

        }

        cout<<"\n\n"<<endl;
        cout<<"Press any key to go back to menu........."<<endl;
        getchar();
        back_to_menu=false;
    }



}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////            Picture Database    /////////////////////////////////////////////////////////
//////////////////////////////////                                /////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Database::create_bst_for_picture_class() {

    string name,year,nominations,rating,durations,genre1,genre2,release,metacritic,synopsis;
    id=99;
    ifstream csv_picture_File("C:\\Users\\chu\\CLionProjects\\Desta_final_project_binary_tree\\pictures.csv");
    if(!csv_picture_File.is_open()) cout<<"Error on reading picture file"<<'\n';

    while(!csv_picture_File.eof()) {

        getline(csv_picture_File, name, ',');
        getline(csv_picture_File, year, ',');
        getline(csv_picture_File, nominations, ',');
        getline(csv_picture_File, rating, ',');
        getline(csv_picture_File, durations, ',');
        getline(csv_picture_File, genre1, ',');
        getline(csv_picture_File, genre2, ',');
        getline(csv_picture_File, release, ',');
        getline(csv_picture_File, metacritic, ',');
        getline(csv_picture_File, synopsis, '\n');

        picture.setId(id);
        picture.setName(name);
        picture.setYear(year);
        picture.setNominations(nominations);
        picture.setRating(rating);
        picture.setDuration(durations);
        picture.setGenre1(genre1);
        picture.setGEnre2(genre2);
        picture.setRelease(release);
        picture.setMetacritic(metacritic);
        picture.setSynopsis(synopsis);


        bsTree_picture.addNode(picture.getName(),picture);

        id++;

    }

    id=99;
    csv_picture_File.close();
}

void Database::write_picture_bst_to_vector() {
    write_picture_bst_to_vector(bsTree_picture.Root());

}

void Database::write_picture_bst_to_vector(Node<Picture, string> *node) {

    if(node== nullptr)
        return;
    write_picture_bst_to_vector(node->Left());
    store_picture_data_to_vector(node->Data());
    write_picture_bst_to_vector(node->Right());
}

void Database::store_picture_data_to_vector(const Picture &picture1) {
    vector_picture.push_back(picture1);
}

void Database::writfile_picture_data_to_new_file() {
    string new_file_name,new_file;
    cout<<"Please enter any file name you want"<<endl;
    cin>>new_file_name;

    for(int i=0; i!=new_file_name.size(); ++i) {
        //create name
        new_file=new_file_name + std::to_string(i) + ".csv"; // C++11
        //create file
        std::ofstream file(new_file);
        //then do with file
    }
    string file_path="C:\\Users\\chu\\CLionProjects\\Desta_final_project_binary_tree\\"+new_file;  //create new path
    ofstream tofile(file_path);//pass path
    if(!tofile.is_open()) cout<<"Error on reading file"<<'\n';
    tofile<<"   Name  ,"<<", Year ,"<<"Nominations,"<<"Rating,"<<"Duration,"<<" Genre1,"<<"Genre2,"<<" Release ,"<<"Metacritic,"<<"                   Synopsis        "<<endl;
    for (auto &i : vector_picture) {
        tofile<<i.getName()<<" , "<<i.getYear()<<" , "<<i.getNominations()<<" , "<<i.getRating()<<" , "<<i.getDurations()<<" , "<<i.getGenre1()<<" , "<<i.getGenre2()<<" , "<<i.getRelease()<<" , "<<i.getMetacritic()<<" , "<<i.getSynosis()<<endl;
    }
    tofile.close();
}

void Database::search_a_picture_record() {

    bool back_to_menu = true;

    while (back_to_menu) {

        string user_sreach_string;
        cout << "Please search any record in the actor database......\n" << endl;
        cout << "Enter any string" << endl;
        cin.ignore();
        getline(cin, user_sreach_string);

        cout << "\n\nThe data associated with :->  " << user_sreach_string << "  is the following below...........\n\n"
             << endl;
        //display column names
        cout << "ID " << ",  Name  ," << "Year, " << " Nominations ," << " Rating ," << " Durations ," << " Genre1 ,"
             << " Genre1 ," << " Release," << " Metacritic," << " Synosis" << "\n" << endl;

        for (iterator_picture = vector_picture.begin(); iterator_picture != vector_picture.end(); ++iterator_picture) {
            if ((iterator_picture->getYear().substr(0, user_sreach_string.size()) == user_sreach_string) ||
                (iterator_picture->getName().substr(0, user_sreach_string.size()) == user_sreach_string) ||
                (iterator_picture->getNominations().substr(0, user_sreach_string.size()) == user_sreach_string) ||
                (iterator_picture->getRating().substr(0, user_sreach_string.size()) == user_sreach_string) ||
                (iterator_picture->getDurations().substr(0, user_sreach_string.size()) == user_sreach_string) ||
                (iterator_picture->getGenre1().substr(0, user_sreach_string.size()) == user_sreach_string) ||
                (iterator_picture->getGenre2().substr(0, user_sreach_string.size()) == user_sreach_string) ||
                (iterator_picture->getRelease().substr(0, user_sreach_string.size()) == user_sreach_string) ||
                (iterator_picture->getMetacritic().substr(0, user_sreach_string.size()) == user_sreach_string) ||
                (iterator_picture->getSynosis().substr(0, user_sreach_string.size()) == user_sreach_string)) {
                cout << iterator_picture->getID() << " , " << iterator_picture->getName() << " , "
                     << iterator_picture->getYear() << " , " << iterator_picture->getNominations() << " , "
                     << iterator_picture->getRating() << " , " << iterator_picture->getDurations() << " , "
                     << iterator_picture->getGenre1() << " , " << iterator_picture->getGenre2() << " , "
                     << iterator_picture->getRelease() << " , " << iterator_picture->getMetacritic() << " , "
                     << iterator_picture->getSynosis() << endl;
            }
        }
        cout << "\n\n" << endl;

        cout << "Press any key to go back to menu........." << endl;
        getchar();
        //getchar();
        back_to_menu = false;
    }
}
//********************************************************* SORTING ***************************************
//sort by name
bool sortByPName(const Picture&lhs,const Picture &rhs){
    return lhs.getName() < rhs.getName();
}
//sort by year
bool sortByPYear(const Picture&lhs,const Picture &rhs){
    return lhs.getYear() < rhs.getYear();
}
//sort by nominations
bool sortByNominations(const Picture&lhs,const Picture &rhs){
    return lhs.getNominations() < rhs.getNominations();
}
//sort by rating
bool sortByRating(const Picture&lhs,const Picture &rhs){
    return lhs.getRating() < rhs.getRating();
}
//sort by duration
bool sortByDuration(const Picture&lhs,const Picture &rhs){
    return lhs.getDurations() < rhs.getDurations();
}
//sort by genre1
bool sortByGenre1(const Picture&lhs,const Picture &rhs){
    return lhs.getGenre1() < rhs.getGenre1();
}
//sort by genre2
bool sortByGenre2(const Picture&lhs,const Picture &rhs){
    return lhs.getGenre2() < rhs.getGenre2();
}
//sort by release
bool sortByRelease(const Picture&lhs,const Picture &rhs){
    return lhs.getRelease() < rhs.getRelease();
}
//sort by metacritic
bool sortByMetacritic(const Picture&lhs,const Picture &rhs){
    return lhs.getMetacritic() < rhs.getMetacritic();
}
//sort by synopsis
bool sortBySynopsis(const Picture&lhs,const Picture &rhs){
    return lhs.getSynosis() < rhs.getSynosis();
}


void Database::sortPictutreDataByType(int picture_ype) {


    switch (picture_ype)
    {
        case 1:
            //sort by name
            sort(vector_picture.begin(),vector_picture.end(),sortByPName);
            break;
        case 2:
            //sort by year
            sort(vector_picture.begin(),vector_picture.end(),sortByPYear);
            break;
        case 3:
            //sort by nominations
            sort(vector_picture.begin(),vector_picture.end(),sortByNominations);
            break;
        case 4:
            //sort by rating
            sort(vector_picture.begin(),vector_picture.end(),sortByRating);
            break;
        case 5:
            //sort by duration
            sort(vector_picture.begin(),vector_picture.end(),sortByDuration);
            break;
        case 6:
            //sort by genre1
            sort(vector_picture.begin(),vector_picture.end(),sortByGenre1);
            break;
        case 7:
            //sort by genre2
            sort(vector_picture.begin(),vector_picture.end(),sortByGenre2);
            break;
        case 8:
            //sort by release
            sort(vector_picture.begin(),vector_picture.end(),sortByRelease);
            break;
        case 9:
            //sort by metacritic
            sort(vector_picture.begin(),vector_picture.end(),sortByMetacritic);
            break;
        case 10:
            //sort by synopsis
            sort(vector_picture.begin(),vector_picture.end(),sortBySynopsis);
            break;
        default:break;
    }


}
//*********************************************************END OF SORTING ***************************************
void Database::addDataToPictureDataSet() {

    string name,year,nominations,rating,durations,genre1,genre2,release,metacritic,synopsis;
    bool keepAsking=true;

    while (keepAsking){

        cout<<"    "<<endl;

        cout<<"Please enter name actor Name: "<<endl;
        cin.ignore();
        getline(cin,name);
        picture.setName(name);

        cout<<"Please enter name actor Year: "<<endl;
        cin.ignore();
        getline(cin,year);
        picture.setYear(year);


        cout<<"Please enter name actor Nominations: "<<endl;
        cin.ignore();
        getline(cin,nominations);
        picture.setName(nominations);

        cout<<"Please enter name actor Rating: "<<endl;
        cin.ignore();
        getline(cin,rating);
        picture.setName(rating);

        cout<<"Please enter name actor Duration: "<<endl;
        cin.ignore();
        getline(cin,durations);
        picture.setName(durations);

        cout<<"Please enter name actor Genre1: "<<endl;
        cin.ignore();
        getline(cin,genre1);
        picture.setName(genre1);

        cout<<"Please enter name actor Genre2: "<<endl;
        cin.ignore();
        getline(cin,genre2);
        picture.setName(genre2);

        cout<<"Please enter name actor Release: "<<endl;
        cin.ignore();
        getline(cin,release);
        picture.setName(release);

        cout<<"Please enter name actor Metacritic: "<<endl;
        cin.ignore();
        getline(cin,metacritic);
        picture.setName(metacritic);

        cout<<"Please enter name actor Synopsis: "<<endl;
        cin.ignore();
        getline(cin,synopsis);
        picture.setName(synopsis);

        picture.setId(picture.getID()+1);  //this will get the last row id and add one to the new record

        vector_picture.push_back(picture);//add new data in to vector

        char comformation;
        cout<<"The new recored is added"<<endl;
        cout<<"would you like to add again:  Y(y)  or  N(n) ";
        cin>>comformation;
        cout<<"\n\n"<<endl;
        keepAsking= comformation == 'N' || comformation == 'n' ? false : true;
    }

    id=99;      //reset id

}

void Database::update_a_picture_record() {

    bool back_to_menu=true;

    while (back_to_menu) {

        string user_sreach_string;

        cout << "Please search any record in the actor database......\n" << endl;
        cout << "Enter any string" << endl;
        cin.ignore();
        getline(cin, user_sreach_string);

        cout << "\n\nThe data associated with :->  " << user_sreach_string << "  is the following below...........\n\n"<< endl;

        //display column names
        cout<<"ID,"<< ",  Name  ," <<"Year,"<<"Nominations,"<<"Rating,"<< "Durations,"<<"Genre1,"<<"Genre1,"<<"Release,"<<"Metacritic,"<<"Synosis"<<"\n"<<endl;

        for (iterator_picture=vector_picture.begin();iterator_picture!=vector_picture.end();++iterator_picture) {
            if((iterator_picture->getName().substr(0,user_sreach_string.size())== user_sreach_string)||
               (iterator_picture->getYear().substr(0,user_sreach_string.size())== user_sreach_string)||
               (iterator_picture->getNominations().substr(0,user_sreach_string.size())== user_sreach_string)||
               (iterator_picture->getRating().substr(0,user_sreach_string.size())== user_sreach_string)||
               (iterator_picture->getDurations().substr(0,user_sreach_string.size())== user_sreach_string)||
               (iterator_picture->getGenre1().substr(0,user_sreach_string.size())==user_sreach_string)||
               (iterator_picture->getGenre2().substr(0,user_sreach_string.size())==user_sreach_string)||
               (iterator_picture->getRelease().substr(0,user_sreach_string.size())==user_sreach_string)||
               (iterator_picture->getMetacritic().substr(0,user_sreach_string.size())==user_sreach_string)||
               (iterator_picture->getSynosis().substr(0,user_sreach_string.size())==user_sreach_string)){

                cout<<iterator_picture->getName()<<" , " <<iterator_picture->getYear()<<" , "
                    <<iterator_picture->getNominations()<<" , " <<iterator_picture->getRating()<<" , "
                    <<iterator_picture->getDurations()<<" , "<<iterator_picture->getGenre1()<<" , "
                    <<iterator_picture->getGenre2()<<" , "<<iterator_picture->getRelease()<<" , "
                    <<iterator_picture->getMetacritic()<<" , "<<iterator_picture->getSynosis()<<endl;
            }
        }
        //take ID and update the record
        string name,year,nominations,rating,durations,genre1,genre2,release,metacritic,synopsis;
        int row_id;
        cout<<"Please enter the ID of the row you want to update:-  "<<endl;
        cin>>row_id;

        for (iterator_picture=vector_picture.begin();iterator_picture!=vector_picture.end();++iterator_picture)
        {
            if(iterator_picture->getID()==row_id){



                char chiose;
                cout<<"Would you like to update a Name: Y/y or N/n"<<endl;
                cin>>chiose;
                if(chiose=='y'|| chiose=='Y'){
                    cout<<"Enter a Name"<<endl;
                    cin.ignore();
                    getline(cin,name);
                    picture.setYear(name);

                }
                cout<<"Would you like to update a Year: Y/y or N/n"<<endl;
                cin>>chiose;
                if(chiose=='y'|| chiose=='Y'){
                    cout<<"Enter a Year"<<endl;
                    cin.ignore();
                    getline(cin,year);
                    picture.setYear(year);

                }
                cout<<"Would you like to update a Nominations: Y/y or N/n"<<endl;
                cin>>chiose;
                if(chiose=='y'|| chiose=='Y'){
                    cout<<"Enter a Nominations"<<endl;
                    cin.ignore();
                    getline(cin,nominations);
                    picture.setNominations(nominations);

                }
                cout<<"Would you like to update a Rating: Y/y or N/n"<<endl;
                cin>>chiose;
                if(chiose=='y'|| chiose=='Y'){
                    cout<<"Enter a Rating"<<endl;
                    cin.ignore();
                    getline(cin,rating);
                    picture.setDuration(rating);

                }
                cout<<"Would you like to update a Duration: Y/y or N/n"<<endl;
                cin>>chiose;
                if(chiose=='y'|| chiose=='Y'){
                    cout<<"Enter a duration"<<endl;
                    cin.ignore();
                    getline(cin,durations);
                    picture.setDuration(durations);

                }
                cout<<"Would you like to update a Genre1: Y/y or N/n"<<endl;
                cin>>chiose;
                if(chiose=='y'|| chiose=='Y'){

                    cout<<"Enter a Genre1"<<endl;
                    cin.ignore();
                    getline(cin,genre1);
                    picture.setGenre1(genre1);

                }
                cout<<"Would you like to update a Genre2: Y/y or N/n"<<endl;
                cin>>chiose;
                if(chiose=='y'|| chiose=='Y'){

                    cout<<"Enter a Genre2"<<endl;
                    cin.ignore();
                    getline(cin,genre2);
                    picture.setGEnre2(genre2);

                }
                cout<<"Would you like to update a Release: Y/y or N/n"<<endl;
                cin>>chiose;
                if(chiose=='y'|| chiose=='Y'){
                    cout<<"Enter a Release"<<endl;
                    cin.ignore();
                    getline(cin,release);
                    picture.setRelease(release);

                }
                cout<<"Would you like to update a Metacritic: Y/y or N/n"<<endl;
                cin>>chiose;
                if(chiose=='y'|| chiose=='Y'){
                    cout<<"Enter a metacritic"<<endl;
                    cin.ignore();
                    getline(cin,metacritic);
                    picture.setMetacritic(metacritic);

                }
                cout<<"Would you like to update a Synopsis: Y/y or N/n"<<endl;
                cin>>chiose;
                if(chiose=='y'|| chiose=='Y'){
                    cout<<"Enter a synopsis"<<endl;
                    cin.ignore();
                    getline(cin,synopsis);
                    picture.setMetacritic(synopsis);

                }

            }

        }
        cout<<"\n\n"<<endl;
        cout<<"Press any key to go back to menu........."<<endl;
        getchar();
        //getchar();
        back_to_menu=false;

    }
}

void Database::delete_record_prcture() {
    bool back_to_menu=true;

    while (back_to_menu)
    {

        string user_sreach_string;
        cout<<"Please search any record in the actor database......\n"<<endl;
        cout<<"Enter any string"<<endl;
        cin.ignore();
        getline(cin, user_sreach_string);

        cout<<"\n\nThe data associated with :->  "<<user_sreach_string<<"  is the following below...........\n\n"<<endl;
        //display column names
        cout<<"ID,"<< ",  Name  ," <<"Year,"<<"Nominations,"<<"Rating,"<< "Durations,"<<"Genre1,"<<"Genre1,"<<"Release,"<<"Metacritic,"<<"Synosis"<<"\n"<<endl;

        for (iterator_picture=vector_picture.begin();iterator_picture!=vector_picture.end();++iterator_picture) {
            if((iterator_picture->getName().substr(0,user_sreach_string.size())== user_sreach_string)||
               (iterator_picture->getYear().substr(0,user_sreach_string.size())== user_sreach_string)||
               (iterator_picture->getNominations().substr(0,user_sreach_string.size())== user_sreach_string)||
               (iterator_picture->getRating().substr(0,user_sreach_string.size())== user_sreach_string)||
               (iterator_picture->getDurations().substr(0,user_sreach_string.size())== user_sreach_string)||
               (iterator_picture->getGenre1().substr(0,user_sreach_string.size())==user_sreach_string)||
               (iterator_picture->getGenre2().substr(0,user_sreach_string.size())==user_sreach_string)||
               (iterator_picture->getRelease().substr(0,user_sreach_string.size())==user_sreach_string)||
               (iterator_picture->getMetacritic().substr(0,user_sreach_string.size())==user_sreach_string)||
               (iterator_picture->getSynosis().substr(0,user_sreach_string.size())==user_sreach_string)){

                cout<<iterator_picture->getName()<<" , " <<iterator_picture->getYear()<<" , "
                    <<iterator_picture->getNominations()<<" , " <<iterator_picture->getRating()<<" , "
                    <<iterator_picture->getDurations()<<" , "<<iterator_picture->getGenre1()<<" , "
                    <<iterator_picture->getGenre2()<<" , "<<iterator_picture->getRelease()<<" , "
                    <<iterator_picture->getMetacritic()<<" , "<<iterator_picture->getSynosis()<<endl;
            }
        }

        int row_id;
        cout<<"Please enter the ID of the row you want to update:-  "<<endl;
        cin>>row_id;
        for (iterator_picture=vector_picture.begin();iterator_picture!=vector_picture.end();++iterator_picture) {
            if (iterator_picture->getID() == row_id) {
                vector_picture.erase(iterator_picture);
                cout<<"The row is successfully deleted"<<endl;
            }
        }


        cout<<"\n\n"<<endl;
        cout<<"Press any key to go back to menu........."<<endl;
        getchar();
        back_to_menu=false;
    }


}
//******************************** NOMINATIONS DATA SET *****************************************
void Database::create_bst_for_Nominations() {
    string yearstring,award,winner,name,film;
    id=99;
    ifstream csvFile("C:\\Users\\chu\\CLionProjects\\Desta_final_project_binary_tree\\nominations.csv");
    if(!csvFile.is_open()) cout<<"Error on reading file"<<'\n';

    while(!csvFile.eof()) {

        getline(csvFile, yearstring, ',');
        getline(csvFile, award, ',');
        getline(csvFile, winner, ',');
        getline(csvFile, name, ',');
        getline(csvFile, film, '\n');

        nominations.setID(id);
        nominations.setAward(award);
        nominations.setYear(yearstring);
        nominations.setWinner(winner);
        nominations.setName(name);
        nominations.setFilm(film);

        bsTree_nominations.addNode(nominations.getName(),nominations);

        id++;

    }

    id=99;



}

void Database::writ_Nominations_bst_tofile() {
    writ_Nominations_bst_tofile(bsTree_nominations.Root());

}

void Database::writ_Nominations_bst_tofile(Node<Nominations, string> *node) {
    if(node== nullptr)
        return;
    writ_Nominations_bst_tofile(node->Left());
    store_picture_data_to_vector(node->Data());
    writ_Nominations_bst_tofile(node->Right());


}

void Database::store_picture_data_to_vector(const Nominations &nominations1) {
    vector_nominations.push_back(nominations1);

}

void Database::writfile_Nominations_data_to_new_file() {
    string new_file_name,new_file;
    cout<<"Please enter any file name you want"<<endl;
    cin>>new_file_name;

    for(int i=0; i!=new_file_name.size(); ++i) {
        //create name
        new_file=new_file_name + std::to_string(i) + ".csv"; // C++11 for std::to_string
        //create file
        std::ofstream file(new_file);
        //then do with file
    }
    string file_path="C:\\Users\\chu\\CLionProjects\\Desta_final_project_binary_tree\\"+new_file;  //create new path
    ofstream tofile(file_path);//pass path
    if(!tofile.is_open()) cout<<"Error on reading file"<<'\n';
    tofile<<"ID ,"<<",  Year  ,"<<"       Award      ,"<<"Winner,"<<"      Name      "<<"     Film        "<<endl;
    for (auto &i : vector_nominations) {
        tofile<<i.getID()<<" , "<<i.getYear()<<" , "<<i.getAward()<<" , "<<i.getWinner()<<" , "<< i.getName()<<" , "<<i.getFilm()<<endl;
    }
    tofile.close();

}

void Database::search_a_Nominations_record() {
    bool back_to_menu=true;

    while (back_to_menu)
    {

        string user_sreach_string;
        cout<<"Please search any record in the actor database......\n"<<endl;
        cout<<"Enter any string"<<endl;
        cin.ignore();
        getline(cin, user_sreach_string);

        cout<<"\n\nThe data associated with :->  "<<user_sreach_string<<"  is the following below...........\n\n"<<endl;
        //display column names
        cout<<"ID"<<" , "<< "Year" <<" ,      "<< "Award" <<"      ,  "<<  " Winner  "<<",     "<< "   Name "<<"      , "<< "     Film   "<<"\n"<<endl;

        for (iterator_nominations=vector_nominations.begin();iterator_nominations!=vector_nominations.end();++iterator_nominations) {
            if((iterator_nominations->getName().substr(0,user_sreach_string.size())== user_sreach_string)||(iterator_nominations->getFilm().substr(0,user_sreach_string.size())== user_sreach_string)||(iterator_nominations->getWinner().substr(0,user_sreach_string.size())== user_sreach_string)||(iterator_nominations->getAward().substr(0,user_sreach_string.size())== user_sreach_string)||(iterator_nominations->getYear().substr(0,user_sreach_string.size())== user_sreach_string)){
                cout<<iterator_nominations->getID()<<" , " <<iterator_nominations->getYear()<<" , "<< iterator_nominations->getAward()<<" , "<<iterator_nominations->getWinner()<<" , "<< iterator_nominations->getName()<<" , "<<iterator_nominations->getFilm()<<endl;
            }
        }
        cout<<"\n\n"<<endl;
        cout<<"Press any key to go back to menu........."<<endl;
        getchar();
        back_to_menu=false;
    }

}
//************************************************* SORTING **********************************************
//sort by year
bool sortByNYear(const Nominations &lhs,const Nominations &rhs){
    return lhs.getYear()<rhs.getYear();
}
//sort by award
bool sortByNAward(const Nominations &lhs,const Nominations &rhs){
    return lhs.getAward()<rhs.getAward();
}
//sort by winner
bool sortByNWinner(const Nominations &lhs,const Nominations &rhs){
    return lhs.getWinner()<rhs.getWinner();
}
//sort by name
bool sortByNName(const Nominations &lhs,const Nominations &rhs){
    return lhs.getName()<rhs.getName();
}
//sort by film
bool sortByNFilm(const Nominations &lhs,const Nominations &rhs){
    return lhs.getFilm()<rhs.getFilm();
}

void Database::sortNominationsDataByType(int type) {
    switch (type)
    {
        case 1:
            //sort by year
            sort(vector_nominations.begin(),vector_nominations.end(),sortByNYear);
            break;
        case 2:
            //sort by award
            sort(vector_nominations.begin(),vector_nominations.end(),sortByNAward);
            break;
        case 3:
            //sort by winner
            sort(vector_nominations.begin(),vector_nominations.end(),sortByNWinner);
            break;
        case 4:
            //sort by name
            sort(vector_nominations.begin(),vector_nominations.end(),sortByNName);
            break;
        case 5:
            //sort by film
            sort(vector_nominations.begin(),vector_nominations.end(),sortByNFilm);
            break;

        default:break;
    }


}

void Database::addDataToNominationsDataSet() {
    string award,yearstring,winner,name,film;
    bool keepAsking=true;

    while (keepAsking){

        cout<<"    "<<endl;

        cout<<"Please enter name actor Year: "<<endl;
        getline(cin,yearstring);
        nominations.setName(yearstring);

        cout<<"Please enter name actor award: "<<endl;
        getline(cin,award);
        nominations.setName(award);


        cout<<"Please enter name actor name: "<<endl;
        getline(cin,name);
        nominations.setName(name);

        cout<<"Please enter name actor winner: "<<endl;
        getline(cin,winner);
        nominations.setName(winner);

        cout<<"Please enter name actor film: "<<endl;
        getline(cin,film);
        nominations.setName(film);

        nominations.setID(nominations.getID()+1);  //this will get the last row id and add one to the new record

        vector_nominations.push_back(nominations);//add new data in to vector

        char comformation;
        cout<<"The new recored is added"<<endl;
        cout<<"whould you like to add agin:  Y(y)  or  N(n) ";
        cin>>comformation;
        cout<<"\n\n"<<endl;
        keepAsking= comformation == 'N' || comformation == 'n' ? false : true;
    }

    id=99;      //reset id

}

void Database::update_a_Nominations_record() {
    bool back_to_menu=true;

    while (back_to_menu) {

        string user_sreach_string;

        cout << "Please search any record in the actor database......\n" << endl;
        cout << "Enter any string" << endl;
        cin.ignore();
        getline(cin, user_sreach_string);

        cout << "\n\nThe data associated with :->  " << user_sreach_string << "  is the following below...........\n\n"<< endl;


        cout<<"ID"<<" , "<< "Year" <<" ,      "<< "Award" <<"      ,  "<<  " Winner  "<<",     "<< "   Name "<<"      , "<< "     Film   "<<"\n"<<endl;

        for (iterator_nominations=vector_nominations.begin();iterator_nominations!=vector_nominations.end();++iterator_nominations) {
            if((iterator_nominations->getName().substr(0,user_sreach_string.size())== user_sreach_string)||(iterator_nominations->getFilm().substr(0,user_sreach_string.size())== user_sreach_string)||(iterator_nominations->getWinner().substr(0,user_sreach_string.size())== user_sreach_string)||(iterator_nominations->getAward().substr(0,user_sreach_string.size())== user_sreach_string)||(iterator_nominations->getYear().substr(0,user_sreach_string.size())== user_sreach_string)){
                cout<<iterator_nominations->getID()<<" , " <<iterator_nominations->getYear()<<" , "<< iterator_nominations->getAward()<<" , "<<iterator_nominations->getWinner()<<" , "<<iterator_nominations->getName()<<" , "<<iterator_nominations->getFilm()<<endl;
            }
        }
        //take ID and update the record
        int row_id;
        cout<<"Please enter the ID of the row you want to update:-  "<<endl;
        cin>>row_id;

        for (iterator_nominations=vector_nominations.begin();iterator_nominations!=vector_nominations.end();++iterator_nominations)
        {
            if(iterator_nominations->getID()==row_id){


                string type_string;
                char chiose;
                cout<<"Would you like to update a Year: Y/y or N/n"<<endl;
                cin>>chiose;
                if(chiose=='y'|| chiose=='Y'){
                    cout<<"Enter a year"<<endl;
                    cin.ignore();
                    getline(cin,type_string);
                    nominations.setYear(type_string);

                }
                cout<<"Would you like to update a Award: Y/y or N/n"<<endl;
                cin>>chiose;
                if(chiose=='y'|| chiose=='Y'){
                    cout<<"Enter a Award"<<endl;
                    cin.ignore();
                    getline(cin,type_string);
                    nominations.setAward(type_string);

                }
                cout<<"Would you like to update a Winner: Y/y or N/n"<<endl;
                cin>>chiose;
                if(chiose=='y'|| chiose=='Y'){
                    cout<<"Enter a Winner"<<endl;
                    cin.ignore();
                    getline(cin,type_string);
                    nominations.setWinner(type_string);

                }
                cout<<"Would you like to update a Name: Y/y or N/n"<<endl;
                cin>>chiose;
                if(chiose=='y'|| chiose=='Y'){
                    cout<<"Enter a Name"<<endl;
                    cin.ignore();
                    getline(cin,type_string);
                    nominations.setName(type_string);

                }
                cout<<"Would you like to update a Film: Y/y or N/n"<<endl;
                cin>>chiose;
                if(chiose=='y'|| chiose=='Y'){

                    cout<<"Enter a Film"<<endl;
                    cin.ignore();
                    getline(cin,type_string);
                    nominations.setFilm(type_string);

                }

            }

        }





        cout<<"\n\n"<<endl;
        cout<<"Press any key to go back to menu........."<<endl;
        getchar();
        back_to_menu=false;

    }


}

void Database::delete_record_Nominations() {
    bool back_to_menu=true;

    while (back_to_menu) {

        string user_sreach_string;

        cout << "Please search any record in the actor database......\n" << endl;
        cout << "Enter any string" << endl;
        cin.ignore();
        getline(cin, user_sreach_string);

        cout << "\n\nThe data associated with :->  " << user_sreach_string << "  is the following below...........\n\n"
             << endl;


        cout << "ID" << " , " << "Year" << " ,      " << "Award" << "      ,  " << " Winner  " << ",     " << "   Name "
             << "      , " << "     Film   " << "\n" << endl;

        for (iterator_nominations = vector_nominations.begin(); iterator_nominations != vector_nominations.end(); ++iterator_nominations) {
            if ((iterator_nominations->getName().substr(0, user_sreach_string.size()) == user_sreach_string) ||
                (iterator_nominations->getFilm().substr(0, user_sreach_string.size()) == user_sreach_string) ||
                (iterator_nominations->getWinner().substr(0, user_sreach_string.size()) == user_sreach_string) ||
                (iterator_nominations->getAward().substr(0, user_sreach_string.size()) == user_sreach_string) ||
                (iterator_nominations->getYear().substr(0, user_sreach_string.size()) == user_sreach_string)) {
                cout << iterator_nominations->getID() << " , " << iterator_nominations->getYear() << " , " << iterator_nominations->getAward() << " , "
                     << iterator_nominations->getWinner() << " , " << iterator_nominations->getName() << " , " << iterator_nominations->getFilm() << endl;
            }
        }
        //take ID and update the record
        int row_id;
        cout << "Please enter the ID of the row you want to update:-  " << endl;
        cin >> row_id;
        for (iterator_nominations=vector_nominations.begin();iterator_nominations!=vector_nominations.end();++iterator) {
            if (iterator_nominations->getID() == row_id) {
                vector_nominations.erase(iterator_nominations);
                cout<<"The row is successfully deleted"<<endl;
            }

        }

        cout<<"\n\n"<<endl;
        cout<<"Press any key to go back to menu........."<<endl;
        getchar();
        back_to_menu=false;
    }




}



