#include <iostream>
#include <fstream>
#include <ctime>

using namespace std;

string GetCurrentDate();
void CreateFile();

int main()
{
  CreateFile();

  return 0;
}

// Generar string con la fecha actual
string GetCurrentDate()
{
  time_t t = time(0);
  tm *now = localtime(&t);
  return to_string(now->tm_mday) + "-" + to_string(now->tm_mon + 1) + "-" + to_string(now->tm_year + 1900);
}

// Crear archivo .txt con la fecha en su nombre
void CreateFile()
{
  ofstream file;
  string fileName = GetCurrentDate() + ".txt";

  file.open(fileName, fstream::app);

  if (file.is_open())
  {
    file << "Algo" << endl;
  }
  else
  {
    cout << "Error: No se puede abrir el archivo" << endl;
  }

  file.close();
}