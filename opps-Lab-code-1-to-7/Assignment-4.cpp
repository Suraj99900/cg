/*
***************************
#Name = vaishnavi mane
#Roll No. = 71
#Lab-3
**************************
*/

#include <iostream>
#include<string>
#include<fstream>
#include<exception>

using namespace std;


class WriteFile{

private:
	string sLine;

public:
	WriteFile();
	WriteFile(const string& fileName);



};

WriteFile::WriteFile(const string& fileName){
		try{
			ofstream outFile(fileName);

			if (!outFile.is_open())
			{
				throw runtime_error("File not open");
			}else{
				cout<<"Enter Text data ..."<<endl;

				while(true){
					getline(cin,sLine);
					if (sLine == "Exit();")
					{
						break;
					}

					outFile<<sLine<<endl;
				}
			}

			cout << "Text written to the file successfully.\n";
        	outFile.close();

		}catch(string $e){
			cout<<$e;
		}catch(...){
			cout<<"inernal Error Found..."<<endl;
		}
}


class ReadFile{

private:
	string sLine;

public:
	ReadFile();
	ReadFile(const string& fileName);

};

ReadFile::ReadFile(const string& fileName){
	try{
		ifstream inFile(fileName);

		if(!inFile.is_open()){
			throw runtime_error("File not open");
		}else{
			while(getline(inFile,sLine)){
				cout<<sLine<<endl;
			}
		}
		inFile.close();

	}catch(string $e){
		cout<<$e;
	}catch(...){
		cout<<"inernal Error Found..."<<endl;
	}
}


int main(){
	const string fileName = "demo.txt";

	WriteFile writeFile(fileName);

	ReadFile readFile(fileName);
}

