/**
 * @author zhayujie
 * @description
 * @date 2020/12/20
 */
public class Contest22001 {
    public String reformatNumber(String number) {
        char[] chs = number.toCharArray();
        char[] numChs = new char[chs.length+1];
        int i = 0;
        for (char ch : chs) {
            if (ch >= '0' && ch <= '9') {
                numChs[i] = ch;
                i++;
            }
        }
        numChs[i] = 0;
        int j = 0, lastSymbol = -1;
        StringBuilder str = new StringBuilder();
        while (numChs[j] != 0) {
            str.append(numChs[j]);
            if (i - j + 1 > 4 || i == 2 || i == 3) {
                if (j % 3 == 2 && j < i - 1) {
                    str.append("-");
                    lastSymbol = j;
                }
            } else {
                if (i - j - 1 == 2 && lastSymbol != j-1) {
                    str.append("-");
                }
            }
            j++;
        }
        return str.toString();
    }

    public static void main(String[] args) {
        System.out.println(new Contest22001().reformatNumber("123 4-567"));
        System.out.println(new Contest22001().reformatNumber("123 4-5678"));
        System.out.println(new Contest22001().reformatNumber("--17-5 229 35-39475 "));
        System.out.println(new Contest22001().reformatNumber("12"));
        System.out.println(new Contest22001().reformatNumber("9964"));

    }
}
