//
// Created by Choi on 2017. 9. 23..
//
#include <iostream>
#include <queue>
using namespace std;

typedef struct Person {
    int korean;
    int english;
    int math;
    string name;
    Person(int kor, int eng, int math, string name) {
        this->korean = kor;
        this->english = eng;
        this->math = math;
        this->name = name;
    }
} Person;

bool operator<(const Person &lp, const Person &rp) {
    if(lp.korean == rp.korean) {
        if(lp.english == rp.english) {
            if(lp.math == rp.math) {
                return lp.name > rp.name;
            } else {
                return lp.math < rp.math;
            }
        } else {
            return lp.english > rp.english;
        }

    } else {
        return lp.korean < rp.korean;
    }

}

int main() {

    int N;
    scanf("%d", &N);

    //국 영 수 이름
    priority_queue<Person> pq;

    int kor, eng, math;
    char name[11];
    for(int i = 0; i < N; i++) {
        scanf("%s %d %d %d", name, &kor, &eng, &math);
        string str(name);
        pq.push(Person(kor, eng, math, name));
    }

    while(!pq.empty()) {
        printf("%s\n", pq.top().name.c_str());
        pq.pop();
    }
    return 0;
}
