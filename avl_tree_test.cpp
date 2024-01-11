#include "avl_tree.h"
#include "avl_tree_test.h"
#include <iostream>
#include <string>
#include <assert.h>

using namespace std;

int main()
{
    avl_tree<int, string> tree;
    tree.insert(20, "20");
    tree.insert(4, "4");
    tree.insert(26, "26");
    tree.insert(3, "3");
    tree.insert(9, "9");
    tree.insert(21, "21");
    tree.insert(30, "30");
    tree.insert(2, "2");
    tree.insert(7, "7");
    tree.insert(11, "11");
    tree.insert(15, "15");
    tree.insert(8, "8");
    tree.insert(10, "10");
    tree.insert(14, "14");
    tree.insert(16, "16");
    tree.insert(1, "1");
    tree.insert(25, "25");
    tree.insert(27, "27");
    tree.insert(5, "5");
    tree.insert(6, "6");
    avl_tree<int, string> tree2(tree);
    tree.insert(12, "12");
    tree.insert(13, "13");
    tree.insert(17, "17");
    tree.insert(18, "18");
    tree.insert(19, "19");
    tree.insert(22, "22");
    tree.insert(23, "23");
    tree.insert(24, "24");
    tree.insert(28, "28");
    tree.insert(29, "29");
    tree.insert(31, "31");
    tree.insert(32, "32");
    tree.insert(33, "33");
    tree.insert(34, "34");
    tree.insert(35, "35");
    tree.insert(36, "36");
    tree.insert(37, "37");
    tree.insert(38, "38");
    tree.insert(39, "39");
    tree.insert(40, "40");
    tree.insert(41, "41");

    
    cout << endl;
    tree.graph(cout);
    cout << endl;
    tree2.graph(cout);
    
    tree.clear();
    cout << tree.empty() << endl;
    cout << tree2.empty() << endl;
    tree.graph(cout);
}