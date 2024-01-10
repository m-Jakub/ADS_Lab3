#include <iostream>

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
        int height;

        Node() : left(nullptr), right(nullptr) {}
        Node(const Key &key, const Info &info) : key(key), info(info), left(nullptr), right(nullptr) {}
    };

    Node *root;

    void search(const DataType &item, bool &found, BinNodePointer &locptr, BinNodePointer &parent);
    void inorder(ostream &out, Node *subtree) const;
    void graph(ostream &out, Node *subtree, int indent) const;
    void left_rotation(Node *&subtree);
    void right_rotation(Node *&subtree);
    Node *copy(Node *subtree)
    {
        if (subtree == nullptr)
            return nullptr;
        Node *newNode = new Node(subtree->key, subtree->info);
        newNode->left = copy(subtree->left);
        newNode->right = copy(subtree->right);
        newNode->height = subtree->height;
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
    bool insert(const Key &key, const Info &info);
    bool remove(const Key &key);
    bool search(const Key &key) const;
    bool empty() const { return root == nullptr; }
    void clear()
    {
        clear(root);
        root = nullptr;
    }
    // indexing operator overloading
    void inorder(ostream &out) const;
    void graph(ostream &out) const;
};