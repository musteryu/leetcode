#include <array>
#include <vector>
#include <string>
#include <memory>
#include <iostream>
using std::vector;
using std::array;
using std::string;
using std::shared_ptr;
using std::make_shared;

class WordDictionary {
public:
    WordDictionary(): root(new TrieNode()) {}
    // w.Adds a word into the data structure.
    void addWord(string word) {
        TrieNode *ptr = root;
        for (const auto &ch: word) {
            if (!ptr->children[ch-'a'])
                ptr->children[ch-'a'] = new TrieNode();
            ptr = ptr->children[ch-'a'];
        }
        ptr->is_end = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return check(word, 0, root);
    }

    ~WordDictionary() {
        delete root;
    }
private:
    
    class TrieNode {
    public:
        std::vector<TrieNode*> children;
        bool is_end;
        TrieNode(): children(26, nullptr), is_end(false) {}
        ~TrieNode() {
            for (auto &t: children)
                delete t;
        }
    };
    TrieNode *root;

    bool check(string &word, int start, TrieNode *node) {
        for (auto i = start; i < word.size(); i++) {
            if (!node) return false;
            const auto ch = word[i];
            if (ch == '.') {
                for (int j = 0; j < 26; j++) {
                    if (check(word, i+1, node->children[j])) return true;
                }
                return false;
            } else {
                node = node->children[ch-'a'];
            }
        }
        return node && node->is_end;
    }
};


// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.w.addWord("word");
// wordDictionary.search("pattern");


int main(int argc, const char* args[]) {
    WordDictionary w;
    w.addWord("ab");
    w.addWord("ran");
    w.addWord("rune");
    w.addWord("runner");
    w.addWord("runs");
    w.addWord("add");
    w.addWord("adds");
    w.addWord("adder");
    w.addWord("addee");
    // std::cout << w.search("r.n") << " ";
    // std::cout << w.search("ru.n.e") << " ";
    // std::cout << w.search("add") << " ";
    // std::cout << w.search("add.") << " ";
    // std::cout << w.search("adde.") << " ";
    // std::cout << w.search(".an.") << " ";
    std::cout << w.search("...s") << " ";
    std::cout << w.search("....e.") << " ";
    std::cout << w.search(".......") << " ";
    std::cout << w.search("..n.r") << std::endl;
}