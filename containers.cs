
public class Solution {
    public int MaxArea(int[] height) {

        int max_area = 0;
        int i = 0;
        int j = height.Length-1;
        int temp_area = 0;

        while(i < j)
        {
            if(height[j] >= height[i])
            {
                temp_area = height[i] * (j-i);
                i++;
            }
            else
            {
                temp_area = height[j] * (j-i);
                j--;
            }

            if(temp_area > max_area)
            {
                max_area = temp_area;
            }
        }
        return max_area;
    }
}