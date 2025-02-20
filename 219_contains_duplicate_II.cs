using System;
public class Solution {
    public bool ContainsNearbyDuplicate(int[] nums, int k) {
        Dictionary<int, int> dict = new Dictionary<int, int>(); // key: valore, value: indice dell'array
        for(int i = 0; i < nums.Length; i++)
        {
            try
            {
                dict.Add(nums[i],i);
            }
            catch(ArgumentException)
            {
                if(Math.Abs(i-dict[nums[i]])<= k)
                {
                    return true;
                }else{
                    dict.Remove(nums[i])
                }
            }

        }
        return false;
    }
}