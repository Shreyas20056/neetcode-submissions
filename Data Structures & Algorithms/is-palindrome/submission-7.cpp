class Solution {
public:
    bool isTrue(vector<char> vt){
        int left=0,right=vt.size()-1;
        while(left<=right){
            if(vt[left]!=vt[right]) return false;
            left++;
            right--;
        }
        return true;
    }
    bool isPalindrome(string s) {
        vector<char> vt;
        for(char c:s){
           if(isalnum(c)){
              vt.push_back(tolower(c));
           }
        }
        return isTrue(vt);
    }
};
