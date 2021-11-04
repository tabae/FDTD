#ifndef __E_FIELD_HPP__
#define __E_FIELD_HPP__

#include "field.hpp"
template<class T> void e_field(const field<T>& fld);
template<class T> void ex_field(const field<T>& fld);
template<class T> void ey_field(field<T>& fld);
template<class T> void ez_field(field<T>& fld);


template<class T>
void e_field(const field<T>& fld) {
    ex_field(fld);
    ey_field(fld);
    ez_field(fld);
}

template<class T>
void ex_field(const field<T>& fld) {
    const int ist = 0;
    const int ied = fld.ni - 1;
    const int jst = 1;
    const int jed = fld.nj - 1;
    const int kst = 1;
    const int ked = fld.nk - 1;
    T*** const ex = fld.ex;
    T*** const hy = fld.hy;
    T*** const hz = fld.hz;
    T* const cex = fld.cex;
    T* const cexly = fld.cexly;
    T* const cexlz = fld.cexlz;
    using id_size_t = typename field<T>::id_size_t;
    id_size_t*** const idex = fld.idex;
    for(int k = kst; k < ked; k++) {
        for(int j = jst; j < jed; j++) {
            for(int i = ist; i < ied; i++) {
                const int id = idex[k][j][i];
                ex[k][j][i] = 
                    cex[id] * ex[k][j][i]
                    + cexly[id] * (hz[k][j][i] - hz[k][j-1][i])
                    - cexlz[id] * (hy[k][j][i] - hy[k-1][j][i]);
            }
        }
    }
}

template<class T>
void ey_field(const field<T>& fld) {
    const int ist = 1;
    const int ied = fld.ni - 1;
    const int jst = 0;
    const int jed = fld.nj - 1;
    const int kst = 1;
    const int ked = fld.nk - 1;
    T*** const ey = fld.ey;
    T*** const hz = fld.hz;
    T*** const hx = fld.hx;
    T* const cey = fld.cex;
    T* const ceylz = fld.ceylz;
    T* const ceylx = fld.ceylx;
    using id_size_t = typename field<T>::id_size_t;
    id_size_t*** const idey = fld.idey;
    for(int k = kst; k < ked; k++) {
        for(int j = jst; j < jed; j++) {
            for(int i = ist; i < ied; i++) {
                const int id = idey[k][j][i];
                ey[k][j][i] = 
                    cey[id] * ey[k][j][i]
                    + ceylz[id] * (hx[k][j][i] - hx[k-1][j][i])
                    - ceylx[id] * (hz[k][j][i] - hz[k][j][i-1]);
            }
        }
    }
}

template<class T>
void ez_field(const field<T>& fld) {
    const int ist = 1;
    const int ied = fld.ni - 1;
    const int jst = 1;
    const int jed = fld.nj - 1;
    const int kst = 0;
    const int ked = fld.nk - 1;
    T*** const ez = fld.ez;
    T*** const hx = fld.hx;
    T*** const hy = fld.hy;
    T* const cez = fld.cex;
    T* const cezlx = fld.cezlx;
    T* const cezly = fld.cezly;
    using id_size_t = typename field<T>::id_size_t;
    id_size_t*** const idez = fld.idez;
    for(int k = kst; k < ked; k++) {
        for(int j = jst; j < jed; j++) {
            for(int i = ist; i < ied; i++) {
                const int id = idez[k][j][i];
                ez[k][j][i] = 
                    cez[id] * ez[k][j][i]
                    + cezlx[id] * (hy[k][j][i] - hy[k][j][i-1])
                    - cezly[id] * (hx[k][j][i] - hx[k][j-1][i]);
            }
        }
    }
}   

#endif
