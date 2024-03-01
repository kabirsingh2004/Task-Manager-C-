#include <iostream>
#include <vector>
#include "taskManager.cpp"
#include <iomanip>

using namespace std;

int main()
{
    int choice;
    string title, description;
    TaskManager<Task> taskManager("tasks.json");

    while (true)
    {
        system("cls");
        cout << "Welcome To Task Manager " << endl;
        cout << "1. Add Task" << endl;
        cout << "2. Remove Task" << endl;
        cout << "3. Complete Task" << endl;
        cout << "4. Get Task" << endl;
        cout << "5. Get All Tasks" << endl;
        cout << "6. Get All Completed Tasks" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter Your Choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
        {
            cout << "Enter Title: ";
            getline(cin, title);
            cout << "Enter Description: ";
            getline(cin, description);
            taskManager.addTask(title, description);
            cout << "Task Added Successfully" << endl;
            break;
        }
        case 2:
        {
            int index;
            cout << "Enter Task Index: ";
            cin >> index;
            cin.ignore();

            int taskCount = taskManager.taskCount();

            if (index < 1 || index > taskCount)
            {
                cout << "Invalid Task Index" << endl;
                break;
            }

            taskManager.removeTask(index - 1);
            cout << "Task Removed Successfully" << endl;
            break;
        }
        case 3:
        {
            int index;
            cout << "Enter Task Index: ";
            cin >> index;
            cin.ignore();

            int taskCount = taskManager.taskCount();

            if (index < 1 || index > taskCount)
            {
                cout << "Invalid Task Index" << endl;
                break;
            }

            taskManager.completeTask(index - 1);
            cout << "Task Completed Successfully" << endl;

            break;
        }
        case 4:
        {
            int index;
            cout << "Enter Task Index: ";
            cin >> index;
            cin.ignore();

            int taskCount = taskManager.taskCount();

            if (index < 1 || index > taskCount)
            {
                cout << "Invalid Task Index" << endl;
                break;
            }

            Task task = taskManager.getTask(index - 1);

            cout << "Task " << index << endl;
            cout << "Title: " << task.title << endl;
            cout << "Description: " << task.description << endl;
            cout << "Is Completed: " << (task.isCompleted ? "Yes" : "No") << endl;

            break;
        }
        case 5:
        {

            vector<Task> tasks = taskManager.getAllTasks();

            if (tasks.size() == 0)
            {
                cout << "No Tasks Found" << endl;
                break;
            }

            // Display tasks in tabular format
            cout << setw(10) << "Task" << setw(20) << "Title" << setw(30) << "Description" << setw(15) << "Is Completed" << endl;
            cout << string(75, '-') << endl;

            for (int i = 0; i < tasks.size(); i++)
            {
                cout << setw(10) << i + 1 << setw(20) << tasks[i].title << setw(30) << tasks[i].description << setw(15) << (tasks[i].isCompleted ? "Yes" : "No") << endl;
            }

            break;
        }
        case 6:
        {

            vector<Task> tasks = taskManager.getAllTasks();
            vector<Task> completedTasks;

            if (tasks.size() == 0)
            {
                cout << "No Tasks Found" << endl;
                break;
            }

            for (int i = 0; i < tasks.size(); i++)
            {
                if (tasks[i].isCompleted)
                {
                    completedTasks.push_back(tasks[i]);
                }
            }

            if (completedTasks.size() == 0)
            {
                cout << "No Completed Tasks Found" << endl;
                break;
            }

            // Display tasks in tabular format
            cout << setw(10) << "Task" << setw(20) << "Title" << setw(30) << "Description" << setw(15) << "Is Completed" << endl;
            cout << string(75, '-') << endl;

            for (int i = 0; i < completedTasks.size(); i++)
            {
                cout << setw(10) << i + 1 << setw(20) << completedTasks[i].title << setw(30) << completedTasks[i].description << setw(15) << (completedTasks[i].isCompleted ? "Yes" : "No") << endl;
            }

            break;
        }
        case 7:
        {
            cout << "Exiting........................" << endl;
            exit(0);
            break;
        }
        default:
        {
            cout << "Invalid Choice" << endl;
            break;
        }
        }
        system("pause");
    }

    return 0;
}
