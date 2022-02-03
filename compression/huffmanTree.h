#ifndef HUFFMANTREE_HUFFMANTREE_H
#define HUFFMANTREE_HUFFMANTREE_H

#include <string>
#include <iostream>
#include <queue>
#include <cstring>
#include <bitset>
#include <vector>

using namespace std;

struct Node {
    char data;
    int freq;
    Node* left;
    Node* right;
};

struct cmp {
    bool operator() (Node* l, Node* r) {
        return (l->freq > r->freq);
    }
};

class huffmanTree {
public:
    Node* root;
    vector<string> code;
    vector<char> ch;
    int cnt = 0, dataSize;
    void printMeta(Node* root, string str);
    void printCode(int size, string originalFile, string compressedFile);
    void huffmanCode(vector<char> data, vector<int> freq, int size);
    void encodeFile(string originalFile);
    void decodeFile(string compressedFile, string newFile);
    void out(string data, string newFile);
};

#endif //HUFFMANTREE_HUFFMANTREE_H
