#include <fstream>
#include "huffmanTree.h"

void huffmanTree::printMeta(Node *root, string str) {
    if(!root) return;
    if(root->data != '$') {
        code.push_back(str);
        ch.push_back(root->data);
        cnt++;
    }
    printMeta(root->left, str + '0');
    printMeta(root->right, str + '1');
}

void huffmanTree::printCode(int size, string originalFile, string compressedFile) {
    ifstream file;
    file.open(originalFile, ios::in | ios::binary);
    string codeString;
    char c;
    while(true) {
        if(file.peek() == EOF) break;
        file.read(&c, 1);
        for(int i = 0; i < size; i++) {
            if(ch[i] == c) {
                codeString += code[i];
                break;
            }
        }
    }
    file.close();

    ofstream codeFile(compressedFile, ios::out | ios::binary);
    for(int i = 0; i < size; i++) {
        codeFile << ch[i] << '~' << code[i] << " ";
    }
    codeFile << "!@#";
    unsigned long len = 8, m = 0;
    unsigned char b = 0;
    while(m != codeString.size()) {
        len--;
        if(codeString[m] == '0') {
            b &= ~(1 << len);
        } else if(codeString[m] == '1') {
            b |= (1 << len);
        }
        if(len == 0) {
            len = 8;
            codeFile << b;
            b = 0;
        }
        m++;
    }
    if(len != 8) {
        bitset<8> bits(codeString, codeString.size() - (8 - len), 8 - len);
        codeFile << static_cast<char>(bits.to_ulong());
        codeFile << static_cast<char>(8 - len);
    } else {
        codeFile << static_cast<char>(0);
    }
    codeFile.close();
}

void huffmanTree::huffmanCode(vector<char> data, vector<int> freq, int size) {
    Node* top;
    priority_queue<Node*, vector<Node*>, cmp> q;
    for(int i = 0; i < size; i++) {
        Node* temp = new Node();
        temp->data = data[i];
        temp->freq = freq[i];
        q.push(temp);
    }

    while(q.size() != 1) {
        Node* left = q.top();
        q.pop();
        Node* right = q.top();
        q.pop();
        top = new Node();
        top->data = '$';
        top->freq = left->freq + right->freq;
        top->left = left;
        top->right = right;
        q.push(top);
    }
    root = q.top();
    char str[100000];
    printMeta(q.top(), str);
}

void huffmanTree::encodeFile(string originalFile) {
    vector<char> data;
    vector<int> freq;
    ifstream file;
    file.open(originalFile, ios::in | ios::binary);
    char c;
    while(true) {
        if(file.peek() == EOF) break;
        file.read(&c, 1);
        bool exist = false;
        for(int i = 0; i < (int)data.size(); i++) {
            if(data[i] == c) {
                exist = true;
                freq[i]++;
                break;
            }
        }
        if(!exist) {
            data.push_back(c);
            freq.push_back(1);
        }
    }
    file.close();

    dataSize = data.size();
    huffmanCode(data, freq, dataSize);
}

void huffmanTree::decodeFile(string compressedFile, string newFile) {
    ifstream file;
    file.open(compressedFile, ios::in | ios::binary);
    bitset<8> bs;
    string rule, data;
    char c;
    while(true) {
        if(file.peek() == EOF) break;
        file.read(&c, 1);
        if(c == '!') {
            char t1, t2;
            file.read(&t1, 1);
            file.read(&t2, 1);
            if(t1 == '@' && t2 == '#') {
                break;
            } else {
                file.seekg(-2, ios::cur);
            }
        }
        rule += c;
    }
    while(true) {
        if(file.peek() == EOF) break;
        file.read(&c, 1);
        bs = c;
        data += bs.to_string();
    }
    file.close();
    out(data, newFile);
}

void huffmanTree::out(string data, string newFile) {
    ofstream file;
    file.open(newFile, ios::out | ios::binary);
    Node* temp = root;
    string end = data.substr(data.size() - 16, 16);
    cout << end << endl;
    bitset<8> len(end, 8, 8);
    unsigned long complement = len.to_ulong();
    if(complement != 0) {
        end = end.substr(8 - complement, complement);
        data.erase(data.size() - 16, data.size());
        data += end;
        cout << end << endl;
    } else {
        end = end.substr(0, 8);
        data.erase(data.size() - 16, data.size());
        data += end;
        cout << end << endl;
    }

    for(int i = 0; i < (int)data.size(); i++) {
        if(data[i] == '0') {
            temp = temp->left;
        } else if(data[i] == '1') {
            temp = temp->right;
        }
        if(temp->left == NULL && temp->right == NULL) {
            file << temp->data;
            temp = root;
        }
    }
    file.close();
}
