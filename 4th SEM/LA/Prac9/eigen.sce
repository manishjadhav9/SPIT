//Eigen values and vectors:
clc
A=[2 2 1; 1 3 -1;1 2 2];
disp(A);
[c,d]=spec(A);
printf("The Eigen values of matrix A are:");
disp(d);
printf("The Eigen vectors of matrix A are:");
disp(c);

