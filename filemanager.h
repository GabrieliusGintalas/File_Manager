#pragma once

#include <vector>
#include <iostream>

class FileManager
{
public:
    FileManager();
    void CreateNewFile(const std::string& fileName);
    void EditFile(const std::string& fileName);
    void RemoveFile(const std::string& fileName);
    void DeleteAllFiles();
    void ListAllFiles();

private:
    std::vector<std::string> files;
    int fileCounter = 0;
};