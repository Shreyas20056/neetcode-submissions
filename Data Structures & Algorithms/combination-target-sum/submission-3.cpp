class Solution {
public:
    void rec(int i,int target,vector<int> &arr,vector<int> nums,vector<vector<int>> &result)
    {
        if(i<0 || target<0){
            return;
        }
        if(target==0){
            result.push_back(arr);
            return;
        }
        arr.push_back(nums[i]);
        rec(i,target-nums[i],arr,nums,result);
        arr.pop_back();
        rec(i-1,target,arr,nums,result);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>> result;
        vector<int> arr;
        rec(n-1,target,arr,nums,result);
        return result;
    }
};
