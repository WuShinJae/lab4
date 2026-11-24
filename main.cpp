#include <iostream>
using namespace std;

// ---------- Оголошення функцій (до main) ----------
// Завдання 1.1: Proc43
bool IsTriangle(double a, double b, double c); // чи можна утворити трикутник зі сторін a, b, c
void task_proc43();                            // задача Proc43 цілком

// Завдання 1.2: Proc9
void AddLeftDigit(int D, int &K);              // додає цифру D до числа K зліва
void task_proc9();                             // задача Proc9 цілком

// Завдання 2: Integer9
bool in_N(int &pN);                            // введення тризначного числа з перевіркою
int first_digit(int pN);                       // підрахунок: перша цифра (сотні)
void out_res(int pr);                          // виведення результату
void task_Int9();                              // задача Integer9 цілком

int main() {
    int menu;
    cout << "Task number (1 - Proc43, 2 - Proc9, 3 - Integer9): ";
    cin >> menu;
    if (cin.fail()) {                          // перевірка: введено не число
        cout << "Wrong task! (Only 1,2,3)" << endl;
        return 0;
    }
    // вибір завдання
    switch (menu) {
        case 1: task_proc43(); break;
        case 2: task_proc9(); break;
        case 3: task_Int9(); break;
        default: cout << "Wrong task! (Only 1,2,3)" << endl;
    }
    return 0;
}

// ---------- Визначення функцій (після main) ----------

// Proc43: повертає true, якщо з додатних a, b, c можна утворити трикутник
bool IsTriangle(double a, double b, double c) {
    // сума будь-яких двох сторін має бути більшою за третю
    return (a + b > c) && (a + c > b) && (b + c > a);
}

// Proc43: задача цілком - перевіряємо три набори чисел
void task_proc43() {
    double a[3], b[3], c[3];                   // три набори по три числа
    cout << "************* Proc 43 *****************" << endl;
    for (int i = 0; i < 3; i++) {              // введення (цикл тільки у введенні)
        cout << "Set " << i + 1 << " - enter a b c (positive, [-100,100]): ";
        cin >> a[i] >> b[i] >> c[i];
        if (cin.fail() || a[i] <= 0 || b[i] <= 0 || c[i] <= 0 ||
            a[i] > 100 || b[i] > 100 || c[i] > 100) { // перевірка коректності
            cout << "Wrong numbers!" << endl;
            return;
        }
    }
    // виклик функції для кожного набору і виведення результату
    cout << "Set 1: " << (IsTriangle(a[0], b[0], c[0]) ? "triangle exists" : "no triangle") << endl;
    cout << "Set 2: " << (IsTriangle(a[1], b[1], c[1]) ? "triangle exists" : "no triangle") << endl;
    cout << "Set 3: " << (IsTriangle(a[2], b[2], c[2]) ? "triangle exists" : "no triangle") << endl;
}

// Proc9: додає цифру D до цілого додатного K зліва (K - вхідний і вихідний параметр)
void AddLeftDigit(int D, int &K) {
    int p = 10;                                // розряд, в який потрапить D
    if (K >= 100) p = 1000;                    // K тризначне - D стане тисячами
    else if (K >= 10) p = 100;                 // K двозначне - D стане сотнями
    K = D * p + K;                             // D записуємо зліва від K
}

// Proc9: задача цілком - спочатку додаємо D1, потім D2
void task_proc9() {
    int K, D1, D2;
    cout << "************* Proc 9 *****************" << endl;
    cout << "Enter K (0 < K < 1000): ";
    cin >> K;
    if (cin.fail() || K <= 0 || K >= 1000) {   // перевірка K
        cout << "Wrong K!" << endl;
        return;
    }
    cout << "Enter digits D1 D2 (1..9): ";
    cin >> D1 >> D2;
    if (cin.fail() || D1 < 1 || D1 > 9 || D2 < 1 || D2 > 9) { // перевірка цифр
        cout << "Wrong digits!" << endl;
        return;
    }
    AddLeftDigit(D1, K);                       // додаємо D1 зліва
    cout << "After D1: K = " << K << endl;
    if (K >= 1000) {                           // після D1 число має бути < 1000 для наступного кроку
        cout << "K is too large for next step!" << endl;
        return;
    }
    AddLeftDigit(D2, K);                       // додаємо D2 зліва
    cout << "After D2: K = " << K << endl;
}

// Integer9: введення тризначного числа з перевіркою; true - помилка
bool in_N(int &pN) {
    cout << "Integer9." << endl;
    cout << "N (three-digit) = ";
    cin >> pN;
    if (cin.fail()) return true;               // не число
    if (pN < 0) pN = -pN;                      // працюємо з модулем
    if (pN < 100 || pN > 999) return true;     // не тризначне
    return false;
}

// Integer9: перша цифра тризначного числа - одна операція ділення
int first_digit(int pN) {
    return pN / 100;
}

// Integer9: виведення результату
void out_res(int pr) {
    cout << "First digit (hundreds) = " << pr << endl;
}

// Integer9: задача цілком
void task_Int9() {
    int N;
    if (in_N(N))                               // некоректні дані
        cout << "N must be three-digit integer!" << endl;
    else
        out_res(first_digit(N));               // підрахунок і виведення
}
