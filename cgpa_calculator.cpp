#include<iostream>
#include<iomanip>
using namespace std;

int main()
{
    int subject_num;
    float grade_point, credit_hours;
    float totalcredit_hours = 0.0, totalgrade_point = 0.0;

    cout << "Enter number of subjects" << endl;
    cin >> subject_num;

    for (int i = 1; i <= subject_num; i++)
    {
        cout << "\nSUBJECT " << i << endl;
        cout << "Enter the credit_hours: ";
        cin >> credit_hours;

        if (credit_hours == 0)
        {
            cout << "Error: credit_hours can't be zero. Skipping this subject." << endl;
            continue; // skip this subject
        }

        cout << "Enter grade_point: ";
        cin >> grade_point;

        totalcredit_hours += credit_hours;
        totalgrade_point += credit_hours * grade_point;
    }

    if (totalcredit_hours == 0)
    {
        cout << "\nError: Total credit hours is zero. CGPA cannot be calculated." << endl;
    }
    else
    {
        float cgpa = totalgrade_point / totalcredit_hours;
        cout << fixed << setprecision(2);
        cout << "\nYour CGPA is: " << cgpa << endl;
    }

    return 0;
}

