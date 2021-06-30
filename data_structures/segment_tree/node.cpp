#include "node.h"
#include <stdexcept>
namespace OOP_Competitive_Programming {

    template<typename T>
    template<typename U>
    seg_tree<T>::Node<U>::Node(int s, int e): start(s), end(e), value() {
        
        // Check if the start and end are valid
        if (start > end) throw std::invalid_argument("Start cannot be greater than end");

        // If the node cannot be split anymore
        if (start == end) return;

        // Find Middle
        int mid = (start + end) >> 1;

        // Create the left and right child
        l = new Node(start, mid);     // start to middle (inclusive)
        r = new Node(mid + 1, end); // middle + 1 to end (inclusive)
    }

    template<typename T>
    template<typename U>
    void seg_tree<T>::Node<U>::update(int pos, U n_val) {

        // Out of range check
        if (pos < start || pos > end) throw std::out_of_range("Position out of range");

        // This is the node to change
        if (start == end) {
            // Set to new value
            value = n_val;
            
            // Stop Recusion here
            return;
        }

        //Not leaf node, must go down towards the child at pos
        int mid = (start + end) >> 1;
        if (pos > mid) r -> update(pos, n_val); // If in right child subtree
        else l -> update(pos, n_val);           // else in left child subtree

        // update the value at the current position after change
        value = calc_value(l -> value, r -> value);
    }

    template<typename T>
    template<typename U>
    U seg_tree<T>::Node<U>::query(int q_s, int q_e) {

        // Check if range is valid
        if (q_s > q_e) throw std::invalid_argument("Query Range cannot start greater than end");

        if (q_e < start || q_e > end || 
            q_s < start || q_s > end) 
                throw std::out_of_range("Query Range out of range");

        int mid = (start + end) >> 1;

        if (q_s > mid) return r -> query(q_s, q_e);
        if (q_e <= mid) return l -> query(q_s, q_e);

        U left = l -> query(q_s, mid);
        U right = r -> query(mid + 1, q_e);

        return calc_value(left, right);
    }

}