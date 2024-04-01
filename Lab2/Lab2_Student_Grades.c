#include <stdio.h>
/*
* Program Name : Lab2
* Author's Name: Ayden Hession
* Class Day & Time : 1 / 21 / 2022 3 - 5 P.M.
* Description : Collect student data and compute weighted avg grade
*/
int main()
{
//initiallizing variables
float wA, wB;
float a, b, c, d; //A's Grades
float e, f, g, h; //B's Grades
//get student A's info
printf("With values 1-100, type student A's quiz, midterm, exam, and project
grades.\n");
scanf("%f %f %f %f", &a, &b, &c, &d);
wA = a * .15 + b * .2 + c * .3 + d * .35; //grades with weights
//get student B's Info
printf("With values 1-100, type student B's quiz, midterm, exam, and project
grades.\n");
scanf("%f %f %f %f", &e, &f, &g, &h);
wB = e * .15 + f * .2 + g * .3 + h * .35; //grades with weights
// printing out chart with grades (were told to use spaces to line up chart
data)
// The %(...).2f statement allow for two decimal grades
printf("%-11s %-7s %-10s %-7s %-11s %-12s\n", "Student", "Quiz", "Midterm",
"Exam", "Projects", "Weighted Avg");
printf("%-11s %-7.2f %-10.2f %-7.2f %-11.2f %-12.2f\n","A", a, b, c, d, wA);
printf("%-11s %-7.2f %-10.2f %-7.2f %-11.2f %-12.2f\n", "B", e, f, g, h, wB);
}
