//#include "AcademicStaffCourse.h"
//#include "AcademicStaffClass.h"
#include "AcademicStaffScoreBoard.h"
#include "Lecturer.h"
#include "Student.h"
#include "AllRoles.h"

int main()
{
    string s = "     chu    dUc    aN    ";
    normalizeFullName(s);
    cout << s << " " << getFirstName(s) << endl;
    cout << getTitle(s, LECTURER, MALE) << endl;
    cout << getHashedPassword("tui rat dep trai hahaha");
    return 0;
}
