#include <stdio.h>
#include <stdlib.h>

float* createMemoryFloat(int n){
    return (float*)malloc(n * sizeof(float));
}


int* createMemoryInt(int n){
    return (int*)malloc(n * sizeof(int));
}

// Function to display the bill
void displayBill(float *prices, int *quantities, int itemCount, float totalBill) {
    printf("\n----- Bill Details -----\n");
    for (int i = 0; i < itemCount; i++) {
        printf("Item %d: Price = ₹%.2f, Quantity = %d, Total = ₹%.2f\n",  i + 1, prices[i], quantities[i], prices[i] * quantities[i]);
    }
    printf("\nTotal Bill: ₹%.2f\n", totalBill);
}

// Function to calculate the total bill
float calculateTotalBill(float* prices, int* quantities, int itemCount) {
    float totalBill = 0.0;
    for (int i = 0; i < itemCount; i++) {
        totalBill += prices[i] * quantities[i];
    }
    return totalBill;
}

int collectItems(float** prices, int** quantities){
    int itemCount = 0; 
    char input[10];
    while (1) {
        printf("\nItem %d:\n", itemCount + 1);
        printf("Enter price (or 'q' to quit): ");
        scanf("%s", input);

        // Check if the user wants to quit
        if (input[0] == 'q' || input[0] == 'Q') {
            break;
        }

        // Convert input to float (price)
        float price;
        sscanf(input, "%f", &price);

        printf("Enter quantity: ");
        scanf("%d", &(*quantities)[itemCount]);

        // Store the price and increment item count
        (*prices)[itemCount] = price;
        itemCount++;
    }
    return itemCount;
}
int process() {
    float* prices = createMemoryFloat(100); // Array to store prices of items
    int* quantities = createMemoryInt(100); // Array to store quantities of items

    printf("Welcome to the Billing System!\n");
    printf("Enter item details (price and quantity). Enter 'q' to quit.\n");

    // Collecting the Data from the user
    int itemCount = collectItems(&prices, &quantities);


    // Calculate the total bill
    float totalBill = calculateTotalBill(prices, quantities, itemCount);

    // Display the bill
    displayBill(prices, quantities, itemCount, totalBill);

    printf("\nThank you for using the Billing System!\n");

    return 0;
}

int main(){
    process();
    return 0;
}