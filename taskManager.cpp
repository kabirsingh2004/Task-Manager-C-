#include <iostream>
#include <vector>
#include "task.cpp"
#include <fstream>

using namespace std;

template <typename T>

class TaskManager
{
private:
    string filename;
    vector<Task> tasks;

    // Function to save vector data to JSON file
    void saveToJSON()
    {
        ofstream file(filename);
        if (file.is_open())
        {
            file << "[";
            for (size_t i = 0; i < tasks.size(); ++i)
            {
                file << tasks[i].to_json();
                if (i < tasks.size() - 1)
                {
                    file << ",";
                }
            }
            file << "]";
            file.close();
        }
        else
        {
            cerr << "Error: Unable to open file for writing\n";
        }
        file.close();
    }

    // Function to load vector data from JSON file
    void loadFromJSON()
    {
        ifstream file(filename);
        if (file.is_open())
        {
            string jsonStr((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
            file.close();

            size_t startPos = jsonStr.find("[");
            size_t endPos = jsonStr.find("]");
            if (startPos != string::npos && endPos != string::npos)
            {
                jsonStr = jsonStr.substr(startPos + 1, endPos - startPos - 1);
                size_t pos = 0;
                while ((pos = jsonStr.find("{")) != string::npos)
                {
                    size_t nextPos = jsonStr.find("}", pos);
                    if (nextPos != string::npos)
                    {
                        T obj;
                        obj.from_json(jsonStr.substr(pos, nextPos - pos + 1));
                        tasks.push_back(obj);
                        jsonStr = jsonStr.substr(nextPos + 1);
                    }
                    else
                    {
                        break; // Invalid JSON
                    }
                }
            }
        }
        else
        {
            cerr << "Error: Unable to open file for reading\n";
        }
        file.close();
    }

public:
    TaskManager(string filename = "tasks.json")
    {
        this->filename = filename;
        loadFromJSON();
    }

    void addTask(string title, string description)
    {
        Task task(title, description);
        tasks.push_back(task);
        saveToJSON();
    }

    void removeTask(int index)
    {
        tasks.erase(tasks.begin() + index);
        saveToJSON();
    }

    void completeTask(int index)
    {
        tasks[index].isCompleted = true;
        saveToJSON();
    }

    Task getTask(int index)
    {
        return tasks[index];
    }

    vector<Task> getAllTasks()
    {
        return tasks;
    }

    int taskCount()
    {
        return tasks.size();
    }
};