class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        if(n<=1) return nums[0];
        int ans=nums[0];
        vector<int> dpMax(n),dpMin(n);
        dpMax[0]=nums[0];
        dpMin[0]=nums[0];
        for(int i=1;i<n;i++){
            int a=nums[i]*dpMax[i-1];
            int b=nums[i]*dpMin[i-1];
            int c=nums[i];
            dpMax[i]=max({a,b,c});
            dpMin[i]=min({a,b,c});
            ans=max(ans,dpMax[i]);
        }
        return ans;
    }
};
