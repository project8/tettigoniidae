
"""
  testintdata.py
 
   Created on: Jun 14, 2022
       Author: A. Ziegler
"""

__all__ = []

import _tettigoniidae

class TestDoubleData(_tettigoniidae.data.DoubleData):
    
    def __init__(self,):
        super().__init__()

def main(args):

    test_data = TestDoubleData()
    
    print(f'The first value is {test_data.DValue1}. The second value is {test_data.DValue2}.')

    value1 = -69.69
    value2 = 420.0

    test_data.DValue1 = value1
    test_data.DValue2 = value2

    print(f'Now the first value is {test_data.DValue1}. Now the second value is {test_data.DValue2}.')

    return 0

if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
