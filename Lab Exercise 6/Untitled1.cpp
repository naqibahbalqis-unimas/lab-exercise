#include <stdio.h>
#include <windows.h>

// Define color constants
#define CYAN    11
#define YELLOW  14
#define PURPLE  13
#define WHITE   7
#define RED     12

// Declare global variables for expense limits
float academicLimit, groceriesLimit, rentalLimit, transportationLimit, stationeryLimit, entertainmentLimit;

// Declare an array of expense category names
const char *expenseCategories[] = {"Academic", "Groceries", "Rental", "Transportation", "Stationery", "Entertainment"};

// Function to set text color
void setTextColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

double setMonthlyIncome();
void enterDailyExpenses();
void expenseCategoriesLimit();

int main() {
    int choice;

    do {
        // Set the initial text color (white)
        setTextColor(WHITE);

        // Set text color for each option
        setTextColor(YELLOW);
        printf("+-----------------------------------------------------------+\n");
        printf("| %10sStudent Personal Finance Manager%15s |\n", " ", " ");
        printf("| %10s%47s |\n", " ", " ");
        printf("| [1] ");
        setTextColor(CYAN);
        printf("Set Monthly Income");
        setTextColor(YELLOW);
        printf("%10s", "[2] ");
        setTextColor(CYAN);
        printf("Categories Expenses Limits");
        setTextColor(YELLOW);
        printf("|\n");

        setTextColor(YELLOW);
        printf("| [3] ");
        setTextColor(CYAN);
        printf("Enter Daily Expenses");
        setTextColor(YELLOW);
        printf("%8s", "[4] ");
        setTextColor(PURPLE);
        printf("View Summary Report");
        setTextColor(YELLOW);
        printf("       |\n");

        setTextColor(YELLOW);
        printf("| [5] ");
        setTextColor(CYAN);
        printf("Exit the Program ");
        setTextColor(YELLOW);
        printf(" %35s |\n", " ");
        setTextColor(YELLOW);
        printf("+-----------------------------------------------------------+\n");
        setTextColor(WHITE);

        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                setMonthlyIncome();
                break;
            case 2:
                expenseCategoriesLimit();
                break;
            case 3:
                enterDailyExpenses();
                break;
        }
    } while (choice != 5);

    return 0;
}

double setMonthlyIncome() {
    double income;
    printf("Enter your monthly income: ");
    scanf("%lf", &income);
    return income;
}

void expenseCategoriesLimit() {
    printf("Enter expense limits for each category:\n");

    // Loop through each expense category
    for (int i = 0; i < sizeof(expenseCategories) / sizeof(expenseCategories[0]); ++i) {
        printf("%s: ", expenseCategories[i]);
        float limit;
        scanf("%f", &limit);

        // Assign the limit to the corresponding global variable
        switch (i) {
            case 0:
                academicLimit = limit;
                break;
            case 1:
                groceriesLimit = limit;
                break;
            case 2:
                rentalLimit = limit;
                break;
            case 3:
                transportationLimit = limit;
                break;
            case 4:
                stationeryLimit = limit;
                break;
            case 5:
                entertainmentLimit = limit;
                break;
            // Add more cases for additional categories
        }
    }
}

void enterDailyExpenses() {
    int categoryChoice;

    // Display expense category menu
    printf("Expense Categories:\n");
    for (int i = 0; i < sizeof(expenseCategories) / sizeof(expenseCategories[0]); ++i) {
        printf("[%d] %s\n", i + 1, expenseCategories[i]);
    }

    // Ask user to choose a category
    printf("Choose a category (1-%d): ", sizeof(expenseCategories) / sizeof(expenseCategories[0]));
    scanf("%d", &categoryChoice);

    if (categoryChoice < 1 || categoryChoice > sizeof(expenseCategories) / sizeof(expenseCategories[0])) {
        printf("Invalid choice.\n");
        return;
    }

    float expense;
    printf("Enter daily expense for %s: ", expenseCategories[categoryChoice - 1]);
    scanf("%f", &expense);

    // Check if daily expense exceeds the limit
    if (expense > 0 && expense > *(&academicLimit + categoryChoice - 1)) {
        setTextColor(RED);
        printf("Warning: You overspent in %s category!\n", expenseCategories[categoryChoice - 1]);
        setTextColor(WHITE);
    } else {
        printf("Daily expense recorded.\n");
    }
}
