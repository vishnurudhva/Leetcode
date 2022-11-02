class Trie {
public:
    bool isEnd;
    unordered_map<char, Trie*> nextChars;
    
    Trie() {
        isEnd = false;
    }
    
    void insert(string word) {
        Trie* node = this;
        int i = 0;
        for (; i < word.size(); i++) {
            if (node->nextChars.find(word[i]) != node->nextChars.end()) {
                node = node->nextChars[word[i]];
            } else {
                break;
            }
        }
        
        for (; i < word.size(); i++) {
            node->nextChars[word[i]] = new Trie();
            node = node->nextChars[word[i]];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        Trie* node = getEnd(word);
        return node != NULL && node->isEnd;
    }
    
    bool startsWith(string prefix) {
        return getEnd(prefix) != NULL;
    }
    
    Trie* getEnd(string word) {
        Trie* node = this;
        int i = 0;
        for (; i < word.size(); i++) {
            if (node->nextChars.find(word[i]) != node->nextChars.end()) {
                node = node->nextChars[word[i]];
            } else {
                return NULL;
            }
        }
        return node;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */