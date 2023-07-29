# Hospital Management System

The Hospital Management System is a console-based C++ and pyhon application that helps manage patient and doctor information in a hospital. It allows users to add, read, search, update, and delete records for patients and doctors. The application uses file handling to store and retrieve data from text files.

## How to use the application

1. When you run the program, you will be presented with a main menu with the following options:
   ```
   +----------------------------+
   + HOSPITAL MANAGEMENT SYSTEM +
   +----------------------------+
   [1]-Enter Patients Department
   [2]-Enter Doctors Department
   [3]-Exit
   ```

2. Choose the desired option by entering the corresponding number.

### Enter Patients Department

If you choose option 1, you will be directed to the Patients Department section. In this section, you can perform the following actions:

1. Write Patient Record: Add patient information and save it to the "Patient.txt" file.
2. Read Patient Records: Display the patient information stored in the "Patient.txt" file.
3. Search for a Patient Record: Search for a patient by last name or ID.
4. Update a Patient Record: Modify the information of a specific patient.
5. Delete a Patient Record: Remove a patient's information from the records.

### Enter Doctors Department

If you choose option 2, you will be directed to the Doctors Department section. In this section, you can perform the following actions:

1. Write Doctor Record: Add doctor information and save it to the "Doctor.txt" file.
2. Read Doctor Records: Display the doctor information stored in the "Doctor.txt" file.
3. Search for a Doctor Record: Search for a doctor by last name or ID.
4. Update a Doctor Record: Modify the information of a specific doctor.
5. Delete a Doctor Record: Remove a doctor's information from the records.

### Exit

If you choose option 3, the program will terminate, and the application will close.

## Important Notes

- Patient and doctor information is stored in separate text files: "Patient.txt" and "Doctor.txt".
- When searching for a patient or doctor, you can use their last name or ID to find the record.
- The application provides basic data validation for blood group entry to ensure it is a valid blood group type.

## How to Compile and Run

Ensure you have a C++ compiler (e.g., GCC) installed on your system.

1. Save the provided C++ code in a file named "hospital_management_system.cpp".
2. Open a terminal or command prompt and navigate to the directory containing the file.
3. Compile the code using the C++ compiler. For example, with GCC:
   ```
   g++ hospital_management_system.cpp -o hospital_management_system
   ```
4. Run the compiled program:
   ```
   ./hospital_management_system
   ```

Now you can interact with the Hospital Management System application and manage patient and doctor records.
