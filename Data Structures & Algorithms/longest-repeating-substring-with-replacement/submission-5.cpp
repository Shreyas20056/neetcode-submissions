class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> mp;
        int left=0;
        int maxf=0;
        int maxLen=0;
        for(int right=0;right<s.size();right++)
        {
            mp[s[right]]++;
            maxf=max(maxf,mp[s[right]]);
            while((right-left+1)-maxf>k){
                mp[s[left]]--;
                left++;
            }
            maxLen=max(maxLen,right-left+1);
        }
        return maxLen;
    }
};
