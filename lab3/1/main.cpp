#include <stdio.h>
#include <string.h>

int stepen(int b) {
    int c = 1;
    for (int i = 1; i <= b; i++) {
        c = c * 2;
    }
    return c;
}

int to10(long long a) {
    if (a < -65535 || a > 65535) {
        printf("ERROR\n");
        return 0;
    }

    int sign = (a < 0) ? 1 : 0;
    long long abs_val = (a < 0) ? -a : a;

    int bits_count = 1;
    if (sign == 0) {
        while (stepen(bits_count) - 1 < abs_val) {
            bits_count++;
        }
    } else {
        while (stepen(bits_count - 1) < abs_val) {
            bits_count++;
        }
    }

    long long val = abs_val;
    if (sign == 1) {
        val = stepen(bits_count) - abs_val;
    }

    printf("%d", sign);
    for (int i = bits_count - 1; i >= 0; i--) {
        printf("%d", (int)((val / stepen(i)) % 2));
    }
    printf("\n");
    return 0;
}

int to2(long long a) {
    if (a < 0) {
        printf("ERROR\n");
        return 0;
    }

    int digits[100];
    int len = 0;
    long long temp = a;

    if (temp == 0) {
        digits[0] = 0;
        len = 1;
    }
    while (temp > 0) {
        int d = temp % 10;
        if (d != 0 && d != 1) {
            printf("ERROR\n");
            return 0;
        }
        digits[len++] = d;
        temp /= 10;
    }

    if (len == 1 && digits[0] == 0) {
        digits[0] = 0;
        len = 2;
    } else if (len == 1 && digits[0] == 1) {
        digits[1] = 0;
        len = 2;
    }

    int sign = digits[len - 1];
    long long result = 0;

    for (int i = 0; i < len - 1; i++) {
        if (digits[i] == 1) {
            result += stepen(i);
        }
    }

    if (sign == 1) {
        result = result - stepen(len - 1);
    }

    if (result < -65535 || result > 65535) {
        printf("ERROR\n");
        return 0;
    }

    int check_bits = 1;
    long long abs_res = (result < 0) ? -result : result;
    if (result >= 0) {
        while (stepen(check_bits) - 1 < abs_res) {
            check_bits++;
        }
    } else {
        while (stepen(check_bits - 1) < abs_res) {
            check_bits++;
        }
    }

    if (check_bits + 1 != len) {
        printf("ERROR\n");
        return 0;
    }

    printf("%lld\n", result);
    return 0;
}

int main() {
    char s1[100], s2[100];

    if (scanf("%99s %99s", s1, s2) != 2) {
        printf("ERROR\n");
        return 0;
    }

    if (strcmp(s2, "10") == 0) {
        long long a;
        if (sscanf(s1, "%lld", &a) != 1) {
            printf("ERROR\n");
            return 0;
        }
        to10(a);
    } else if (strcmp(s2, "2") == 0) {
        if (s1[0] == '-') {
            printf("ERROR\n");
            return 0;
        }

        long long a;
        if (sscanf(s1, "%lld", &a) != 1) {
            printf("ERROR\n");
            return 0;
        }

        if (strcmp(s1, "00") == 0) {
            printf("0\n");
            return 0;
        }

        to2(a);
    } else {
        printf("ERROR\n");
    }

    return 0;
}
