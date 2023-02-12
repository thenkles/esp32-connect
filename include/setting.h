#pragma once

#include "settings_node.h"
#include <string.h>

using namespace std;

class SettingsGroup;

enum SettingEditorType
{
    Text,
    Select,
    Number,
    Password,
    Checkbox,
    SSID,
    Custom
};

class Setting : public SettingsNode
{
public:
    Setting(SettingsGroup *parent, string name, string title, SettingEditorType editorType);
    Setting(SettingsGroup *parent, string name, string title, string customEditorType);
    SettingEditorType getEditorType();
    string getCustomEditorType();

private:
    SettingEditorType _editorType;
    string _customEditorType;
};