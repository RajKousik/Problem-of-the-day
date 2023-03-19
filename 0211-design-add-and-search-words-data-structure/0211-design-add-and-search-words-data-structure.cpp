class TrieNode
{
public:
    TrieNode* links[26];
    bool isEnd; 
};


class WordDictionary
{
private:
    TrieNode* root;
    
    bool searchHelper(string word, TrieNode *rootNode)
    {
        for(int i=0; i<word.size(); i++)
        {
            char ch = word[i];
            
            if(ch == '.')
            {
                
                for(int j=0; j<26; j++)
                {
                    if(rootNode->links[j] and searchHelper(word.substr(i+1), rootNode->links[j]))
                    {
                        return true;
                    }
                }
                return false;
            }
            else
            {
                if(rootNode->links[ch-'a'] == NULL)
                {
                    return false;
                }
                rootNode = rootNode->links[ch-'a']; 
            }
            
        }
        
        return rootNode->isEnd;
    }
    
public:
    WordDictionary() 
    {
        root = getNewnode();
    }
    
    TrieNode* getNewnode()
    {
        TrieNode* newNode = new TrieNode();
        for(int i=0; i<26; i++)
        {
            newNode->links[i] = NULL;
        }
        newNode->isEnd = false;
        return newNode;
    }
    
    void addWord(string word) 
    {
        TrieNode* tempRoot = root;
        
        for(int i=0; i<word.size(); i++)
        {
            int key = word[i] - 'a';
            
            if(tempRoot->links[key] == NULL)
            {
                tempRoot->links[key] = getNewnode();
            }
            tempRoot = tempRoot->links[key];
            
        }
        
        tempRoot->isEnd = true;
        
    }
    
    bool search(string word) 
    {
        TrieNode* tempRoot = root;
        
        return searchHelper(word, tempRoot);
        
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */