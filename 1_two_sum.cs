using System;
public class Solution {
    public int[] TwoSum(int[] nums, int target)
    {
        Dictionary<int,List<int>> dict = new Dictionary<int, List<int>>();
        for(int i = 0; i < nums.Length; i++)
        {
            int[] array_of_indexes = new int[nums.Length];
            List<int> existing;

            if (!dict.TryGetValue(nums[i], out existing)) {
                existing = new List<int>();
                existing.Add(i);
                dict[nums[i]] = existing;
            }else{
                dict[nums[i]].Add(i);
            }
        }

        for(int i = 0; i < nums.Length; i++)
        {
            int compl_index = 0;
            int compl = target - nums[i];

            List<int> existing;

            if (dict.TryGetValue(compl, out existing)) {
                if(existing.Count > 1){
                    compl_index = existing[1]; 
                    int[] res = {i,compl_index};
                    return res;
                }else{
                    if(existing[0] != i){
                        compl_index = existing[0]; 
                        int[] res = {i,compl_index};
                        return res;
                    }
                }
            }
            
            
            
        }
        return null;
    }
}
