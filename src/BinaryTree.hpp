#pragma once
#ifndef BINARY_TREE
#define BINARY_TREE
#include <iostream>

template <typename T>
class BinaryTree
{
private:
    class Node
    {
    public:
        T value;
        Node* left, * right;

        Node(const T& value)
            : left(nullptr), right(nullptr), value(value)
        {}

        Node(const Node& node)
            : value(node.value), left(nullptr), right(nullptr)
        {}
    }*root;

    Node* insert(T value, Node*& node)
    {
        if (node == nullptr)
        {
            node = new Node(value);
            return node;
        }

        if (value < node->value)
            insert(value, node->left);
        else if (value > node->value)
            insert(value, node->right);
        else
            return nullptr;

        return node;
    }

    T delete_min(Node*& root)
    {
        if (root->left == NULL)
        {
            T temp = root->value;
            root = root->right;
            return temp;
        }
        else
            return delete_min(root->left);
    }

    void erase(T value, Node*& root)
    {
        Node* temp;
        if (root == NULL)
            return;
        else if (value < root->value)
            erase(value, root->left);
        else if (value > root->value)
            erase(value, root->right);
        else if ((root->left == NULL) && (root->right == NULL))
        {
            temp = root;
            delete temp;
            root = NULL;
        }
        else if (root->left == NULL)
        {
            temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == NULL)
        {
            temp = root;
            root = root->left;
            delete temp;
        }
        else
            root->value = delete_min(root->right);
    }

    void print(Node* ptr, int space = 0) const
    {
        if (ptr == NULL)
            return;

        print(ptr->right, space + 1);

        std::cout << std::endl;
        for (int i = 0; i < space; i++)
            std::cout << "     ";
        std::cout << '[' << ptr->value << ']' << std::endl;

        print(ptr->left, space + 1);
    }

    Node* copy_tree(Node* node)
    {
        if (node == nullptr)
            return nullptr;
        Node* new_node = new Node(*node);
        new_node->left = copy_tree(node->left);
        new_node->right = copy_tree(node->right);
        return new_node;
    }

    void delete_tree(Node* node)
    {
        if (node)
        {
            delete_tree(node->left);
            delete_tree(node->right);
            delete node;
        }
    }

public:

    BinaryTree()
        : root(nullptr)
    {}

    BinaryTree(const BinaryTree<T>& tree)
        : root(nullptr)
    {
        root = copy_tree(tree.root);
    }

    ~BinaryTree()
    {
        delete_tree(root);
    }

    BinaryTree<T>& operator =(const BinaryTree<T>& tree)
    {
        BinaryTree res(tree);
        std::swap(root, res.root);
        return *this;
    }

    bool insert(T value)
    {
        if (insert(value, root))
            return true;
        return false;
    }

    void print() const
    {
        print(root);
    }

    void erase(T value)
    {
        erase(value, root);
    }
};
#endif