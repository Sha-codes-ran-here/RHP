class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int>presum;
		int sum = 0;
		int count = 0;
		int n = nums.size();
        presum[0]=1;
		
		for (int i = 0; i<n; i++) {
			sum += nums[i];
			int rem = sum - k;
			if (presum.find(rem) != presum.end()) {
				count+=presum[rem];
			}
			presum[sum]++;
		}
		return count;
	
    }
};