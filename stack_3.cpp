// string reversal using stack
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack> //stack from standard template library (STL)
using namespace std;

void Reverse(char *c, int n)
{
    stack<char> s;
    // loop for push
    for (int i = 0; i < n; i++)
    {
        s.push(c[i]);
    }

    // loop for pop
    for (int i = 0; i < n; i++)
    {
        c[i] = s.top(); // over writing the character at index i
        s.pop();
    }
}

int main()
{
    char c[51];
    printf("enter a string: ");
    scanf("%s", c);
    Reverse(c, strlen(c));
    printf("output= %s", c);
}