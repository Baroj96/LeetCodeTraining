int lengthOfLongestSubstring(char* s) {
    int map[255];
    int max = 0;
    int head = 0;
    int tail = 0;

    for(int i = 0; i < 255; i++){
        map[i] = -1;
    }
    
    for(head=0; head < strlen(s); head++){
        if(map[s[head]] >= tail){
            //qui entra se l'ultima volta che abbiamo visto il carattere a cui punta la head
            //aveva indice maggiore di tail. ciò vuol dire che è nella sliding window quindi
            //dobbiamo far ripartire la sliding window dall'indice di quel carattere + 1 .
            tail = map[s[head]] + 1;
        }
        //aggiorno l'indice dell'ultima volta che abbiamo visto il carattere puntato da head.
        map[s[head]] = head;

        if((head-tail +1) > max){
            max = head - tail +1;
        }
    }

    return max;
}