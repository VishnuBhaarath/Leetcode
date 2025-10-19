class Solution {
public:
    void merge(vector<pair<int,int>>& arr, vector<int>& cnt, int left, int mid, int right){
        vector<pair<int,int>> temp(right-left+1);
        int i = left; 
        int j = mid+1;
        int k = 0;
        // we need to sort in descending order
        while(i<=mid && j<=right){
            if(arr[i].first <= arr[j].first){ // increaing order
                temp[k++] = arr[j++];
            }
            else{// descending order and the greater elem comes first then smaller elms 
                cnt[arr[i].second] += right-j+1;
                temp[k] = arr[i];
                i++;
                k++;
            }
        }

        // remaining elms
        while(i<=mid){
            temp[k]= arr[i];
            k++;
            i++;
        }

        while(j<=right){
            temp[k] = arr[j];
            k++;
            j++;
        }
        // copying elmt to original arr
        for(int i=left; i<=right; i++){
            arr[i]= temp[i-left];
        }

    }
    void mergeSort(vector<pair<int,int>>& arr, vector<int>& cnt, int left, int right){
        if(left>=right)
            return;
        
        int mid = left + (right-left)/2;
        mergeSort(arr, cnt, left, mid);
        mergeSort(arr, cnt, mid+1, right);
        merge(arr, cnt, left, mid, right);
    }

    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> arr(n);
        for(int i=0; i<n; i++){
            arr[i]={nums[i],i};
        }

        vector<int> cnt(n,0);
        mergeSort(arr, cnt, 0, n-1);
        return cnt;
    }
};
