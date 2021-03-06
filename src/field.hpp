#ifndef __FIELD_HPP__
#define __FIELD_HPP__

#include "config.hpp"
#include "log.hpp"
#include "alloc.hpp"
#include <iostream>

/**
 * @brief 各格子点の電磁界成分（`ex`,`ey`,`ez`,`hx`,`hy`,`hz`）と各格子点の媒質情報（のインデックス）(`idex`,`idey`,`idez`,`idhx`,`idhy`,`idhz`)を持ちます．
 * @details コンストラクタによってメモリの動的確保が行われ，デストラクタによって解放されます．
 * @details 電磁界成分の型はテンプレート化されており，`float`でも`double`でも`long double`でも好きに設定できます．
 * @details 媒質情報のインデックスの型は`id_size_t`のエイリアスに設定されており，媒質の種類は2^(4*sizeof(id_size_t))以下であることが要求されます．
 */
template<class T>
class field {
public:
    //! 媒質情報のインデックスの型．媒質の種類は2^(4*sizeof(id_size_t))以下であることが要求されます．
    using id_size_t = u_int8_t;
    //! 各軸の格子領域長 X方向
    int ni;
    //! 各軸の格子領域長 Y方向
    int nj;
    //! 各軸の格子領域長 Z方向
    int nk;
    //! 電解成分 X方向
    T ***ex;
    //! 電解成分 Y方向
    T ***ey;
    //! 電解成分 Z方向
    T ***ez;
    //! 磁界成分 X方向
    T ***hx;
    //! 磁界成分 Y方向
    T ***hy;
    //! 磁界成分 Z方向
    T ***hz;
    //! 電界座標系の媒質情報へのインデックス X方向
    id_size_t ***idex;
    //! 電界座標系の媒質情報へのインデックス Y方向
    id_size_t ***idey;
    //! 電界座標系の媒質情報へのインデックス Z方向
    id_size_t ***idez;
    //! 磁界座標系の媒質情報へのインデックス X方向
    id_size_t ***idhx;
    //! 磁界座標系の媒質情報へのインデックス Y方向
    id_size_t ***idhy;
    //! 磁界座標系の媒質情報へのインデックス Z方向
    id_size_t ***idhz;
    //! 電界成分X方向の係数
    T* cex;
    //! 電界成分X方向の係数
    T* cexly;
    //! 電界成分X方向の係数
    T* cexlz;
    //! 電界成分Y方向の係数
    T* cey;
    //! 電界成分Y方向の係数
    T* ceylz;
    //! 電界成分Y方向の係数
    T* ceylx;
    //! 電界成分Z方向の係数
    T* cez;
    //! 電界成分Z方向の係数
    T* cezlx;
    //! 電界成分Z方向の係数
    T* cezly;
    //! 磁界成分X方向の係数
    T* chxly;
    //! 磁界成分X方向の係数
    T* chxlz;
    //! 磁界成分Y方向の係数
    T* chylz;
    //! 磁界成分Y方向の係数
    T* chylx;
    //! 磁界成分Z方向の係数
    T* chzlx;
    //! 磁界成分Z方向の係数
    T* chzly;
    field();
    field(const config<T>& cfg);
    field& operator=(field&& field);
    ~field();
private:
    void set_nullptr();
};

/**
 * @brief 全ポインタをヌル初期化
 */
template<class T>
void field<T>::set_nullptr() {
    this->ex = nullptr;
    this->ey = nullptr;
    this->ez = nullptr;
    this->hx = nullptr;
    this->hy = nullptr;
    this->hz = nullptr;
    this->idex = nullptr;
    this->idey = nullptr;
    this->idez = nullptr;
    this->idhx = nullptr;
    this->idhy = nullptr;
    this->idhz = nullptr;
    this->cex = nullptr;
    this->cexly = nullptr;
    this->cexlz = nullptr;
    this->cey = nullptr;
    this->ceylz = nullptr;
    this->ceylx = nullptr;
    this->cez = nullptr;
    this->cezlx = nullptr;
    this->cezly = nullptr;
    this->chxly = nullptr;
    this->chxlz = nullptr;
    this->chylz = nullptr;
    this->chylx = nullptr;
    this->chzlx = nullptr;
    this->chzly = nullptr;
}

/**
 * @brief 各ポインタをヌル初期化します．
 */
template<class T>
field<T>::field() {
    this->set_nullptr();
}   

/**
 * @brief 配列の動的確保を行い，値をゼロで初期化します．
 * @details i方向にメモリ上で連続するように確保を行います.
 */
template<class T>
field<T>::field(const config<T>& cfg) {
    log("field<T>::field", "Begin Allocating Arrays");
    this->set_nullptr();
    this->nk = cfg.nk;
    this->nj = cfg.nj;
    this->ni = cfg.ni;
    this->ex = allocate_3d_array<T>(this->nk, this->nj, this->ni);
    this->ey = allocate_3d_array<T>(this->nk, this->nj, this->ni);
    this->ez = allocate_3d_array<T>(this->nk, this->nj, this->ni);
    this->hx = allocate_3d_array<T>(this->nk, this->nj, this->ni);
    this->hy = allocate_3d_array<T>(this->nk, this->nj, this->ni);
    this->hz = allocate_3d_array<T>(this->nk, this->nj, this->ni);
    this->idex = allocate_3d_array<id_size_t>(this->nk, this->nj, this->ni);
    this->idey = allocate_3d_array<id_size_t>(this->nk, this->nj, this->ni);
    this->idez = allocate_3d_array<id_size_t>(this->nk, this->nj, this->ni);
    this->idhx = allocate_3d_array<id_size_t>(this->nk, this->nj, this->ni);
    this->idhy = allocate_3d_array<id_size_t>(this->nk, this->nj, this->ni);
    this->idhz = allocate_3d_array<id_size_t>(this->nk, this->nj, this->ni);
    this->cex = new T[cfg.n_medium];
    this->cexly = new T[cfg.n_medium]; 
    this->cexlz = new T[cfg.n_medium];
    this->cey = new T[cfg.n_medium];
    this->ceylz = new T[cfg.n_medium];
    this->ceylx = new T[cfg.n_medium];
    this->cez = new T[cfg.n_medium];
    this->cezlx = new T[cfg.n_medium];
    this->cezly = new T[cfg.n_medium];
    this->chxly = new T[cfg.n_medium];
    this->chxlz = new T[cfg.n_medium];
    this->chylx = new T[cfg.n_medium];
    this->chylz = new T[cfg.n_medium];
    this->chzlx = new T[cfg.n_medium];
    this->chzly = new T[cfg.n_medium];
    set_value(this->ex, this->nk, this->nj, this->ni);
    set_value(this->ey, this->nk, this->nj, this->ni);
    set_value(this->ez, this->nk, this->nj, this->ni);
    set_value(this->hx, this->nk, this->nj, this->ni);
    set_value(this->hy, this->nk, this->nj, this->ni);
    set_value(this->hz, this->nk, this->nj, this->ni);
    set_value(this->idex, this->nk, this->nj, this->ni);
    set_value(this->idey, this->nk, this->nj, this->ni);
    set_value(this->idez, this->nk, this->nj, this->ni);
    set_value(this->idhx, this->nk, this->nj, this->ni);
    set_value(this->idhy, this->nk, this->nj, this->ni);
    set_value(this->idhz, this->nk, this->nj, this->ni);
    log("field<T>::field", "Finish Allocating Arrays");
} 

/**
 * @brief 配列のメモリ解放を行います．
 */
template<class T>
field<T>::~field() {
    log("field<T>::field", "Begin Deallocating Arrays");
    deallocate_3d_array<T>(this->ex, this->nk, this->nj, this->ni);
    deallocate_3d_array<T>(this->ey, this->nk, this->nj, this->ni);
    deallocate_3d_array<T>(this->ez, this->nk, this->nj, this->ni);
    deallocate_3d_array<T>(this->hx, this->nk, this->nj, this->ni);
    deallocate_3d_array<T>(this->hy, this->nk, this->nj, this->ni);
    deallocate_3d_array<T>(this->hz, this->nk, this->nj, this->ni);
    deallocate_3d_array<id_size_t>(this->idex, this->nk, this->nj, this->ni);
    deallocate_3d_array<id_size_t>(this->idey, this->nk, this->nj, this->ni);
    deallocate_3d_array<id_size_t>(this->idez, this->nk, this->nj, this->ni);
    deallocate_3d_array<id_size_t>(this->idhx, this->nk, this->nj, this->ni);
    deallocate_3d_array<id_size_t>(this->idhy, this->nk, this->nj, this->ni);
    deallocate_3d_array<id_size_t>(this->idhz, this->nk, this->nj, this->ni);
    delete [] this->cex;
    delete [] this->cexly;
    delete [] this->cexlz;
    delete [] this->cey;
    delete [] this->ceylz;
    delete [] this->ceylx;
    delete [] this->cez;
    delete [] this->cezlx;
    delete [] this->cezly;
    delete [] this->chxly;
    delete [] this->chxlz;
    delete [] this->chylx;
    delete [] this->chylz;
    delete [] this->chzlx;
    delete [] this->chzly;
    this->set_nullptr();
    log("field<T>::field", "Finish Deallocating Arrays");
}

/**
 * @brief std::moveの処理．ポインタをヌル初期化する必要がある．
 */
template<class T>
field<T>& field<T>::operator=(field<T>&& rhs) {
    this->ni = rhs.ni;
    this->nj = rhs.nj;
    this->nk = rhs.nk;
    this->ex = rhs.ex;
    this->ey = rhs.ey;
    this->ez = rhs.ez;
    this->hx = rhs.hx;
    this->hy = rhs.hy; 
    this->hz = rhs.hz; 
    this->idex = rhs.idex; 
    this->idey = rhs.idey; 
    this->idez = rhs.idez; 
    this->idhx = rhs.idhx; 
    this->idhy = rhs.idhy; 
    this->idhz = rhs.idhz; 
    this->cex = rhs.cex; 
    this->cexly = rhs.cexly; 
    this->cexlz = rhs.cexlz; 
    this->cey = rhs.cey; 
    this->ceylz = rhs.ceylz; 
    this->ceylx = rhs.ceylx; 
    this->cez = rhs.cez; 
    this->cezlx = rhs.cezlx; 
    this->cezly = rhs.cezly; 
    this->chxly = rhs.chxly; 
    this->chxlz = rhs.chxlz; 
    this->chylz = rhs.chylz; 
    this->chylx = rhs.chylx; 
    this->chzlx = rhs.chzlx; 
    this->chzly = rhs.chzly; 
    rhs.set_nullptr();
    return *this;
}

#endif
