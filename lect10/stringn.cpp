#include<iostream>
#include<sstream>
using namespace std;
int main()
{
    int i=20;
    ostringstream str1;
    str1<<i;
    string geek=str1.str();
    cout<<geek;
    return 0;
}