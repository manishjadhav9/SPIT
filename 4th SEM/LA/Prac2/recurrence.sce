clc
U=[4];
for n=1:19
    U(n+1)=4*U(n)+4;
end
disp(U)
printf("\n")
printf("the 20th term is: ")
disp(U(20))
