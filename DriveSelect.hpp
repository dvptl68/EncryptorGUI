#ifndef DRIVESELECT_HPP
#define DRIVESELECT_HPP
#include <map>
#include <string>

using namespace std;

class DriveSelect {
  private:
    char lpBuffer[30];
  public:
    DriveSelect();
    void parseBuffer(map<string, string>& drives);
    string pickDrive(map<string, string>& drives);
};

#endif // DRIVESELECT_HPP
