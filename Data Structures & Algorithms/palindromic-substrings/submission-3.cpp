class Solution {
public:
    int countPali(string s,int l,int r){
        int result=0;
        while(l>=0 && r<s.size() && s[l]==s[r]){
            result++;
            l--;
            r++;
        }
        return result;
    }
    int countSubstrings(string s) {
        int count=0;
        for(int i=0;i<s.size();i++){
            count+=countPali(s,i,i);
            count+=countPali(s,i,i+1);
        }
        return count;
    }
};
