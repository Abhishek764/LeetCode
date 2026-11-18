class Solution {
public:
    int lengthOfLIS(vector<int>& a) {
        int n=a.size();
        int d[n];
        int k=0;
        for(int i=0;i<n; i++){
            int p=lower_bound(d,d+k,a[i])-d;
            d[p]=a[i];
            if(p==k){
                k++;
            }
        }
        return k;
    }
};