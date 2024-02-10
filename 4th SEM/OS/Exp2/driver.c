#include "lib_mylib.h"
#include <stdio.h>
int main() {
int choice;
int n1, n2;
int value;
int x, y;
do {
printf("\nMenu:\n");
printf("1. Add\n");
printf("2. Subtract\n");
printf("3. Multiply\n");
printf("4. Divide\n");
printf("5. Sine\n");
printf("6. Cosine\n");
printf("7. Tangent\n");
printf("8. Log base 10\n");
printf("9. Natural Log\n");
printf("10. Exponential\n");
printf("11. X to the power of Y\n");
printf("12. Factorial\n");
printf("0. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
printf("Enter two numbers: ");
scanf("%d %d", &n1, &n2);
printf("Result: %d\n", add(n1, n2));
break;
case 2:
printf("Enter two numbers: ");
scanf("%d %d", &n1, &n2);
printf("Result: %d\n", subtract(n1, n2));
break;
case 3:
printf("Enter two numbers: ");
scanf("%d %d", &n1, &n2);
printf("Result: %d\n", multiply(n1, n2));
break;
case 4:
printf("Enter two numbers: ");
scanf("%d %d", &n1, &n2);
printf("Result: %d\n", divide(n1, n2));
break;
case 5:
printf("Enter an angle in degrees: ");
scanf("%d", &value);
printf("Result: %lf\n", sine(value));
break;
case 6:
printf("Enter an angle in degrees: ");
scanf("%d", &value);
printf("Result: %lf\n", cosine(value));
break;
case 7:
printf("Enter an angle in degrees: ");
scanf("%d", &value);
printf("Result: %lf\n", tangent(value));
break;
case 8:
printf("Enter a value: ");
scanf("%d", &value);
printf("Result: %lf\n", log_base_10(value));
break;
case 9:
printf("Enter a value: ");
scanf("%d", &value);
printf("Result: %lf\n", natural_log(value));
break;
case 10:
printf("Enter a value: ");
scanf("%d", &value);
printf("Result: %lf\n", exponential(value));
break;
case 11:
printf("Enter base (x) and exponent (y): ");
scanf("%d %d", &x, &y);
printf("Result: %lf\n", x_power_y(x, y));
break;
case 12:
printf("Enter a number: ");
scanf("%d", &y);
printf("Result: %d\n", fact(y));
break;
case 0:
printf("Exiting program. Goodbye!\n");
break;
default:
printf("Invalid choice. Please try again.\n");
}
} while (choice != 0);
return 0;
}
