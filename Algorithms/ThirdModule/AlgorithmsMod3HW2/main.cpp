#include <iostream>
#include "queue"
#include "stack"

struct Node {
    int data;
    Node* left;
    Node* right;

    explicit Node(const int &value)
            :data(value), left(nullptr), right(nullptr) {

    }
    ~Node() {
        delete left;
        delete right;
    }
};

class BinaryTree {
public :
    BinaryTree();
    ~BinaryTree();

    void Insert(const int &data);
    void PrintPreOrder();

private :
    Node* root;
    void PrintPreOrderHelper(Node *node);
};

BinaryTree::BinaryTree(): root(nullptr) {

}

BinaryTree::~BinaryTree() {
    delete root;
}

void BinaryTree::Insert(const int &data) {
    Node* node = new Node(data);
    if (root == nullptr) {
        root = node;
        return;
    }
    Node* nextNode = root;
    while (true) {
        if (nextNode->data > data) {
            if (nextNode->left != nullptr) {
                nextNode = nextNode->left;
            } else {
                nextNode->left = node;
                return;
            }
        } else {
            if (nextNode->right != nullptr) {
                nextNode = nextNode->right;
            } else {
                nextNode->right = node;
                return;
            }
        }
    }
}

void BinaryTree::PrintPreOrderHelper(Node *node) {
    if (node == nullptr) {
        return;
    }

    std::stack<Node *> nodeStack;
    nodeStack.push(node);

    while (!nodeStack.empty()) {
        Node *tmp = nodeStack.top();
        std::cout << tmp->data << " ";
        nodeStack.pop();

        if (tmp->right) {
            nodeStack.push(tmp->right);
        }
        if (tmp->left) {
            nodeStack.push(tmp->left);
        }
    }

}

void BinaryTree::PrintPreOrder() {
    PrintPreOrderHelper(root);
}

int main() {
    BinaryTree binaryTree;

    int countOfInserts = 0;
    std::cin >> countOfInserts;

    if (countOfInserts <= 0) {
        return 0;
    }

    for(int i = 0; i < countOfInserts; ++i){
        int tmp = 0;
        std::cin >> tmp;

        binaryTree.Insert(tmp);
    }

    binaryTree.PrintPreOrder();
    return 0;
}