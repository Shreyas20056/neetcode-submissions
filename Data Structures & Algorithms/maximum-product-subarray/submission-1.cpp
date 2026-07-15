class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        vector<int> dpMax(n) ,dpMin(n);
        dpMax[0]=nums[0];
        dpMin[0]=nums[0];
        int ans=nums[0];
        for(int i=1;i<n;i++){
            int b=nums[i]*dpMax[i-1];
            int c=nums[i]*dpMin[i-1];
            int a=nums[i];
            dpMax[i]=max({a,b,c});
            dpMin[i]=min({a,b,c});
            ans=max(ans,dpMax[i]);
        }
        return ans;
    }
};
