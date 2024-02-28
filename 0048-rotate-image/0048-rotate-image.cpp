class Solution{
public:
    void reverse(vector<int> &row){
        int left = 0;
        int right = row.size() - 1;
        while(left < right) {
            swap(row[left], row[right]);
            left++;
            right--;
        }
    }
    void rotate(vector<vector<int>>& matrix){
        int rows = matrix.size();
        // Transpose of matrix
        for(int i=0; i<rows; i++)
            for(int j=0; j<i; j++)
                swap(matrix[i][j], matrix[j][i]);
        // Reverse a row
        for(int i=0; i<rows; i++)
            reverse(matrix[i]);
    }
};