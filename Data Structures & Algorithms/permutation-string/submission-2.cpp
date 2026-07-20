class Solution {
public:
    bool checkCondition(string a,string b){
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        return a==b;
    }
    bool checkInclusion(string s1, string s2) {
        int k=s1.size();
        int n=s2.size()-k;
        for(int i=0;i<=n;i++){
            string a=s2.substr(i,k);
            if(checkCondition(a,s1)) return true;
        }
        return false;
    }
};
