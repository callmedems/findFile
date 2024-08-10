// RECURSIVIDAD 

#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Archivo{
    string name;
};

struct Directorio{
    string name;
    vector<Archivo> archivos;
    vector<Directorio> subdirectorio;
};

bool findFile(Directorio& dir, string& path, string& target) {
    // caso base
    for(auto arch: dir.archivos){
        if(arch.name == target){
            path += "/" + dir.name;
            return true;
        }
    }

    for(auto& subdir: dir.subdirectorio){
        string subdirPath = path + "/" + dir.name;
        if(findFile(subdir, subdirPath, target)){
            path = subdirPath;
            return true;
        }
    }
    return false;
}


int main(){
    Directorio sistemaDeArchivos = {
        "root",
        {
            {"archivo1.txt"},
            {"archivo2.txt"}
        },
        {
            {   
                "subdir1",
                {
                    {"archivo3.txt"},
                },
                {
                    {
                        "subdir2",
                        {
                            {"target.txt"},
                            {"archivo4.txt"}
                        },
                        {}
                    }
                }
            },
            {"archivo5.txt"}
        }
    };
    string target = "archivo3.txt";
    string path = "";

    if(findFile(sistemaDeArchivos, path, target)){
        cout << "Archivo encontrado en: " << path <<  "/" << target << endl;
    } else {
        cout << "Archivo no encontrado" << endl;
    }

    return 0;
}
