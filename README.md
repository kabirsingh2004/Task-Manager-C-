# Task Manager Console Application

## Overview

This C++ console application serves as a Task Manager, providing users with the ability to manage tasks efficiently through a simple and intuitive interface. Users can perform operations such as adding, removing, completing, and viewing tasks. The application ensures persistent storage by saving tasks to a JSON file.

## Features

- **Add Task:** Users can add tasks by providing a title and description.
- **Remove Task:** Remove tasks by specifying the task index.
- **Complete Task:** Mark tasks as completed by selecting the task index.
- **Get Task:** Retrieve details of a specific task.
- **Get All Tasks:** Display a tabular format of all tasks.
- **Get All Completed Tasks:** View completed tasks in a tabular format.
- **Exit:** Quit the application.

## Usage

1. **Clone the Repository:**

   ```bash
   git clone https://github.com/kabirsingh2004/Task-Manager-C.git
   ```

2. **Compile and Run:**

   ```bash
   g++ -o task_manager main.cpp taskManager.cpp
   ./task_manager
   ```

3. **Navigate the Menu:**

   - Use the numbered options to perform various tasks.
   - Follow on-screen instructions for input.

4. **Persisted Data:**
   - Tasks are stored in a `tasks.json` file for persistent storage.

## Header Files

- iostream
- vector
- iomanip

## Contributing

1. Fork the repository
2. Create a branch: `git checkout -b feature/new-feature`
3. Make your changes and commit: `git commit -m 'Add new feature'`
4. Push to the branch: `git push origin feature/new-feature`
5. Submit a pull request

## License

This Task Manager Console Application is open-source and available under the [MIT License](LICENSE).
