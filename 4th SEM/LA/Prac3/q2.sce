clc
A = [1 2 -1 ; 3 -1 1 ; 2 -2 3];
printf("The Matrix A is\n");
disp(A);
n = 3; 

for i = 1:n
    if A(i,i) == 0
        A(i,:) = A(i,:);
    else
        A(i,:) = A(i,:) / A(i,i);
        disp(A);
        for j = 1:n-1
            if i+j <= n
                A(i+j,:) = A(i+j,:) - A(i+j,i)*A(i,:);
            end
        end
    end
end
if A(1,2) == A(2,2)
    A(1,:) = A(1,:) - A(2,:);
end

printf("The final matrix is: ")
disp(A);
