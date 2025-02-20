import java.lang.*;
import java.io.*;
import java.util.*;

public class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int n = 0;
        ListNode l1_p = l1;
        ListNode l2_p = l2;
        ListNode res_p = new ListNode();
        ListNode res_start = res_p;

        while(l1_p != null || l2_p != null || n!=0){
            if(l1_p != null && l2_p != null){
                res_p.val = l1_p.val + l2_p.val + n;
                n = 0;
                l1_p = l1_p.next;
                l2_p = l2_p.next;
            }else if(l1_p != null){
                res_p.val = l1_p.val + n;
                n = 0;
                l1_p = l1_p.next;
            }else if(l2_p != null){
                res_p.val = l2_p.val + n;
                n = 0;
                l2_p = l2_p.next;
            }else if(n!=0){
                res_p.val = n;
                n = 0;
            }

            if(res_p.val >= 10){
                    res_p.val = res_p.val - 10;
                    n = 1;
            }

            if(l1_p != null || l2_p != null || n != 0){    
                ListNode temp = new ListNode();
                res_p.next = temp;
                res_p = temp;
            }

        }

        return res_start;
    }
}
