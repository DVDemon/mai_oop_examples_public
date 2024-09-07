#include "../include/solve_func.h"

int solve_func(int lhv, int rhv){
    if (lhv < 0 || rhv < 0) {
        return 0;
    }
    int result;
    result = lhv * rhv - 1;
    return result;
}
