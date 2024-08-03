class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int index1 = m - 1;
        int index2 = n - 1;
        int indexMerged = m + n - 1;

        while (index2 >= 0)
        {
            if (index1 >= 0 && nums1[index1] > nums2[index2])
            {
                nums1[indexMerged] = nums1[index1];
                index1--;
            }
            else
            {
                nums1[indexMerged] = nums2[index2];
                index2--;
            }
            indexMerged--;
        }

        //    This Solution is Using Extra Space
        // vector<int> arr(m + n);
        // int index = 0, in1 = 0, in2 = 0;
        // while (in1 < m && in2 < n)
        // {

        //     if (nums1[in1] < nums2[in2])
        //     {
        //         arr[index++] = nums1[in1++];
        //     }
        //     else
        //     {
        //         arr[index++] = nums2[in2++];
        //     }
        // }
        // while (in1 < m)
        // {
        //     arr[index++] = nums1[in1++];
        // }
        // while (in2 < n)
        // {
        //     arr[index++] = nums2[in2++];
        // }
        // for (int i = 0; i < m + n; i++)
        // {
        //     nums1[i] = arr[i];
        // }
    }
};
