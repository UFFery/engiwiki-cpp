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

    int sign = (a < 0) ? 1 : 0;
    long long val = (a < 0) ? -a : a;

    int total_len = (a >= -128 && a <= 127) ? 8 : 17;
    int bits_count = total_len - 1;

    if (sign == 1) {
        val = stepen(bits_count) - val;
    }

    printf("%d", sign);

    for (int i = bits_count - 1; i >= 0; i--) {
        int bit = (val / stepen(i)) % 2;
        printf("%d", bit);
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
        digits[0] = 0;
        len = 1;
    }
    
    while (temp > 0) {
        int d = temp % 10;
        if (d != 0 && d != 1) {
            printf("ERROR\n");
            return 0;
        }
        digits[len] = d;
        len++;
        temp /= 10;
    }

    int sign = 0;
    int total_len = 0;

    if (len == 8) {
        sign = digits[7];
        total_len = 8;
    } else if (len == 17) {
        sign = digits[16];
        total_len = 17;
    } else if (len < 8) {
        sign = 0;
        total_len = 8;
        for (int i = len; i < 8; i++) {
            digits[i] = 0;
        }
    } else if (len > 8 && len < 17) {
        sign = 0;
        total_len = 17;
        for (int i = len; i < 17; i++) {
            digits[i] = 0;
        }
    } else {
        printf("ERROR\n");
        return 0;
    }

    long long result = 0;
    for (int i = 0; i < total_len - 1; i++) {
        if (digits[i] == 1) {
            result += stepen(i);
        }
    }

    if (sign == 1) {
        result = result - stepen(total_len - 1);
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
        to10(a); 
    } else if (b == 2) {
        to2(a);
    } else {
        printf("ERROR\n");
    }

    return 0;
}
