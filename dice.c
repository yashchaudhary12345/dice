#include <stdio.h>
#include <math.h>

double calculateProbability(int numDice, int targetNumber) {
    if (numDice <= 0) {
        return 0.0;  // No dice, so probability is zero.
    }
    if (targetNumber < 1 || targetNumber > 6) {
        return 0.0;  // Invalid target number.
    }

    int totalOutcomes = pow(6, numDice);  // Total possible outcomes when rolling 'numDice' dice.
    int favorableOutcomes = 0;  // Number of outcomes where 'targetNumber' is rolled.

    // Recursive function to calculate the number of favorable outcomes.
    void calculateFavorableOutcomes(int currentDice, int currentSum) {
        if (currentDice == 0) {
            if (currentSum == targetNumber) {
                favorableOutcomes++;
            }
        } else {
            for (int i = 1; i <= 6; i++) {
                calculateFavorableOutcomes(currentDice - 1, currentSum + i);
            }
        }
    }

    calculateFavorableOutcomes(numDice, 0);

    return (double)favorableOutcomes / totalOutcomes;
}

int main() {
    int numDice, targetNumber;

    // Input the number of dice and the target number.
    printf("Enter the number of dice: ");
    scanf("%d", &numDice);
    printf("Enter the target number (1 to 6): ");
    scanf("%d", &targetNumber);

    if (numDice < 1) {
        printf("Number of dice should be at least 1.\n");
        return 1;
    }

    double probability = calculateProbability(numDice, targetNumber);

    // Display the probability.
    printf("The probability of getting a %d with %d dice is: %.6lf\n", targetNumber, numDice, probability);

    return 0;
}
