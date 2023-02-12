#include "setting.h"

Setting::Setting(SettingsGroup *parent, string name, string title, SettingEditorType editorType) : SettingsNode(parent, name, title)
{
    _editorType = editorType;
}

Setting::Setting(SettingsGroup *parent, string name, string title, string customEditorType) : SettingsNode(parent, name, title)
{
    _editorType = Custom;
    _customEditorType = customEditorType;
}

SettingEditorType Setting::getEditorType()
{
    return _editorType;
}

string Setting::getCustomEditorType()
{
    return _customEditorType;
}