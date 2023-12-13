
/* ----------------
Name :- suraj jaiswal

Roll no. :- 69

Lab_2
*/

#include <iostream>
#include <cstring>

class Student {
private:
    char* name;
    int rollNumber;
    char* className;
    char division;
    char* dob;
    char* bloodGroup;
    char* contactAddress;
    long long phoneNumber;
    char* licenseNumber;

    // Static member variable
    static int count;

public:
    // Constructors
    Student();
    Student(const char* n, int roll, const char* cls, char div,
            const char* birthDate, const char* blood, const char* address,
            long long phone, const char* license);
    Student(const Student& other);  // Copy constructor

    // Destructor
    ~Student();

    // Static member function
    static int getCount();

    // Friend class
    friend class StudentDatabase;

    // Member function to display student information
    void displayInfo();

    // Exception handling
    void setPhoneNumber(long long phone);
};

// Static member variable initialization
int Student::count = 0;

// Constructors
Student::Student() : name(nullptr), className(nullptr), dob(nullptr), bloodGroup(nullptr), contactAddress(nullptr), licenseNumber(nullptr) {
    rollNumber = 0;
    division = 'A';
    phoneNumber = 0;
    count++;
}

Student::Student(const char* n, int roll, const char* cls, char div,
                const char* birthDate, const char* blood, const char* address,
                long long phone, const char* license)
    : rollNumber(roll), division(div), phoneNumber(phone) {
    // Allocate memory and copy strings
    name = new char[strlen(n) + 1];
    strcpy(name, n);

    className = new char[strlen(cls) + 1];
    strcpy(className, cls);

    dob = new char[strlen(birthDate) + 1];
    strcpy(dob, birthDate);

    bloodGroup = new char[strlen(blood) + 1];
    strcpy(bloodGroup, blood);

    contactAddress = new char[strlen(address) + 1];
    strcpy(contactAddress, address);

    licenseNumber = new char[strlen(license) + 1];
    strcpy(licenseNumber, license);

    count++;
}

// Copy constructor
Student::Student(const Student& other) {
    // Similar to the parameterized constructor
    // Implement copying of each data member
}

// Destructor
Student::~Student() {
    delete[] name;
    delete[] className;
    delete[] dob;
    delete[] bloodGroup;
    delete[] contactAddress;
    delete[] licenseNumber;
    count--;
}

// Static member function definition
int Student::getCount() {
    return count;
}

// Display student information
void Student::displayInfo() {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Roll Number: " << rollNumber << std::endl;
    std::cout << "Class: " << className << std::endl;
    std::cout << "Division: " << division << std::endl;
    std::cout << "Date of Birth: " << dob << std::endl;
    std::cout << "Blood Group: " << bloodGroup << std::endl;
    std::cout << "Contact Address: " << contactAddress << std::endl;
    std::cout << "Telephone Number: " << phoneNumber << std::endl;
    std::cout << "Driving License No.: " << licenseNumber << std::endl;
    std::cout << "---------------------------------" << std::endl;
}

// Exception handling for setting phone number
void Student::setPhoneNumber(long long phone) {
    if (phone < 0) {
        throw std::invalid_argument("Phone number cannot be negative.");
    }
    phoneNumber = phone;
}

// Friend class for accessing private members of Student
class StudentDatabase {
public:
    static void displayCount() {
        std::cout << "Total Students: " << Student::getCount() << std::endl;
    }
};

int main() {
    // Creating student objects
    Student student1("John Doe", 101, "12th", 'A', "01-01-2000", "O+", "123 Main St", 1234567890, "DL12345");
    Student student2("Jane Doe", 102, "12th", 'B', "02-02-2001", "AB-", "456 Oak St", 9876543210, "DL67890");

    // Displaying student information
    student1.displayInfo();
    student2.displayInfo();

    // Using friend class to display total count
    StudentDatabase::displayCount();

    // Exception handling example
    try {
        student1.setPhoneNumber(-1); // This should throw an exception
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
