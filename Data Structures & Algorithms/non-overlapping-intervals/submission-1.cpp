class Solution {
public:
    static bool comp(const vector<int> &a,const vector<int> &b){
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& Intervals) {
         int n=Intervals.size();
        sort(Intervals.begin(),Intervals.end(),comp);
        int count=1;
        int firstEnd=Intervals[0][1];
        for(int i=1;i<n;i++){
            if(Intervals[i][0]>=firstEnd){
                count++;
                firstEnd=Intervals[i][1];
            }
        }
        return n-count;
    }
};
