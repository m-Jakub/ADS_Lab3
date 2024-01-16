#ifndef AVL_TREE_H_TEST
#define AVL_TREE_H_TEST

#include <iostream>
#include <string>
#include "avl_tree.h"

using namespace std;

// public:
//     avl_tree() : root(nullptr) {}
//     avl_tree(const avl_tree &src) { root = copy(src.root); }
//     ~avl_tree() { clear(); }
//     avl_tree &operator=(const avl_tree &src)
//     {
//         if (this != &src)
//         {
//             clear();
//             root = copy(src.root);
//         }
//         return *this;
//     }
//     bool insert(const Key &key, const Info &info) { return insert(key, info, root); }
//     // bool update_info(const Key &key, const Info &info);
//     bool remove(const Key &key) { remove(key, root); }
//     // bool search(const Key &key, Info &toReturn) const;
//     bool empty() const { return root == nullptr; }
//     void clear()
//     {
//         clear(root);
//         root = nullptr;
//     }
//     // indexing operator overloading
//     // operator-
//     // void inorder(ostream &out) const;
//     void graph(ostream &out) const { graph(out, root, 0); }
// };

void test_constructor();
void test_copy_constructor();
void test_assignment_operator();
void test_destructor();
void test_insert();
void test_change_info();
void test_remove();
void test_search();
void test_empty();
void test_clear();
void test_indexing_operator();
void test_inorder();
void test_graph();
void test_grapgh_with_balance_factor();

#endif // AVL_TREE_H_TEST