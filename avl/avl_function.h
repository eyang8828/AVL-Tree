/*
 * Author: Eddie Yang
 * Project: Binary Search Tree
 * Purpose: to create a system that we can store data in to 
 *        a binary search tree and organize the node within
 *        the tree with function given in BTree_function
 * Notes: Haven't yet implemented the add function, cause
 *        didn't see the need to implement it.
 */
#ifndef BTREE_FUNCTION_H
#define BTREE_FUNCTION_H
#include "tree_node.h"
#include <iostream>
#include <iomanip>

using namespace std;

template <typename T>
void tree_insert(tree_node<T>* &root, const T& insert_me){
    //if the current node is empty, insert the item here.
    if(root == nullptr){
        root = new tree_node<T>(insert_me);
    //if insert_me is larger then the item, we go right
    }else if(insert_me >root->_item){
        tree_insert(root->_right,insert_me);
    //if insert_me is less then the item, we go left
    }else if (insert_me < root->_item){
        tree_insert(root->_left,insert_me);
    }
    //update height at the end.
    root->update_height();
    rotate(root);
};

template <typename T>
tree_node<T>* tree_search(tree_node<T>* root, const T& target){
    //if we find the target match the item, return the node
    if(root->_item == target){
        return root;
    //if the target is larger than the item, we go right
    }else if (target >root->_item){
        return tree_search(root->_right, target);
    //if the target is less than the item, we go left 
    }else if (target< root->_item){
        return tree_search(root->_left, target);
    }
};

template <typename T>
bool tree_search(tree_node<T>* root, const T& target,
                 tree_node<T>* &found_ptr){
    if (root == nullptr){
        return false;
    }
    //if we found the item. return true and set a pointer
    // to the item's node
    if(root->_item == target){
        found_ptr = root;
        return true;
    // if the target is larger than the item we go right
    }else if (target > root->_item){
        return tree_search(root->_right, target, found_ptr);
    // if the target is less than the item we go left
    }else if (target < root->_item){
        return tree_search(root->_left, target, found_ptr);
    }
    return false;

};

template<typename T>
void tree_print(tree_node<T>* root, int level=0, 
                                    ostream& outs=cout){
    if( root == nullptr){
        return;
    }
    //print out the root from the right tree to the left tree
    tree_print(root->_right,level+1);
    outs<<setw(level*4)<<""<<*root<<endl;
    tree_print(root->_left,level+1);
};

template<typename T>       //prints detailes info about each node
void tree_print_debug(tree_node<T>* root, int level=0, 
                                          ostream& outs=cout){

    if(root == nullptr){
        return;
    }
    //print out the tree with the item in the root with its height
    tree_print_debug(root->_right,level+1);
    outs<<setw(level*4)<<""<<*root<< root->balance_factor()<<endl;
    tree_print_debug(root->_left,level+1);

};

template <typename T>       //clear the tree
void tree_clear(tree_node<T>* &root){
    //clear out the left tree and then the right tree
    if(root->_left != nullptr){
        tree_clear(root->_left);
    }
    if (root->_right != nullptr){
        tree_clear(root->_right);
    }
    //after the recurrsion reach the end of the tree
    // start deleting and set root to null.
    delete root;
    root = nullptr;
};

template <typename T>       //erase target from the tree
bool tree_erase(tree_node<T>* &root, const T& target){
    //if there is no match return false to show it.
    if(root == nullptr){
        return false;
    }

    //if the target is larger than the item, we go right,
    // update the height on our way back
    if (target >root->_item){
        tree_erase(root->_right,target);
        root->update_height();
        rotate(root);
        
    //if the target is less than the item, we go left,
    // update the height on our way back
    }else if (target < root->_item){
        tree_erase(root->_left,target);
        root->update_height();
        rotate(root);

    // if the upper two didn't execute -> we found a match
    //if the node doesn't have a left tree, we simply connect
    // the root with the right node.        
    }else if (root->_left == nullptr){
        tree_node<T> *r_node = root->_right;
        delete root;
        root = r_node;
    //if there is something on the left tree, we move the max
    // node up and replace our root, and update the height on
    // our way back.
    }else{
        T item;
        tree_remove_max(root->_left,item);
        tree_node<T> *r_node = root->_right;
        tree_node<T> *l_node = root->_left;
        tree_node<T> *delete_this = root;
        root = new tree_node<T>(item,l_node,r_node);
        delete delete_this;
        root->update_height();
        rotate(root);
    }
    
    // return true to show that we found a match
    return true;
    
};

template <typename T>       //erase rightmost node from the tree
                            // store the item in max_value
void tree_remove_max(tree_node<T>* &root, T& max_value){

    //item on the very right end is the largest item
    // therefore if we reach the very right, we remove
    // that one.
    if(root->_right != nullptr){
        tree_remove_max(root->_right,max_value);
        root->update_height();
        rotate(root);

    // if there is an item on the left, we hook it up
    // with root.
    }else if (root->_left != nullptr){
        tree_node<T> *l_node= root->_left;
        max_value = root->_item;
        delete root;
        root = l_node;
        root->update_height();
    }else{
        max_value = root->_item;
        delete root;
        root = nullptr;
    }
    
};

template <typename T>       //return copy of tree pointed to by root
tree_node<T>* tree_copy(tree_node<T>* root){

    //call constructor function with copy function in it, so we can
    // copy the whole tree
    if ( root!= nullptr){
        tree_node<T> *temp= new tree_node<T>(root->_item, tree_copy(root->_left),tree_copy(root->_right));
        temp->update_height();
        return temp;
    }
    return nullptr;
};

template <typename T>       // sorted array -> tree
tree_node<T>* tree_from_sorted_list(const T* a, int start, int end){
    if (start > end){
        return nullptr;
    }
    /* Get the middle element and make it root */
    int mid = (start + end)/2;  
    tree_node<T> *temp = new tree_node<T>(a[mid],
                tree_from_sorted_list(a, start, mid - 1),
                tree_from_sorted_list(a, mid + 1, end));
  
    return temp;  
};

template <typename T>       // sorted array -> tree
tree_node<T>* tree_from_sorted_list(const T* a, int size){
    size -=1;
    tree_node<T> *temp;
    if(!size <=1){
        temp = new tree_node<T>(a[size/2],
                        tree_from_sorted_list(a,0,(size/2)-1),
                        tree_from_sorted_list(a,(size/2)+1,size));
    }
    return temp;
};

// ...................................................


template <typename T>
tree_node<T>* rotate_right(tree_node<T>* &root){
    tree_node<T> *pivot = root->_left;
    tree_node<T> *move = pivot->_right;
    root->_left = move;
    pivot->_right = root;
    root->update_height();
    root= pivot;
    // cout<<*pivot;
    
    root->update_height();
    return root;
};
template <typename T>
tree_node<T>* rotate_left(tree_node<T>* &root){
    tree_node<T> *pivot = root->_right;
    tree_node<T> *move = pivot->_left;
    root->_right = move;
    pivot->_left = root;
    root->update_height();
    root= pivot;
    
    return root;
};
template <typename T>
tree_node<T>* rotate(tree_node<T>* & root){
    // four cases ~ LL LR RR RL
    if (root->balance_factor()>1){
        if(root->_right->balance_factor()<=-1){          //RL
            rotate_right(root->_right);
            rotate_left(root);
        }else if (root->_right->balance_factor()>=0){    //RR
            rotate_left(root);
        }
        
    }else if (root->balance_factor()<-1){
        //can't be 0, 
        if(root->_left->balance_factor()>=1){            //LR
            rotate_left(root->_left);
            rotate_right(root);

        }else if (root->_left->balance_factor()<=0){    //LL
            rotate_right(root);
        }
    }
    return root;
}; //decide which rotate is needed based on balance factor


//add function to merge two tree into one
template <typename T>
void tree_add(tree_node<T>* &host, tree_node<T>* guest){
    // while guest doesn't equal to null keep the recurrsion going
    if(guest!= nullptr){
        if(guest->_right)
            tree_add(host,guest->_right);
        if(guest->_left)
            tree_add(host,guest->_left);
        tree_insert(host,guest->_item);
    }else{
        //stop
        return;
    }
}


#endif // BTREE_FUNCTION_H