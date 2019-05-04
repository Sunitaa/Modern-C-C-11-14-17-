/*
 Before C++11, there were many initialization notation, which has been cleaned up in C++11
 and uniform initilization syntax {} for any data type has been introduced.
*/

class Person
{
private:
    int m_age = 10; //C++ 11 only, in class intialization of data members
    int m_height;
    int m_array [5];
public:
    Person(int age, int height);
};

Person::Person(int age, int height) : m_array {50, 60, 70, 80, 90} // member array initializer
{
    //...
}

int main(void)
{
    Person person {10, 140}; //C++11 only and is equivalent to Person person(10,140);

    //initialize dynamically allocated array while being created
    int *array = new int[3] {3, 6, 9 }; //C++11 only

    //With respect to containers, long list of push_back() calls is not required now.
    //Instead initialize containers intuitively using { }:
    std:vector<string> rankVector = { "first", "second", "third"};

    std::map marksMap = { {"Physics", 70},
                          {"Chmistry", 80},
                          {"Maths", 90}
                        };

}
