#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXIMUM(x,y) (((x) > (y)) ? (x) : (y)) 
#define MINIMUM(x,y) (((x) < (y)) ? (x) : (y))

const int MONTHS = 12;
const char* ALL_MONTHS[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

float* load_data(const char* file_name)
{
    float* month_sales_data = (float*)malloc(sizeof(float) * MONTHS);

    FILE *file_pointer = fopen(file_name, "r");
    if(file_pointer == NULL)
    {
        printf("No file found...\n");
        return NULL;
    }

    for(int i = 0; i < MONTHS; i++)
    {
        fscanf(file_pointer, "%f\n", &month_sales_data[i]);
        month_sales_data[i] = ((int)(month_sales_data[i] * 100.0)) / 100.0; // Format to two decimal places
    }

    fclose(file_pointer);

    return month_sales_data;
}

void data_print(float *sales)
{
    printf("Monthly sales report for 2023:\n");
    printf("%-15s %-15s\n", "Month", "Sales");
    for(int i = 0; i < MONTHS; ++i)
    {
        printf("%-15s $%.2f\n", ALL_MONTHS[i], sales[i]);
    }
}

float find_min(float* sales, int* month)
{
    float min_sale = sales[0];
    *month = 0;

    for(int i = 0; i < MONTHS; ++i)
    {
        if (sales[i] < min_sale)
        {
            min_sale = sales[i];
            *month = i;
        }
    }

    return min_sale;
}

float find_max(float* sales, int* month)
{
    float max_sale = sales[0];
    *month = 0;

    for(int i = 0; i < MONTHS; ++i)
    {
        if (sales[i] > max_sale)
        {
            max_sale = sales[i];
            *month = i;
        }
    }

    return max_sale;
}

float calculate_average(float* sales)
{
    float total = 0;

    for(int i = 0; i < MONTHS; ++i)
    {
        total += sales[i];
    }

    return total / MONTHS;
}

void min_max_avg(float* sales)
{
    int min_month, max_month;
    float min_sale = find_min(sales, &min_month);
    float max_sale = find_max(sales, &max_month);
    float avg = calculate_average(sales);

    printf("Sales summary:\n");
    printf("Minimum sales: $%.2f (%s)\n", min_sale, ALL_MONTHS[min_month]);
    printf("Maximum sales: $%.2f (%s)\n", max_sale, ALL_MONTHS[max_month]);
    printf("Average sales: %.2f\n", avg);
}

void six_month_avg(float* sales)
{
    printf("Six-Month Moving Average Report: \n");

    for(int i = 0; i < 7; ++i)
    {
        float total = 0;

        if (i + 6 <= MONTHS)
        {
            for(int j = i; j < i + 6; ++j)
            {
                total += sales[j];
            }

            float avg = total / 6;
            printf("%s - %s: $%.2f\n", ALL_MONTHS[i], ALL_MONTHS[i+5], avg);
        }
    }
}

void sales_highlow(float* sales)
{
    int temp;
    int indexes[MONTHS];
    for(int i = 0; i < MONTHS; ++i)
    {
        indexes[i] = i;
    }

    for(int i = 0; i < MONTHS; ++i)
    {
        for(int j = i+1; j < MONTHS; ++j)
        {
            if(sales[indexes[i]] < sales[indexes[j]])
            {
                temp = indexes[i];
                indexes[i] = indexes[j];
                indexes[j] = temp;
            }
        }
    }
    printf("Sales report (Highest to Lowest):\n");
    for(int i = 0; i < MONTHS; ++i)
    {
        printf("%-15s : $%.2f\n", ALL_MONTHS[indexes[i]], sales[indexes[i]]);
    }
}

int main()
{
    float* month_sales_data = load_data("input.txt");

    if(month_sales_data == NULL)
    {
        return 1;
    }

    data_print(month_sales_data);
    printf("\n");
    min_max_avg(month_sales_data);  
    printf("\n");
    six_month_avg(month_sales_data);
    printf("\n");
    sales_highlow(month_sales_data);
    printf("\n");
    free(month_sales_data);

    return 0;
}
