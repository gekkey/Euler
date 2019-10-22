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

binfiles = sorted(os.listdir('bin/'))
answers = [0] + open('answers.txt', 'r').read().split('\n')
for f in binfiles:
    if f == '000':
        continue
    a = answers[int(f)]
    setattr(TestSolutions, "test_" + f, make_test_case(f, a))

if __name__ == "__main__":
    unittest.main()
