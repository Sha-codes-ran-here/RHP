class Solution {
public:
    int trap(vector<int>& height) {
        int R=height.size();
        vector<int> larr(R,0),rarr(R,0);
        for (int i=0;i<R;i++){
            if (i==0 || height[i]>larr[i-1]){
                larr[i]=height[i];
            }
            else{
                larr[i]=larr[i-1];
            }
        }
        for (int i=R-1;i>=0;i--){
            if (i==R-1 || height[i]>rarr[i+1]){
                rarr[i]=height[i];
            }
            else{
                rarr[i]=rarr[i+1];
            }
        }
        int sum=0;
        for (int i=0;i<R;i++){
            if (larr[i]<rarr[i]){
                sum+=larr[i]-height[i];
            }
            else{
                sum+=rarr[i]-height[i];
            }
        }
        return sum;
    }
};