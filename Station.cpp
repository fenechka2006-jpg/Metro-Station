#include <iostream>
#include <string>
#include <clocale>
class Station{
	int orderNumber{0};
	std::string name{""};
	double passengerFlow{0.0};
public:
	Station() : orderNumber(0), name(""), passengerFlow(0.0) {}
	Station(int orderNumber, std::string name, double passengerFlow) {
		if (!setOrderNumber(orderNumber)) {
			std::cout << "Неккоректный номер" << std::endl;
		}
		if (!setName(name)) {
			std::cout << "Неккоректное название" << std::endl;
		}
		if (!updatePassengerFlow(passengerFlow)) {
			std::cout << "Некорректный пассажиропоток" << std::endl;
		}
	}

	bool setOrderNumber(int new_number) {
		if (new_number < 1) {
			std::cout << "Номер станции должен быть >= 1" << std::endl;
			return false;
		}
		orderNumber = new_number;
		return true;
	}
	bool setName(std::string new_name) {
		if (new_name.empty()) {
			std::cout << "Название станции не может быть пустым" << std::endl;
			return false;
		}
		name = new_name;
		return true;
	}
	bool updatePassengerFlow(double new_flow) {
		if (new_flow < 0) {
			std::cout << "Пассажиропоток не может быть отрицательным" << std::endl;
			return false;
		}
		double oldFlow = passengerFlow;
		passengerFlow = new_flow;
		std::cout << "Станция '" << name << "': пассажиропоток изменён с "
			<< oldFlow << " до " << new_flow << " чел/день" << std::endl;
		return true;
	}
	int getOrderNumber() const {
		return orderNumber;
	}
	std::string getName() const {
		return name;
	}
	double getPassengerFlow() const {
		return passengerFlow;
	}
	bool operator<(const Station& other) const {
		return orderNumber < other.orderNumber;
	}
	bool operator==(const Station& other) const {
		return orderNumber == other.orderNumber;
	}
};
int main() {
	setlocale(LC_ALL, "Russian");
	// Тест на конструктор по умолчанию
	Station s1;
	std::cout << "Тест1" << std::endl;
	std::cout << "Номер:" << s1.getOrderNumber() << std::endl;
	std::cout << "Название:"  << s1.getName() << std::endl;
	std::cout << "Пассажиропоток: " << s1.getPassengerFlow() << std::endl;
	// Тест на основной конструктор
	Station s2(-1, "Новодачка", 250000000.1);
	std::cout << "Тест2" << std::endl;
	std::cout << "Номер:" << s2.getOrderNumber() << std::endl;
	std::cout << "Название:" << s2.getName() << std::endl;
	std::cout << "Пассажиропоток: " << s2.getPassengerFlow() << std::endl;
	// Тесты на сеттеры
	std::cout << "Тест3" << std::endl;
	s1.setOrderNumber(5);
	s1.setName("Стрешка");
	s1.updatePassengerFlow(1001.5);
	std::cout << "Номер:" << s1.getOrderNumber() << std::endl;
	std::cout << "Название:" << s1.getName() << std::endl;
	std::cout << "Пассажиропоток: " << s1.getPassengerFlow() << std::endl;
	// Тест - неккоректные данные
	std::cout << "Тест4" << std::endl;
	s1.setOrderNumber(-1);
	std::cout << "Номер:" << s1.getOrderNumber() << std::endl;
	s1.setName("");
	std::cout << "Название:" << s1.getName() << std::endl;
	s1.updatePassengerFlow(-500);
	std::cout << "Пассажиропоток: " << s1.getPassengerFlow() << std::endl;
	// Тесты на сравнения
	std::cout << "Тест5" << std::endl;
	Station s3(1, "Первая", 34.9);
	Station s4(2, "Вторая", 2839.4);
	Station s5(1, "Третья", 134.6);

	std::cout << "s3 < s4: " << (s3 < s4) << std::endl;
	std::cout << "s4 < s3: " << (s4 < s3) << std::endl;
	std::cout << "s3 == s5: " << (s3 == s5) << std::endl;
	std::cout << "s3 == s4: " << (s3 == s4) << std::endl;
}