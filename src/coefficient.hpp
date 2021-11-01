#ifndef __COEFFICIENT_HPP__
#define __COEFFICIENT_HPP__

#include "log.hpp"
#include "config.hpp"
#include "field.hpp"

template<class T> void set_coefficient(const config<T>& cfg, const field<T>& fld);
template<class T> void set_cex(const config<T>& cfg, const field<T>& fld);
template<class T> void set_cexly(const config<T>& cfg, const field<T>& fld);
template<class T> void set_cexlz(const config<T>& cfg, const field<T>& fld);
template<class T> void set_cey(const config<T>& cfg, const field<T>& fld);
template<class T> void set_ceylz(const config<T>& cfg, const field<T>& fld);
template<class T> void set_ceylx(const config<T>& cfg, const field<T>& fld);
template<class T> void set_cez(const config<T>& cfg, const field<T>& fld);
template<class T> void set_cezlx(const config<T>& cfg, const field<T>& fld);
template<class T> void set_cezly(const config<T>& cfg, const field<T>& fld);
template<class T> void set_chxly(const config<T>& cfg, const field<T>& fld);
template<class T> void set_chxlz(const config<T>& cfg, const field<T>& fld);
template<class T> void set_chylz(const config<T>& cfg, const field<T>& fld);
template<class T> void set_chylx(const config<T>& cfg, const field<T>& fld);
template<class T> void set_chzlx(const config<T>& cfg, const field<T>& fld);
template<class T> void set_chzly(const config<T>& cfg, const field<T>& fld);

/**
 * @brief 係数の前計算を行います．
 * @param [in] cfg 設定情報
 * @param [in] fld フィールド情報
 */
template<class T>
void set_coefficient(const config<T>& cfg, const field<T>& fld) {
    log("set_coefficient", "Begin Setting Coefficients");
    set_cex<T>(cfg, fld);
    set_cexly<T>(cfg, fld);
    set_cexlz<T>(cfg, fld);
    set_cey<T>(cfg, fld);
    set_ceylz<T>(cfg, fld);
    set_ceylx<T>(cfg, fld);
    set_cez<T>(cfg, fld);
    set_cezlx<T>(cfg, fld);
    set_cezly<T>(cfg, fld);
    set_chxly<T>(cfg, fld);
    set_chxlz<T>(cfg, fld);
    set_chylz<T>(cfg, fld);
    set_chylx<T>(cfg, fld);
    set_chzlx<T>(cfg, fld);
    set_chzly<T>(cfg, fld);
    log("set_coefficient", "Finish Setting Coefficients");
}

/**
 * @brief 係数の前計算を行います．
 * @param [in] cfg 設定情報
 * @param [in] fld フィールド情報
 */
template<class T>
void set_cex(const config<T>& cfg, const field<T>& fld) {
    for(int i = 0; i < cfg.n_medium; i++) {
        const T tmp = (cfg.mediums[i].sigma * cfg.delta_t * 0.5) / (cfg.mediums[i].eps);
        fld.cex[i] = (1 - tmp) / (1 + tmp);
    }
}

/**
 * @brief 係数の前計算を行います．
 * @param [in] cfg 設定情報
 * @param [in] fld フィールド情報
 */
template<class T>
void set_cexly(const config<T>& cfg, const field<T>& fld) {
    for(int i = 0; i < cfg.n_medium; i++) {
        const T tmp = (cfg.mediums[i].sigma * cfg.delta_t * 0.5) / (cfg.mediums[i].eps);
        fld.cexly[i] = (cfg.delta_t) / (cfg.mediums[i].eps * (1 + tmp) * cfg.delta_y);
    }
}

/**
 * @brief 係数の前計算を行います．
 * @param [in] cfg 設定情報
 * @param [in] fld フィールド情報
 */
template<class T>
void set_cexlz(const config<T>& cfg, const field<T>& fld) {
    for(int i = 0; i < cfg.n_medium; i++) {
        const T tmp = (cfg.mediums[i].sigma * cfg.delta_t * 0.5) / (cfg.mediums[i].eps);
        fld.cexlz[i] = (cfg.delta_t) / (cfg.mediums[i].eps * (1 + tmp) * cfg.delta_z);
    }
}

/**
 * @brief 係数の前計算を行います．
 * @param [in] cfg 設定情報
 * @param [in] fld フィールド情報
 */
template<class T>
void set_cey(const config<T>& cfg, const field<T>& fld) {
    for(int i = 0; i < cfg.n_medium; i++) {
        const T tmp = (cfg.mediums[i].sigma * cfg.delta_t * 0.5) / (cfg.mediums[i].eps);
        fld.cey[i] = (1 - tmp) / (1 + tmp);
    }
}

/**
 * @brief 係数の前計算を行います．
 * @param [in] cfg 設定情報
 * @param [in] fld フィールド情報
 */
template<class T>
void set_ceylz(const config<T>& cfg, const field<T>& fld) {
    for(int i = 0; i < cfg.n_medium; i++) {
        const T tmp = (cfg.mediums[i].sigma * cfg.delta_t * 0.5) / (cfg.mediums[i].eps);
        fld.ceylz[i] = (cfg.delta_t) / (cfg.mediums[i].eps * (1 + tmp) * cfg.delta_z);
    }
}

/**
 * @brief 係数の前計算を行います．
 * @param [in] cfg 設定情報
 * @param [in] fld フィールド情報
 */
template<class T>
void set_ceylx(const config<T>& cfg, const field<T>& fld) {
    for(int i = 0; i < cfg.n_medium; i++) {
        const T tmp = (cfg.mediums[i].sigma * cfg.delta_t * 0.5) / (cfg.mediums[i].eps);
        fld.ceylx[i] = (cfg.delta_t) / (cfg.mediums[i].eps * (1 + tmp) * cfg.delta_x);
    }
}

/**
 * @brief 係数の前計算を行います．
 * @param [in] cfg 設定情報
 * @param [in] fld フィールド情報
 */
template<class T>
void set_cez(const config<T>& cfg, const field<T>& fld) {
    for(int i = 0; i < cfg.n_medium; i++) {
        const T tmp = (cfg.mediums[i].sigma * cfg.delta_t * 0.5) / (cfg.mediums[i].eps);
        fld.cez[i] = (1 - tmp) / (1 + tmp);
    }
}

/**
 * @brief 係数の前計算を行います．
 * @param [in] cfg 設定情報
 * @param [in] fld フィールド情報
 */
template<class T>
void set_cezlx(const config<T>& cfg, const field<T>& fld) {
    for(int i = 0; i < cfg.n_medium; i++) {
        const T tmp = (cfg.mediums[i].sigma * cfg.delta_t * 0.5) / (cfg.mediums[i].eps);
        fld.cezlx[i] = (cfg.delta_t) / (cfg.mediums[i].eps * (1 + tmp) * cfg.delta_x);
    }
}

/**
 * @brief 係数の前計算を行います．
 * @param [in] cfg 設定情報
 * @param [in] fld フィールド情報
 */
template<class T>
void set_cezly(const config<T>& cfg, const field<T>& fld) {
    for(int i = 0; i < cfg.n_medium; i++) {
        const T tmp = (cfg.mediums[i].sigma * cfg.delta_t * 0.5) / (cfg.mediums[i].eps);
        fld.cezly[i] = (cfg.delta_t) / (cfg.mediums[i].eps * (1 + tmp) * cfg.delta_y);
    }
}

/**
 * @brief 係数の前計算を行います．
 * @param [in] cfg 設定情報
 * @param [in] fld フィールド情報
 */
template<class T>
void set_chxly(const config<T>& cfg, const field<T>& fld) {
    for(int i = 0; i < cfg.n_medium; i++) {
        fld.chxly[i] = cfg.delta_t / (cfg.mediums[i].mu * cfg.delta_y);
    }
}

/**
 * @brief 係数の前計算を行います．
 * @param [in] cfg 設定情報
 * @param [in] fld フィールド情報
 */
template<class T>
void set_chxlz(const config<T>& cfg, const field<T>& fld) {
    for(int i = 0; i < cfg.n_medium; i++) {
        fld.chxlz[i] = cfg.delta_t / (cfg.mediums[i].mu * cfg.delta_z);
    }
}

/**
 * @brief 係数の前計算を行います．
 * @param [in] cfg 設定情報
 * @param [in] fld フィールド情報
 */
template<class T>
void set_chylz(const config<T>& cfg, const field<T>& fld) {
    for(int i = 0; i < cfg.n_medium; i++) {
        fld.chylz[i] = cfg.delta_t / (cfg.mediums[i].mu * cfg.delta_z);
    }
}

/**
 * @brief 係数の前計算を行います．
 * @param [in] cfg 設定情報
 * @param [in] fld フィールド情報
 */
template<class T>
void set_chylx(const config<T>& cfg, const field<T>& fld) {
    for(int i = 0; i < cfg.n_medium; i++) {
        fld.chylx[i] = cfg.delta_t / (cfg.mediums[i].mu * cfg.delta_x);
    }
}

/**
 * @brief 係数の前計算を行います．
 * @param [in] cfg 設定情報
 * @param [in] fld フィールド情報
 */
template<class T>
void set_chzlx(const config<T>& cfg, const field<T>& fld) {
    for(int i = 0; i < cfg.n_medium; i++) {
        fld.chzlx[i] = cfg.delta_t / (cfg.mediums[i].mu * cfg.delta_x);
    }
}

/**
 * @brief 係数の前計算を行います．
 * @param [in] cfg 設定情報
 * @param [in] fld フィールド情報
 */
template<class T>
void set_chzly(const config<T>& cfg, const field<T>& fld) {
    for(int i = 0; i < cfg.n_medium; i++) {
        fld.chzly[i] = cfg.delta_t / (cfg.mediums[i].mu * cfg.delta_y);
    }
}

#endif