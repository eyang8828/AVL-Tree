
#include <iomanip>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "avl.h"
using namespace std;

int main(){
    
    //setting up for the function
    srand(time(NULL));
    avl<int> *tree = new  avl<int>();
    char ans = ' ';

    // //while the user's answer is not x, kept the function going
    // while (tolower(ans) != 'x'){
        
    //     cout<<"[R]andom  [I]nsert  [C]clear  [S]earch   e[X]it:";
    //     cin >> ans ;
    //     cout<<endl;
    //     switch (tolower(ans)){

    //         //case random : get a random number from 1~99 and insert to the tree 
    //         case 'r':{
    //             int num = rand()%99 +1;

    //             cout<<"-- Inserting "<<num<<endl;
    //             cout<<"tree_node CTOR: item: "<<num<<":0"<<endl;
    //             tree->insert(num);
    //             tree->print();
    //             break;
    //         }

    //         //case insert : ask for a number to insert and insert to the tree
    //         case 'i':{
    //             int num;
    //             cout<< "what number?";
    //             cin >> num;

    //             cout<<"-- Inserting "<<num<<endl;
    //             cout<<"tree_node CTOR: item: "<<num<<":0"<<endl;
    //             tree->insert(num);
    //             tree->print();
    //             break;
    //         }

    //         //case clear : clear the whole tree.
    //         case 'c':{
    //             tree->clear();
    //             cout<<"clearing the tree";
    //             break;
    //         }

    //         //case search : ask for number to search, show the result
    //         case 's':{
    //             int num;
    //             cout<<"what number to search ?";
    //             cin>> num;
    //             cout<<endl;


    //             tree_node<int> *temp = NULL;
    //             bool found = tree->search(num,temp);


    //             if(found){
    //                 cout<<"item is found. "<<*temp<<endl;
    //                 tree->print();
    //             }else{
    //                 cout<<"item not found."<<endl;
    //                 tree->print();
    //             }
    //             break;
    //         }
    //         case 'e':
    //         {
    //             int num;
    //             cout << "what number to erase ?" << endl;
    //             cin >> num;
    //             bool found = tree->erase(num);
    //             tree->print();
    //             break;
    //         }
    //         //case exit : ans = x ending program
    //         case 'x':{
    //             cout<<"ending program~";
    //             break;
    //         }

    //         //if the user answer anything invalid, we tell them
    //         default:{
    //             cout<<"please enter a valid input";
    //             break;
    //         }
    //     };

    //     cout<<endl<<string(32,'=')<<endl;
    // }
}