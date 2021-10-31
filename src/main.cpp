#include "config.hpp"
#include "field.hpp"
#include "log.hpp"
#include "setup.hpp"
#include "e_field.hpp"
#include "h_field.hpp"
#include "absorbing_boundary_condition.hpp"
#include "output.hpp"
#include <iostream>

int main() {
    log("main", "Launch Solver");
    config<float> cfg;
    field<float> fld;
    setup(cfg, fld);
    log("main", "Begin Time Step Loop");
    float t = 0;
    for(int step = 0; step < cfg.total_step; step++) {
        e_field(fld);
        absorbing_boundary_condition();
        t += cfg.delta_t * 0.5;
        h_field(fld);
        t += cfg.delta_t * 0.5;
    }
    log("main", "Finish Time Step Loop");
    output();
    return 0;
}
