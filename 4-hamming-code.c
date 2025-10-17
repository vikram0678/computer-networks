#include <stdio.h>
#include <math.h>

// Calculate number of parity bits
int getParityBits(int m) {
    int r = 0;
    while ((1 << r) < m + r + 1) r++;
    return r;
}

// Generate Hamming code
void generateHamming(int data[], int m) {
    int r = getParityBits(m);
    int n = m + r;
    int hamming[20]; // enough size

    // Place data and parity bits
    for (int i = 1, j = 1; i <= n; i++) {
        if ((i & (i - 1)) == 0) hamming[i] = 0; // parity position
        else hamming[i] = data[j++];
    }

    // Calculate parity bits
    for (int i = 1; i <= n; i <<= 1) {
        int parity = 0;
        for (int j = 1; j <= n; j++)
            if (j & i) parity ^= hamming[j];
        hamming[i] = parity;
    }

    // Print Hamming code
    printf("Hamming code: ");
    for (int i = 1; i <= n; i++) printf("%d", hamming[i]);
    printf("\n");
}

int main() {
    int m;
    printf("Number of data bits: ");
    scanf("%d", &m);

    int data[20];
    printf("Enter data bits: ");
    for (int i = 1; i <= m; i++) scanf("%d", &data[i]);

    generateHamming(data, m);
    return 0;
}



