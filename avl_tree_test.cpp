#include "avl_tree.h"
#include "avl_tree_test.h"
#include <iostream>
#include <string>
#include <assert.h>
#include <fstream>
#include <chrono>
#include <map>

using namespace std;

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
    cout << "=====================================" << endl;
    tree.remove(28.28);
    tree.graph(cout);
    cout << "=====================================" << endl;
    tree.remove(27.27);
    tree.graph(cout);
    cout << "=====================================" << endl;
    tree.remove(26.26);
    tree.graph(cout);
    cout << "=====================================" << endl;
    tree.remove(25.25);
    tree.graph(cout);
    cout << "=====================================" << endl;
    tree.remove(24.24);
    tree.remove(23.23);
    tree.graph(cout);
    tree.inorder(cout);
}

void test_constructor()
{
    // empty tree
    avl_tree<string, int> tree_1;
    assert(tree_1.empty());

    
}

bool count_words_speed_test()
{
    cout << "===== Counting words speed test =====" << endl;
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

int main()
{
    // test();
    // test_constructor();
    count_words_speed_test();

    return 0;
}