#ifndef BS_TREE_HPP
#define BS_TREE_HPP

#include "bt_node.hpp"
#include <iostream>

template <typename T>
class BSTree {
public:
    BSTree() : root(nullptr) {}
    ~BSTree() { clear(root); }

    void insert(const T& data) {
        root = insert(root, data);
    }

    void remove(const T& data) {
        root = remove(root, data);
    }

    bool find(const T& data) const {
        return find(root, data);
    }

    void inorder() const {
        inorder(root);
        std::cout << std::endl;
    }

    void preorder() const {
        preorder(root);
        std::cout << std::endl;
    }

    void postorder() const {
        postorder(root);
        std::cout << std::endl;
    }

private:
    BTNode<T>* root;

    BTNode<T>* insert(BTNode<T>* node, const T& data) {
        if (!node) {
            return new BTNode<T>(data);
        }
        if (data < node->data) {
            node->left = insert(node->left, data);
        } else {
            node->right = insert(node->right, data);
        }
        return node;
    }

    BTNode<T>* remove(BTNode<T>* node, const T& data) {
        if (!node) return node;
        if (data < node->data) {
            node->left = remove(node->left, data);
        } else if (data > node->data) {
            node->right = remove(node->right, data);
        } else {
            if (!node->left) {
                BTNode<T>* rightChild = node->right;
                delete node;
                return rightChild;
            } else if (!node->right) {
                BTNode<T>* leftChild = node->left;
                delete node;
                return leftChild;
            }
            BTNode<T>* minNode = findMin(node->right);
            node->data = minNode->data;
            node->right = remove(node->right, minNode->data);
        }
        return node;
    }

    BTNode<T>* findMin(BTNode<T>* node) const {
        while (node->left) {
            node = node->left;
        }
        return node;
    }

    bool find(BTNode<T>* node, const T& data) const {
        if (!node) return false;
        if (data < node->data) return find(node->left, data);
        if (data > node->data) return find(node->right, data);
        return true;
    }

    void inorder(BTNode<T>* node) const {
        if (node) {
            inorder(node->left);
            std::cout << node->data << " ";
            inorder(node->right);
        }
    }

    void preorder(BTNode<T>* node) const {
        if (node) {
            std::cout << node->data << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }

    void postorder(BTNode<T>* node) const {
        if (node) {
            postorder(node->left);
            postorder(node->right);
            std::cout << node->data << " ";
        }
    }

    void clear(BTNode<T>* node) {
        if (node) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }
};

#endif // BS_TREE_HPP
