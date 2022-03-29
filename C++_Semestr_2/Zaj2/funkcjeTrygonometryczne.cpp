#include<iostream>
#include<cmath>
#include<cstdlib>

class Sinus
{
private:
    double x;
    static int countCreated;
public:
    static int getCC() const;
    Sinus();
    Sinus(double x);
    ~Sinus();
    void oblicz() const;
    double getX();
    void setX(double x);
};

int Sinus::countCreated = 0;

int Sinus::getCC() const {
    return countCreated;
}

Sinus::Sinus(){
    std::cout << "Rozpoczynam Prace (PUSTY)" << std::endl;
    this->x = 1;
    countCreated++;
}

Sinus::Sinus(double x)
{
    std::cout << "Rozpoczynam Prace" << std::endl;
    this->x = x;
    countCreated++;
}

Sinus::~Sinus()
{
    std::cout << "Koncze Prace" << std::endl;
}
void Sinus::oblicz() const {
    std::cout << sin(x) << std::endl;
}

double Sinus::getX() {
    return x;
}
void Sinus::setX(double x) {
    this->x = x;
}

class Cosinus
{
private:
    double x;
public:
    static int countAlive;
    static int getCA();
    Cosinus(double x);
    ~Cosinus();
    void oblicz() const;
    double getX();
    void setX(double x);
};int Cosinus::countAlive = 0;

int Cosinus::getCA() {
    return countAlive;
}

Cosinus::Cosinus(double x)
{
    std::cout << "Rozpoczynam Prace" << std::endl;
    this->x = x;
    countAlive++;
}

Cosinus::~Cosinus()
{
    std::cout << "Koncze Prace" << std::endl;
    countAlive--;
}
void Cosinus::oblicz() const {
    std::cout << cos(x) << std::endl;
}

double Cosinus::getX() {
    return x;
}
void Cosinus::setX(double x) {
    this->x = x;
}

class Tangens
{
private:
    double x;
public:
    static int licz;
    static int getLicz();
    Tangens(double x);
    ~Tangens();
    void oblicz() const;
    double getX();
    void setX(double x);
};int Tangens::licz = 0;

int Tangens::getLicz() {
    return licz;
}
Tangens::Tangens(double x)
{
    std::cout << "Rozpoczynam Prace" << std::endl;
    this->x = x;
}

Tangens::~Tangens()
{
    std::cout << "Koncze Prace" << std::endl;
}
void Tangens::oblicz() const {
    std::cout <<tan(x) << std::endl;
    licz++;
}
double Tangens::getX() {
    return x;
}
void Tangens::setX(double x) {
    this->x = x;
}

class Kotangens
{
private:
    double x;
public:
    Kotangens(double x);
    ~Kotangens();
    void oblicz() const;
    double getX();
    void setX(double x);
};

Kotangens::Kotangens(double x)
{
    std::cout << "Rozpoczynam Prace" << std::endl;
    this->x = x;
}

Kotangens::~Kotangens()
{
    std::cout << "Koncze Prace" << std::endl;
}
void Kotangens::oblicz() const {
    std::cout << 1/tan(x) << std::endl;
}

double Kotangens::getX() {
    return x;
}

void Kotangens::setX(double x) {
    this->x = x;
}



int main() {
    std::cout << "Hello, World!" << std::endl;
    const Sinus s(12);
    s.oblicz();
    Sinus *s1 = new Sinus(2);
    Tangens *t = static_cast<Tangens *>(malloc(sizeof(Tangens *)));
    delete s1;
    delete t;
    return 0;
}