#include <iostream>		// Библиотека ввод/ввывод
#include <string>		// Библиотека для string
#include <vector>		// Для динаамических масивов
#include <memory>		// Для умных ссылок
#include <cstdlib>		// Для функции rand()
#include <locale>		// Для локализации

#ifdef _WIN32
#include <windows.h> // Для работы с консолью в Windows
#endif

// Константы
const int MAX_EMPLOYEES = 5;

const int ADVERTISEMENT_COST = 1000; 
const int MAX_POPULARITY = 100; 
const int OLD_AGE_THRESHOLD = 1000;
const int BREEDING_ENCLOSURE_COST = 800;

/*
В зоопарке есть животные (имя, возраст, вес, предпочтительный климат, цена)
Некоторые животные являются хищниками, некоторые травоядными.
Травоядные не могут жить с хищниками в одном вольере.
*/

// Диета животного
// PREDATORS - хищники
// HERBIVORES - травоядные
// ANY - любая диета
enum class Diet { HERBIVORES, PREDATORS, ANY };
// Климат животного
// TROPIC - тропический
// CONTINENT - умереный (континентальный)
// ARCTIC - арктический
// AQUATIC - аквоид (водный)
enum class Climate { TROPIC, CONTINENT, ARCTIC, AQUATIC };

// Описывает состояние животного
// HEALTHY - здорово
// SICK - больное
// DEAD - погибло
// SELL - продано
enum class AnimalState { HEALTHY, SICK, DEAD, SELL };

// Указывает сытое животное или голодное
// FULL - Сыт
// HUNGRY - Голоден
enum class HungerState { FULL, HUNGRY };

// Указывает пол животного
// MALE - Мужской
// FEMALE - Женский
enum class Gender { MALE, FEMALE };

class Animal {
public:
    int id;						// Индификатор существа
    int age;					// Возраст существа
    Diet diet;					// Диета, хищник или травоядное существо
    int price;                  // Цена животного
    int weight;					// Вес существа
    int happy;					// Счастье существа
    Gender gender;				// Пол, где true - мужик, иначе - женщина
    Climate climate;			// Климат существа
    AnimalState state;			// Состояние существа
    HungerState hunger;			// Голод существа
    std::string name;			// Имя существа
    std::string type;			// Вид животного

    static int nextIdAnimal;	// Статичная переменная для выдачи id существу

    // Наследственность
    int parentId1;	// Родитель 1
    int parentId2;	// Родитель 2

    static const int BASE_ANIMAL_PRICE = 100;
    static const int MAX_AGE = 30;

    // Конструктор
    Animal(int _age, std::string _name, std::string _type, Diet _diet, Climate _climate)
        : age(_age), name(_name), type(_type), diet(_diet), climate(_climate) {
        id = ++nextIdAnimal;
        gender = rand() % 2 == 0 ? Gender::MALE : Gender::FEMALE;
		state = AnimalState::HEALTHY;
		hunger = HungerState::FULL;
    }


    // ===== Гетеры =====

    // Индификатор
    int getId() const { return id; }
    
    // Возраст
    int getAge() { return age; }
   
    // Пол животнго
    Gender getGender() const { return gender; }
    
    // Возвращаем пол животного string
    std::string getGenderString() const {
        return gender == Gender::MALE ? "Мужик" : gender == Gender::FEMALE ? "Женщина" : "Неизвестно";
    }
    
    // Возвращает диету существа, смотри enum Diet
    Diet getDiet() const { return diet; }
    
    // Вернет string диеты животного
    std::string getDietString() const {
        switch (diet)
        {
            case Diet::HERBIVORES: return "Травоядный";
            case Diet::PREDATORS: return "Хищник";
            default: return "Неизвестно";
        }
    }

	// Вернуть тип животного
	std::string getTypeString() const {
		return type;
	}
   
    // Вес животного
    int getWeight() { return weight; }
    
    // Возвращает число счастья в float
    int getHappy() { return happy; }
    
    // Имя животного
    std::string getName() { return name; }
    
    // Родитель №1
    int getParentId1() { return parentId1; }
    
    // Родитель №2
    int getParentId2() { return parentId2; }
    
    // Климат животного, смотри в enum Climate
    Climate getClimate() { return climate; }
   
    // Возвращаем название климата животного
    std::string getClimateString() const {
        switch (climate)
        {
            case Climate::AQUATIC: return "Водный";
            case Climate::ARCTIC: return "Арктический";
            case Climate::CONTINENT: return "Континентальный";
            case Climate::TROPIC: return "Тропический";
            default: return "Неизвестно";
        }
    }
    
    // Состояние животного, смотри enum AnimalState
    AnimalState getState() { return state; }
    
    // Возвращает string состояния животного
    std::string getStateString() {
        switch (state)
        {
            case AnimalState::DEAD: return "Мертвое";
            case AnimalState::HEALTHY: return "Здоровое";
            case AnimalState::SELL: return "Продано";
            case AnimalState::SICK: return "Больное";
            default: return "Неизвестно";
        }
    }
    
    // Состояние животного покушало оно или нет
    HungerState getHungerState() { return hunger; }
    
    // Возвращает string состояние голода животного
    std::string getHungerStateString() {
        switch (hunger)
        {
        case HungerState::FULL: return "Сытое";
        case HungerState::HUNGRY: return "Голодное";
        default: return "Неизвестно";
        }
    }
    
    // Возвращает bool довольно ли животное или нет
    bool getStatisfied() {
        return (hunger == HungerState::FULL && state == AnimalState::HEALTHY);
    }
    
    // Получить цену животного
    int getPrice() {
        return price;
    }


    // ===== Сетеры =====

    // Задать вес
    void setWeight(int _weight) { weight = _weight; }
    
    // Статус голода
    void setHungry(HungerState _hunger) { hunger = _hunger; }

	// Задаем стоимость животного
	void setPrice(int _price) { price = _price; }
    
    // // Задаем кимат
    // void setClimate(Climate _climate) { climate = _climate; }
    
    // Задаем состояние животного
    void setAnimalState(AnimalState _state) { state = _state; }
    
    // Счастье 
    void setHappy(int _happy) { happy = _happy; }
    
    // Изменить имя
    void setName(std::string _name) { name = _name; }
    
    // Задать родителя №1
    void setParent1(int _parentId1) { parentId1 = _parentId1; }
    
    // Задать родителя №2
    void setParent2(int _parentId2) { parentId2 = _parentId2; }


    // ===== Методы =====
    
    // Покормить животное
    void toFood() { hunger = HungerState::FULL; }

    // Полечить животное
    void toHeal() { state = state != AnimalState::HEALTHY ? AnimalState::HEALTHY : state; }


    void update() {
        // Потому что нам не нужно думать что делать с трупом. Трупы нас не интересуют.
        if (state == AnimalState::DEAD || state == AnimalState::SELL) return;

        age++;

        // считаем стоимость животного она меняется с возрастом
        price = price + static_cast<float>(BASE_ANIMAL_PRICE) * (static_cast<float>(MAX_AGE) / static_cast<float>(age));

        // Заражение вирусом с шансом 10%
        if (state == AnimalState::HEALTHY && rand() % 100 < 10) {
            state = AnimalState::SICK;
        }

        // Животное грустит когда болеет
        if (state == AnimalState::SICK) {
            happy = happy - 10 <= 0 ? 0 : happy - 10;
        }

        // Животное радуется еслм оно довольное
        if (getStatisfied()) {
            happy = happy + 10 >= 100 ? 100 : happy + 10;

            // Если животное довольно, здорово и не голодное и растет, то оно набирает вес
            if (happy >= 80) {
                weight = weight + 3;
            }
        }

        // После обновления состояния животное становится голодным
        // Для этого нужно вызвать вункцию кормления животного
        if (hunger == HungerState::FULL) {
            hunger = HungerState::HUNGRY;
        }
        else {
            happy = happy - 20 <= 0 ? 0 : happy - 20;
        }

        // Проверка на старость
		int deathChance = (age > MAX_AGE) ? MAX_AGE : age; // Ограничиваем до MAX_AGE дней
		if (rand() % 100 < deathChance) {
			state = AnimalState::DEAD;
		}

        // Если животное слишком грустит оно межет умереть с 10% шансом
        if (happy <= 10 && rand() % 100 < 10) {
            // std::cout << "happy < 0.1f && rand() % 100 < 10" << std::endl;
            state = AnimalState::DEAD;
        }
    }

    // Перегрузка оператора + для размножения
    std::shared_ptr<Animal> operator+(std::shared_ptr<Animal> partner);
};

// Инициализация статичной переменной для выдачи id существам
int Animal::nextIdAnimal = 0;

// Фабрика для создания животных
class AnimalFactory {
public:
	static std::shared_ptr<Animal> createAnimal(
		int age,
		// const std::string name,
		const std::string type,
		int weight,
		Diet diet,
		Climate climate
	) {
		const std::vector<std::string> names = {
			"Джэнэ", "Гена", "Игорь", "Ринатик", "Генадя", "Ахахах",
			"Джесус", "Гад", "Гаденыш", "Чупокабра", "Черкаш", "Катя бро",
			"Ангелина бро", "Апчехба", "Сулик", "Шарлотан", "Тарантино",
			"Чикотило", "Головешка", "Ожикушик", "Галина", "Чиришка",
			"Алибаба", "Мага брат", "Хуяверс", "Дотер", "Мамкин хулиган",
			"Жириновский", "Паша Техник", "Виктор Цой", "Рюрик", "Владимир красное шонышко",
			"Шалашик", "Султан Сулиман Хан", "Наталья морская пехота", "Иброгим Паша из Парги",
			"Хой", "Изя", "Кузя", "Пизя", "Армен", "Марвин", "Мару", "Боня", "Джига", "Бобик Джан",
			"Муха", "Я хочу салат", "Я хочу поесть", "Сафонов оплатить!"
		};

		std::string name = names[rand() % names.size()];

		// создаем животное
		std::shared_ptr<Animal> animal = std::make_shared<Animal>(age, name, type, diet, climate);
		animal->setWeight(weight);

		return animal;
	}
};

std::shared_ptr<Animal> Animal::operator+(std::shared_ptr<Animal> partner) {
	// Проверки условий размножения
	if (this->gender == partner->gender) {
		throw std::runtime_error("Животные одного пола не могут размножаться");
	}

	// Проверяем, что оба партнера взрослые
	if (this->age <= 5 || partner->age <= 5) {
		throw std::runtime_error("Животные слишком молоды для размножения");
	}

	// Проверяем, что оба партнера разного вида
	// if (this->type == partner->type) {
	//     throw std::runtime_error("Животные одного вида не могут размножаться");
	// }

	// Создание нового животного
	auto animal = AnimalFactory::createAnimal(
		0,
		this->getTypeString() + "+" + partner->getTypeString(),
		(this->getWeight() + partner->getWeight()) / 2,
		this->getDiet(),
		this->getClimate()
	);
	animal->setPrice((this->getPrice() + partner->getPrice()) / 2); // Устанавливаем цену потомку

	// Устанавливаем информацию о родителях
	animal->setParent1(this->getId());
	animal->setParent2(partner->getId());

	return animal;
}

// Профессия рабоотников
// DIRECTOR - директор
// VETERINAR - ветеринар
// CLEANER - уборщик
// FOODMEN - кормильщик
enum class WorkerRole { DIRECTOR, VETERINAR, CLEANER, FOODMEN };

// Статус работника 
// WORK - Работает
// TIRED - Устал
// WORK_ALWAYS - Работает постоянно
enum class WorkerStatus { WORK, TIRED, WORK_ALWAYS };

/*
В зоопарке есть работники
(имя, должность, зарплата, количество обслуживаемых животных)
((не забудьте добавить себя, товарищ Директор))

Работники теперь делятся на разные типы: ветеринар(обслуживает до 20 животных),
уборщик (обслуживает 1 вольер), кормильщик (обслуживает 2 вольера).
В зависимости от типа они имеют разную зарплату.
*/
class Worker {
public:
	int id;					// Индификатор работника
	int price;				// Устанавливает стоимость работы в сутки
	int service;			// Устанавливает количество обслуживаемых животных
	WorkerRole role;		// Устанавливает роль работника
	WorkerStatus status;	// Статус работника устал или не устал
	std::string name;		// Имя раотника

	static int nextIdWorker;	// Статичная переменная для выдачи id работнику

    Worker(std::string _name, int _price, WorkerRole _role) 
		: name(_name), price(_price), role(_role) {
		id = ++nextIdWorker;
		status = WorkerStatus::WORK;
		service = 0;	// Устанавливаем количество обслуживаемых животных
	}


	// ===== Гетеры =====

	int getId() const { return id; }	// Индификатор работника
	int getPrice() const { return price; }	// Цена работника
	WorkerRole getRole() const { return role; }	// Роль работника
	std::string getRoleString() const {
		switch (role)
		{
			case WorkerRole::DIRECTOR: return "Директор";
			case WorkerRole::VETERINAR: return "Ветеринар";
			case WorkerRole::CLEANER: return "Уборщик";
			case WorkerRole::FOODMEN: return "Кормильщик";
			default: return "Неизвестно";
		}
	}
	std::string getName() const { return name; }	// Имя работника
	WorkerStatus getStatus() const { return status; }	// Статус работника
	std::string getStatusString() const {
		switch (status)
		{
			case WorkerStatus::WORK: return "Работает";
			case WorkerStatus::TIRED: return "Устал";
			case WorkerStatus::WORK_ALWAYS: return "Работает постоянно";
			default: return "Неизвестно";
		}
	}


	// ===== Сетеры =====

	void setPrice(int _price) { price = _price; }	// Устанавливает цену работника
	void setRole(WorkerRole _role) { role = _role; }	// Устанавливает роль работника
	void setName(std::string _name) { name = _name; }	// Устанавливает имя работника
	void setStatus(WorkerStatus _status) { status = _status; }	// Устанавливает статус работника
	// Устанавливает статус усталости работника
	void setTired() { status = status != WorkerStatus::WORK_ALWAYS ? WorkerStatus::TIRED : WorkerStatus::WORK_ALWAYS; }	// Устанавливает статус усталости работника
	// Устанавливает статус работника работает
	void setWork() { status = status != WorkerStatus::WORK_ALWAYS ? WorkerStatus::WORK : WorkerStatus::WORK_ALWAYS; }	// Устанавливает статус работника работает

	// ===== Функции =====
	bool getJob() {
		if (status == WorkerStatus::TIRED) return false;

		service++; // Увеличиваем количество обслуживаемых животных

		switch (role)
		{
			case WorkerRole::DIRECTOR:
				// Директор работает всегда
				return true;
			case WorkerRole::VETERINAR:
				// Ветеринар работает до 20 животных
				if (service > 20) {
					setTired();
					return false;
				}
				return true;
			case WorkerRole::CLEANER:
				// Уборщик работает с одним вольером
				if (service > 1) {
					setTired();
					return false;
				}
				return true;
			case WorkerRole::FOODMEN:
				// Кормильщик работает с двумя вольерами
				if (service > 2) {
					setTired();
					return false;
				}
				return true;
			default:
				return false;
		}
	}

    void update() {
		service = 0;
		setWork();
    }
};

int Worker::nextIdWorker = 0;	// Инициализация статичной переменной для выдачи id работнику

// Билдер для создания работника
class WorkerBuilder {
public:
	// Создание работника
	static std::shared_ptr<Worker> createWorker(int price, WorkerRole role, std::string name = "") {
		const std::vector<std::string> names = {
			"Гена", "Игорь", "Ринатик", "Генадя", "Ахахах", 
			"Джесус", "Гад", "Чокопай", "Виктор", "Рюрик",
			"Вова", "Паша", "Ваня", "Саша", "Дима",
			"Роман", "Джон", "Джек", "Джордж",
		};
		
		if (name.empty()) {
			name = names[rand() % names.size()];
		}

		return std::make_shared<Worker>(name, price, role);
	}
};

/*
В зоопарке есть разные вольеры
(количество животных которые могут жить в вольере, тип животных, климат, расходы в день)
*/
class Enclosure {
public:
	int id;											// Индинтификатор
	int dirty;										// Загрязнение вольера
    int capacity;									// Вместимость вольера
	int dailyCost;									// Стоимость обслуживания
    Climate climate;								// Климат вольера
	std::string name;								// Название вольера
	std::vector<std::shared_ptr<Animal>> animals;	// Список животных

	static int nextIdEnclosure;						// Используется для назначения id вольеру

	const int BASE_ANIMAL_COST = 5;					// Базовая стоимость обслуживание животного
	const int BASE_ENCLOSURE_COST = 50;				// Базовая стоимость обслуживание вольера

	Enclosure(std::string _name, int _capacity, Climate _climate) 
		: name(_name), capacity(_capacity), climate(_climate) {
			id = ++nextIdEnclosure;
			dirty = 0;	// Изначально вольер чистый
	}

	// ===== Гетеры =====

	// Получить индификатор вольера
	int getId() const { return id; }

	// Получить загрязнение вольера
	int getDirty() const { return dirty; }
	
	// Получить вместимость вольера
	int getCapacity() const { return capacity; }
	
	// Получить название вольера
	std::string getName() const { return name; }

	// Получить климат вольера
	Climate getClimate() const { return climate; }

	// Получить название климата вольера
	std::string getClimateString() const {
		switch (climate)
		{
			case Climate::AQUATIC: return "Водный";
			case Climate::ARCTIC: return "Арктический";
			case Climate::CONTINENT: return "Континентальный";
			case Climate::TROPIC: return "Тропический";
			default: return "Неизвестно";
		}
	}

	// Получить список живых животных (shared_ptr)
	std::vector<std::shared_ptr<Animal>> getAnimals() const {
		std::vector<std::shared_ptr<Animal>> aliveAnimals;
		for (const auto& animal : animals) {
			if(animal->getState() == AnimalState::HEALTHY || animal->getState() == AnimalState::SICK) {
				aliveAnimals.push_back(animal);
			}
		}
		return aliveAnimals;
	}

	// Получить список животных (shared_ptr)
	std::vector<std::shared_ptr<Animal>> getAllAnimals() const {
		std::vector<std::shared_ptr<Animal>> aliveAnimals;
		for (const auto& animal : animals) {
			aliveAnimals.push_back(animal);
		}
		return aliveAnimals;
	}

	// Получить текущее количесво животных
	// Животные которые живые или больные
	size_t getAnimalCount() const {
		return getAnimals().size();
	}

	// Получить текущее количесво больных животных
	int getSickAnimalCount() const {
		int sickCount = 0;
		for (const auto& animal : animals) {
			if (animal->getState() == AnimalState::SICK) {
				sickCount++;
			}
		}
		return sickCount;
	}

	// Получить текущее количесво всех животных
	size_t getAllAnimalCount() const {
		return getAllAnimals().size();
	}

	// Получить животное по индексу
	std::shared_ptr<Animal> getAnimal(int index) const {
		if (!animals[index]) return nullptr;
		return animals[index];
	}

	// Получить диету вольера
	Diet getDiet() const {
		if (animals.empty()) return Diet::ANY; // Если вольер пустой, возвращаем травоядное
		return animals[0]->getDiet(); // Предполагаем, что все животные в вольере одного типа
	}

	// ===== Сетеры =====
	
	// Установить загрязнение вольера
	void setDirty(int _dirty) {
		dirty = _dirty;
	}

	// Установить название вольера
	void setName(const std::string& _name) {
		name = _name;
	}

	// Проверить, есть ли мето в вольере
	bool hasSpace() const {
		return static_cast<int>(getAnimalCount()) < capacity;
	}

    // Добавить животное в вольер
	bool addAnimal(const std::shared_ptr<Animal>& animal) {
		animals.push_back(animal);
		std::cout << "Животное с id " << animal->getId() << " добавлено в вольер " << name << std::endl;
		return true;
	}

	// Удалить животное
    bool sellAnimal(int id) {
        auto animal = getAnimal(id);
        if (animal != nullptr) {
            animal->setAnimalState(AnimalState::SELL);
			std::cout << "Животное с id " << id << " продано." << std::endl;
			return true;
        }
        else {
            std::cout << "Животное с id " << id << " не найдено в вольере." << std::endl;
			return false;
        }
    }

    // Размножение животных в вольере
    bool breedAnimals(int index1, int index2) {
        auto animal1 = getAnimal(index1);
        auto animal2 = getAnimal(index2);

		// Проверяем, что индексы не равны
		if (index1 == index2) {
			std::cout << "Вы не можете размножать одно и то же животное." << std::endl;
			return false;
		}

		// Проверяем, что оба животных существуют
        if (animal1 == nullptr || animal2 == nullptr) {
            std::cout << "Одно из животных не найдено в вольере." << std::endl;
            return false;
        }

        // Проверяем, что оба животных здоровы
        if (animal1->getState() != AnimalState::HEALTHY || animal2->getState() != AnimalState::HEALTHY) {
            std::cout << "Одно из животных больно или мертво." << std::endl;
            return false;
        }

        // Проверяем, что оба животных разных полов
        if (animal1->getGender() == animal2->getGender()) {
            std::cout << "Животные одного пола не могут размножаться." << std::endl;
            return false;
        }

        // Создаем потомка
        auto offspring = (*animal1) + animal2;
        animals.push_back(offspring);
        return true;
    }

	// Проверить, нужно ли чистить вольер
    bool needsCleaning() {
        if (dirty > 5) { return true; }
        return false;
    }

	// Убрать вольер
    void clean() {
        dirty = 0;
    }

	// Обновить состояние вольера
    void update() {
        dirty += getAnimalCount() / 2;

		// Расчитаем расходы на вольер
		dailyCost = BASE_ENCLOSURE_COST + (getAnimalCount() * BASE_ANIMAL_COST);
		// Учитываем загрязнение вольера
		dailyCost += dirty * 10 * getAnimalCount();

		// Если в вольере есть больные животные, то они могут заразить других животных
		for (int i = 0; i < getSickAnimalCount(); i++) {
			for (auto& animal : animals) {
				if (animal->getState() == AnimalState::HEALTHY) {
					animal->setAnimalState(AnimalState::SICK);
					std::cout << "ID: " << animal->getId() << " | Имя: " << animal->getName() << ", " << animal->getTypeString() << " заболело.\n";
					animal->setHappy(animal->getHappy() - 10); // Животное теряет счастье при болезни
					break;
				}
			}
		}

		// Смерть от болезни
		// Животное умирает если в вольере болеет больше 50% животных, с шансом 50 на 50
		if (getAnimalCount() - getSickAnimalCount() < getSickAnimalCount()) {
			for (auto& animal : animals) {
				if (animal->getState() == AnimalState::SICK && rand() % 2 == 0) {
					std::cout << "ID: " << animal->getId() << " | Имя: " << animal->getName() << ", " << animal->getTypeString() << " умерло.\n";
					animal->setAnimalState(AnimalState::DEAD);
				}
			}
		}
	}
};

int Enclosure::nextIdEnclosure = 0;	// Инициализация статичной переменной для выдачи id вольеру

// Билдер для создания вольера
class EnclosureBuilder {
public:
	// Создание вольера
	static std::shared_ptr<Enclosure> createEnclosure(int capacity, Climate climate) {
        std::shared_ptr<Enclosure> enclosure = std::make_shared<Enclosure>("Вольер", capacity, climate);
		const std::vector<std::string> names = {
			"Восточный", "Октяборьский", "Ленинский", "Центральный", "Севастопольский",
			"Краснопресненский", "Валихановский", "Смоленский", "Пушкинский", "Тверской",
			"Таганский", "Синегорский", "Северный", "Южный", "Западный",
			"Дальневосточный", "Сибирский", "Уральский", "Кавказский", "Крымский",
			"Калужский", "Тульский", "Рязанский", "Липецкий", "Воронежский"
		};
		enclosure->setName(std::to_string(enclosure->getId()) + ". Вольер " + names[rand() % names.size()]);
		return enclosure;
	}
};


/*
В зоопарке есть список показателей (еда, деньги, популярность)
еда тратится на животных (сколько съели = количество животных),
если животное не покормить - оно может умереть(50% шанс).
еду можно покупать (+еда -деньги)
в зоопарк в зависимости от популярность приходят посетители (посетители = 2*популярность)
в зависимости от количества животных посетители приносят зоопарку деньги
(деньги в день = количество посетителей * количество животных)
на популярность влияют различные факторы
        повысить рекламой (-деньги, +популярность)
        колеблется случайно (+-10% в день)
        *специфичные для варианта вещи*

*/

struct animalData {
	std::string type;
	int age;
	int weight;
	int price;
	Diet diet;
	Climate climate;
};

// Шаблоны животных для рынка
const std::vector<animalData> animalTemplates = {
	{"Лев", 0, 200, 1000, Diet::PREDATORS, Climate::TROPIC},
	{"Тигр", 0, 180, 900, Diet::PREDATORS, Climate::TROPIC},
	{"Слон", 0, 5000, 900, Diet::HERBIVORES, Climate::CONTINENT},
	{"Жираф", 0, 800, 800, Diet::HERBIVORES, Climate::CONTINENT},
	{"Пингвин", 0, 30, 600, Diet::PREDATORS, Climate::ARCTIC},
	{"Белый медведь", 0, 450, 750, Diet::PREDATORS, Climate::ARCTIC},
	{"Зебра", 0, 300, 600, Diet::HERBIVORES, Climate::CONTINENT},
	{"Обезьяна", 0, 50, 400, Diet::HERBIVORES, Climate::TROPIC},
	{"Крокодил", 0, 1000, 500, Diet::PREDATORS, Climate::TROPIC},
	{"Панда", 0, 200, 1000, Diet::HERBIVORES, Climate::TROPIC},
	{"Кенгуру", 0, 80, 1000, Diet::HERBIVORES, Climate::CONTINENT},
	{"Лемур", 0, 10, 700, Diet::HERBIVORES, Climate::TROPIC},
	{"Коала", 0, 15, 700, Diet::HERBIVORES, Climate::TROPIC},
	{"Тюлень", 0, 200, 350, Diet::PREDATORS, Climate::ARCTIC},
	{"Медведь", 0, 450, 550, Diet::PREDATORS, Climate::CONTINENT},
	{"Лошадь", 0, 400, 500, Diet::HERBIVORES, Climate::CONTINENT},
	{"Кошка", 0, 5, 200, Diet::PREDATORS, Climate::TROPIC},
	{"Собака", 0, 10, 300, Diet::PREDATORS, Climate::CONTINENT},
	{"Попугай", 0, 1, 100, Diet::HERBIVORES, Climate::TROPIC},
	{"Черепаха", 0, 2, 150, Diet::HERBIVORES, Climate::ARCTIC},
	{"Фламинго", 0, 3, 200, Diet::HERBIVORES, Climate::TROPIC},
	{"Сурикат", 0, 4, 250, Diet::HERBIVORES, Climate::TROPIC},
	{"Бобер", 0, 20, 300, Diet::HERBIVORES, Climate::CONTINENT},
	{"Лосось", 0, 200, 400, Diet::HERBIVORES, Climate::AQUATIC},
	{"Вобла", 0, 300, 500, Diet::HERBIVORES, Climate::AQUATIC},
	{"Краб", 0, 1, 100, Diet::HERBIVORES, Climate::AQUATIC},
	{"Утка", 0, 2, 150, Diet::HERBIVORES, Climate::AQUATIC},
	{"Лягушка", 0, 1, 50, Diet::HERBIVORES, Climate::AQUATIC},
	{"Сом", 0, 10, 200, Diet::HERBIVORES, Climate::AQUATIC},
	{"Кит", 0, 10000, 2000, Diet::HERBIVORES, Climate::AQUATIC},
	{"Дельфин", 0, 300, 1500, Diet::HERBIVORES, Climate::AQUATIC},
	{"Морская звезда", 0, 1, 50, Diet::HERBIVORES, Climate::AQUATIC},
	{"Морская свинка", 0, 2, 100, Diet::HERBIVORES, Climate::TROPIC},
	{"Крыса", 0, 1, 50, Diet::HERBIVORES, Climate::CONTINENT}
};

class Zoo {
public:
	int day;			// День
	int food;			// Количество еды
	int money;			// Количество денег
	int popularity;		// Популярность
	std::string name;	// Название зоопарка
	std::vector<std::shared_ptr<Worker>> workers;	// Список работников
	int animalsBoughtToday;	// Количество купленных животных сегодня
	std::vector<std::shared_ptr<Enclosure>> enclosures;	// Список вольеров
	std::vector<animalData> marketAnimals;	// Список животных на рынке

	const int MARKET_REFRESH_COST = 500;	// Стоимость обновления рынка
	const int MARKET_MAX_COUNT = 10;	// Максимальное количество животных на рынке

	Zoo(std::string _name, int start_money)
		: name(_name), money(start_money), day(0), food(100), popularity(50), animalsBoughtToday(0) {
		// Добавляем директора
		workers.push_back(WorkerBuilder::createWorker(100, WorkerRole::DIRECTOR, "Директор Егор"));
		generateMarketAnimals();
	}

	// ===== Гетеры =====
	int getDay() const { return day; }	// Получить день
	int getFood() const { return food; }	// Получить количество еды
	int getMoney() const { return money; }	// Получить количество денег
	int getPopularity() const { return popularity; }	// Получить популярность
	std::string getName() const { return name; }	// Получить название зоопарка
	std::vector<std::shared_ptr<Worker>> getWorkers() const { return workers; }	// Получить список работников
	std::vector<std::shared_ptr<Enclosure>> getEnclosures() const { return enclosures; }	// Получить список вольеров
	// Получить список животных
	std::vector<std::shared_ptr<Animal>> getAnimals() const { 
		std::vector<std::shared_ptr<Animal>> allAnimals;
		for (const auto& enclosure : enclosures) {
			auto animals = enclosure->getAllAnimals();
			allAnimals.insert(allAnimals.end(), animals.begin(), animals.end());
		} 
		return allAnimals; 
	}

	// Получить животное по id
	std::shared_ptr<Animal> getAnimal(int id) const {
		for (const auto& enclosure : enclosures) {
			for (const auto& animal : enclosure->getAllAnimals()) {
				if (animal->getId() == id) {
					return animal;
				}
			}
		}
		return nullptr; // Если животное не найдено
	}

    // Считаем количество больных животных
    int getCountSickAnimal() const {
        int totalSickAnimal = 0;
		for (const auto& enclosure : enclosures) {
			totalSickAnimal += enclosure->getSickAnimalCount();
		}
		return totalSickAnimal;
    }

    // Считаем количество живых животных
    int getCountAnimal() const {
        int totalAnimal = 0;
        for (const auto& enclosure : enclosures) {
			totalAnimal += enclosure->getAnimalCount();
        }
        return totalAnimal;
    }

	std::shared_ptr<Enclosure> getEnclosure(int index) const {
		for (const auto& enclosure : enclosures) {
			if (enclosure->getId() == index) {
				return enclosure;
			}
		}
		return nullptr;
	}

	// ===== методы =====

	// Метод для лечения животных
    void healthingAnimal() {
        int totalSickAnimal = getCountSickAnimal();

        if (totalSickAnimal == 0) {
            std::cout << "Нет больных животных.\n";
            return;
        }

        for (auto& worker : workers) {
			if (worker->getRole() == WorkerRole::VETERINAR && worker->getStatus() != WorkerStatus::TIRED) {
				std::cout << "Ветеринар " << worker->getName() << ", начал лечить животных:\n";
				for (auto& enclosure : enclosures) {
					for (auto& animal : enclosure->getAnimals()) {
						// Если животное больно, то лечим его
						if (animal->getState() == AnimalState::SICK) {
							if (worker->getJob())
							{
								animal->setAnimalState(AnimalState::HEALTHY);
								std::cout << "ID: " << animal->getId() << " | Имя: " << animal->getName() << ", " << animal->getTypeString() << " вылечили.\n";
							}
						}
					}
				}
			}
        }

        totalSickAnimal = getCountSickAnimal();
        if (totalSickAnimal) {
            std::cout << "Еще остались больные животные\n";
        }
    }

	// Сгенерировать список животных для рынка
	void generateMarketAnimals() {
		marketAnimals.clear();

		// Генерируем до MARKET_MAX_COUNT случайных животных
		for (int i = 0; i < MARKET_MAX_COUNT; i++) {
			animalData templateAnimal = animalTemplates[rand() % animalTemplates.size()];
			animalData newAnimal = templateAnimal;
			newAnimal.age = rand() % Animal::MAX_AGE;
	
			// Избегаем деления на ноль при расчете цены
			if (newAnimal.age > 0) {
				newAnimal.price += static_cast<float>(Animal::BASE_ANIMAL_PRICE) *
								   (static_cast<float>(Animal::MAX_AGE) / static_cast<float>(newAnimal.age));
			}
	
			// Избегаем деления на ноль при расчете веса
			int halfWeight = newAnimal.weight / 2;
			if (halfWeight > 0) {
				newAnimal.weight += rand() % halfWeight;
			}
	
			marketAnimals.push_back(newAnimal);
		}
	}

	// Метод для покупки животных на рынке
	// Возвращает true, если животное куплено успешно
    bool buyFromMarket(std::shared_ptr<Enclosure> encl, int index) {
        if (day > 10 && animalsBoughtToday >= 1) {
            std::cout << "После 10-го дня можно покупать только 1 животное в день" << std::endl;
            return false;
        }

        if (index < 0 || index >= marketAnimals.size() + 1) {
			std::cout << "Некорректный индекс животного на рынке." << std::endl;
			return false;
		}

        auto animal = marketAnimals[index - 1];

        if (money < animal.price) {
			std::cout << "Недостаточно денег для покупки животного." << std::endl;
			return false;
		}

        //Проверяем, есть ли место в зоопарке
		if (encl->hasSpace()) {
			// Создаем животное
			auto newAnimal = AnimalFactory::createAnimal(
				animal.age,
				animal.type,
				animal.weight,
				animal.diet,
				animal.climate
			);
			newAnimal->setPrice(animal.price);

			if (!newAnimal) {
				std::cout << "Не удалось создать животное." << std::endl;
				return false;
			}

			// Добавляем животное в вольер
			encl->addAnimal(newAnimal);

			money -= animal.price;
			animalsBoughtToday++;
			std::cout << "Животное " << newAnimal->getName() << ", " << newAnimal->getTypeString() << " куплено за " << newAnimal->getPrice() << std::endl;
			// Удаляем животное из рынка
			marketAnimals.erase(marketAnimals.begin() + index - 1);
			return true;
		}

        std::cout << "Не удалось добавить животное. Возможно вольер полон." << std::endl;
        return false;
    }

	// Найм работника
	// Возвращает true, если работник успешно нанят
    bool hireWorker(WorkerRole role) {
        int salary = 0;
        switch (role) {
			case WorkerRole::VETERINAR: salary = 80; break;
			case WorkerRole::CLEANER: salary = 50; break;
			case WorkerRole::FOODMEN: salary = 60; break;
			default: return false;
        }

        if (money < salary) return false;

		auto worker = WorkerBuilder::createWorker(salary, role);

		workers.push_back(worker);
		std::cout << "Работник " << worker->getName() << ", " << worker->getRoleString() << " нанят за $" << salary << std::endl;
        
        money -= salary;
        return true;
    }

	// Построить вольер
	// Возвращает true, если вольер успешно построен
	// capacity - вместимость вольера
    bool buildEnclosure(Climate climate, int capacity = 5) {
        int cost = capacity * 100;
        if (money < cost) {
			std::cout << "Недостаточно денег для постройки вольера." << std::endl;
			return false;
		}

		auto enclosure = EnclosureBuilder::createEnclosure(capacity, climate);
		std::cout << "Вольер построен \"" << enclosure->getName() << "\" построен за $" << cost << std::endl;

        enclosures.push_back(enclosure);
        money -= cost;
        return true;
    }

	// Купить еду
	// Возвращает true, если еда успешно куплена
    bool buyFood(int amount) {
        int cost = amount * 10;
        if (money >= cost) {
            food += amount;
            money -= cost;
			std::cout << "Куплено " << amount << " еды за $" << cost << std::endl;
			return true;
		}
		std::cout << "Недостаточно денег для покупки еды." << std::endl;
		return false;
    }

	// Рекламировать зоопарк
	// Возвращает true, если реклама успешно проведена
    bool advertise() {
        if (money >= 50) {
			popularity = popularity + 15 >= 100 ? 100 : popularity + 15;
            money -= 50;
			std::cout << "Реклама проведена. Популярность увеличена на 15." << std::endl;
			return true;
        }
		std::cout << "Недостаточно денег для рекламы." << std::endl;
		return false;
    }

	void nextDay() {
        day++;
		
		int popularityChange = rand() % 21 - 10; // Случайное число от -10 до +10
		// Случайно повялтяется известная личность прибавляет популярности с шансом 5%
		if (rand() % 100 < 15) {
			std::cout << "Известная личность посетила зоопарк!" << std::endl;
			popularityChange += 10;
		}
		// Случайно повялтяется фотограф прибаляет полурярность 5% с шансом 10%
		if (rand() % 100 < 20) {
			std::cout << "Фотограф сделал снимки животных!" << std::endl;
			popularityChange += 5;
		}
		popularity = popularity + popularityChange >= 100 ? 100 : popularity + popularityChange; // Ограничиваем популярность от 0 до 100

        generateMarketAnimals();
        animalsBoughtToday = 0;

        // Обновим статус усталости работникам зоопарка
        for (auto& worker : workers) {
			worker->update();
		}


        // Считаем количество живых животных
        int totalAnimal = getCountAnimal();
		// std::cout << "Количество животных: " << totalAnimal << std::endl;
        // Считаем количество больных животных
        int totalSickAnimal = getCountSickAnimal();
		// std::cout << "Количество больных животных: " << totalSickAnimal << std::endl;

        
		// Считаем количество еды
		if (food <= 0) {
			std::cout << "Еда закончилась! Животные могут умереть." << std::endl;
			for (auto& enclosure : enclosures) {
				for (auto& animal : enclosure->getAnimals()) {
					if (animal->getState() == AnimalState::HEALTHY) {
						animal->setAnimalState(AnimalState::DEAD);
						std::cout << "ID: " << animal->getId() << " | Имя: " << animal->getName() << ", " << animal->getTypeString() << " умерло от голода.\n";
					}
				}
			}
			food = 0; // Обнуляем еду, чтобы не было отрицательного значения
		} else {
			// Тратим еду на животных
			int foodConsumed = 0;
			for (const auto& enclosure : enclosures) {
				foodConsumed += enclosure->getAnimalCount();
			}
			if (foodConsumed > food) {
				std::cout << "Недостаточно еды для всех животных! Некоторые животные могут умереть от голода." << std::endl;
				for (auto& enclosure : enclosures) {
					for (auto& animal : enclosure->getAnimals()) {
						if (animal->getState() == AnimalState::HEALTHY) {
							animal->setAnimalState(AnimalState::DEAD);
							std::cout << "ID: " << animal->getId() << " | Имя: " << animal->getName() << ", " << animal->getTypeString() << " умерло от голода.\n";
						}
					}
				}
				food = 0; // Обнуляем еду, чтобы не было отрицательного значения
			} else {
				food -= foodConsumed; // Тратим еду на животных
				std::cout << "Потрачено " << foodConsumed << " еды на животных. Осталось " << food << " еды." << std::endl;
			}
		}
		// Считаем доход от животных
		int income = totalAnimal * 5; // 5$ за животное
		money += income;
		std::cout << "Доход от животных: $" << income << ". Текущие деньги: $" << money << std::endl;
		// Обновляем вольеры
		for (auto& enclosure : enclosures) {
			std::cout << "Обновление вольера: " << enclosure->getName() << std::endl;
			enclosure->update();
		}
		std::cout << "Конец дня " << day << ". Текущие деньги: $" << money << ", еда: " << food << ", популярность: " << popularity << std::endl;
    }
};


void marketManagement(Zoo& zoo) {
	if (zoo.enclosures.empty()) {
		std::cout << "Нет вольеров для покупки животных. Сначала постройте вольер." << std::endl;
		return;
	}
	while (true) {
        std::cout << "\n=== Рынок животных ===" << std::endl;
        std::cout << "1. Посмотреть доступных животных" << std::endl;
        std::cout << "2. Купить животное" << std::endl;
        std::cout << "3. Обновить ассортимент (стоимость: $" << zoo.MARKET_REFRESH_COST << ")" << std::endl;
        std::cout << "4. Назад" << std::endl;
        std::cout << "Выбор: ";

		int choice;
		std::cin >> choice;
		if (choice < 1 || choice > zoo.MARKET_MAX_COUNT) {
			std::cout << "Неверный выбор! Пожалуйста, выберите от 1 до " << zoo.MARKET_MAX_COUNT <<"." << std::endl;
			continue;
		}

		if (choice != 3 && choice != 4 && zoo.marketAnimals.empty()) {
			std::cout << "Рынок пуст. Пожалуйста, обновите ассортимент." << std::endl;
			continue;
		}

		switch (choice) 
		{
			case 1:
				// Вывод списка доступных животных на рынке
				std::cout << "\nДоступные животные на рынке:" << std::endl;
				for (auto& animal : zoo.marketAnimals) {
					std::cout << "Вид: " << animal.type << " ";
					std::cout << "Возраст: " << animal.age << " дней ";
					std::cout << "Вес: " << animal.weight << " кг ";
					std::cout << "Цена: " << animal.price << "$ ";
					std::cout << "Диета: " << (animal.diet == Diet::PREDATORS ? "Хищник" : "Травоядное") << " ";
					std::cout << "Климат: ";
					switch (animal.climate) {
						case Climate::TROPIC: std::cout << "Тропики"; break;
						case Climate::CONTINENT: std::cout << "Континент"; break;
						case Climate::ARCTIC: std::cout << "Арктика"; break;
						case Climate::AQUATIC: std::cout << "Водный"; break;
						default: std::cout << "Неизвестно"; break;
					}
					std::cout << std::endl;
				}
			break;
			case 2: 
			{
					int idx = 0;
					// Вывод списка вольеров
					std::cout << "\nДоступные вольеры:" << std::endl;
					for (const auto enclosure : zoo.enclosures) {
						std::cout << "ID: " << enclosure->getId() << " Вольер: " << enclosure->getName() << ", " << enclosure->getClimateString() << " - " << enclosure->getAnimalCount() << "/" << enclosure->getCapacity() << std::endl;
					}
					
					std::cout << "Выберите вольер для покупки животного (1-" << zoo.enclosures.size() << "): ";
					int enclosureChoice;
					std::cin >> enclosureChoice;

					if (enclosureChoice < 1 || enclosureChoice > zoo.enclosures.size()) {
						std::cout << "Неверный выбор вольера" << std::endl;
						continue;
					}
					
					auto enclosure = zoo.getEnclosure(enclosureChoice);
					if (!enclosure) {
						std::cout << "Вольер не найден" << std::endl;
						continue;
					}	

					std::cout << "\nДоступные животные на рынке:" << std::endl;
					for (auto& animal : zoo.marketAnimals) {
						idx++;
						if (enclosure->getClimate() != animal.climate) {
							continue; // Пропускаем животных, не подходящих по климату
						}
						std::cout << idx << ". ";
						std::cout << "Вид: " << animal.type << " ";
						std::cout << "Возраст: " << animal.age << " дней ";
						std::cout << "Вес: " << animal.weight << " кг ";
						std::cout << "Цена: " << animal.price << "$ ";
						std::cout << "Диета: " << (animal.diet == Diet::PREDATORS ? "Хищник" : "Травоядное") << " ";
						std::cout << "Климат: ";
						switch (animal.climate) {
							case Climate::TROPIC: std::cout << "Тропики"; break;
							case Climate::CONTINENT: std::cout << "Континент"; break;
							case Climate::ARCTIC: std::cout << "Арктика"; break;
							case Climate::AQUATIC: std::cout << "Водный"; break;
							default: std::cout << "Неизвестно"; break;
						}
						std::cout << std::endl;
					}

					std::cout << "Выберите животное для покупки (1-" << zoo.marketAnimals.size() << ", 0 для отмены): ";
					int animalChoice;
					std::cin >> animalChoice;

					if (animalChoice == 0) continue; // Отмена покупки

					if (animalChoice < 1 || animalChoice > zoo.marketAnimals.size()) {
						std::cout << "Неверный выбор животного" << std::endl;
						continue;
					}

					if (enclosure->getClimate() != zoo.marketAnimals[animalChoice - 1].climate) {
						std::cout << "Животное не подходит по климату для этого вольера" << std::endl;
						continue;
					}

					if (enclosure->getDiet() != Diet::ANY && enclosure->getDiet() != zoo.marketAnimals[animalChoice - 1].diet) {
						std::cout << "Животное не подходит по диете для этого вольера" << std::endl;
						continue;
					}

					if (zoo.buyFromMarket(enclosure, animalChoice)) {
						std::cout << "Животное успешно куплено!" << std::endl;
					}
					else {
						std::cout << "Не удалось купить животное" << std::endl;
					}
					break;
				}
			case 3:
				if (zoo.money >= zoo.MARKET_REFRESH_COST) {
					zoo.generateMarketAnimals();
					zoo.money -= zoo.MARKET_REFRESH_COST;
					std::cout << "Ассортимент обновлен!" << std::endl;
				}
				else {
					std::cout << "Недостаточно средств для обновления ассортимента" << std::endl;
				}
				break;
			case 4:
			return; // Возврат в главное меню
			default:
				std::cout << "Неверный выбор! Пожалуйста, выберите от 1 до 4." << std::endl;
			break;
		}
    }
}

void breedingManagement(Zoo& zoo) {
    while (true) {
        std::cout << "\n=== Размножение животных ===" << std::endl;
        std::cout << "1. Посмотреть животных в вольерах" << std::endl;
        std::cout << "2. Размножить животных" << std::endl;
        std::cout << "3. Назад" << std::endl;
        std::cout << "Выбор: ";


        int choice;
        std::cin >> choice;

        int enclosureChoice = 0;
        auto enclosure = std::shared_ptr<Enclosure>(nullptr);
		auto firstAnimal = std::shared_ptr<Animal>(nullptr);
		auto secondAnimal = std::shared_ptr<Animal>(nullptr);

        switch (choice) {
            case 1:
                // Просмотр животных в зоопарке
                for (const auto enclosure : zoo.enclosures) {
                    std::cout << "Вольер: " << enclosure->getName() << " - " << enclosure->getAnimalCount() << "/" << enclosure->getCapacity() << std::endl;
                    for (const auto& animal : enclosure->getAnimals()) {
                        std::cout << "ID: " << animal->getId() << " | Имя: " << animal->getName()
                            << " | Тип: " << animal->getTypeString()
                            << " | Возраст: " << animal->getAge() << " дней"
                            << " | Пол: " << (animal->getGenderString())
                            << " | Состояние: " << animal->getStateString() 
                            << " | Вес: " << animal->getWeight() << " кг"
                            << " | Диета: " << (animal->getDiet() == Diet::PREDATORS ? "Хищник" : "Травоядное") << std::endl;
                    }
                }
            break;
            case 2:
                // Размножение животных

                // Вывод списка вольеров
                std::cout << "\nДоступные вольеры для размножения:" << std::endl;
                for (const auto enclosure : zoo.enclosures) {
                    std::cout << "ID: " << enclosure->getId() << " Вольер: " << enclosure->getName() << ", " << enclosure->getClimateString() << " - " << enclosure->getAnimalCount() << "/" << enclosure->getCapacity() << std::endl;
                }

                std::cout << "Выберите вольер для размножения (1-" << zoo.enclosures.size() << "): ";
                std::cin >> enclosureChoice;

                enclosure = zoo.getEnclosure(enclosureChoice);
                if (!enclosure) {
                    std::cout << "Неверный выбор вольера" << std::endl;
                    continue;
                }

                if (enclosure->getAnimalCount() < 2) {
                    std::cout << "Недостаточно животных в вольере для размножения" << std::endl;
                    continue;
                }

				if (enclosure->getAnimalCount() + 1 > enclosure->getCapacity()) {
					std::cout << "Недостаточно места в вольере для размножения" << std::endl;
				}

                // Вывод списка животных в вольере
                std::cout << "ID: " << enclosure->getId() << " Вольер: " << enclosure->getName() << ", " << enclosure->getClimateString() << " - " << enclosure->getAnimalCount() << "/" << enclosure->getCapacity() << std::endl;
                std::cout << "\nВыбери 1-ое животное:" << std::endl;
				for (const auto& animal : enclosure->getAnimals()) {
					if (animal->getAge() <= 5 && animal->getState() != AnimalState::HEALTHY) continue; // Пропускаем слишком молодых или больных животных
					std::cout << "ID: " << animal->getId() 
					<< " | Имя: " << animal->getName() 
					<< " | Тип: " << animal->getTypeString()
					<< " | Возраст: " << animal->getAge() << " дней"
					<< " | Пол: " << animal->getGenderString()
					<< " | Состояние: " << animal->getStateString()
					<< " | Вес: " << animal->getWeight() << " кг"
					<< " | Диета: " << (animal->getDiet() == Diet::PREDATORS ? "Хищник" : "Травоядное") << std::endl;
				}

				std::cout << "Выберите ID первого животного (0 для отмены): ";
				int firstAnimalId;
				std::cin >> firstAnimalId;

				if (firstAnimalId == 0) continue; // Отмена

				firstAnimal = enclosure->getAnimal(firstAnimalId);
				if (!firstAnimal) {
					std::cout << "Животное с таким ID не найдено." << std::endl;
					continue;
				}

				std::cout << "Выбери 2-ое животное:" << std::endl;
				for (const auto& animal : enclosure->getAnimals()) {
					if (animal->getAge() <= 5 
						&& animal->getState() != AnimalState::HEALTHY 
						&& firstAnimal->getGender() == animal->getGender()) continue; // Пропускаем слишком молодых или больных животных
					std::cout << "ID: " << animal->getId() 
					<< " | Имя: " << animal->getName() 
					<< " | Тип: " << animal->getTypeString()
					<< " | Возраст: " << animal->getAge() << " дней"
					<< " | Пол: " << animal->getGenderString()
					<< " | Состояние: " << animal->getStateString()
					<< " | Вес: " << animal->getWeight() << " кг"
					<< " | Диета: " << (animal->getDiet() == Diet::PREDATORS ? "Хищник" : "Травоядное") << std::endl;
				}

				std::cout << "Выберите ID второго животного (0 для отмены): ";
				int secondAnimalId;
				std::cin >> secondAnimalId;

				if (secondAnimalId == 0) continue; // Отмена

				secondAnimal = enclosure->getAnimal(secondAnimalId);
				if (!secondAnimal) {
					std::cout << "Животное с таким ID не найдено." << std::endl;
					continue;
				}

				// Размножаем животных
				if (enclosure->breedAnimals(firstAnimalId, secondAnimalId)) {
					std::cout << "Животные успешно размножены!" << std::endl;
				} else {
					std::cout << "Не удалось размножить животных. Возможно, они не подходят друг другу." << std::endl;
				}
			break;
			case 3:
				return; // Возврат в главное меню
			default:
				std::cout << "Неверный выбор! Пожалуйста, выберите от 1 до 3." << std::endl;
			continue;
        }
    }
}

// Функции интерфейса
void displayStatus(const Zoo& zoo) {
    std::cout << "\n=== " << zoo.getName() << " === День " << zoo.getDay() << " ===\n";
    std::cout << "Деньги: $" << zoo.getMoney() << " | Еда: " << zoo.getFood() << " | Популярность: " << zoo.getPopularity() << "%\n";

    std::cout << "Животных: " << zoo.getCountAnimal() << " | Вольеров: " << zoo.getEnclosures().size() 
		<< " | Больных животных: " << zoo.getCountSickAnimal()
        << " | Работников: " << zoo.getWorkers().size() << "\n";
}

void animalManagement(Zoo& zoo) {
    while (true) {
        std::cout << "\n=== Управление животными ===\n";
        std::cout << "1. Купить животное\n";
        std::cout << "2. Просмотреть животных в зоопарке\n";
		std::cout << "3. Размножить животных\n";
        std::cout << "4. Продать животное\n";
        std::cout << "5. Лечить животных\n";
        std::cout << "6. Назад\n";
        std::cout << "Выбор: ";

        int choice;
        std::cin >> choice;

		switch (choice) {
			case 1:
				marketManagement(zoo);
				break;
			case 2:
				// Просмотр животных в зоопарке
				if (zoo.getCountAnimal() == 0) {
					std::cout << "В зоопарке пока нет животных.\n";
				} else {
					for (const auto enclosure : zoo.getEnclosures()) {
						std::cout << "\n" << enclosure->getName() 
							<< ", " << enclosure->getClimateString() << " - " 
							<< enclosure->getAnimalCount() << "/" << enclosure->getCapacity() << std::endl;
						for (const auto& animal : enclosure->getAnimals()) {
							std::cout << "ID: " << animal->getId() << " | Имя: " << animal->getName()
								<< " | Тип: " << animal->getTypeString()
								<< " | Возраст: " << animal->getAge() << " дней"
								<< " | Пол: " << animal->getGenderString()
								<< " | Состояние: " << animal->getStateString()
								<< " | Вес: " << animal->getWeight() << " кг"
								<< " | Диета: " << (animal->getDiet() == Diet::PREDATORS ? "Хищник" : "Травоядное") 
								<< std::endl;
						}
					}
				}
				break;
			case 3:
				breedingManagement(zoo);
				break;
			case 4:
				// Проверяем, есть ли в зоопарке животные для продажи
				if (zoo.getCountAnimal() == 0) {
					std::cout << "В зоопарке нет животных для продажи.\n";
				} else {
					// Выводим список животных для продажи
					for (const auto& animal : zoo.getAnimals()) {
						std::cout << "ID: " << animal->getId() << " | Имя: " << animal->getName()
							<< " | Тип: " << animal->getTypeString()
							<< " | Возраст: " << animal->getAge() << " дней"
							<< " | Пол: " << animal->getGenderString()
							<< " | Состояние: " << animal->getStateString()
							<< " | Вес: " << animal->getWeight() << " кг"
							<< " | Диета: " << (animal->getDiet() == Diet::PREDATORS ? "Хищник" : "Травоядное")
							<< " | Цена: $" << animal->getPrice() / 2 // Продаем за полцены
							<< std::endl;
					}

					std::cout << "Выберите ID животного для продажи (0 для отмены): ";
					int animalId;
					std::cin >> animalId;
					if (animalId == 0) continue;

					auto animalToSell = zoo.getAnimal(animalId);
					if (!animalToSell) {
						std::cout << "Животное с таким ID не найдено.\n";
						continue;
					}
					if (animalToSell->getState() == AnimalState::SELL || animalToSell->getState() == AnimalState::DEAD) {
						std::cout << "Не корректный ввод id.\n";
						continue;
					}

					animalToSell->setAnimalState(AnimalState::SELL); // Устанавливаем состояние "на продажу"
					zoo.money += animalToSell->getPrice() / 2; // Продаем за полцены
				}
				break;
		case 5:
            zoo.healthingAnimal();
			break;
		case 6:
			return; // Возврат в главное меню
		default:
            std::cout << "Неверный выбор!\n";
			continue;
		}
    }
}

void workerManagement(Zoo& zoo) {
    while (true) {
        std::cout << "\nУправление работниками:\n"
			<< "1. Нанять ветеринара ($80/день)\n"
			<< "2. Нанять уборщика ($50/день)\n"
			<< "3. Нанять кормильщика ($60/день)\n"
			<< "4. Просмотреть работников\n"
			<< "5. Назад\n"
			<< "Выбор: ";

        int choice;
        std::cin >> choice;

		switch (choice){
			case 1: case 2: case 3:
				if (zoo.hireWorker(static_cast<WorkerRole>(choice))) {
					std::cout << "Работник нанят!" << std::endl;
				} else {
					std::cout << "Не удалось нанять работника (не хватает денег)" << std::endl;
				}
				break; 
			case 4:
				if (zoo.workers.empty()) {
					std::cout << "Нет работников.\n";
				} else {
					std::cout << "\nРаботники в зоопарке:\n";
					for (const auto& worker : zoo.workers) {
						std::cout << "Имя: " << worker->getName()
							<< " | Зарплата: $" << worker->getPrice()
							<< " | Роль: " << worker->getRoleString()
							<< " | Статус: " << worker->getStatusString() << std::endl;
					}
				}
				break;
			case 5:
				return; // Возврат в главное меню
			default:
				std::cout << "Неверный выбор!\n";
				continue;

		}
    }
}

void mainMenu(Zoo& zoo) {
    while (true) {
        displayStatus(zoo);

        std::cout << "\nГлавное меню:\n";
        std::cout << "1. Управление животными\n";
        std::cout << "2. Управление работниками\n";
        std::cout << "3. Купить еду ($10 за 1 ед.)\n";
        std::cout << "4. Построить вольер ($500)\n";
        std::cout << "5. Реклама (+15% популярности, $50)\n";
        std::cout << "6. Следующий день\n";
        std::cout << "7. Выход\n";
        std::cout << "Выбор: "; 

        int choice;
        std::cin >> choice;

        switch (choice) {
    case 1: animalManagement(zoo); break;
    case 2: workerManagement(zoo); break;
    case 3:
        std::cout << "Сколько еды купить? ";
        int amount;
        std::cin >> amount;
        zoo.buyFood(amount);
        break;
    case 4: {
        std::cout << "Постройка вольера:\n";
        std::cout << "Выберите вместимость вольера (5-10): ";
        int capacity = 5;
        std::cin >> capacity;
        if (capacity < 5 || capacity > 10) {
            std::cout << "Неверная вместимость вольера. Используется значение по умолчанию (5).\n";
            capacity = 5;
        }
        // Выбор климата вольера
        std::cout << "Выберите климат вольера:\n";
        std::cout << "1. Тропический климат\n2. Континентальный климат\n3. Арктический климат\n4. Водный климат\n";
        int climateChoice = 1;
        std::cin >> climateChoice;
        if (climateChoice < 1 || climateChoice > 4) {
            std::cout << "Неверный выбор климата. Используется значение по умолчанию (континентальный).\n";
            climateChoice = 1;
        }
        // Преобразование выбора климата в enum
        Climate climate = static_cast<Climate>(climateChoice - 1);

        // Попытка постройки вольера
        if (zoo.buildEnclosure(climate, capacity)) {
            std::cout << "Вольер построен!\n";
        } else {
            std::cout << "Не удалось построить вольер (не хватает денег)\n";
        }
        break;
    }
    case 5: zoo.advertise(); break;
    case 6: zoo.nextDay(); break;
    case 7: return;
    }

        // Проверка на банкротство
        if (zoo.money < 0) {
            std::cout << "\n!!! ВЫ БАНКРОТ !!!\n";
            std::cout << "Игра окончена. Вы продержались " << zoo.day << " дней.\n";
            exit(0);
        }

        // Проверка победы
        if (zoo.day >= 30) {
            std::cout << "\n=== ПОБЕДА! ===\n";
            std::cout << "Вы успешно управляли зоопарком 30 дней!\n";
            exit(0);
        }
    }
}


int main()
{
	#ifdef _WIN32
	SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    // setlocale(LC_ALL, "ru_RU.UTF-8");
	#endif
	
    srand(static_cast<unsigned int>(time(0)));

    std::cout << "Добро пожаловать в симулятор зоопарка!\n";
    std::cout << "Введите название вашего зоопарка: ";
    std::string name;
    getline(std::cin, name);

    Zoo zoo(name, 100000);
    mainMenu(zoo);

    return 0;
}
