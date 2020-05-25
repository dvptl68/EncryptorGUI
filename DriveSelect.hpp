#ifndef DRIVESELECT_HPP
#define DRIVESELECT_HPP
#include <map>
#include <vector>
#include <string>

using namespace std;

class DriveSelect {
  private:
    vector<string> paths;
  public:
    DriveSelect();
    vector<string> getDrives();
};

#endif // DRIVESELECT_HPP
