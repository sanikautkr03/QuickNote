#include <iostream>
#include <fstream>
#include <string>

void createNewFile(std::string& content);
void openFile(std::string& content);
void saveFile(const std::string& filename, const std::string& content);
void displayFile(const std::string& content);
void editFile(std::string& content);

int main() {
    int choice;
    std::string content;
    std::string filename;

    while (true) {
        std::cout << "\nSimple Text Editor\n";
        std::cout << "1. Create New File\n";
        std::cout << "2. Open Existing File\n";
        std::cout << "3. Save File\n";
        std::cout << "4. Display File Content\n";
        std::cout << "5. Edit File Content\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore();  // Clear the input buffer

        switch (choice) {
            case 1:
                content.clear();
                createNewFile(content);
                break;
            case 2:
                content.clear();
                openFile(content);
                break;
            case 3:
                std::cout << "Enter filename to save: ";
                std::getline(std::cin, filename);
                saveFile(filename, content);
                break;
            case 4:
                displayFile(content);
                break;
            case 5:
                editFile(content);
                break;
            case 6:
                std::cout << "Exiting...\n";
                return 0;
            default:
                std::cout << "Invalid choice, try again.\n";
        }
    }
}

void createNewFile(std::string& content) {
    std::string filename;
    std::cout << "Enter filename for the new file: ";
    std::getline(std::cin, filename);
    std::ofstream outfile(filename);
    if (outfile.is_open()) {
        std::cout << "Start typing your text (type 'EXIT' to stop):\n";
        std::string line;
        while (true) {
            std::getline(std::cin, line);
            if (line == "EXIT") break;
            content += line + "\n";
        }
        outfile << content;
        outfile.close();
        std::cout << "File '" << filename << "' created and saved.\n";
    } else {
        std::cout << "Unable to create file.\n";
    }
}

void openFile(std::string& content) {
    std::string filename, line;
    std::cout << "Enter filename to open: ";
    std::getline(std::cin, filename);
    std::ifstream infile(filename);
    if (infile.is_open()) {
        while (std::getline(infile, line)) {
            content += line + "\n";
        }
        infile.close();
        std::cout << "File '" << filename << "' opened.\n";
    } else {
        std::cout << "Unable to open file.\n";
    }
}

void saveFile(const std::string& filename, const std::string& content) {
    std::ofstream outfile(filename);
    if (outfile.is_open()) {
        outfile << content;
        outfile.close();
        std::cout << "File '" << filename << "' saved.\n";
    } else {
        std::cout << "Unable to save file.\n";
    }
}

void displayFile(const std::string& content) {
    if (content.empty()) {
        std::cout << "No content to display.\n";
    } else {
        std::cout << "\nFile Content:\n";
        std::cout << content;
    }
}

void editFile(std::string& content) {
    std::cout << "Edit the text (type 'EXIT' to stop):\n";
    std::string line;
    while (true) {
        std::getline(std::cin, line);
        if (line == "EXIT") break;
        content += line + "\n";
    }
    std::cout << "Text edited.\n";
}
