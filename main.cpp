#include <iostream>

#include "filemanager.h"

int main()
{
    std::cout << "Welcome to the File Manager by Gabrielius Gintalas!" << std::endl;
    FileManager fileManager;

    while (true)
    {
        std::cout << "Please choose from one of the options below" << std::endl;
        std::cout << "Option 1: Add File" << std::endl;
        std::cout << "Option 2: Edit File" << std::endl;
        std::cout << "Option 3: Remove File" << std::endl;
        std::cout << "Option 4: List All Files" << std::endl;
        std::cout << "Option 5: View a File" << std::endl;
        std::cout << "Option 6: Rename a File" << std::endl;
        std::cout << "Option 7: Copy a file" << std::endl;
        std::cout << "Option 8: Exit program" << std::endl;

        int optionNum;
        std::cout << "Option: ";
        std::cin >> optionNum;
        std::string fileName;

        if (optionNum == 1){
            std::cout << "Please enter file name: ";
            std::cin >> fileName;
            fileManager.CreateNewFile(fileName);
        } else if (optionNum == 2){
            std::cout << "Please enter the file name in which you want to modify: ";
            std::cin >> fileName;
            fileManager.EditFile(fileName);
        } else if (optionNum == 3){
            fileManager.ListAllFiles();
            std::cout << "Please enter the file name in which you would like to delete: ";
            std::cin >> fileName;
            fileManager.RemoveFile(fileName);
        } else if (optionNum == 4){
            fileManager.ListAllFiles();
        } else if (optionNum == 5){
            std::cout << "Please enter the file name in which you would like to view: ";
            std::cin >> fileName;
            fileManager.ViewFile(fileName);
        } else if (optionNum == 6){
            fileManager.ListAllFiles();
            std::cout << "Please enter the file name in which you would like to rename: ";
            std::cin >> fileName;
            fileManager.RenameFile(fileName);
        } else if (optionNum == 7){
            fileManager.ListAllFiles();
            std::cout << "Please enter the file name in which you would like to copy: ";
            std::cin >> fileName;
            fileManager.CopyFile(fileName);
        } else if (optionNum == 8){
            std::cout << "Thank you for using my program!!" << std::endl;
            fileManager.DeleteAllFiles();
            break;
        } else {
            std::cout << "Invalid Input!" << std::endl;
        }
    }

    return 0;
}