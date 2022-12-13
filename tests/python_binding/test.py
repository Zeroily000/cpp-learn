#!/usr/bin/env python3
import unittest

# Add <BUILD_DIR>/python to the PYTHONPATH
import cppLearnPyLib


class TestCppLearn(unittest.TestCase):
    def setUp(self):
        self.base = cppLearnPyLib.Base()
        self.derived = cppLearnPyLib.Derived.get_instance()


    def testInheritance(self):
        self.assertEqual(self.base.m_public_string, self.derived.m_public_string)
        self.assertEqual(self.base.get_protected_string(), self.derived.get_protected_string())


    def testSingleton(self):
        derived2 = cppLearnPyLib.Derived.get_instance()
        self.assertEqual(id(self.derived), id(derived2))


if __name__ == '__main__':
    print(cppLearnPyLib.the_answer)
    print(cppLearnPyLib.what)

    unittest.main()