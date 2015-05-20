class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode() : val('-'), isEnd(false), next(NULL), child(NULL) {}
    
    char val;
    bool isEnd;
    TrieNode* next;
    TrieNode* child;
};

class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    // Adds a word into the data structure.
    void addWord(string word) {
        TrieNode** pCur = &root;
        for (auto ch : word) {
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

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return search(word, root);
    }
    
private:
    bool search(string word, TrieNode* cur) {
        for (int i = 0; i < word.size(); i++) {
            cur = cur->child;
            if (word[i] == '.') {
                while (cur) {
                    if (search(word.substr(i + 1), cur))
                        return true;
                    cur = cur->next;
                }
                return false;
            }
            else {
                while (cur && cur->val < word[i])
                    cur = cur->next;
                if (!cur || cur->val != word[i])
                    return false;
            }
        }
        return cur->isEnd;
    }
    TrieNode *root;
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");
