
#include <iostream>

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};
class BinaryTree {
private:
    Node* root;
    void InsertSimple(Node* node, int value) {
        if (value < node->data) {
            if (node->left == nullptr) {
                node->left = new Node(value);
            }
            else {
                InsertSimple(node->left, value);
            }
        }
        else {
            if (node->right == nullptr)
            {
                node->right = new Node(value);
            }
            else
                InsertSimple(node->right, value);
        }
    }
    Node* RemoveSimple(Node* node, int value)
    {
        if (node == nullptr)
            return nullptr;
        if (node->data == value) {
            if (node->left == nullptr && node->right == nullptr)
            {
                delete node;
                return nullptr;
            }
        }
        if (value < node->data) {
            node->left = RemoveSimple(node->left, value);
        }
        else {
            node->right = RemoveSimple(node->right, value);
        }
        return node;
    }
    void PrintSimple(Node* node, int level)
    {
        if (node != nullptr)
        {
            PrintSimple(node->right, level+1);
            for (int i = 0; i < level; i++)
            {
                std::cout << "    ";
            }
            std::cout << node->data << std::endl;
            PrintSimple(node -> left, level + 1);
        }
    }
public:
    BinaryTree() {
        root = nullptr;
    }
    void insert(int value) {
        if (root == nullptr) {
            root = new Node(value);
        }
        else
            InsertSimple(root, value);
    }
    void remove(int value) {
        root = RemoveSimple(root, value);
    }
    void print() {
        std::cout << "Структура дерева: " << std::endl;
        PrintSimple(root,0);
    }
};
int main()
{
    setlocale(0, "rus");
    BinaryTree tree;
    tree.insert(50);
    tree.insert(20);
    tree.insert(10);
    tree.insert(30);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);
    std::cout << "Дерево: ";
    tree.print();
    tree.remove(30);
    std::cout << "После удаления 30: ";
    tree.print();
}