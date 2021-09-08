/*
* 502. IPO
* Suppose LeetCode will start its IPO soon. In order to sell a good price of its shares to Venture Capital, LeetCode would like to work on some projects to increase its capital before the IPO. 
Since it has limited resources, it can only finish at most k distinct projects before the IPO. Help LeetCode design the best way to maximize its total capital after finishing at most k distinct projects.
You are given n projects where the ith project has a pure profit profits[i] and a minimum capital of capital[i] is needed to start it.
Initially, you have w capital. When you finish a project, you will obtain its pure profit and the profit will be added to your total capital.
Pick a list of at most k distinct projects from given projects to maximize your final capital, and return the final maximized capital.
The answer is guaranteed to fit in a 32-bit signed integer.

Example 1:
Input: k = 2, w = 0, profits = [1,2,3], capital = [0,1,1]
Output: 4
Explanation: Since your initial capital is 0, you can only start the project indexed 0.
After finishing it you will obtain profit 1 and your capital becomes 1.
With capital 1, you can either start the project indexed 1 or the project indexed 2.
Since you can choose at most 2 projects, you need to finish the project indexed 2 to get the maximum capital.
Therefore, output the final maximized capital, which is 0 + 1 + 3 = 4.

Example 2:
Input: k = 3, w = 0, profits = [1,2,3], capital = [0,1,2]
Output: 6

Constraints:
1 <= k <= 10^5
0 <= w <= 10^9
n == profits.length
n == capital.length
1 <= n <= 10^5
0 <= profits[i] <= 10^4
0 <= capital[i] <= 10^9
*/

// ��ʱ
void myQiuckSort(int* pros, int* caps, int left, int right)
{
    if (left >= right)
        return;
    int i = left;
    int j = right;
    int key = caps[left];
    int tmp;
    while (i < j)
    {
        while (i < j && key <= caps[j])
            j--;
        tmp = pros[i];
        pros[i] = pros[j];
        pros[j] = tmp;
        tmp = caps[i];
        caps[i] = caps[j];
        caps[j] = tmp;
        while (i < j && key >= caps[i])
            i++;
        tmp = pros[i];
        pros[i] = pros[j];
        pros[j] = tmp;
        tmp = caps[i];
        caps[i] = caps[j];
        caps[j] = tmp;
    }
    myQiuckSort(pros, caps, left, i - 1);
    myQiuckSort(pros, caps, i + 1, right);
}

void myQiuckSortSingle(int* pros, int left, int right)
{
    if (left >= right)
        return;
    int i = left;
    int j = right;
    int key = pros[left];
    int tmp;
    while (i < j)
    {
        while (i < j && key >= pros[j])
            j--;
        tmp = pros[i];
        pros[i] = pros[j];
        pros[j] = tmp;
        while (i < j && key <= pros[i])
            i++;
        tmp = pros[i];
        pros[i] = pros[j];
        pros[j] = tmp;
    }
    myQiuckSortSingle(pros, left, i - 1);
    myQiuckSortSingle(pros, i + 1, right);
}

int findMaximizedCapital(int k, int w, int* profits, int profitsSize, int* capital, int capitalSize)
{
    // ���������ʱ�������profits�������ʱ�capital��С��������
    myQiuckSort(profits, capital, 0, profitsSize - 1);
    int i = 0;
    int start_idx, end_idx,pre_idx;
    int max_idx;
    max_idx=pre_idx=end_idx = start_idx = 0;
    // �������ʽ�������Ŀ��
    while (i < k)
    {
        while (end_idx < profitsSize && w >= capital[end_idx])
            ++end_idx;
        if (pre_idx == end_idx)
        {
            
        }
        else
        {
            max_idx = 0;
            // �ҵ���ǰ���������Ŀ
            myQiuckSortSingle(profits, 0, end_idx - 1);
            // ���㵱ǰ��Ŀ�����ʽ𣬲�������ʹ�õ���Ŀ����ֵ
        }
        w += profits[max_idx];
        profits[max_idx++] = 0;
        i++;
        pre_idx = end_idx;
    }
    return w;
}
/*
* ִ�н��������ʱ������
*/


typedef struct {
    int p; // profit
    int c; // capital
} node_t;

int cmpc(const void* a, const void* b)
{ // �Գɱ�cost�������򣬴�С����
    node_t* n1 = (node_t*)a;
    node_t* n2 = (node_t*)b;
    return n1->c - n2->c;
}

int cmpp(const void* a, const void* b)
{ // ������profit�������򣬴�С����
    node_t* n1 = (node_t*)a;
    node_t* n2 = (node_t*)b;
    return n1->p - n2->p;
}

int gd(int k, int w, node_t* a, int n)
{ // ̰��greedy�㷨��ÿ�ζ�ѡ�����������Ǹ�
    if (k == 0 || w < 0 || a == NULL || n <= 0) {
        return 0;
    }
    node_t c[n];
    memset(c, 0, sizeof(c));
    qsort(a, n, sizeof(node_t), cmpc);
    for (int ai = 0, ci = 0; k > 0; k--) {
        bool inserted = false; // ����� 
        while (ai < n && a[ai].c <= w) { // ����ѡ 
            inserted = true;
            c[ci] = a[ai];
            ci++, ai++;
        }
        if (ci > 0) {
            if (inserted) { // ��Ԫ�ز��룬���������� 
                qsort(c, ci, sizeof(node_t), cmpp);
            }
            w += c[ci - 1].p; // ���һ����ȡ�� 
            ci--; // ���һ����ȡ��
        }
    }
    return w;
}

int findMaximizedCapital(int k, int w, int* p, int pn, int* c, int cn)
{
    if (k == 0 || w < 0 || p == NULL || pn <= 0 || c == NULL || cn <= 0) {
        return 0;
    }
    node_t a[pn];
    memset(a, 0, sizeof(a));
    for (int i = 0; i < pn; i++) {
        a[i].p = p[i];
        a[i].c = c[i];
    }
    return gd(k, w, a, pn);
}
/*
* ִ�н����ͨ��
* ִ����ʱ��172 ms, ������ C �ύ�л�����31.48%���û�
* �ڴ����ģ�16.8 MB, ������ C �ύ�л�����75.93%���û�
* ͨ������������35 / 35
*/
