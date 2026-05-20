class Solution {
public:
    void rec(int i,vector<int> &arr,vector<int> &nums,vector<vector<int>> &result,int target){
        if(target==0){
            result.push_back(arr);
            return;
        }
        if(target<0  || i>=nums.size()) return;
        arr.push_back(nums[i]);
        rec(i,arr,nums,result,target-nums[i]);
        arr.pop_back();
        rec(i+1,arr,nums,result,target);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        vector<int> arr;
        rec(0,arr,nums,result,target);
        return result;
    }
};
