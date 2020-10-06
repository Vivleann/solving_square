#include <stdio.h>
#include <math.h>
#include <assert.h>

/*!
     \brief Алгоритм сравнения двух чисел типа double
     \param a,b Два числа, которые хотим сравнить

     Данная функция реализует сравнение с определенной точностью.

     
*/
 
bool double_equals(double a, double b)
{
    double accuracy = 0.000001;
    return (fabs(a - b) < accuracy);
    }
 
/*!
     \brief Алгоритм вычисления дискриминанта
     \param a, b, c Коэффициенты квадратного уравнения

    
*/ 
int discrim(double a, double b, double c)
{
    double D =(b*b) - (4*a*c);
    return D;
    }

/*!
     \brief Алгоритм поиска корней
     \param a, b, с *x1,  *x2 3 Коэффициента квадратного уравнения и две переменные, куда будут записаны корни

     Данная функция реализует проверку входных параметров на небесконечность, неравенство a, b, c nan, x1, x2 NULL.
     Затем обрабатывает разные случаи квадратных уравнений 
     
*/    
    
int solving_sq(double a, double b, double c, double *x1, double *x2)
{ 
    assert(isfinite(a));
    assert(isfinite(b));
    assert(isfinite(c));
    
    assert(!isnan(a));
    assert(!isnan(b));
    assert(!isnan(c));
    
    assert (x1 != NULL);
    assert (x2 != NULL); 
    
    if (double_equals(a, 0) && double_equals(b, 0) && double_equals(c, 0))
    {
        printf("The equation has a lot of solutions\n");
        return -1;
    }
    
    if (double_equals(a, 0))
    {
        *x1 = -c/b;
        printf("The equation has one solution x= %d\n",*x1); 
        
        return 1;
    }
    
    double D = discrim(a, b, c);
    if (D < 0)
    {
        printf("The equation has no valid solutions\n");
        return 0;
    }
        
    
    *x1 = (-b - sqrt(D))/(2 * a);
    *x2 = (-b + sqrt(D))/(2 * a);
     
    return 2;
    
     
}

#define TEST(call, ref, correct_x3, correct_x4, test_num)                         		\
{                                                                       		\
    int res = call;                                                     		\
    if (res != ref)                                                     		\
    {                                                                   		\
        printf("Test %d failed on line %d: %d != %d \n", test_num, __LINE__, res, ref);     \
    }                                                                   		\ 
    else if (ref == 2)                                                  		\
    {                                                                   		\
        if (x3 != correct_x3 || x4 != correct_x4)                     			\
        {                                                                   	\
            printf("Test %d is Wrong on line %d: \n", test_num, __LINE__);      \                             	
        }                                                               		\   
        else{                                                           		\
            printf("Test %d is Correct\n", test_num);                           \
        }                                                               		\
    }                                                                   		\
    else                                                                		\
    {                                                                   		\
        printf("Test %d is Correct\n", test_num);                               \
    }                                                                   		\
}                                                                       		\

/*!
     \brief Тестовая проверка основных случаев решения квадратного уравнения
     

*/
void test_solving_sq()
{   
    double x3 = NAN, x4 = NAN;
    TEST(solving_sq(0, 0, 0, &x3, &x4), -1, 0, 0, 1);
    TEST(solving_sq(0, 2, -5, &x3, &x4), 1, 0, 0, 2);
    TEST(solving_sq(5, 2, 6, &x3, &x4), 0, 0, 0, 3);
    TEST(solving_sq(1, -5, 6, &x3, &x4), 2, 2, 3, 4);
    
    
}
 
 
 
int main()
{
    double a = NAN,  b = NAN, c = NAN;
    double x1 = NAN, x2 = NAN;
    
    printf("ax^2+bx+c=0 \n");
    printf("enter 'a': \n");
    scanf("%lf", &a);
    printf("enter  'b': \n");
    scanf("%lf", &b);
    printf("enter 'c': \n");
    scanf("%lf", &c);
    
    test_solving_sq();
    
    solving_sq(a, b, c, &x1, &x2);  
    printf("x1 = %lf, x2 = %lf ", x1, x2);
}