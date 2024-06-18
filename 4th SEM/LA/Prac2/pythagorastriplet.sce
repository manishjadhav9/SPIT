clc
for i=1:50
    for j=i+1:50
        c=(i*i)+(j*j)
        for k=i+2:50
            if c==(k*k)
                printf("\n")
                printf("Pythagorean Triplet is %d, %d, %d, \n", i,j,k);
            end
        end
    end
end
