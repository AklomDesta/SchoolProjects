//
// Created by chu on 11/12/2018.
//

#ifndef DESTA_FINAL_PROJECT_BINARY_TREE_DATABASE_H
#define DESTA_FINAL_PROJECT_BINARY_TREE_DATABASE_H


#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <ostream>
//#include <conio.h>
#include "BSTree.h"
#include "BSTree.hpp"
#include "Actor.h"
#include "Picture.h"
#include "Nominations.h"


using namespace std;

class Database {

    //**************** Actor elements **********************************
    BSTree<Actor, string> bsTree;
    Actor actor;
    vector<Actor> vector1;
    vector<Actor>::iterator iterator;
    Node<Actor*,string> *node;
    //**************** Actor elements **********************************
    BSTree<Picture, string> bsTree_picture;
    Picture picture;
    vector<Picture> vector_picture;
    vector<Picture>::iterator iterator_picture;
    //**************** Nominations elements **********************************
    BSTree<Nominations, string> bsTree_nominations;
    Nominations nominations;
    vector<Nominations> vector_nominations;
    vector<Nominations>::iterator iterator_nominations;


public:

    //**************** Actor methods **********************************
    void create_bst_for_actor();
   void  writ_actor_bst_tofile();
   void writ_actor_bst_tofile(Node<Actor,string> *node);
   void store(const Actor&actor1);
   void writfile();
   void search_a_record();
   void sortActorDataByType(int type);
   void addDataToActorDataSet();
   void update_a_record();
   void delete_record();
    //****************End of Actor methods **********************************
    void create_bst_for_picture_class();
    void write_picture_bst_to_vector();
    void write_picture_bst_to_vector(Node<Picture,string> *node);
    void store_picture_data_to_vector(const Picture&picture1);
    void writfile_picture_data_to_new_file();
    void search_a_picture_record();
    void sortPictutreDataByType(int picture_ype);
    void addDataToPictureDataSet();
    void update_a_picture_record();
    void delete_record_prcture();

    //**************** Nominations methods **********************************
    void create_bst_for_Nominations();
    void  writ_Nominations_bst_tofile();
    void writ_Nominations_bst_tofile(Node<Nominations,string> *node);
    void store_picture_data_to_vector(const Nominations&nominations1);
    void writfile_Nominations_data_to_new_file();
    void search_a_Nominations_record();
    void sortNominationsDataByType(int type);
    void addDataToNominationsDataSet();
    void update_a_Nominations_record();
    void delete_record_Nominations();

};


#endif //DESTA_FINAL_PROJECT_BINARY_TREE_DATABASE_H
