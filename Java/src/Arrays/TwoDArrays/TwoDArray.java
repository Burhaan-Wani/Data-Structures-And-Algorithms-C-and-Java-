package Arrays.TwoDArrays;

import java.util.ArrayList;

public class TwoDArray {
    public static void main(String[] args) {
        int[][] one = {
                { 1, 2, 3 },
                { 4, 5, 6 },
        };
        int[][] two = {
                { 1, 2, 3 },
                { 4, 5, 6 },
                { 7, 8, 9 },
        };
        printArrayInWaveForm(one);
        transposeMatrix(two);

        int[][] res = matrixMultiplication(one, two);
        for (int[] val : res) {
            for (int el : val) {
                System.out.print(el + " ");
            }
            System.out.println();
        }

        RotateImage(two);

        spiralOrder(two);
    }

    public static void printArrayInWaveForm(int[][] arr) {

        for (int col = 0; col < arr[0].length; col++) {
            if (col % 2 == 0) {
                for (int i = 0; i < arr.length; i++) {
                    System.out.print(arr[i][col] + " ");
                }
            } else {
                for (int i = arr.length - 1; i >= 0; i--) {
                    System.out.print(arr[i][col] + " ");
                }

            }
        }
    }

    public static void transposeMatrix(int[][] arr) {
        /**
         * 1,2,3 1,4,7
         * 4,5,6 2,5,8
         * 7,8,9 3,6,9
         */
        int rows = arr.length;
        int cols = arr[0].length;
        int[][] result = new int[cols][rows];

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result[j][i] = arr[i][j];
            }
        }

        for (int[] val : result) {
            for (int el : val) {
                System.out.print(el + " ");
            }
            System.out.println();
        }
    }

    public static int[][] matrixMultiplication(int[][] one, int[][] two) {
        int cols = one[0].length;
        int rows = two.length;

        if (rows != cols) {
            return new int[0][0];
        }
        int[][] result = new int[one.length][two[0].length];

        for (int i = 0; i < result.length; i++) {
            for (int j = 0; j < result[i].length; j++) {
                int sum = 0;
                for (int k = 0; k < cols; k++) {
                    sum += one[i][k] * two[k][j];
                }
                result[i][j] = sum;
            }
        }
        return result;
    }

    public static void setZeroes(int[][] matrix) {
        int rows = matrix.length;
        int cols = matrix[0].length;
        boolean isRow = false;
        boolean isCol = false;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;

                    if (i == 0)
                        isRow = true;
                    if (j == 0)
                        isCol = true;
                }
            }
        }

        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        if (isRow) {
            for (int i = 0; i < cols; i++) {
                matrix[0][i] = 0;
            }
        }
        if (isCol) {
            for (int i = 0; i < rows; i++) {
                matrix[i][0] = 0;
            }
        }
    }

    public static void RotateImage(int[][] arr) {
        int rows = arr.length;
        int cols = arr[0].length;

        for (int col = 0; col < rows; col++) {
            int i = 0;
            int j = rows - 1;
            while (i < j) {
                int temp = arr[i][col];
                arr[i][col] = arr[j][col];
                arr[j][col] = temp;
                i++;
                j--;
            }
        }
        for (int i = 0; i < rows; i++) {
            for (int j = i + 1; j < cols; j++) {
                int temp = arr[i][j];
                arr[i][j] = arr[j][i];
                arr[j][i] = temp;
            }
        }

        for (int[] val : arr) {
            for (int el : val) {
                System.out.print(el + " ");
            }
            System.out.println();
        }
    }

    public static ArrayList<Integer> spiralOrder(int[][] matrix) {
        ArrayList<Integer> arraylist = new ArrayList<>();
        int m = matrix.length;
        int n = matrix[0].length;
        int sr = 0;
        int sc = 0;
        int er = m - 1;
        int ec = n - 1;
        int count = m * n;

        while (count > 0) {
            for (int i = sc; i <= ec; i++) {
                arraylist.add(matrix[sr][i]);
                count--;
            }
            sr++;
            if (count == 0)
                break;
            for (int i = sr; i <= er; i++) {
                arraylist.add(matrix[i][ec]);
                count--;
            }
            ec--;
            if (count == 0)
                break;
            for (int i = ec; i >= sc; i--) {
                arraylist.add(matrix[er][i]);
                count--;
            }
            er--;
            if (count == 0)
                break;
            for (int i = er; i >= sr; i--) {
                arraylist.add(matrix[i][sc]);
                count--;
            }
            sc++;
            if (count == 0)
                break;
        }
        return arraylist;
    }
}
