
/*this is a very simple program to calculate the GPA of a student, given the number of subjects,
the credits for each subject, and the letter grade for each subject. GPA is calculated out of 4.0*/
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class GPACalculator {
private:
    int totalCredits;
    float totalPoints;

public:
    // Constructor
    GPACalculator() {
        totalCredits = 0;
        totalPoints = 0.0;
    }

    // Convert letter grade to grade points
    // typing a lowercase or uppercase letter works the same
    float getGradePoint(string grade) {
        if (grade == "A" || grade == "a") return 4.0;
        else if (grade == "B" || grade == "b") return 3.0;
        else if (grade == "C" || grade == "c") return 2.0;
        else if (grade == "D" || grade == "d") return 1.0;
        else if (grade == "F" || grade == "f") return 0.0;
        else return -1.0; //  makes it invalid
    }

    // Add a course
    void addCourse(int credits, string grade) {
        float gradePoint = getGradePoint(grade);

        if (gradePoint == -1.0) { //invalid if user doesnt enter valid letter grade
            cout << "Invalid grade entered. Please use A, B, C, D, or F.\n";
            return;
        }

        totalCredits += credits;
        totalPoints += credits * gradePoint;
    }

    // Calculate GPA
    float calculateGPA() {
        if (totalCredits == 0) return 0.0;
        return totalPoints / totalCredits;
    }

    // Display GPA
    void displayGPA() {
        cout << fixed << setprecision(2);
        cout << "\nTotal Credits: " << totalCredits << endl;
        cout << "Total Grade Points: " << totalPoints << endl;
        cout << "Your GPA is: " << calculateGPA() << endl;
    }
};

int main() {
    GPACalculator gpaCalc;
    int numCourses;

    cout << "How many courses? ";
    cin >> numCourses;

    for (int i = 0; i < numCourses; i++) { // loop for course number
        int credits;
        string grade;

        cout << "\nCourse " << i + 1 << ":\n";
        cout << "Enter credit hours: ";
        cin >> credits;
        cout << "Enter grade (A, B, C, D, F): ";
        cin >> grade;

        gpaCalc.addCourse(credits, grade);
    }

    gpaCalc.displayGPA();

    return 0;
}

