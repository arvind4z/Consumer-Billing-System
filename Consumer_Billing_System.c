#include <stdio.h>

int main() {
    // Item names and their prices
    const char* items[] = {
        "Coffee", "Tea", "Maggie", "Pizza", "Burger",
        "Soft Drink", "Pasta", "Fries", "Vada Pav", "Momo", "Ice Cream"
    };
    const int prices[] = {45, 25, 50, 120, 70, 60, 75, 50, 25, 80, 110};
    int quantities[11] = {0}; // To store quantity of each item
    int choice;
    int total = 0;

    printf("\n");
    printf("Welcome to the BackGate Cafe!");
    printf("Available items:\n");
    printf("-----------------------------------------------------\n");
    printf("No.  Item           Price\n");
    printf("-----------------------------------------------------\n");
    for (int i = 0; i < 11; i++) {
        printf("%d.   %-12s  %d\n", i + 1, items[i], prices[i]);
    }
    printf("-----------------------------------------------------\n");

    // Take orders
    while (1) {
        printf("Enter the item number to order (1-11), or 0 to finish: ");
        scanf("%d", &choice);

        if (choice == 0) {
            break; // Exit the loop if the user is done ordering
        } else if (choice < 1 || choice > 11) {
            printf("Invalid choice, please try again.\n");
            continue;
        }

        printf("Enter the quantity of %s: ", items[choice - 1]);
        int quantity;
        scanf("%d", &quantity);

        if (quantity < 0) {
            printf("Quantity cannot be negative. Please try again.\n");
            continue;
        }

        quantities[choice - 1] += quantity; // Update quantity for the item
        total += prices[choice - 1] * quantity; // Update total        price
    }

    // Print the bill
     printf("-----------------------------------------------------\n");
    printf("\nWelcome to the BackGate Cafe!\n");
    printf("\nName of Customer:");
    printf("\nBill:\n");
    printf("-----------------------------------------------------\n");
    printf("Item           Quantity      Price\n");
    printf("-----------------------------------------------------\n");
    for (int i = 0; i < 11; i++) {
        if (quantities[i] > 0) {
            printf("%-12s  %d            %d\n", items[i], quantities[i], prices[i] * quantities[i]);
        }
    }
    printf("-----------------------------------------------------\n");
    printf("Total Amount: %d\n", total);
    printf("Thank you for visiting! Please come again.\n");

    return 0;
}