package Recursions;

public class Recursion {
    public static void main(String[] args) {
        // System.out.println(factorial(5));
        // System.out.println(power(5, 2));
        // printDecreasing(5);
        printIncreasing(5);
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
}
