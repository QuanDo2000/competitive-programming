#include <bits/stdc++.h>
using namespace std;

// Solution
class Trie {
   public:
    Trie() {
    }

    void insert(string word) {
        Node* p = root;
        for (char c : word) {
            if (p->next[c - 'a'] == nullptr) {
                p->next[c - 'a'] = new Node();
            }
            p = p->next[c - 'a'];
        }
        p->isWord = true;
    }

    bool search(string word) {
        Node* p = root;
        for (char c : word) {
            if (p->next[c - 'a'] == nullptr) {
                return false;
            }
            p = p->next[c - 'a'];
        }
        return p->isWord;
    }

    bool startsWith(string prefix) {
        Node* p = root;
        for (char c : prefix) {
            if (p->next[c - 'a'] == nullptr) {
                return false;
            }
            p = p->next[c - 'a'];
        }
        return true;
    }

   private:
    struct Node {
        bool isWord;
        Node* next[26];
        Node() {
            isWord = false;
            for (int i = 0; i < 26; i++) {
                next[i] = nullptr;
            }
        }
    };
    Node* root = new Node();
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
