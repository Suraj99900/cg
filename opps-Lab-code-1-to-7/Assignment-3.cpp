/*
***************************
#Name = vaishnavi mane
#Roll No. = 71
#Lab-3
**************************
*/


#include <iostream>
#include <string>

using namespace std;

class Publication {
public:
    string title;
    float price;

public:
    Publication(){};
    Publication(string title, float price);
    ~Publication();
};

Publication::Publication(string title, float price) {
    this->title = title;
    this->price = price;
}

Publication::~Publication() {
    cout << "Publication was destroyed" << endl;
}

class Book : public Publication {
public:
    int iPageCount;

public:
    Book(string title, float price, int pageCount);
    ~Book();
};

Book::Book(string title, float price, int pageCount) : Publication(title, price) {
    this->iPageCount = pageCount;
}

Book::~Book() {
    cout << "Book Destroyed" << endl;
}

class Tape : public Book {
private:
    float min;

public:
    Tape(string title, float price, int pageCount, float min);
    ~Tape();

    void Display() {
        cout << "Book Title: " << this->title << endl;
        cout << "Book price: " << this->price << endl;
        cout << "Page count: " << this->iPageCount << endl;
        cout << "Page Minute: " << this->min << endl;
    }
};

Tape::Tape(string title, float price, int pageCount, float min) : Book(title, price, pageCount) {
    this->min = min;
}

Tape::~Tape() {
    cout << "Tape Destroyed" << endl;
}

int main() {
    const int MAX_TAPES = 100;
    // Allocated Dynamic Memory for storing data 
    Tape** tapeCollection = new Tape*[MAX_TAPES];

    int tapeCount = 0;

    while (true) {
        cout << "\nMenu:\n1. Add Tape\n2. Display Tapes\n3. Quit\n";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                if (tapeCount < MAX_TAPES) {
                    string Title;
                    float price;
                    int iPageCount;
                    float min;

                    cout << "Book Title: ";
                    cin >> Title;
                    cout << "Book price: ";
                    cin >> price;
                    cout << "Page count: ";
                    cin >> iPageCount;
                    cout << "Minute count: ";
                    cin >> min;

                    tapeCollection[tapeCount] = new Tape(Title, price, iPageCount, min);
                    tapeCount++;

                    cout << "Tape added successfully!" << endl;
                } else {
                    cout << "Maximum number of tapes reached!" << endl;
                }
                break;
            }
            case 2: {
                cout << "\n--- Displaying Tapes ---" << endl;
                for (int i = 0; i < tapeCount; ++i) {
                    tapeCollection[i]->Display();
                    cout << "------------------------" << endl;
                }
                break;
            }
            case 3: {
                // Clean up memory before exiting
                for (int i = 0; i < tapeCount; ++i) {
                    delete tapeCollection[i];
                }
                delete[] tapeCollection;
                return 0;
            }
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
}
