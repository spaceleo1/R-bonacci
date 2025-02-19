#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <string>
#include <cstring>
#include <complex>

typedef long long ll;
typedef std::vector<std::vector<ll> > matrix;

ll MOD = 1000000009;
int n, k;
matrix q;

void print(const matrix &M) {
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            std::cout << M[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

matrix matrixProduct(const matrix &A, const matrix &B) {
    matrix C;
    for (int i = 0; i < k; i++) {
        C.push_back(std::vector<ll>(k));
        for (int j = 0; j < k; j++) {
            C[i][j] = 0;
            for (int z = 0; z < k; z++) {
                C[i][j] += (A[i][z] * B[z][j]) % MOD;
                while (C[i][j] < 0) {
                    C[i][j] = (C[i][j] + MOD) % MOD;
                }
            }
        }
    }
    return C;
}

matrix matrixPower(matrix &M, int power) {
    matrix result;
    for (int i = 0; i < k; i++) {
        result.push_back(std::vector<ll>(k, 0));
        result[i][i] = 1;
    }

    while (power) {
        if (power & 1) {
            result = matrixProduct(result, M);
        }
        M = matrixProduct(M, M);
        power >>= 1;
    }
    return result;
}

int main() {
    std::cout << "N-th element of R-bonacci sequence modulo MOD" << std::endl;

    std::cout << "R: " << std::flush;
    std::cin >> k;

    std::cout << "N: " << std::flush;
    std::cin >> n;

    std::cout << "MOD: " << std::flush;
    std::cin >> MOD;

    for (int i = 0; i < k; i++) {
        q.push_back(std::vector<ll>(k));
        for (int j = 0; j < k; j++) {
            q[i][j] = 0;
        }
    }
    for (int i = 0; i < k; i++) {
        q[i][0] = 1;
    }
    for (int i = 0; i < k; i++) {
        for (int j = 1; j < k; j++) {
            if (j - 1 == i) {
                q[i][j] = 1;
            }
        }
    }

    auto answer = matrixPower(q, n);
    std::cout << answer[0][0] << std::endl;
    return 0;
}
