//
// Created by Duc An Chu on 5/31/20.
//

//#include <filesystem>
#include "FileManagement.h"

namespace fs = std::filesystem;


PathNode::PathNode() {

}

PathList::PathList() {
    c = nullptr;
    cnt = 0;
}

PathList::~PathList() {
    delete [] c;
}

void PathList::getDirectoryList(string path, bool (*checkPath)(string), string *hint, int n) {
    if (path.length() == 0 || path[path.length()-1] != '/')
        path.push_back('/');

    cnt = distance(fs::directory_iterator(path), fs::directory_iterator{});
    c = new PathNode [cnt];

    cnt = 0;
    for (auto &p : fs::directory_iterator(path)) {
        //cout << p.path() << " " << checkPath(p.path().u8string()) << " " <<  fs::is_directory(p) << endl;
        if (checkPath(p.path().u8string()) || fs::is_directory(p)) {
            c[cnt].path = p.path().u8string();
            c[cnt].weight = 0;

            for (int i = 0; i < n; i++)
                if (c[cnt].path.find(hint[i]) != string::npos)
                    c[cnt].weight++;

            cnt++;
        }
    }

    sort(c, c + cnt, &cmpPath);

    for (int i = 0; i<cnt; i++)
        c[i].path.erase(0, path.length());
}

bool cmpPath(const PathNode &a, const PathNode &b) {
    if (fs::is_directory(a.path) != fs::is_directory(b.path))
        return fs::is_directory(a.path) > fs::is_directory(b.path);

    if (a.weight != b.weight)
        return a.weight > b.weight;

    return a.path < b.path;
}

bool isClassListCSV(string filePath) {
    if (!fs::is_regular_file(filePath))
        return false;

    if (fs::path(filePath).extension() != ".csv")
        return false;

    ifstream fin;
    fin.open(filePath);

    if (!fin.is_open())
        return false;

    string s;
    getline(fin, s);

    if (s.find(ClassListHeader) == string::npos) {
        fin.close();
        return false;
    }

    while (fin.good()) {
        getline(fin, s);
        if (numComma(s) != numCommaClassList && s != "") {
            fin.close();
            return false;
        }
    }

    return true;
}

bool isCourseListCSV(string filePath) {
    if (!fs::is_regular_file(filePath))
        return false;

    if (fs::path(filePath).extension() != ".csv")
        return false;

    ifstream fin;
    fin.open(filePath);

    if (!fin.is_open())
        return false;

    string s;
    getline(fin, s);

    if (s.find(CourseListHeader) == string::npos) {
        fin.close();
        return false;
    }

    while (fin.good()) {
        getline(fin, s);
        if (numComma(s) != numCommaCourseList && s != "") {
            fin.close();
            return false;
        }
    }

    return true;
}

bool isLecturerListCSV(string filePath) {
    if (!fs::is_regular_file(filePath))
        return false;

    if (fs::path(filePath).extension() != ".csv")
        return false;

    ifstream fin;
    fin.open(filePath);

    if (!fin.is_open())
        return false;

    string s;
    getline(fin, s);

    if (s.find(LecturerListHeader) == string::npos) {
        fin.close();
        return false;
    }

    while (fin.good()) {
        getline(fin, s);
        if (numComma(s) != numCommaLecturerList && s != "") {
            fin.close();
            return false;
        }
    }

    return true;
}

bool isStudentListCSV(string filePath) {
    if (!fs::is_regular_file(filePath))
        return false;

    if (fs::path(filePath).extension() != ".csv")
        return false;

    ifstream fin;
    fin.open(filePath);

    if (!fin.is_open())
        return false;

    string s;
    getline(fin, s);

    if (s.find(StudentListHeader) == string::npos) {
        fin.close();
        return false;
    }

    while (fin.good()) {
        getline(fin, s);
        if (numComma(s) != numCommaStudentList && s != "") {
            fin.close();
            return false;
        }
    }

    return true;
}

bool isScoreBoardListCSV(string filePath) {
    if (!fs::is_regular_file(filePath))
        return false;

    if (fs::path(filePath).extension() != ".csv")
        return false;

    ifstream fin;
    fin.open(filePath);

    if (!fin.is_open())
        return false;

    string s;
    getline(fin, s, '\n');

    if (s.find(ScoreBoardListHeader) == string::npos) {
        fin.close();
        return false;
    }

    while (fin.good()) {
        getline(fin, s);
        //cout << s << endl;
        if (numComma(s) != numCommaScoreBoardList && s != "") {
            fin.close();
            return false;
        }
    }

    return true;
}

int numComma(string s) {
    int ans = 0;
    for (int i = 0; i<s.length(); i++)
        if (s[i] == ',') ans++;
    return ans;
}
