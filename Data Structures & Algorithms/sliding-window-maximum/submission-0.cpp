class Solution {
public:
    int findMax(unordered_map<int,int> mp){
        int maxi=INT_MIN;
        for(auto it:mp){
            maxi=max(maxi,it.first);
        }
        return maxi;
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
         vector<int> result;
          unordered_map<int,int> mp;
        int n=nums.size();
        for(int i=0;i<k;i++){
            mp[nums[i]]++;
        }
        result.push_back(findMax(mp));
        for(int i=k;i<n;i++){
            mp[nums[i]]++;
            mp[nums[i-k]]--;
            if(mp[nums[i-k]]==0){
                mp.erase(nums[i-k]);
            }
            result.push_back(findMax(mp));
        }
        return result;
        
    }
};
