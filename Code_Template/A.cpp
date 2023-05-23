#include<stdio.h>

int main()
{
    char name[20];
    scanf("%s", name);



    int rollno;

    scanf("%d", &rollno);



    int marks[4]; //marks[0], marks[1]
    int total_marks = 0;
    for (int i = 0; i < 4; i++)
    {
        ///input
        scanf("%d", &marks[i]);
        total_marks = total_marks + marks[i];
    }
    printf("name : %s\n", name);
    printf("rollno : %d\n", rollno);

    double percentage = (total_marks / 400.0) * 100;
    /// 200 / 400 = 0.5 -> 0   5/2 = 2.5
    char ch = '%';
    printf("percentage : %0.2f%c\n",percentage, ch);

    //200 / 400 = 0.5 * 100% = 50%


    return 0;
}


/*#include<stdio.h>

int main()
{
    int h = 10, w = 12, d = 8;

    printf("Enter height width depth of the cube : ");
    scanf("%d %d %d", &h, &w, &d);

    int volume = h * w * d;

    printf("Volume : %d", volume);


    return 0;
}*/
