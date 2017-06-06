import unittest, subprocess, os

class TestSolutions(unittest.TestCase):
    pass

def make_test_case(num, answer):
    def test_case(self):
        result = subprocess.run(
            'bin/' + num,
            stdout=subprocess.PIPE,
            encoding='utf-8',
            #timeout=10
        )
        self.assertEqual(
            result.returncode,
            0
        )
        self.assertEqual(
            result.stdout.strip(),
            answer
        )
    return test_case


if __name__ == "__main__":
    subprocess.run(["make", "all"])

    binfiles = sorted(os.listdir('bin/'))
    answers = [''] + open('answers.txt', 'r').read().split('\n')
    for f in binfiles:
        a = answers[int(f)]
        setattr(TestSolutions, "test_" + f, make_test_case(f, a))

    unittest.main()