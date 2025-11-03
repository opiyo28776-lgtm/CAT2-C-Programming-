/*
Name Prince Opiyo
Reg no PA106/G/28776/25
Description calculation for gross pay taxes and net pay
*/

#include <stdio.h>

#define STANDARD_HOURS 40.0
#define OVERTIME_RATE 1.5
#define TAX_RATE_1 0.15
#define TAX_RATE_2 0.20
#define TAX_THRESHOLD 600.0

int main() {
    double hours_worked, hourly_wage, gross_pay, taxes, net_pay;

    // Get user input
    printf("Enter hours worked in a week: ");
    scanf("%lf", &hours_worked);
    printf("Enter hourly wage: ");
    scanf("%lf", &hourly_wage);

    // Calculate gross pay
    if (hours_worked > STANDARD_HOURS) {
        double regular_pay = STANDARD_HOURS * hourly_wage;
        double overtime_hours = hours_worked - STANDARD_HOURS;
        double overtime_pay = overtime_hours * hourly_wage * OVERTIME_RATE;
        gross_pay = regular_pay + overtime_pay;
    } else {
        gross_pay = hours_worked * hourly_wage;
    }

    // Calculate taxes
    if (gross_pay > TAX_THRESHOLD) {
        taxes = (TAX_THRESHOLD * TAX_RATE_1) + ((gross_pay - TAX_THRESHOLD) * TAX_RATE_2);
    } else {
        taxes = gross_pay * TAX_RATE_1;
    }

    // Calculate net pay
    net_pay = gross_pay - taxes;

    // Print the results
    printf("\n--- Payroll Summary ---\n");
    printf("Gross Pay: $%.2f\n", gross_pay);
    printf("Taxes:     $%.2f\n", taxes);
    printf("Net Pay:   $%.2f\n", net_pay);

    return 0;
}