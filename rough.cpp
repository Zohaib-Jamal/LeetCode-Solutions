struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {


        
        ListNode* temp;
        if(list1 && list2 && list1->val > list2->val){
            temp = list1;
            list1  = list2;
            list2 = temp;
        }else if(list2 && !list1){
            list1 = list2;
        }
        ListNode* merged = list1;
        while(list2){

       
           if(list1->next && list1->next->val < list2->val){
                list1 = list1->next;
            }
            else if(list1->val <= list2->val){
                temp = list2;
                list2 = list1->next;
                list1->next = temp;
                if(list1->next && list2 && list1->next->val == list2->val){
                    list1=list1->next;
                }
            }
        }

        return merged;
        
    }

int main()
{
    ListNode *list1 = new ListNode(1, new ListNode(2, new ListNode(4)));
    ListNode *list2 = new ListNode(1, new ListNode(3, new ListNode(4)));

    mergeTwoLists(list1, list2);
}