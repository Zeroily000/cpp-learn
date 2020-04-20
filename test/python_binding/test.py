#!/usr/bin/env python3
import unittest

import cppLearnPyLib


class TestCppLearn(unittest.TestCase):
    def testBinarySearch(self):
        nums = [0,1,2,4,4,4,6]
        self.assertEqual(cppLearnPyLib.CppLearn().findLeft(nums, 4), 3)
        self.assertEqual(cppLearnPyLib.CppLearn().findRight(nums, 4), 5)
        self.assertEqual(cppLearnPyLib.CppLearn.findLeft(nums, 5), 6)
        self.assertEqual(cppLearnPyLib.CppLearn.findRight(nums, 3), 2)

if __name__ == '__main__':
    print(cppLearnPyLib.the_answer)
    print(cppLearnPyLib.what)
    unittest.main()