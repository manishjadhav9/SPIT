clc
A = [3 -1 2 1 ; 2 -2 3 2 ; 1 -1 1 -1 ; 1 2 -1 3];
printf("The Matrix A is\n");
disp(A);
n = 4;

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

for i = n:-1:2
    for j = i-1:-1:1
        A(j,:) = A(j,:) - A(j,i)*A(i,:);
    end
end

printf("The final matrix in row-reduced echelon form is: \n");
disp(A);
