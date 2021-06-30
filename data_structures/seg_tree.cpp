#include "seg_tree.h"
#include <cassert>
#include <stdexcept>

namespace OOP_Competitive_Programming {

    template<typename T>
    seg_tree<T>::seg_tree(int s, int e, T (*f) (T, T)) {

        //start must be smaller than end
        assert(s <= e);

        // N is the number of nodes on the highest counted layer
        int N = num_nodes = e - s + 1;

        // While it is not at the top layer
        while (N != 1) {        
            // Is there a node with no pair
            int r = N % 2; 

            // Merge all pairs
            N /= 2;    

            // Add the new layer nodes to the count
            num_nodes += N;    

            // Add back the unused node
            N += r; 
        }

        // Creates array of all nodes
        node_values = new T[num_nodes + 5];
    }
    
}