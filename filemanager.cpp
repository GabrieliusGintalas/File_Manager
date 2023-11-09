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

    std::cout << "Would you like to add something to this file?" << std::endl;
    std::cout << "Enter 'YES' or 'NO'" << std::endl;
    std::string option;
    std::cin >> option;
    if(option == "YES"){
        EditFile(fileName);
    } else if (option == "NO"){
        return;
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

void FileManager::ViewFile(const std::string& fileName){
    if(std::find(files.begin(), files.end(), fileName) != files.end()){
        std::ifstream file(fileName);
        std::cout << "Contents of '" << fileName << "'" << std::endl;
        std::cout << "-------------------------------------";
        // Read the contents of the file line by line
        std::string line;
        while(std::getline(file, line)){
            std::cout << line << std::endl;
        }
        
        file.close();
        std::cout << "-------------------------------------" << std::endl;
    }
}

void FileManager::RenameFile(std::string& oldFileName){
    std::cout << "What would you like to change the name of this file to? ";
    std::string newFileName;
    std::cin >> newFileName;
    
    if(std::rename(oldFileName.c_str(), newFileName.c_str()) == 0){
        std::cout << "Successfully renamed file from: " << oldFileName << " to " << newFileName << std::endl;

        auto it = std::find(files.begin(), files.end(), oldFileName);
        *it = newFileName;
    } else {
        perror("Error renaming file");
    }
}

void FileManager::CopyFile(const std::string& fileName){
    std::string copyFileName = "Copy_" + fileName;

    std::ifstream src(fileName, std::ios::binary);
    if(!src){
        std::cerr << "Error: Source file '" << fileName << "' could not be opened" << std::endl;
        return;
    }

    std::ofstream dest(copyFileName, std::ios::binary);
    if(!dest){
        std::cerr << "Error: Destination file '" << fileName << "' could not be opened" << std::endl;
        return;
    }

    //Copies source contents to desination file
    dest << src.rdbuf();

    files.push_back(copyFileName);

    if(src.fail() || dest.fail()){
        std::cerr << "An error occurred while copying the file." << std::endl;
    } else {
        std::cout << "Copied file '" << fileName << "' and made duplicate called " << copyFileName << std::endl;
    }

    src.close();
    dest.close();
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