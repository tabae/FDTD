#ifndef __MEDIUM_HPP__
#define __MEDIUM_HPP__

#include "physical_constants.hpp"

/**
 * @brief 媒質の物性値
 */
template<class T>
class medium {
public:
    //! 誘電率
    T eps;
    //! 導電率
    T sigma;
    //! 透磁率
    T mu;    
    //! @brief 引数未指定時は何もしません． 
    medium() {};
    medium(T, T, T);
};

/**
 * @brief 媒質の物性値を初期化します
 * @param [in] _eps 誘電率
 * @param [in] r_sigma 比導電率
 * @param [in] r_mu 比透磁率
 */
template<class T>
medium<T>::medium(T _eps, T r_sigma, T r_mu) {
    this->eps = _eps;
    this->sigma = r_sigma * SIGMA0;
    this->mu = r_mu * MU0;
}

#endif
