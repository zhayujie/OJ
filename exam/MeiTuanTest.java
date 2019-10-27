class ReviewEncourage {
    private volatile int count = 1;
    private int max;
    private volatile int isB = 1;

    public ReviewEncourage(int n) {
        max = n;
    }      // 构造函数,n为中奖用户数

    public static class PrizePool {

        public void send(String input) {

            System.out.print(input);

        }

    }

    public void bonus(PrizePool prizePool) {
        while (count <= max) {
            synchronized (this) {
                while (count % 2 == 0) {
                    try {
                        wait();
                    } catch (Exception e) {

                    }
                }
                if (count <= max) {
                    prizePool.send("A");
                }
                count++;
                notifyAll();
            }
        }
    }  // 仅能打印A，表示发放积分

    public void coupon(PrizePool prizePool) {
        while (count <= max) {
            synchronized (this) {
                while (count % 2 == 1 || isB == 0) {
                    try {
                        wait();
                    } catch (Exception e) {

                    }
                }
                if (count <= max) {
                    prizePool.send("B");
                }
                isB = 0;
                count++;
                notifyAll();
            }
        }

    }  // 仅能打印B，表示发放优惠券

    public void contribution(PrizePool prizePool) {
        while (count <= max) {
            synchronized (this) {
                while (count % 2 == 1 || isB == 1) {
                    try {
                        wait();
                    } catch (Exception e) {

                    }
                }
                if (count <= max) {
                    prizePool.send("C");
                }
                isB = 1;
                count++;
                notifyAll();
            }
        }
    }  // 仅能打印C，表示发放贡献值

    public static void main(String[] args) {

        ReviewEncourage re = new ReviewEncourage(10);
        PrizePool pl = new ReviewEncourage.PrizePool();

        Thread t1 = new Thread() {
            @Override
            public void run() {
                re.bonus(pl);
            }
        };
        Thread t2 = new Thread() {
            @Override
            public void run() {
                re.coupon(pl);
            }
        };
        Thread t3 = new Thread() {
            @Override
            public void run() {
                re.contribution(pl);
            }
        };
        t1.start();
        t2.start();
        t3.start();
    }

}

