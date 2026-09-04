class Solution {
public:
    int countPali(string s,int l,int r){
        int res=0;
        while(l>=0 && r<s.size() && s[l]==s[r]){
            res++;
            l--;
            r++;
        }
        return res;
    }
    int countSubstrings(string s) {
        int result=0;
        for(int i=0;i<s.size();i++){
            result+=countPali(s,i,i);
            result+=countPali(s,i,i+1);
        }
        return result;
    }
};
