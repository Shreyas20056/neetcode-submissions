class Solution {
public:
    static bool comparator(const vector<int> &a,const vector<int> &b){
        return a[0]<b[0];
    }
    vector<vector<int>> insert(vector<vector<int>>& Intervals, vector<int>& newInterval) {
        vector<vector<int>> result;
        Intervals.push_back(newInterval);
        sort(Intervals.begin(),Intervals.end(),comparator);
        int n=Intervals.size();
        vector<int> curr=Intervals[0];
        for(int i=1;i<n;i++){
            if(Intervals[i][0]<=curr[1]){
                curr[1]=max(Intervals[i][1],curr[1]);
            }else{
               result.push_back(curr);
               curr=Intervals[i];
            }
        }
        result.push_back(curr);
        return result;
    }
};
