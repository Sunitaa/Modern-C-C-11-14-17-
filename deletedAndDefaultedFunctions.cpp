#include <iostream>

/*  Defaulted functions:
    The =default; part instructs the compiler to generate the default implementation for the function.
    Defaulted functions have two advantages:
    - They are more efficient than manual implementations, and
    - They rid the programmer from the chore of defining those functions manually.

    The opposite of a defaulted function is a deleted function:
    int func()=delete;
    Deleted functions are useful for preventing object copying, among the rest.
    Recall that C++ automatically declares a copy constructor and an assignment operator for classes.
    To disable copying, declare these two special member functions =delete.
    */

struct ClassWithDeletedAndDefaultedFunctions
{

 ClassWithDeletedAndDefaultedFunctions & operator =( const ClassWithDeletedAndDefaultedFunctions & ) = delete;

 ClassWithDeletedAndDefaultedFunctions ( const ClassWithDeletedAndDefaultedFunctions & ) = delete;

 ClassWithDeletedAndDefaultedFunctions()=default; //C++11 default implementation of constructor

 virtual ~ClassWithDeletedAndDefaultedFunctions()=default; //C++11 , default implementation of destructor


};

int main(void)
{
    ClassWithDeletedAndDefaultedFunctions nonCopyableObj;

    ClassWithDeletedAndDefaultedFunctions copyObj(nonCopyableObj); //compilation error, because copy custructor is deleted

    ClassWithDeletedAndDefaultedFunctions assignedObj = nonCopyableObj; //compilation error, because assignment operator is deleted
}

/*
main.cpp:44:65: error: use of deleted function ‘ClassWithDeletedAndDefaultedFunctions::ClassWithDeletedAndDefaultedFunctions(const ClassWithDeletedAndDefaultedFunctions&)’
     ClassWithDeletedAndDefaultedFunctions copyObj(nonCopyableObj); //compilation error, because copy custructor is deleted
                                                                 ^
main.cpp:21:2: note: declared here
  ClassWithDeletedAndDefaultedFunctions ( const ClassWithDeletedAndDefaultedFunctions & ) = delete;
  ^
main.cpp:46:57: error: use of deleted function ‘ClassWithDeletedAndDefaultedFunctions::ClassWithDeletedAndDefaultedFunctions(const ClassWithDeletedAndDefaultedFunctions&)’
     ClassWithDeletedAndDefaultedFunctions assignedObj = nonCopyableObj; //compilation error, because copy custructor is deleted
                                                         ^
main.cpp:21:2: note: declared here
  ClassWithDeletedAndDefaultedFunctions ( const ClassWithDeletedAndDefaultedFunctions & ) = delete;
  ^
  */
