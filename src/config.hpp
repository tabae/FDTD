#ifndef __CONFIG_HPP__
#define __CONFIG_HPP__

#include "medium.hpp"
#include <vector>

template<class T>
class config {
public: 
    int total_step;
    int ni;
    int nj;
    int nk;
    int n_medium;
    T delta_t;
    T delta_x;
    T delta_y;
    T delta_z;
    std::vector<medium<T>> mediums;
    void read_from_file();
    void assign_medium();
};

/**
 * @brief TODO:書く
 */
template<class T>
void config<T>::read_from_file() {
    //! とりあえずダミーデータを突っ込んであります
    auto set_dummy_config = [&]() {
        this->total_step = 1000;        
        this->delta_t = 1e-3;
        this->ni = 30;
        this->nj = 20;
        this->nk = 2;
        this->delta_x = 1e-2;
        this->delta_y = 1e-2;
        this->delta_z = 1e-2;
        this->n_medium = 2;   
        this->mediums.resize(2);
        //! 完全導体を追加．完全導体は無限の導電率を持つが，計算上都合が悪いため，ダミーデータのみ代入しておく．
        this->mediums[0] = medium<T>();
        //! 自由空間を追加．導電率0,誘電率SIGMA0，透磁率MU0
        this->mediums[1] = medium<T>(0, 1, 1);  
    };
    set_dummy_config();
}

/**
 * @brief TODO:書く
 */
void assign_medium() {

}

#endif
