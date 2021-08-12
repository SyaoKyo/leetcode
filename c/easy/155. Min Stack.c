/*
* 155. Min Stack
* Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
* Implement the MinStack class:
* MinStack() initializes the stack object.
* void push(val) pushes the element val onto the stack.
* void pop() removes the element on the top of the stack.
* int top() gets the top element of the stack.
* int getMin() retrieves the minimum element in the stack.
*  
* Example 1:
* Input
* ["MinStack","push","push","push","getMin","pop","top","getMin"]
* [[],[-2],[0],[-3],[],[],[],[]]
* Output
* [null,null,null,null,-3,null,0,-2]
* Explanation
* MinStack minStack = new MinStack();
* minStack.push(-2);
* minStack.push(0);
* minStack.push(-3);
* minStack.getMin(); // return -3
* minStack.pop();
* minStack.top();    // return 0
* minStack.getMin(); // return -2
*
* Constraints:
* -2^31 <= val <= 2^31 - 1
* Methods pop, top and getMin operations will always be called on non-empty stacks.
* At most 3 * 10^4 calls will be made to push, pop, top, and getMin.
*/
typedef struct MinStack
{
    int val;
    struct MinStack* next;
} MinStack;
typedef struct MinStackHead
{
    int min_stack[25];
    int top;
    MinStack* next;
}MinStackHead;
/** initialize your data structure here. */
const int MAX = ~(1 << 31);
/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);

 * minStackPop(obj);

 * int param_3 = minStackTop(obj);

 * int param_4 = minStackGetMin(obj);

 * minStackFree(obj);
*/
MinStackHead* minStackCreate()
{
    MinStackHead* msh = (MinStackHead*)malloc(sizeof(MinStackHead));
    msh->top = 0;
    msh->min_stack[msh->top] = MAX;
    msh->next = NULL;
    return msh;
}

void minStackPush(MinStackHead* obj, int val)
{
    MinStack* next = (MinStack*)malloc(sizeof(MinStack));
    next->val = val;
    next->next = obj->next;
    if (obj->min_stack[obj->top] >= val)
        obj->min_stack[++(obj->top)] = val;
    obj->next = next;
}

void minStackPop(MinStackHead* obj)
{
    MinStack* p = obj->next;
    if (p->val == obj->min_stack[obj->top])
        --(obj->top);
    obj->next = p->next;
    free(p);
    p = obj->next;
    // while (p!=NULL)
    // {
    //     printf("%d -> ",p->val);
    //     p=p->next;
    // }
    // printf("null\n");
}

int minStackTop(MinStackHead* obj)
{
    if (obj->next != NULL)
        return obj->next->val;
    else
        return 0;
}

int minStackGetMin(MinStackHead* obj)
{
    return obj->min_stack[obj->top];
}

void minStackFree(MinStackHead* obj)
{
    MinStack* p = obj->next;
    while (p != NULL)
    {
        MinStack* q = p->next;
        free(p);
        p = q;
    }
}

/*
* 执行结果：通过
* 执行用时：28 ms, 在所有 C 提交中击败了89.35%的用户
* 内存消耗：12.5 MB, 在所有 C 提交中击败了83.66%的用户
*/