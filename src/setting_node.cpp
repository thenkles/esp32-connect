#include "settings_node.h"

#include <string.h>
#include "settings_group.h"

using namespace std;

SettingsNode::SettingsNode(SettingsGroup *parent, string name, string title)
{
    _parent = parent;
    _name = name;
    _title = title;
}

string SettingsNode::getPath()
{
    if (_parent == NULL)
    {
        return "/" + _name;
    }

    return _parent->getPath() + "/" + _name;
};

string SettingsNode::getTitle()
{
    return _title;
};