public class Solution {
    public void Merge(int[] nums1, int m, int[] nums2, int n) {
        int i = 0;
        int j = 0;
        // for(i = m; i < nums1.Length; i ++, j ++){
        //     nums1[i] = nums2[j];
        // }
        // j = m;
        // i = 0;
        while(i < (m+n) && j < (n+m)){
            if(nums1[i] < nums2[j]){
                temp = nums1[i];
                nums1[i] = nums2[j];
                nums2[j] = temp;
                i++;
            }else{
                j++;
            }
        }
    }
}