class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() : val('-'), isEnd(false), next(NULL), child(NULL) {
        
    }
    
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
    bool search(string key) {
        TrieNode* cur = root;
        for (auto ch : key) {
            cur = cur->child;
            while (cur && cur->val < ch)
                cur = cur->next;
            if (!cur || cur->val != ch)
                return false;
        }
        return cur->isEnd;
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

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
