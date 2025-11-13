#include <iostream>
#include <String>
#include <Windows.h>
#include <limits>
#include <iomanip>

size_t userSize = 2;

std::string userStatus[3]{ "Супер администратор", "Администратор", "Сотрудник" };
std::string* loginArr = new std::string[userSize]{ "ad", "us" };
std::string* passArr = new std::string[userSize]{ "123", "321" };
std::string* statusArr = new std::string[userSize]{ userStatus[0], userStatus[2] };
std::string currentStatus{};

//Cклад
size_t storageSize = 0;
unsigned int* idArr = nullptr;
std::string* nameArr = nullptr;
unsigned int* countArr = nullptr;
double* priceArr = nullptr;
bool isStorageCreated = false;

void CreateStorage();
template<typename ArrType>
void FillArray(ArrType* dinamicArray, ArrType* staticArray, size_t arraySize);

void ShowStorage();


void Start();
bool Login();
void SnowSuperAdminMenu();
inline void GetLine(std::string& str);
inline void Err(int time = 1500);


int main() // Магазин видеокарт
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	Start();

	delete[] loginArr, passArr, statusArr;
	if (isStorageCreated)
	{
		delete[] idArr, nameArr, countArr, priceArr;
	}
	return 0;
}
void ShowStorage()
{
	std::cout << "ID\t" << std::left << std::setw(60) << "Название товара\t\t" << "Кол-во\t" << "Цена\n";
	for (int i = 0; i < storageSize; i++)
	{
		std::cout << idArr[i] << "\t" << std::left << std::setw(60) << nameArr[i] << "\t" << countArr[i] << "\t" << priceArr[i] << "\n";
	}
}
void CreateStorage()
{
	const int staticSize = 10;
	
	unsigned int id[staticSize]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; 
	std::string name[staticSize]
	{
		"Видеокарта AmdAsusPrime RTX 2090 - 4 gb", "Видеокарта AmdAsusPrime RTX 4060 ti super - 8 gb",
		"Видеокарта AmdAsusPrime RTX 5070 ti MegaSuper - 32 gb", "Видеокарта AmdAsusPrime RTX 5090 ti UltraSupersi - 64 gb",
		"Видеокарта AmdAsusPrime RTX 2010 - 2 gb", "Видеокарта AmdAsusPrime RTX A5000 - 48 gb",
		"Видеокарта AmdAsusPrime RTX 5060 ti MegaSuper - 24 gb", "Видеокарта AmdAsusPrime RTX 5070 - 8 gb",
		"Видеокарта AmdAsusPrime RTX 2050 ti super - 16 gb", "Видеокарта AmdAsusPrime RTX 5080 - 16 gb",
	};
	unsigned int count[staticSize]{3, 4, 2, 1, 10, 2, 3, 5, 6, 4};
	double price[staticSize]{ 25999.99, 44999.99, 144999.99, 699999.99, 19999.99, 999999.99, 59999.99, 114999.999, 28999.99, 117999.99};

	storageSize = staticSize;
	idArr = new unsigned int[storageSize];
	countArr = new unsigned int[storageSize];
	nameArr = new std::string[storageSize];
	priceArr = new double[storageSize];

	isStorageCreated = true;

	FillArray(idArr, id, storageSize);
	FillArray(nameArr, name, storageSize);
	FillArray(countArr, count, storageSize);
	FillArray(priceArr, price, storageSize);
}

void Start() 
{
	std::string choose;
	std::cout << "\n\n\n\t\t\t3dMaps\n\n\n";
	if (Login())
	{
		if (currentStatus == userStatus[0])
		{
			while (true)
			{
				std::cout << "Выберите склад\n1- Готовый склад\n2 - Создать новый\nВвод: ";
				GetLine(choose);
				if (choose == "1")
				{
					CreateStorage();

				}
				else if (choose == "2")
				{
					// создать новый склад
				}
				else
				{
					Err();
				}
			}
			CreateStorage();
			// Открытие + создание склада
		}
		else if (currentStatus == userStatus[1])
		{
			CreateStorage();
			// Открытие + создание склада
		}
		else if (currentStatus == userStatus[2])
		{
			CreateStorage();
			// Открытие + создание склада
		}
	}
	else
	{
		system("cls");
		std::cout << "Завершения работы программы" << std::endl << std::endl;
	}
}

bool Login()
{
	std::string login, pass;

	while (true)
	{
		std::cout << "Введите логин: ";
		GetLine(login);
		std::cout << "Введите пароль: ";
		GetLine(pass);
		if (login == "exit" && pass == "exit")
		{
			currentStatus = "";
			return false;
		}
		for (size_t i = 0; i < userSize; i++)
		{
			if (login == loginArr[i] && pass == passArr[i])
			{
				std::cout << "Пользователь: " << loginArr[i] << "\n\nДобро пожаловать!\n\n";
				std::cout << "Ваш статус: " << statusArr[i] << "\n\n";
				currentStatus = statusArr[i];
				return true;
			}
		}
	
	}
}

inline void GetLine(std::string& str)
{
	std::getline(std::cin, str, '\n');
}

inline void Err(int time)
{
	std::cout << "Некоректный ввод" << std::endl << std::endl;
	Sleep(time);
	system("cls");
}

template<typename ArrType>
void FillArray(ArrType* dinamicArray, ArrType* staticArray, size_t arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		dinamicArray[i] = staticArray[i];
	}
}

void SnowSuperAdminMenu()
{
	std::string choose;
	while (true)
	{
		std::cout << "1 - Начать продажу" << std::endl;
		std::cout << "2 - Показать склад" << std::endl;
		std::cout << "3 - Попалнить склад" << std::endl;
		std::cout << "4 - Списать товар" << std::endl;
		std::cout << "5 - Изменить цену" << std::endl;
		std::cout << "6 - Редактировать склад" << std::endl;
		std::cout << "7 - Редактировать персонал" << std::endl;
		std::cout << "8 - Отчет о прибыли" << std::endl;
		std::cout << "0 - Закрыть смену" << std::endl;

		std::cout << "Ввод: ";
		GetLine(choose);
		if (choose == "1")
		{

		}
		else if (choose == "2")
		{
			ShowStorage();
		}
		else if (choose == "3")
		{

		}
		else if (choose == "4")
		{

		}
		else if (choose == "5")
		{

		}
		else if (choose == "6")
		{

		}
		else if (choose == "7")
		{

		}
		else if (choose == "8")
		{

		}
		else if (choose == "0")
		{

		}
		else
		{
			Err();
		}
	}
}