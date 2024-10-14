#include <iostream>
#include <initializer_list>

class MyString 
{
private:
    char* str;
    size_t size;

public:
    
    MyString() : str(nullptr), size(0) {}

    
    MyString(std::initializer_list<char> initList) 
    {
        size = initList.size(); 
        str = new char[size + 1]; 
        size_t i = 0;
        for (char c : initList) 
        {
            str[i++] = c; 
        }
        str[size] = '\0'; 
    }

    
    ~MyString() 
    {
        delete[] str;
    }

    
    void print() const 
    {
        if (str) {
            std::cout << str << std::endl;
        }
        else 
        {
            std::cout << "Empty string" << std::endl;
        }
    }
};

int main() 
{
    
    MyString obj{ 'H', 'e', 'l', 'l', 'o' };
    obj.print();  

    return 0;
}