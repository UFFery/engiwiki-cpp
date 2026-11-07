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
    long long abs_val = (a < 0) ? -a : a;

    int bits_count = 1;
    if (sign == 0) {
        while (stepen(bits_count) <= abs_val) {
            bits_count++;
        }
    } else {
        while (abs_val > stepen(bits_count - 1)) {
            bits_count++;
        }
    }

    long long val = abs_val;
    if (sign == 1) {
        val = stepen(bits_count) - abs_val;
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

    if (a == 0) {
        printf("0\n");
        return 0;
    }

    int digits[40];
    int len = 0;
    long long temp = a;

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

    long long val_neg = 0;
    for (int i = 0; i < len - 1; i++) {
        if (digits[i] == 1) {
            val_neg += stepen(i);
        }
    }
    val_neg -= stepen(len - 1);

    if (val_neg >= -65535 && val_neg <= 65535) {
        int bits_count = 1;
        long long abs_neg = -val_neg;
        while (abs_neg > stepen(bits_count - 1)) {
            bits_count++;
        }
        if (bits_count + 1 == len) {
            long long v = stepen(bits_count) - abs_neg;
            int match = 1;
            for (int i = 0; i < bits_count; i++) {
                if ((v % 2) != digits[i]) {
                    match = 0;
                }
                v /= 2;
            }
            if (match) {
                printf("%lld\n", val_neg);
                return 0;
            }
        }
    }

    long long val_pos = 0;
    for (int i = 0; i < len; i++) {
        if (digits[i] == 1) {
            val_pos += stepen(i);
        }
    }

    if (val_pos >= -65535 && val_pos <= 65535) {
        int bits_count = 1;
        while (stepen(bits_count) <= val_pos) {
            bits_count++;
        }
        if (bits_count == len) {
            long long v = val_pos;
            int match = 1;
            for (int i = 0; i < bits_count; i++) {
                if ((v % 2) != digits[i]) {
                    match = 0;
                }
                v /= 2;
            }
            if (match) {
                printf("%lld\n", val_pos);
                return 0;
            }
        }
    }

    printf("ERROR\n");
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
