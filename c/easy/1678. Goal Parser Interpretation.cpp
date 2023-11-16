/* 1678. Goal Parser Interpretation
 * You own a Goal Parser that can interpret a string command.
 * The command consists of an alphabet of "G", "()" and/or "(al)" in some order.
 * The Goal Parser will interpret "G" as the string "G",
 * "()" as the string "o" and "(al)" as the string "al".
 * The interpreted strings are then concatenated in the original order.
 * Given the string command, return the Goal Parser's interpretation of command.
 * Example 1:
 * Input: command = "G()(al)"
 * Output: "Goal"
 * Explanation: The Goal Parser interprets the command as follows:
 * G -> G
 * () -> o
 * (al) -> al
 * The final concatenated result is "Goal".
 *
 * Example 2:
 * Input: command = "G()()()()(al)"
 * Output: "Gooooal"
 *
 * Example 3:
 * Input: command = "(al)G(al)()()G"
 * Output: "alGalooG"
 *
 * Constraints:
 * 1 <= command.length <= 100
 * command consists of "G", "()", and/or "(al)" in some order.
 */

class Solution {
public:
    string interpret(string command) {
        int idx = command.find("()");
        while (idx != -1) {
            command.replace(idx, 2, "o");
            idx = command.find("()");
        }
        idx = command.find("(al)");
        while (idx != -1) {
            command.replace(idx, 4, "al");
            idx = command.find("(al)");
        }
        return command;
    }
};

// 时间0 ms，击败100%
// 内存6.4 MB，击败25.63%