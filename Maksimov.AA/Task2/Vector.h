#pragma once
using namespace std;

enum TVectorEXType { vectorOUTOFSIZE, vectorOUTOFRANGE, vectorCOMPNULLVALUE, vectorINICOUTOFSIZE, vectorFILEREADEX };
struct TVectorException
{
	TVectorEXType extype; // вид исключения
	int bspos; // позиция нецифрового символа
	TVectorException(TVectorEXType _extype, int _bspos) : extype(_extype), bspos(_bspos) {};
};
class Vector
{
private:
	int size;
	int *components;
public:
	Vector() { size = 0; }; // по умолчанию
	Vector(const Vector& vec); // копирования
	Vector(string path); // преобразования типа
	explicit Vector(int _size); // инициализатор
	Vector(int _size, int c1); // инициализатор
	Vector(int _size, int c1, int c2); // инициализатор
	Vector(int _size, int c1, int c2, int c3); // инициализатор
	~Vector(); // деструктор

	int getSize() { return size; }; // узнать размер вектора
	void setSize(int _size); // задать размер вектора
	string getFile(string name); // сохранение в файл, возвращает название файла
	double length(); // длина

	int& operator[] (int index); // операция индексации
	const int& operator[] (int index) const; // операция индексации
	Vector& Vector::operator= (const Vector& vec); // =
	int Vector::operator* (const Vector& vec); // скалярное произведение
	Vector Vector::operator+ (const Vector& vec); // сумма (+)
	Vector Vector::operator+= (const Vector& vec); // сумма (+=)

	friend ostream& operator<< (ostream& stream, const Vector& vec); // вывод (Перегрузка операций обмена с потоком)
	friend istream& operator>> (istream& stream, Vector& vec); // ввод (Перегрузка операций обмена с потоком)
};