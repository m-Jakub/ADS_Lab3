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
            if (insert(key, info, subtree->left))
            {
                subtree->height = max(height(subtree->left), height(subtree->right)) + 1;
                balance(subtree);
                return true;
            }
        }
        else
        {
            if (insert(key, info, subtree->right))
            {
                subtree->height = max(height(subtree->left), height(subtree->right)) + 1;
                balance(subtree);
                return true;
            }
        }
        return false;
    }
    void clear(Node *subtree)
    {
        if (subtree == nullptr)
            return;
        clear(subtree->left);
        clear(subtree->right);
        delete subtree;
    }
    bool remove(const Key &key, Node *&subtree)
    {
        if (subtree == nullptr)
            return false;
        if (key == subtree->key)
        {
            if (subtree->left == nullptr && subtree->right == nullptr)
                {
                delete subtree;
                subtree = nullptr;
                }

            else if (subtree->left == nullptr)
            {
                Node *temp = subtree;
                subtree = subtree->right;
                delete temp;
            }
            else if (subtree->right == nullptr)
            {
                Node *temp = subtree;
                subtree = subtree->left;
                delete temp;
            }
            else
            {
                Node *temp = subtree->right;
                while (temp->left != nullptr)
                    temp = temp->left;
                swap(subtree->key, temp->key);
                swap(subtree->info, temp->info);
                remove(key, subtree->right);
            }
            return true;
        }
        if (key < subtree->key)
        {
            if (remove(key, subtree->left))
            {
                subtree->height = max(height(subtree->left), height(subtree->right)) + 1;
                balance(subtree);
                return true;
            }
        }
        else
        {
            if (remove(key, subtree->right))
            {
                subtree->height = max(height(subtree->left), height(subtree->right)) + 1;
                balance(subtree);
                return true;
            }
        }
        return false;
    }
    Node *search(const Key &key, Node *subtree)
    {
        if (subtree == nullptr)
            return nullptr;
        if (key == subtree->key)
            return subtree;
        if (key < subtree->key)
            return search(key, subtree->left);
        else
            return search(key, subtree->right);
    }
    void inorder(ostream &out, Node *subtree) const
    {
        if (subtree == nullptr)
            return;
        inorder(out, subtree->left);
        out << subtree->key << " ";
        inorder(out, subtree->right);
    }
    void graph(ostream &out, Node *subtree, int indent) const
    {
        if (subtree == nullptr)
            return;
        graph(out, subtree->right, indent + 8);
        // out << setw(indent) << " " << subtree->key << endl;
        out << setw(indent) << " " << subtree->height << endl;
        graph(out, subtree->left, indent + 8);
    }
    int height(Node *subtree)
    {
        if (subtree == nullptr)
            return 0;
        return subtree->height;
    }
    int balance_factor(Node *subtree)
    {
        if (subtree == nullptr)
            return 0;
        return height(subtree->right) - height(subtree->left);
    }
    void balance(Node *&subtree)
    {
        int balance = balance_factor(subtree);
        if (balance == 2)
        {
            if (balance == -1)
                right_rotation(subtree->right);
            left_rotation(subtree);
        }
        if (balance == -2)
        {
            if (balance == 1)
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
    bool change_info(const Key &key, const Info &info)
    {
        Node *node = search(key, root);
        if (node == nullptr)
            return false;
        node->info = info;
        return true;
    }
    bool remove(const Key &key) { return remove(key, root); }
    bool search(const Key &key, Info &toReturn)
    {
        Node *node = search(key, root);
        if (node == nullptr)
            return false;
        toReturn = node->info;
        return true;
    }
    bool empty() const { return root == nullptr; }
    void clear()
    {
        clear(root);
        root = nullptr;
    }
    Info &operator[](const Key &key)
    {
        Node *node = search(key, root);
        if (node == nullptr)
        {
            insert(key, Info());
            node = search(key, root);
        }
        return node->info;
    }
    const Info &operator[](const Key &key) const
    {
        Node *node = search(key, root);
        if (node == nullptr)
            throw "Key not found";
        return node->info;
    }
    // {
    //     Node *node = search(key, root);
    //     if (node == nullptr)
    //     {
    //         insert(key, Info());
    //         node = search(key, root);
    //     }
    //     return node->info;
    // }
    // operator-
    void inorder(ostream &out) const { inorder(out, root); }
    void graph(ostream &out) const { graph(out, root, 0); }
};

#endif // AVL_TREE_H

// sprawdzić czy height jest dobrze liczone