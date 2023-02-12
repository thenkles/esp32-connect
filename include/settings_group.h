#pragma once

#include "setting.h"
#include <list>

using namespace std;

class SettingsGroup : public SettingsNode
{
public:
    SettingsGroup(SettingsGroup *parent, string name, string title);
    SettingsGroup *createGroup(string name, string title);
    Setting *createSetting(string name, string title, SettingEditorType editorType);
    list<SettingsNode *> getItems();

private:
    list<SettingsNode *> _items;
};