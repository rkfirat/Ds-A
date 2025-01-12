#include <iostream>
#include <queue>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};


class BinaryTree {
    private:
        Node* root;
    public:
        BinaryTree()
        {
            root = nullptr;
        }
        void insert(int value)
        {
            Node* newNode = new Node(value);
            if (!root)
            {
                root = newNode;
                return;
            }
            queue<Node *> q;
            q.push(root);

            while (!q.empty())
            {
                Node *temp = q.front();
                q.pop();

                if (!temp->left)
                {
                    temp->left = newNode;
                    return;
                } else {
                    q.push(temp->left);
                }

                if (!temp->right)
                {
                    temp->right = newNode;
                    return;
                } else {
                    q.push(temp->right);
                }
            }
        }

        void OddCount()
        {
            if (!root)
            {
                cout << "Tree is empty" << endl;
                return;
            }
            int count = 0;
            queue<Node *> q;
            q.push(root);

            while (!q.empty())
            {
                Node*   temp = q.front();
                q.pop();

                if (temp->data % 2 == 1)
                    count++;
                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }
            cout << "This tree contains " << count << " odd numbers" << endl;
        }
};

int main() {
    BinaryTree tree;

    // Adding elements to the binary tree
    tree.insert(10);
    tree.insert(15);
    tree.insert(20);
    tree.insert(25);
    tree.insert(30);

    // Display count of odd numbers
    tree.OddCount();

    return 0;
}
