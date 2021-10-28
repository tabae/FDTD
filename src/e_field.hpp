#ifndef __E_FIELD_HPP__
#define __E_FIELD_HPP__

#include "field.hpp"
template<class T> void e_field(field<T>& fld);
template<class T> void ex_field(field<T>& fld);
template<class T> void ey_field(field<T>& fld);
template<class T> void ez_field(field<T>& fld);


template<class T>
void e_field(field<T>& fld) {
    ex_field(fld);
    ey_field(fld);
    ez_field(fld);
}

template<class T>
void ex_field(field<T>& fld) {
    
}

template<class T>
void ey_field(field<T>& fld) {

}

template<class T>
void ez_field(field<T>& fld) {

}   


#endif
