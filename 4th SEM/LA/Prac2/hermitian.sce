A = [1 2+3*%i 3-4*%i; 2-3*%i 5 6+7*%i; 3+4*%i 6-7*%i 8];

if A == A' then
    disp("The input matrix is Hermitian.");
else
    disp("The input matrix is not Hermitian.");
end
