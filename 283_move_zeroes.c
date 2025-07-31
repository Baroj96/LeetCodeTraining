void moveZeroes(int* nums, int numSsize) {
    // int i = 0;
    // int j = 0;
    // int* res_array = (int*)malloc(numSsize * sizeof(int));
    // memset(res_array, 0, numSsize * sizeof(int));
    // for(i = 0; i < numSsize; i ++){
    //     if(nums[i] != 0){
    //         res_array[j] = nums[i];
    //         j++;
    //     }
    // }
    // for(i = 0; i < numSsize; i ++){
    //     nums[i] = res_array[i];
    // }
    int nums_of_zeroes = 0;
    for (int i = 0; i < numSsize; i++ ){
        if(nums[i] == 0){
            nums_of_zeroes += 1;
        }else{
            if(nums_of_zeroes != 0){
                nums[i-nums_of_zeroes] = nums[i];
            }
        } 
    }

    for(int i = numSsize-nums_of_zeroes; i < numSsize; i++){
        nums[i] = 0;
    }
        
}