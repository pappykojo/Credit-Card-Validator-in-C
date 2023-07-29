#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool is_valid_credit_card(const char* card_number) {
    int len = strlen(card_number);
    int sum = 0;
    bool alternate = false;

    // Iterate over the card number digits from right to left
    for (int i = len - 1; i >= 0; i--) {
        int digit = card_number[i] - '0';

        // If it's an alternate digit, double its value
        if (alternate) {
            digit *= 2;

            // If the doubled value is greater than 9, subtract 9 from it
            if (digit > 9) {
                digit -= 9;
            }
        }

        sum += digit;
        alternate = !alternate;
    }

    // If the sum is divisible by 10, the card number is valid
    return (sum % 10 == 0);
}

int main() {
    char card_number[20];

    printf("Enter the credit card number: ");
    scanf("%s", card_number);

    if (is_valid_credit_card(card_number)) {
        printf("The credit card number is valid.\n");
    } else {
        printf("Invalid credit card number.\n");
    }

    return 0;
}
