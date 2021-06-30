#pragma once

#include "node.h" // To get the definition of node
namespace OOP_Competitive_Programming {

    template<typename T>
    class seg_tree {

    private:
        // Expected of nodes in the tree
        int num_nodes;
    
        // Class representing a node on the tree
        template<typename U>
        class node; 
        
        // Root node
        node<T> *root;

        //Function for getting the value from the child
        T *f (T, T);

    public:

        //Default Ctor
        seg_tree(int = 0, int = 0, T (*)(T, T) = std::min);

        //Copy Ctor
        seg_tree(seg_tree const&);

        //Copy Assignment Operator
        seg_tree& operator=(seg_tree const&);

        //Destructor
        ~seg_tree();

        void update(int, T);

        T query(int, int);

        T (*)(T, T) getValueFunction();
        int getSize();

    }; // End of seg_tree class

} // End of namespace CP