#ifndef __SETUP_HPP__
#define __SETUP_HPP__

#include "config.hpp"
#include "field.hpp"
#include "coefficient.hpp"
template<class T> void setup(config<T>& cfg, field<T>& fld);

template<class T>
void setup(config<T> &cfg, field<T> &fld) {
    cfg.read_from_file();
    fld.build(cfg);
    set_coefficient(cfg, fld);    
}

#endif
