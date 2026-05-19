class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit=0;
        int l=0;
        for(int r=0;r<prices.size();r++){
             if(prices[r]>prices[l]){
                maxProfit=max(maxProfit,prices[r]-prices[l]);
             }else{
                l=r;
             }
        }
        return maxProfit;
    }
};
