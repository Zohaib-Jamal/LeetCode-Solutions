
// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode* temp = head;

        while(temp){
            count++;
            temp = temp->next;
        }

        temp = head;
        bool flag = true;
        for(int i=0; i<count-n; i++){
            flag = false;
            if(!(i+1<count-n)){
                temp->next = temp->next->next;
                break;
            }else{
                temp=temp->next;
            }
        }

        if(flag){
            head = head->next;
        }
        
       

        return head;

    }
};