#include <iostream>
#include <sstream>

using namespace std;

class Task
{
public:
    string title;
    string description;
    bool isCompleted;

    // Combined constructor
    Task(string title = "", string description = "", bool isCompleted = false)
    {
        this->title = title;
        this->description = description;
        this->isCompleted = isCompleted;
    }

    // Function to serialize Task object to JSON-like string
    string to_json() const
    {
        stringstream jsonStream;
        jsonStream << "{";
        jsonStream << "\"title\":\"" << title << "\",";
        jsonStream << "\"description\":\"" << description << "\",";
        jsonStream << "\"isCompleted\":" << (isCompleted ? "true" : "false");
        jsonStream << "}";
        return jsonStream.str();
    }

    // Function to deserialize JSON-like string to Task object
    void from_json(const string &jsonStr)
    {
        // This is a simple parsing example. In a real-world scenario, you'd need a more robust parser.
        size_t pos = jsonStr.find("\"title\":\"");
        if (pos != string::npos)
        {
            pos += 8;
            size_t endPos = jsonStr.find("\"", pos);
            if (endPos != string::npos)
            {
                title = jsonStr.substr(pos, endPos - pos);
            }
        }

        pos = jsonStr.find("\"description\":\"");
        if (pos != string::npos)
        {
            pos += 15;
            size_t endPos = jsonStr.find("\"", pos);
            if (endPos != string::npos)
            {
                description = jsonStr.substr(pos, endPos - pos);
            }
        }

        pos = jsonStr.find("\"isCompleted\":");
        if (pos != string::npos)
        {
            pos += 13;
            size_t endPos = jsonStr.find(",", pos);
            if (endPos == string::npos)
            {
                endPos = jsonStr.find("}", pos);
            }
            if (endPos != string::npos)
            {
                isCompleted = (jsonStr.substr(pos, endPos - pos) == "true");
            }
        }
    }
};