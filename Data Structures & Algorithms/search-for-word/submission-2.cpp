class Solution {
public:
    bool dfs(vector<vector<char>> &board,vector<vector<bool>> &visited,string word,int row,int col,int index){
        if(index==word.length()){
            return true;
        }
        if(row<0 || row>=board.size() || col<0 || col>=board[0].size()){
            return false;
        }
        if(visited[row][col]){
            return false;
        }
        if(board[row][col]!=word[index]){
            return false;
        }
        visited[row][col]=true;
        bool found=dfs(board,visited,word,row+1,col,index+1) ||
        dfs(board,visited,word,row-1,col,index+1) ||
        dfs(board,visited,word,row,col+1,index+1) ||
        dfs(board,visited,word,row,col-1,index+1);
        visited[row][col]=false;

        return found;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int rows=board.size();
        int cols=board[0].size();
        vector<vector<bool>> visited(rows,vector<bool>(cols,false));
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(dfs(board,visited,word,i,j,0)){
                    return true;
                }
            }
        }
        return false;

    }
};
