using System.Collections;
public class Solution {
    public int FindDuplicate(int[] nums) {
        
        for(int i = 0; i < nums.Length-1; i ++){
            for(int j = i+1; j < nums.Length ; j++){
                if(nums[i] == nums[j])
                {
                    return nums[i];
                }
            }
        }
        return -1;
    }
}