struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *swapPairs(ListNode *head)
{
    ListNode *dummyHead = head;

    if (!head || !head->next)
        return head;
    head = head->next;
    int count = 0;
    while (dummyHead && dummyHead->next)
    {
        ListNode *temp = dummyHead->next;
        if (!temp->next && count%2==1)
        {
            break;
        }
        dummyHead->next = temp->next;
        if (count % 2 == 0)
        {
            temp->next = dummyHead;
        }
        else
        {
            dummyHead = temp;
        }
        count++;
    }

    return head;
}

int main()
{
    ListNode *head = new ListNode(1, new ListNode(2, new ListNode(3)));
    swapPairs(head);
}