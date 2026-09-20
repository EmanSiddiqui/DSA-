//Eman Siddiqui CT-25072
#include <iostream>
#include <string>
using namespace std;

int main() {
    // Student names
    string students[] = {"Ali", "Hiba", "Asma", "Zain", "Faisal"};
    int numStudents = 5;

    // GPA data (using -1 for missing courses "---")
    // Columns: DSA, AI, DLD, P&S, F&A
    double gpas[5][5] = {
        {3.66, 3.33, 4.0, 3.0, 2.66},
        {3.33, 3.0, 3.66, 3.0, -1},
        {4.0, 3.66, 2.66, -1, -1},
        {2.66, 2.33, 4.0, -1, -1},
        {3.33, 3.66, 4.0, 3.0, 3.33}
    };

    int creditHour = 3;

    cout << "Student GPA Calculator" << endl;
    cout << "=====================" << endl << endl;

    for(int i = 0; i < numStudents; i++) {
        double sum = 0;
        int count = 0;

        
        for(int j = 0; j < 5; j++) {
            if(gpas[i][j] != -1) { 
                sum += gpas[i][j] * creditHour;
                count++;
            }
        }

        // GPA = Total (Grade * Credit) / Total Credits
        double gpa = sum / (count * creditHour);

        cout << students[i] << "'s GPA: "<< gpa << endl;
    }

    return 0;
}
