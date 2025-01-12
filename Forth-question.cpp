#include <iostream>

using namespace std;

class Node {
    public:
        int data;
        Node* next;
    
        Node (int value) : data(value), next(nullptr) {}
};

class LinkedList {
    private:
        Node* head;
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
                return;
            }

            Node* temp = head;
            while (temp->next)
                temp = temp->next;
            temp->next = newNode;
        }

        void display()
        {
            if (head)
            {
                Node* temp = head;
                while (temp)
                {
                    cout << temp->data << " ";
                    temp = temp->next;
                }
            } else {
                cout << "LinkedList is empty" << endl;
            }
        }

        void deleteNth(int index)
        {
            if (!head)
            {
                cout << "LinkedList is empty" << endl;
                return;
            }

            if (index == 1)
            {
                Node* temp = head;
                head = head->next;
                delete temp;
                return;
            }
            Node* temp = head;
            int count = 1;
            while (temp && count < index - 1)
            {
                temp = temp->next;
                count++;
            }

            if (!temp || !temp->next)            
            {
                cout << "Node could not found!" << endl;
                return;
            }
            Node* nodeToDelete = temp->next;
            temp->next = temp->next->next;
            delete nodeToDelete;
        }
};


int main() {
    LinkedList list;

    // Listeye bazı elemanlar ekleyelim
    list.add(1);
    list.add(2);
    list.add(3);
    list.add(4);
    list.add(5);
 
    cout << "Orijinal liste: ";
    list.display();
    cout << endl;

    list.deleteNth(2);

    cout << "Değiştirilmiş liste: ";
    list.display();
    cout << endl;
    
    return 0;
}