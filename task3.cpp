#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node* prev;
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
        newNode->prev = head;
        return;
    }

    Node* last = head->prev;

    newNode->next = head;
    newNode->prev = last;

    last->next = newNode;
    head->prev = newNode;
}
void insertBeginning(int value)
{
    Node* newNode = new Node;
    newNode->data = value;

    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
        newNode->prev = head;
        return;
    }

    Node* last = head->prev;

    newNode->next = head;
    newNode->prev = last;

    last->next = newNode;
    head->prev = newNode;

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
    newNode->prev = temp;

    temp->next->prev = newNode;
    temp->next = newNode;
}

void deleteNode(int value)
{
    if (head == NULL)
    {
        cout << "List is empty!" << endl;
        return;
    }

    Node* current = head;

    do
    {
        if (current->data == value)
        {
            if (current->next == current)
            {
                delete current;
                head = NULL;
                return;
            }

            current->prev->next = current->next;
            current->next->prev = current->prev;

            if (current == head)
            {
                head = current->next;
            }

            delete current;
            return;
        }

        current = current->next;

    } while (current != head);

    cout << "Node not found!" << endl;
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
        cout << temp->data << " <-> ";
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
