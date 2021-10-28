#ifndef __FIELD_HPP__
#define __FIELD_HPP__

#include "config.hpp"
#include "color.hpp"
#include "alloc.hpp"
#include <iostream>

template<class T>
class field {
public:
    int ni, nj, nk;
    T ***ex, ***ey, ***ez;
    T ***hx, ***hy, ***hz;
    field();
    field(int, int, int);
    ~field();
};


template<class T>
field<T>::field() {
    this->ex = nullptr;
    this->ey = nullptr;
    this->ez = nullptr;
    this->hx = nullptr;
    this->hy = nullptr;
    this->hz = nullptr;
}

template<class T>
field<T>::field(int _ni, int _nj, int _nk) : ni(_ni), nj(_nj), nk(_nk) {
    this->ex = allocate_3d_array<T>(nk, nj, ni);
    this->ey = allocate_3d_array<T>(nk, nj, ni);
    this->ez = allocate_3d_array<T>(nk, nj, ni);
    this->hx = allocate_3d_array<T>(nk, nj, ni);
    this->hy = allocate_3d_array<T>(nk, nj, ni);
    this->hz = allocate_3d_array<T>(nk, nj, ni);
    auto set_zero = [&](T ***p) -> void {
        for(int k = 0; k < nk; k++) {
            for(int j = 0; j < nj; j++) {
                for(int i = 0; i < ni; i++) {
                    p[k][j][i] = 0;
                }
            }
        }
    };
    set_zero(this->ex);
    set_zero(this->ey);
    set_zero(this->ez);
    set_zero(this->hx);
    set_zero(this->hy);
    set_zero(this->hz);
    std::cout << GREEN "[field<T>::field] Array allocation is finished\n" PLAIN << std::endl;
} 

template<class T>
field<T>::~field() {
    deallocate_3d_array<T>(this->ex, this->nk, this->nj, this->ni);
    deallocate_3d_array<T>(this->ey, this->nk, this->nj, this->ni);
    deallocate_3d_array<T>(this->ez, this->nk, this->nj, this->ni);
    deallocate_3d_array<T>(this->hx, this->nk, this->nj, this->ni);
    deallocate_3d_array<T>(this->hy, this->nk, this->nj, this->ni);
    deallocate_3d_array<T>(this->hz, this->nk, this->nj, this->ni);
    std::cout << GREEN "[field<T>::~field] Array deallocation is finished\n" PLAIN << std::endl;
}


#endif