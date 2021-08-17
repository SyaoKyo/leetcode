/*
* 551. Student Attendance Record I
* You are given a string s representing an attendance record for a student where each character signifies 
* whether the student was absent, late, or present on that day. The record only contains the following three characters:
* 'A': Absent.
* 'L': Late.
* 'P': Present
* The student is eligible for an attendance award if they meet both of the following criteria:
* The student was absent ('A') for strictly fewer than 2 days total.
* The student was never late ('L') for 3 or more consecutive days.
* Return true if the student is eligible for an attendance award, or false otherwise.
* Example 1:
* Input: s = "PPALLP"
* Output: true
* Explanation: The student has fewer than 2 absences and was never late 3 or more consecutive days.
* Example 2:
* Input: s = "PPALLL"
* Output: false
* Explanation: The student was late 3 consecutive days in the last 3 days, so is not eligible for the award.
*  
* Constraints:
* 1 <= s.length <= 1000
* s[i] is either 'A', 'L', or 'P'.
*/

bool checkRecord(char* s)
{
    int strlens = strlen(s), i = 0;
    int count_L, count_A;
    count_A = count_L = 0;
    while (i < strlens)
    {
        switch (s[i])
        {
        case 'A':
            ++count_A;
            count_L = 0;
            if (count_A == 2)
                return false;
            break;
        case 'L':
            ++count_L;
            if (count_L == 3)
                return false;
            break;
        case 'P':
            count_L = 0;
            break;
        default:
            break;
        }
        ++i;
    }
    return true;
}
/*
* 执行结果：通过
* 执行用时：0 ms, 在所有 C 提交中击败了100.00%的用户
* 内存消耗：5.3 MB, 在所有 C 提交中击败了84.79%的用户
*/