import java.util.PriorityQueue;

/**
 * @author zhayujie
 * @description
 * @date 2020/12/20
 */
public class Contest22101 {
    public int eatenApples(int[] apples, int[] days) {
        // 优先队列，队首是最早过期的  int[0]:苹果个数  int[1]:过期时间
        PriorityQueue<int[]> queue = new PriorityQueue<>((o1, o2) -> o1[1] < o2[1] ? -1 : 1);
        int eatNum = 0;
        for (int i = 0; i < apples.length || queue.size() > 0; i++) {
            //1.移除过期的
            while (!queue.isEmpty()) {
                int[] apple = queue.peek();
                if (apple[1] <= i) {
                    queue.poll();
                } else {
                    break;
                }
            }
            //2.添加当天新长出来的
            if (i < apples.length && apples[i] > 0) {
                queue.add(new int[]{apples[i], days[i] + i});
            }
            //3.吃掉已有的（优先吃最早过期的）
            int[] ap = queue.peek();
            if (ap != null && ap[0] > 0) {
                eatNum++;
                ap[0] -= 1;
                if (ap[0] == 0) {
                    queue.poll();
                }
            }
        }
        return eatNum;
    }

    public static void main(String[] args) {
        System.out.println(new Contest22101().eatenApples(new int[]{1,2,3,5,2}, new int[]{3,2,1,4,2}));
        System.out.println(new Contest22101().eatenApples(new int[]{3,0,0,0,0,2}, new int[]{3,0,0,0,0,2}));
    }
}
