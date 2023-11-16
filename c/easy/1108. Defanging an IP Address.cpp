/* 1108. Defanging an IP Address
 * Given a valid (IPv4) IP address, return a defanged version of that IP address.
 * A defanged IP address replaces every period "." with "[.]".
 *
 * Example 1:
 * Input: address = "1.1.1.1"
 * Output: "1[.]1[.]1[.]1"
 *
 * Example 2:
 * Input: address = "255.100.50.0"
 * Output: "255[.]100[.]50[.]0"
 *
 * Constraints:
 * The given address is a valid IPv4 address.
 */

class Solution {
public:
    string defangIPaddr(string address) {
        while (address.find(".", address.rfind("[.]") + 2) != -1) {
            address.replace(address.find(".", address.rfind("[.]") + 2), 1, "[.]");
        }
        return address;
    }
};

// 时间0 ms，击败100%
// 内存6.1 MB，击败61.20%