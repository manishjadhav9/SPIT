A =[0 0 0 0 ; 0 1 0 0 ; 0 0 2 0 ; 0 3 4 5];
n = 4
disp(A)
 for i=1:n
    printf("for row")
    disp(i)
    if A(i,i)==0
        A(i,:)=A(i,:);

    else
        for j = 1:n
            if(j == i)
                A(i,:) = A(i,:)/A(i,i)
                disp(A,"making pivot zero")
                continue
            else
                A(j,:)=A(j,:)-(A(j,i)/A(i,i))*A(i,:)
                printf("for iteration")
                disp(j)
                disp(A)
            end
        end
    end
end

printf("Final result:")
disp(A)