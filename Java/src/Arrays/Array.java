package Arrays;

public class Array {
    public static void main(String[] args) {
        // Basics syntax of arrays
        // Initialization and declaration in one line
        int[] arr = { 1, 2, 3, 4, 5 };
        int[] res = runningSumOf1DArray(arr);

        for (int val : res) {
            System.out.print(val + " ");
        }
    }

    public static void swapArrayElements(int[] arr, int i, int j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    public static void reverseAnArray(int[] arr, int i, int j) {
        while (i < j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    public static int maxArrayElement(int[] arr) {
        int maxEl = arr[0];
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] > maxEl)
                maxEl = arr[i];
        }
        return maxEl;
    }

    public static int minArrayElement(int[] arr) {
        int minEl = arr[0];
        for (int i = 1; i < arr.length; i++) {
            if (arr[i] < minEl)
                minEl = arr[i];
        }
        return minEl;
    }

    public static void rotateArrayKTimes(int[] arr, int k) {
        // k is the rotating factor
        k = k % arr.length;
        if (k < 0) {
            k += arr.length;
        }
        for (int r = 1; r <= k; r++) {
            int temp = arr[arr.length - 1];
            for (int i = arr.length - 1; i > 0; i--) {
                arr[i] = arr[i - 1];
            }
            arr[0] = temp;
        }
    }

    public static int[] secondLargestElementInArray(int[] arr) {

        int largest = arr[0];
        int secondLargest = Integer.MIN_VALUE;

        for (int i = 1; i < arr.length; i++) {
            if (arr[i] > largest) {
                secondLargest = largest;
                largest = arr[i];
            } else if (arr[i] < largest && arr[i] > secondLargest) {
                secondLargest = arr[i];
            }
        }

        return new int[] { largest, secondLargest };
    }

    public static void isSortedOrNot(int[] arr) {
        boolean isSorted = true;

        for (int i = 1; i < arr.length; i++) {
            if (arr[i] < arr[i - 1]) {
                isSorted = false;
            }
        }

        if (isSorted) {
            System.out.println("Array is sorted");
        } else {
            System.out.println("Array is not sorted");
        }
    }

    public static int[] runningSumOf1DArray(int[] arr) {
        int[] result = new int[arr.length];
        result[0] = arr[0];

        for (int i = 1; i < arr.length; i++) {
            result[i] = result[i - 1] + arr[i];
        }
        return result;
    }

    public static int removeDuplicatesFromSortedArray(int[] arr) {
        int idx = 1;

        for (int i = 1; i < arr.length; i++) {
            if (arr[i - 1] != arr[i]) {
                arr[idx] = arr[i];
                idx += 1;
            }
        }
        return idx;
    }
}
