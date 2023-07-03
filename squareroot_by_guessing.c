#include <stdio.h>

double squareRoot(double n, double guess, double epsilon)
{
    double nextGuess = 0.5 * (guess + (n / guess));
    double diff = nextGuess - guess;

    if (diff < 0)
    {
        diff = -diff;
    }

    if (diff <= epsilon)
    {   
        printf("last guess: %f", nextGuess);
        return nextGuess;
    }
    else
    {
        printf("squareRoot(n: %f, nextGuess: %f, epsilon: %f)\n", n, nextGuess, epsilon);
        return squareRoot(n, nextGuess, epsilon);
    }
}

int main()
{
    double number, epsilon;
    printf("Enter a positive number: ");
    scanf("%lf", &number);

    printf("Enter the desired precision (epsilon): ");
    scanf("%lf", &epsilon);

    double result = squareRoot(number, 1.0, epsilon);
    printf("Square root of %.2lf is approximately %.6lf\n", number, result);

    return 0;
}