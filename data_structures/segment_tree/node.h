#pragma once

#include "seg_tree.h" // To define the node
namespace OOP_Competitive_Programming {
    
    template<typename T>
    template<typename U>
    class seg_tree<T>::node {

        // Start and end of segment
        int s, e; 
        
        // Value contained by the segment
        U value;  

        // Left and Right child
        node<U> *l, *r;

        // No Default Ctor
        node() = delete;

        // No Copy Ctor
        node(node<U> const&) = delete; 

        // Only this Ctor
        node(int, int);

        void update(int, U);

        U query(int, int);
            
    };

}
