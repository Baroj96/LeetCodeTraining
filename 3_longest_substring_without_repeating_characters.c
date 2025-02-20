#define MAX_ASCII 255

int lengthOfLongestSubstring(char* s) {
    unsigned int map[255] = {0};
    unsigned int max = 0;
    unsigned int counter_substring = 0;
    int j = 0;

    for(int i=0; i < strlen(s); i++){
        
        map[s[i]] = 1;
        counter_substring ++;

        for(j = i+1; j < strlen(s) && map[s[j]] == 0; j++){
            map[s[j]] = 1;
            counter_substring ++;
        }
        if(counter_substring > max){
            max = counter_substring;
        }

        counter_substring = 0;

        for(int x=0; x < MAX_ASCII; x ++){
            map[x] = 0;
        }
    }

    return max;
}
