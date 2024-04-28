#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Animal class representing each animal on the ark
class Animal {
private:
    string species;
    string gender;
    int age;
public:
    Animal(string species, string gender, int age) : species(species), gender(gender), age(age) {}

    // Getter for species
    string getSpecies() const {
        return species;
    }

    // Getter for gender
    string getGender() const {
        return gender;
    }

    // Getter for age
    int getAge() const {
        return age;
    }

    // Method to age the animal by one month
    void ageOneMonth() {
        age++;
    }

    // Method to print information about the animal
    void printInfo(int index) const {
        cout << "Animal #" << index << ": I am a " << gender << " " << species << ", " << age << " months old" << endl;
    }
};

// NoahsArk class representing the ark and managing the animals
class NoahsArk {
private:
    vector<Animal> animals;
    int monthsOnArk;
public:
    NoahsArk() : monthsOnArk(0) {
        // Initializing the ark with 2 of each species, one male and one female
        animals.push_back(Animal("cat", "female", 0));
        animals.push_back(Animal("cat", "male", 0));
        animals.push_back(Animal("dog", "female", 0));
        animals.push_back(Animal("dog", "male", 0));
        animals.push_back(Animal("goldfish", "female", 0));
        animals.push_back(Animal("goldfish", "male", 0));
        animals.push_back(Animal("shark", "female", 0));
        animals.push_back(Animal("shark", "male", 0));
        animals.push_back(Animal("eagle", "female", 0));
        animals.push_back(Animal("eagle", "male", 0));
        animals.push_back(Animal("parakeet", "female", 0));
        animals.push_back(Animal("parakeet", "male", 0));
    }

    // Method to age all animals on the ark by one month
    void ageAnimals() {
        for (auto& animal : animals) {
            animal.ageOneMonth();
        }
        monthsOnArk++;
    }

    // Method to check inventory and print information about all animals
    void checkInventory() const {
        for (size_t i = 0; i < animals.size(); ++i) {
            animals[i].printInfo(i + 1);
        }
    }

    // Method to simulate breeding based on months passed
    void breedAnimals() {
        for (auto& animal : animals) {
            if (animal.getGender() == "female") {
                if (animal.getSpecies() == "cat" && monthsOnArk % 12 == 0) {
                    animals.push_back(Animal("cat", "male", 0));
                } else if ((animal.getSpecies() == "goldfish" || animal.getSpecies() == "shark") && monthsOnArk % 6 == 0) {
                    animals.push_back(Animal(animal.getSpecies(), "male", 0));
                } else if (animal.getSpecies() == "eagle" && monthsOnArk % 9 == 0) {
                    animals.push_back(Animal("eagle", "male", 0));
                }
            }
        }
    }

    // Method to display menu and handle user input
    void displayMenu() {
        char choice;
        do {
            cout << "You have been on the ark for " << monthsOnArk << " months. Would you like to:" << endl;
            cout << "1 - Let another month pass" << endl;
            cout << "2 - Check inventory" << endl;
            cout << "3 - Quit" << endl;
            cin >> choice;

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
    NoahsArk ark;
    ark.displayMenu();
    return 0;
}
