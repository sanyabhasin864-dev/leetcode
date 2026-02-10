constexpr int N=1e5+1;
bitset<N> seen=0;
class Solution {
public:
    int longestBalanced(vector<int>& nums) {
         int n = (int)nums.size();

        int i = 0, ans = 0, j, sum;
        for(i; i < n; i ++){
            for(j = i - 1; j >= 0; j --){
                if((nums[i] ^ nums[j]) == (1<<30)){
                    nums[j] ^= (1<<30);
                }
            }
            nums[i] ^= (1<<30);
            sum = 0;
            for(int j = i; j >= 0; j --){
                if(nums[j]&(1<<30)){
                    if(nums[j]&1) sum += 1;
                    else sum -= 1;
                }
                if(sum == 0){
                    ans = max(ans, i - j + 1);
                }
            }
        }
        return ans;
    }
};