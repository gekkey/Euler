#!/usr/bin/env python3
import os
import time
import subprocess
import unittest


class TestSolutions(unittest.TestCase):
    pass


def make_test_case(num, answer):
    def test_case(self):
        start = time.time()
        result = subprocess.run(
            'bin/' + num,
            stdout=subprocess.PIPE,
            encoding='utf-8',
            timeout=10
        )
        duration = time.time() - start
        self.assertEqual(
            result.returncode,
            0
        )
        self.assertEqual(
            result.stdout.strip(),
            answer
        )
        print(f"{num}: {int(duration * 1000)} ms")
    return test_case


binfiles = sorted(os.listdir('bin/'))
answers = [""] + open('answers.txt', 'r').read().split('\n')
for f in binfiles:
    if f == '000':  # This is the scratch file
        continue
    a = answers[int(f)]
    setattr(TestSolutions, "test_" + f, make_test_case(f, a))

if __name__ == "__main__":
    unittest.main()
