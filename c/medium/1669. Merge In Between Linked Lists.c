/*
* 1669. Merge In Between Linked Lists
* You are given two linked lists: list1 and list2 of sizes n and m respectively.
* Remove list1's nodes from the ath node to the bth node, and put list2 in their place.
* The blue edges and nodes in the following figure incidate the result:
* Build the result list and return its head.
*
* Example 1:
* Input: list1 = [0,1,2,3,4,5], a = 3, b = 4, list2 = [1000000,1000001,1000002]
* Output: [0,1,2,1000000,1000001,1000002,5]
* Explanation: We remove the nodes 3 and 4 and put the entire list2 in their place. 
* The blue edges and nodes in the above figure indicate the result.
* 
* Example 2:
* Input: list1 = [0,1,2,3,4,5,6], a = 2, b = 5, list2 = [1000000,1000001,1000002,1000003,1000004]
* Output: [0,1,1000000,1000001,1000002,1000003,1000004,6]
* Explanation: The blue edges and nodes in the above figure indicate the result.
*
* Constraints:
* 3 <= list1.length <= 10^4
* 1 <= a <= b < list1.length - 1
* 1 <= list2.length <= 10^4
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b, struct ListNode* list2) 
{
    struct ListNode* ls1p, * pa, * pb, * ls2p;
    int i = 0;
    ls1p = list1;
    ls2p = list2;
    while (ls1p != NULL)
    {
        if (i == a - 1)
            pa = ls1p;
        else if (i == b + 1)
            pb = ls1p;
        ls1p = ls1p->next;
        ++i;
    }
    while (ls2p->next != NULL)
        ls2p = ls2p->next;
    ls1p = pa->next;
    pa->next = list2;
    ls2p->next = pb;
    while (ls1p != pb)
    {
        struct ListNode* p = ls1p->next;
        free(ls1p);
        ls1p = p;
    }
    return list1;
}
/*
* 执行结果：通过
* 执行用时：112 ms, 在所有 C 提交中击败了98.70%的用户
* 内存消耗：32.1 MB, 在所有 C 提交中击败了76.09%的用户
*/