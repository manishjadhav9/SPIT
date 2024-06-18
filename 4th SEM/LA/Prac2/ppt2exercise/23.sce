clc;
printf("Enter a month(number) from a user and check whether its a first, second, third or fourth quarter.");
month = input("Enter a month: ")
if month >=1 & month <=3
then
printf("first quarter");
elseif month >= 4 & month <= 6
then
printf("second quarter");
elseif month >= 7 & month <=9
then
printf("third quarter");
elseif month >= 10 & month <=12
then
printf("fourth quarter");
else
printf("Invalid month");
end
