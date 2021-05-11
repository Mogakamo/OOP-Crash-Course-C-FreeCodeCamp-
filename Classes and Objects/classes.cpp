#include <iostream>
using std::string;

class AbstractEmployee {
   virtual void AskForPromotion()=0;
};

class Employee:AbstractEmployee {
private:
    string Company;
    int Age;
protected:
    string Name;
public:
    //setter
    void setName(string name) {
        Name = name;
    }
    //getter
    string getName() {
        return Name;
    }
    void setCompany(string company) {
        Company = company;
    }
    string getCompany() {
        return Company;
    }
    void setAge(int age) {
        if (age > 18)
        Age  = age;
    }
    int getAge() {
        return Age;
    }
    void IntroduceYourself() {
        std::cout << "Name - " << Name << std::endl;
        std::cout << "Company - " << Company << std::endl;
        std::cout << "Age - " << Age << std::endl;
    }
    Employee(string name, string company, int age) {
        Name = name;
        Company = company;
        Age = age;
    }
    void AskForPromotion() {
        if (Age > 30)
            std::cout<<Name<< " got Promoted" << std::endl;
        else
            std::cout<<Name<< " no promotion for you"<< std::endl;
    }
    virtual void Work() {
        std::cout << Name << " is checking email, task backlog, perfoming tasks ...." << std::endl;
    }
};

class Developer:public Employee {
public:
    string FavoriteProgrammingLanguage;
    Developer(string name, string company, int age, string favoriteProgrammingLanguage)
        : Employee(name, company, age)
    {
        FavoriteProgrammingLanguage=favoriteProgrammingLanguage;
    }
    void FixBug() {
        std::cout<<Name<<" fixed a bug using "<<FavoriteProgrammingLanguage<<std::endl;
    }
    void Work() {
        std::cout << Name << " is writing " << FavoriteProgrammingLanguage << " code." << std::endl;
    }
};

class Teacher:public Employee {
public:
    string Subject;
    void PrepareLesson() {
        std::cout<<Name<<" is preparing "<<Subject<< " lesson" << std::endl;
    }
    Teacher(string name, string company, int age, string subject)
        : Employee(name, company, age)
    {
        Subject=subject;
    }
    void Work() {
        std::cout << Name << " is teaching " << Subject << " class." << std::endl;
    }
};

int main () {
    //Employee employee1=Employee("Amos Mogaka", " Wasify ", 32);
    //employee1.IntroduceYourself();

    //Employee employee2= Employee("Musa Esau", "Amazon", 13);
    //employee2.IntroduceYourself();

    //employee1.setAge(9);
    //std::cout << employee1.getName()<< " is " << employee1.getAge()<< " years old"<< std::endl;

    //employee1.AskForPromotion();
    //employee2.AskForPromotion();

    Developer d=Developer("Willy Manyara", "Wasify", 25, "C++");
    //d.FixBug();
    //d.AskForPromotion();

    Teacher t=Teacher("Jack", "Karura", 45, "History");
    //t.PrepareLesson();
    //t.AskForPromotion();
    //d.Work();
    //t.Work();

    Employee* e1 = &d;
    Employee* e2 = &t;

    e1->Work();
    e2->Work();
}