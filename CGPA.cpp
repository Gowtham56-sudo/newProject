#include <iostream>
#include <vector>
using namespace std;

// Function to convert letter grades to grade points
float gradeToPoint(char grade) {
    switch (grade) {
        case 'A': return 4.0;
        case 'B': return 3.0;
        case 'C': return 2.0;
        case 'D': return 1.0;
        case 'F': return 0.0;
        default: return -1.0; // Invalid grade
    }
}

int main() {
    int numCourses;
    cout << "Enter the number of courses: ";
    cin >> numCourses;

    vector<float> creditHours(numCourses);
    vector<char> grades(numCourses);
    float totalPoints = 0, totalCredits = 0;

    // Input for each course
    for (int i = 0; i < numCourses; i++) {
        cout << "Enter the credit hours for course " << i + 1 << ": ";
        cin >> creditHours[i];
        cout << "Enter the grade (A, B, C, D, F) for course " << i + 1 << ": ";
        cin >> grades[i];

        float gradePoint = gradeToPoint(grades[i]);
        if (gradePoint == -1.0) {
            cout << "Invalid grade entered! Please enter grades A, B, C, D, or F only." << endl;
            return 1;
        }

        totalPoints += gradePoint * creditHours[i];
        totalCredits += creditHours[i];
    }

    // Calculate CGPA
    float CGPA = totalPoints / totalCredits;
    cout << "Your CGPA is: " << CGPA << endl;

    return 0;
}
