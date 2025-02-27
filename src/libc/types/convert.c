#include <orion/stdint.h>
#include <orion/stdbool.h>
#include <orion/string.h>

void itoa(int32_t N, char *str) {
    int i = 0;
    bool isNegative = false;
 
    /* Handle 0 explicitly, otherwise empty string is
     * printed for 0 */
    if (N == 0) {
        str[i++] = '0';
        str[i] = '\0';
        return;
    }
 
    // In standard itoa(), negative numbers are handled
    // only with base 10. Otherwise numbers are
    // considered unsigned.
    if (N < 0) {
        isNegative = true;
        N = -N;
    }
 
    // Process individual digits
    while (N != 0) {
        uint8_t rem = (uint8_t)N % 10;
        str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
        N = N / 10;
    }
 
    // If number is negative, append '-'
    if (isNegative)
        str[i++] = '-';
 
    str[i] = '\0'; // Append string terminator
 
    // Reverse the string
    reverse(str);
    return;
}