#!/usr/bin/env python3
import random
import subprocess
import sys

# Maximum n to test in each random case:
N_MAX = 50

def gen_test():
    """Generate one random test case in the required format."""
    n = random.randint(2, N_MAX)
    # weights from 1..10000
    w = [str(random.randint(1, 10000)) for _ in range(n)]
    # parents p2..pn, where pi in [1..i]
    parents = [str(random.randint(1, i)) for i in range(2, n+1)]
    parts = [
        str(n),
        " ".join(w),
        " ".join(parents)
    ]
    return "\n".join(parts) + "\n"

def compile_solutions():
    """Compile sol.cpp → sol and mine.cpp → mine."""
    subprocess.run(
        ["g++", "-std=c++17", "-O2", "D.cpp", "-o", "D"],
        check=True
    )
    subprocess.run(
        ["g++", "-std=c++17", "-O2", "Dgpt.cpp", "-o", "Dgpt"],
        check=True
    )

def run_test(iteration):
    test_input = gen_test().encode()
    # run reference
    mine = subprocess.run(
        ["./D"],
        input=test_input,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE
    )
    ref = subprocess.run(
        ["./Dgpt"],
        input=test_input,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE
    )
    out_ref  = ref.stdout.decode()
    out_mine = mine.stdout.decode()

    if out_ref != out_mine:
        print(f"\n❌ Mismatch on test #{iteration}")
        print("---- INPUT ----")
        print(test_input.decode(), end="")
        print("---- sol.cpp ----")
        print(out_ref, end="")
        print("---- mine.cpp ----")
        print(out_mine, end="")
        sys.exit(1)
    else:
        print(f"✔ OK test #{iteration}")

def main():
    print("Compiling solutions...")
    compile_solutions()
    print("Starting stress test (n up to {})".format(N_MAX))

    i = 0
    try:
        while True:
            i += 1
            run_test(i)
    except KeyboardInterrupt:
        print("\nInterrupted by user. No mismatches found so far.")

if __name__ == "__main__":
    main()
