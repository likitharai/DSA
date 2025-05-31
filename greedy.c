#include <stdio.h>

void fractionalKnapsack(int n, float weight[], float profit[], float capacity) {
    float ratio[20], temp;
    int i, j;
    float totalProfit = 0.0;

    // Calculate profit/weight ratio
    for (i = 0; i < n; i++) {
        ratio[i] = profit[i] / weight[i];
    }

    // Sort items by ratio in descending order
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (ratio[i] < ratio[j]) {
                // Swap ratio
                temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;
                // Swap weight
                temp = weight[i];
                weight[i] = weight[j];
                weight[j] = temp;
                // Swap profit
                temp = profit[i];
                profit[i] = profit[j];
                profit[j] = temp;
            }
        }
    }

    // Knapsack filling
    for (i = 0; i < n; i++) {
        if (weight[i] <= capacity) {
            capacity -= weight[i];
            totalProfit += profit[i];
        } else {
            totalProfit += ratio[i] * capacity;
            break;
        }
    }

    printf("Maximum profit = %.2f\n", totalProfit);
}

int main() {
    int n, i;
    float weight[20], profit[20], capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter weight and profit of each item:\n");
    for (i = 0; i < n; i++) {
        scanf("%f %f", &weight[i], &profit[i]);
    }

    printf("Enter capacity of knapsack: ");
    scanf("%f", &capacity);

    fractionalKnapsack(n, weight, profit, capacity);

    return 0;
}
