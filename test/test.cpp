#include <iostream>
#include "../src/setup.hpp"
#include "../src/alloc.hpp"
#include "../src/color.hpp"

bool test_allocate_3d_array(int, int, int);

int main() {
    std::cerr << "[main] start test_allocate_3d_array...\n\n";
    test_allocate_3d_array(2, 20, 30);
    return 0;    
}

bool test_allocate_3d_array(int nk, int nj, int ni) {
    auto field = allocate_3d_array<int>(nk, nj, ni);
    for(int k = 0; k < nk; k++) {
        for(int j = 0; j < nj; j++) {
            for(int i = 0; i < ni; i++) {
                field[k][j][i] = i ^ j ^ k;
            }
        }
    }
    bool success = true;
    for(int k = 0; k < nk; k++) {
        for(int j = 0; j < nj; j++) {
            for(int i = 0; i < ni; i++) {
                if(field[k][j][i] != (i ^ j ^ k)) {
                    success = false;
                    std::cerr << RED "[test_allocate_3d_array] Test failed!\n" PLAIN;
                    std::cerr << "\t the value of (" << k << "," << j << "," << i << ") is invalid, ";
                    std::cerr << "\t correct value is " << (i ^ j ^ k) << ", but measured value is " << field[k][j][i] << "!\n\n";
                    break;
                }                              
            }
        }
    }
    if(success) {
        std::cerr << GREEN "[test_allocate_3d_array] Test success!\n\n" PLAIN;
    }
    return success;
}
