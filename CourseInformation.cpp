#include <map>
#include <iostream>

using namespace std;

int main(){
    string courseNumber;

    map<string, string> courseRoom = {{"CS101","3004"}, {"CS102","4501"},{"CS103","6755"},{"NT110","1244"},{"CM241","1411"}};
    
    map<string, string> courseInstructor = {{"CS101","Haynes"}, {"CS102","Alvarado"},{"CS103","Rich"},{"NT110","Burke"},{"CM241","Lee"}};

    map<string, string> courseTime = {{"CS101","8:00 AM"}, {"CS102","9:00 AM"},{"CS103","10:00 AM"},{"NT110","11:00 AM"},{"CM241","1:00 PM"}};

    cout << "Enter a course number: ";
    cin >> courseNumber;

    if (courseRoom.find(courseNumber) == courseRoom.end()) {
        cout << "Course not found." << endl;
        return 1;
    }
    cout << "Course: " << courseNumber << endl;
    cout << "Room: " << courseRoom[courseNumber] << endl;
    cout << "Instructor: " << courseInstructor[courseNumber] << endl;
    cout << "Time: " << courseTime[courseNumber] << endl;
    return 0;
}