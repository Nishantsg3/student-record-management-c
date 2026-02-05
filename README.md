# Student Record Management System (C)

A simple console-based project written in C that manages student records using file handling.  
I built this to practice C fundamentals like structures, binary file I/O, and basic CRUD operations.

The program stores each student's roll number, name, and marks in a binary file (`student.dat`) so the data persists even after closing the program.

---

## 🔍 What This Project Does

- Add new student records  
- View all saved records  
- Search a student by roll number  
- Update an existing record  
- Delete a student record  

Everything happens through a clean, menu-driven interface.

---

## 🧠 Concepts Used

This project helped me understand:

- `struct` for grouping related data  
- File handling in C (`fopen`, `fwrite`, `fread`, `fseek`)  
- Working with binary files  
- Updating records in-place  
- Using a temporary file for deletion  
- Modular, function-based programming in C  

---

## 📂 Folder Structure
```
StudentRecordSystem/
│
├── main.c           # complete source code
├── student.dat      # auto-created at runtime
└── README.md        # documentation
```

*(`student.dat` is optional to upload—recommended to ignore it)*

---

## 🛠️ How It Works (Short & Simple)

### ➤ Adding Records  
Take student details from the user → write to `student.dat` using `fwrite()`.

### ➤ Displaying Records  
Read the file from start to end using `fread()` in a loop.

### ➤ Searching  
Compare roll numbers until a match is found.

### ➤ Updating  
Use `fseek()` to move back one record and overwrite it.

### ➤ Deleting  
Copy everything except the target record to `temp.dat`, then replace the original file.

---

## ▶️ How to Compile and Run

### Windows:
```bash
gcc main.c -o student
student
```

### Linux / Mac:
```bash
gcc main.c -o student
./student
```

---

## 📸 Sample Menu Output
```
===== Student Record Management =====
1. Add Student
2. Display Students
3. Search Student
4. Update Student
5. Delete Student
6. Exit

Enter your choice: 
```

---

## 🎯 Features Overview

| Feature | Description |
|---------|-------------|
| ✅ Add Record | Input roll number, name, and marks |
| 📋 Display All | Shows all stored student records |
| 🔍 Search | Find student by roll number |
| ✏️ Update | Modify existing student data |
| 🗑️ Delete | Remove a student record |
| 💾 Persistence | Data saved in binary file |

---

## 🚀 Future Enhancements

- Input validation for marks and roll numbers
- Sort students by marks or roll number
- Export records to CSV format
- Add more fields (DOB, grade, contact)

---

## 👤 Author

**Nishant Santosh Gawande**  
A fresher actively learning C, Java, SQL & Web Development, and building projects to strengthen my resume and land my first developer role.

---

## 📜 License

This project is open source and available for educational purposes.