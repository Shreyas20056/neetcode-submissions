class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> need,window;
        for(char c:t){
            need[c]++;
        }

        int left=0,have=0;
        int required=need.size();
        int start=0,minLen=INT_MAX;

        for(int right=0;right<s.size();right++){
            char c=s[right];
            window[c]++;
            if(need.count(c) && window[c]==need[c]){
                have++;
            }
            while(have==required){
                if(right-left+1<minLen){
                    minLen=right-left+1;
                    start=left;
                }
                char ch=s[left];
                window[ch]--;
                if(need.count(ch) && window[ch]<need[ch]){
                    have--;
                }
                left++;
            }
        }
        return minLen==INT_MAX?"":s.substr(start,minLen);
    }
};
