class Solution 
{
private:
    
    int findGcd(int a, int b)
    {
        if(!b)
        {
            return a;
        }
        
        return findGcd(b, a%b);
    }
    
public:
    string gcdOfStrings(string str1, string str2) {
        
        if(str1 + str2 != str2 + str1)
        {
            return "";
        }
        
        int gcd = findGcd(str1.size(), str2.size());
        
        return str1.substr(0, gcd);
        
    }
};