#include <iostream>

using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node (int value) : data(value), next(nullptr) {}
};

class LinkedList {
    public:
        Node* head;
        LinkedList()
        {
            head = nullptr;
        }
        void insert(int value)
        {
            Node* newNode = new Node(value);
            if (!head)
            {
                head = newNode;
            } else {
                Node *temp = head;
                while (temp->next)
                    temp = temp->next;
                temp->next = newNode;
            }
        }
        void display()
        {
            Node *temp = head;
            while (temp)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
};

Node* mergeLinkedList(Node* l1, Node* l2)
{
    Node* dummy = new Node(0);
    Node* current = dummy;

    while (l1 && l2)
    {
        if (l1->data < l2->data)
        {
            current->next = l1;
            l1 = l1->next;
        } else {
            current->next = l2;
            l2 = l2->next;
        }
        current = current->next;
    }

    if (l1)
    {
        current->next = l1;
    } else {
        current->next = l2;
    }

    Node* last = dummy->next;
    delete dummy;
    return last;
}

int main() {
    LinkedList list1;
    LinkedList list2;

    list1.insert(1);
    list1.insert(3);
    list1.insert(5);
    list1.insert(7);

    list2.insert(2);
    list2.insert(4);
    list2.insert(6);
    list2.insert(8);

    cout << "List 1: ";
    list1.display();
    cout << "List 2: ";
    list2.display();

    Node* mergedHead = mergeLinkedList(list1.head, list2.head);

    cout << "Merged List: ";
    Node* temp = mergedHead;
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;

    return 0;
}