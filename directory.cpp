// Author: Xiaoyun Wang
#include <iostream>
#include <cstring>

#include "directory.h"

using namespace std;

const int MAX_SUB_DIRS=3;


Directory::Directory(const char* name, Directory* parent, short umask, int time)
{
    this->name = new char[strlen(name)+1];
    memcpy(this->name, name, sizeof(char)*strlen(name));
    this->name[strlen(name)]='\0';
    this->parent_dir = parent;
    this->sub_dirs = NULL;
    this->num_sub_dirs = 0;
    this->mod_time = time;
    this->permissions.oct_perm = umask;
}// Directory constructor

Directory::~Directory()
{
}// destructor

void Directory::showPath()
{
    if (this->parent_dir != NULL)
    {
        this->parent_dir->showPath();
        cout<< this->name << "/" ;
    } else cout<< this->name;
}// show path

void Directory::ls(int argCount, const char* arguments[])
{
    char prem_str[4];
    prem_str[3]='\0';
    if (argCount==1)
    {
        if (strcmp(arguments[0],"-l")!=0)
        {
            cout<<"usage: ls [-l]"<<endl;
            return ;
        }
        for (int i=0;i<this->num_sub_dirs;i++)
        {
            this->sub_dirs[i]->permissions.get_str(prem_str);
            cout<<prem_str<<" "<<this->sub_dirs[i]->mod_time<<" "<<this->sub_dirs[i]->name<<endl;
        }
    } else if (argCount==0)
    {
        for (int i=0;i<this->num_sub_dirs;i++)
        {
            cout<<this->sub_dirs[i]->name<<" ";
        }
        cout<<endl;
    } else {
        cout<<"usage: ls [-l]"<<endl;
        return ;
    }
}// ls function

void Directory::mkdir(int argCount, const char* arguments[], short umask, int time)
{
    if (argCount!=1)
    {
        cout<<"usage: mkdir directory_name"<<endl;
        return;
    }
    if (this->num_sub_dirs >= MAX_SUB_DIRS)
    {
        cout<<"mkdir: "<<this->name<<" already contains the maximum number of directories"<<endl;
        return;
    }
    bool found=false;
    for (int i=0;i<this->num_sub_dirs;i++)
        if (strcmp(arguments[0],this->sub_dirs[i]->name)==0) found=true;
    if (found)
    {
        cout<<"mkdir: cannot create directory '"<<arguments[0]<<"': File exists"<<endl;
        return;
    }

    Directory** temp_pointer = new Directory*[this->num_sub_dirs+1];
    memcpy(temp_pointer, this->sub_dirs, sizeof(Directory*) * this->num_sub_dirs);
    delete[] this->sub_dirs;
    this->sub_dirs = temp_pointer;
    this->sub_dirs[this->num_sub_dirs] = new Directory(arguments[0], this, umask, time);
    this->num_sub_dirs++;
} // mkdir function

Directory* Directory::cd(int argCount, const char* arguments[])
{
    if (argCount!=1)
    {
        cout<<"usage: cd directoryName"<<endl;
        return this;
    }
    if (strcmp(arguments[0],"..")==0)
    {
        if (this->parent_dir == NULL)
        {
            return this;
        } else return this->parent_dir;
    } else {
        bool found = false;
        for (int i=0;i<this->num_sub_dirs;i++)
        if (strcmp(arguments[0],this->sub_dirs[i]->name)==0)
        {
            found=true;
            return this->sub_dirs[i];
        }
        if (!found) {
            cout<<"subdirectory can not be found"<<endl;
            return this;
        }
    }
    return this;
}// cd function

