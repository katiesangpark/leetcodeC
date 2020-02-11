double findMaxAverage(int* n, int numsSize, int k)
{
    if (k > numsSize)
        return 0.0;

    int* nums = malloc(sizeof(int) * (numsSize + 1));
    nums[0] = 0;

    for (int i = 0; i < numsSize; i ++)
        nums[i + 1] = nums[i] + n[i];

    numsSize ++;
    int s = 0;
    double max = ((double) nums[k]) / ((double) k);
    for (int i = k; i < numsSize; i ++)
    {
        double d;

        if (i - k != s)
        {
            d = ((double) (nums[i - k] - nums[s])) / (double) (i - k - s);
            if (d <= max)
                s = i - k;
        }

        if (max * (i - s) <= nums[i] -  nums[s])
        {
            for (int j = s; j <= i - k; j ++)
            {
                d = ((double) (nums[i] - nums[j])) / ((double) (i - j));
                if (d >= max)
                {
                    max = d;
                    s = j;
                }
            }
        }
    }
    return max;
}