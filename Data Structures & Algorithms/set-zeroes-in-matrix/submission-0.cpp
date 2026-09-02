class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>> temp=matrix;
        int m=temp.size();
        int n=temp[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(temp[i][j]==0){
                    for(int k=0;k<n;k++){
                        matrix[i][k]=0;
                    }
                    for(int l=0;l<m;l++){
                        matrix[l][j]=0;
                    }
                }
            }
        }
        return;

    }
};
