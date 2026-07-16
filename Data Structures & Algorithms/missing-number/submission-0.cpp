class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int sum=(n*(n+1)/2);
        int sum1=0;
        for(int num:nums) sum1+=num;
        return abs(sum-sum1);
    }
};
