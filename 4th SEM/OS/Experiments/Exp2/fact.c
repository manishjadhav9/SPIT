# include <stdio.h>
int fact(int y){
if (y == 0)
return 1;
return y * fact(y - 1);
}
