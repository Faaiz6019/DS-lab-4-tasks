#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* head = NULL;

void insertEnd(int value)
{
    Node* newNode = new Node;
    newNode->data = value;

    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
        return;
    }

    Node* temp = head;

    while (temp->next != head)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
}

void insertBeginning(int value)
{
    Node* newNode = new Node;
    newNode->data = value;

    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
        return;
    }

    Node* temp = head;

    while (temp->next != head)
    {
        temp = temp->next;
    }

    newNode->next = head;
    temp->next = newNode;
    head = newNode;
}

void insertPosition(int value, int position)
{
    if (position == 1)
    {
        insertBeginning(value);
        return;
    }

    if (head == NULL)
    {
        cout << "Invalid position!" << endl;
        return;
    }

    Node* temp = head;

    for (int i = 1; i < position - 1; i++)
    {
        temp = temp->next;

        if (temp == head)
        {
            cout << "Invalid position!" << endl;
            return;
        }
    }

    Node* newNode = new Node;
    newNode->data = value;

    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteNode(int value)
{
    if (head == NULL)
    {
        cout << "List is empty!" << endl;
        return;
    }

    if (head->data == value)
    {
        if (head->next == head)
        {
            delete head;
            head = NULL;
            return;
        }

        Node* last = head;

        while (last->next != head)
        {
            last = last->next;
        }

        Node* temp = head;
        head = head->next;
        last->next = head;

        delete temp;
        return;
    }

    Node* current = head;

    while (current->next != head &&
           current->next->data != value)
    {
        current = current->next;
    }

    if (current->next == head)
    {
        cout << "Node not found!" << endl;
        return;
    }

    Node* temp = current->next;
    current->next = temp->next;

    delete temp;
}
void display()
{
    if (head == NULL)
    {
        cout << "List is empty!" << endl;
        return;
    }

    Node* temp = head;

    do
    {
        cout << temp->data << " -> ";
        temp = temp->next;

    } while (temp != head);

    cout << "HEAD" << endl;
}

int main(){
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);

    cout << "Original List:" << endl;
    display();

    cout << "\nInsert 40 at end:" << endl;
    insertEnd(40);
    display();

    cout << "\nInsert 5 at beginning:" << endl;
    insertBeginning(5);
    display();

    cout << "\nInsert 15 at position 3:" << endl;
    insertPosition(15, 3);
    display();

    cout << "\nDelete node 20:" << endl;
    deleteNode(20);
    display();

    return 0;
}
