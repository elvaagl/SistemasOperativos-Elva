#include <iostream>
#include <fstream>
#include <thread>
#include <mutex>
#include <vector>

using namespace std;

mutex fileMutex;

void writeFile(int id, string filename){
    lock_guard<mutex> lock(fileMutex);
    ofstream file(filename, ios::app); 

    if (file.is_open()){
        file << "Thread #" << id << endl;
        file.close();
        cout << "Thread #" << id << " ended" << endl;
    }
}

int main() {
    string nameFile = "pregunta4.txt";
    vector<thread> hilos; 

    for(int i = 1; i <= 5; i++){
        hilos.emplace_back(writeFile, i, nameFile);
    }

    for (auto& t: hilos){
        t.join();
    }
    return 0;
}
