#include <stdio.h>
#include <string.h>
int isPalindrome(char* str);
int main()
{
char string1[] = "racecar"; //is p
char string2[] = "racecTr"; //isn't p
char string3[] = "abc121cba"; //is p
char string4[] = "afdfsfea"; //isn't p
int test1, test2, test3, test4;
//calling the function
test1 = isPalindrome(&string1);
test2 = isPalindrome(&string2);
test3 = isPalindrome(&string3);
test4 = isPalindrome(&string4);
printf("%d\n%d\n%d\n%d", test1, test2, test3, test4);
return 0;
}
int isPalindrome(char* str)
{
int len = strlen(str);
for (int i = 0; i < len/2; i++) //if it is an odd length then the middle num
wont be checked cause doesn't matter, then even will check both middle terms if
equal
{
if (str[i] != str[len - i - 1]) //chcecks if the left side isn't equal
to right side, if this is the case isn't a palindrome
{
return 0;
}
}
return 1; //if for loop runs through without the if statement catching
anything then it was a palindrome, so it returns 1
}
