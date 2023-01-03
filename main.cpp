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
	
	
	std::cout << "������� ����:  �������� ����� �� ���� '�������', ������� �����. ������ 10 �������.\n\n";
	std::cout << "�������� ������� ���� : ��������� ���� (������� ����� '1') ��� ���� �� ���� (������� ����� '2') \n";
	std::cout << "���� �� ����: �� ������ ���������� ����� 10 ������, �� ������ ��������� ������� ����� 5 ������.\n\n";
	
	int num{};
	std::cin >> num;

	std::vector<std::string>words = { "������", "������", "�����������", "�������", "������", "���������", "�������", "�������", "�������", "�������", "��������", "�������" };
	
	std::mt19937 gen{ std::random_device()() };
	std::uniform_int_distribution<int> dist(0, words.size() - 1);
	int index = dist(gen);
	std::string word = words[index];
		
	//std::cout << word;

	std::cout << "�������� ����! ������� �����!\n";

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
				std::cout << "������ ����������, ������� ��������� �����...\n";
			}
			if (codeword == word && attempt <= 10) {
				std::cout << "�����������!\n";
			}
			if (counter == 0 && attempt < 10) {
				std::cout << "���... ���������� ��� ���...\n";
			}
		}
		if (attempt == 10 && codeword != word) {
			std::cout << "�������...! ������� ���������. ���� �������� ����� - " << word << " . ������� ������!\n";
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
				std::cout << "������ ����������, ������� ��������� �����...\n";
				std::cout << "��� ���� = " << result << " ������.\n";
			}
			if (codeword == word && attempt <= 10) {
				std::cout << "�����������! �� ������� " << result << " ������!\n";
			}
			if (counter == 0 && attempt < 10) {
				std::cout << "���... ���������� ��� ���...\n";
				if (result >= 5) {
					result -= 5;
					std::cout << "��� ���� = " << result << " ������.\n";
				}
				else if (result < 5) {
					std::cout << "��� ���� = " << result << " ������.\n";
				}
			}
			if (attempt == 10 && codeword != word) {
				std::cout << "�������...! ������� ���������. ���� �������� ����� - " << word << " .�� ������� " << result -5 << " ������! ������ ������ ���� ������!\n";
			}
		}
	}

	return 0;
}