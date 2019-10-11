public class ClassLoadTest {
    static int a = 3;

    static {
        System.out.println("static init");
    }

}

class subLoad extends ClassLoadTest {
    static {
        System.out.println("static sub init");
    }
}


class Sub {
    public static void main(String[] args) {
        System.out.println(subLoad.a);
    }
}