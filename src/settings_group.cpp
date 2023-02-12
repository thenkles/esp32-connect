#include "settings_group.h"
#include <string>

using namespace std;

SettingsGroup::SettingsGroup(SettingsGroup *parent, string name, string title) : SettingsNode(parent, name, title)
{
}

SettingsGroup *SettingsGroup::createGroup(string name, string title)
{
    SettingsGroup *group = new SettingsGroup(this, name, title);
    _items.push_back(group);

    return group;
}

Setting *SettingsGroup::createSetting(string name, string title, SettingEditorType editorType)
{
    Setting *setting = new Setting(this, name, title, editorType);
    _items.push_back(setting);

    return setting;
}

list<SettingsNode *> SettingsGroup::getItems()
{
    return _items;
}