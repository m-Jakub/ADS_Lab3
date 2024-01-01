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

        Node() : left(nullptr), right(nullptr) {}
        Node(const Key &key, const Info &info) : key(key), info(info), left(nullptr), right(nullptr) {}
    };

    Node *root;
    
    void inorder(ostream &out, Node *subtree) const;
    void graph(ostream &out, Node *subtree, int indent) const;

public:
    avl_tree();
    avl_tree(const avl_tree &src);
    ~avl_tree();
    avl_tree &operator=(const avl_tree &src);
    bool insert(const Key &key, const Info &info);
    bool remove(const Key &key);
    bool search(const Key &key) const;
    bool empty() const;
    void clear();
    void inorder(ostream &out) const;
    void graph(ostream &out) const;
};