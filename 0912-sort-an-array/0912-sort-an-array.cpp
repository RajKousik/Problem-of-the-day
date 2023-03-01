class Solution {
public:
    
    void merge(vector<int>& nums, int p, int q, int r){
        
        int n1 = q-p+1;
        int n2 = r-q;
        
        int l1[n1], l2[n2];
        for(int i=0; i<n1; i++){
           l1[i] = nums[p+i];   
        }
        for(int j=0; j<n2; j++){
           l2[j] = nums[q+1+j];   
        }
        
        int i = 0;
        int j = 0;
        int k = p;
        
        while(i<n1 && j<n2){
            if(l1[i]<=l2[j]){
                nums[k] = l1[i];
                i++;
            }
            else{
                nums[k] = l2[j];
                j++;
            }
            k++;
        }
        
        while(i<n1){
            nums[k] = l1[i];
            i++;
            k++;
        }
        
        while(j<n2){
            nums[k] = l2[j];
            j++;
            k++;
        }
        
    }
    
    void mergeSort(vector<int> &nums, int l, int r){
        if(l < r){
            int mid = l + (r-l)/2;
            mergeSort(nums, l, mid);
            mergeSort(nums, mid+1, r);
            merge(nums, l, mid, r);
        }
    }
    
    vector<int> sortArray(vector<int>& nums) {
        int size = nums.size();
        mergeSort(nums, 0, size-1);
        return nums;
    }
};