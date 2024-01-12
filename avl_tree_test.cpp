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


}

int main()
{
    test_constructor();
    return 0;
}