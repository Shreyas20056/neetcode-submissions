/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> start,end;
        for(const auto &i:intervals){
            start.push_back(i.start);
            end.push_back(i.end);
        }
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());

        int res=0,count=0;
        int i=0,j=0;
        while(i<intervals.size()){
            if(start[i]<end[j]){
                i++;
                count++;
            }else{
                j++;
                count--;
            }
            res=max(res,count);
        }
        return res;
    }
};
