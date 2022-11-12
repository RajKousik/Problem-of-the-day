//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		int characterReplacement(string s, int k){
		    // Code here
		    unordered_map<char, int> mp;
		    int i=0, j=0, n=s.size();
		    int maxCharOcc=0;
		    int ans=0;
		    
		    while(j<n){
		        int sz= j-i+1;
		        mp[s[j]]++;
		        maxCharOcc=max(maxCharOcc, mp[s[j]]);
		        
		        int diffChar= sz-maxCharOcc;
		        if(diffChar<=k){
		            ans= max(ans, sz);
		        }
		        if(diffChar>k){
		            mp[s[i]]--;
		            maxCharOcc=max(maxCharOcc, mp[s[i]]);
		            
		            if(mp[s[i]] ==0 ) mp.erase(s[i]);
		            i++;
		        }
		        j++;
		    }
		    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		int k;
		cin >> k;
		Solution obj;
		int ans = obj.characterReplacement(s, k);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends