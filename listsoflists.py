import unittest

class lists_in_lists:
    def __init__(self,listof:list) -> None:
        self._list = listof
    def givelist(self):
        return self._list
    def reverse_transpose(self):
        revlist=[ [] for _ in range(len(self._list))]
        index = len(self._list) - 1
        while index >= 0:
            index2=len(self._list[index]) - 1
            for obj in self._list[index]:
                revlist[index2].append(obj)
                index2 = index2 - 1
            index = index - 1
        return revlist

    def calculate_sums(self):
        editlist = []
        for obj in self._list:
            if type(obj)==list:
                templist = []
                for ebj in obj:
                    templist.append(ebj)
                editlist.append(templist)
            else:
                editlist.append(obj)
        for x in range(len(editlist)):
            for y in range(len(editlist[x])):
                sum = 0
                for a in range(x, len(editlist)):
                    for b in range(y, len(editlist[a])):
                        sum = sum + editlist[a][b]
                editlist[x][y]=sum
        return editlist

class lists_in_lists_test(unittest.TestCase):
    def setUp(self):
        self._case1 = lists_in_lists([[2,3],[3,4,2],[7,5,6]])
        self._case2 = lists_in_lists([[7,1,2],[3],[7,7,6]])
    def test_calc_sums(self):
        self.assertEqual(self._case1.calculate_sums(),[[32, 20], [27, 17, 8], [18, 11, 6]])
        self.assertEqual(self._case2.calculate_sums(),[[33, 16, 8], [23], [20, 13, 6]])
    def test_reverse(self):
        self.assertEqual(self._case1.reverse_transpose(),[[6, 2, 3], [5, 4, 2], [7, 3]])
        self.assertEqual(self._case2.reverse_transpose(),[[6, 3, 2], [7, 1], [7, 7]])
if __name__ == "__main__":
    unittest.main()
