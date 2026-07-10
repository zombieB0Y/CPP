#include "PmergeMe.hpp"

int F(int n)
{
    int sum = 0;
    for (int k = 1; k <= n; ++k) {
        double value = (3.0 / 4.0) * k;
        sum += static_cast<int>(ceil(log2(value)));
    }
    return sum;
}

int main() {
	// for (int i = 0; i < 10; ++i) std::cout << _generateJacob(i) << std::endl;
	PmergeMe	p("11 2 17 0 16 8 6 15 10 3 21 1 18 9 14 19 12 5 4 20 13 0");
}