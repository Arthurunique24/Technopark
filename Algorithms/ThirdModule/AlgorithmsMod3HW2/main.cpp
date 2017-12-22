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
};

class BinaryTree {
public :
    BinaryTree();
    ~BinaryTree();

    void Insert(const int &);
    void PrintPreOrder();

private :
    Node* root;
    void PrintPreOrderHelper(Node *);
};

BinaryTree::BinaryTree(): root(nullptr) {

}

BinaryTree::~BinaryTree() {
    if (root == nullptr) {
        return;
    }

    if(root->left == nullptr && root->right == nullptr) {
        delete root;
    } else if(root->left == nullptr) {
        Node* tmp = root->right;
        root = tmp;
        tmp->left = nullptr;
        tmp->right = nullptr;
        delete tmp;
    } else {
        Node *tmpR = root->right;
        Node *tmpL = root->left;

        while (tmpR->right) {
            tmpL = tmpR;
            tmpR = tmpR->right;
        }
        tmpL->right = tmpR->left;
        tmpR->left = nullptr;
        root->data = tmpR->data;

        delete tmpL;
    }
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