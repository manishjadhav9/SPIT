A = [1 3 2;2 7 7; 2 5 2]
disp(A);
B = [2;-1;7]
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

for i=n:-1:2
    for j=1:n-1
        C(j,:)=C(j,:)-C(j,i)*C(i,:);
    end
end

disp("X=");
disp(C(1,4));
disp("y=");
disp(C(2,4));
disp("z=");
disp(C(3,4));
