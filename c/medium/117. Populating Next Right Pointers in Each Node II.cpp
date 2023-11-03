/* 117. Populating Next Right Pointers in Each Node II
 * Given a binary tree
 * struct Node {
 *  int val;
 *  Node *left;
 *  Node *right;
 *  Node *next;
 *  }
 * Populate each next pointer to point to its next right node.
 * If there is no next right node, the next pointer should be set to NULL.
 * Initially, all next pointers are set to NULL.
 * Example 1:
 * Input: root = [1,2,3,4,5,null,7]
 * Output: [1,#,2,3,#,4,5,7,#]
 * Explanation: Given the above binary tree (Figure A),
 * your function should populate each next pointer to point to its next right node,
 * just like in Figure B. The serialized output is in level order as connected by the next pointers,
 * with '#' signifying the end of each level.
 *
 * Example 2:
 * Input: root = []
 * Output: []
 * Constraints:
 * The number of nodes in the tree is in the range [0, 6000].
 * -100 <= Node.val <= 100
 *
 * Follow-up:
 * You may only use constant extra space.
 * The recursive approach is fine. You may assume implicit stack space does not count as extra space for this problem.
 */

class Solution {
public:
    Node *connect(Node *root) {
        if (root == nullptr) {
            return root;
        }
        queue<Node *> q1;
        queue<Node *> q2;
        q1.push(root);
        while (!q1.empty() || !q2.empty()) {
            while (!q1.empty()) {
                Node *p1 = q1.front();
                q1.pop();
                Node *p2 = q1.empty() ? nullptr : q1.front();
                p1->next = p2;
                if (p1->left) {
                    q2.push(p1->left);
                }
                if (p1->right) {
                    q2.push(p1->right);
                }
            }
            while (!q2.empty()) {
                Node *p1 = q2.front();
                q2.pop();
                q1.push(p1);
            }
        }
        return root;
    }
};

// 时间16 ms，击败39.15%
// 内存17.6 MB，击败13.54%