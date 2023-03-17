
struct TrieNode
{
    TrieNode* links[26];
    bool isEnd;
};

class Trie 
{
private:
    TrieNode* root;
    
public:
    Trie()
    {
        root = getNewNode();  
    }
    
    TrieNode* getNewNode()
    {
        TrieNode* newNode = new TrieNode();
        for(int i=0; i<26; i++)
        {
            newNode->links[i] = NULL;
        }
        newNode->isEnd = false;
        return newNode;
    }
    
    void insert(string word) 
    {
        TrieNode* tempRoot = root;
        
        for(int i=0; i<word.size(); i++)
        {
            if(tempRoot->links[word[i] - 'a'] == NULL)
            {
                tempRoot->links[word[i] - 'a'] = getNewNode();
            }
            tempRoot = tempRoot->links[word[i] - 'a'];
        }
        
        tempRoot->isEnd = true;
        
    }
    
    bool search(string word) 
    {
        TrieNode* tempRoot = root;
        
        for(int i=0; i<word.size(); i++)
        {
            if(tempRoot->links[word[i] - 'a'] == NULL)
            {
                return false;
            }
            tempRoot = tempRoot->links[word[i] - 'a'];
        }
        
        return tempRoot->isEnd;
        
    }
    
    bool startsWith(string prefix) 
    {
        TrieNode* tempRoot = root;
        
        for(int i=0; i<prefix.size(); i++)
        {
            if(tempRoot->links[prefix[i] - 'a'] == NULL)
            {
                return false;
            }
            tempRoot = tempRoot->links[prefix[i] - 'a'];
        }
        
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */