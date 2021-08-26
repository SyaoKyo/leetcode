/*
* 1089. Duplicate Zeros
* Given a fixed-length integer array arr, duplicate each occurrence of zero, shifting the remaining elements to the right.
Note that elements beyond the length of the original array are not written. Do the above modifications to the input array in place and do not return anything.

Example 1:
Input: arr = [1,0,2,3,0,4,5,0]
Output: [1,0,0,2,3,0,0,4]
Explanation: After calling your function, the input array is modified to: [1,0,0,2,3,0,0,4]

Example 2:
Input: arr = [1,2,3]
Output: [1,2,3]
Explanation: After calling your function, the input array is modified to: [1,2,3]

Constraints:
1 <= arr.length <= 10^4
0 <= arr[i] <= 9
*/

// ����
void duplicateZeros(int* arr, int arrSize)
{
    int i = 0;
    while (i < arrSize)
    {
        if (arr[i] == 0)
        {
            int j = arrSize - 1;
            while (j > i)
                arr[j--] = arr[j - 1];
            arr[j] = 0;
            i++;
        }
        ++i;
    }
}
/*
* ִ�н����ͨ��
* ִ����ʱ��52 ms, ������ C �ύ�л�����40.91%���û�
* �ڴ����ģ�7.2 MB, ������ C �ύ�л�����77.27%���û�
* ͨ������������30 / 30
*/

// �ռ任ʱ�䣨������Ҫ��
void duplicateZeros(int* arr, int arrSize)
{
    int tmp[arrSize];
    memcpy(tmp, arr, arrSize * sizeof(int));
    int i = 0, j = 0;
    while (i + j < arrSize)
    {
        arr[i + j] = tmp[i];
        if (tmp[i] == 0)
        {
            ++j;
            if (i + j < arrSize)
                arr[i + j] = tmp[i];
        }
        ++i;
    }
}
/*
* ִ�н����ͨ��
* ִ����ʱ��12 ms, ������ C �ύ�л�����98.86%���û�
* �ڴ����ģ�7.3 MB, ������ C �ύ�л�����71.59%���û�
* ͨ������������30 / 30
*/

// �Ż�
void duplicateZeros(int* arr, int arrSize)
{
    int possibleDups = 0;
    int length_ = arrSize - 1;
    // ͳ��0������
    for (int left = 0; left <= length_ - possibleDups; left++)
        if (arr[left] == 0)
        {
            if (left == length_ - possibleDups)
            {
                arr[length_] = 0;
                length_ -= 1;
                break;
            }
            possibleDups++;
        }
    int last = length_ - possibleDups;
    // ��д0
    for (int i = last; i >= 0; i--)
        if (arr[i] == 0)
        {
            arr[i + possibleDups] = 0;
            possibleDups--;
            arr[i + possibleDups] = 0;
        }
        else
            arr[i + possibleDups] = arr[i];
}
/*
* ִ�н����ͨ��
* ִ����ʱ��16 ms, ������ C �ύ�л�����88.64%���û�
* �ڴ����ģ�7.2 MB, ������ C �ύ�л�����90.91%���û�
* ͨ������������30 / 30
*/
