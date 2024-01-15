#include "avl_tree.h"
#include "avl_tree_test.h"
#include <iostream>
#include <string>
#include <assert.h>

using namespace std;

void test_constructor()
{
    // empty tree
    avl_tree<string, int> tree_1;
    assert(tree_1.empty());
    
    // tree with one node
    avl_tree<string, int> tree_2;
    tree_2.insert("a", 1);
    assert(!tree_2.empty());

    // adding 15 more nodes
    tree_2.insert("b", 2);
    tree_2.insert("d", 4);
    tree_2.insert("e", 6);
    tree_2.insert("g", 7);
    tree_2.insert("i", 10);
    tree_2.insert("k", 11);
    tree_2.insert("m", 13);
    tree_2.insert("n", 14);
    tree_2.insert("p", 16);
    tree_2.insert("c", 17);
    tree_2.insert("l", 18);
    
    tree_2.graph(cout);
    cout << endl;
    cout << "=====================================" << endl;

    // remove test
    tree_2.remove("d");
    tree_2.insert("h", 18);
    tree_2.graph(cout);
    cout << endl;
    cout << "=====================================" << endl;

    tree_2.remove("c");
    tree_2.graph(cout);
    cout << endl;
    cout << "=====================================" << endl;

}

void test()
{
    avl_tree<float, int> tree;
    tree.insert(1.1, 1);
    tree.insert(2.2, 2);
    tree.insert(3.3, 3);
    tree.insert(4.4, 4);
    tree.insert(5.5, 5);
    tree.insert(6.6, 6);
    tree.insert(7.7, 7);
    tree.insert(8.8, 8);
    tree.insert(9.9, 9);
    tree.insert(10.10, 10);
    tree.insert(11.11, 11);
    tree.insert(12.12, 12);
    tree.insert(13.13, 13);
    tree.insert(14.14, 14);
    tree.insert(15.15, 15);
    tree.insert(16.16, 16);
    tree.insert(17.17, 17);
    tree.insert(18.18, 18);
    tree.insert(19.19, 19);
    tree.insert(20.20, 20);
    tree.insert(21.21, 21);
    tree.insert(22.22, 22);
    tree.insert(23.23, 23);
    tree.insert(24.24, 24);
    tree.insert(25.25, 25);
    tree.insert(26.26, 26);
    tree.insert(27.27, 27);
    tree.insert(28.28, 28);
    tree.insert(29.29, 29);
    tree.insert(30.30, 30);
    tree.insert(31.31, 31);
    tree.insert(32.32, 32);
    tree.insert(33.33, 33);
    tree.insert(34.34, 34);
    tree.remove(29.29);
    tree.graph(cout);
    tree.remove(28.28);
    tree.graph(cout);
    tree.inorder(cout);
}

void test2()
{
    avl_tree<string, int> tree;
    tree.insert("a", 1);
    int a;
    assert(tree.search("a", a));
    cout << a << endl;
    tree.change_info("a", 2);
    assert(tree.search("a", a));
    cout << a << endl;
}

int main()
{
    // test_constructor();
    test();
    // test2();
    return 0;
}