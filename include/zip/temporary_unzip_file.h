#pragma once
#include <string>
#include <algorithm>
#include <cstdio>
#include "zip.c"

class TemporaryUnzipFile
{

    std::string zip_path, location;
public:

    std::string get_location()
    {
        std::string path = zip_path + ":" + location;
        std::replace(path.begin(), path.end(), '/', '-');
        return path;
    }

    TemporaryUnzipFile(std::string zip_path, std::string location)
    {
        this->zip_path = zip_path;
        this->location = location;

        struct zip_t *zip = zip_open(zip_path.c_str(), 0, 'r');
        {
            zip_entry_open(zip, location.c_str());
            {
                zip_entry_fread(zip, get_location().c_str());
            }
            zip_entry_close(zip);
        }
        zip_close(zip);
    }

    ~TemporaryUnzipFile()
    {
        std::remove(get_location().c_str());
    }
};