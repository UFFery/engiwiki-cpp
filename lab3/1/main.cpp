#include <stdio.h>

int stepen(int b) {
    int c = 1;
    for (int i = 1; i <= b; i++) {
        c = c * 2;
    }
    return c;
}

int to2(long long a) {
    if (a < -65535 || a > 65535) {
        printf("ERROR\n");
        return 0;
    }

    if (a >= 0) {
        int bits_count = 1;
        while (stepen(bits_count) <= a) {
            bits_count++;
        }
        printf("0");
        for (int i = bits_count - 1; i >= 0; i--) {
            printf("%d", (int)((a / stepen(i)) % 2));
        }
        printf("\n");
        return 0;
    }

    long long abs_val = -a;
    if (abs_val == 65535) {
        printf("1");
        for (int i = 0; i < 16; i++) printf("1");
        printf("\n");
        return 0;
    }

    int bits_count_pos = 1;
    while (stepen(bits_count_pos) <= abs_val) {
        bits_count_pos++;
    }
    int bits_count = bits_count_pos + 1;
    long long val = stepen(bits_count) - abs_val;

    for (int i = bits_count - 1; i >= 0; i--) {
        printf("%d", (int)((val / stepen(i)) % 2));
    }
    printf("\n");
    return 0;
}

int to10(long long a) {
    if (a < 0) {
        printf("ERROR\n");
        return 0;
    }

    int digits[100];
    int len = 0;
    long long temp = a;

    if (temp == 0) {
        digits[len++] = 0;
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

    if (len < 2) {
        printf("ERROR\n");
        return 0;
    }

    int sign = digits[len - 1];
    long long val = 0;
    for (int i = 0; i < len - 1; i++) {
        if (digits[i] == 1) {
            val += stepen(i);
        }
    }

    long long result;
    if (sign == 0) {
        result = val;
    } else {
        if (len == 2 && val == 0) {
            result = 0;
        } else if (len == 17 && val == 65535) {
            result = -65535;
        } else {
            result = val - stepen(len - 1);
        }
    }

    if (result < -65535 || result > 65535) {
        printf("ERROR\n");
        return 0;
    }

    printf("%lld\n", result);
    return 0;
}

int main() {
    long long a;
    int b;

    if (scanf("%lld %d", &a, &b) != 2) {
        printf("ERROR\n");
        return 0;
    }

    if (b == 10) {
        to2(a);
    } else if (b == 2) {
        if (a < 0) {
            printf("ERROR\n");
            return 0;
        }
        to10(a);
    } else {
        printf("ERROR\n");
    }

    return 0;
}
