#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include <cstdlib>
#include <ctime>

using namespace std;

class Animal {
private:
    string species;
    string gender;
    int age;
public:
    Animal(string species, string gender, int age) : species(species), gender(gender), age(age) {}

    string getSpecies() const {
        return species;
    }

    string getGender() const {
        return gender;
    }

    int getAge() const {
        return age;
    }

    void ageOneMonth() {
        age++;
    }

    void printInfo(int index) const {
        cout << "Animal #" << index << ": I am a " << gender << " " << species << ", " << age << " months old" << endl;
    }
};

class NoahsArk {
private:
    vector<Animal> animals;
    int monthsOnArk;
public:
    NoahsArk() : monthsOnArk(0) {
        animals.emplace_back("cat", "female", 0);
        animals.emplace_back("cat", "male", 0);
        animals.emplace_back("dog", "female", 0);
        animals.emplace_back("dog", "male", 0);
        animals.emplace_back("goldfish", "female", 0);
        animals.emplace_back("goldfish", "male", 0);
        animals.emplace_back("shark", "female", 0);
        animals.emplace_back("shark", "male", 0);
        animals.emplace_back("eagle", "female", 0);
        animals.emplace_back("eagle", "male", 0);
        animals.emplace_back("parakeet", "female", 0);
        animals.emplace_back("parakeet", "male", 0);
    }

    void ageAnimals() {
        for (vector<Animal>::iterator it = animals.begin(); it != animals.end(); ++it) {
            it->ageOneMonth();
        }
        monthsOnArk++;
    }

    void checkInventory() const {
        for (size_t i = 0; i < animals.size(); ++i) {
            animals[i].printInfo(i + 1);
        }
    }

    void breedAnimals() {
        vector<Animal> newAnimals;
        for (vector<Animal>::iterator it = animals.begin(); it != animals.end(); ++it) {
            Animal& animal = *it;
            if (animal.getGender() == "female" && rand() % 2 == 0) { // 50% chance to breed new animals
                string newGender = rand() % 2 == 0 ? "male" : "female";
                int numNewAnimals = rand() % 10 + 1;
                if ((animal.getSpecies() == "cat" && monthsOnArk % 12 == 0) ||
                    ((animal.getSpecies() == "goldfish" || animal.getSpecies() == "shark") && monthsOnArk % 6 == 0) ||
                    (animal.getSpecies() == "eagle" && monthsOnArk % 9 == 0)) {
                    for (int i = 0; i < numNewAnimals; i++) {
                        newAnimals.emplace_back(animal.getSpecies(), newGender, 0);
                    }
                }
            }
        }
        animals.insert(animals.end(), newAnimals.begin(), newAnimals.end());
    }

    void displayMenu() {
        char choice;
        do {
            cout << "You have been on the ark for " << monthsOnArk << " months. Would you like to:" << endl;
            cout << "1 - Let another month pass" << endl;
            cout << "2 - Check inventory" << endl;
            cout << "3 - Quit" << endl;
            cin >> choice;

            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid choice. Please try again." << endl;
                continue;
            }

            switch (choice) {
                case '1':
                    ageAnimals();
                    breedAnimals();
                    break;
                case '2':
                    checkInventory();
                    break;
                case '3':
                    cout << "Exiting program." << endl;
                    break;
                default:
                    cout << "Invalid choice. Please try again." << endl;
            }
        } while (choice != '3');
    }
};

int main() {
    srand(time(0));  // Seed the random number generator
    NoahsArk ark;
    ark.displayMenu();
    return 0;
}
