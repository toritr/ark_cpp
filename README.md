# ark_cpp
The Noah's Ark Inventory Application 
The scenario is this: you are on Noah's ark with a set of animals. As the months pass, the
animals begin to breed. You need to keep track of your animal inventory down below.
The ark has 3 types of animals: mammals, birds, and fish. Your program should have at least 2
kinds of mammals (cat, dog), 2 kinds of fish (goldfish, shark), and 2 kinds of birds (eagle,
parakeet). You should start the program with 2 animals of each species on the ark, one male
and one female, for a total of 12 animals.
The program should give you a menu such as follows:
You have been on the ark for 11 months. Would you like to:
1 - Let another month pass
2 - Check inventory
3 - Quit
If you let another month pass, all of the animals on the ark are aged by a month. Each female
animal in heat gives birth to another animal of the same species. You will then get the same
menu:
You have been on the ark for 12 months. Would you like to:
1 - Let another month pass
2 - Check inventory
3 - Quit
If you choose 2, you should see something like this:
Animal #1: I am a female cat, 12 months old
Animal #2: I am a male cat, 12 months old
Animal #3: I am a male cat, 0 months old
Animal #4 I am a male shark, 12 months old
Animal #5: I am a female shark, 12 months old
Animal #6: I am a male shark, 6 months old
.........
All female mammals give birth once every 12 months. All female fish give birth once every 6 months.
All female birds give birth once every 9 months.
