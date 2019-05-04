/*
Lambda expression is an unnamed function used for few lines of code and
reusability of this code may not be required.

It can be used as a function inside std library functions e.g. sort, accumulate
In Qt, a slot connected to a signal can be a lambda function
With C++14, lambdas are generic i.e. specifying the type of variables as auto is sufficient.

General syntax:=>
[ capture clause ] (list_of_parameters) -> return-type
{
   function definition
}

capture clause:=>

Unlike functions, a lambda expression can have access to external variables from the enclosing scope in three ways :
      [&] : Capture all variables by reference
      [=] : Capture all variables by value
      [var1, &var2]: Capture var1 by value and var2 by reference
If capture clause [ ] is empty, lambda function can access only passed and local variables

list_of_parameters:=> like general functions

return_type:=> is optional, but in some cases it is better to specify the return type

*/

#include <iostream>
#include <algorithm>
#include <vector>


int main()
{
    std::vector<int> nums{3, 4, 2, 8, 15, 267};

    auto print = [](const int& n) { std::cout << " " << n; };

    std::cout << "Original values:";
    std::for_each(nums.begin(), nums.end(), print);
    std::cout << '\n';

    //  accesses nums by reference
    auto push = [&] (int m)
    {
        nums.push_back(m);
    };

    // it pushes 20 in both v1 and v2
    push(20);

    std::cout << "After pushing 20: ";
    std::for_each(nums.begin(), nums.end(), print);
    std::cout << '\n';

    // function to sort vector, lambda expression is for sorting in
    // non-decreasing order. Even though compiler can make out return type as
    // bool, but shown here just for explanation

    auto isGreater = [](const int& a, const int& b) -> bool
    {
        return a > b;
    };

    std::sort(nums.begin(), nums.end(), isGreater);
    std::cout << "After sorting: ";
    std::for_each(nums.begin(), nums.end(), print);
    std::cout << '\n';
    return 0;
}
