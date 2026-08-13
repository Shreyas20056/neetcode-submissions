class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        res.clear();
        sort(nums.begin(),nums.end());
        vector<int> subset;
        rec(nums,0,subset);
        return res;
    }
    void rec(vector<int> &nums,int i,vector<int> &subset)
    {
        if(i==nums.size()){
            res.push_back(subset);
            return;
        }
        if(i>=nums.size()) return;
        subset.push_back(nums[i]);
        rec(nums,i+1,subset);
        subset.pop_back();
        while(i+1<nums.size() && nums[i]==nums[i+1]){
            i++;
        }
        rec(nums,i+1,subset);
    }
};
