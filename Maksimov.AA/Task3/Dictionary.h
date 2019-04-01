#pragma once
using namespace std;

enum TDictEXType { dictWORDNOTFOUND, dictOUTOFRANGE };
struct TDictException
{
	TDictEXType extype; // вид исключения
	int bspos; // позиция нецифрового символа
	string word;
	TDictException(TDictEXType _extype, int _bspos, string _word) : extype(_extype), bspos(_bspos), word(_word) {};
};
class Dictionary
{
private:
	int size = 0;
	string **dict;
public:
	Dictionary(); // по умолчанию
	Dictionary(const Dictionary& d); // копирования
	Dictionary(int _size, string arrD[]); // инициализатор
	Dictionary(string path); // преобразования типа (чтение из файла)
	~Dictionary(); // деструктор

	void Add(string w1, string w2); // добавить слово и его перевод в словарь
	int Find(string word); // найти слово в словаре
	string Translation(string word); // узнать перевод слова
	void Change(string word, string t); // изменить перевод
	int Size() { return size; }; // узнать размер словаря
	void Delete(string word); // удалить слово из словаря

	Dictionary& Dictionary::operator= (const Dictionary& d); // =
	Dictionary Dictionary::operator+ (const Dictionary& d); // сумма (+)
	Dictionary Dictionary::operator+= (const Dictionary& d); // сумма (+=)
	string& operator[] (int index); // операция индексации
	const string& operator[] (int index) const; // операция индексации
	string& operator[] (string word); // операция индексации
	const string& operator[] (string word) const; // операция индексации
	friend ostream& operator<< (ostream& stream, const Dictionary& dict); // вывод (Перегрузка операций обмена с потоком)
	friend istream& operator>> (istream& stream, Dictionary& dict); // ввод (Перегрузка операций обмена с потоком)
	friend ifstream& operator>> (Dictionary& dict, ifstream& fstream); // чтение из файла (Перегрузка ifstream)
};