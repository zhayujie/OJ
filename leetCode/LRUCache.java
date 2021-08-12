import java.util.*;

/**
 * @author zhayujie
 * @description
 * @date 2021/8/5
 */
public class LRUCache {
    private int capacity;
    private Map<Integer, Node> cache;
    private Node head;

    class Node {
        int key;
        int val;
        Node prev;
        Node next;
    }

    public LRUCache(int capacity) {
        this.capacity = capacity;
        this.cache = new HashMap<>(capacity);
        this.head = new Node();
        // 虚拟头节点
        head.prev = head;
        head.next = head;
    }

    public int get(int key) {
        Node v = cache.get(key);
        if (v == null) {
            return -1;
        }
        remove(v);
        addToHead(v);
        return v.val;
    }

    public void put(int key, int value) {
        Node v = cache.get(key);
        if (v != null) {
            v.val = value;
            remove(v);
            addToHead(v);
            cache.put(key, v);
            return;
        }
        if (cache.size() == capacity) {
            // 淘汰末尾的least recent used元素
            // 注意要先从map移除，再从链表移除
            cache.remove(head.prev.key);
            remove(head.prev);
        }
        Node e = new Node();
        e.key = key;
        e.val = value;
        addToHead(e);
        cache.put(key, e);
    }

    private void addToHead(Node v) {
        // 头部插入节点
        v.next = head.next;
        v.prev = head;
        head.next.prev = v;
        head.next = v;
    }

    private void remove(Node v) {
        // 移除某个节点
        v.prev.next = v.next;
        v.next.prev = v.prev;
    }


    public static void main(String[] args) {
        LRUCache lRUCache = new LRUCache(2);
        lRUCache.put(1, 1); // 缓存是 {1=1}
        lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
        lRUCache.get(1);    // 返回 1
        lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
        lRUCache.get(2);    // 返回 -1 (未找到)
        lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
        lRUCache.get(1);    // 返回 -1 (未找到)
        lRUCache.get(3);    // 返回 3
        lRUCache.get(4);    // 返回 4
    }
}
