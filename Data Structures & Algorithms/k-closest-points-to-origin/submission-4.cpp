class Solution {
public:
    static bool comparator(vector<int> &a,vector<int> &b){
        long long  dis1=(a[0]*a[0]+a[1]*a[1]);
        long long  dis2=(b[0]*b[0]+b[1]*b[1]);
        return dis1<=dis2;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
       vector<vector<int>> result;
       sort(points.begin(),points.end(),comparator);
       int i=0;
       while(k>0){
           result.push_back(points[i]);
           i++;
           k--;
       }
        return result;
    }
};
