class Solution(object):
    def maxRotateFunction(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        n = A.length();
        if n == 0:
            return 0;
        max = -1;
        for i in range(len(A)):
            result = figure(A,n,i);
            if max < result:
                max = result;
        return max;
    def figure(self, A, length, start):
        sum = 0;
        i = 0;
        index = start;
        while i < length:
            sum += A[index] * i;
            i = i + 1;
            index = index + 1;
            if index >= length:
                index = 0;

        return sum;

if __name__ == '__main__':
    Solution
