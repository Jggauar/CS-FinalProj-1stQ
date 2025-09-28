#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
using namespace std;

/* 
   PART B: FUNCTION IMPLEMENTATION
   Rick Juanico
*/
// Calculates the average of 5 grades
float calculateAverage(float g1, float g2, float g3, float g4, float g5) {
    return (g1 + g2 + g3 + g4 + g5) / 5.0f;
}

// Finds the highest grade
float findHighest(float g1, float g2, float g3, float g4, float g5) {
    float h = g1;
    if (g2 > h) h = g2;
    if (g3 > h) h = g3;
    if (g4 > h) h = g4;
    if (g5 > h) h = g5;
    return h;
}

// Finds the lowest grade
float findLowest(float g1, float g2, float g3, float g4, float g5) {
    float l = g1;
    if (g2 < l) l = g2;
    if (g3 < l) l = g3;
    if (g4 < l) l = g4;
    if (g5 < l) l = g5;
    return l;
}
// Converts average to grade equivalent
float getGrade(float average) {
    if (average >= 96) return 1.0f;
    else if (average >= 94) return 1.25f;
    else if (average >= 92) return 1.5f;
    else if (average >= 90) return 1.75f;
    else if (average >= 88) return 2.0f;
    else if (average >= 86) return 2.25f;
    else if (average >= 84) return 2.5f;
    else if (average >= 82) return 2.75f;
    else if (average >= 80) return 3.0f;
    return 5.0f;
}
// Counts how many subjects are passing (≥ 60)
int countPassing(float g1, float g2, float g3, float g4, float g5) {
    int c = 0;
    if (g1 >= 60) c++;
    if (g2 >= 60) c++;
    if (g3 >= 60) c++;
    if (g4 >= 60) c++;
    if (g5 >= 60) c++;
    return c;
}

/*
   PART C: ADVANCED FEATURES
   Carl Tejano
*/

// Input Validation: Checks grade is between 0–100
float inputGrade(const string &subject) {
    float g;
    while (true) {
        cout << "Enter " << subject << " grade (0-100): ";
        if (!(cin >> g)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }
        if (g < 0.0f || g > 100.0f) {
            cout << "Invalid. Value must be between 0 and 100.\n";
            continue;
        }
        return g;
    }
}


// GPA Converter: Converts average to GWA (pareha ra sa grade equivalent)
float convertToGWA(float average) {
    return getGrade(average);
}


// DL Checker: Determines if student qualifies for Director’s List (≤1.5)
bool checkDirectorsList(float gwa) {
    return (gwa <= 1.5f);
}

/*
   PART A: CORE REQUIREMENTS
   Jasmine Alangilan(mostly) + help w/ the other members
*/

int main() {
    string studentName, studentID;
    int age, gradeLevel;

    cout << "========================================\n";
    cout << "        STUDENT GRADE CALCULATOR\n";
    cout << "========================================\n\n";

//               Student Profile Setup 
    cout << "=== STUDENT PROFILE SETUP ===\n";
    cout << "Enter student name: ";
    getline(cin, studentName);

    // Easter egg: Special message for "Lexxi Villa" (Jasmine gahimo ani)
    if (studentName == "Lexxi Villa") {
        cout << "Idk who lexxi is but ok\n";
    }

    cout << "Enter student ID: ";
    getline(cin, studentID);
    cout << "Enter student age: ";
    cin >> age;
    cout << "Enter grade level: ";
    cin >> gradeLevel;
    int birthYear = 2025 - age;

    cout << "\nProfile created successfully!\n\n";

//                Grade Entry 
    cout << "=== GRADE ENTRY ===\n";
    float mathGrade = inputGrade("Math");
    float scienceGrade = inputGrade("Science");
    float englishGrade = inputGrade("English");
    float historyGrade = inputGrade("History");
    float artGrade = inputGrade("Art");

    cout << "\nGrades recorded successfully!\n\n";

//     Final calculations
    float average = calculateAverage(mathGrade, scienceGrade, englishGrade, historyGrade, artGrade);
    float highest = findHighest(mathGrade, scienceGrade, englishGrade, historyGrade, artGrade);
    float lowest = findLowest(mathGrade, scienceGrade, englishGrade, historyGrade, artGrade);
    int passing = countPassing(mathGrade, scienceGrade, englishGrade, historyGrade, artGrade);
    float gwa = convertToGWA(average);
    bool directorsList = checkDirectorsList(gwa);

//    REPORT CARD OUTPUT
    cout << "========================================\n";
    cout << "           STUDENT REPORT CARD\n";
    cout << "========================================\n\n";

    cout << "STUDENT INFORMATION:\n";
    cout << "Name: " << studentName << "\n";
    cout << "ID: " << studentID << "\n";
    cout << "Age: " << age << " years old\n";
    cout << "Grade Level: " << gradeLevel << "th Grade\n";
    cout << "Birth Year: " << birthYear << "\n\n";

    cout << fixed << setprecision(1);
    cout << "SUBJECT GRADES:\n";
    cout << "Math: " << mathGrade << "%\n";
    cout << "Science: " << scienceGrade << "%\n";
    cout << "English: " << englishGrade << "%\n";
    cout << "History: " << historyGrade << "%\n";
    cout << "Art: " << artGrade << "%\n\n";

    cout << "GRADE STATISTICS:\n";
    cout << fixed << setprecision(2);
    cout << "Average Grade: " << average << "%\n";
    cout << "Grade Equivalent: " << getGrade(average) << "\n";
    cout << "Highest Grade: " << highest << "%\n";
    cout << "Lowest Grade: " << lowest << "%\n";
    cout << "Subjects Passing: " << passing << " out of 5\n\n";

    cout << "GWA: " << gwa << "\n";
    cout << "Director’s List Status: "
         << (directorsList ? "YES (Congratulations!)" : "NO (Better luck next time!)") << "\n";

    cout << "\n========================================\n";
    return 0;
}
