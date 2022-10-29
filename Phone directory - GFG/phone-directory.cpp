//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    #define SIZE 26
    
    //trie node where isend is used to denote the last character
    struct TrieNode
    {
        
        TrieNode* links[SIZE];
        
        bool isEnd;
    
    };


    class Trie
    {
        //root of the trie structure
         TrieNode *root;
        
    public:
        Trie()
        {   
            //constructor function to initialize the root of the trie when a object is initialized
            root = getNewNode();
        }
        
        //returns a newly created node
        TrieNode* getNewNode()
        {
            TrieNode* temp = new TrieNode;
            
            //making all childlinks as null initially 
            for(int i=0; i<SIZE; i++)
            {
                temp->links[i] = NULL;
            }
            //initially isend will be false
            temp->isEnd = false;
        }
        
        //insert function for inserting a word in to the trie
        void insert(string word)
        {
            int n = word.size();
            
            TrieNode* tempRoot = root;
            
            for(int i=0; i<n; i++)
            {
                
                if(tempRoot->links[word[i] - 'a'] == NULL)
                {
                    tempRoot->links[word[i] - 'a'] = getNewNode();
                }
                
                tempRoot = tempRoot->links[word[i]-'a'];
                
            }
            
            //last character's isend will be true
            tempRoot->isEnd = true;
            
        }
        
        //dfs function to find the string s answers
        void dfs(string s, TrieNode *root, vector<string> &ans)
        {
            //if last character reached, then it is one of the ans, push it to the ans array
            if(root->isEnd == true)
            {
                ans.push_back(s);
            }
            
            
            //go to all the child links and check
            for(int i=0; i<SIZE; i++)
            {
                
                if(root->links[i] != NULL)
                {
                    //add the character into the str
                    s+=('a' + i);
                    
                    //call the dfs function with root->links[i]
                    dfs(s, root->links[i], ans);
                    
                    //backtracking step 
                    //remove the last character and search for next ans
                    s.pop_back();
                }
                
            }
            
            
        }
        
        vector<string> findIt(string prefix)
        {
            
            int n = prefix.size();
            
            TrieNode* tempRoot = root;
            
            //go to the prefix last character in the trie, if not return "0" (as an array) 
            for(int i=0; i<n; i++)
            {
                
                if(tempRoot->links[prefix[i] - 'a'] == NULL)
                {
                    return {"0"};
                }
                else
                {
                    tempRoot = tempRoot->links[prefix[i] - 'a'];
                }
                
            }
            
            vector<string> ans;
            
            //call the dfs function to find the ans
            dfs(prefix, tempRoot, ans);
            
            return ans;
            
        }
        
    };

    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        //to store the ans
        vector<vector<string>> ans;
        
        //creating the object for the class Trie
        Trie trie;
        
        //inserting each word in the contact to the trie structure
        for(int i=0; i<n; i++)
        {
            trie.insert(contact[i]);
        }
        
        //iterating through each letter and forming a substring
        //and finding that substring's answers and adding to ans
        for(int i=0; i<s.length(); i++)
        {
            ans.push_back(trie.findIt(s.substr(0, i+1)));
        }
        //returning the ans
        return ans;
        
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}
// } Driver Code Ends