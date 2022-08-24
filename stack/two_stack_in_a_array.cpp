#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class twostack
{

    int top1;
    int top2;
    int size;
    int *arr;

public:
    twostack(int s)
    {
        this->size = s;
        top1 = -1;
        top2 = s;
        arr = new int[s];
    }

    void Push1(int data)
    {
        if (top2 - top1 > 1)
        {
            top1++;
            arr[top1] = data;
        }
        else
        {
            cout << "stack overflow" << endl;
        }
    }
    void Push2(int data)
    {
        if (top2 - top1 > 1)
        {
            top2--;
            arr[top2] = data;
        }
        else
        {
            cout << "stack overflow" << endl;
        }
    }

    int Pop1()
    {
        if (top1 >= 0)
        {
            return arr[top1--];
        }
        else
        {
            cout << "underflow" << endl;
            return -1;
        }
    }

    int Pop2()
    {
        if (top2 < size)
        {
            return arr[top2++];
        }
        else
        {
            cout << "underflow" << endl;
            return -1;
        }
    }
};

int main(){

twostack s(5);
s.Push1(1);
s.Push1(2);
s.Push1(3);
s.Push2(4);
s.Push2(5);

cout<<s.Pop1()<<endl;
cout<<s.Pop1()<<endl;
cout<<s.Pop1()<<endl;
cout<<s.Pop2()<<endl;
cout<<s.Pop2()<<endl;
cout<<s.Pop2()<<endl;



}