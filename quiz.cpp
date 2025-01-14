#include <iostream>

using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node (int value)
    {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
    private:
        Node* head;
    public:
    public:
        LinkedList()
        {
            head = nullptr;
        }
        void add(int value)
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

        int OddCount()
        {
            Node *temp = head;
            int count = 0;
            while (temp)
            {
                if (temp->data % 2 == 1)
                    count++;
                temp = temp->next;
            }

            //Part B

            Node* newNode = new Node(count);
            newNode->next = head;
            head = newNode;
            return count;
        }
};


int main() {
    LinkedList list;

    list.add(11);
    list.add(20);
    list.add(35);
    list.add(40);

    cout << "Original list: ";
    list.display();
    cout << endl;

    cout << "Linked List has " << list.OddCount() << " odd numbers" << endl;

    cout << "Last list : ";
    list.display();
    return 0;
}