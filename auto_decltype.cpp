#include <iostream>
#include <vector>

/*
auto:
 Automatic type deduction, i.e. declare an object without specifying the type explicitly.
 Very useful when the type of the object is verbose or
 when it's automatically generated (in templates or lambda function)

 auto no longer designates an object with automatic storage type.
 Rather, it declares an object whose type is deducible from its initializer.
 The old meaning of auto was removed from C++11 to avoid confusion.


decltype:
 It is a mechanism for capturing the type of an object or an expression.
 The new operator decltype takes an expression and "returns" its type.

const vector<int> vi;
typedef decltype (vi.begin()) CIT;

CIT another_const_iterator;
*/

void printVector(const std::vector<int> &vec)
{
    //vector<int>::const_iterator cbegin=vec.begin();//This is too verbose
    auto cIter = vec.begin();//auto saves us from typing the big data types
    auto cEnd = vec.end();
    while (cIter != cEnd)
    {
        std::cout<<*cIter<<"\n";
        ++cIter;
    }

    //decltype would capture the type of cIter and define as CIT
    typedef decltype (cIter) CIT;
    CIT anotherConstIterator = vec.begin();

    std::cout<<"Printing the same vector again with anotherConstIterator\n";
    while (anotherConstIterator != cEnd)
    {
        std::cout<<*anotherConstIterator<<"\n";
        ++anotherConstIterator;
    }
}

int main()
{
    std::vector<int> vec = {10,20,30};
    printVector(vec);
}
