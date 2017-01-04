// Author: Xiaoyun Wang

#ifndef DIRECTORY_H
  #define DIRECTORY_H

#include "permissions.h"

class Directory
{
private:
    char*        name;
    int          mod_time;
    Directory** sub_dirs;
    Directory*  parent_dir;
    int          num_sub_dirs;
    Permissions   permissions;

public:
    Directory();
    Directory(const char* name, Directory* parent, short umask, int time);
    ~Directory();
    void        showPath();
    void        ls             (int argCount, const char* arguments[]);
    void        mkdir          (int argCount, const char* arguments[], short umask, int time);
    Directory* cd             (int argCount, const char* arguments[]);
};// directory class

#endif // DIRECTORY_H

