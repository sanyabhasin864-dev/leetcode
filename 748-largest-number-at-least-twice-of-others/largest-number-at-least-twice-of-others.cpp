class Solution {
public:
    int dominantIndex(vector<int>& nums) {

        int n = nums.size();

        // Find largest
        int largest = nums[0];

        for(int i = 0; i < n; i++) {
            if(nums[i] > largest) {
                largest = nums[i];
            }
        }

        // Find index of largest
        int index = 0;

        for(int i = 0; i < n; i++) {
            if(nums[i] == largest) {
                index = i;
            }
        }

        // Check if largest is twice every other number
        for(int i = 0; i < n; i++) {
            if(i != index && largest < 2 * nums[i]) {
                return -1;
            }
        }

        return index;
    }
};