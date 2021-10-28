#ifndef __CONFIG_HPP__
#define __CONFIG_HPP__

class config {
public: 
    int total_step;
    int ni, nj, nk;
    float delta_t;
    void read_from_file();
};


void config::read_from_file() {
    auto set_dummy_config = [&]() {
        this->total_step = 1000;        
        this->delta_t = 1e-3;
        this->ni = 30;
        this->nj = 20;
        this->nk = 2;
    };
    set_dummy_config();
}

#endif
