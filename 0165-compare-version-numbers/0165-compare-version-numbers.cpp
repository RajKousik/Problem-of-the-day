class Solution {
public:
int compareVersion(string version1, string version2) {
    // add logic here
	int len1 = version1.size();
	int len2 = version2.size();
	
	
	int i=0, j=0;
	
	int num1=0, num2 = 0;
	
	while(i < len1 or j < len2)
	{
		while(i < len1 and version1[i] != '.')
		{
			num1 = (num1 * 10) + (version1[i] - '0');
			i++;
		}
		
		while(j < len2 and version2[j] != '.')
		{
			num2 = (num2 * 10) + (version2[j] - '0');
			j++;
		}
		// cout<<num1<<" "<<num2<<endl;
		if(num1 > num2) return 1;
		else if(num2 > num1) return -1;
		
		num1 = 0;
		num2 = 0;
		
		i++;
		j++;
		
	}
	return 0;
}
};