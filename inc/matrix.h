#include <cstdlib>
#include <vector>
#include <chrono>
#include <stdio.h>

#define NUM_OF_DIM 2

constexpr int DIM_A_ROW = 1000;
constexpr int DIM_A_COL = 800;
constexpr int DIM_B_ROW = 800;
constexpr int DIM_B_COL = 1000;

class Matrix {
public:
    Matrix();
    ~Matrix();

    void generate();
    void log_mat();
    void multip();
    void multip_ikj();
    void multip_blocking();
private:
    void generate();
    void destroy();
    int _mat_a[DIM_A_ROW][DIM_A_COL];
    int _mat_b[DIM_B_ROW][DIM_B_COL];
    std::vector<int> _dim_a;
    std::vector<int> _dim_b;
    int* mat_a;
    int* mat_b;
};