

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int max_size = nums1Size+nums2Size;
    int merge_array[max_size];
    int i = 0;
    int j = 0;
    int merge_arr_index = 0;
    int median_index = 0;
    double median = 0;
    median_index = (nums1Size + nums2Size) / 2;
    
    while ( merge_arr_index < median_index)
    {
        if( i < nums1Size && j < nums2Size){
            if(nums1[i] > nums2[j]){
                merge_array[merge_arr_index] = nums2[j];
                merge_arr_index ++;                
                j++;
            }else{
                merge_array[merge_arr_index] = nums1[i];
                merge_arr_index ++;                
                i++;
            }
        }else if(i < nums1Size){
            merge_array[merge_arr_index] = nums1[i];
            merge_arr_index ++;
        }else if(j < nums2Size){
            merge_array[merge_arr_index] = nums2[j];
            merge_arr_index ++;
        }
    }

    // if(nums1[i] > nums2[j]){
    //     if(i > nums1Size){
    //         merge_array[merge_arr_index] = nums2[i];
    //     }else{
    //         merge_array[merge_arr_index] = nums2[j];
    //     }
    // }else{
    //     if(j > nums2Size){
    //         merge_array[merge_arr_index] = nums2[j];
    //     }else{
    //         merge_array[merge_arr_index] = nums1[i];
    //     }
    // }

    if((nums1Size + nums2Size)%2 == 0){
        median = ((merge_array[merge_arr_index] * 1.0) + (merge_array[merge_arr_index-1] *1.0)) / 2.0;
    }else{
        median = merge_array[merge_arr_index] * 1.0;
    }
    

    return median;
}