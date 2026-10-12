class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        // Vector to store merged intervals
        vector<vector<int>> merged;
 
        // Traverse through intervals
        for (auto interval : intervals) {
            // If merged is empty or no overlap, add interval
            if (merged.empty() || merged.back()[1] < interval[0]) {
                merged.push_back(interval);
            }
            // Otherwise, merge the overlapping intervals
            else {
                merged.back()[1] = max(merged.back()[1], interval[1]);
            }
        }
        // Return the merged list
        return merged;
    }
};
