class MultiplyArray {
    public int[] multiply(int[] A) {
        int len1 = A.length;
        if (len1 < 2)   return A;

        int[] B = new int[len1];
        B[0] = A[0];
        for (int i = 1; i < len1; i++) {
            B[i] = B[i-1] * A[i];
        }
        int back = 1;
        for (int j = len1-1; j >= 0; j--) {
            if (j < len1-1)     back *= A[j+1];
            B[j] = j == 0 ? back : B[j-1] * back;
        }
        return B;
    }
}
