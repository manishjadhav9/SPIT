#include <bits/stdc++.h>

using namespace std;

// This function performs adding in accumulator
void add(int ac[], int x[], int qrn)
{
	int i, c = 0;
	
	for (i = 0; i < qrn; i++) {
		
		// updating accumulator with A = A + BR
		ac[i] = ac[i] + x[i] + c;
		
		if (ac[i] > 1) {
			ac[i] = ac[i] % 2;
			c = 1;
		}
		else
			c = 0;
	}
}

// function to find the number's complement
void complement(int a[], int n)
{
	int i;
	int x[8] = {0};
	x[0] = 1;
	
	for (i = 0; i < n; i++) {
		a[i] = (a[i] + 1) % 2;
	}
	add(a, x, n);
}

// function to perform right shift
void rightShift(int ac[], int qr[], int& qn, int qrn)
{
	int temp, i;
	temp = ac[0];
	qn = qr[0];
	
	cout << "\t\trightShift\t";
	
	for (i = 0; i < qrn - 1; i++) {
		ac[i] = ac[i + 1];
		qr[i] = qr[i + 1];
	}
	qr[qrn - 1] = temp;
}

// function to display operations
void display(int ac[], int qr[], int qrn)
{
	int i;
	
	// accumulator content
	for (i = qrn - 1; i >= 0; i--)
		cout << ac[i];
	cout << "\t";
	
	// multiplier content
	for (i = qrn - 1; i >= 0; i--)
		cout << qr[i];
}

// Function to implement booth's algo
void boothAlgorithm(int br[], int qr[], int mt[], int qrn, int sc)
{

	int qn = 0, ac[10] = { 0 };
	int temp = 0;
	cout << "qn\tq[n+1]\t\tBR\t\tAC\tQR\t\tsc\n";
	cout << "\t\t\tinitial\t\t";
	
	display(ac, qr, qrn);
	cout << "\t\t" << sc << "\n";
	
	while (sc != 0) {
		cout << qr[0] << "\t" << qn;
		
		// SECOND CONDITION
		if ((qn + qr[0]) == 1)
		{
			if (temp == 0) {
				
				// subtract BR from accumulator
				add(ac, mt, qrn);
				cout << "\t\tA = A - BR\t";
				
				for (int i = qrn - 1; i >= 0; i--)
					cout << ac[i];
				temp = 1;
			}
			
			// THIRD CONDITION
			else if (temp == 1)
			{
				// add BR to accumulator
				add(ac, br, qrn);
				cout << "\t\tA = A + BR\t";
				
				for (int i = qrn - 1; i >= 0; i--)
					cout << ac[i];
				temp = 0;
			}
			cout << "\n\t";
			rightShift(ac, qr, qn, qrn);
		}
		
		// FIRST CONDITION
		else if (qn - qr[0] == 0)
			rightShift(ac, qr, qn, qrn);
		
		display(ac, qr, qrn);
		
		cout << "\t";
		
		// decrement counter
		sc--;
		cout << "\t" << sc << "\n";
	}
}

// driver code
int main(int argc, char** arg)
{

	int mt[10], sc;
	int brn, qrn;
	
	// Number of multiplicand bit
	brn = 4;
	
	// multiplicand
	int br[] = { 0, 1, 1, 0 };
	
	// copy multiplier to temp array mt[]
	for (int i = brn - 1; i >= 0; i--)
		mt[i] = br[i]; 
		
	reverse(br, br + brn);

	complement(mt, brn);

	// No. of multiplier bit
	qrn = 4;
	
	// sequence counter
	sc = qrn;
	
	// multiplier
	int qr[] = { 1, 0, 1, 0 };
	reverse(qr, qr + qrn);

	boothAlgorithm(br, qr, mt, qrn, sc);

	cout << endl
		<< "Result = ";
		
	for (int i = qrn - 1; i >= 0; i--)
		cout << qr[i];
}




// The provided C++ code implements Booth's Algorithm for binary multiplication. Booth's Algorithm is an algorithm used to multiply two binary numbers efficiently, especially for signed binary numbers. Here's an explanation of the code and how Booth's Algorithm works:

// 1. **Add Function (add)**:
//    - This function performs addition in the accumulator. It takes three arguments: an accumulator (ac), an array (x), and the number of bits (qrn).
//    - It iterates through the bits of the accumulator and updates them based on the values of the corresponding bits in the array 'x'.
//    - If the sum is greater than 1, it takes the remainder after dividing by 2 and sets a carry 'c' to 1.
//    - This function is used to add or subtract binary numbers from the accumulator based on the conditions in Booth's Algorithm.

// 2. **Complement Function (complement)**:
//    - This function computes the two's complement of a binary number. It takes two arguments: an array 'a' and the number of bits 'n'.
//    - It first creates an array 'x' with a single '1' at the least significant bit.
//    - Then, it flips the bits in the 'a' array and adds '1' to it using the 'add' function. This results in the two's complement of the binary number.

// 3. **Right Shift Function (rightShift)**:
//    - This function performs a right shift operation on the accumulator and the multiplier. It takes four arguments: accumulator (ac), multiplier (qr), next multiplier bit (qn), and the number of bits (qrn).
//    - It shifts each element of the accumulator and the multiplier one position to the right and updates the least significant bit with the value of 'ac[0]'.
//    - This function simulates the right shift operation required in Booth's Algorithm.

// 4. **Display Function (display)**:
//    - This function is used to display the values of the accumulator and multiplier at each step of the algorithm.

// 5. **Booth Algorithm Function (boothAlgorithm)**:
//    - This function implements Booth's Algorithm for binary multiplication. It takes the following arguments:
//      - 'br': The binary representation of the multiplicand.
//      - 'qr': The binary representation of the multiplier.
//      - 'mt': The two's complement of the multiplicand.
//      - 'qrn': The number of bits in the multiplier.
//      - 'sc': The sequence counter, initially set to 'qrn'.
//    - The function initializes the accumulator 'ac' and other variables, displays the initial values, and then enters a loop.
//    - Inside the loop, it follows Booth's three conditions for multiplication and shifts the bits right. It updates the accumulator and the multiplier based on these conditions.
//    - The loop continues until the sequence counter 'sc' reaches zero, and at each step, it displays the values.
//    - The algorithm effectively multiplies the binary numbers and follows the rules for signed binary numbers (two's complement) when necessary.

// 6. **Main Function**:
//    - In the main function, it initializes the binary representations of the multiplicand ('br') and multiplier ('qr').
//    - It computes the two's complement of the multiplicand and reverses the order of bits for both 'br' and 'qr'.
//    - It then calls the 'boothAlgorithm' function to perform binary multiplication and displays the result.

// The result of the multiplication is displayed at the end of the code.

// This code demonstrates the Booth's Algorithm for binary multiplication and provides a clear view of how the algorithm works step by step.