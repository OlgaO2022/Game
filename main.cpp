#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <array>
#include < windows.h >



int main() {
	setlocale(LC_ALL, "rus");
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	
	
	std::cout << "Правила игры:  отгадать слово на тему 'Природа', называя буквы. Дается 10 попыток.\n\n";
	std::cout << "Выберите вариант игры : свободная игра (нажмите цифру '1') или игра на счет (нажмите цифру '2') \n";
	std::cout << "Игра на счет: за каждую отгаданную букву 10 баллов, за каждую неудачную попытку минус 5 баллов.\n\n";
	
	int num{};
	std::cin >> num;

	std::vector<std::string>words = { "гепард", "яблоко", "лиственница", "медведь", "кактус", "крыжовник", "верблюд", "ромашка", "колибри", "журавль", "муравьед", "бегемот" };
	
	std::mt19937 gen{ std::random_device()() };
	std::uniform_int_distribution<int> dist(0, words.size() - 1);
	int index = dist(gen);
	std::string word = words[index];
		
	//std::cout << word;

	std::cout << "Начинаем игру! Вводите буквы!\n";

	std::string codeword;
	for (int i = 0; i < word.size(); i++) {
			codeword += "*";
		}
	std::cout << codeword;
	std::cout << '\n';
	
	if (num == 1) {
		int attempt{};
		int CharOpen = 0;
		while (attempt != 10 && CharOpen < word.size()) {
			char user_char;
			std::cin >> user_char;
			attempt++;
			int counter{};
			for (int i = 0; i < word.size(); i++) {
				if (word[i] == user_char) {
					codeword[i] = user_char;
					std::cout << codeword;
					std::cout << '\n';
					counter++;
				}
			}
			if (counter > 0 && codeword != word && attempt < 10) {
				std::cout << "Хорошо получается, вводите следующую букву...\n";
			}
			if (codeword == word && attempt <= 10) {
				std::cout << "Поздравляем!\n";
			}
			if (counter == 0 && attempt < 10) {
				std::cout << "Упс... Попробуйте ещё раз...\n";
			}
		}
		if (attempt == 10 && codeword != word) {
			std::cout << "Неудача...! Попытки исчерпаны. Было загадано слово - " << word << " . Начните заново!\n";
		}
	}

	if (num == 2) {
		int result{};
		int attempt{};
		int CharOpen = 0;
		while (attempt != 10 && CharOpen < word.size()) {
			char user_char;
			std::cin >> user_char;
			attempt++;
			int counter{};
			for (int i = 0; i < word.size(); i++) {
				if (word[i] == user_char) {
					codeword[i] = user_char;
					std::cout << codeword;
					std::cout << '\n';
					counter++;
					result += 10;
				}
			}
			if (counter > 0 && codeword != word && attempt < 10) {
				std::cout << "Хорошо получается, вводите следующую букву...\n";
				std::cout << "Ваш счет = " << result << " баллов.\n";
			}
			if (codeword == word && attempt <= 10) {
				std::cout << "Поздравляем! Вы набрали " << result << " баллов!\n";
			}
			if (counter == 0 && attempt < 10) {
				std::cout << "Упс... Попробуйте ещё раз...\n";
				if (result >= 5) {
					result -= 5;
					std::cout << "Ваш счет = " << result << " баллов.\n";
				}
				else if (result < 5) {
					std::cout << "Ваш счет = " << result << " баллов.\n";
				}
			}
			if (attempt == 10 && codeword != word) {
				std::cout << "Неудача...! Попытки исчерпаны. Было загадано слово - " << word << " .Вы набрали " << result -5 << " баллов! Можете начать игру заново!\n";
			}
		}
	}

	return 0;
}