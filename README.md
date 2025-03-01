# Task Manager App

A C++-based task management application that allows users to create, manage, and organize tasks across multiple JSON files while maintaining a structured record of task files in a TXT-based Task File Manager.

## Features
Task File Manager (TXT File)
- Stores a list of all **JSON** task files.
- Allows users to **add**, **delete**, **edit**, and **clear** **all** task file entries.
- Ensures only **correctly formatted JSON files** are processed.
- Provides **error protection** by flagging issues when processing files.
  
Task Management (JSON Files)
- Each task file is a JSON document that holds multiple tasks.
- Users can **add**, **delete**, **edit**, or **clear** **all** tasks within a selected file.
- Supports **persistent storage**, ensuring tasks remain available across sessions.
- **Error handling** ensures tasks are saved correctly and logs any processing issues.
- Users can duplicate or copy JSON files within the software to ensure compatibility across devices.

## How It Works
1. Task File Management:
- The TXT file acts as an index, keeping track of all JSON task files.
- Users can manually or programmatically add/remove file names from the TXT index.
- JSON files must follow the correct format to be processed successfully.

2. Task Handling:
- Select a JSON file to manage tasks.
- Modify tasks by adding, editing, or deleting them.
- Clear an entire task file if needed.
3. Error Protection:
- The application automatically logs issues when something goes wrong.
- It prevents file corruption by ensuring safe operations.

## Technologies Used
- **C++** – Core language for application logic.
- **JSON** – Stores structured task data.
- **TXT Files** – Manages and tracks task files.
- **File Handling** – Reads/writes data while ensuring persistence and integrity.

## Getting Started

### Prerequisites

Make sure you have a C++ compiler (such as `g++` or Visual Studio) installed on your machine.

### Installation

1. Clone the repository to your local machine:

    ```bash
    git clone https://github.com/your-username/ToDo-List-Application.git
    ```

2. Navigate to the project directory:

    ```bash
    cd ToDo-List-Application
    ```

3. Compile the code using a C++ compiler:

    ```bash
    g++ -o ToDo_List_Application main.cpp ToDoListing.cpp
    ```

4. Run the program:

    ```bash
    ./ToDo_List_Application
    ```

## Usage

**working on example but also listed above**

## Contributing

Feel free to fork this project, create pull requests, and report issues. Contributions are welcome!

1. Fork the repository.
2. Create a new branch (`git checkout -b feature-name`).
3. Commit your changes (`git commit -am 'Add new feature'`).
4. Push to the branch (`git push origin feature-name`).
5. Create a new pull request.

## License

This project is NOT Licensed.

Created by Cyril D. Tchouta-Moussa.
