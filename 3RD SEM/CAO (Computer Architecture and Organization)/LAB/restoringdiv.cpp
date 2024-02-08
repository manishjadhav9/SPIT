#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Function to add two binary numbers
string add(string A, string M) {

	int carry = 0;
	string Sum;

	// Iterating through the number
	// A. Here, it is assumed that
	// the length of both the numbers
	// is same
	for (int i = A.length() - 1; i >= 0; i--) {
		//Adding the values at both
		// the indices along with the
		//carry
		int temp = A[i] - '0' + M[i] - '0' + carry;
		// If the binary number exceeds 1
		if (temp > 1) {
			Sum.push_back('0' + (temp % 2));
			carry = 1;
		}
		else {
			Sum.push_back('0' + temp);
			carry = 0;
		}
	}
	// Return the sum from Most Significant to Low Significant
	reverse(Sum.begin(), Sum.end());
	return Sum;
}

// Function of find the complement of the binary number
string complement(string m) {
	string M;

	// Iterating through the number
	for (int i = 0; i < m.length(); i++) {
		// Computing the Complement
		M.push_back('0' + ((m[i] - '0' + 1) % 2));
	}
	// Adding 1 to the computed value
	M = add(M, "0001");
	return M;
}

// Function to find the quotient and remainder
// Using Restoring Division
void restoringDivision(string Q, string M, string A) {
	int count = M.length();
	//Printing the initial values
	// of the accumulator, dividend
	// and divisor
	cout << "Initial Values: A:" << A << " Q:" << Q << " M:" << M << endl;
	// The number of steps is equal to the 
	// length of the binary number
	while (count > 0) {
		// Printing the values at every step
		cout << "\nstep:" << (M.length() - count + 1) << endl;
		A = A.substr(1) + Q[0];
		// Taking complement and adding it to A 
		// Indirectly we are subtracting(A-M)
		string comp_M = complement(M);
		A = add(A, comp_M);
		// Left shift,assigning LSB of Q to MSB of A.
		cout << "Left Shift and Subtract: ";
		cout << " A:" << A << endl;
		cout << "A:" << A << " Q:" << Q.substr(1) << "_";
		if (A[0] == '1') {
			// Unsuccessful and Quotient bit will be zero
			Q = Q.substr(1) + '0';
			cout << " -Unsuccessful" << endl;
			// Restoration is required for A
			A = add(A, M);
			cout << "A:" << A << " Q:" << Q << " -Restoration" << endl;
		}
		else {
			// Quotient bit will be 1
			Q = Q.substr(1) + '1';
			cout << " Successful" << endl;
			// No restoration
			cout << "A:" << A << " Q:" << Q << " -No Restoration" << endl;
		}
		count--;
	}
	// Final quotient and remainder of the 
	// given dividend and divisor
	cout << "\nQuotient(Q):" << Q << " Remainder(A):" << A << endl;
}

int main() {
	string dividend = "0101";
	string divisor = "0111";
	string accumulator
			= string(dividend.length(), '0');


	restoringDivision(dividend, divisor, accumulator);

	return 0;
}


// The provided code implements the restoring division algorithm, a method for dividing two binary numbers. It works by simulating the division process and providing a quotient and remainder as the output. Here's a step-by-step explanation of the code:

// 1. `add(string A, string M)`:
//    - This function takes two binary strings `A` and `M` as input.
//    - It iterates through the strings from right to left (least significant bit to most significant bit) and performs binary addition with a carry.
//    - If the sum of two bits plus the carry is greater than 1, it appends '0' or '1' to the result string `Sum` based on whether the sum is even or odd.
//    - The carry is updated accordingly.
//    - Finally, it reverses the result string and returns it as the sum of the two binary numbers.

// 2. `complement(string m)`:
//    - This function takes a binary string `m` as input.
//    - It computes the one's complement of the input binary number by flipping each bit (0 to 1, and 1 to 0) and stores it in the string `M`.
//    - It then adds 1 to the one's complement to obtain the two's complement, which is returned as the result.

// 3. `restoringDivision(string Q, string M, string A)`:
//    - This function implements the restoring division algorithm.
//    - It takes three binary strings as input: `Q` (quotient), `M` (divisor), and `A` (accumulator).
//    - It simulates the division process using a loop that iterates for the length of the binary numbers.
//    - In each iteration:
//      - The accumulator `A` is shifted left, and the least significant bit (LSB) of the quotient `Q` is assigned to the most significant bit (MSB) of `A`.
//      - The two's complement of the divisor `M` is computed using the `complement` function and added to `A`. This simulates subtraction (A - M).
//      - If the MSB of `A` is 1, it means that the subtraction was unsuccessful, and the quotient bit for this step is set to 0. Restoration is then performed by adding `M` back to `A`.
//      - If the MSB of `A` is 0, it means that the subtraction was successful, and the quotient bit for this step is set to 1. No restoration is needed.
//      - The values of `A` and `Q` are printed after each step.
//    - The loop continues until `count` reaches 0, which is equivalent to completing the division process.
//    - Finally, the function prints the quotient (Q) and remainder (A) as the final results.

// 4. `main()`:
//    - In the `main` function, two binary numbers (dividend and divisor) are defined as strings, and an accumulator (initially all zeros) is created to store intermediate results.
//    - The `restoringDivision` function is called with these inputs, and it simulates the division process.
//    - The final quotient and remainder are printed to the console.

// To understand the code's execution, consider the provided example of dividing "0101" by "0111." The code goes through each step of the restoring division algorithm and prints the values at each step, ultimately giving you the quotient and remainder.