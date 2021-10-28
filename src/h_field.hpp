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

}

template<class T>
void hy_field(field<T>& fld) {

}

template<class T>
void hz_field(field<T>& fld) {
    
}

#endif
