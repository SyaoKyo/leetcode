/*
* 206. Reverse Linked List
* Given the head of a singly linked list, reverse the list, and return the reversed list.
* 
* Example 1:
* Input: head = [1,2,3,4,5]
* Output: [5,4,3,2,1]
* 
* Example 2:
* Input: head = [1,2]
* Output: [2,1]
* 
* Example 3:
* Input: head = []
* Output: []
*
* Constraints:
* The number of nodes in the list is the range [0, 5000].
* -5000 <= Node.val <= 5000
*
* Follow up: A linked list can be reversed either iteratively or recursively. Could you implement both?
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head)
{
    if (head == NULL)
        return NULL;
    struct ListNode* p, * q;
    p = head;
    q = head->next;
    while (p->next != NULL)
    {
        p->next = q->next;
        q->next = head;
        head = q;
        q = p->next;
    }
    return head;
}
/*
* 执行结果：通过
* 执行用时：0 ms, 在所有 C 提交中击败了100.00%的用户
* 内存消耗：6.1 MB, 在所有 C 提交中击败了86.28%的用户
*/
