#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>
#include <cstdlib>

using namespace std;

// Function to display the menu
void displayMenu() {
    cout << "\n--- To-Do List Menu ---\n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Mark Task as Done (and Set to Repeat)\n";
    cout << "4. Delete Task\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

// Function to handle repeating tasks
void repeatTask(vector<string>& tasks, const string& task, int interval) {
    while (true) {
        this_thread::sleep_for(chrono::seconds(interval));
        tasks.push_back(task);
        cout << "\nTask \"" << task << "\" has been repeated!\n";
    }
}

int main() {
    vector<string> tasks;
    int choice;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
        case 1: { // Add Task
            cout << "Enter the task: ";
            cin.ignore(); // Clear input buffer
            string task;
            getline(cin, task);
            tasks.push_back(task);
            cout << "Task added successfully!\n";
            break;
        }
        case 2: { // View Tasks
            if (tasks.empty()) {
                cout << "No tasks available.\n";
            } else {
                cout << "\n--- To-Do List ---\n";
                for (size_t i = 0; i < tasks.size(); ++i) {
                    cout << i + 1 << ". " << tasks[i] << '\n';
                }
            }
            break;
        }
        case 3: { // Mark Task as Done and Set to Repeat
            if (tasks.empty()) {
                cout << "No tasks to mark as done.\n";
            } else {
                cout << "Enter the task number to mark as done: ";
                int taskNumber;
                cin >> taskNumber;

                if (taskNumber > 0 && taskNumber <= tasks.size()) {
                    string completedTask = tasks[taskNumber - 1];
                    cout << "Task \"" << completedTask << "\" marked as done.\n";

                    cout << "Enter the repeat interval in seconds: ";
                    int interval;
                    cin >> interval;

                    // Start a new thread for repeating the task
                    thread(repeatTask, ref(tasks), completedTask, interval).detach();
                    cout << "Task will now repeat every " << interval << " seconds.\n";

                } else {
                    cout << "Invalid task number!\n";
                }
            }
            break;
        }
        case 4: { // Delete Task
            if (tasks.empty()) {
                cout << "No tasks to delete.\n";
            } else {
                cout << "Enter the task number to delete: ";
                int taskNumber;
                cin >> taskNumber;

                if (taskNumber > 0 && taskNumber <= tasks.size()) {
                    tasks.erase(tasks.begin() + taskNumber - 1);
                    cout << "Task deleted successfully!\n";
                } else {
                    cout << "Invalid task number!\n";
                }
            }
            break;
        }
        case 5: // Exit
            cout << "Exiting To-Do List. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
