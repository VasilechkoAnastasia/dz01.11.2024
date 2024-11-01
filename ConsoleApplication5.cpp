#include <iostream>
#include <cstring>
using namespace std;

class MyString
{
    char* str;

public:
    MyString(const char* s = "")
    {
        str = new char[strlen(s) + 1];
        strcpy_s(str, strlen(s) + 1, s); 
    }

    ~MyString()
    {
        delete[] str;
    }

    const char* getStr() const
    {
        return str;
    }

    ostream& operator<<(ostream& os) const
    {
        os << str;
        return os;
    }

    istream& operator>>(istream& is)
    {
        char buffer[100];
        is.getline(buffer, sizeof(buffer)); 
        delete[] str;
        str = new char[strlen(buffer) + 1];
        strcpy_s(str, strlen(buffer) + 1, buffer);
        return is;
    }
};

ostream& operator<<(ostream& os, const MyString& myStr)
{
    return os << myStr.getStr();
}

istream& operator>>(istream& is, MyString& myStr)
{
    return myStr.operator>>(is);
}

int main()
{
    MyString myStr;
    cout << "Input text: ";
    cin >> myStr; 
    cout << "Your text: " << myStr << endl; 
}