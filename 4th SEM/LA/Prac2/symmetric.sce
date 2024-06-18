A = input("Enter the matrix: ");
// [1 1 -1; 1 2 0; -1 0 5];
// Check if the matrix is square
[m, n] = size(A);
if m ~= n
    disp('Matrix must be square');
    return;
end

isSymmetric = isequal(A, A');

isSkewSymmetric = isequal(A, -A');

if isSymmetric
    disp('Matrix type: symmetric');
elseif isSkewSymmetric
    disp('Matrix type: skew-symmetric');
else
    disp('Matrix is neither symmetric nor skew-symmetric');
end
