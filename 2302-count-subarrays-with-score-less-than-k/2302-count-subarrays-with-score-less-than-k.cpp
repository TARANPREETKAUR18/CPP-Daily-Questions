class Solution {
public:
    long long countSubarrays(vector<int>& arr, long long k) {
        long long ans  = 0;
        int n = arr.size();
        long long i = 0,j = 0;
        long long sum = 0;
        while(j<n){
            sum+=arr[j];
            long long  len = j-i+1;
            while(sum*len >= k){
                sum-=arr[i];
                i++;
                len = j-i+1;
            }
            ans+=(j-i+1);
            j++;
        }
        return ans;
    }
};