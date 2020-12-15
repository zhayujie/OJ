import java.util.HashMap;
import java.util.Map;

/**
 * @author yujiezha
 * @description
 * @date 2020/12/15
 */
public class No013 {
    public int romanToInt(String s) {
        if (s == null || s.length() <= 0) {
            return 0;
        }
        Map<String, Integer> map = new HashMap<>(16);
        map.put("I", 1);
        map.put("IV", 4);
        map.put("V", 5);
        map.put("IX", 9);
        map.put("X", 10);
        map.put("XL", 40);
        map.put("L", 50);
        map.put("XC", 90);
        map.put("C", 100);
        map.put("CD", 400);
        map.put("D", 500);
        map.put("CM", 900);
        map.put("M", 1000);
        char[] chs = s.toCharArray();
        int count = 0;
        for (int i = 0; i < chs.length; i++) {
            if (i < chs.length - 1) {
                // 优先匹配两个字符
                String temp = chs[i] + "" +chs[i+1];
                if (map.get(temp) != null) {
                    count += map.get(temp);
                    i++;
                    continue;
                }
            }
            // 未命中则匹配一个字符
            count += map.get(chs[i] + "");
        }
        return count;
    }

    public static void main(String[] args) {
        System.out.println(new No013().romanToInt("III"));
        System.out.println(new No013().romanToInt("IV"));
        System.out.println(new No013().romanToInt("IX"));
        System.out.println(new No013().romanToInt("LVIII"));
        System.out.println(new No013().romanToInt("MCMXCIV"));
    }
}
