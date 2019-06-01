class TrieNode {
public:
    bool is_end;
    vector<TrieNode*> children;
    TrieNode() {
        is_end = false;
        children=vector<TrieNode*>(26,NULL);
    }
};

class Trie {
public:
    TrieNode* getRoot(){return root;}
    Trie(vector<string>& words) {
        root = new TrieNode();
        for(int i = 0;i<words.size();i++) {
            addWord(words[i]);
        }
    }
    
    void addWord(const string& word) {
        TrieNode* cur = root;
        for(int i = 0;i<word.size();i++) {
            int index = word[i]-'a';
            if(cur->children[index]==NULL)
                cur->children[index] = new TrieNode();
            cur = cur->children[index];
        }
        cur->is_end = true;
    }
    
    TrieNode* root;
};

class Solution {
    vector<string> res;
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        Trie* tree = new Trie(words);
        
        for(int i = 0; i<words.size();i++) {
            if(dfs(words[i],0,tree->root,0))
                res.push_back(words[i]);
        }
        
        return res;
    }
    
    bool dfs(string& word, int from, TrieNode* tree, int count) {
        TrieNode* root = tree;
        for(int i = from;i<word.size();) {
            //cout << i;
            int index = word[i]-'a';
            if(tree->children[index] == NULL)
                return false;
            i++;
            if(tree->children[index]->is_end == true) {
                //cout << from;
                if(i == word.size() && count != 0) {
                    //cout << 'a';
                    return true;
                }
                if(dfs(word, i, root, count+1)) {
                    //cout << 'b';
                    return true;
                }
            }
            tree = tree->children[index];
        }
        return false;
    }
};