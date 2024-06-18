clc;

printf("Display identity matrix of order 3:");
disp(eye(3,3));

printf("Display matrix with all elements ONE of order 3:");
disp(ones(3,3));

printf("Display given matrix A:");
A=[1 2 3;4 5 6;7 8 0]
disp(A);

printf("Display random matrix of order 3:");
disp(rand(3,3));

printf("Display lower triangular matrix from A:");
disp(tril(A));

printf("Display upper triangular matrix from A:");
disp(triu(A));

printf("Display transpose of A:")
disp(A');

printf("Display size of matrix A:");
disp(size(A));

printf("Display A33 element of A:");
disp(A(3,3));

printf("Display 2nd column of A:");
disp(A(:,2));

printf("Display 3rd row of A:");
disp(A(3,:));

printf("Display sum of all elements of A:");
disp(sum(A));

printf("Display product of all elements of A:");
disp(prod(A));

printf("Display sum of elements of 2nd column in matrix A:");
disp(sum(A(:,2)));

printf("Display product of elements of 2nd column in matrix A:");
disp(prod(A(:,2)));

printf("Display sum of elements of 3rd row in matrix A:");
disp(sum(A(3,:)));

printf("Display product of elements of 3rd row in matrix A:");
disp(prod(A(3,:)));

printf("Display sum of all columns in order in matrix A:");
disp(sum(A,'r'));

printf("Display product of all columns in order in matrix A:");
disp(prod(A,'r'));

printf("Display sum of all rows in order in matrix A:");
disp(sum(A,'c'));

printf("Display product of all rows in order in matrix A:");
disp(prod(A,'c'));

printf("Display imaginary part of matrix A:");
disp(imag(A));

printf("Display real part of matrix A:");
disp(real(A));

printf("Display inverse of matrix A:");
disp(inv(A));

printf("Display determinant of matrix A:");
disp(det(A));

printf("Display trace of matrix A:");
disp(trace(A));

printf("Display rank of matrix A:");
disp(rank(A));

printf("Display diagonal matrix A:");
disp(eye(3,3).*A);

printf("Display only diagonal elements of matrix A:");
disp(diag(A));

printf("Display conjugate of matrix A:");
disp(conj(A));
