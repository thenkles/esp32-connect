#pragma once

#include <list>
#include <FS.h>
#include "settings_group.h"

using namespace fs;

class Settings
{
public:
    Settings(FS *fileSystem);

private:
    FS *_fileSystem;
};