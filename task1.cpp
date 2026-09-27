#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

void insert(Node*& head, int value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node* temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

void evenBeforeOdd(Node*& head)
{
    if (head == NULL || head->next == NULL)
        return;

    Node* evenHead = NULL;
    Node* evenTail = NULL;

    Node* oddHead = NULL;
    Node* oddTail = NULL;

    Node* current = head;

    while (current != NULL)
    {
        Node* nextNode = current->next;

        current->next = NULL;

        if (current->data % 2 == 0)
        {
            if (evenHead == NULL)
            {
                evenHead = current;
                evenTail = current;
            }
            else
            {
                evenTail->next = current;
                evenTail = current;
            }
        }
        else
        {
            if (oddHead == NULL)
            {
                oddHead = current;
                oddTail = current;
            }
            else
            {
                oddTail->next = current;
                oddTail = current;
            }
        }

        current = nextNode;
    }

    if (evenHead == NULL)
    {
        head = oddHead;
        return;
    }

    evenTail->next = oddHead;

    head = evenHead;
}

void display(Node* head)
{
    while (head != NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }

    cout << "NULL" << endl;
}

int main()
{
    Node* head = NULL;

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";

    for (int i = 0; i < n; i++)
    {
        int value;
        cin >> value;
        insert(head, value);
    }

    cout << "\nOriginal List: ";
    display(head);

    evenBeforeOdd(head);

    cout << "Modified List: ";
    display(head);

    return 0;
}
