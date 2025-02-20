using System;
public class Solution {
    public int LongestPalindrome(string s) {

        Dictionary<char,int> dict = new Dictionary<char, int>();
        bool spare_char_for_middle = false;
        int sum = 0;

        foreach (char c in s){
            try
            {
                dict.Add(c,1);
            }
            catch(ArgumentException)
            {
                dict[c] = dict[c] + 1;
            }
        }

        foreach( KeyValuePair<char, int> kvp in dict )
        {
            sum += (kvp.Value / 2) * 2;
            if (kvp.Value % 2 == 1 && !spare_char_for_middle){
                spare_char_for_middle = true;
                sum += 1;
            }

        }

        return sum;

    }
}