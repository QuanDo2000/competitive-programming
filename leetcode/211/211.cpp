#include <bits/stdc++.h>
using namespace std;

// Solution
class WordDictionary {
   public:
    WordDictionary() {}

    void addWord(string word) {
        int len = word.length();
        if (words.find(len) == words.end()) {
            words[len] = vector<string>();
        }
        words[len].push_back(word);
    }

    bool search(string word) {
        int len = word.length();
        if (words.find(len) == words.end()) {
            return false;
        }
        vector<string> &v = words[len];
        for (int i = 0; i < v.size(); i++) {
            bool flag = true;
            for (int j = 0; j < len; j++) {
                if (word[j] != '.' && word[j] != v[i][j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                return true;
            }
        }
        return false;
    }

   private:
    unordered_map<int, vector<string>> words;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
