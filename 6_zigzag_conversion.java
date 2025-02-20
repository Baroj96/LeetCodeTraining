class Solution {
    public String convert(String s, int numRows) {
        int i = 0;
        int j = 0;
        int z = 0;
        String out = "";
        int start = 0;
        if(numRows == 1){
            return s;
        } else if(numRows == 3){
            for(i = numRows-1; i > 0; i--){
                start = z;
                z ++;
                while(start < s.length()){          
                    out += s.charAt(start);
                    start = start + (i + i); // index + numRows + numRows
                }
            }
            start = z;
            while(start < s.length()){          
                out += s.charAt(start);
                start = start + (numRows*2)-2; // index + numRows + numRows
            }
        }else{
            for(i = numRows-1; i > 0; i--){
                start = z;
                z ++;
                while(start < s.length()){          
                    out += s.charAt(start);
                    start = start + (i + i); // index + numRows + numRows -1 
                }
            }
            start = z;
            while(start < s.length()){          
                out += s.charAt(start);
                start = start + (numRows*2)-2; // index + numRows + numRows
            }
        }
        return out;
    }
} 