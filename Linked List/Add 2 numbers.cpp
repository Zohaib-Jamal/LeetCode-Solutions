struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    void makeNum(ListNode *l1, ListNode *l2, ListNode *l3, int adder)
    {
  
        if (l1 && l2)
        {

            int num = l1->val + l2->val + adder;
            l3->val = num % 10;
            if (l1->next || l2->next || num / 10)
            {
                l3->next = new ListNode();
            }
            makeNum(l1->next, l2->next, l3->next, num / 10);
            return;
        }
        else if (l2)
        {

            int num = l2->val + adder;
            l3->val = num % 10;
            if (l2->next || num / 10)
            {
                l3->next = new ListNode();
            }

            makeNum(nullptr, l2->next, l3->next, num / 10);
            return;
        }
        else if (l1)
        {

            int num = l1->val + adder;
            l3->val = num % 10;

            if (l1->next || num / 10)
            {

                l3->next = new ListNode();
            }

            makeNum(l1->next, nullptr, l3->next, num / 10);
            return;
        }
        else if (adder > 0)
        {
            l3->val = adder;
        }
     
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *l3 = new ListNode();
        makeNum(l1, l2, l3, 0);
        return l3;
    }
};