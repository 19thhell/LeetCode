class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() : val('-'), isEnd(false), next(NULL), child(NULL) {}
    
    char val;
    bool isEnd;
    TrieNode* next;
    TrieNode* child;
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string s) {
        TrieNode** pCur = &root;
        for (auto ch : s) {
            bool used = false;
            TrieNode* newNode = new TrieNode();
            newNode->val = ch;
            if (!(*pCur)->child) {
                (*pCur)->child = newNode;
                used = true;
            }
            pCur = &((*pCur)->child);
            while ((*pCur)->val < ch) {
                if (!(*pCur)->next) {
                    (*pCur)->next = newNode;
                    used = true;
                }
                pCur = &((*pCur)->next);
            }
            if ((*pCur)->val != ch) {
                newNode->next = *pCur;
                *pCur = newNode;
                pCur = &(*pCur);
                used = true;
            }
            if (!used)
                delete newNode;
        }
        (*pCur)->isEnd = true;
    }

    // Returns if the word is in the trie.
    bool searchOnce(string key) {
        TrieNode* cur = root;
        for (auto ch : key) {
            cur = cur->child;
            while (cur && cur->val < ch)
                cur = cur->next;
            if (!cur || cur->val != ch)
                return false;
        }
        if (cur->isEnd) {
            cur->isEnd = false;
            return true;
        }
        return false;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for (auto ch : prefix) {
            cur = cur->child;
            while (cur && cur->val < ch)
                cur = cur->next;
            if (!cur || cur->val != ch)
                return false;
        }
        return true;
    }

private:
    TrieNode* root;
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> result;
        if (board.empty() || words.empty())
            return result;
        Trie trie;
        for (auto word : words)
            trie.insert(word);
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                string candidate = "";
                dfs(board, trie, result, i, j, m, n, candidate);
            }
        }
        return result;
    }
private:
    void dfs(vector<vector<char>>& board, Trie& trie, vector<string>& result, int row, int col, int m, int n, const string& candidate) {
        char backup = board[row][col];
        string next = candidate + backup;
        if (trie.searchOnce(next))
            result.push_back(next);
        if (!trie.startsWith(next))
            return;
        board[row][col] = '*';
        if (row > 0 && board[row - 1][col] != '*')
            dfs(board, trie, result, row - 1, col, m, n, next);
        if (row < m - 1 && board[row + 1][col] != '*')
            dfs(board, trie, result, row + 1, col, m, n, next);
        if (col > 0 && board[row][col - 1] != '*')
            dfs(board, trie, result, row, col - 1, m, n, next);
        if (col < n - 1 && board[row][col + 1] != '*')
            dfs(board, trie, result, row, col + 1, m, n, next);
        board[row][col] = backup;
    }
};
