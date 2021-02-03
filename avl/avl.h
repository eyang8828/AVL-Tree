/*
 * Author: Eddie Yang
 * Project: AVL Tree
 * Purpose: to create a system that we can store data in to 
 *        a AVL tree and organize the node within the tree
 *        and maintain the height to always be lower than
 *        2 as we make changes to the tree.
 * Notes: Haven't implement cout for the whole tree, instead
 *        of the top root
 */
#include "avl_function.h"

using namespace std;

template <typename T>
class avl{
    public:
        avl();
        avl(const T* sorted_list, int size=-1);
 
 //. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
 
        avl(const avl<T>& copy_me);
        avl<T>& operator =(const avl<T>& rhs);
        ~avl();
 
 //. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
 
        void insert(const T& insert_me);
        bool erase(const T& target);
        void clear();
        bool search(const T& target, tree_node<T>* & found_ptr);
        void print();
 
        friend ostream& operator <<(ostream& outs, const avl<T>& tree){
            outs<<"|"<<tree.root->_item<<"|"<<endl;
            return outs;
        };
        avl<T>& operator +=(const avl<T>& rhs);
    private:
        tree_node<T>* root;
};

template<typename T> avl<T>::avl(){
    root = nullptr;   
}

template<class T> avl<T>::avl(const T *sorted_list, int size){

    root = tree_from_sorted_list(sorted_list, size);
}

template<class T> avl<T>::avl(const avl<T> &copy_me){
    tree_node<T> *n1 = new tree_node<T>();
}

template<class T> avl<T> &avl<T>::operator=(const avl<T> &rhs){
    root = tree_copy(rhs->root);
    avl<T>temp = new avl<T>();
}

template<class T> void avl<T>::insert(const T &insert_me){
    tree_insert(root,insert_me);
}

template<class T> bool avl<T>::erase(const T &target){
    bool flag = tree_erase(root,target);
    return flag;
}

template<class T> bool avl<T>::search(const T &target, tree_node<T> *&found_ptr){
    bool found = tree_search(root,target,found_ptr);
    return found;
}

template<class T> void avl<T>::print(){
    tree_print_debug(root);
}

template<class T> void avl<T>::clear(){
    tree_clear(root);
}

template<class T> avl<T>::~avl(){
    tree_clear(root);
}

template<class T> avl<T> &avl<T>::operator+=(const avl<T> &rhs){
    tree_add(root,rhs->root);
}