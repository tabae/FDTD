#ifndef __SETUP_HPP__
#define __SETUP_HPP__

#include "config.hpp"
#include "field.hpp"
template<class T> void setup(config& cfg, field<T>& fld);

template<class T>
void setup(config &cfg, field<T> &fld) {
    cfg.read_from_file();
    fld = field<T>(cfg.ni, cfg.nj, cfg.nk);
}

#endif
