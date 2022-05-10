// TC: O(m + n)
// SC: O(1)

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;
        
        while(i >= 0 && j >= 0){
            if(nums1[i] > nums2[j]) 
                nums1[k--] = nums1[i--];
            else
                nums1[k--] = nums2[j--];
        }
        
        while(i >= 0)
            nums1[k--] = nums1[i--];
        
        while(j >= 0)
            nums1[k--] = nums2[j--];
    }
};

/*
TC: O(m + n)
SC: O(m + n)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> ans;
        
        int i = 0, j = 0;
        
        while(i != m && j != n){
            if(nums1[i] < nums2[j]){
                ans.push_back(nums1[i]);
                i++;
            }
            else if(nums1[i] > nums2[j]){
                ans.push_back(nums2[j]);
                j++;
            }
            else{
                ans.push_back(nums1[i]);
                ans.push_back(nums2[j]);
                i++;
                j++;
            }
        }
        
        while(i != m){
            ans.push_back(nums1[i]);
            i++;
        }
        
        while(j != n){
            ans.push_back(nums2[j]);
            j++;
        }
        
        for(int i = 0; i < m; ++i) nums1[i] = ans[i];
        for(int i = m; i < m + n; ++i) nums1[i] = ans[i];
    }
};

*/