/**
 * @author zhayujie
 * @description
 * @date 2020/12/16
 */
public class No738 {
    public int monotoneIncreasingDigits(int N) {
        char chs[] = String.valueOf(N).toCharArray();
        int eqStart = 0;
        for (int i = 0; i < chs.length - 1; i++) {
            if (chs[i] < chs[i+1]) {
                // 更新相等序列的开始位置
                eqStart = i+1;
            } else if (chs[i] == chs[i+1]) {
                // 相等则不做操作
            } else  {
                // 遇到后一位比自己小的情况，找到相等序列的开始位置 退1位，后面的数字都设为9
                chs[eqStart] -= 1;
                for (int j = eqStart+1; j < chs.length; j++) {
                    chs[j] = '9';
                }
                return Integer.valueOf(String.valueOf(chs));
            }
        }
        return Integer.valueOf(String.valueOf(chs));
    }

    public static void main(String[] args) {
        System.out.println(new No738().monotoneIncreasingDigits(10));
        System.out.println(new No738().monotoneIncreasingDigits(1234));
        System.out.println(new No738().monotoneIncreasingDigits(332));
    }
}
