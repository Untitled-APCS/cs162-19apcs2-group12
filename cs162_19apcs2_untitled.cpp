//#include "AcademicStaffCourse.h"
//#include "AcademicStaffClass.h"
#include "AcademicStaffScoreBoard.h"
#include "Lecturer.h"
#include "Student.h"
#include "AllRoles.h"

int main()
{
//    string s = "     chu    dUc    aN    ";
//    normalizeFullName(s);
//    cout << s << " " << getFirstName(s) << endl;
//    cout << getTitle(s, LECTURER, MALE) << endl;
//    cout << getHashedPassword("tui rat dep trai hahaha");

//    string s;
//    getline(cin, s);
//    cout << s << endl;
//    string s1 = "CM105";
//    string s2 = "cm101_student_2018_2019";
//    cout << DamerauLevenshteinDistance(s1, s2) << endl;
//    printf("%0.4f", suitability(s1, s2));
    string s1, s2;
    getline(cin, s1);
    //getline(cin, s2, (char) 27);
    cout << s1.length() << endl; bool ok = false;
    for (int i = 0; i<s1.length(); i++) {
        cout << s1[i] << endl;
        if (s1[i] == (char) 27) ok = true;
    }

    if (ok) cout << "This string contains esc character.\n";

    return 0;
}
