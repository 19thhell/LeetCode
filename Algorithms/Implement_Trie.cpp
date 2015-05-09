class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() {
        isEnd = false;
        next = NULL;
        child = NULL;
    }
    
    char val = '-';
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
        TrieNode* cur = root;
        for (auto ch : s) {
            if (!cur->child) {
                cur->child = new TrieNode();
                cur->child->val = ch;
            }
            cur = cur->child;
            while (cur->val != ch) {
                if (!cur->next) {
                    cur->next = new TrieNode();
                    cur->next->val = ch;
                }
                cur = cur->next;
            }
        }
        cur->isEnd = true;
    }

    // Returns if the word is in the trie.
    bool search(string key) {
        TrieNode* cur = root;
        for (auto ch : key) {
            cur = cur->child;
            if (!cur)
                return false;
            while (cur->val != ch) {
                cur = cur->next;
                if (!cur)
                    return false;
            }
        }
        return cur->isEnd;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for (auto ch : prefix) {
            cur = cur->child;
            if (!cur)
                return false;
            while (cur->val != ch) {
                cur = cur->next;
                if (!cur)
                    return false;
            }
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
