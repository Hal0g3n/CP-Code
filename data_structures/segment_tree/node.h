#pragma once

#include "seg_tree.h" // To define the node
namespace OOP_Competitive_Programming {
    
    template<typename T>
    template<typename U>
    class seg_tree<T>::Node {

        // Start and end of segment
        int start, end; 
        
        // Value contained by the segment
        U value;  

        // Left and Right child
        Node<U> *l, *r;

        // No Default Ctor
        Node() = delete;

        // No Copy Ctor
        Node(Node<U> const&) = delete; 

        // Default Init nodes
        Node(int, int);

        // Value Init nodes
        Node(initializer_list<T>);

        // Destructor
        ~Node();

        void update(int, U);

        U query(int = start, int = end);
            
    };

}
