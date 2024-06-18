clc;
printf("Write a program to find values for x=1 to 5 for f(x)=x^2 + sqrt(x) using for and while loop.");
for x= 1:1:5
f(x)= x^2 + sqrt(x);
printf('\nThe value of f(x)= %f at x= %i',f(x),x )
end
//using while loop
printf("\n*******************************");
x=1;
while x<=5
f(x)= x^2 + sqrt(x);
printf('\nThe value of f(x)= %g at x= %i',f(x),x )
x=x+1;
end
