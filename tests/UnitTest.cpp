// Підключаємо бібліотеку Google Test
#include "gtest/gtest.h"
// Підключаємо заголовочний файл з вашими функціями
#include "src/functions.h"

/*
 * TEST(TestSuiteName, TestName)
 * - TestSuiteName: Назва групи тестів. Логічно об'єднує тести.
 * - TestName: Назва конкретного тесту.
 */

// Тест 1: Перевірка на звичайних додатних числах
TEST(SummationTest, HandlesPositiveNumbers) {
    const int K = 5;
    const int N = 15;

    // Обчислюємо очікуване значення за допомогою ітеративної функції,
    // яку вважаємо еталоном.
    double expected_value = S0(K, N);

    // Порівнюємо результат кожної рекурсивної функції з еталоном.
    // ASSERT_NEAR використовується для чисел з плаваючою комою,
    // щоб уникнути помилок через похибку обчислень.
    ASSERT_NEAR(expected_value, S1(K, N, K), 1e-9);
    ASSERT_NEAR(expected_value, S2(K, N, N), 1e-9);
    ASSERT_NEAR(expected_value, S3(K, N, K, 0), 1e-9);
    ASSERT_NEAR(expected_value, S4(K, N, N, 0), 1e-9);
}

// Тест 2: Граничний випадок, коли K дорівнює N
TEST(SummationTest, HandlesKEqualsN) {
    const int K = 10;
    const int N = 10;

    // Розраховуємо результат вручну: (10^2) / (10^2 + 10^2) = 100 / 200 = 0.5
    double expected_value = 0.5;

    // Перевіряємо, чи всі функції повертають цей результат
    ASSERT_NEAR(expected_value, S0(K, N), 1e-9);
    ASSERT_NEAR(expected_value, S1(K, N, K), 1e-9);
    ASSERT_NEAR(expected_value, S2(K, N, N), 1e-9);
}

// Тест 3: Перевірка на діапазоні, що включає від'ємні числа та нуль
TEST(SummationTest, HandlesNegativeAndZeroRange) {
    const int K = -2;
    const int N = 2;

    // Розраховуємо вручну: ((-2)^2 + (-1)^2 + 0^2 + 1^2 + 2^2) / ((-2)^2 + 2^2)
    // = (4 + 1 + 0 + 1 + 4) / (4 + 4) = 10 / 8 = 1.25
    double expected_value = 1.25;

    ASSERT_NEAR(expected_value, S0(K, N), 1e-9);
    ASSERT_NEAR(expected_value, S3(K, N, K, 0), 1e-9);
    ASSERT_NEAR(expected_value, S4(K, N, N, 0), 1e-9);
}

// Тест 4: Перевірка коректної обробки ділення на нуль
TEST(SummationTest, HandlesDivisionByZero) {
    const int K = 0;
    const int N = 0;

    // Всі функції мають безпечно повернути 0, як ми це реалізували
    ASSERT_NEAR(0.0, S0(K, N), 1e-9);
    ASSERT_NEAR(0.0, S1(K, N, K), 1e-9);
}