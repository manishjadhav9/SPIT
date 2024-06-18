A = [1 1 1;1 2 3;1 3 2]
disp(A);
B = [3;0;3]
disp(B);
C = [A,B]
disp(C);
n = 3;
for i=1:n
    C(i,:) = C(i,:)/C(i,i);
    disp(C)
    for j=1:n-1
        if i+j<n+1
            C(i+j,:)= C(i+j,:)-C(i+j,i)*C(i,:)
        end
    end
    disp(C)
end
z=C(3,4);
y=C(2,4)-C(2,3)*z;
x=C(1,4)-C(1,3)*z-C(1,2)*y;
printf("x=");
disp(x);
printf("y=");
disp(y);
printf("z=");
disp(z);

