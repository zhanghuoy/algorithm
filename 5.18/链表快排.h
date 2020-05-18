#include<algorithm>
using namespace std;
struct ListNode
{
    ListNode* next;
    int val;
};
ListNode* listQuickSort(ListNode* head)
{
    if (head == nullptr || head->next == nullptr)
        return head;
    helper(head, nullptr);
    return head;
}
void helper(ListNode* first, ListNode* second)
{
    if (first == second)
        return;
    ListNode* slow = first, *fast = first->next;
    int tmp = slow->val;
    while (fast!=second)
    {
        while (fast!=second&&fast->val >= tmp)
            fast = fast->next;
        if (fast != second)
        {
            slow = slow->next;
            swap(slow->val, fast->val);
            if (fast != second)
                fast = fast->next;
        }
    }
    swap(slow->val, first->val);
    helper(first, slow);
    helper(slow->next, second);
}