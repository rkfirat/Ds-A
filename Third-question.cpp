#include <iostream>

using namespace std;

class Node {
    public:
        int data;
        Node* next;
    
        Node (int value) : data(value), next(nullptr) {}
};

class LinkedStack {
    private:
        Node* top;
    public:
        LinkedStack()
        {
            top = nullptr;
        }

        ~LinkedStack()
        {
            while (top)
                pop();
        }

        void push(int value)
        {
            Node *newNode = new Node(value);
            newNode->next = top;
            top = newNode;
        }

        int pop()
        {
            if (isEmpty())
            {
                cout << "Stack is empty. Cannot pop" << endl;
                return -1;
            }

            Node *temp = top;
            int poppedVal = top->data;
            top = top->next;
            delete temp;
            return poppedVal;
        }

        bool isEmpty()
        {
            return (top == nullptr);
        }

        void display()
        {
            if (isEmpty())
            {
                cout << "Stack is empty." << endl;
                return;
            }

            Node *temp = top;
            while (temp)
            {
                cout <<  temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
};

int main() {
    LinkedStack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    stack.display();

    cout << "Popped: " << stack.pop() << endl;
    stack.display();

    stack.pop();
    stack.pop();
    stack.pop();

    return 0;
}