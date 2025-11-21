class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> vec(2001, 0);

        for(int i=0; i<arr.size(); i++){
            vec[arr[i]+1000]+=1;
        }

        sort(begin(vec), end(vec));

        for(int i=1; i<2001; i++){
            if(vec[i] !=0 && vec[i] == vec[i-1]) return false;
        }

        return true;
    }
};