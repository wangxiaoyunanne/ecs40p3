// Author: Xiaoyun Wang
#ifndef PERMISSION_H
#define PERMISSION_H

class Permissions
{
public:
    short oct_perm;
    Permissions();
    ~Permissions();

    void get_str(char *prem_str);
}; // permissions

#endif // PERMISSION_H
