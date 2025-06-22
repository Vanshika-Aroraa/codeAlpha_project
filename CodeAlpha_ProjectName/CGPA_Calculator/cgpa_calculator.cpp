#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct Course {
    string name;
    float grade;
    int credit;
};

float calculateCGPA(vector<Course> &courses) {
    float totalPoints = 0;
    int totalCredits = 0;

    for (int i = 0; i < courses.size(); i++) {
        totalPoints += courses[i].grade * courses[i].credit;
        totalCredits += courses[i].credit;
    }

    if (totalCredits == 0)
        return 0;

    return totalPoints / totalCredits;
}

int main() {
    int numCourses;
    vector<Course> courseList;

    cout << "How many courses? ";
    cin >> numCourses;

    for (int i = 0; i < numCourses; i++) {
        Course c;
        cout << "\nEnter name of course " << i + 1 << ": ";
        cin >> c.name;
        cout << "Enter grade (out of 10): ";
        cin >> c.grade;
        cout << "Enter credit hours: ";
        cin >> c.credit;

        courseList.push_back(c);
    }

    float cgpa = calculateCGPA(courseList);

    
    ofstream file("my_cgpa.txt");
    file << "CGPA Report\n";
    file << "-----------\n";
    for (int i = 0; i < courseList.size(); i++) {
        file << courseList[i].name << " | Grade: " << courseList[i].grade << " | Credit: " << courseList[i].credit << "\n";
    }
    file << "\nFinal CGPA: " << cgpa << "\n";
    file.close();

    cout << "\n Final CGPA: " << cgpa << "\n";
    cout << "Report saved in 'my_cgpa.txt'\n";

    return 0;
}
