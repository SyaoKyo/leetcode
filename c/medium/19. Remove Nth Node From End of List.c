/*
* 19. Remove Nth Node From End of List
* Given the head of a linked list, remove the nth node from the end of the list and return its head.
* 
Example 1:
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2:
Input: head = [1], n = 1
Output: []

Example 3:
Input: head = [1,2], n = 1
Output: [1]
 
Constraints:
The number of nodes in the list is sz.
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz
 
Follow up: Could you do this in one pass?
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
    struct ListNode* p = head, * q;
    int rear = 0, idx;
    while (p != NULL)
    {
        ++rear;
        p = p->next;
    }
    if (rear == 1)
        return NULL;
    else if (rear == n)
        return head->next;
    else
    {
        idx = rear - n - 1;
        p = head;
        while (idx)
        {
            --idx;
            p = p->next;
        }
        q = p->next;
        p->next = q->next;
        free(q);
    }
    return head;
}
/*
* 执行结果：通过
* 执行用时：0 ms, 在所有 C 提交中击败了100.00%的用户
* 内存消耗：5.6 MB, 在所有 C 提交中击败了89.74%的用户
*/
