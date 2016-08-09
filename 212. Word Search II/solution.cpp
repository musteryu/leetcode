#include <vector>
#include <string>
#include <memory>
#include <array>
#include <iostream>
using namespace std;

class TrieNode {
public:
    string word;
    vector<TrieNode*> children;
    TrieNode(): word(""), children(26, nullptr) {}
};

class Trie {
public:
    Trie(vector<string>& words): root(new TrieNode()) {
        TrieNode* iter;
        for (auto& word: words) {
            iter = root;
            for (auto& ch: word) {
                if (!iter->children[ch-'a']) {
                    iter->children[ch-'a'] = new TrieNode();
                }
                iter = iter->children[ch-'a'];
            }
            iter->word = word;
        }
    }

    TrieNode* getRoot() {
        return root;
    }
private:
    TrieNode* root;
};


class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie dictTree(words);
        TrieNode* root = dictTree.getRoot();
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                find(board, root, i, j);
            }
        }
        return solution;
    }
private:
    vector<string> solution;
    void find(vector<vector<char>>& board, TrieNode* root, int row, int col) {
        char ch = board[row][col];
        if (ch == '*') return;
        if (!(root = root->children[ch-'a'])) return;
        if (root->word.size()) {
            solution.push_back(root->word);
            root->word.clear();
        }
        board[row][col] = '*';
        if (row < board.size()-1)
            find(board, root, row+1, col);
        if (row > 0)
            find(board, root, row-1, col);
        if (col < board[0].size()-1)
            find(board, root, row, col+1);
        if (col > 0)
            find(board, root, row, col-1);
        board[row][col] = ch;
    }
};


int main(int argc, const char* args[]) {
    Solution s;
    vector<vector<char>> board = {
        vector<char>{'o', 'a', 'a', 'n'},
        vector<char>{'e', 't', 'a', 'e'},
        vector<char>{'i', 'h', 'k', 'r'},
        vector<char>{'i', 'f', 'l', 'v'}
    };
    vector<string> words = {"oath","pea","eat","rain"};
    vector<string> res = s.findWords(
        board, words
    );
    for (auto& s: res) {
        cout << s << endl;
    }
}