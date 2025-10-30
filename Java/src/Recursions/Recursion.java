package Recursions;

public class Recursion {
    public static void main(String[] args) {
        // String s = "abxxcdxxe";
        // removeCharactersOccurenceFromString(s, 0, 'x', "");
        subsequencesOfString("abc", 0, "");
    }

    public static int factorial(int n) {
        if (n == 1)
            return 1;
        return n * factorial(n - 1);
    }

    public static int power(int a, int b) {
        if (b == 0)
            return 1;
        return a * power(a, b - 1);
    }

    public static void printDecreasing(int n) {
        if (n == 0)
            return;
        System.out.print(n + " ");
        printDecreasing(n - 1);
    }

    public static void printIncreasing(int n) {
        if (n == 0)
            return;
        printIncreasing(n - 1);
        System.out.print(n + " ");
    }

    public static int fibonacci(int n) {
        if (n <= 1)
            return n;
        return fibonacci(n - 1) + fibonacci(n - 2);
    }

    // Given a number x, count the number of binary strings of length x,
    // which has no consecutive 1's
    public static int countBinaryStrings(int n) {
        if (n == 1)
            return 2;
        if (n == 2)
            return 3;

        return countBinaryStrings(n - 1) + countBinaryStrings(n - 2);
    }

    public static int maxElement(int[] arr, int idx) {
        if (idx == arr.length - 1)
            return arr[idx];
        return Math.max(arr[idx], maxElement(arr, idx + 1));
    }

    // Given an array and a number x, return index of first occurence of x.
    public static int returnIndexOfAnElement(int[] arr, int idx, int x) {
        if (idx >= arr.length)
            return -1;
        return arr[idx] == x ? idx : returnIndexOfAnElement(arr, idx + 1, x);
    }

    // House Robber Problem -- Not optimized code
    public static int houseRobber(int[] arr, int idx) {
        if (idx >= arr.length)
            return 0;
        return Math.max(arr[idx] + houseRobber(arr, idx + 2), houseRobber(arr, idx + 1));
    }

    // Basic Pattern Problems using recursion
    public static void pattern1(int n, int rows, int cols) {
        if (rows == n)
            return;

        if (cols == n) {
            System.out.println();
            pattern1(n, rows + 1, 0);
            return;
        }
        System.out.print("*" + " ");
        pattern1(n, rows, cols + 1);
    }

    public static void pattern2(int n, int rows, int cols) {
        if (rows == n)
            return;

        if (cols > rows) {
            System.out.println();
            pattern2(n, rows + 1, 0);
            return;
        }
        System.out.print("*" + " ");
        pattern2(n, rows, cols + 1);
    }

    public static void removeCharactersOccurenceFromString(String s, int idx, int x, String str) {
        if (idx >= s.length()) {
            System.out.println((str));
            return;
        }
        if (s.charAt(idx) != x) {
            removeCharactersOccurenceFromString(s, idx + 1, x, str + s.charAt(idx));
        } else {
            removeCharactersOccurenceFromString(s, idx + 1, x, str);
        }
    }

    public static void subsequencesOfString(String s, int idx, String str) {
        if (idx >= s.length()) {
            System.out.println("[" + str + "]");
            return;
        }
        subsequencesOfString(s, idx + 1, str + s.charAt(idx));
        subsequencesOfString(s, idx + 1, str);
    }
}
