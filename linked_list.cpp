#include <iostream>
using namespace std;
struct node
{
    int val;
    node *next;
};
node *head;
void insert(int d)
{
    node *t = new node;
    t->val = d;
    t->next = head;
    head = t;
}
void insertend(int d)
{
    node *t = new node;
    t->val = d;
    t->next = NULL;
    if (head == NULL)
    {
        head = t;
    }
    else
    {
        node *c = head;
        while (c->next != NULL)
        {
            c = c->next;
        }
        c->next = t;
    }
}
void dis()
{
    node *t = head;
    while (t != NULL)
    {
        cout << t->val << " ";
        t = t->next;
    }
}
void del(int key)
{
    node *temp = head;
    node *prev = head;
    if (temp != NULL && temp->val == key)
    {
        head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->val != key)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return;
    prev->next = temp->next;

    free(temp);
}
void reverse()
{
    node *a = head;
    node *b = NULL;
    node *c;
    while (a != NULL)
    {
        c = a->next;
        a->next = b;
        b = a;
        a = c;
    }
    head = b;
}
int main()
{
    insert(1);
    insert(1);
    insert(1);
    insertend(2);
    insertend(2);
    dis();
    reverse();
    cout << endl;
    dis();
    return 0;
}