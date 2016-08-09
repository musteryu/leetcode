#include <array>
#include <string>
using std::array;
using std::string;

class TrieNode {
public:
    // Initialize your data structure here.
    std::array<TrieNode*, 26> children;
    bool is_end;
    TrieNode(): is_end(false) {
        for (TrieNode* &ch: children)
            ch = nullptr;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode *ptr = root;
        for (char &c: word) {
            if (ptr->children[c-'a'] == nullptr) {
                ptr->children[c-'a'] = new TrieNode();
            }
            ptr = ptr->children[c-'a'];
        }
        ptr->is_end = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *ptr = root;
        for (char &c: word) {
            if (ptr->children[c-'a'] == nullptr)
                return false;
            ptr = ptr->children[c-'a'];
        }
        return ptr->is_end;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *ptr = root;
        for (char &c: prefix) {
            if (ptr->children[c-'a'] == nullptr)
                return false;
            ptr = ptr->children[c-'a'];
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");