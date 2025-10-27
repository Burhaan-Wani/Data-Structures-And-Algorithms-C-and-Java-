package arrays.TwoPointer;

import java.util.Arrays;

public class Pointers {
    public static void main(String[] args) {
        // removeDuplicateFromSortedAray();
        sortZeroesAndOnes();
    }

    public static void removeDuplicateFromSortedAray() {
        int[] arr = { 0, 0, 1, 1, 1, 2, 2, 3, 3, 4 };
        int iIdx = 1;

        for (int i = 1; i < arr.length; i++) {
            if (arr[i] != arr[i - 1]) {
                arr[iIdx] = arr[i];
                iIdx++;
            }
        }

        for (int i = 0; i < iIdx; i++) {
            System.out.print(arr[i] + " ");
        }
    }

    public static void sortZeroesAndOnes() {
        int[] arr = { 0, 1, 1, 0, 0, 1, 0 };
        int left = 0;
        int right = arr.length - 1;

        while (left <= right) {
            if (arr[left] == 0) {
                left++;
            } else {
                int temp = arr[left];
                arr[left] = arr[right];
                arr[right] = temp;
                right--;
            }
        }

        for (int val : arr) {
            System.out.print(val + " ");
        }
    }

    public static int numRescueBoats(int[] people, int limit) {
        // int[] people={3,2,2,1};

        Arrays.sort(people);
        int boats = 0;
        int left = 0;
        int right = people.length - 1;
        while (left <= right) {
            boats++;
            if (people[left] + people[right] <= limit) {
                left++;
            }
            right--;
        }
        return boats;
    }

    public static int[] twoSum(int[] numbers, int target) {
        // int[] numbers={2,7,11,15};

        int low = 0;
        int high = numbers.length - 1;

        while (low < high) {
            int sum = numbers[low] + numbers[high];
            if (sum == target) {
                return new int[] { low + 1, high + 1 };
            } else if (sum > target) {
                high--;
            } else {
                low++;
            }
        }
        return new int[] { -1, -1 };
    }

    public static void nextPermutation(int[] nums) {
        // int[] nums={1,5,8,4,7,6,5,3,1};

        int i = nums.length - 1;
        while (i >= 1 && nums[i - 1] >= nums[i]) {
            i--;
        }
        if (i == 0) {
            // Array is in descending order, reverse to get smallest permutation
            reverse(nums, 0);
            return;
        }
        int k = 0;
        for (int j = i; j < nums.length; j++) {
            if (nums[j] > nums[i - 1]) {
                k = j;
            }
        }

        swap(nums, i - 1, k);
        reverse(nums, i);
    }

    // utility functions
    private static void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }

    private static void reverse(int[] nums, int start) {
        int i = start, j = nums.length - 1;
        while (i < j) {
            swap(nums, i, j);
            i++;
            j--;
        }
    }
}
