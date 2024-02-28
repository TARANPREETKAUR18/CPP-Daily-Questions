class Solution {
public:
    void rotate(vector<vector<int>> &matrix){
        //rotate = reverse +transpose(main gist)
        reverse(matrix.begin(), matrix.end());
        int n = matrix.size();
        int m = matrix[0].size();

        for(int i=0; i<n; i++)
            for(int j=i; j<m; j++)
                swap(matrix[i][j], matrix[j][i]);
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target){
        for(int i=0; i<4; i++){
            if(mat == target) return true;
            rotate(mat);
        }
        return false;
    }
};