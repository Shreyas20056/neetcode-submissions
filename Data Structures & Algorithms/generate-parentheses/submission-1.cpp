class Solution {
public:
    void generate(string res,int left,int right,int n,vector<string> &result){
        if((left==right) && (left+right==2*n)){
            result.push_back(res);
            return;
        }
        if(left<n){
            generate(res+"(",left+1,right,n,result);
        }
        if(right<left){
            generate(res+")",left,right+1,n,result);
        }
    }
    vector<string> generateParenthesis(int n) {
         vector<string> result;
         generate("",0,0,n,result);
         return result;
    }
};
