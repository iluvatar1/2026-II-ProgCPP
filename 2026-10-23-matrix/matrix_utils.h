#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <print>

void fill_matrix(std::vector<double> & data, int m, int n);
void print_matrix(const std::vector<double> & data, int m, int n);
void transpose_matrix(const std::vector<double> & indata, int m, int n,
                      std::vector<double> & outdata);
double trace(const std::vector<double> & indata, int m, int n);
void matmul(const std::vector<double> & A, int mA, int nA, 
            const std::vector<double> & B, int mB, int nB,
            std::vector<double> & C, int mC, int nC);
