#ifndef __H_FIELD_HPP__
#define __H_FIELD_HPP__

#include "field.hpp"

template<class T> void h_field(field<T>& fld);
template<class T> void hx_field(field<T>& fld);
template<class T> void hy_field(field<T>& fld);
template<class T> void hz_field(field<T>& fld);

template<class T> 
void h_field(field<T>& fld) {
    hx_field<T>(fld);
    hy_field<T>(fld);
    hz_field<T>(fld);
}

template<class T>
void hx_field(field<T>& fld) {
    const int ist = 1;
    const int ied = fld.ni - 1;
    const int jst = 0;
    const int jed = fld.nj - 1;
    const int kst = 0;
    const int ked = fld.nk - 1;
    T*** const hx = fld.hx;
    T*** const ey = fld.ey;
    T*** const ez = fld.ez;
    T* const chxly = fld.chxly;
    T* const chxlz = fld.chxlz;
    using id_size_t = typename field<T>::id_size_t;
    id_size_t*** const idhx = fld.idhx;
    for(int k = kst; k < ked; k++) {
        for(int j = jst; j < jed; j++) {
            for(int i = ist; i < ied; i++) {
                const int id = idhx[k][j][i];
                hx[k][j][i] = hx[k][j][i]
                    - chxly[id] * (ez[k][j+1][i] - ez[k][j][i])
                    + chxlz[id] * (ey[k+1][j][i] - ey[k][j][i]);
            }
        }
    }
}

template<class T>
void hy_field(field<T>& fld) {
    const int ist = 0;
    const int ied = fld.ni - 1;
    const int jst = 1;
    const int jed = fld.nj - 1;
    const int kst = 0;
    const int ked = fld.nk - 1;
    T*** const hy = fld.hy;
    T*** const ez = fld.ez;
    T*** const ex = fld.ex;
    T* const chylz = fld.chylz;
    T* const chylx = fld.chylx;
    using id_size_t = typename field<T>::id_size_t;
    id_size_t*** const idhy = fld.idhy;
    for(int k = kst; k < ked; k++) {
        for(int j = jst; j < jed; j++) {
            for(int i = ist; i < ied; i++) {
                const int id = idhy[k][j][i];
                hy[k][j][i] = hy[k][j][i]
                    - chylz[id] * (ex[k+1][j][i] - ex[k][j][i])
                    + chylx[id] * (ez[k][j][i+1] - ez[k][j][i]);
            }
        }
    }
}

template<class T>
void hz_field(field<T>& fld) {
    const int ist = 0;
    const int ied = fld.ni - 1;
    const int jst = 0;
    const int jed = fld.nj - 1;
    const int kst = 1;
    const int ked = fld.nk - 1;
    T*** const hz = fld.hz;
    T*** const ex = fld.ex;
    T*** const ey = fld.ey;
    T* const chzlx = fld.chzlx;
    T* const chzly = fld.chzly;
    using id_size_t = typename field<T>::id_size_t;
    id_size_t*** const idhz = fld.idhz;
    for(int k = kst; k < ked; k++) {
        for(int j = jst; j < jed; j++) {
            for(int i = ist; i < ied; i++) {
                const int id = idhz[k][j][i];
                hz[k][j][i] = hz[k][j][i]
                    - chzlx[id] * (ey[k][j][i+1] - ey[k][j][i])
                    + chzly[id] * (ex[k][j+1][i] - ex[k][j][i]);
            }
        }
    }
}

#endif
