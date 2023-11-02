#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>

#include "filemanager.h"

FileManager::FileManager(){

}

void FileManager::CreateNewFile(const std::string& fileName){
    std::ofstream file(fileName); //This creates the file
    if (file.is_open()){
        std::cout << "File '" << fileName << "' created successfully." << std::endl;
        files.push_back(fileName);
        fileCounter++;
        file.close();
    } else {
        std::cout << "Error creating '" << fileName << "'" << std::endl;
    }
}

void FileManager::EditFile(const std::string& fileName){
    std::ofstream file(fileName);
    if(!file){
        std::cout << "Error opening '" << fileName << "'" << std::endl;
        return;
    }

    std::cout << "Editing File: '" << fileName << "'" << std::endl;
    std::cout << "Enter the text you want to write to the file. Type 'EOF' when you are done." << std::endl;

    std::string input;
    while (std::getline(std::cin, input)){
        if(input == "EOF"){
            break;
        }
        file << input << std::endl;
    }
    file.close();
    
}


void FileManager::RemoveFile(const std::string& fileName){
    if(remove(fileName.c_str()) != 0){
        std::cout << "Could not delete file: '" << fileName << "'" << std::endl;
    } else {
        std::cout << "Successfully deleted: '" << fileName << "'" << std::endl;
        auto iter = std::find(files.begin(), files.end(), fileName);
        if(iter != files.end()){
            files.erase(iter);
            fileCounter--;
        }
    }
}

void FileManager::DeleteAllFiles(){
    for(const auto& fileName : files){
        remove(fileName.c_str());
    }

    files.clear();
    fileCounter = 0;
}


void FileManager::ListAllFiles(){
    std::cout << "-------List of all Files:-------" << std::endl;
    for(const auto& fileName : files){
        std::cout << fileName << std::endl;
    }
    std::cout << "--------------------------------" << std::endl;
    std::cout << "Total file count: " << fileCounter << std::endl;
 }