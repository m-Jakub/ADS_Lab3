#ifndef AVL_TREE_H
#define AVL_TREE_H

#include <iostream>
#include <string>
#include "avl_tree_test.h"
#include <iomanip>

using namespace std;

template <typename Key, typename Info>
class avl_tree
{
private:
    struct Node
    {
        Key key;
        Info info;
        Node *left;
        Node *right;
        int height = 1;

        Node() : left(nullptr), right(nullptr) {}
        Node(const Key &key, const Info &info) : key(key), info(info), left(nullptr), right(nullptr) {}
    };

    Node *root;

    bool insert(const Key &key, const Info &info, Node *&subtree)
    {
        if (subtree == nullptr)
        {
            subtree = new Node(key, info);
            return true;
        }
        if (key == subtree->key)
        {
            return false;
        }
        if (key < subtree->key)
        {
            insert(key, info, subtree->left);
            subtree->height = max(height(subtree->left), height(subtree->right)) + 1;
            balance(subtree);
            return true;
        }
        else
        {
            insert(key, info, subtree->right);
            subtree->height = max(height(subtree->left), height(subtree->right)) + 1;
            balance(subtree);
            return true;
        }
    }
    void remove(const Key &key, Node *&subtree);
    // void search();
    void inorder(ostream &out, Node *subtree) const;
    void graph(ostream &out, Node *subtree, int indent) const
    {
        if (subtree == nullptr)
            return;
        graph(out, subtree->right, indent + 8);
        out << setw(indent) << " " << subtree->key << endl;
        graph(out, subtree->left, indent + 8);
    }
    int height(Node *subtree)
    {
        if (subtree == nullptr)
            return 0;
        return subtree->height;
    }
    int balance_factor(Node *subtree) { return height(subtree->right) - height(subtree->left); }
    void balance(Node *&subtree)
    {
        if (balance_factor(subtree) == 2)
        {
            if (balance_factor(subtree->right) == -1)
                right_rotation(subtree->right);
            left_rotation(subtree);
        }
        if (balance_factor(subtree) == -2)
        {
            if (balance_factor(subtree->left) == 1)
                left_rotation(subtree->left);
            right_rotation(subtree);
        }
    }
    void left_rotation(Node *&subtree)
    {
        Node *temp = subtree->right;
        subtree->right = temp->left;
        temp->left = subtree;
        subtree = temp;
        subtree->left->height = max(height(subtree->left->left), height(subtree->left->right)) + 1;
        subtree->height = max(height(subtree->left), height(subtree->right)) + 1;
    }
    void right_rotation(Node *&subtree)
    {
        Node *temp = subtree->left;
        subtree->left = temp->right;
        temp->right = subtree;
        subtree = temp;
        subtree->right->height = max(height(subtree->right->left), height(subtree->right->right)) + 1;
        subtree->height = max(height(subtree->left), height(subtree->right)) + 1;
    }
    Node *copy(Node *subtree)
    {
        if (subtree == nullptr)
            return nullptr;
        Node *newNode = new Node(subtree->key, subtree->info);
        newNode->left = copy(subtree->left);
        newNode->right = copy(subtree->right);
        newNode->height = subtree->height;
        return newNode;
    }
    void clear(Node *subtree)
    {
        if (!subtree)
            return;
        clear(subtree->left);
        clear(subtree->right);
        delete subtree;
        return;
    }

public:
    avl_tree() : root(nullptr) {}
    avl_tree(const avl_tree &src) { root = copy(src.root); }
    ~avl_tree() { clear(); }
    avl_tree &operator=(const avl_tree &src)
    {
        if (this != &src)
        {
            clear();
            root = copy(src.root);
        }
        return *this;
    }
    bool insert(const Key &key, const Info &info) { return insert(key, info, root); }
    bool update_info(const Key &key, const Info &info);
    bool remove(const Key &key);
    bool search(const Key &key, Info &toReturn) const;
    bool empty() const { return root == nullptr; }
    void clear()
    {
        clear(root);
        root = nullptr;
    }
    // indexing operator overloading
    void inorder(ostream &out) const;
    void graph(ostream &out) const { graph(out, root, 0); }
};

#endif // AVL_TREE_H