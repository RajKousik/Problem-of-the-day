class Solution {
public:
    
    void merge(vector<int> &arr, int low, int mid, int high)
    {
        int m = mid - low + 1;
        int n = high - mid;

        vector<int> leftArr(m), rightArr(n);

        for(int i=0; i<m; i++)
        {
            leftArr[i] = arr[i+low];
        }

        for(int i=0; i<n; i++)
        {
            rightArr[i] = arr[mid + 1 + i];
        }

        int i=0, j=0, k=low;
        int inv = 0;

        while(i<m && j<n)
        {
            if(leftArr[i] <= rightArr[j])
            {
                arr[k++] = leftArr[i++];
            }
            else
            {
                arr[k++] = rightArr[j++];
            }
        }

        while(i < m)
        {
            arr[k++] = leftArr[i++];
        }
        while(j < n)
        {
            arr[k++] = rightArr[j++];
        }

    }
    
    int countPairs(vector<int> &arr, int low, int mid, int high)
    {
        int cnt = 0;
        
        int right = mid + 1;
        
        for(int i=low ; i<=mid; i++)
        {
            while(right <= high and arr[i] > (long long)2 * arr[right])
            {
                right++;
            }
            cnt += (right - (mid + 1));
        }
        return cnt;
    }
    
    int mergeSort(vector<int> &arr, int low, int high)
    {
        int inv = 0;
        if(low < high)
        {
            int mid = (low + high)/2;
            inv += mergeSort(arr, low, mid);
            inv += mergeSort(arr, mid+1, high);
            inv += countPairs(arr, low, mid, high);
            merge(arr, low, mid, high);
        }
        return inv;
    }
    
    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int ans = mergeSort(nums, 0, n-1);
        return ans;
    }
};