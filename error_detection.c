#include <stdio.h>


#include <stdlib.h>


#include <string.h>

 

void remove_hyphen(char *psrc, char c)


{


    char *pdes = psrc;


    while (*psrc)


    {


        if (*psrc != c)


        {


            *pdes++ = *psrc++;


        }


        else


        {


            *psrc++;


        }


    }


    *pdes = '\0';


}


int control_digit_cal(int array1[])


{


    int j, even_digit, sum_even = 0, sum2_even = 0, sum_odd = 0, num1, total_even, controldigit;


    for (j = 0; j < 9; j++)


    {


        if (j % 2 == 0)


        {

 

            even_digit = array1[j] * 2;


            if (even_digit > 9)


            {


                while (even_digit != 0)


                {


                    num1 = even_digit % 10;


                    sum_even = sum_even + num1;


                    even_digit = even_digit / 10;


                }


            }


            else


            {


                sum2_even = sum2_even + even_digit;


            }


            total_even = sum_even + sum2_even;


        }


        else


        {


            sum_odd = sum_odd + array1[j];


        }


    }


    int total = sum_odd + total_even;


    controldigit = (10 - (total % 10)) % 10;


    return controldigit;


}


int main(void)


{


    int count = 0, control_digit, array1[10], i, j, len, num = 0, controldigit;


    char personal_number[12], array2[12];


    printf("Enter ur personal number(YYMMDD-nnnC)....\n");


    gets(personal_number);

 

    remove_hyphen(personal_number, '-');

 

    strcpy(array2, personal_number);

 

    for (i = 0; i < strlen(array2); i++)


    {


        array1[i] = array2[i] - '0';


    }

 

    controldigit = control_digit_cal(array1);

 

    if (controldigit == array1[9])


    {


        printf("Valid Personal Number");


    }


    else


    {


        printf("Invalid Personal Number");


        exit(0);


    }


    return 0;


}