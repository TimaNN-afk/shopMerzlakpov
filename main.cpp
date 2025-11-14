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
void AddStorageItem();
void RemoveStorageItem();
void ChangePrice();
bool IsNumber(const std::string& str);

void ShowStorage(int mode = 0);


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
void ShowStorage(int mode)
{
	if (mode == 0)
	{
		system("cls");
		std::cout << "ID\t" << std::left << std::setw(60) << "Название товара\t\t" << "Кол-во\t" << "Цена\n";
		for (int i = 0; i < storageSize; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(60) << nameArr[i] << "\t" << countArr[i] << "\t" << priceArr[i] << std::endl;
		}
		system("pause");
		system("сls");
	}
	else if (mode == 1)
	{
		std::cout << "ID\t" << std::left << std::setw(60) << "Название товара\t\t" << "Кол-во" << std::endl;
		for (int i = 0; i < storageSize; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(60) << nameArr[i] << "\t" << countArr[i] << std::endl;
		}
	}
	else if (mode == 2)
	{
		std::cout << "ID\t" << std::left << std::setw(60) << "Название товара\t\t" << "Цена\n";
		for (int i = 0; i < storageSize; i++)
		{
			std::cout << idArr[i] << "\t" << std::left << std::setw(60) << nameArr[i] << "\t" << priceArr[i] << std::endl;
		}
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
					system("cls");
					CreateStorage();
					SnowSuperAdminMenu();

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
				system("cls");
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
		std::cout << "3 - Пополнить склад" << std::endl;
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
			AddStorageItem();
		}
		else if (choose == "4")
		{
			RemoveStorageItem();
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

void AddStorageItem()
{
	std::string chooseId, chooseCount, choose;
	unsigned int id = 0, count = 0;
	while (true)
	{
		system("cls");
		ShowStorage(1);
		std::cout << "Введите ID товара или \"exit\" для выхода: ";
		GetLine(chooseId);
		if (chooseId == "exit")
		{
			std::cout << "Отмена операция пополнения товара!" << std::endl;
			Sleep(1500);
			system("cls");
			break;
		}
		std::cout << "Введите кол-во товара для пополнения: ";
		GetLine(chooseCount);

		if (IsNumber(chooseId) && IsNumber(chooseCount))
		{
			id = std::stoi(chooseId) - 1;
			count = std::stoi(chooseCount);

			if(id < 0 || id > storageSize - 1 || count < 0 || count > 20)
			{
				std::cout << "Некорректный id или кол-во\nМаксимальное кол-во 20";
				Sleep(1500);
			}
			else
			{
				std::cout << std::left << std::setw(50) << nameArr[id] << "\t" << countArr[id] << " ---> " << countArr[id] + count << "\n\n";
				std::cout << "Подтвердить?\n1 - Да\n2- Нет\nВвод: ";
				GetLine(choose);
				if (choose == "1")
				{
					countArr[id] += count;
					std::cout << "Товар успешно пополнен\n\n";
					Sleep(1500);
					system("cls");
					break;
				}
				else if (choose == "2")
				{
					std::cout << "Отмена пополнения товара\n";
					Sleep(1500);
				}
				else
				{
					Err();
				}
			}
		}
	}
}

void RemoveStorageItem()
{
	std::string chooseId, chooseCount, choose;
	unsigned int id = 0, count = 0;
	while (true)
	{
		system("cls");
		ShowStorage(1);
		std::cout << "Введите ID товара или \"exit\" для выхода: ";
		GetLine(chooseId);
		if (chooseId == "exit")
		{
			std::cout << "Отмена операция списания товара!" << std::endl;
			Sleep(1500);
			system("cls");
			break;
		}
		std::cout << "Введите кол-во товара для списания: ";
		GetLine(chooseCount);

		if (IsNumber(chooseId) && IsNumber(chooseCount))
		{
			id = std::stoi(chooseId) - 1;
			count = std::stoi(chooseCount);

			if (id < 0 || id > storageSize - 1 || count < 0 || count > countArr[id])
			{
				std::cout << "Некорректный id или кол-во\nМаксимальное кол-во 20";
				Sleep(1500);
			}
			else
			{
				std::cout << std::left << std::setw(50) << nameArr[id] << "\t" << countArr[id] << " ---> " << countArr[id] - count << "\n\n";
				std::cout << "Подтвердить?\n1 - Да\n2- Нет\nВвод: ";
				GetLine(choose);
				if (choose == "1")
				{
					countArr[id] -= count;
					std::cout << "Товар успешно списан\n\n";
					Sleep(1500);
					system("cls");
					break;
				}
				else if (choose == "2")
				{
					std::cout << "Отмена списания товара\n";
					Sleep(1500);
				}
				else
				{
					Err();
				}
			}
		}
	}
}

void ChangePrice()
{
	std::string chooseId, chooseCount, choose;
	unsigned int id = 0, count = 0;
	double newPrice = 0.0;
	while (true)
	{
		system("cls");
		ShowStorage(2);
		std::cout << "Введите ID товара или \"exit\" для выхода: ";
		GetLine(chooseId);
		if (chooseId == "exit")
		{
			std::cout << "Отмена операция изменение цены!" << std::endl;
			Sleep(1500);
			system("cls");
			break;
		}
		std::cout << "Введите новую цену товара: ";
		GetLine(chooseCount);

		if (IsNumber(chooseId) && IsNumber(chooseCount))
		{
			id = std::stod(chooseId) - 1;
			count = std::stod(chooseCount);

			if (id < 0 || id > storageSize - 1 || newPrice < 0.0 || newPrice > 999999.99)
			{
				std::cout << "Некорректная цена\nМаксимальное цена - " << 999999.99 << "\n\n";
				Sleep(1500);
			}
			else
			{
				std::cout << std::left << std::setw(50) << nameArr[id] << "\t" << priceArr[id] << " ---> " << newPrice << "\n\n";
				std::cout << "Подтвердить?\n1 - Да\n2- Нет\nВвод: ";
				GetLine(choose);
				if (choose == "1")
				{
					countArr[id] -= count;
					std::cout << "Цена успешно изменена\n\n";
					Sleep(1500);
					system("cls");
					break;
				}
				else if (choose == "2")
				{
					std::cout << "Отмена изменения цены\n";
					Sleep(1500);
				}
				else
				{
					Err();
				}
			}
		}
	}
}

bool IsNumber(const std::string& str)
{
	if (str.size() <= 0 || str.size() >= 10)
	{
		std::cout << "Ошибка длины числа. Максимум девятизначные числа!\n\n";
		Sleep(1500);
		return false();
	}
	for (int i = 0; i < str.size(); i++)
	{
		if (!std::isdigit(str[i]))
		{
			std::cout << "Введенные данные не являются числом!\n\n";
			Sleep(1500);
			return false;
		}
	}
	return true;
}