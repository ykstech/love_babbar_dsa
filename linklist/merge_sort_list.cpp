#include <iostream>
#include <bits/stdc++.h>
#include "linkedlist.h"
using namespace std;
using namespace singlell;

node *merge(node *left, node *right)
{

    if (left == NULL)
        return right;

    if (right == NULL)
        return left;

    node *ans = new node(-1);
    node *temp = ans;

    while (left != NULL && right != NULL)
    {
        if (left->data < right->data)
        {
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else
        {
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }

    while (left != NULL)
    {
        temp->next = left;
        temp = left;
        left = left->next;
    }
    while (right != NULL)
    {
        temp->next = right;
        temp = right;
        right = right->next;
    }

    ans= ans->next;
    return ans;
}

node* mergesort(node* head)
{

    if (head == NULL || head->next == NULL)
        return head;

    node *left = head;
    node *mid = getmid(head);
    
    node *right = mid->next;
    mid->next = NULL;

    left = mergesort(left);
    right = mergesort(right);

    node* result = merge(left, right);

    return result;
}

int main()
{

   node* node1= new node(1);
   node* head= node1;

   insertathead(head,3);
   insertathead(head,2);
   insertathead(head,9);
   insertathead(head,6);
  print(head);
  node* ans= mergesort(head);
  print(ans);

}