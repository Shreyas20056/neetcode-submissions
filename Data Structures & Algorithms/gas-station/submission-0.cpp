class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int start_node=0;
        int current_surplus=0;
        int total_surplus=0;
        for(int i=0;i<gas.size();i++){
            int diff=gas[i]-cost[i];
            current_surplus+=diff;
            total_surplus+=diff;
            if(current_surplus<0){
                start_node=i+1;
                current_surplus=0;
            }
        }
        return (total_surplus<0)?-1:start_node;
    }
};
