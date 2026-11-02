
import random
import csv
from pathlib import Path


OUTPUT_DIR = Path(__file__).resolve().parent / "datasets"
OUTPUT_DIR.mkdir(exist_ok=True)


def is_prime(n):
    if n < 2:
        return False
    if n == 2:
        return True
    if n % 2 == 0:
        return False

    i = 3
    while i * i <= n:
        if n % i == 0:
            return False
        i += 2

    return True


def get_random_primes_any_size(count):
    primes = set()

    ranges = [
        (2, 99),
        (100, 999),
        (1_000, 999_999),
        (1_000_000, 999_999_999),
        (1_000_000_000, 999_999_999_999),
    ]

    while len(primes) < count:
        min_value, max_value = random.choice(ranges)
        number = random.randint(min_value, max_value)

        if is_prime(number):
            primes.add(number)

    return list(primes)


def random_primes(count, min_value, max_value):
    primes = set()

    while len(primes) < count:
        number = random.randint(min_value, max_value)

        if is_prime(number):
            primes.add(number)

    return list(primes)


def save_csv(filename, primes):
    filepath = OUTPUT_DIR / filename

    with open(filepath, "w", newline="") as file:
        writer = csv.writer(file)
        writer.writerow(["prime"])

        for prime in primes:
            writer.writerow([prime])

    print(f"Generated {len(primes)} primes: {filepath}")


# Random100: 100 primes selected using random digit ranges
def generate_random100():
    primes = get_random_primes_any_size(100)
    save_csv("Random100.csv", primes)


# Random1000: 1000 primes selected using random digit ranges
def generate_random1000():
    primes = get_random_primes_any_size(1000)
    save_csv("Random1000.csv", primes)


# Test-1: use Random100's range-selection method,
# but keep only primes between 1,000 and 1,000,000.
def generate_test1():
    primes = set()

    ranges = [
        (2, 99),
        (100, 999),
        (1_000, 999_999),
        (1_000_000, 999_999_999),
        (1_000_000_000, 999_999_999_999),
    ]

    while len(primes) < 100:
        min_value, max_value = random.choice(ranges)
        number = random.randint(min_value, max_value)

        # Reject candidates outside the required interval.
        if number < 1_000 or number > 1_000_000:
            continue

        if is_prime(number):
            primes.add(number)

    save_csv("Test-1.csv", list(primes))


# Test-2: 10 primes for each digit length from 3 to 12
def generate_test2():
    primes = []

    for digits in range(3, 13):
        minimum = 10 ** (digits - 1)
        maximum = (10 ** digits) - 1

        primes.extend(random_primes(10, minimum, maximum))

    primes.sort()
    save_csv("Test-2.csv", primes)


# Test-3: 25 primes each with 3, 6, 9, and 12 digits
def generate_test3():
    primes = []

    for digits in (3, 6, 9, 12):
        minimum = 10 ** (digits - 1)
        maximum = (10 ** digits) - 1

        primes.extend(random_primes(25, minimum, maximum))

    primes.sort()
    save_csv("Test-3.csv", primes)


if __name__ == "__main__":
    generate_random100()
    generate_random1000()
    generate_test1()
    generate_test2()
    generate_test3()
