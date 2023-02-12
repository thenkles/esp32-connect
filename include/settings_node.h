#pragma once

#include <string>

using namespace std;

class SettingsGroup;

class SettingsNode
{
public:
    SettingsNode(SettingsGroup *parent, string name, string title);
    string getPath();
    string getTitle();

private:
    SettingsGroup *_parent;
    string _name;
    string _title;
};