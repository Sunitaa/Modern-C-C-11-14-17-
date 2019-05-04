#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>

/*
This example demonstrates the use of for_each() and lambda function.
It uses a lambda function to increment all of the elements of a vector
and then uses a lambda function to compute their sum.
Note that to compute the sum, the dedicated algorithm std::accumulate
can be used as well.

template< class InputIt, class UnaryFunction >
UnaryFunction for_each( InputIt first, InputIt last, UnaryFunction f );

*/

int main()
{
    std::vector<int> nums{3, 4, 2, 8, 15, 267};

    auto print = [](const int& n) { std::cout << " " << n; };

    std::cout << "Original values:";
    std::for_each(nums.begin(), nums.end(), print);
    std::cout << '\n';

    int sum=0;
    std::for_each(nums.begin(), nums.end(), [&sum](int n) {sum+=n;});
    std::cout << "Sum = " << sum << '\n';

    std::for_each(nums.begin(), nums.end(), [](int &n){ n++; });

    std::cout << "After incrementing: ";
    std::for_each(nums.begin(), nums.end(), print);
    std::cout << '\n';

    sum = 0;
    auto sumFunc = [& sum](const int n){sum+=n;};
    std::for_each(nums.begin(), nums.end(), sumFunc);
    std::cout << "Sum = " << sum << '\n';

    sum = std::accumulate(nums.begin(), nums.end(), 0);
    std::cout << "Sum calculated using accumulate function defined in numeric header = " << sum << '\n';

    // function to sort vector, lambda expression is for sorting in
    // non-decreasing order Compiler can make out return type as
    // bool, but shown here just for explanation

    auto isGreater = [](const int& a, const int& b) -> bool
    {
        return a > b;
    };

    std::sort(nums.begin(), nums.end(), isGreater);
    std::cout << "After sorting: ";
    std::for_each(nums.begin(), nums.end(), print);
    std::cout << '\n';
}
