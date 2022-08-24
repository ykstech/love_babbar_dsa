#include <iostream>
#include <bits/stdc++.h>
#include "linkedlist.h"
using namespace std;
using namespace singlell;



node *add(node *first, node *second)
{

    int carry = 0;

        //dummy node//
        node *anstail = NULL;
        node *anshead = NULL;


    while (first != NULL || second != NULL || carry != 0)
    {
        int val = 0;
        if (first != NULL)
            val = first->data;
        int val2 = 0;
        if (second != NULL)
            val2 = second->data;

        int sum = carry + val + val2;

        int digit = sum % 10;

        insertatnulltail(anshead,anstail, digit);

        carry = sum / 10;
        if (first != NULL)
            first = first->next;
        if (second != NULL)
            second = second->next;
    }

    return anshead;
}

node *addtwolistdata(node *first, node *second)
{

    first = reverse(first);
    second = reverse(second);

    node *ans = add(first, second);
    ans = reverse(ans);

    return ans;
}

int main()
{
    node *node1 = new node(9);
    node *head = node1;
    node *tail = node1;
    insertattail(tail, 9);
    insertattail(tail, 9);

    node *node2 = new node(1);
    node *head2 = node2;
    node *tail2 = node2;
    insertattail(tail2, 2);
    insertattail(tail2, 3);

    print(head);
    print(head2);

    node *temp = addtwolistdata(node1, node2);
    print(temp);
}