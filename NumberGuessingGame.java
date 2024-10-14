import java.util.Random;
import java.util.Scanner;

public class NumberGuessingGame {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Random random = new Random();

        int numberToGuess = random.nextInt(100) + 1; // Random number between 1 and 100
        int numberOfTries = 0;
        int guessedNumber = 0;

        System.out.println("Welcome to the Number Guessing Game!");
        System.out.println("I have selected a number between 1 and 100. Try to guess it!");

        // Game loop
        while (guessedNumber != numberToGuess) {
            System.out.print("Enter your guess: ");
            guessedNumber = scanner.nextInt();
            numberOfTries++;

            if (guessedNumber < numberToGuess) {
                System.out.println("Too low! Try again.");
            } else if (guessedNumber > numberToGuess) {
                System.out.println("Too high! Try again.");
            } else {
                System.out.println("Congratulations! You've guessed the number " + numberToGuess + " in " + numberOfTries + " tries.");
            }
        }

        scanner.close();
    }
}
