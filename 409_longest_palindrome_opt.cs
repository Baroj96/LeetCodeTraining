using System;
public class Solution {
    public int LongestPalindrome(string s) {

        int[] charCount = new int[128];
        bool spare_char_for_middle = false;
        int sum = 0;

        foreach (char c in s){
            charCount[c]++;
        }

        foreach(int n in charCount )
        {
            sum += (n / 2) * 2;
            if ( n % 2 == 1 && !spare_char_for_middle){
                spare_char_for_middle = true;
                sum += 1;
            }

        }

        return sum;

    }
}