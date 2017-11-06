//Атлеты
//В город N приехал цирк с командой атлетов.
//Они хотят удивить горожан города N — выстроить из своих тел башню максимальной высоты.
//Башня — это цепочка атлетов, первый стоит на земле, второй стоит у него на плечах,
//третий стоит на плечах у второго и т.д. Каждый атлет характеризуется силой si (kg) и массой mi (kg).
//Сила — это максимальная масса, которую атлет способен держать у себя на плечах.
//К сожалению ни один из атлетов не умеет программировать, так как всю жизнь
//они занимались физической подготовкой, и у них не было времени на изучение языков программирования.
//Помогите им, напишите программу, которая определит максимальную высоту башни, которую они могут составить.
//Известно, что если атлет тяжелее, то он и сильнее: если mi>mj, то si > sj. Атлеты равной
//массы могут иметь различную силу.

#include <iostream>
#include <algorithm>

struct AthleteStats {
    long int mass;
    long int power;


};

int tallestTower(AthleteStats* athleteStats, int countOf) {
    std::sort(athleteStats, athleteStats + countOf, [](AthleteStats &a, AthleteStats &b) {
        return (a.power < b.power);
    });

    int height = 1;
    long long currentMass = athleteStats[0].mass;

    for (int i = 1; i < countOf; i++) {
        if (athleteStats[i].power >= currentMass) {
            currentMass += athleteStats[i].mass;
            height++;
        } else if (athleteStats[countOf - 1].power < currentMass) {
            break;
        }
    }

    return height;
}



int main() {
    AthleteStats * athleteStats = new AthleteStats[100000];

    long int mass = 0;
    long int power = 0;
    int countOf = 0;

    while (std::cin >> mass >> power) {
        athleteStats[countOf].mass = mass;
        athleteStats[countOf].power = power;
        countOf++;
    }

    std::cout << tallestTower(athleteStats, countOf);
    delete[](athleteStats);
    return 0;
}