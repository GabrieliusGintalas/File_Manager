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
    void ViewFile(const std::string& fileName);
    void RenameFile(std::string& fileName);
    //CopyFile
    //Move File
    //Create Folder
    //Delete Folder
    //Move File to Folder
    //File Properties
    //Sort Files
    //
    void DeleteAllFiles();
    void ListAllFiles();

private:
    std::vector<std::string> files;
    int fileCounter = 0;
};