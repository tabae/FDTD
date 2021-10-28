#ifndef __ALLOC_HPP__
#define __ALLOC_HPP__

#include "color.hpp"
#include <iostream>
#include <cstdlib>

template<class T> T*** allocate_3d_array(int, int, int);
template<class T> void deallocate_3d_array(T ***, int, int, int);

template<class T>
T*** allocate_3d_array(int nk, int nj, int ni) {
    if(ni <= 0 || nj <= 0 || nk <= 0) {
        std::cerr << RED "[allocate_3d_array] Error!\n" PLAIN;
        std::cerr << "\t non positive value is assigned to array size, (" << nk << "," << nj << "," << ni << ")\n";
        std::cerr << "\t must be positive integer.\n" << std::endl;
        exit(1);
    }
    T ***ptr = new T**[nk];
    for(int k = 0; k < nk; k++) {
        ptr[k] = new T*[nj];
    } 
    for(int k = 0; k < nk; k++) {
        for(int j = 0; j < nj; j++) {
            ptr[k][j] = new T[ni];
        }
    }
    return ptr;
}

template<class T>
void deallocate_3d_array(T*** ptr, int nk, int nj, int ni) {
    
}

#endif