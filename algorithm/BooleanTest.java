import jdk.nashorn.internal.ir.debug.ObjectSizeCalculator;

class BooleanTest {
    private boolean a;
    private boolean b;
    private boolean c;
    private boolean d;
    private boolean e;
}


class BooleanSizeTest {
    public static void main(String[] args) {
        // 4个boolean值时对象占16字节，5个时占24字节，对象头12字节，说明 boolean值占1字节
        System.out.println(ObjectSizeCalculator.getObjectSize(new BooleanTest()));
    }
}