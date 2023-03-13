#include "matrix.h"

Matrix::Matrix() {
    generate();
}

Matrix::~Matrix() {
    destroy();
}

void Matrix::generate() {
    // Hardcode for now
    _dim_a.push_back(DIM_A_ROW);
    _dim_a.push_back(DIM_A_COL);
    _dim_b.push_back(DIM_B_ROW);
    _dim_b.push_back(DIM_B_COL);

    mat_a = nullptr;
    mat_b = nullptr;

    // Profile the duration of generating matrix
    auto t1 = std::chrono::high_resolution_clock::now();
    for (int r = 0; r < DIM_A_ROW; r++) {
        for (int c = 0; c < DIM_A_COL; c++) {
            _mat_a[r][c] = rand();
        }
    }
    auto t2 = std::chrono::high_resolution_clock::now();
    auto ms_delta_1 = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
    printf("It takes %d ms to generate a matrix with dim %d.%d\n",ms_delta_1.count, DIM_A_ROW, DIM_A_COL);

    auto t3 = std::chrono::high_resolution_clock::now();
    for (int r = 0; r < DIM_B_ROW; r++) {
        for (int c = 0; c < DIM_B_COL; c++) {
            _mat_b[r][c] = rand();
        }
    }
    auto t4 = std::chrono::high_resolution_clock::now();
    auto ms_delta_2 = std::chrono::duration_cast<std::chrono::milliseconds>(t4 - t3);
    printf("It takes %d ms to generate a matrix with dim %d.%d\n",ms_delta_2.count, DIM_B_ROW, DIM_B_COL);
}

void Matrix::destroy() {
    if (mat_a != nullptr) {
        free(mat_a);
    }
    if (mat_b != nullptr) {
        free(mat_b);
    }
}