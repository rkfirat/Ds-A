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

        bool ExchangeNode(int i, int j)
        {
            if (i == j) return true;

            Node *nodeI = nullptr;
            Node *nodeJ = nullptr;

            int index = 0;
            Node *temp = head;
            while (temp)
            {
                if (index == i) nodeI = temp;
                if (index == j) nodeJ = temp;
                temp = temp->next;
                index++;
            }

            if (!nodeI || !nodeJ)
                return false;

            int tempo = nodeI->data;
            nodeI->data = nodeJ->data;
            nodeJ->data = tempo;
            return true;
        }
};

int main() {
    LinkedList list;

    list.add(10);
    list.add(20);
    list.add(30);
    list.add(40);

    cout << "Orijinal liste: ";
    list.display();

    if (list.ExchangeNode(1, 3)) {
        cout << "1 ve 3 indekslerindeki düğümler değiştirildi: ";
        list.display();
    } else {
        cout << "Geçersiz indisler nedeniyle değişim yapılamadı." << endl;
    }

    if (!list.ExchangeNode(1, 10)) {
        cout << "Geçersiz indisler nedeniyle değişim yapılamadı." << endl;
    }

    return 0;
}