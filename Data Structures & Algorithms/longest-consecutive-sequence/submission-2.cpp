class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> st;
        for(int x:nums){
            st.insert(x);
        }
        int res=0;
        for(auto x:st){
            if(st.find(x-1)==st.end()){
                 int count=1;
                 while(st.find(x+1)!=st.end()){
                    count++;
                    x++;
                 }
                 res=max(res,count);
            }
        }
        return res;
    }
};
