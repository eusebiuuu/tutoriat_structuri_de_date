#include <iostream>
#include <vector>
#include <fstream>

class MyStack {
    unsigned int current_size = 0;
    std::vector<std::string> stack;

public:
    void push(const std::string &directory) {
        stack.push_back(directory);
        ++current_size;
    }

    std::string pop() {
        if (current_size > 0) {
            std::string directory = stack[current_size - 1];
            stack.pop_back();
            --current_size;
            return directory;
        }
        std::cout << "Stiva este goala!\n";
        return "";
    }

    std::string peek() {
        if (current_size > 0) {
            return stack[current_size - 1];
        }
        return "/";
    }

    [[nodiscard]] bool isEmpty() const {
        return current_size == 0;
    }
};

int main() {
    std::ifstream f("input.txt");
    int n;
    std::vector<std::string> commands;

    f >> n;
    f.ignore();

    while (n--) {
        std::string command;
        std::getline(f, command);
        commands.push_back(command);
    }

    MyStack stack;
    for (const auto &command: commands) {
        if (command[0] == 'c') {
            if (std::string directory = command.substr(3); directory == "..") {
                stack.pop();
            } else {
                stack.push(directory);
            }
        } else {
            std::cout << stack.peek() << "\n";
        }
    }
    return 0;
}
