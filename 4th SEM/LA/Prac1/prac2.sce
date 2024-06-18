A=[1 2+%i 4; 3-4*%i 9 -2; 2 -5 1-%i]
disp(A);
printf("Display real part of matrix A:");
disp(real(A));
printf("Display imaginary part of matrix A:");
disp(imag(A));

printf("Display random matrix of order 3 with elements from 0 to 9:")
disp(rand(3,3)*10);

printf("Display random matrix of order 3 with integer elements from 0 to 9:")
disp(int(rand(3,3)*10));

B=[1 3 5; 2 4 1; 1 2 3]
printf("Display matrix B:")
disp(B);

printf("Display reduced row echelon form of B:");
disp(rref(B));

printf("Display multiplication of A & B: ");
disp(A*B);

printf("Display reciprocal of elements in B: ")
disp(1./B);

printf("Display square root of 25:");
disp(sqrt(25));

printf("Display the sine of pi/2");
disp(sin(%pi/2));

printf("Display the given value of x:");
x= 3^2;
disp(x);

printf("Display reciprocal of given value");
disp(1/x);
