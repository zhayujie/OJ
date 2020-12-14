/**
 * @author zhayujie
 * @description
 * @date 2020/12/14
 */
public class No011 {
    public int maxArea(int[] height) {
        int i = 0, j = height.length - 1;
        int max = 0;
        while (i < j) {
            max = Math.max(max, (j - i) * Math.min(height[i], height[j]));
            // 哪边的柱子矮则选择哪边走
            if (height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }
        return max;
    }

    public static void main(String[] args) {
        int[] array = new int[]{1,8,6,2,5,4,8,3,7};
        System.out.println(new No011().maxArea(array));
    }
}
