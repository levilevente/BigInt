#define _CRTDBG_MAP_ALLOC
#include <iostream>
#include "bigint.h"
#include <fstream>

using namespace std;


int main()
{
    ifstream fin("numbers.txt");

    if (!fin) {
        cout << "ERROR: Cannot open the file." << endl;
        return 1;
    }
    long long int num1, num2;
    fin >> num1 >> num2;
    int* v1;
    int* v2;
    int nn1;
    int nn2;
    int el1;
    int el2;
    fin >> nn1 >> el1;
    v1 = new int [nn1] {0};
    for (int i = 0; i < nn1; i++)
    {
        fin >> v1[i];
    }


    fin >> nn2 >> el2;
    v2 = new int [nn2] {0};
    for (int i = 0; i < nn2; i++)
    {
        fin >> v2[i];
    }



    fin.close();


    bigint n1(num1);
    bigint n2(num2);

    bigint v_n1(el1, nn1, v1);
    bigint v_n2(el2, nn2, v2);

    cout << "NUMBER 1: " << n1 << "\tNUMBER 2: " << n2 << endl;

    bigint sum = n1 + n2;
    cout << "Sum: " << sum << endl;


    bigint difference = n1 - n2;
    cout << "Difference: " << difference << endl;


    bigint product = n1 * n2;
    cout << "Product: " << product << endl;

    try {
        bigint division = n1 / n2;
        cout << "Division: " << division << endl;
    }
    catch (bigint::NullavalValoOsztas)
    {
        cout << "Division by zero... (caught in try block)\n";
    }

    bigint n1_cpy = n1;
    cout << "Copied value of number: " << n1_cpy << endl;

    bool is_equal = (n1 == n2);
    cout << "Equality check: " << is_equal << endl;

    bigint combined_operation = n1;
    combined_operation -= n2;
    cout << "Combined subtraction operator: " << combined_operation << endl;

    combined_operation += n2;
    cout << "Combined addition operator: " << combined_operation << endl;

    combined_operation *= n2;
    cout << "Combined multiplication operator: " << combined_operation << endl;

    try {
        combined_operation /= n2;
        cout << "Combined division operator: " << combined_operation << endl;
    }
    catch (bigint::NullavalValoOsztas)
    {
        cout << "Division by zero... (caught in try block)\n" << endl;
    }

    cout << "Less than: " << (n1 < n2) << endl;
    cout << "Greater than: " << (n1 > n2) << endl;
    cout << "Less than or equal to: " << (n1 <= n2) << endl;
    cout << "Greater than or equal to: " << (n1 >= n2) << endl;

    bigint prefix_increment = ++n1;
    cout << "Prefix increment: " << prefix_increment << endl;

    bigint postfix_increment = n1++;
    cout << "Postfix increment: " << postfix_increment << endl;

    bigint prefix_decrement = --n2;
    cout << "Prefix decrement: " << prefix_decrement << endl;

    bigint postfix_decrement = n2--;
    cout << "Postfix decrement: " << postfix_decrement << endl;

    n1.pow2();
    bigint square1 = n1;
    cout << "Square of the first number: " << square1 << endl;

    bigint square2 = n2.pow2();
    cout << "Square of the second number: " << square2 << endl;

    cout << "Minimum: " << min(n1, n2) << endl;

    cout << "Maximum: " << max(n1, n2) << endl;



    cout << "Correct type conversion: n1 + LLONG_MAX\t" << n1 + LLONG_MAX << endl;
    cout << "n1 > 123: " << (n1 > 123) << endl;
    cout << "n1 < 123: " << (n1 < 123) << endl;
    cout << "n1 != 123: " << (n1 != 123) << endl;
    cout << "n1 == 123: " << (n1 == 123) << endl;

    cout << endl << endl;
    /**********************************************************************/

    cout << "NUMBER 1: " << v_n1 << "\tNUMBER 2: " << v_n2 << endl;

    bigint v_sum = v_n1 + v_n2;
    cout << "Sum: " << v_sum << endl;


    bigint v_difference = v_n1 - v_n2;
    cout << "Difference: " << v_difference << endl;


    bigint v_product = v_n1 * v_n2;
    cout << "Product: " << v_product << endl;

    try {
        bigint v_division = v_n1 / v_n2;
        cout << "Division: " << v_division << endl;
    }
    catch (bigint::NullavalValoOsztas)
    {
        cout << "Division by zero... (caught in try block)\n";
    }

    bigint v_n1_cpy = v_n1;
    cout << "Copied value of number: " << v_n1_cpy << endl;

    bool v_is_equal = (v_n1 == v_n2);
    cout << "Equality check: " << v_is_equal << endl;

    bigint v_combined_operation = v_n1;
    v_combined_operation -= v_n2;
    cout << "Combined subtraction operator: " << v_combined_operation << endl;

    v_combined_operation += v_n2;
    cout << "Combined addition operator: " << v_combined_operation << endl;

    v_combined_operation *= v_n2;
    cout << "Combined multiplication operator: " << v_combined_operation << endl;

    try {
        v_combined_operation /= v_n2;
        cout << "Combined division operator: " << v_combined_operation << endl;
    }
    catch (bigint)
    {
        cout << "Division by zero... (caught in try block)\n" << endl;
    }

    cout << "Less than: " << (v_n1 < v_n2) << endl;
    cout << "Greater than: " << (v_n1 > v_n2) << endl;
    cout << "Less than or equal to: " << (v_n1 <= v_n2) << endl;
    cout << "Greater than or equal to: " << (v_n1 >= v_n2) << endl;

    bigint v_prefix_increment = ++v_n1;
    cout << "Prefix increment: " << v_prefix_increment << endl;

    bigint v_postfix_increment = v_n1++;
    cout << "Postfix increment: " << v_postfix_increment << endl;

    bigint v_prefix_decrement = --v_n2;
    cout << "Prefix decrement: " << v_prefix_decrement << endl;

    bigint v_postfix_decrement = v_n2--;
    cout << "Postfix decrement: " << v_postfix_decrement << endl;

    v_n1.pow2();
    bigint v_square1 = v_n1;
    cout << "Square of the first number: " << v_square1 << endl;

    bigint v_square2 = v_n2.pow2();
    cout << "Square of the second number: " << v_square2 << endl;

    cout << "Minimum: " << min(v_n1, v_n2) << endl;

    cout << "Maximum: " << max(v_n1, v_n2) << endl;



    cout << "Correct type conversion: n1 + LLONG_MAX\t" << v_n1 + LLONG_MAX << endl;
    cout << "n1 > 123: " << (v_n1 > 123) << endl;
    cout << "n1 < 123: " << (v_n1 < 123) << endl;
    cout << "n1 != 123: " << (v_n1 != 123) << endl;
    cout << "n1 == 123: " << (v_n1 == 123) << endl;


    _CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);
    _CrtDumpMemoryLeaks();
    return 0;
}
