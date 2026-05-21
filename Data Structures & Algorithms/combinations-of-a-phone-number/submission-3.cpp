class Solution {
public:
    void backtrack(int i,string curStr,string &digits,vector<string> &result,vector<string> digitToChar){
        if(curStr.size()==digits.size()){
            result.push_back(curStr);
            return;
        }
        string chars=digitToChar[digits[i]-'0'];
        for(char c:chars){
            backtrack(i+1,curStr+c,digits,result,digitToChar);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        vector<string> digitToChar={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        if(digits.empty()) return result;
        backtrack(0,"",digits,result,digitToChar);
        return result;
    }
};
