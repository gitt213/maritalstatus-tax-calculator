#include <iostream>
#include <string>
#include <limits> 

using namespace std;

// These will be used to calculate tax
double computeTax(double monthlySalary, string mStatus) {
    double taxAmount = 0.0;
    double taxRate = 0.0;

    // this will determine tax rate based on marital status and salary
    if (mStatus == "S") {
        if (monthlySalary > 100000) {
            taxRate = 0.30;  // 30% tax rate for above 100,000
        } else if (monthlySalary >= 50000 && monthlySalary <= 100000) {
            taxRate = 0.20;  // 20% tax rate for between 50,000 and 100,000
        } else {
            taxRate = 0.10;  // 10% tax rate for below 50,000
        }
    } else if (mStatus == "M") {
        if (monthlySalary > 100000) {
            taxRate = 0.25;  // 25% tax rate for above 100,000
        } else if (monthlySalary >= 50000 && monthlySalary <= 100000) {
            taxRate = 0.15;  // 15% tax rate for between 50,000 and 100,000
        } else {
            taxRate = 0.05;  // 5% tax rate for below 50,000
        }
    }

    taxAmount = monthlySalary * taxRate;
    cout << "Applicable tax rate: " << taxRate * 100 << "%" << endl;
    return taxAmount;
}

int main() {
    string employmentStatus;
    double salaryAmount;

    // Marital status input
    cout << "Enter marital status (S-single/M-married): ";
    cin >> employmentStatus;

    // Convert input to uppercase for case-insensitive comparison
    for (char &c : employmentStatus) {
        c = toupper(c);
    }

   // if inputed Invalid marital status
    if (employmentStatus != "S" && employmentStatus != "M") {
        cout << "Error: Invalid marital status. Use 'Single' or 'Married' only!." << endl;
        return 1;  // Exit program if marital status is invalid
    }

    // Salary input
    cout << "Enter monthly salary (non-negative): ";
    cin >> salaryAmount;

    // Validate salary input
    if (salaryAmount < 0) {
        cout << "Error: Salary must be a non-negative value only!." << endl;
        return 1;
    }

    // Compute and display tax
    double tax = computeTax(salaryAmount, employmentStatus);
    cout << "The tax amount is: ₱" << tax << endl;

    return 0;
}