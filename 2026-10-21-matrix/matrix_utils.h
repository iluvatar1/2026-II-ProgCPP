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
