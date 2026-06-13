class Solution {
public:
    int sumOfSquares(int num){
        int sum=0;
        while(num!=0){
            sum+=pow(num%10,2);
            num/=10;
        }
        return sum;
    }
    bool isHappy(int n) {
        unordered_set<int> st;
        while(st.find(n)==st.end()){
            st.insert(n);
            n=sumOfSquares(n);
            if(n==1){
                return true;
            }
        }
        return false;
    }
};
