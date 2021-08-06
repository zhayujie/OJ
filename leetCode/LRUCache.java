import java.util.*;

/**
 * @author zhayujie
 * @description
 * @date 2021/8/5
 */
public class LRUCache {
    private Entry head;
    private Map<Integer, Entry> map;
    private int capacity;

    public class Entry {
        public Integer key;
        public Integer val;
        public Entry prev;
        public Entry next;
    }

    public LRUCache(int capacity) {
        this.capacity = capacity;
        this.map = new HashMap<>(capacity);
        // 虚拟头节点
        head = new Entry();
        head.prev = head;
        head.next = head;
    }

    public int get(int key) {
        Entry val = map.get(key);
        if (val == null) {
            return -1;
        }
        moveToFront(val);
        return val.val;
    }

    public void put(int key, int value) {
        Entry val = map.get(key);
        if (val != null) {
            val.val = value;
            moveToFront(val);
            return;
        }
        Entry e = new Entry();
        e.key = key;
        e.val = value;
        if (map.size() == capacity) {
            // 移除尾部 least recent used
            Entry tail = head.prev;
            Entry newTail = tail.prev;
            newTail.next = head;
            head.prev = newTail;
            map.remove(tail.key);
        }
        map.put(key, e);

        // 头部插入
        e.next = head.next;
        e.prev = head;
        head.next.prev = e;
        head.next = e;
    }

    private void moveToFront(Entry val) {
        // 将某个节点移动到头部
        val.prev.next = val.next;
        val.next.prev = val.prev;
        val.prev = head;
        val.next = head.next;
        head.next.prev = val;
        head.next = val;
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
