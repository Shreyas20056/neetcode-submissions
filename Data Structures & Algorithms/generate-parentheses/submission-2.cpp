class Solution {
public:
    void rec(int left,int right,string res,vector<string> &result,int n){
        if((left==right) && (left+right==2*n)){
            result.push_back(res);
            return;
        }
        if(left<n){
            rec(left+1,right,res+"(",result,n);
        }
        if(right<left){
            rec(left,right+1,res+")",result,n);
        }
    }
    vector<string> generateParenthesis(int n) {
         vector<string> result;
         rec(0,0,"",result,n);
         return result;
    }
};
