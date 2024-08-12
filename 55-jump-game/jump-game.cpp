class Solution {
public:
    bool canJump(vector<int>& nums) {
        int counter = 0;

        for(int i = 0 ; i < nums.size() ; i++)
        {
            if ( i > counter ){
                return false;
            }
            counter = max ( counter , i + nums[i]);

            if (counter >= nums.size() -1){
                return true;
            }
        }
        return false;
    }
};