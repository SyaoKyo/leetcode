/*
* 剑指 Offer II 028. 展平多级双向链表
* 多级双向链表中，除了指向下一个节点和前一个节点指针之外，它还有一个子链表指针，
* 可能指向单独的双向链表。这些子列表也可能会有一个或多个自己的子项，依此类推，生成多级数据结构，如下面的示例所示。
* 给定位于列表第一级的头节点，请扁平化列表，即将这样的多级双向链表展平成普通的双向链表，使所有结点出现在单级双链表中。
*
* 示例 1：
* 输入：head = [1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]
* 输出：[1,2,3,7,8,11,12,9,10,4,5,6]
* 解释：
*  1---2---3---4---5---6--NULL
*          |
*          7---8---9---10--NULL
*              |
*              11--12--NULL
* 序列化其中的每一级之后：
* [1,2,3,4,5,6,null]
* [7,8,9,10,null]
* [11,12,null]
* 为了将每一级都序列化到一起，我们需要每一级中添加值为 null 的元素，以表示没有节点连接到上一级的上级节点。
* [1,2,3,4,5,6,null]
* [null,null,7,8,9,10,null]
* [null,11,12,null]
* 合并所有序列化结果，并去除末尾的 null 。
* [1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]
* 
* 示例 2：
* 输入：head = [1,2,null,3]
* 输出：[1,3,2]
* 解释：
* 输入的多级列表如下图所示：
*   1---2---NULL
*   |
*   3---NULL
*
* 示例 3：
* 输入：head = []
* 输出：[]
*
* 提示：
* 节点数目不超过 1000
* 1 <= Node.val <= 10^5
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
// 把child变next
class Solution {
public:
    Node* flatten(Node* head)
    {
        Node* p = head;
        while (p != NULL)
        {
            if (p->child != NULL)
            {
                Node* q = p->child;
                Node* pn = p->next;
                p->next = q;
                p->child = NULL;
                q->prev = p;
                flatten(q);
                while (q->next != NULL)
                    q = q->next;
                q->next = pn;
                if (pn != NULL)
                    pn->prev = q;
                p = pn;
            }
            else
                p = p->next;
        }
        return head;
    }
};
/*
* 执行结果：通过
* 执行用时：4 ms, 在所有 C++ 提交中击败了89.83%的用户
* 内存消耗：7.1 MB, 在所有 C++ 提交中击败了96.61%的用户
*/