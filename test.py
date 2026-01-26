#!/usr/bin/env python3
import random
import subprocess


def gen(count, low, high):
    return random.sample(range(low, high), count)


MAX_TESTS = 10000
COUNT = 500
MOVE_LIMIT = 5500

for i in range(MAX_TESTS):
    numbers = gen(COUNT, -10000, 10000)
    args = list(map(str, numbers))

    proc = subprocess.run(
        ["./push_swap", *args],
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
        text=True
    )

    if proc.returncode != 0:
        print(f"test case {i} crashed")
        print("args:", " ".join(args))
        print("stderr:", proc.stderr)
        break

    moves = proc.stdout.count("\n")

    if moves == 0:
        print("empty or already sorted output")
        print("args:", " ".join(args))
        break

    if moves > MOVE_LIMIT:
        print(f"test case {i} failed: {moves} moves (limit {MOVE_LIMIT})")
        print("args:", " ".join(args))
        break

    print(f"test case {i} passed: {moves} moves")

