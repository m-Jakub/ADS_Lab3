#include "avl_tree.h"
#include "avl_tree_test.h"
#include <iostream>
#include <string>
#include <assert.h>
#include <fstream>
#include <chrono>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

void test_constructor()
{
    cout << endl
         << "===== Constructor test =====" << endl;
    avl_tree<string, int> tree_1;
    assert(tree_1.empty());
}

void test_copy_constructor()
{
    cout << endl
         << "===== Copy constructor test =====" << endl;

    avl_tree<string, int> tree_1;

    // copying empty tree
    avl_tree<string, int> tree_2(tree_1);
    assert(tree_2.empty());
    tree_1.insert("a", 1);
    tree_1.insert("b", 2);
    tree_1.insert("c", 3);
    tree_1.insert("d", 4);
    tree_1.insert("e", 5);
    tree_1.insert("f", 6);
    tree_1.insert("g", 7);
    tree_1.insert("h", 8);
    tree_1.insert("i", 9);
    tree_1.insert("j", 10);
    tree_1.insert("k", 11);
    tree_1.insert("l", 12);
    tree_1.insert("m", 13);
    tree_1.insert("n", 14);
    tree_1.insert("o", 15);
    tree_1.insert("p", 16);
    tree_1.insert("q", 17);
    tree_1.insert("r", 18);
    tree_1.insert("s", 19);
    tree_1.insert("t", 20);
    tree_1.insert("u", 21);
    tree_1.insert("v", 22);
    tree_1.insert("w", 23);
    tree_1.insert("x", 24);
    tree_1.insert("y", 25);
    tree_1.insert("z", 26);
    // copying non-empty tree
    avl_tree<string, int> tree_3(tree_1);
    assert(!tree_3.empty());
    int info;
    assert(tree_3.search("a", info));
    assert(tree_3.search("q", info));
    assert(tree_3.search("z", info));
}

void test_assignment_operator()
{
    cout << endl
         << "===== Assignment operator test =====" << endl;

    avl_tree<string, int> tree_1;
    avl_tree<string, int> tree_2;
    // copying empty tree to empty tree
    tree_2 = tree_1;
    assert(tree_2.empty());

    tree_1.insert("a", 1);
    tree_1.insert("b", 2);
    tree_1.insert("c", 3);
    tree_1.insert("d", 4);
    tree_1.insert("e", 5);
    tree_1.insert("f", 6);
    tree_1.insert("g", 7);
    tree_1.insert("h", 8);
    tree_1.insert("i", 9);
    tree_1.insert("j", 10);
    tree_1.insert("k", 11);
    tree_1.insert("l", 12);
    tree_1.insert("m", 13);
    tree_1.insert("n", 14);
    tree_1.insert("o", 15);
    tree_1.insert("p", 16);
    tree_1.insert("q", 17);
    tree_1.insert("r", 18);
    tree_1.insert("s", 19);
    tree_1.insert("t", 20);
    tree_1.insert("u", 21);
    tree_1.insert("v", 22);
    tree_1.insert("w", 23);
    tree_1.insert("x", 24);
    tree_1.insert("y", 25);
    tree_1.insert("z", 26);
    // copying non-empty tree
    tree_2 = tree_1;
    assert(!tree_2.empty());
    int info;
    assert(tree_2.search("a", info));
    assert(tree_2.search("q", info));
    assert(tree_2.search("z", info));
    // self-assignment
    tree_1 = tree_1;
    assert(!tree_1.empty());
    assert(tree_1.search("a", info));
    assert(tree_1.search("q", info));
    assert(tree_1.search("z", info));
    // copying empty tree to non-empty tree
    tree_2.clear();
    tree_1 = tree_2;
    assert(tree_1.empty());
}

void test_destructor()
{
    cout << endl
         << "===== Destructor test =====" << endl;

    avl_tree<string, int> *tree_1 = new avl_tree<string, int>;
    avl_tree<string, int> *tree_2 = new avl_tree<string, int>;

    tree_2->insert("a", 1);
    tree_2->insert("b", 2);
    tree_2->insert("c", 3);

    // deleting empty tree
    delete tree_1;

    // deleting non-empty tree
    delete tree_2;
}

void test_insert()
{
    cout << endl
         << "===== Insert test =====" << endl;

    avl_tree<string, int> tree;

    assert(tree.insert("a", 1));
    assert(tree.insert("b", 2));
    assert(tree.insert("c", 3));
    assert(tree.insert("d", 4));
    assert(tree.insert("e", 5));
    assert(tree.insert("f", 6));
    assert(tree.insert("g", 7));
    assert(tree.insert("h", 8));
    assert(tree.insert("i", 9));
    assert(tree.insert("j", 10));
    assert(!tree.insert("a", 1));
    assert(!tree.insert("b", 2));
    assert(!tree.insert("c", 3));
    assert(!tree.insert("d", 4));
    assert(!tree.insert("e", 5));
    assert(!tree.insert("f", 6));
    assert(!tree.insert("g", 7));
    assert(!tree.insert("h", 8));
    assert(!tree.insert("i", 9));
    assert(!tree.insert("j", 10));
    assert(!tree.empty());

    int info;

    assert(tree.search("a", info));
    assert(info == 1);
    assert(tree.search("e", info));
    assert(info == 5);
    assert(tree.search("j", info));
    assert(info == 10);
}

void test_change_info()
{
    cout << endl
         << "===== Change info test =====" << endl;

    avl_tree<string, int> tree;

    tree.insert("a", 1);
    tree.insert("b", 2);
    tree.insert("c", 3);
    tree.insert("d", 4);
    tree.insert("e", 5);
    tree.insert("f", 6);
    tree.insert("g", 7);
    tree.insert("h", 8);
    tree.insert("i", 9);
    tree.insert("j", 10);

    assert(tree.change_info("a", 11));
    assert(tree.change_info("b", 12));
    assert(tree.change_info("c", 13));
    assert(tree.change_info("d", 14));
    assert(tree.change_info("e", 15));
    assert(tree.change_info("f", 16));
    assert(tree.change_info("g", 17));
    assert(tree.change_info("h", 18));
    assert(tree.change_info("i", 19));
    assert(tree.change_info("j", 20));

    int info;

    assert(tree.search("a", info));
    assert(info == 11);
    assert(tree.search("e", info));
    assert(info == 15);
    assert(tree.search("j", info));
    assert(info == 20);
}

void test_remove()
{
    cout << endl
         << "===== Remove test =====" << endl;

    avl_tree<string, int> tree;

    tree.insert("a", 1);
    tree.insert("b", 2);
    tree.insert("c", 3);
    tree.insert("d", 4);
    tree.insert("e", 5);
    tree.insert("f", 6);
    tree.insert("g", 7);
    tree.insert("h", 8);
    tree.insert("i", 9);
    tree.insert("j", 10);

    assert(tree.remove("a"));
    assert(tree.remove("b"));
    assert(tree.remove("c"));
    assert(tree.remove("d"));
    assert(tree.remove("e"));

    int info;
    assert(!tree.search("a", info));
    assert(!tree.search("b", info));
    assert(tree.search("f", info));

    assert(tree.remove("f"));
    assert(tree.remove("g"));
    assert(tree.remove("h"));
    assert(tree.remove("i"));
    assert(tree.remove("j"));

    assert(tree.empty());
}

void test_search()
{
    cout << endl
         << "===== Search test =====" << endl;

    avl_tree<string, int> tree;

    tree.insert("a", 1);
    tree.insert("b", 2);
    tree.insert("c", 3);
    tree.insert("d", 4);
    tree.insert("e", 5);
    tree.insert("f", 6);
    tree.insert("g", 7);
    tree.insert("h", 8);
    tree.insert("i", 9);
    tree.insert("j", 10);

    int info;

    assert(tree.search("a", info));
    assert(info == 1);
    assert(tree.search("j", info));
    assert(info == 10);
    assert(!tree.search("k", info));
    assert(info == 10);
    assert(!tree.search("l", info));
    assert(info == 10);
    assert(tree.search("e", info));
    assert(info == 5);
}

void test_empty()
{
    cout << endl
         << "===== Empty test =====" << endl;

    avl_tree<string, int> tree;
    assert(tree.empty());
    tree.insert("a", 1);
    assert(!tree.empty());
    tree.remove("a");
    assert(tree.empty());
}

void test_clear()
{
    cout << endl
         << "===== Clear test =====" << endl;

    avl_tree<string, int> tree;

    tree.clear();
    assert(tree.empty());

    tree.insert("a", 1);
    tree.insert("b", 2);
    tree.insert("c", 3);
    tree.insert("d", 4);
    tree.insert("e", 5);
    tree.insert("f", 6);
    tree.insert("g", 7);
    tree.insert("h", 8);
    tree.insert("i", 9);
    tree.insert("j", 10);

    assert(!tree.empty());
    tree.clear();
    assert(tree.empty());
}

void test_indexing_operator()
{
    cout << endl
         << "===== Indexing operator test =====" << endl;

    avl_tree<string, int> tree;

    tree["a"] = 1;
    tree["b"] = 2;
    tree["c"] = 3;
    tree["d"] = 4;
    tree["e"] = 5;
    tree["f"] = 6;
    tree["g"] = 7;
    tree["h"] = 8;
    tree["i"] = 9;
    tree["j"] = 10;

    assert(tree["a"] == 1);
    assert(tree["b"] == 2);
    assert(tree["c"] == 3);
    assert(tree["d"] == 4);
    assert(tree["e"] == 5);
    assert(tree["f"] == 6);
    assert(tree["g"] == 7);
    assert(tree["h"] == 8);
    assert(tree["i"] == 9);
    assert(tree["j"] == 10);

    tree["a"]++;
    assert(tree["a"] == 2);
    tree["a"]++;
    assert(tree["a"] == 3);
}

void test_inorder()
{
    cout << endl
         << "===== Inorder test =====" << endl;

    avl_tree<string, int> tree;

    tree.insert("a", 1);
    tree.insert("b", 2);
    tree.insert("c", 3);
    tree.insert("d", 4);
    tree.insert("e", 5);
    tree.insert("f", 6);
    tree.insert("g", 7);
    tree.insert("h", 8);
    tree.insert("i", 9);
    tree.insert("j", 10);

    tree.inorder(cout);
}

void test_graph()
{
    cout << endl
         << "===== Graph test =====" << endl;

    avl_tree<string, int> tree;

    tree.insert("a", 1);
    tree.insert("b", 2);
    tree.insert("c", 3);
    tree.insert("d", 4);
    tree.insert("e", 5);
    tree.insert("f", 6);
    tree.insert("g", 7);
    tree.insert("h", 8);
    tree.insert("i", 9);
    tree.insert("j", 10);
    tree.insert("k", 11);
    tree.insert("l", 12);
    tree.insert("m", 13);
    tree.insert("n", 14);
    tree.insert("o", 15);
    tree.insert("p", 16);
    tree.insert("q", 17);
    tree.insert("r", 18);
    tree.insert("s", 19);
    tree.insert("t", 20);
    tree.insert("u", 21);
    tree.insert("v", 22);
    tree.insert("w", 23);
    tree.insert("x", 24);
    tree.insert("y", 25);
    tree.insert("z", 26);

    cout << "Initial graph:" << endl;
    tree.graph(cout);

    // removing to test if tree is balanced well

    tree.remove("a");
    tree.remove("b");
    tree.remove("c");
    tree.remove("d");
    tree.remove("e");
    tree.remove("f");
    tree.remove("g");

    cout << "Graph after removing some nodes:" << endl;
    tree.graph(cout);
}

void test_grapgh_with_balance_factor()
{
    cout << endl
         << "===== Graph with balance factor test =====" << endl;

    avl_tree<string, int> tree;

    tree.insert("a", 1);
    tree.insert("b", 2);
    tree.insert("c", 3);
    tree.insert("d", 4);
    tree.insert("e", 5);
    tree.insert("f", 6);
    tree.insert("g", 7);
    tree.insert("h", 8);
    tree.insert("i", 9);
    tree.insert("j", 10);
    tree.insert("k", 11);
    tree.insert("l", 12);
    tree.insert("m", 13);
    tree.insert("n", 14);
    tree.insert("o", 15);
    tree.insert("p", 16);
    tree.insert("q", 17);
    tree.insert("r", 18);
    tree.insert("s", 19);
    tree.insert("t", 20);
    tree.insert("u", 21);
    tree.insert("v", 22);
    tree.insert("w", 23);
    tree.insert("x", 24);
    tree.insert("y", 25);
    tree.insert("z", 26);

    cout << "Initial graph:" << endl;
    tree.graph_with_balance_factor(cout);

    // removing to test if tree is balanced well

    tree.remove("a");
    tree.remove("b");
    tree.remove("c");
    tree.remove("d");
    tree.remove("e");
    tree.remove("f");
    tree.remove("g");

    cout << "Graph after removing some nodes:" << endl;
    tree.graph_with_balance_factor(cout);
}

bool count_words_speed_test()
{
    cout << endl
         << "===== Count words speed test =====" << endl;

    cout << "std::map results:" << endl;
    for (int rep = 0; rep < 5; ++rep)
    {
        ifstream is("beagle_voyage.txt");
        if (!is)
        {
            cout << "Error opening input file.\n";
            return 0;
        }
        auto start_time = std::chrono::high_resolution_clock::now();
        string word;
        map<string, int> wc; // counting word occurrences in the stream
        while (is >> word)
        {
            wc[word]++;
        }
        auto end_time = std::chrono::high_resolution_clock::now();
        auto time = end_time - start_time;
        std::cout << "Ellapsed time: " << time / std::chrono::milliseconds(1) << " ms.\n";
    }

    cout << "avl_tree results:" << endl;

    for (int rep = 0; rep < 5; ++rep)
    {
        ifstream is("beagle_voyage.txt");
        if (!is)
        {
            cout << "Error opening input file.\n";
            return 0;
        }
        auto start_time = std::chrono::high_resolution_clock::now();
        string word;
        avl_tree<string, int> wc; // counting word occurrences in the stream
        while (is >> word)
        {
            wc[word]++;
        }
        auto end_time = std::chrono::high_resolution_clock::now();
        auto time = end_time - start_time;
        std::cout << "Ellapsed time: " << time / std::chrono::milliseconds(1) << " ms.\n";
    }
    return 1;
}

void test_maxinfo_selector()
{
    cout << endl
         << "===== Maxinfo selector test =====" << endl;

    avl_tree<string, int> tree;

    cout << "Test on a tree inserted with a whole alphabet:" << endl;
    
    tree.insert("m", 13);
    tree.insert("g", 7);
    tree.insert("x", 24);
    tree.insert("q", 17);
    tree.insert("b", 2);
    tree.insert("y", 25);
    tree.insert("u", 21);
    tree.insert("f", 6);
    tree.insert("o", 15);
    tree.insert("d", 4);
    tree.insert("w", 23);
    tree.insert("z", 26);
    tree.insert("h", 8);
    tree.insert("v", 22);
    tree.insert("i", 9);
    tree.insert("j", 10);
    tree.insert("e", 5);
    tree.insert("a", 1);
    tree.insert("r", 18);
    tree.insert("t", 20);
    tree.insert("k", 11);
    tree.insert("s", 19);
    tree.insert("c", 3);
    tree.insert("p", 16);
    tree.insert("l", 12);
    tree.insert("n", 14);

    vector<pair<string, int>> max_infos = maxinfo_selector(tree, 5);

    for (auto &i : max_infos)
    {
        cout << i.first << " " << i.second << endl;
    }

    cout << "Test on a tree with less nodes than the cnt integer:" << endl;

    tree.clear();
    tree.insert("a", 1);
    tree.insert("b", 2);
    tree.insert("c", 3);

    max_infos = maxinfo_selector(tree, 5);

    for (auto &i : max_infos)
    {
        cout << i.first << " " << i.second << endl;
    }
}

int main()
{
    test_constructor();
    test_assignment_operator();
    test_copy_constructor();
    test_destructor();
    test_insert();
    test_change_info();
    test_remove();
    test_search();
    test_empty();
    test_clear();
    test_indexing_operator();
    test_inorder();
    test_graph();
    test_grapgh_with_balance_factor();
    count_words_speed_test();
    test_maxinfo_selector();

    cout << "All tests passed" << endl;
    return 0;
}