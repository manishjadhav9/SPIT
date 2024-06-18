C=rand(4,4);
printf("The random generated matrix C is: ");
disp(C);

sum_first_column = sum(C(:,1));
printf("Sum of first column elements: ");
disp(sum_first_column);

product_second_row = prod(C(2,:));
printf("Product of second row elements: ");
disp(product_second_row);

sum_matrix = sum(C);
printf("Sum of all elements: ");
disp(sum_matrix);

determinant = det(C);
printf("Determinant of Matrix A: ");
disp(determinant);

trace_matrix = trace(C);
printf("Trace of Matrix A: ");
disp(trace_matrix);
