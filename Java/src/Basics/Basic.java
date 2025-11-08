package Basics;

public class Basic {
    public static void main(String[] args) {
        printAllDivisors(36);
    }

    public static int countDigits(int x) {
        int n = 0;
        while (x != 0) {
            x /= 10;
            n += 1;
        }
        return n;
    }

    public static int reverseNumber(int x) {
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;

            if (rev > Integer.MAX_VALUE / 10 || (rev == Integer.MAX_VALUE / 10 && pop > 7))
                return 0;
            if (rev < Integer.MIN_VALUE / 10 || (rev == Integer.MIN_VALUE / 10 && pop < -8))
                return 0;

            rev = rev * 10 + pop;
        }
        return rev;
    }

    public static boolean palindromeNumber(int x) {
        if ((x < 0) || (x % 10 == 0 && x != 0)) {
            return false;
        }
        int reverse = 0;
        while (x > reverse) {
            reverse = reverse * 10 + x % 10;
            x /= 10;
        }
        return x == reverse || x == reverse / 10;
    }

    public static void checkArmStrongNumber(int x) {
        int duplicate = x;
        int result = 0;
        int len = countDigits(x);
        while (x != 0) {
            int rem = x % 10;
            result += Math.powExact(rem, len);
            x /= 10;
        }

        if (duplicate == result) {
            System.out.println(duplicate + " is an armStrong number");
        } else {
            System.out.println(duplicate + " is not an armStrong number");
        }
    }

    public static void printAllDivisors(int x) {

        for (int i = 1; i * i <= x; i++) {
            if (x % i == 0) {
                System.out.println(i);
                if ((x / i) != i) {
                    System.out.println(x / i);
                }
            }
        }
    }
}
