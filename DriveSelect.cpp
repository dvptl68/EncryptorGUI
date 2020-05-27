#include <iostream>
#include <windows.h>
#include <sys/stat.h>
#include <vector>
#include <string>
#include "DriveSelect.hpp"

using namespace std;
struct stat info;

//Constructor for Select class
DriveSelect::DriveSelect(void){
  //Fill vector with possible drive letters
  vector<string> alphabet = {"A", "B", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};
  //Iterate through possible drive letters
  for (int i = 0; i < (int)alphabet.size(); i++){
    struct stat buffer;
    //Set current path
    char current[4] ={alphabet[i].c_str()[0], ':', '\\'};
    //Check if drive path exists
    if (stat (current, &buffer) == 0){
      //Retrieve drive name and add to vector
      char VolumeName[MAX_PATH];
      GetVolumeInformationA((LPCSTR)current, (LPSTR)VolumeName, sizeof(VolumeName), NULL, NULL, NULL, NULL, 0);
      string vol(VolumeName);
      DriveSelect::paths.push_back(current + vol);
    }
  }
}

//Returns the drives that are found
vector<string> DriveSelect::getDrives(){
  return DriveSelect::paths;
}
