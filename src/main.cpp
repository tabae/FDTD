#include "config.hpp"
#include "field.hpp"
#include "color.hpp"
#include "setup.hpp"
#include "e_field.hpp"
#include "h_field.hpp"
#include "absorbing_boundary_condition.hpp"
#include "output.hpp"
#include <iostream>

int main() {
    config<float> cfg;
    field<float> fld;
    setup(cfg, fld);
    std::cout << "[main] Start time step loop\n" << std::endl;
    float t = 0;
    for(int step = 0; step < cfg.total_step; step++) {
        e_field(fld);
        absorbing_boundary_condition();
        t += cfg.delta_t * 0.5;
        h_field(fld);
        t += cfg.delta_t * 0.5;
    }
    std::cout << "[main] Finish time step loop\n" << std::endl;
    output();
    return 0;
}
