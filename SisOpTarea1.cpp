#include <iostream>
#include <fstream>

using namespace std;

int main() {

    fstream my_file;

    my_file.open("my_file", ios::out);

    if (!my_file) {
        cout << "File not created!";
    }

    else {
        cout << "File created successfully!";
        my_file << "Hello.";
        my_file << " Me duele la cabeza \n";
        my_file << " Al parecer cat es para ver el contenido del archivo, pero nunca encontre el archivo txt. \n";
        my_file.close();
    }

    return 0;
}