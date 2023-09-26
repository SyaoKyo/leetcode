/* 146. LRU Cache
 * Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.
 * Implement the LRUCache class:
 * LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
 * int get(int key) Return the value of the key if the key exists, otherwise return -1.
 * void put(int key, int value) Update the value of the key if the key exists.
 * Otherwise, add the key-value pair to the cache.
 * If the number of keys exceeds the capacity from this operation, evict the least recently used key.
 * The functions get and put must each run in O(1) average time complexity.
 *
 * Example 1:
 * Input
 * ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
 * [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
 * Output
 * [null, null, null, 1, null, -1, null, -1, 3, 4]
 *
 * Explanation
 * LRUCache lRUCache = new LRUCache(2);
 * lRUCache.put(1, 1); // cache is {1=1}
 * lRUCache.put(2, 2); // cache is {1=1, 2=2}
 * lRUCache.get(1);    // return 1
 * lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
 * lRUCache.get(2);    // returns -1 (not found)
 * lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
 * lRUCache.get(1);    // return -1 (not found)
 * lRUCache.get(3);    // return 3
 * lRUCache.get(4);    // return 4
 *
 * Constraints:
 * 1 <= capacity <= 3000
 * 0 <= key <= 10^4
 * 0 <= value <= 10^5
 * At most 2 * 10^5 calls will be made to get and put.
 * */

class LinkNode
{
public:
    int key;
    int value;
    LinkNode *next;

    LinkNode(int key, int value, LinkNode *next)
    {
        this->key = key;
        this->value = value;
        this->next = next;
    }
};


class LRUCache
{
private:
    int capacity;
    LinkNode *head, *tail;
    map<int, LinkNode*> keyToPre{};

    void pushBack(LinkNode *node)
    {
        keyToPre[node->key] = tail;
        tail->next = node;
        tail = node;
    }

    void popFront()
    {
        LinkNode *node = head->next;
        keyToPre.erase(keyToPre.find(node->key));
        head->next = node->next;
        keyToPre[node->next->key] = head;
    }

    void kick(LinkNode *pre)
    {
        LinkNode *node = pre->next;
        if (node == tail)
            return;

        pre->next = node->next;
        keyToPre[node->next->key] = pre;
        node->next = nullptr;

        pushBack(node);
    }
public:
    LRUCache(int capacity)
    {
        head = new LinkNode(0, 0, nullptr);
        tail = head;
        this->capacity = capacity;
    }

    int get(int key)
    {
        if (keyToPre.find(key) == keyToPre.end())
            return -1;
        LinkNode *pre = keyToPre[key];
        LinkNode *curr = pre->next;

        kick(pre);
        return curr->value;
    }

    void put(int key, int value)
    {
        if (keyToPre.find(key) != keyToPre.end())
        {
            kick(keyToPre[key]);
            tail->value = value;
            return;
        }
        LinkNode *newNode = new LinkNode(key, value, nullptr);
        pushBack(newNode);
        if (keyToPre.size() > capacity)
            popFront();
    }
};

// 时间432 ms，击败43.36%
// 内存160.7 MB，击败93.88%