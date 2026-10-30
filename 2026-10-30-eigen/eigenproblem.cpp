#include <iostream>
#include <print>
#include <chrono>
#include <string>
#include <complex>
#include <eigen3/Eigen/Dense>

int main(int argc, char **argv) {
    if (argc < 2) {
        std::println(stderr, "Usage: {} <matrix_size_N>", argv[0]);
        return 1;
    }

    // read the matrix ncols, to be NxN
    const int N = std::stoi(argv[1]);

    // create a random matrix
    Eigen::MatrixXd A = Eigen::MatrixXd::Random(N, N);
    // std::println("Here is a random matrix, A:");
    // std::cout << A << "\n\n";

    // Measure time spent solving the eigenvalue problem
    auto start = std::chrono::high_resolution_clock::now();

    // create an eigen solver with that matrix. 
    // Once created it solves everything immediately
    Eigen::EigenSolver<Eigen::MatrixXd> es(A);

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration_ms = end - start;

    std::println("Time spent solving the eigen problem: {:.4f} ms\n", duration_ms.count());

    // // print some results
    // std::println("The eigenvalues of A are:");
    // std::cout << es.eigenvalues() << "\n\n";

    // std::println("The matrix of eigenvectors, V, is:");
    // std::cout << es.eigenvectors() << "\n\n";

    // Check the first eigenvalue: Av = lambda * v
    std::complex<double> lambda = es.eigenvalues()[0];
    std::cout << "Consider the first eigenvalue, lambda = " << lambda << "\n\n";

    // Eigen::VectorXcd v = es.eigenvectors().col(0);
    // std::println("If v is the corresponding eigenvector, then lambda * v =");
    // std::cout << lambda * v << "\n\n";

    // std::println("... and A * v =");
    // std::cout << A.cast<std::complex<double>>() * v << "\n\n";

    // // Diagonalization check
    // Eigen::MatrixXcd D = es.eigenvalues().asDiagonal();
    // Eigen::MatrixXcd V = es.eigenvectors();
    // std::println("Finally, V * D * V^(-1) =");
    // std::cout << V * D * V.inverse() << "\n";

    return 0;
}