#include <stdio.h>
#include <windows.h>

int main() {
    int choice, categoryChoice;
    // Declare global variables for expense limits
    double academicLimit, groceriesLimit, rentalLimit, transportationLimit, stationeryLimit, entertainmentLimit;
    double academicExpense = 0.0, groceriesExpense = 0.0, rentalExpense = 0.0,
            transportationExpense = 0.0, stationeryExpense = 0.0, entertainmentExpense = 0.0;
    double totalLimit = 0.0;
    double totalExpenses = 0.0;
    double totalSavings = 0.0;
    double income = 0.0;
    double remainingAmount = 0.0;
    do {

        // Display main menu
        printf("+-----------------------------------------------------------+\n");
        printf("| %10sStudent Personal Finance Manager%15s |\n", " ", " ");
        printf("| %10s%47s |\n", " ", " ");
        printf("| [1] Set Monthly Income     [2] Categories Expenses Limits |\n");
        printf("| [3] Enter Daily Expenses   [4] View Summary Report        |\n");
        printf("| [5] Exit the Program                                      |\n");
        printf("+-----------------------------------------------------------+\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter your monthly income: ");
                scanf("%lf", &income);
                break;
            case 2:
                printf("Enter expense limits for each category:\n");

                printf("Academic: ");
                scanf("%lf", &academicLimit);
                if (academicExpense > income) {
                    printf("Warning: You Limit is over your income!\n");
                    academicExpense = 0.0;
                } else {
                    printf("Daily Limit recorded.\n");
                }



                printf("Groceries: ");
                scanf("%lf", &groceriesLimit);


                printf("Rental: ");
                scanf("%lf", &rentalLimit);

                printf("Transportation: ");
                scanf("%lf", &transportationLimit);

                printf("Stationery: ");
                scanf("%lf", &stationeryLimit);

                printf("Entertainment: ");
                scanf("%lf", &entertainmentLimit);
                break;
            case 3:
                printf("+--------------------------------------------------------+\n");
                printf("| %16sCategories%29s |\n", " ", " ");
                printf("| [1] Academic                    [2] Groceries           |\n");
                printf("| [3] Rental                      [4] Stationery          |\n");
                printf("| [5] Entertainment               [6] Transportation      |\n");
                printf("| [0] Exit the Program                                    |\n");
                printf("+---------------------------------------------------------+\n");

                do {
                    // Ask user to choose a category
                    printf("Choose a category (1-6, 0 to exit): ");
                    scanf("%d", &categoryChoice);

                    if (categoryChoice < 0 || categoryChoice > 6) {
                        printf("Invalid choice.\n");
                    } else if (categoryChoice != 0) {
                        float expense;
                        printf("Enter daily expense for ");
                        switch (categoryChoice) {
                            case 1:
                                printf("Academic: ");
                                scanf("%lf", &academicExpense);
                                if (academicExpense > academicLimit) {
                                    printf("Warning: You overspent in Academic category!\n");
                                } else {
                                    printf("Daily expense recorded.\n");
                                }
                                break;
                            case 2:
                                printf("Groceries: ");
                                scanf("%lf", &groceriesExpense);
                                if (groceriesExpense > groceriesLimit) {
                                    printf("Warning: You overspent in Groceries category!\n");
                                } else {
                                    printf("Daily expense recorded.\n");
                                }
                                break;
                            case 3:
                                printf("Rental: ");
                                scanf("%lf", &rentalExpense);
                                if (rentalExpense > rentalLimit) {
                                    printf("Warning: You overspent in Rental category!\n");
                                } else {
                                    printf("Daily expense recorded.\n");
                                }
                                break;
                            case 4:
                                printf("Stationery: ");
                                scanf("%lf", &stationeryExpense);
                                if (stationeryExpense > stationeryLimit) {
                                    printf("Warning: You overspent in Stationery category!\n");
                                } else {
                                    printf("Daily expense recorded.\n");
                                }
                                break;
                            case 5:
                                printf("Entertainment: ");
                                scanf("%lf", &entertainmentExpense);
                                if (entertainmentExpense > entertainmentLimit) {
                                    printf("Warning: You overspent in Entertainment category!\n");
                                } else {
                                    printf("Daily expense recorded.\n");
                                }
                                break;
                            case 6:
                                printf("Transportation: ");
                                scanf("%lf", &transportationExpense);
                                if (transportationExpense > transportationLimit) {
                                    printf("Warning: You overspent in Transportation category!\n");
                                } else {
                                    printf("Daily expense recorded.\n");
                                }
                                break;
                        }
                    }
                } while (categoryChoice != 0);
                break;
            case 4:
                totalLimit =
                        academicLimit + groceriesLimit + rentalLimit + transportationLimit + stationeryLimit +
                        entertainmentLimit;
                totalExpenses =
                        academicExpense + groceriesExpense + rentalExpense + transportationExpense + stationeryExpense +
                        entertainmentExpense;
                totalSavings = totalLimit - totalExpenses;
                remainingAmount = income - totalExpenses;
                printf("Summary Report\n");
                printf("+------------------+---------+----------+\n");
                printf("| %-16s | %7s | %8s |\n", "Category", "Limit", "Expenses");
                printf("+------------------+---------+----------+\n");
                printf("| %-16s | %7.2f | %8.2f |\n", "Academic", academicLimit, academicExpense);
                printf("| %-16s | %7.2f | %8.2f |\n", "Groceries", groceriesLimit, groceriesExpense);
                printf("| %-16s | %7.2f | %8.2f |\n", "Rental", rentalLimit, rentalExpense);
                printf("| %-16s | %7.2f | %8.2f |\n", "Transportation", transportationLimit, transportationExpense);
                printf("| %-16s | %7.2f | %8.2f |\n", "Stationery", stationeryLimit, stationeryExpense);
                printf("| %-16s | %7.2f | %8.2f |\n", "Entertainment", entertainmentLimit, entertainmentExpense);
                printf("+------------------+---------+----------+\n");
                printf("| %-16s | %18.2f |\n", "Total Savings", remainingAmount);
                printf("| %-16s | %18.2f |\n", "Total Expenses", totalExpenses);
                printf("| %-16s | %18.2f |\n", "Total Savings", totalSavings);
                printf("+------------------+---------+----------+\n");

                break;

            default:
                printf("Invalid Choice, Please Try Again\n\n");
        }

    } while (choice != 5);

    return 0;
}
