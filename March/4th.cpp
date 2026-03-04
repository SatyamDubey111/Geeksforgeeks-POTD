class Solution {
  public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
        // code here
       int a = arr.size();
       int b =INT_MIN;
       int c =0;
       for(int d =0; d < k; d++){
           c ^= arr[d];
       }
       b = max(b,c);
       for(int e =k; e<a; e++){
           c ^= arr[e-k];
           c ^= arr[e];
           b = max(b, c);
       }
       
       return b;
    
    }
};