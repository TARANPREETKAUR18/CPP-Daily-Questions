class Solution{
public:
    int trap(vector<int>& arr){
        int n=arr.size();
	    int lmax=arr[0], rmax=arr[n-1], left=1, right=n-2, ans=0;
	    while(left<=right){
		    if(arr[left]>=lmax) lmax=arr[left++];
		    else if(arr[right]>=rmax) rmax=arr[right--];
		    else if(lmax<=rmax && arr[left]<lmax) ans+=lmax-arr[left++];
		    else ans+=rmax-arr[right--];
	    }
        return ans;
    }
};